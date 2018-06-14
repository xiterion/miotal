#pragma once

#include <cstdint>
#include <cstddef>

#include <platform/generic/register.hpp>

namespace platform {

template <typename Derived>
using Register = generic::Generic_Register<std::uint32_t, Derived>;
template <typename reg, std::size_t offset, std::size_t width=1>
using Bitfield = generic::Generic_Bitfield<std::uint32_t, reg, offset, width>;

template <typename Derived>
using Register_16 = generic::Generic_Register<std::uint16_t, Derived>;
template <typename reg, std::size_t offset, std::size_t width=1>
using Bitfield_16 = generic::Generic_Bitfield<std::uint16_t, reg, offset, width>;

namespace generic {

// Partial specialization of Bitfield to support bit banding
template <typename T, typename Reg, std::size_t offset>
struct Generic_Bitfield<T, Reg, offset, 1> {
    typedef Reg register_t;

    const T value;

    static constexpr T mask {1u << offset};
    static constexpr std::size_t shift {offset};

    constexpr Generic_Bitfield(T raw) : value{raw} {}
    constexpr Generic_Bitfield(Reg r) : value{r} {}

    inline static constexpr std::uintptr_t bitband_address(const Reg& instance);
    static Generic_Bitfield read(const Reg& instance) {
        return {static_cast<T>(
                Generic_Register<std::uint32_t, Reg>{bitband_address(instance)}.read())};
    }
    static void write(const Reg& instance, Generic_Bitfield val) {
        Generic_Register<std::uint32_t, Reg>{bitband_address(instance)}.write(val.value);
    }
};

template <typename T, typename Reg, std::size_t offset>
constexpr std::uintptr_t Generic_Bitfield<T, Reg, offset, 1>::bitband_address(const Reg& instance) {
    if((0x2000'0000 <= instance.address) and (instance.address < 0x2010'0000)) {
        return 0x2200'0000 + (((instance.address - 0x2000'0000) * 32) + (offset * 4));
    }
    if((0x4000'0000 <= instance.address) and (instance.address < 0x4010'0000)) {
        return 0x4200'0000 + (((instance.address - 0x4000'0000) * 32) + (offset * 4));
    }
    return 0;
}

} // namespace generic
} // namespace platform

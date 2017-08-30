#pragma once

#include <cstdint>
#include <cstddef>

#include <platform/generic/register.hpp>

namespace platform {

template <std::uintptr_t address>
using Register = generic::Generic_Register<std::uint32_t, address>;
template <std::size_t offset, std::size_t width=1>
using Bitfield = generic::Generic_Bitfield<std::uint32_t, offset, width>;


namespace generic {

// Partial specialization of Bitfield to support bit banding
template <typename T, std::size_t offset>
struct Generic_Bitfield<T, offset, 1> {
    typedef Generic_Bitfield bits_t;

    T value;

    constexpr Generic_Bitfield(T raw) : value{raw} {}
    explicit operator T() const { return value; }

    static constexpr T mask {1u << offset};
    static constexpr std::size_t shift {offset};

    template <std::uintptr_t address>
    struct Bits {
        inline static constexpr std::uintptr_t bitband_address();
        typedef Generic_Register<T, bitband_address()> bitband_reg;

        Generic_Bitfield operator()() { return {bitband_reg::read()}; }
        void operator()(Generic_Bitfield value) { bitband_reg::write(static_cast<T>(value)); }
    };
};

template <typename T, std::size_t offset>
template <std::uintptr_t address>
constexpr std::uintptr_t Generic_Bitfield<T, offset, 1>::Bits<address>::bitband_address() {
    if((0x2000'0000 <= address) and (address < 0x2010'0000)) {
        return 0x2200'0000 + (((address - 0x2000'0000) * 32) + (offset * 4));
    }
    if((0x4000'0000 <= address) and (address < 0x4010'0000)) {
        return 0x4200'0000 + (((address - 0x4000'0000) * 32) + (offset * 4));
    }
    return 0;
}

} // namespace generic
} // namespace platform

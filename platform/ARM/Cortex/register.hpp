#pragma once

#include <climits>
#include <cstdint>
#include <cstddef>

#include <platform/generic/register.hpp>

namespace platform {

template <typename T>
class Register : public generic::Generic_Register<T> {
public:
    using bitband_enabled = std::true_type;
};

template <typename R,
          std::size_t msb,
          std::size_t lsb=msb,
          typename BitbandAllowed = void>
struct Bitfield : public generic::Bitfield<R, msb, lsb> {};

template <typename R, std::size_t msb, std::size_t lsb>
bool operator==(const Bitfield<R, msb, lsb>& lhs, const Bitfield<R, msb, lsb>& rhs) {
    return lhs.value == rhs.value;
}

template <typename R, std::size_t bit>
struct Bitfield<R, bit, bit, std::enable_if_t<R::bitband_enabled::value>> {
    static_assert(bit < sizeof(typename R::reg_t)*CHAR_BIT, "Bitfield not inside parent type");
    const typename R::reg_t value;

    static constexpr std::size_t offset = bit;
    static constexpr std::size_t width = 1;
    static constexpr typename R::reg_t mask = 1u << offset;

    constexpr Bitfield(typename R::reg_t raw) : value{raw} {}
    template <class>
    Bitfield(R* reg) : value{bitband_register(reg, offset)} {}

    static Bitfield decode(const volatile R* reg) {
        return Bitfield{reg->read()};
    }
    void update(volatile R* reg) { bitband_register(reg, offset) = value; }
private:
    static auto& bitband_register(volatile R* reg, std::size_t offset) {
        return *reinterpret_cast<volatile typename R::reg_t*>(
                0x4400'0000 + (((reinterpret_cast<std::uintptr_t>(reg)) * 32) + (offset * 4)));
    }
};

} // namespace platform

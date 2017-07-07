#pragma once

#include <cstdint>
#include <cstddef>

#include <port/generic/register.hpp>

namespace port {

using Register = generic::Register<std::uint32_t>;

template <typename T, std::uint32_t bit>
class BitBandedBit : private generic::Bit<T, std::uint32_t, bit>
{
public:
    inline constexpr BitBandedBit(std::uintptr_t address);

    T read() const      { return reg.read(); }
    void set()          { reg.write(1); }
    void clear()        { reg.write(0); }
    void write(T value) { reg.write(value ? 1 : 0); }
    using generic::Bit<T, std::uint32_t, bit>::to_word;

private:
    Register reg;

    inline constexpr std::uint32_t BitWordAddress(std::uintptr_t bit_band_base,
                                                  std::ptrdiff_t byte_offset);
    inline constexpr std::uint32_t BitBandAddress(std::uintptr_t address);
};

template <typename T, std::uint32_t bit>
using Bit = typename std::conditional<BitBandEnabled::value,
                                      BitBandedBit<T, bit>,
                                      generic::Bit<T, std::uint32_t, bit>>::type;

template <typename T, std::uint32_t start_bit, std::uint32_t end_bit>
using Bits = generic::Bits<T, std::uint32_t, start_bit, end_bit>;

// BitBandedBit implementation

template <typename T, std::uint32_t bit>
constexpr BitBandedBit<T, bit>::BitBandedBit(std::uintptr_t address) :
    generic::Bit<T, std::uint32_t, bit>(address),
    reg(BitBandAddress(address)) {}

template <typename T, std::uint32_t bit>
constexpr std::uint32_t
BitBandedBit<T, bit>::BitWordAddress(std::uintptr_t bit_band_base,
                                     std::ptrdiff_t byte_offset)
{
    return bit_band_base + ((byte_offset * 32) + (bit * 4));
}

template <typename T, std::uint32_t bit>
constexpr std::uint32_t
BitBandedBit<T, bit>::BitBandAddress(std::uintptr_t address)
{
    if((0x20000000 <= address) and (address <= 0x200FFFFF))
    {
        return BitWordAddress(0x22000000, address-0x20000000);
    }
    if((0x40000000 <= address) and (address <= 0x400FFFFF))
    {
        return BitWordAddress(0x42000000, address-0x40000000);
    }
    return 0;
}
} // namespace port

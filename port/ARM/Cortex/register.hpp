#pragma once

#include <cstdint>
#include <cstddef>

#include <port/generic/register.hpp>

namespace port {

using Register = generic::Register<std::uint32_t>;

template <typename T>
class BitBandedBit : private generic::Bit<T, std::uint32_t>
{
public:
    inline constexpr BitBandedBit(std::uintptr_t address, std::uint32_t bit);

    T read() const      { return reg.read(); }
    void set()          { reg.write(1); }
    void clear()        { reg.write(0); }
    void write(T value) { reg.write(value ? 1 : 0); }
    using generic::Bit<T, std::uint32_t>::to_word;

private:
    Register reg;

    inline constexpr std::uint32_t BitWordAddress(std::uintptr_t bit_band_base,
                                                  std::ptrdiff_t byte_offset,
                                                  std::uint32_t bit_number);
    inline constexpr std::uint32_t BitBandAddress(std::uintptr_t address,
                                                  std::uint32_t bit_number);
};

template <typename T>
using Bit = typename std::conditional<BitBandEnabled::value,
                                      BitBandedBit<T>,
                                      generic::Bit<T, std::uint32_t>>::type;

template <typename T>
using Bits = generic::Bits<T, std::uint32_t>;

// BitBandedBit implementation

template <typename T>
constexpr BitBandedBit<T>::BitBandedBit(std::uintptr_t address, std::uint32_t bit) :
    generic::Bit<T, std::uint32_t>(address, bit),
    reg(BitBandAddress(address, bit)) {}

template <typename T>
constexpr std::uint32_t
BitBandedBit<T>::BitWordAddress(std::uintptr_t bit_band_base,
                                std::ptrdiff_t byte_offset,
                                std::uint32_t bit_number)
{
    return bit_band_base + ((byte_offset * 32) + (bit_number * 4));
}

template <typename T>
constexpr std::uint32_t
BitBandedBit<T>::BitBandAddress(std::uintptr_t address, std::uint32_t bit_number)
{
    if((0x20000000 <= address) and (address <= 0x200FFFFF))
    {
        return BitWordAddress(0x22000000, address-0x20000000, bit_number);
    }
    if((0x40000000 <= address) and (address <= 0x400FFFFF))
    {
        return BitWordAddress(0x42000000, address-0x40000000, bit_number);
    }
    return 0;
}
} // namespace port

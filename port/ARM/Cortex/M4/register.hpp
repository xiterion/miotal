#pragma once

#include <type_traits>

#include <hal/register.hpp>

namespace port {

constexpr std::uint32_t bit_word_address(std::uint32_t bit_band_base,
                                         std::uint32_t byte_offset,
                                         std::uint32_t bit_number)
{
    return bit_band_base + ((byte_offset * 32) + (bit_number * 4));
}

constexpr std::uint32_t BitBandAddress(std::uint32_t address, std::uint32_t bit_number)
{
    if((0x20000000 <= address) and (address <= 0x200FFFFF))
    {
        return bit_word_address(0x22000000, address-0x20000000, bit_number);
    }
    if((0x40000000 <= address) and (address <= 0x400FFFFF))
    {
        return bit_word_address(0x42000000, address-0x40000000, bit_number);
    }
    return 0;
}

template <std::uint32_t bit>
class BitBandedBit
{
public:
    constexpr BitBandedBit(hal::Register* reg) :
        reg(hal::Register(BitBandAddress(reg->address, bit))) {};

    bool read() const { return reg.read(); }
    BitBandedBit<bit>& set() { return write(1); }
    BitBandedBit<bit>& clear() { return write(0); }
    BitBandedBit<bit>& write(const std::uint32_t& value)
    {
        reg.write(value);
        return *this;
    }
private:
    hal::Register reg;
};

template <std::uint32_t bit>
using Bit = typename std::conditional<BitBandEnabled::value,
                                      BitBandedBit<bit>,
                                      hal::Bit<bit>>::type;

} // namespace port

#pragma once

#include <type_traits>

#include <hal/register.hpp>

namespace port {

using Register = hal::Register<std::uint32_t>;
using Bits = hal::Bits<std::uint32_t>;

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

class BitBandedBit
{
public:
    inline constexpr BitBandedBit(Register* reg, std::uint32_t bit);

    inline bool read() const;
    inline void set();
    inline void clear();
    inline void write(std::uint32_t value);
private:
    Register reg;
};

using Bit = typename std::conditional<BitBandEnabled::value,
                                      BitBandedBit,
                                      hal::Bit<std::uint32_t>>::type;

constexpr BitBandedBit::BitBandedBit(Register* reg, std::uint32_t bit) :
    reg(Register(BitBandAddress(reg->address, bit))) {};

bool BitBandedBit::read() const
{
    return reg.read();
}

void BitBandedBit::set()
{
    write(1);
}

void BitBandedBit::clear()
{
    write(0);
}

void BitBandedBit::write(std::uint32_t value)
{
    reg.write(value);
}

} // namespace port

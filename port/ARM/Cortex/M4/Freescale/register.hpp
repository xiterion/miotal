#pragma once

#include <type_traits>

#include <port/generic/register.hpp>

namespace port {

using Register = generic::Register<std::uint32_t>;

class BitBandedBit : private generic::Bit<std::uint32_t>
{
public:
    inline constexpr BitBandedBit(Register* reg, std::uint32_t bit);

    inline bool read() const;
    inline void set();
    inline void clear();
    inline void write(std::uint32_t value);

    using generic::Bit<std::uint32_t>::mask;
private:
    Register reg;

    inline constexpr std::uint32_t bit_word_address(std::uint32_t bit_band_base,
                                                    std::uint32_t byte_offset,
                                                    std::uint32_t bit_number);
    inline constexpr std::uint32_t BitBandAddress(std::uint32_t address,
                                                  std::uint32_t bit_number);
};

using Bit = typename std::conditional<BitBandEnabled::value,
                                      BitBandedBit,
                                      generic::Bit<std::uint32_t>>::type;

struct W1C : private port::Bit
{
    inline constexpr W1C(Register* reg, std::uint32_t bit);

    using port::Bit::read;
    inline void clear();
};

using Bits = generic::Bits<std::uint32_t>;

// BitBandedBit implementation

constexpr BitBandedBit::BitBandedBit(Register* reg, std::uint32_t bit) :
    generic::Bit<std::uint32_t>(reg, bit),
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

constexpr std::uint32_t
BitBandedBit::bit_word_address(std::uint32_t bit_band_base,
                               std::uint32_t byte_offset,
                               std::uint32_t bit_number)
{
    return bit_band_base + ((byte_offset * 32) + (bit_number * 4));
}

constexpr std::uint32_t
BitBandedBit::BitBandAddress(std::uint32_t address, std::uint32_t bit_number)
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

// W1C implementation

constexpr W1C::W1C(Register* reg, std::uint32_t bit) :
    port::Bit(reg, bit) {};

void W1C::clear()
{
    port::Bit::set();
}

} // namespace port

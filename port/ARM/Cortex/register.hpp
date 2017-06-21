#pragma once

#include <port/generic/register.hpp>

namespace port {

using Register = generic::Register<std::uint32_t>;

class BitBandedBit : private generic::Bit<std::uint32_t>
{
public:
    inline constexpr BitBandedBit(Register* reg, std::uint32_t bit);

    bool read() const      { return reg.read(); }
    void set()             { reg.write(1); }
    void clear()           { reg.write(0); }
    void write(bool value) { reg.write(value ? 1 : 0); }

    using generic::Bit<std::uint32_t>::bitmask;
private:
    Register reg;

    inline constexpr std::uint32_t BitWordAddress(std::uint32_t bit_band_base,
                                                  std::uint32_t byte_offset,
                                                  std::uint32_t bit_number);
    inline constexpr std::uint32_t BitBandAddress(std::uint32_t address,
                                                  std::uint32_t bit_number);
};

using Bit = typename std::conditional<BitBandEnabled::value,
                                      BitBandedBit,
                                      generic::Bit<std::uint32_t>>::type;

using Bits = generic::Bits<std::uint32_t>;

// BitBandedBit implementation

constexpr BitBandedBit::BitBandedBit(Register* reg, std::uint32_t bit) :
    generic::Bit<std::uint32_t>(reg, bit),
    reg(Register(BitBandAddress(reg->address, bit))) {};

constexpr std::uint32_t
BitBandedBit::BitWordAddress(std::uint32_t bit_band_base,
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
        return BitWordAddress(0x22000000, address-0x20000000, bit_number);
    }
    if((0x40000000 <= address) and (address <= 0x400FFFFF))
    {
        return BitWordAddress(0x42000000, address-0x40000000, bit_number);
    }
    return 0;
}

} // namespace port

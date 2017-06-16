#pragma once

#include <cstdint>

namespace hal {

class Register
{
public:
    constexpr Register(std::uint32_t address) : address(address) {};

    std::uint32_t read() const { return *reinterpret_cast<volatile std::uint32_t*>(address); }
    Register& write(const std::uint32_t& value)
    {
        *reinterpret_cast<volatile std::uint32_t*>(address) = value;
        return *this;
    }

    const std::uint32_t address;
};

class Bit
{
public:
    constexpr Bit(Register* reg, std::uint32_t bit) :
        reg(Register(reg->address)), mask(1 << bit) {};

    bool read() const { return reg.read() & mask; }
    Bit& set() { return write(reg.read() | mask); }
    Bit& clear() { return write(reg.read() & ~mask); }
    Bit& write(bool value) { return value ? set() : clear(); }
private:
    Bit& write(std::uint32_t value) { reg.write(value); return *this; }
    Register reg;
    const std::uint32_t mask;
};

class Bits
{
public:
    constexpr Bits(Register* reg, std::uint32_t start_bit, std::uint32_t end_bit) :
        reg(Register(reg->address)), shift(end_bit),
        mask(bitmask(start_bit, end_bit)) {};

    std::uint32_t read() const { return (reg.read() & mask) >> shift; }
    void write(std::uint32_t value)
    {
        reg.write((reg.read() & ~mask) | (value << shift));
    }

private:
    Register reg;
    const std::uint32_t mask;
    const std::uint32_t shift;

    static constexpr std::uint32_t bitmask(std::uint32_t start_bit, std::uint32_t end_bit)
    {
        return ((1 << (1 + start_bit - end_bit)) - 1) << end_bit;
    }
};

} // namespace hal

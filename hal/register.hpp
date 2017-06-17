#pragma once

#include <cstdint>

namespace hal {

class Register
{
public:
    inline constexpr Register(std::uint32_t address);
    inline constexpr Register(const Register& reg);

    inline std::uint32_t read() const; 
    inline Register& write(const std::uint32_t& value);

    const std::uint32_t address;
};

class Bit
{
public:
    inline constexpr Bit(Register* reg, std::uint32_t bit);

    inline bool read() const;
    inline Bit& set();
    inline Bit& clear();
    inline Bit& write(bool value);
private:
    Register reg;
    const std::uint32_t mask;

    inline Bit& write(std::uint32_t value);
};

class Bits
{
public:
    inline constexpr Bits(Register* reg, std::uint32_t start_bit, std::uint32_t end_bit);

    inline std::uint32_t read() const;
    inline Bits& write(std::uint32_t value);

private:
    Register reg;
    const std::uint32_t mask;
    const std::uint32_t shift;

    static constexpr std::uint32_t bitmask(std::uint32_t start_bit, std::uint32_t end_bit);
};


// Register implementation

constexpr Register::Register(std::uint32_t address) : address(address) {};
constexpr Register::Register(const Register& reg) : address(reg.address) {};

std::uint32_t Register::read() const
{
    return *reinterpret_cast<volatile std::uint32_t*>(address);
}

Register& Register::write(const std::uint32_t& value)
{
    *reinterpret_cast<volatile std::uint32_t*>(address) = value;
    return *this;
}

// Bit implementation

constexpr Bit::Bit(Register* reg, std::uint32_t bit) :
        reg(Register(*reg)), mask(1 << bit) {};

bool Bit::read() const
{
    return reg.read() & mask;
}

Bit& Bit::set()
{
    return write(reg.read() | mask);
}

Bit& Bit::clear()
{
    return write(reg.read() & ~mask);
}

Bit& Bit::write(bool value)
{
    return value ? set() : clear();
}

Bit& Bit::write(std::uint32_t value)
{
    reg.write(value);
    return *this;
}

// Bits implementation

constexpr Bits::Bits(Register* reg, std::uint32_t start_bit, std::uint32_t end_bit) :
    reg(Register(*reg)),
    shift(end_bit),
    mask(bitmask(start_bit, end_bit)) {};

std::uint32_t Bits::read() const
{
    return (reg.read() & mask) >> shift;
}

Bits& Bits::write(std::uint32_t value)
{
    reg.write((reg.read() & ~mask) | (value << shift));
    return *this;
}

constexpr std::uint32_t Bits::bitmask(std::uint32_t start_bit, std::uint32_t end_bit)
{
    return ((1 << (1 + start_bit - end_bit)) - 1) << end_bit;
}

} // namespace hal

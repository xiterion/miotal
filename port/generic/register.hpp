#pragma once

#include <cstdint>

namespace port {
namespace generic {

template <typename T>
class Register
{
public:
    constexpr Register(std::uintptr_t address) : address(address) {};

    T read() const             { return *reinterpret_cast<volatile T*>(address); }
    void write(const T& value) { *reinterpret_cast<volatile T*>(address) = value; }

private:
    const std::uintptr_t address;
};

template <typename T>
class Bit
{
public:
    inline constexpr Bit(std::uintptr_t address, std::uint32_t bit);

    bool read() const      { return reg.read() & mask; }
    void set()             { reg.write(reg.read() | mask); }
    void clear()           { reg.write(reg.read() & ~mask); }
    void write(bool value) { value ? set() : clear(); }

private:
    Register<T> reg;
    const T mask;
};

template <typename T>
class Bits
{
public:
    inline constexpr Bits(std::uintptr_t address, std::uint32_t start_bit, std::uint32_t end_bit);

    T read() const      { return (reg.read() & mask) >> shift; }
    void write(T value) { reg.write((reg.read() & ~mask) | ((value << shift) & mask)); }

private:
    Register<T> reg;
    const T mask;
    const std::uint32_t shift;

    static constexpr T bitmask(std::uint32_t start_bit, std::uint32_t end_bit);
};

// Bit implementation

template <typename T>
constexpr Bit<T>::Bit(std::uintptr_t address, std::uint32_t bit) :
    reg(address), mask(1 << bit) {};

// Bits implementation

template <typename T>
constexpr Bits<T>::Bits(std::uintptr_t address, std::uint32_t start_bit, std::uint32_t end_bit) :
    reg(address), shift(end_bit), mask(bitmask(start_bit, end_bit)) {};

template <typename T>
constexpr T Bits<T>::bitmask(std::uint32_t start_bit, std::uint32_t end_bit)
{
    return ((1 << (1 + start_bit - end_bit)) - 1) << end_bit;
}

} // namespace generic
} // namespace port

#pragma once

#include <cstdint>
#include <util/bit_manipulation.hpp>

namespace platform {
namespace generic {

template <typename T>
class Register
{
public:
    constexpr Register(std::uintptr_t address) : address{address} {};

    T read() const             { return *reinterpret_cast<volatile T*>(address); }
    void write(const T& value) { *reinterpret_cast<volatile T*>(address) = value; }

private:
    const std::uintptr_t address;
};

template <typename T, typename V, std::uint32_t bit>
class Bit
{
public:
    inline constexpr Bit(std::uintptr_t address);

    T    read() const        { return reg.read() & mask; }
    void write(T value)      { static_cast<bool>(value) ? set() : clear(); }
    void set()               { reg.write(reg.read() | mask); }
    void clear()             { reg.write(reg.read() & ~mask); }
    V to_word(T value) const { return static_cast<bool>(value) ? mask : 0; }

private:
    Register<V> reg;
    const V mask;
};

template <typename T, typename V, std::uint32_t start_bit, std::uint32_t end_bit>
class Bits
{
public:
    inline constexpr Bits(std::uintptr_t address);

    T    read() const        { return (reg.read() & mask) >> shift; }
    void write(T value)      { reg.write((reg.read() & ~mask) | to_word(value)); }
    V to_word(T value) const { return (static_cast<V>(value) << shift) & mask; }

private:
    Register<V> reg;
    const V mask;
    const std::uint32_t shift;

    static constexpr V bitmask();
};

// Bit implementation

template <typename T, typename V, std::uint32_t bit>
constexpr Bit<T, V, bit>::Bit(std::uintptr_t address) :
    reg{address}, mask{1u << bit} {}

// Bits implementation

template <typename T, typename V, std::uint32_t start_bit, std::uint32_t end_bit>
constexpr Bits<T, V, start_bit, end_bit>::Bits(std::uintptr_t address) :
    reg{address}, mask{bitmask()}, shift{end_bit} {}

template <typename T, typename V, std::uint32_t start_bit, std::uint32_t end_bit>
constexpr V Bits<T, V, start_bit, end_bit>::bitmask()
{
    return ((1u << (1u + start_bit - end_bit)) - 1u) << end_bit;
}

} // namespace generic
} // namespace platform

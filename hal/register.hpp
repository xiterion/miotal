#pragma once

#include <cstdint>

template <typename T>
class MemoryLocation
{
public:
    inline constexpr MemoryLocation(T address);
    inline constexpr MemoryLocation(const MemoryLocation& reg);

    inline T read() const; 
    inline void write(const T& value);

    const T address;
};

template <typename T>
class DefaultBit
{
public:
    inline constexpr DefaultBit(MemoryLocation<T>* reg, std::uint32_t bit);

    inline bool read() const;
    inline void set();
    inline void clear();
    inline void write(bool value);

    const T mask;
private:
    MemoryLocation<T> reg;

    inline void write(T value);
};

template <typename T>
class Bits
{
public:
    inline constexpr Bits(MemoryLocation<T>* reg, std::uint32_t start_bit, std::uint32_t end_bit);

    inline std::uint32_t read() const;
    inline void write(std::uint32_t value);

private:
    MemoryLocation<T> reg;
    const T mask;
    const std::uint32_t shift;

    static constexpr T bitmask(std::uint32_t start_bit, std::uint32_t end_bit);
};


// MemoryLocation implementation

template <typename T>
constexpr MemoryLocation<T>::MemoryLocation(T address) : address(address) {};

template <typename T>
constexpr MemoryLocation<T>::MemoryLocation(const MemoryLocation& reg) : address(reg.address) {};

template <typename T>
T MemoryLocation<T>::read() const
{
    return *reinterpret_cast<volatile T*>(address);
}

template <typename T>
void MemoryLocation<T>::write(const T& value)
{
    *reinterpret_cast<volatile T*>(address) = value;
}

// DefaultBit implementation

template <typename T>
constexpr DefaultBit<T>::DefaultBit(MemoryLocation<T>* reg, std::uint32_t bit) :
        reg(MemoryLocation<T>(*reg)), mask(1 << bit) {};

template <typename T>
bool DefaultBit<T>::read() const
{
    return reg.read() & mask;
}

template <typename T>
void DefaultBit<T>::set()
{
    write(reg.read() | mask);
}

template <typename T>
void DefaultBit<T>::clear()
{
    write(reg.read() & ~mask);
}

template <typename T>
void DefaultBit<T>::write(bool value)
{
    value ? set() : clear();
}

template <typename T>
void DefaultBit<T>::write(T value)
{
    reg.write(value);
}

// Bits implementation

template <typename T>
constexpr Bits<T>::Bits(MemoryLocation<T>* reg, std::uint32_t start_bit, std::uint32_t end_bit) :
    reg(MemoryLocation<T>(*reg)),
    shift(end_bit),
    mask(bitmask(start_bit, end_bit)) {};

template <typename T>
std::uint32_t Bits<T>::read() const
{
    return (reg.read() & mask) >> shift;
}

template <typename T>
void Bits<T>::write(std::uint32_t value)
{
    reg.write((reg.read() & ~mask) | (value << shift));
}

template <typename T>
constexpr T Bits<T>::bitmask(std::uint32_t start_bit, std::uint32_t end_bit)
{
    return ((1 << (1 + start_bit - end_bit)) - 1) << end_bit;
}

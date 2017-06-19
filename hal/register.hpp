#pragma once

#include <cstdint>

namespace hal {

template <typename T>
class Register
{
public:
    inline constexpr Register(T address);
    inline constexpr Register(const Register& reg);

    inline T read() const; 
    inline void write(const T& value);

    const T address;

    class Bit
    {
    public:
        inline constexpr Bit(Register<T>* reg, std::uint32_t bit);

        inline bool read() const;
        inline void set();
        inline void clear();
        inline void write(bool value);
    private:
        Register<T> reg;
        const T mask;

        inline void write(T value);
    };

    class Bits
    {
    public:
        inline constexpr Bits(Register<T>* reg, std::uint32_t start_bit, std::uint32_t end_bit);

        inline std::uint32_t read() const;
        inline void write(std::uint32_t value);

    private:
        Register<T> reg;
        const T mask;
        const std::uint32_t shift;

        static constexpr T bitmask(std::uint32_t start_bit, std::uint32_t end_bit);
    };

};


// Register implementation

template <typename T>
constexpr Register<T>::Register(T address) : address(address) {};

template <typename T>
constexpr Register<T>::Register(const Register& reg) : address(reg.address) {};

template <typename T>
T Register<T>::read() const
{
    return *reinterpret_cast<volatile T*>(address);
}

template <typename T>
void Register<T>::write(const T& value)
{
    *reinterpret_cast<volatile T*>(address) = value;
}

// Register::Bit implementation

template <typename T>
constexpr Register<T>::Bit::Bit(Register<T>* reg, std::uint32_t bit) :
        reg(Register<T>(*reg)), mask(1 << bit) {};

template <typename T>
bool Register<T>::Bit::read() const
{
    return reg.read() & mask;
}

template <typename T>
void Register<T>::Bit::set()
{
    write(reg.read() | mask);
}

template <typename T>
void Register<T>::Bit::clear()
{
    write(reg.read() & ~mask);
}

template <typename T>
void Register<T>::Bit::write(bool value)
{
    value ? set() : clear();
}

template <typename T>
void Register<T>::Bit::write(T value)
{
    reg.write(value);
}

// Register::Bits implementation

template <typename T>
constexpr Register<T>::Bits::Bits(Register<T>* reg, std::uint32_t start_bit, std::uint32_t end_bit) :
    reg(Register<T>(*reg)),
    shift(end_bit),
    mask(bitmask(start_bit, end_bit)) {};

template <typename T>
std::uint32_t Register<T>::Bits::read() const
{
    return (reg.read() & mask) >> shift;
}

template <typename T>
void Register<T>::Bits::write(std::uint32_t value)
{
    reg.write((reg.read() & ~mask) | (value << shift));
}

template <typename T>
constexpr T Register<T>::Bits::bitmask(std::uint32_t start_bit, std::uint32_t end_bit)
{
    return ((1 << (1 + start_bit - end_bit)) - 1) << end_bit;
}

} // namespace hal

#pragma once

#include <type_traits>

#include <hal/register.hpp>

namespace port {

template <typename T>
class BitBandedBit : private hal::Bit<T>
{
public:
    inline constexpr BitBandedBit(hal::Register<T>* reg, std::uint32_t bit);

    inline bool read() const;
    inline void set();
    inline void clear();
    inline void write(std::uint32_t value);

    using hal::Bit<T>::mask;
private:
    hal::Register<T> reg;

    inline constexpr std::uint32_t bit_word_address(std::uint32_t bit_band_base,
                                                    std::uint32_t byte_offset,
                                                    std::uint32_t bit_number);
    inline constexpr std::uint32_t BitBandAddress(std::uint32_t address,
                                                  std::uint32_t bit_number);
};

template <typename T>
using Bit = typename std::conditional<BitBandEnabled::value,
                                      BitBandedBit<T>,
                                      hal::Bit<T>>::type;

template <typename T>
struct W1C : private Bit<T>
{
    inline constexpr W1C(hal::Register<T>* reg, std::uint32_t bit);

    using Bit<T>::read;
    inline void clear();
};

template <typename T>
class Register : public hal::Register<T>
{
public:
    using hal::Register<T>::Register;
    using Bit = port::Bit<T>;
    using Bits = typename hal::Bits<T>;
    using W1C = port::W1C<T>;
};

// BitBandedBit implementation

template <typename T>
constexpr BitBandedBit<T>::BitBandedBit(hal::Register<T>* reg, std::uint32_t bit) :
    hal::Bit<T>(reg, bit), reg(hal::Register<T>(BitBandAddress(reg->address, bit))) {};

template <typename T>
bool BitBandedBit<T>::read() const
{
    return reg.read();
}

template <typename T>
void BitBandedBit<T>::set()
{
    write(1);
}

template <typename T>
void BitBandedBit<T>::clear()
{
    write(0);
}

template <typename T>
void BitBandedBit<T>::write(std::uint32_t value)
{
    reg.write(value);
}

template <typename T>
constexpr std::uint32_t
BitBandedBit<T>::bit_word_address(std::uint32_t bit_band_base,
                                             std::uint32_t byte_offset,
                                             std::uint32_t bit_number)
{
    return bit_band_base + ((byte_offset * 32) + (bit_number * 4));
}

template <typename T>
constexpr std::uint32_t
BitBandedBit<T>::BitBandAddress(std::uint32_t address, std::uint32_t bit_number)
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

template <typename T>
constexpr W1C<T>::W1C(hal::Register<T>* reg, std::uint32_t bit) :
    Bit<T>(reg, bit) {};

template <typename T>
void W1C<T>::clear()
{
    Bit<T>::set();
}

} // namespace port

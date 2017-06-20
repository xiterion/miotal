#pragma once

#include <type_traits>

#include <hal/register.hpp>

template <typename T>
class BitBandedBit : private DefaultBit<T>
{
public:
    inline constexpr BitBandedBit(MemoryLocation<T>* reg, std::uint32_t bit);

    inline bool read() const;
    inline void set();
    inline void clear();
    inline void write(std::uint32_t value);

    using DefaultBit<T>::mask;
private:
    MemoryLocation<T> reg;

    inline constexpr std::uint32_t bit_word_address(std::uint32_t bit_band_base,
                                                    std::uint32_t byte_offset,
                                                    std::uint32_t bit_number);
    inline constexpr std::uint32_t BitBandAddress(std::uint32_t address,
                                                  std::uint32_t bit_number);
};

template <typename T>
using Bit = typename std::conditional<BitBandEnabled::value,
                                      BitBandedBit<T>,
                                      DefaultBit<T>>::type;

template <typename T>
struct W1C : private Bit<T>
{
    inline constexpr W1C(MemoryLocation<T>* reg, std::uint32_t bit);

    using Bit<T>::read;
    inline void clear();
};

template <typename T>
class Register : public MemoryLocation<T>
{
public:
    using MemoryLocation<T>::MemoryLocation;
    using Bit = ::Bit<T>;
    using Bits = ::Bits<T>;
    using W1C = ::W1C<T>;
};

// BitBandedBit implementation

template <typename T>
constexpr BitBandedBit<T>::BitBandedBit(MemoryLocation<T>* reg, std::uint32_t bit) :
    DefaultBit<T>(reg, bit), reg(MemoryLocation<T>(BitBandAddress(reg->address, bit))) {};

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
constexpr W1C<T>::W1C(MemoryLocation<T>* reg, std::uint32_t bit) :
    Bit<T>(reg, bit) {};

template <typename T>
void W1C<T>::clear()
{
    Bit<T>::set();
}

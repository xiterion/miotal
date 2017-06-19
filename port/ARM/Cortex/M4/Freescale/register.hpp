#pragma once

#include <type_traits>

#include <hal/register.hpp>

namespace port {

template <typename T>
class Register : public hal::Register<T>
{
public:
    using hal::Register<T>::Register;
    class BitBandedBit;
    using Bit = typename std::conditional<BitBandEnabled::value,
                                          BitBandedBit,
                                          typename hal::Register<T>::Bit>::type;

    class BitBandedBit : private hal::Register<T>::Bit
    {
    public:
        inline constexpr BitBandedBit(Register* reg, std::uint32_t bit);

        inline bool read() const;
        inline void set();
        inline void clear();
        inline void write(std::uint32_t value);

        using hal::Register<T>::Bit::mask;
    private:
        Register reg;

        inline constexpr std::uint32_t bit_word_address(std::uint32_t bit_band_base,
                                                        std::uint32_t byte_offset,
                                                        std::uint32_t bit_number);
        inline constexpr std::uint32_t BitBandAddress(std::uint32_t address,
                                                      std::uint32_t bit_number);
    };

    struct W1C : private Bit
    {
        inline constexpr W1C(Register* reg, std::uint32_t bit);

        using Bit::read;
        inline void clear();
    };

};


template <typename T>
constexpr Register<T>::BitBandedBit::BitBandedBit(Register* reg, std::uint32_t bit) :
    hal::Register<T>::Bit(reg, bit), reg(Register(BitBandAddress(reg->address, bit))) {};

template <typename T>
bool Register<T>::BitBandedBit::read() const
{
    return reg.read();
}

template <typename T>
void Register<T>::BitBandedBit::set()
{
    write(1);
}

template <typename T>
void Register<T>::BitBandedBit::clear()
{
    write(0);
}

template <typename T>
void Register<T>::BitBandedBit::write(std::uint32_t value)
{
    reg.write(value);
}

template <typename T>
constexpr std::uint32_t
Register<T>::BitBandedBit::bit_word_address(std::uint32_t bit_band_base,
                                             std::uint32_t byte_offset,
                                             std::uint32_t bit_number)
{
    return bit_band_base + ((byte_offset * 32) + (bit_number * 4));
}

template <typename T>
constexpr std::uint32_t
Register<T>::BitBandedBit::BitBandAddress(std::uint32_t address, std::uint32_t bit_number)
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

template <typename T>
constexpr Register<T>::W1C::W1C(Register* reg, std::uint32_t bit) :
    Bit(reg, bit) {};

template <typename T>
void Register<T>::W1C::clear()
{
    Bit::set();
}

} // namespace port

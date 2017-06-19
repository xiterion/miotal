#pragma once
#if 0
#include <type_traits>

#include <hal/register.hpp>

namespace port {

template <typename T>
class Register_ : public hal::Register<T>
{
private:
    class BitBandedBit;
public:
    using Bit = typename std::conditional<BitBandEnabled::value,
                                          BitBandedBit,
                                          typename hal::Register<T>::Bit>::type;
private:
    class BitBandedBit
    {
    public:
        inline constexpr BitBandedBit(Register_* reg, std::uint32_t bit);

        inline bool read() const;
        inline void set();
        inline void clear();
        inline void write(std::uint32_t value);
    private:
        Register_ reg;

        inline constexpr std::uint32_t bit_word_address(std::uint32_t bit_band_base,
                                                        std::uint32_t byte_offset,
                                                        std::uint32_t bit_number);
        inline constexpr std::uint32_t BitBandAddress(std::uint32_t address,
                                                      std::uint32_t bit_number);
    };
};

using Register = Register_<std::uint32_t>;


template <typename T>
constexpr Register_<T>::BitBandedBit::BitBandedBit(Register_* reg, std::uint32_t bit) :
    reg(Register_(BitBandAddress(reg->address, bit))) {};

template <typename T>
bool Register_<T>::BitBandedBit::read() const
{
    return reg.read();
}

template <typename T>
void Register_<T>::BitBandedBit::set()
{
    write(1);
}

template <typename T>
void Register_<T>::BitBandedBit::clear()
{
    write(0);
}

template <typename T>
void Register_<T>::BitBandedBit::write(std::uint32_t value)
{
    reg.write(value);
}

template <typename T>
constexpr std::uint32_t
Register_<T>::BitBandedBit::bit_word_address(std::uint32_t bit_band_base,
                                             std::uint32_t byte_offset,
                                             std::uint32_t bit_number)
{
    return bit_band_base + ((byte_offset * 32) + (bit_number * 4));
}

template <typename T>
constexpr std::uint32_t
Register_<T>::BitBandedBit::BitBandAddress(std::uint32_t address, std::uint32_t bit_number)
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

} // namespace port
#endif

#pragma once

#include <type_traits>

using BitBandEnabled = std::true_type;
#include <port/ARM/Cortex/M4/Freescale/register.hpp>

namespace port {

struct PORTx_PCRn : public hal::Register
{
    constexpr PORTx_PCRn(std::uint32_t address) : hal::Register(address),
        ISF(this), LK(this), DSE(this), ODE(this),
        PFE(this), SRE(this), PE(this), PS(this) {};

    W1C<24> ISF;
//    Bits<Address, 23, 4> IRQC;
    Bit<15> LK;
//    Bits<Address, 11, 4> MUX;
    Bit<6> DSE;
    Bit<5> ODE;
    Bit<4> PFE;
    Bit<2> SRE;
    Bit<1> PE;
    Bit<0> PS;
};

PORTx_PCRn PORTA_PCR0(0x40049000);

} // namespace port

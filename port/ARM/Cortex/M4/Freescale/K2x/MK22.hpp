#pragma once

#include <type_traits>

using BitBandEnabled = std::true_type;
#include <port/ARM/Cortex/M4/Freescale/register.hpp>

namespace port {

struct PORTx_PCRn : public Register
{
    constexpr PORTx_PCRn(std::uint32_t address) : Register(address),
        ISF(this, 24), IRQC(this, 23, 20), LK(this, 15), MUX(this, 11, 8),
        DSE(this, 6), ODE(this, 5), PFE(this, 4), SRE(this, 2), PE(this, 1), PS(this, 0) {};

    W1C ISF;
    Bits IRQC;
    Bit LK;
    Bits MUX;
    Bit DSE;
    Bit ODE;
    Bit PFE;
    Bit SRE;
    Bit PE;
    Bit PS;
};

PORTx_PCRn PORTA_PCR0(0x40049000);

} // namespace port

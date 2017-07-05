#pragma once

#include <type_traits>

using BitBandEnabled = std::true_type;
#include <port/ARM/Cortex/M4/Freescale/register.hpp>

namespace port {

struct PORTx_PCRn : public Register
{
    constexpr PORTx_PCRn(std::uintptr_t address) : Register(address),
        ISF(address, 24),
        IRQC(address, 23, 20),
        LK(address, 15),
        MUX(address, 11, 8),
        DSE(address, 6),
        ODE(address, 5),
        PFE(address, 4),
        SRE(address, 2),
        PE(address, 1),
        PS(address, 0) {};

    W1C  ISF;
    Bits IRQC;
    Bit  LK;
    Bits MUX;
    Bit  DSE;
    Bit  ODE;
    Bit  PFE;
    Bit  SRE;
    Bit  PE;
    Bit  PS;
};

} // namespace port
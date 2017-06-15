#pragma once

#include <type_traits>

using BitBandEnabled = std::true_type;
#include <port/ARM/Cortex/M4/Freescale/register.hpp>

namespace port {
namespace K22 {

template <std::uint32_t address>
struct PORTx_PCRn : public hal::Register<address>
{
    W1C<address, 24> ISF;
//    Bits<address, 23, 4> IRQC;
    Bit<address, 15> LK;
//    Bits<address, 11, 4> MUX;
    Bit<address, 6> DSE;
    Bit<address, 5> ODE;
    Bit<address, 4> PFE;
    Bit<address, 2> SRE;
    Bit<address, 1> PE;
    Bit<address, 0> PS;
};

PORTx_PCRn<0x40049000> PORTA_PCR0;

} // namespace K22
} // namespace port

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

    void initialize(std::uint32_t interrupt_configuration,
                             bool lock_register,
                    std::uint32_t pin_mux_control,
                             bool drive_strength_enable,
                             bool open_drain_enable,
                             bool passive_filter_enable,
                             bool slew_rate_enable,
                             bool pull_enable,
                             bool pull_select)
    {
        this->write(IRQC.to_word(interrupt_configuration) |
                      LK.to_word(lock_register) |
                     MUX.to_word(pin_mux_control) |
                     DSE.to_word(drive_strength_enable) |
                     ODE.to_word(open_drain_enable) |
                     PFE.to_word(passive_filter_enable) |
                     SRE.to_word(slew_rate_enable) |
                      PE.to_word(pull_enable) |
                      PS.to_word(pull_select));
    }
};


} // namespace port

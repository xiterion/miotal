#pragma once

#include <type_traits>

using BitBandEnabled = std::true_type;
#include <port/ARM/Cortex/M4/Freescale/register.hpp>

namespace port {

enum class Interrupt_Status : bool
{
    not_detected = false,
    detected = true
};

enum class Interrupt_Configuration : std::uint32_t
{
    disabled                    = 0b0000,
    DMA_request_on_rising_edge  = 0b0001,
    DMA_request_on_falling_edge = 0b0010,
    DMA_request_on_either_edge  = 0b0011,
    interrupt_when_logic_0      = 0b1000,
    interrupt_on_rising_edge    = 0b1001,
    interrupt_on_falling_edge   = 0b1010,
    interrupt_on_either_edge    = 0b1011,
    interrupt_when_logic_1      = 0b1100
};

enum class Lock_Register : bool
{
    disabled = false,
    enabled  = true,
};

enum class Pin_Mux_Control : std::uint32_t
{
    disabled_analog    = 0b000,
    alternative_1_GPIO = 0b001,
    alternative_2      = 0b010,
    alternative_3      = 0b011,
    alternative_4      = 0b100,
    alternative_5      = 0b101,
    alternative_6      = 0b110,
    alternative_7      = 0b111
};

enum class Drive_Strength_Enable : bool
{
    low  = false,
    high = true
};

enum class Open_Drain_Enable : bool
{
    disabled = false,
    enabled  = true
};

enum class Passive_Filter_Enable : bool
{
    disabled = false,
    enabled  = true
};

enum class Slew_Rate_Enable : bool
{
    fast = false,
    slow = true
};

enum class Pull_Enable : bool
{
    disabled = false,
    enabled  = true
};

enum class Pull_Select : bool
{
    down = false,
    up   = true
};

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

    W1C<Interrupt_Status>  ISF;
    Bits<Interrupt_Configuration> IRQC;
    Bit<Lock_Register>  LK;
    Bits<Pin_Mux_Control> MUX;
    Bit<Drive_Strength_Enable>  DSE;
    Bit<Open_Drain_Enable>  ODE;
    Bit<Passive_Filter_Enable>  PFE;
    Bit<Slew_Rate_Enable>  SRE;
    Bit<Pull_Enable>  PE;
    Bit<Pull_Select>  PS;

    void initialize(Interrupt_Configuration irqc,
                    Lock_Register           lk,
                    Pin_Mux_Control         mux,
                    Drive_Strength_Enable   dse,
                    Open_Drain_Enable       ode,
                    Passive_Filter_Enable   pfe,
                    Slew_Rate_Enable        sre,
                    Pull_Enable             pe,
                    Pull_Select             ps)
    {
        this->write(IRQC.to_word(irqc) |
                      LK.to_word(lk)   |
                     MUX.to_word(mux)  |
                     DSE.to_word(dse)  |
                     ODE.to_word(ode)  |
                     PFE.to_word(pfe)  |
                     SRE.to_word(sre)  |
                      PE.to_word(pe)   |
                      PS.to_word(ps));
    }
};

} // namespace port

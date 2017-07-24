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

enum class Drive_Strength : bool
{
    low  = false,
    high = true
};

enum class Open_Drain : bool
{
    disabled = false,
    enabled  = true
};

enum class Passive_Filter : bool
{
    disabled = false,
    enabled  = true
};

enum class Slew_Rate : bool
{
    fast = false,
    slow = true
};

enum class Internal_Pull : bool
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
        ISF(address), IRQC(address), LK(address), MUX(address), DSE(address),
		ODE(address), PFE(address), SRE(address), PE(address), PS(address) {};

    W1C<Interrupt_Status, 24>  ISF;
    Bits<Interrupt_Configuration, 23, 20> IRQC;
    Bit<Lock_Register, 15>  LK;
    Bits<Pin_Mux_Control, 11, 8> MUX;
    Bit<Drive_Strength, 6>  DSE;
    Bit<Open_Drain, 5>  ODE;
    Bit<Passive_Filter, 4>  PFE;
    Bit<Slew_Rate, 2>  SRE;
    Bit<Internal_Pull, 1>  PE;
    Bit<Pull_Select, 0>  PS;

    void initialize(Interrupt_Configuration irqc,
                    Lock_Register           lk,
                    Pin_Mux_Control         mux,
                    Drive_Strength          dse,
                    Open_Drain              ode,
                    Passive_Filter          pfe,
                    Slew_Rate               sre,
                    Internal_Pull           pe,
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

#include "registers.hpp"

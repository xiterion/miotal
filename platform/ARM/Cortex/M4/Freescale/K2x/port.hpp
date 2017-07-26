#pragma once
#include <type_traits>
#include <numeric>
#include "platform.hpp"
#include <util/bit_manipulation.hpp>

using BitBandEnabled = std::true_type;
#include <platform/ARM/Cortex/M4/Freescale/register.hpp>

#if defined(DEFINE_SYMBOLS)
#define SYMBOL(type, name, ...) type name{__VA_ARGS__}
#else // !defined(DEFINE_SYMBOLS)
#define SYMBOL(type, name, ...) extern type name
#endif

namespace platform {

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


class PORTx_PCRn : public Register
{
public:
    constexpr PORTx_PCRn(std::uintptr_t address) : Register{address},
        ISF{address}, IRQC{address}, LK{address}, MUX{address}, DSE{address},
		ODE{address}, PFE{address}, SRE{address}, PE{address}, PS{address} {}

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

    using Register::write;
    void write(Interrupt_Configuration irqc,
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

class GPCxR : public Register
{
public:
    constexpr GPCxR(std::uintptr_t address) : Register{address},
        LK{address}, MUX{address}, DSE{address}, ODE{address},
        PFE{address}, SRE{address}, PE{address}, PS{address} {}

    using Register::write;
    void write(util::Bitmask   bits,
               Lock_Register   lk,
               Pin_Mux_Control mux,
               Drive_Strength  dse,
               Open_Drain      ode,
               Passive_Filter  pfe,
               Slew_Rate       sre,
               Internal_Pull   pe,
               Pull_Select     ps)
    {
        this->write( LK.to_word(lk)  |
                    MUX.to_word(mux) |
                    DSE.to_word(dse) |
                    ODE.to_word(ode) |
                    PFE.to_word(pfe) |
                    SRE.to_word(sre) |
                     PE.to_word(pe)  |
                     PS.to_word(ps)  |
                     bits.mask);
    }
private:
    Bit<Lock_Register, 15>  LK;
    Bits<Pin_Mux_Control, 11, 8> MUX;
    Bit<Drive_Strength, 6>  DSE;
    Bit<Open_Drain, 5>  ODE;
    Bit<Passive_Filter, 4>  PFE;
    Bit<Slew_Rate, 2>  SRE;
    Bit<Internal_Pull, 1>  PE;
    Bit<Pull_Select, 0>  PS;
};

class PORTx_GPCLR : public GPCxR
{
public:
    using GPCxR::GPCxR;
};

class PORTx_GPCHR : public GPCxR
{
public:
    using GPCxR::GPCxR;
};

class PORTx_ISFR : public Register
{
public:
    constexpr PORTx_ISFR(std::uintptr_t address) : Register{address} {}
};

class PORTx_DFER : public Register
{
public:
    constexpr PORTx_DFER(std::uintptr_t address) : Register{address} {}
};

class PORTx_DFCR : public Register
{
public:
    constexpr PORTx_DFCR(std::uintptr_t address) : Register{address} {}
};

class PORTx_DFWR : public Register
{
public:
    constexpr PORTx_DFWR(std::uintptr_t address) : Register{address} {}
};

SYMBOL(PORTx_PCRn,  PORTA_PCR0,  0x4004'9000);
SYMBOL(PORTx_PCRn,  PORTA_PCR1,  0x4004'9004);
SYMBOL(PORTx_PCRn,  PORTA_PCR2,  0x4004'9008);
SYMBOL(PORTx_PCRn,  PORTA_PCR3,  0x4004'900C);
SYMBOL(PORTx_PCRn,  PORTA_PCR4,  0x4004'9010);
SYMBOL(PORTx_PCRn,  PORTA_PCR5,  0x4004'9014);
SYMBOL(PORTx_PCRn,  PORTA_PCR6,  0x4004'9018);
SYMBOL(PORTx_PCRn,  PORTA_PCR7,  0x4004'901C);
SYMBOL(PORTx_PCRn,  PORTA_PCR8,  0x4004'9020);
SYMBOL(PORTx_PCRn,  PORTA_PCR9,  0x4004'9024);
SYMBOL(PORTx_PCRn,  PORTA_PCR10, 0x4004'9028);
SYMBOL(PORTx_PCRn,  PORTA_PCR11, 0x4004'902C);
SYMBOL(PORTx_PCRn,  PORTA_PCR12, 0x4004'9030);
SYMBOL(PORTx_PCRn,  PORTA_PCR13, 0x4004'9034);
SYMBOL(PORTx_PCRn,  PORTA_PCR14, 0x4004'9038);
SYMBOL(PORTx_PCRn,  PORTA_PCR15, 0x4004'903C);
SYMBOL(PORTx_PCRn,  PORTA_PCR16, 0x4004'9040);
SYMBOL(PORTx_PCRn,  PORTA_PCR17, 0x4004'9044);
SYMBOL(PORTx_PCRn,  PORTA_PCR18, 0x4004'9048);
SYMBOL(PORTx_PCRn,  PORTA_PCR19, 0x4004'904C);
SYMBOL(PORTx_PCRn,  PORTA_PCR20, 0x4004'9050);
SYMBOL(PORTx_PCRn,  PORTA_PCR21, 0x4004'9054);
SYMBOL(PORTx_PCRn,  PORTA_PCR22, 0x4004'9058);
SYMBOL(PORTx_PCRn,  PORTA_PCR23, 0x4004'905C);
SYMBOL(PORTx_PCRn,  PORTA_PCR24, 0x4004'9060);
SYMBOL(PORTx_PCRn,  PORTA_PCR25, 0x4004'9064);
SYMBOL(PORTx_PCRn,  PORTA_PCR26, 0x4004'9068);
SYMBOL(PORTx_PCRn,  PORTA_PCR27, 0x4004'906C);
SYMBOL(PORTx_PCRn,  PORTA_PCR28, 0x4004'9070);
SYMBOL(PORTx_PCRn,  PORTA_PCR29, 0x4004'9074);
SYMBOL(PORTx_PCRn,  PORTA_PCR30, 0x4004'9078);
SYMBOL(PORTx_PCRn,  PORTA_PCR31, 0x4004'907C);
SYMBOL(PORTx_GPCLR, PORTA_GPCLR, 0x4004'9080);
SYMBOL(PORTx_GPCHR, PORTA_GPCHR, 0x4004'9084);
SYMBOL(PORTx_ISFR,  PORTA_ISFR,  0x4004'90A0);
SYMBOL(PORTx_DFER,  PORTA_DFER,  0x4004'90C0);
SYMBOL(PORTx_DFCR,  PORTA_DFCR,  0x4004'90C4);
SYMBOL(PORTx_DFWR,  PORTA_DFWR,  0x4004'90C8);

SYMBOL(PORTx_PCRn,  PORTB_PCR0,  0x4004'A000);
SYMBOL(PORTx_PCRn,  PORTB_PCR1,  0x4004'A004);
SYMBOL(PORTx_PCRn,  PORTB_PCR2,  0x4004'A008);
SYMBOL(PORTx_PCRn,  PORTB_PCR3,  0x4004'A00C);
SYMBOL(PORTx_PCRn,  PORTB_PCR4,  0x4004'A010);
SYMBOL(PORTx_PCRn,  PORTB_PCR5,  0x4004'A014);
SYMBOL(PORTx_PCRn,  PORTB_PCR6,  0x4004'A018);
SYMBOL(PORTx_PCRn,  PORTB_PCR7,  0x4004'A01C);
SYMBOL(PORTx_PCRn,  PORTB_PCR8,  0x4004'A020);
SYMBOL(PORTx_PCRn,  PORTB_PCR9,  0x4004'A024);
SYMBOL(PORTx_PCRn,  PORTB_PCR10, 0x4004'A028);
SYMBOL(PORTx_PCRn,  PORTB_PCR11, 0x4004'A02C);
SYMBOL(PORTx_PCRn,  PORTB_PCR12, 0x4004'A030);
SYMBOL(PORTx_PCRn,  PORTB_PCR13, 0x4004'A034);
SYMBOL(PORTx_PCRn,  PORTB_PCR14, 0x4004'A038);
SYMBOL(PORTx_PCRn,  PORTB_PCR15, 0x4004'A03C);
SYMBOL(PORTx_PCRn,  PORTB_PCR16, 0x4004'A040);
SYMBOL(PORTx_PCRn,  PORTB_PCR17, 0x4004'A044);
SYMBOL(PORTx_PCRn,  PORTB_PCR18, 0x4004'A048);
SYMBOL(PORTx_PCRn,  PORTB_PCR19, 0x4004'A04C);
SYMBOL(PORTx_PCRn,  PORTB_PCR20, 0x4004'A050);
SYMBOL(PORTx_PCRn,  PORTB_PCR21, 0x4004'A054);
SYMBOL(PORTx_PCRn,  PORTB_PCR22, 0x4004'A058);
SYMBOL(PORTx_PCRn,  PORTB_PCR23, 0x4004'A05C);
SYMBOL(PORTx_PCRn,  PORTB_PCR24, 0x4004'A060);
SYMBOL(PORTx_PCRn,  PORTB_PCR25, 0x4004'A064);
SYMBOL(PORTx_PCRn,  PORTB_PCR26, 0x4004'A068);
SYMBOL(PORTx_PCRn,  PORTB_PCR27, 0x4004'A06C);
SYMBOL(PORTx_PCRn,  PORTB_PCR28, 0x4004'A070);
SYMBOL(PORTx_PCRn,  PORTB_PCR29, 0x4004'A074);
SYMBOL(PORTx_PCRn,  PORTB_PCR30, 0x4004'A078);
SYMBOL(PORTx_PCRn,  PORTB_PCR31, 0x4004'A07C);
SYMBOL(PORTx_GPCLR, PORTB_GPCLR, 0x4004'A080);
SYMBOL(PORTx_GPCHR, PORTB_GPCHR, 0x4004'A084);
SYMBOL(PORTx_ISFR,  PORTB_ISFR,  0x4004'A0A0);
SYMBOL(PORTx_DFER,  PORTB_DFER,  0x4004'A0C0);
SYMBOL(PORTx_DFCR,  PORTB_DFCR,  0x4004'A0C4);
SYMBOL(PORTx_DFWR,  PORTB_DFWR,  0x4004'A0C8);

SYMBOL(PORTx_PCRn,  PORTC_PCR0,  0x4004'B000);
SYMBOL(PORTx_PCRn,  PORTC_PCR1,  0x4004'B004);
SYMBOL(PORTx_PCRn,  PORTC_PCR2,  0x4004'B008);
SYMBOL(PORTx_PCRn,  PORTC_PCR3,  0x4004'B00C);
SYMBOL(PORTx_PCRn,  PORTC_PCR4,  0x4004'B010);
SYMBOL(PORTx_PCRn,  PORTC_PCR5,  0x4004'B014);
SYMBOL(PORTx_PCRn,  PORTC_PCR6,  0x4004'B018);
SYMBOL(PORTx_PCRn,  PORTC_PCR7,  0x4004'B01C);
SYMBOL(PORTx_PCRn,  PORTC_PCR8,  0x4004'B020);
SYMBOL(PORTx_PCRn,  PORTC_PCR9,  0x4004'B024);
SYMBOL(PORTx_PCRn,  PORTC_PCR10, 0x4004'B028);
SYMBOL(PORTx_PCRn,  PORTC_PCR11, 0x4004'B02C);
SYMBOL(PORTx_PCRn,  PORTC_PCR12, 0x4004'B030);
SYMBOL(PORTx_PCRn,  PORTC_PCR13, 0x4004'B034);
SYMBOL(PORTx_PCRn,  PORTC_PCR14, 0x4004'B038);
SYMBOL(PORTx_PCRn,  PORTC_PCR15, 0x4004'B03C);
SYMBOL(PORTx_PCRn,  PORTC_PCR16, 0x4004'B040);
SYMBOL(PORTx_PCRn,  PORTC_PCR17, 0x4004'B044);
SYMBOL(PORTx_PCRn,  PORTC_PCR18, 0x4004'B048);
SYMBOL(PORTx_PCRn,  PORTC_PCR19, 0x4004'B04C);
SYMBOL(PORTx_PCRn,  PORTC_PCR20, 0x4004'B050);
SYMBOL(PORTx_PCRn,  PORTC_PCR21, 0x4004'B054);
SYMBOL(PORTx_PCRn,  PORTC_PCR22, 0x4004'B058);
SYMBOL(PORTx_PCRn,  PORTC_PCR23, 0x4004'B05C);
SYMBOL(PORTx_PCRn,  PORTC_PCR24, 0x4004'B060);
SYMBOL(PORTx_PCRn,  PORTC_PCR25, 0x4004'B064);
SYMBOL(PORTx_PCRn,  PORTC_PCR26, 0x4004'B068);
SYMBOL(PORTx_PCRn,  PORTC_PCR27, 0x4004'B06C);
SYMBOL(PORTx_PCRn,  PORTC_PCR28, 0x4004'B070);
SYMBOL(PORTx_PCRn,  PORTC_PCR29, 0x4004'B074);
SYMBOL(PORTx_PCRn,  PORTC_PCR30, 0x4004'B078);
SYMBOL(PORTx_PCRn,  PORTC_PCR31, 0x4004'B07C);
SYMBOL(PORTx_GPCLR, PORTC_GPCLR, 0x4004'B080);
SYMBOL(PORTx_GPCHR, PORTC_GPCHR, 0x4004'B084);
SYMBOL(PORTx_ISFR,  PORTC_ISFR,  0x4004'B0A0);
SYMBOL(PORTx_DFER,  PORTC_DFER,  0x4004'B0C0);
SYMBOL(PORTx_DFCR,  PORTC_DFCR,  0x4004'B0C4);
SYMBOL(PORTx_DFWR,  PORTC_DFWR,  0x4004'B0C8);

SYMBOL(PORTx_PCRn,  PORTD_PCR0,  0x4004'C000);
SYMBOL(PORTx_PCRn,  PORTD_PCR1,  0x4004'C004);
SYMBOL(PORTx_PCRn,  PORTD_PCR2,  0x4004'C008);
SYMBOL(PORTx_PCRn,  PORTD_PCR3,  0x4004'C00C);
SYMBOL(PORTx_PCRn,  PORTD_PCR4,  0x4004'C010);
SYMBOL(PORTx_PCRn,  PORTD_PCR5,  0x4004'C014);
SYMBOL(PORTx_PCRn,  PORTD_PCR6,  0x4004'C018);
SYMBOL(PORTx_PCRn,  PORTD_PCR7,  0x4004'C01C);
SYMBOL(PORTx_PCRn,  PORTD_PCR8,  0x4004'C020);
SYMBOL(PORTx_PCRn,  PORTD_PCR9,  0x4004'C024);
SYMBOL(PORTx_PCRn,  PORTD_PCR10, 0x4004'C028);
SYMBOL(PORTx_PCRn,  PORTD_PCR11, 0x4004'C02C);
SYMBOL(PORTx_PCRn,  PORTD_PCR12, 0x4004'C030);
SYMBOL(PORTx_PCRn,  PORTD_PCR13, 0x4004'C034);
SYMBOL(PORTx_PCRn,  PORTD_PCR14, 0x4004'C038);
SYMBOL(PORTx_PCRn,  PORTD_PCR15, 0x4004'C03C);
SYMBOL(PORTx_PCRn,  PORTD_PCR16, 0x4004'C040);
SYMBOL(PORTx_PCRn,  PORTD_PCR17, 0x4004'C044);
SYMBOL(PORTx_PCRn,  PORTD_PCR18, 0x4004'C048);
SYMBOL(PORTx_PCRn,  PORTD_PCR19, 0x4004'C04C);
SYMBOL(PORTx_PCRn,  PORTD_PCR20, 0x4004'C050);
SYMBOL(PORTx_PCRn,  PORTD_PCR21, 0x4004'C054);
SYMBOL(PORTx_PCRn,  PORTD_PCR22, 0x4004'C058);
SYMBOL(PORTx_PCRn,  PORTD_PCR23, 0x4004'C05C);
SYMBOL(PORTx_PCRn,  PORTD_PCR24, 0x4004'C060);
SYMBOL(PORTx_PCRn,  PORTD_PCR25, 0x4004'C064);
SYMBOL(PORTx_PCRn,  PORTD_PCR26, 0x4004'C068);
SYMBOL(PORTx_PCRn,  PORTD_PCR27, 0x4004'C06C);
SYMBOL(PORTx_PCRn,  PORTD_PCR28, 0x4004'C070);
SYMBOL(PORTx_PCRn,  PORTD_PCR29, 0x4004'C074);
SYMBOL(PORTx_PCRn,  PORTD_PCR30, 0x4004'C078);
SYMBOL(PORTx_PCRn,  PORTD_PCR31, 0x4004'C07C);
SYMBOL(PORTx_GPCLR, PORTD_GPCLR, 0x4004'C080);
SYMBOL(PORTx_GPCHR, PORTD_GPCHR, 0x4004'C084);
SYMBOL(PORTx_ISFR,  PORTD_ISFR,  0x4004'C0A0);
SYMBOL(PORTx_DFER,  PORTD_DFER,  0x4004'C0C0);
SYMBOL(PORTx_DFCR,  PORTD_DFCR,  0x4004'C0C4);
SYMBOL(PORTx_DFWR,  PORTD_DFWR,  0x4004'C0C8);

SYMBOL(PORTx_PCRn,  PORTE_PCR0,  0x4004'D000);
SYMBOL(PORTx_PCRn,  PORTE_PCR1,  0x4004'D004);
SYMBOL(PORTx_PCRn,  PORTE_PCR2,  0x4004'D008);
SYMBOL(PORTx_PCRn,  PORTE_PCR3,  0x4004'D00C);
SYMBOL(PORTx_PCRn,  PORTE_PCR4,  0x4004'D010);
SYMBOL(PORTx_PCRn,  PORTE_PCR5,  0x4004'D014);
SYMBOL(PORTx_PCRn,  PORTE_PCR6,  0x4004'D018);
SYMBOL(PORTx_PCRn,  PORTE_PCR7,  0x4004'D01C);
SYMBOL(PORTx_PCRn,  PORTE_PCR8,  0x4004'D020);
SYMBOL(PORTx_PCRn,  PORTE_PCR9,  0x4004'D024);
SYMBOL(PORTx_PCRn,  PORTE_PCR10, 0x4004'D028);
SYMBOL(PORTx_PCRn,  PORTE_PCR11, 0x4004'D02C);
SYMBOL(PORTx_PCRn,  PORTE_PCR12, 0x4004'D030);
SYMBOL(PORTx_PCRn,  PORTE_PCR13, 0x4004'D034);
SYMBOL(PORTx_PCRn,  PORTE_PCR14, 0x4004'D038);
SYMBOL(PORTx_PCRn,  PORTE_PCR15, 0x4004'D03C);
SYMBOL(PORTx_PCRn,  PORTE_PCR16, 0x4004'D040);
SYMBOL(PORTx_PCRn,  PORTE_PCR17, 0x4004'D044);
SYMBOL(PORTx_PCRn,  PORTE_PCR18, 0x4004'D048);
SYMBOL(PORTx_PCRn,  PORTE_PCR19, 0x4004'D04C);
SYMBOL(PORTx_PCRn,  PORTE_PCR20, 0x4004'D050);
SYMBOL(PORTx_PCRn,  PORTE_PCR21, 0x4004'D054);
SYMBOL(PORTx_PCRn,  PORTE_PCR22, 0x4004'D058);
SYMBOL(PORTx_PCRn,  PORTE_PCR23, 0x4004'D05C);
SYMBOL(PORTx_PCRn,  PORTE_PCR24, 0x4004'D060);
SYMBOL(PORTx_PCRn,  PORTE_PCR25, 0x4004'D064);
SYMBOL(PORTx_PCRn,  PORTE_PCR26, 0x4004'D068);
SYMBOL(PORTx_PCRn,  PORTE_PCR27, 0x4004'D06C);
SYMBOL(PORTx_PCRn,  PORTE_PCR28, 0x4004'D070);
SYMBOL(PORTx_PCRn,  PORTE_PCR29, 0x4004'D074);
SYMBOL(PORTx_PCRn,  PORTE_PCR30, 0x4004'D078);
SYMBOL(PORTx_PCRn,  PORTE_PCR31, 0x4004'D07C);
SYMBOL(PORTx_GPCLR, PORTE_GPCLR, 0x4004'D080);
SYMBOL(PORTx_GPCHR, PORTE_GPCHR, 0x4004'D084);
SYMBOL(PORTx_ISFR,  PORTE_ISFR,  0x4004'D0A0);
SYMBOL(PORTx_DFER,  PORTE_DFER,  0x4004'D0C0);
SYMBOL(PORTx_DFCR,  PORTE_DFCR,  0x4004'D0C4);
SYMBOL(PORTx_DFWR,  PORTE_DFWR,  0x4004'D0C8);

} // namespace platform

#undef SYMBOL

#pragma once
#include "platform.hpp"

#include <util/bit_manipulation.hpp>
#include <platform/ARM/Cortex/M4/Freescale/register.hpp>

#if defined(DEFINE_SYMBOLS)
#define REGISTER(type, name, ...) extern const type name {__VA_ARGS__}
#else // !defined(DEFINE_SYMBOLS)
#define REGISTER(type, name, ...) extern const type name;
#endif

namespace platform {

struct PORTx_PCRn : public Register<PORTx_PCRn>
{
    using Register<PORTx_PCRn>::Register;

    using Interrupt_Status = W1C<PORTx_PCRn, 24>;
    auto ISF() const { return Interrupt_Status::read(*this); }
    auto ISF(Interrupt_Status::clear_flag) const { Interrupt_Status::clear(*this); }
    static constexpr Interrupt_Status interrupt_not_active {false};
    static constexpr Interrupt_Status interrupt_active {true};
    static constexpr Interrupt_Status::clear_flag clear_interrupt {};

    using Interrupt_Configuration = Bitfield<PORTx_PCRn, 16, 4>;
    auto IRQC() const { return Interrupt_Configuration::read(*this); }
    auto IRQC(Interrupt_Configuration val) const { Interrupt_Configuration::write(*this, val); }
    static constexpr Interrupt_Configuration interrupt_DMA_disabled {0b0000};
    static constexpr Interrupt_Configuration DMA_request_on_rising_edge {0b0001};
    static constexpr Interrupt_Configuration DMA_request_on_falling_edge {0b0010};
    static constexpr Interrupt_Configuration DMA_request_on_either_edge {0b0011};
    static constexpr Interrupt_Configuration interrupt_when_logic_0 {0b1000};
    static constexpr Interrupt_Configuration interrupt_on_rising_edge {0b1001};
    static constexpr Interrupt_Configuration interrupt_on_falling_edge {0b1010};
    static constexpr Interrupt_Configuration interrupt_on_either_edge {0b1011};
    static constexpr Interrupt_Configuration interrupt_when_logic_1 {0b1100};

    using Lock_Register = Bitfield<PORTx_PCRn, 15>;
    auto LK() const { return Lock_Register::read(*this); }
    auto LK(Lock_Register val) const { Lock_Register::write(*this, val); }
    static constexpr Lock_Register unlocked {0};
    static constexpr Lock_Register locked {1};

    using Pin_Mux_Control = Bitfield<PORTx_PCRn, 8, 3>;
    auto MUX() const { return Pin_Mux_Control::read(*this); }
    auto MUX(Pin_Mux_Control val) const { Pin_Mux_Control::write(*this, val); }
    static constexpr Pin_Mux_Control disabled_analog {0b000};
    static constexpr Pin_Mux_Control alternative_1_GPIO {0b001};
    static constexpr Pin_Mux_Control alternative_2 {0b010};
    static constexpr Pin_Mux_Control alternative_3 {0b011};
    static constexpr Pin_Mux_Control alternative_4 {0b100};
    static constexpr Pin_Mux_Control alternative_5 {0b101};
    static constexpr Pin_Mux_Control alternative_6 {0b110};
    static constexpr Pin_Mux_Control alternative_7 {0b111};

    using Drive_Strength = Bitfield<PORTx_PCRn, 6>;
    auto DSE() { return Drive_Strength::read(*this); }
    auto DSE(Drive_Strength val) { Drive_Strength::write(*this, val); }
    static constexpr Drive_Strength low_drive {false};
    static constexpr Drive_Strength high_drive {true};

    using Open_Drain = Bitfield<PORTx_PCRn, 5>;
    auto ODE() { return Open_Drain::read(*this); }
    auto ODE(Open_Drain val) { return Open_Drain::write(*this, val); }
    static constexpr Open_Drain open_drain_disabled {false};
    static constexpr Open_Drain open_drain_enabled {true};

    using Passive_Filter = Bitfield<PORTx_PCRn, 4>;
    auto PFE() { return Passive_Filter::read(*this); }
    auto PFE(Passive_Filter val) { return Passive_Filter::write(*this, val); }
    static constexpr Passive_Filter passive_filter_disabled {false};
    static constexpr Passive_Filter passive_filter_enabled {true};

    using Slew_Rate = Bitfield<PORTx_PCRn, 2>;
    auto SRE() { return Slew_Rate::read(*this); }
    auto SRE(Slew_Rate val) { Slew_Rate::write(*this, val); }
    static constexpr Slew_Rate fast_slew_rate {false};
    static constexpr Slew_Rate slow_slew_rate {true};

    using Internal_Pull = Bitfield<PORTx_PCRn, 1>;
    auto PE() { return Internal_Pull::read(*this); }
    auto PE(Internal_Pull val) { Internal_Pull::write(*this, val); }
    static constexpr Internal_Pull internal_pull_disabled {false};
    static constexpr Internal_Pull internal_pull_enabled  {true};

    using Pull_Select = Bitfield<PORTx_PCRn, 0>;
    auto PS() { return Pull_Select::read(*this); }
    auto PS(Pull_Select val) { Pull_Select::write(*this, val); }
    static constexpr Pull_Select pull_down {false};
    static constexpr Pull_Select pull_up   {true};
};

// Note: this register shares most of its features in common with
// PORTx_GPCHR.  The compiler currently will not suffer refactoring
// their commmon behavior into a base class and retain the desired
// optimization level.  Some amount of copy-pasta results.

class PORTx_GPCLR : public Register<PORTx_GPCLR>
{
public:
    using Register<PORTx_GPCLR>::Register;
};

class PORTx_GPCHR : public Register<PORTx_GPCHR>
{
public:
    using Register<PORTx_GPCHR>::Register;
};

class PORTx_ISFR : public Register<PORTx_ISFR>
{
public:
    using Register<PORTx_ISFR>::Register;

    template <typename... Bits>
    void clear(Bits... bits) { this->write(util::Bitmask<std::uint32_t>{bits...}.mask); }
    template <typename... Bits>
    bool is_set(Bits... pins) { return this->read() & util::Bitmask<std::uint32_t>{pins...}.mask; }
};

class PORTx_DFER : public Register<PORTx_DFER>
{
public:
    using Register<PORTx_DFER>::Register;

    template <typename... Bits>
    void enable_filter_for_pins(Bits... bits) {
        write(read() | util::Bitmask<std::uint32_t>{bits...}.mask);
    }
    template <typename... Bits>
    void disable_filter_for_pins(Bits... bits) {
        write(read() & ~util::Bitmask<std::uint32_t>{bits...}.mask);
    }
};

class PORTx_DFCR : public Register<PORTx_DFCR>
{
public:
    using Register<PORTx_DFCR>::Register;

    using Clock_Source = Bitfield<PORTx_DFCR, 0>;
    auto CS() const { return Clock_Source::read(*this); }
    auto CS(Clock_Source val) const { Clock_Source::write(*this, val); }
    static constexpr Clock_Source bus_clock {false};
    static constexpr Clock_Source LPO_1_kHz {true};
};

class PORTx_DFWR : public Register<PORTx_DFWR>
{
public:
    using Register<PORTx_DFWR>::Register;

    void write_filter_length(std::uint32_t length) { write(length & 0b11111u); }
    std::uint32_t read_filter_length() { return read(); }
};

REGISTER(PORTx_PCRn,  PORTA_PCR0,  0x4004'9000);
REGISTER(PORTx_PCRn,  PORTA_PCR1,  0x4004'9004);
REGISTER(PORTx_PCRn,  PORTA_PCR2,  0x4004'9008);
REGISTER(PORTx_PCRn,  PORTA_PCR3,  0x4004'900C);
REGISTER(PORTx_PCRn,  PORTA_PCR4,  0x4004'9010);
REGISTER(PORTx_PCRn,  PORTA_PCR5,  0x4004'9014);
REGISTER(PORTx_PCRn,  PORTA_PCR6,  0x4004'9018);
REGISTER(PORTx_PCRn,  PORTA_PCR7,  0x4004'901C);
REGISTER(PORTx_PCRn,  PORTA_PCR8,  0x4004'9020);
REGISTER(PORTx_PCRn,  PORTA_PCR9,  0x4004'9024);
REGISTER(PORTx_PCRn,  PORTA_PCR10, 0x4004'9028);
REGISTER(PORTx_PCRn,  PORTA_PCR11, 0x4004'902C);
REGISTER(PORTx_PCRn,  PORTA_PCR12, 0x4004'9030);
REGISTER(PORTx_PCRn,  PORTA_PCR13, 0x4004'9034);
REGISTER(PORTx_PCRn,  PORTA_PCR14, 0x4004'9038);
REGISTER(PORTx_PCRn,  PORTA_PCR15, 0x4004'903C);
REGISTER(PORTx_PCRn,  PORTA_PCR16, 0x4004'9040);
REGISTER(PORTx_PCRn,  PORTA_PCR17, 0x4004'9044);
REGISTER(PORTx_PCRn,  PORTA_PCR18, 0x4004'9048);
REGISTER(PORTx_PCRn,  PORTA_PCR19, 0x4004'904C);
REGISTER(PORTx_PCRn,  PORTA_PCR20, 0x4004'9050);
REGISTER(PORTx_PCRn,  PORTA_PCR21, 0x4004'9054);
REGISTER(PORTx_PCRn,  PORTA_PCR22, 0x4004'9058);
REGISTER(PORTx_PCRn,  PORTA_PCR23, 0x4004'905C);
REGISTER(PORTx_PCRn,  PORTA_PCR24, 0x4004'9060);
REGISTER(PORTx_PCRn,  PORTA_PCR25, 0x4004'9064);
REGISTER(PORTx_PCRn,  PORTA_PCR26, 0x4004'9068);
REGISTER(PORTx_PCRn,  PORTA_PCR27, 0x4004'906C);
REGISTER(PORTx_PCRn,  PORTA_PCR28, 0x4004'9070);
REGISTER(PORTx_PCRn,  PORTA_PCR29, 0x4004'9074);
REGISTER(PORTx_PCRn,  PORTA_PCR30, 0x4004'9078);
REGISTER(PORTx_PCRn,  PORTA_PCR31, 0x4004'907C);
REGISTER(PORTx_GPCLR, PORTA_GPCLR, 0x4004'9080);
REGISTER(PORTx_GPCHR, PORTA_GPCHR, 0x4004'9084);
REGISTER(PORTx_ISFR,  PORTA_ISFR,  0x4004'90A0);
REGISTER(PORTx_DFER,  PORTA_DFER,  0x4004'90C0);
REGISTER(PORTx_DFCR,  PORTA_DFCR,  0x4004'90C4);
REGISTER(PORTx_DFWR,  PORTA_DFWR,  0x4004'90C8);

REGISTER(PORTx_PCRn,  PORTB_PCR0,  0x4004'A000);
REGISTER(PORTx_PCRn,  PORTB_PCR1,  0x4004'A004);
REGISTER(PORTx_PCRn,  PORTB_PCR2,  0x4004'A008);
REGISTER(PORTx_PCRn,  PORTB_PCR3,  0x4004'A00C);
REGISTER(PORTx_PCRn,  PORTB_PCR4,  0x4004'A010);
REGISTER(PORTx_PCRn,  PORTB_PCR5,  0x4004'A014);
REGISTER(PORTx_PCRn,  PORTB_PCR6,  0x4004'A018);
REGISTER(PORTx_PCRn,  PORTB_PCR7,  0x4004'A01C);
REGISTER(PORTx_PCRn,  PORTB_PCR8,  0x4004'A020);
REGISTER(PORTx_PCRn,  PORTB_PCR9,  0x4004'A024);
REGISTER(PORTx_PCRn,  PORTB_PCR10, 0x4004'A028);
REGISTER(PORTx_PCRn,  PORTB_PCR11, 0x4004'A02C);
REGISTER(PORTx_PCRn,  PORTB_PCR12, 0x4004'A030);
REGISTER(PORTx_PCRn,  PORTB_PCR13, 0x4004'A034);
REGISTER(PORTx_PCRn,  PORTB_PCR14, 0x4004'A038);
REGISTER(PORTx_PCRn,  PORTB_PCR15, 0x4004'A03C);
REGISTER(PORTx_PCRn,  PORTB_PCR16, 0x4004'A040);
REGISTER(PORTx_PCRn,  PORTB_PCR17, 0x4004'A044);
REGISTER(PORTx_PCRn,  PORTB_PCR18, 0x4004'A048);
REGISTER(PORTx_PCRn,  PORTB_PCR19, 0x4004'A04C);
REGISTER(PORTx_PCRn,  PORTB_PCR20, 0x4004'A050);
REGISTER(PORTx_PCRn,  PORTB_PCR21, 0x4004'A054);
REGISTER(PORTx_PCRn,  PORTB_PCR22, 0x4004'A058);
REGISTER(PORTx_PCRn,  PORTB_PCR23, 0x4004'A05C);
REGISTER(PORTx_PCRn,  PORTB_PCR24, 0x4004'A060);
REGISTER(PORTx_PCRn,  PORTB_PCR25, 0x4004'A064);
REGISTER(PORTx_PCRn,  PORTB_PCR26, 0x4004'A068);
REGISTER(PORTx_PCRn,  PORTB_PCR27, 0x4004'A06C);
REGISTER(PORTx_PCRn,  PORTB_PCR28, 0x4004'A070);
REGISTER(PORTx_PCRn,  PORTB_PCR29, 0x4004'A074);
REGISTER(PORTx_PCRn,  PORTB_PCR30, 0x4004'A078);
REGISTER(PORTx_PCRn,  PORTB_PCR31, 0x4004'A07C);
REGISTER(PORTx_GPCLR, PORTB_GPCLR, 0x4004'A080);
REGISTER(PORTx_GPCHR, PORTB_GPCHR, 0x4004'A084);
REGISTER(PORTx_ISFR,  PORTB_ISFR,  0x4004'A0A0);
REGISTER(PORTx_DFER,  PORTB_DFER,  0x4004'A0C0);
REGISTER(PORTx_DFCR,  PORTB_DFCR,  0x4004'A0C4);
REGISTER(PORTx_DFWR,  PORTB_DFWR,  0x4004'A0C8);

REGISTER(PORTx_PCRn,  PORTC_PCR0,  0x4004'B000);
REGISTER(PORTx_PCRn,  PORTC_PCR1,  0x4004'B004);
REGISTER(PORTx_PCRn,  PORTC_PCR2,  0x4004'B008);
REGISTER(PORTx_PCRn,  PORTC_PCR3,  0x4004'B00C);
REGISTER(PORTx_PCRn,  PORTC_PCR4,  0x4004'B010);
REGISTER(PORTx_PCRn,  PORTC_PCR5,  0x4004'B014);
REGISTER(PORTx_PCRn,  PORTC_PCR6,  0x4004'B018);
REGISTER(PORTx_PCRn,  PORTC_PCR7,  0x4004'B01C);
REGISTER(PORTx_PCRn,  PORTC_PCR8,  0x4004'B020);
REGISTER(PORTx_PCRn,  PORTC_PCR9,  0x4004'B024);
REGISTER(PORTx_PCRn,  PORTC_PCR10, 0x4004'B028);
REGISTER(PORTx_PCRn,  PORTC_PCR11, 0x4004'B02C);
REGISTER(PORTx_PCRn,  PORTC_PCR12, 0x4004'B030);
REGISTER(PORTx_PCRn,  PORTC_PCR13, 0x4004'B034);
REGISTER(PORTx_PCRn,  PORTC_PCR14, 0x4004'B038);
REGISTER(PORTx_PCRn,  PORTC_PCR15, 0x4004'B03C);
REGISTER(PORTx_PCRn,  PORTC_PCR16, 0x4004'B040);
REGISTER(PORTx_PCRn,  PORTC_PCR17, 0x4004'B044);
REGISTER(PORTx_PCRn,  PORTC_PCR18, 0x4004'B048);
REGISTER(PORTx_PCRn,  PORTC_PCR19, 0x4004'B04C);
REGISTER(PORTx_PCRn,  PORTC_PCR20, 0x4004'B050);
REGISTER(PORTx_PCRn,  PORTC_PCR21, 0x4004'B054);
REGISTER(PORTx_PCRn,  PORTC_PCR22, 0x4004'B058);
REGISTER(PORTx_PCRn,  PORTC_PCR23, 0x4004'B05C);
REGISTER(PORTx_PCRn,  PORTC_PCR24, 0x4004'B060);
REGISTER(PORTx_PCRn,  PORTC_PCR25, 0x4004'B064);
REGISTER(PORTx_PCRn,  PORTC_PCR26, 0x4004'B068);
REGISTER(PORTx_PCRn,  PORTC_PCR27, 0x4004'B06C);
REGISTER(PORTx_PCRn,  PORTC_PCR28, 0x4004'B070);
REGISTER(PORTx_PCRn,  PORTC_PCR29, 0x4004'B074);
REGISTER(PORTx_PCRn,  PORTC_PCR30, 0x4004'B078);
REGISTER(PORTx_PCRn,  PORTC_PCR31, 0x4004'B07C);
REGISTER(PORTx_GPCLR, PORTC_GPCLR, 0x4004'B080);
REGISTER(PORTx_GPCHR, PORTC_GPCHR, 0x4004'B084);
REGISTER(PORTx_ISFR,  PORTC_ISFR,  0x4004'B0A0);
REGISTER(PORTx_DFER,  PORTC_DFER,  0x4004'B0C0);
REGISTER(PORTx_DFCR,  PORTC_DFCR,  0x4004'B0C4);
REGISTER(PORTx_DFWR,  PORTC_DFWR,  0x4004'B0C8);

REGISTER(PORTx_PCRn,  PORTD_PCR0,  0x4004'C000);
REGISTER(PORTx_PCRn,  PORTD_PCR1,  0x4004'C004);
REGISTER(PORTx_PCRn,  PORTD_PCR2,  0x4004'C008);
REGISTER(PORTx_PCRn,  PORTD_PCR3,  0x4004'C00C);
REGISTER(PORTx_PCRn,  PORTD_PCR4,  0x4004'C010);
REGISTER(PORTx_PCRn,  PORTD_PCR5,  0x4004'C014);
REGISTER(PORTx_PCRn,  PORTD_PCR6,  0x4004'C018);
REGISTER(PORTx_PCRn,  PORTD_PCR7,  0x4004'C01C);
REGISTER(PORTx_PCRn,  PORTD_PCR8,  0x4004'C020);
REGISTER(PORTx_PCRn,  PORTD_PCR9,  0x4004'C024);
REGISTER(PORTx_PCRn,  PORTD_PCR10, 0x4004'C028);
REGISTER(PORTx_PCRn,  PORTD_PCR11, 0x4004'C02C);
REGISTER(PORTx_PCRn,  PORTD_PCR12, 0x4004'C030);
REGISTER(PORTx_PCRn,  PORTD_PCR13, 0x4004'C034);
REGISTER(PORTx_PCRn,  PORTD_PCR14, 0x4004'C038);
REGISTER(PORTx_PCRn,  PORTD_PCR15, 0x4004'C03C);
REGISTER(PORTx_PCRn,  PORTD_PCR16, 0x4004'C040);
REGISTER(PORTx_PCRn,  PORTD_PCR17, 0x4004'C044);
REGISTER(PORTx_PCRn,  PORTD_PCR18, 0x4004'C048);
REGISTER(PORTx_PCRn,  PORTD_PCR19, 0x4004'C04C);
REGISTER(PORTx_PCRn,  PORTD_PCR20, 0x4004'C050);
REGISTER(PORTx_PCRn,  PORTD_PCR21, 0x4004'C054);
REGISTER(PORTx_PCRn,  PORTD_PCR22, 0x4004'C058);
REGISTER(PORTx_PCRn,  PORTD_PCR23, 0x4004'C05C);
REGISTER(PORTx_PCRn,  PORTD_PCR24, 0x4004'C060);
REGISTER(PORTx_PCRn,  PORTD_PCR25, 0x4004'C064);
REGISTER(PORTx_PCRn,  PORTD_PCR26, 0x4004'C068);
REGISTER(PORTx_PCRn,  PORTD_PCR27, 0x4004'C06C);
REGISTER(PORTx_PCRn,  PORTD_PCR28, 0x4004'C070);
REGISTER(PORTx_PCRn,  PORTD_PCR29, 0x4004'C074);
REGISTER(PORTx_PCRn,  PORTD_PCR30, 0x4004'C078);
REGISTER(PORTx_PCRn,  PORTD_PCR31, 0x4004'C07C);
REGISTER(PORTx_GPCLR, PORTD_GPCLR, 0x4004'C080);
REGISTER(PORTx_GPCHR, PORTD_GPCHR, 0x4004'C084);
REGISTER(PORTx_ISFR,  PORTD_ISFR,  0x4004'C0A0);
REGISTER(PORTx_DFER,  PORTD_DFER,  0x4004'C0C0);
REGISTER(PORTx_DFCR,  PORTD_DFCR,  0x4004'C0C4);
REGISTER(PORTx_DFWR,  PORTD_DFWR,  0x4004'C0C8);

REGISTER(PORTx_PCRn,  PORTE_PCR0,  0x4004'D000);
REGISTER(PORTx_PCRn,  PORTE_PCR1,  0x4004'D004);
REGISTER(PORTx_PCRn,  PORTE_PCR2,  0x4004'D008);
REGISTER(PORTx_PCRn,  PORTE_PCR3,  0x4004'D00C);
REGISTER(PORTx_PCRn,  PORTE_PCR4,  0x4004'D010);
REGISTER(PORTx_PCRn,  PORTE_PCR5,  0x4004'D014);
REGISTER(PORTx_PCRn,  PORTE_PCR6,  0x4004'D018);
REGISTER(PORTx_PCRn,  PORTE_PCR7,  0x4004'D01C);
REGISTER(PORTx_PCRn,  PORTE_PCR8,  0x4004'D020);
REGISTER(PORTx_PCRn,  PORTE_PCR9,  0x4004'D024);
REGISTER(PORTx_PCRn,  PORTE_PCR10, 0x4004'D028);
REGISTER(PORTx_PCRn,  PORTE_PCR11, 0x4004'D02C);
REGISTER(PORTx_PCRn,  PORTE_PCR12, 0x4004'D030);
REGISTER(PORTx_PCRn,  PORTE_PCR13, 0x4004'D034);
REGISTER(PORTx_PCRn,  PORTE_PCR14, 0x4004'D038);
REGISTER(PORTx_PCRn,  PORTE_PCR15, 0x4004'D03C);
REGISTER(PORTx_PCRn,  PORTE_PCR16, 0x4004'D040);
REGISTER(PORTx_PCRn,  PORTE_PCR17, 0x4004'D044);
REGISTER(PORTx_PCRn,  PORTE_PCR18, 0x4004'D048);
REGISTER(PORTx_PCRn,  PORTE_PCR19, 0x4004'D04C);
REGISTER(PORTx_PCRn,  PORTE_PCR20, 0x4004'D050);
REGISTER(PORTx_PCRn,  PORTE_PCR21, 0x4004'D054);
REGISTER(PORTx_PCRn,  PORTE_PCR22, 0x4004'D058);
REGISTER(PORTx_PCRn,  PORTE_PCR23, 0x4004'D05C);
REGISTER(PORTx_PCRn,  PORTE_PCR24, 0x4004'D060);
REGISTER(PORTx_PCRn,  PORTE_PCR25, 0x4004'D064);
REGISTER(PORTx_PCRn,  PORTE_PCR26, 0x4004'D068);
REGISTER(PORTx_PCRn,  PORTE_PCR27, 0x4004'D06C);
REGISTER(PORTx_PCRn,  PORTE_PCR28, 0x4004'D070);
REGISTER(PORTx_PCRn,  PORTE_PCR29, 0x4004'D074);
REGISTER(PORTx_PCRn,  PORTE_PCR30, 0x4004'D078);
REGISTER(PORTx_PCRn,  PORTE_PCR31, 0x4004'D07C);
REGISTER(PORTx_GPCLR, PORTE_GPCLR, 0x4004'D080);
REGISTER(PORTx_GPCHR, PORTE_GPCHR, 0x4004'D084);
REGISTER(PORTx_ISFR,  PORTE_ISFR,  0x4004'D0A0);
REGISTER(PORTx_DFER,  PORTE_DFER,  0x4004'D0C0);
REGISTER(PORTx_DFCR,  PORTE_DFCR,  0x4004'D0C4);
REGISTER(PORTx_DFWR,  PORTE_DFWR,  0x4004'D0C8);

} // namespace platform

#undef REGISTER

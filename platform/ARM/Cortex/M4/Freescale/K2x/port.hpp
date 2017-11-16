#pragma once

#include <util/bit_manipulation.hpp>
#include <platform/ARM/Cortex/M4/Freescale/register.hpp>

/* W1C bitfield
   using field_type = W1C<register_name, offset>;
   auto field_name const { return field_type::read(*this); }
   auto field_name(field_type::clear_flag) const { field_type::clear(*this); }
   static constexpr field_type name {value};
   static constexpr field_type::clear_flag name {};
*/

/* Single bit
   using field_type = Bitfield<register_name, offset>;
   auto field_name const { return field_type::read(*this); }
   auto field_name(field_type val) const { field_type::write(*this, val); }
   static constexpr field_type name {value};
*/

/* Multi-bit
   using field_type = Bitfield<register_name, offset, length>;
   auto field_name const { return field_type::read(*this); }
   auto field_name(field_type val) const { field_type::write(*this, val); }
   static constexpr field_type name {value};
*/

namespace platform::port {

struct PORTx_PCRn : public Register<PORTx_PCRn> {
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

struct PORTx_GPCyR : public Register<PORTx_GPCyR> {
    using Register<PORTx_GPCyR>::Register;

    using Lock_Register = Bitfield<PORTx_GPCyR, 15>;
    static constexpr Lock_Register unlocked {0};
    static constexpr Lock_Register locked {1};

    using Pin_Mux_Control = Bitfield<PORTx_GPCyR, 8, 3>;
    static constexpr Pin_Mux_Control disabled_analog {0b000};
    static constexpr Pin_Mux_Control alternative_1_GPIO {0b001};
    static constexpr Pin_Mux_Control alternative_2 {0b010};
    static constexpr Pin_Mux_Control alternative_3 {0b011};
    static constexpr Pin_Mux_Control alternative_4 {0b100};
    static constexpr Pin_Mux_Control alternative_5 {0b101};
    static constexpr Pin_Mux_Control alternative_6 {0b110};
    static constexpr Pin_Mux_Control alternative_7 {0b111};

    using Drive_Strength = Bitfield<PORTx_GPCyR, 6>;
    static constexpr Drive_Strength low_drive {false};
    static constexpr Drive_Strength high_drive {true};

    using Open_Drain = Bitfield<PORTx_GPCyR, 5>;
    static constexpr Open_Drain open_drain_disabled {false};
    static constexpr Open_Drain open_drain_enabled {true};

    using Passive_Filter = Bitfield<PORTx_GPCyR, 4>;
    static constexpr Passive_Filter passive_filter_disabled {false};
    static constexpr Passive_Filter passive_filter_enabled {true};

    using Slew_Rate = Bitfield<PORTx_GPCyR, 2>;
    static constexpr Slew_Rate fast_slew_rate {false};
    static constexpr Slew_Rate slow_slew_rate {true};

    using Internal_Pull = Bitfield<PORTx_GPCyR, 1>;
    static constexpr Internal_Pull internal_pull_disabled {false};
    static constexpr Internal_Pull internal_pull_enabled  {true};

    using Pull_Select = Bitfield<PORTx_GPCyR, 0>;
    static constexpr Pull_Select pull_down {false};
    static constexpr Pull_Select pull_up   {true};
};

struct PORTx_GPCLR : public PORTx_GPCyR {
    using PORTx_GPCyR::PORTx_GPCyR;

    template <typename... Args>
    std::enable_if_t<
        std::conjunction<std::is_base_of<typename Args::register_t, PORTx_GPCLR>...>::value>
    set(const util::Bitmask<std::uint32_t> bits, const Args... args) const {
        write((bits.mask << 16) | value(args...));
    }
};

struct PORTx_GPCHR : public PORTx_GPCyR {
    using PORTx_GPCyR::PORTx_GPCyR;

    template <typename... Args>
    std::enable_if_t<
        std::conjunction<std::is_base_of<typename Args::register_t, PORTx_GPCHR>...>::value>
    set(util::Bitmask<std::uint32_t> bits, Args... args) const {
        write(bits.mask | value(args...));
    }
};

struct PORTx_ISFR : public Register<PORTx_ISFR> {
    using Register<PORTx_ISFR>::Register;

    template <typename... Bits>
    void clear(Bits... bits) const { write(util::Bitmask<std::uint32_t>{bits...}.mask); }
    template <typename... Bits>
    bool is_set(Bits... pins) const { return read() & util::Bitmask<std::uint32_t>{pins...}.mask; }
};

struct PORTx_DFER : public Register<PORTx_DFER> {
    using Register<PORTx_DFER>::Register;

    template <typename... Bits>
    void enable_filter_for_pins(Bits... bits) const {
        write(read() | util::Bitmask<std::uint32_t>{bits...}.mask);
    }
    template <typename... Bits>
    void disable_filter_for_pins(Bits... bits) const {
        write(read() & ~util::Bitmask<std::uint32_t>{bits...}.mask);
    }
};

struct PORTx_DFCR : public Register<PORTx_DFCR> {
    using Register<PORTx_DFCR>::Register;

    using Clock_Source = Bitfield<PORTx_DFCR, 0>;
    auto CS() const { return Clock_Source::read(*this); }
    auto CS(Clock_Source val) const { Clock_Source::write(*this, val); }
    static constexpr Clock_Source bus_clock {false};
    static constexpr Clock_Source LPO_1_kHz {true};
};

struct PORTx_DFWR : public Register<PORTx_DFWR> {
    using Register<PORTx_DFWR>::Register;

    void write_filter_length(std::uint32_t length) { write(length & 0b11111u); }
    std::uint32_t read_filter_length() { return read(); }
};

extern const PORTx_PCRn PORTA_PCR0;
extern const PORTx_PCRn PORTA_PCR1;
extern const PORTx_PCRn PORTA_PCR2;
extern const PORTx_PCRn PORTA_PCR3;
extern const PORTx_PCRn PORTA_PCR4;
extern const PORTx_PCRn PORTA_PCR5;
extern const PORTx_PCRn PORTA_PCR6;
extern const PORTx_PCRn PORTA_PCR7;
extern const PORTx_PCRn PORTA_PCR8;
extern const PORTx_PCRn PORTA_PCR9;
extern const PORTx_PCRn PORTA_PCR10;
extern const PORTx_PCRn PORTA_PCR11;
extern const PORTx_PCRn PORTA_PCR12;
extern const PORTx_PCRn PORTA_PCR13;
extern const PORTx_PCRn PORTA_PCR14;
extern const PORTx_PCRn PORTA_PCR15;
extern const PORTx_PCRn PORTA_PCR16;
extern const PORTx_PCRn PORTA_PCR17;
extern const PORTx_PCRn PORTA_PCR18;
extern const PORTx_PCRn PORTA_PCR19;
extern const PORTx_PCRn PORTA_PCR20;
extern const PORTx_PCRn PORTA_PCR21;
extern const PORTx_PCRn PORTA_PCR22;
extern const PORTx_PCRn PORTA_PCR23;
extern const PORTx_PCRn PORTA_PCR24;
extern const PORTx_PCRn PORTA_PCR25;
extern const PORTx_PCRn PORTA_PCR26;
extern const PORTx_PCRn PORTA_PCR27;
extern const PORTx_PCRn PORTA_PCR28;
extern const PORTx_PCRn PORTA_PCR29;
extern const PORTx_PCRn PORTA_PCR30;
extern const PORTx_PCRn PORTA_PCR31;
extern const PORTx_GPCLR PORTA_GPCLR;
extern const PORTx_GPCHR PORTA_GPCHR;
extern const PORTx_ISFR PORTA_ISFR;
extern const PORTx_DFER PORTA_DFER;
extern const PORTx_DFCR PORTA_DFCR;
extern const PORTx_DFWR PORTA_DFWR;

extern const PORTx_PCRn PORTB_PCR0;
extern const PORTx_PCRn PORTB_PCR1;
extern const PORTx_PCRn PORTB_PCR2;
extern const PORTx_PCRn PORTB_PCR3;
extern const PORTx_PCRn PORTB_PCR4;
extern const PORTx_PCRn PORTB_PCR5;
extern const PORTx_PCRn PORTB_PCR6;
extern const PORTx_PCRn PORTB_PCR7;
extern const PORTx_PCRn PORTB_PCR8;
extern const PORTx_PCRn PORTB_PCR9;
extern const PORTx_PCRn PORTB_PCR10;
extern const PORTx_PCRn PORTB_PCR11;
extern const PORTx_PCRn PORTB_PCR12;
extern const PORTx_PCRn PORTB_PCR13;
extern const PORTx_PCRn PORTB_PCR14;
extern const PORTx_PCRn PORTB_PCR15;
extern const PORTx_PCRn PORTB_PCR16;
extern const PORTx_PCRn PORTB_PCR17;
extern const PORTx_PCRn PORTB_PCR18;
extern const PORTx_PCRn PORTB_PCR19;
extern const PORTx_PCRn PORTB_PCR20;
extern const PORTx_PCRn PORTB_PCR21;
extern const PORTx_PCRn PORTB_PCR22;
extern const PORTx_PCRn PORTB_PCR23;
extern const PORTx_PCRn PORTB_PCR24;
extern const PORTx_PCRn PORTB_PCR25;
extern const PORTx_PCRn PORTB_PCR26;
extern const PORTx_PCRn PORTB_PCR27;
extern const PORTx_PCRn PORTB_PCR28;
extern const PORTx_PCRn PORTB_PCR29;
extern const PORTx_PCRn PORTB_PCR30;
extern const PORTx_PCRn PORTB_PCR31;
extern const PORTx_GPCLR PORTB_GPCLR;
extern const PORTx_GPCHR PORTB_GPCHR;
extern const PORTx_ISFR PORTB_ISFR;
extern const PORTx_DFER PORTB_DFER;
extern const PORTx_DFCR PORTB_DFCR;
extern const PORTx_DFWR PORTB_DFWR;

extern const PORTx_PCRn PORTC_PCR0;
extern const PORTx_PCRn PORTC_PCR1;
extern const PORTx_PCRn PORTC_PCR2;
extern const PORTx_PCRn PORTC_PCR3;
extern const PORTx_PCRn PORTC_PCR4;
extern const PORTx_PCRn PORTC_PCR5;
extern const PORTx_PCRn PORTC_PCR6;
extern const PORTx_PCRn PORTC_PCR7;
extern const PORTx_PCRn PORTC_PCR8;
extern const PORTx_PCRn PORTC_PCR9;
extern const PORTx_PCRn PORTC_PCR10;
extern const PORTx_PCRn PORTC_PCR11;
extern const PORTx_PCRn PORTC_PCR12;
extern const PORTx_PCRn PORTC_PCR13;
extern const PORTx_PCRn PORTC_PCR14;
extern const PORTx_PCRn PORTC_PCR15;
extern const PORTx_PCRn PORTC_PCR16;
extern const PORTx_PCRn PORTC_PCR17;
extern const PORTx_PCRn PORTC_PCR18;
extern const PORTx_PCRn PORTC_PCR19;
extern const PORTx_PCRn PORTC_PCR20;
extern const PORTx_PCRn PORTC_PCR21;
extern const PORTx_PCRn PORTC_PCR22;
extern const PORTx_PCRn PORTC_PCR23;
extern const PORTx_PCRn PORTC_PCR24;
extern const PORTx_PCRn PORTC_PCR25;
extern const PORTx_PCRn PORTC_PCR26;
extern const PORTx_PCRn PORTC_PCR27;
extern const PORTx_PCRn PORTC_PCR28;
extern const PORTx_PCRn PORTC_PCR29;
extern const PORTx_PCRn PORTC_PCR30;
extern const PORTx_PCRn PORTC_PCR31;
extern const PORTx_GPCLR PORTC_GPCLR;
extern const PORTx_GPCHR PORTC_GPCHR;
extern const PORTx_ISFR PORTC_ISFR;
extern const PORTx_DFER PORTC_DFER;
extern const PORTx_DFCR PORTC_DFCR;
extern const PORTx_DFWR PORTC_DFWR;

extern const PORTx_PCRn PORTD_PCR0;
extern const PORTx_PCRn PORTD_PCR1;
extern const PORTx_PCRn PORTD_PCR2;
extern const PORTx_PCRn PORTD_PCR3;
extern const PORTx_PCRn PORTD_PCR4;
extern const PORTx_PCRn PORTD_PCR5;
extern const PORTx_PCRn PORTD_PCR6;
extern const PORTx_PCRn PORTD_PCR7;
extern const PORTx_PCRn PORTD_PCR8;
extern const PORTx_PCRn PORTD_PCR9;
extern const PORTx_PCRn PORTD_PCR10;
extern const PORTx_PCRn PORTD_PCR11;
extern const PORTx_PCRn PORTD_PCR12;
extern const PORTx_PCRn PORTD_PCR13;
extern const PORTx_PCRn PORTD_PCR14;
extern const PORTx_PCRn PORTD_PCR15;
extern const PORTx_PCRn PORTD_PCR16;
extern const PORTx_PCRn PORTD_PCR17;
extern const PORTx_PCRn PORTD_PCR18;
extern const PORTx_PCRn PORTD_PCR19;
extern const PORTx_PCRn PORTD_PCR20;
extern const PORTx_PCRn PORTD_PCR21;
extern const PORTx_PCRn PORTD_PCR22;
extern const PORTx_PCRn PORTD_PCR23;
extern const PORTx_PCRn PORTD_PCR24;
extern const PORTx_PCRn PORTD_PCR25;
extern const PORTx_PCRn PORTD_PCR26;
extern const PORTx_PCRn PORTD_PCR27;
extern const PORTx_PCRn PORTD_PCR28;
extern const PORTx_PCRn PORTD_PCR29;
extern const PORTx_PCRn PORTD_PCR30;
extern const PORTx_PCRn PORTD_PCR31;
extern const PORTx_GPCLR PORTD_GPCLR;
extern const PORTx_GPCHR PORTD_GPCHR;
extern const PORTx_ISFR PORTD_ISFR;
extern const PORTx_DFER PORTD_DFER;
extern const PORTx_DFCR PORTD_DFCR;
extern const PORTx_DFWR PORTD_DFWR;

extern const PORTx_PCRn PORTE_PCR0;
extern const PORTx_PCRn PORTE_PCR1;
extern const PORTx_PCRn PORTE_PCR2;
extern const PORTx_PCRn PORTE_PCR3;
extern const PORTx_PCRn PORTE_PCR4;
extern const PORTx_PCRn PORTE_PCR5;
extern const PORTx_PCRn PORTE_PCR6;
extern const PORTx_PCRn PORTE_PCR7;
extern const PORTx_PCRn PORTE_PCR8;
extern const PORTx_PCRn PORTE_PCR9;
extern const PORTx_PCRn PORTE_PCR10;
extern const PORTx_PCRn PORTE_PCR11;
extern const PORTx_PCRn PORTE_PCR12;
extern const PORTx_PCRn PORTE_PCR13;
extern const PORTx_PCRn PORTE_PCR14;
extern const PORTx_PCRn PORTE_PCR15;
extern const PORTx_PCRn PORTE_PCR16;
extern const PORTx_PCRn PORTE_PCR17;
extern const PORTx_PCRn PORTE_PCR18;
extern const PORTx_PCRn PORTE_PCR19;
extern const PORTx_PCRn PORTE_PCR20;
extern const PORTx_PCRn PORTE_PCR21;
extern const PORTx_PCRn PORTE_PCR22;
extern const PORTx_PCRn PORTE_PCR23;
extern const PORTx_PCRn PORTE_PCR24;
extern const PORTx_PCRn PORTE_PCR25;
extern const PORTx_PCRn PORTE_PCR26;
extern const PORTx_PCRn PORTE_PCR27;
extern const PORTx_PCRn PORTE_PCR28;
extern const PORTx_PCRn PORTE_PCR29;
extern const PORTx_PCRn PORTE_PCR30;
extern const PORTx_PCRn PORTE_PCR31;
extern const PORTx_GPCLR PORTE_GPCLR;
extern const PORTx_GPCHR PORTE_GPCHR;
extern const PORTx_ISFR PORTE_ISFR;
extern const PORTx_DFER PORTE_DFER;
extern const PORTx_DFCR PORTE_DFCR;
extern const PORTx_DFWR PORTE_DFWR;

} // namespace platform::port

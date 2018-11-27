#pragma once

#include <util/bit_manipulation.hpp>
#include <platform/ARM/Cortex/M4/Freescale/register.hpp>

namespace platform::port {

struct PORTx_PCRn : public Register<std::uint32_t> {
    using Interrupt_Status = W1C<PORTx_PCRn, 24>;
    auto ISF() const volatile { return Interrupt_Status::decode(this); }
    auto ISF(Interrupt_Status::clear_flag) volatile { Interrupt_Status::clear(this); }
    static constexpr Interrupt_Status interrupt_not_active {false};
    static constexpr Interrupt_Status interrupt_active {true};
    static constexpr Interrupt_Status::clear_flag clear_interrupt {};

    using Interrupt_Configuration = Bitfield<PORTx_PCRn, 19, 16>;
    auto IRQC() const volatile { return Interrupt_Configuration::decode(this); }
    void IRQC(Interrupt_Configuration val) volatile { val.update(this); }
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
    auto LK() const volatile { return Lock_Register::decode(this); }
    auto LK(Lock_Register val) volatile { val.update(this); }
    static constexpr Lock_Register unlocked {0};
    static constexpr Lock_Register locked {1};

    using Pin_Mux_Control = Bitfield<PORTx_PCRn, 10, 8>;
    auto MUX() const volatile { return Pin_Mux_Control::decode(this); }
    auto MUX(Pin_Mux_Control val) volatile { val.update(this); }
    static constexpr Pin_Mux_Control disabled_analog {0b000};
    static constexpr Pin_Mux_Control alternative_1_GPIO {0b001};
    static constexpr Pin_Mux_Control alternative_2 {0b010};
    static constexpr Pin_Mux_Control alternative_3 {0b011};
    static constexpr Pin_Mux_Control alternative_4 {0b100};
    static constexpr Pin_Mux_Control alternative_5 {0b101};
    static constexpr Pin_Mux_Control alternative_6 {0b110};
    static constexpr Pin_Mux_Control alternative_7 {0b111};

    using Drive_Strength = Bitfield<PORTx_PCRn, 6>;
    auto DSE() const volatile { return Drive_Strength::decode(this); }
    auto DSE(Drive_Strength val) volatile { val.update(this); }
    static constexpr Drive_Strength low_drive {false};
    static constexpr Drive_Strength high_drive {true};

    using Open_Drain = Bitfield<PORTx_PCRn, 5>;
    auto ODE() const volatile { return Open_Drain::decode(this); }
    auto ODE(Open_Drain val) volatile { return val.update(this); }
    static constexpr Open_Drain open_drain_disabled {false};
    static constexpr Open_Drain open_drain_enabled {true};

    using Passive_Filter = Bitfield<PORTx_PCRn, 4>;
    auto PFE() const volatile { return Passive_Filter::decode(this); }
    auto PFE(Passive_Filter val) volatile { return val.update(this); }
    static constexpr Passive_Filter passive_filter_disabled {false};
    static constexpr Passive_Filter passive_filter_enabled {true};

    using Slew_Rate = Bitfield<PORTx_PCRn, 2>;
    auto SRE() const volatile { return Slew_Rate::decode(this); }
    auto SRE(Slew_Rate val) volatile { val.update(this); }
    static constexpr Slew_Rate fast_slew_rate {false};
    static constexpr Slew_Rate slow_slew_rate {true};

    using Internal_Pull = Bitfield<PORTx_PCRn, 1>;
    auto PE() const volatile { return Internal_Pull::decode(this); }
    auto PE(Internal_Pull val) volatile { val.update(this); }
    static constexpr Internal_Pull internal_pull_disabled {false};
    static constexpr Internal_Pull internal_pull_enabled  {true};

    using Pull_Select = Bitfield<PORTx_PCRn, 0>;
    auto PS() const volatile { return Pull_Select::decode(this); }
    auto PS(Pull_Select val) volatile { val.update(this); }
    static constexpr Pull_Select pull_down {false};
    static constexpr Pull_Select pull_up   {true};
};

struct PORTx_GPCyR : public Register<std::uint32_t> {
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
    template <typename... Args>
    std::enable_if_t<
        std::conjunction<std::is_base_of<typename Args::register_t, PORTx_GPCLR>...>::value>
    set(const util::Bitmask<std::uint32_t> bits, const Args... args) volatile {
        write((bits.mask << 16) | value(args...));
    }
};

struct PORTx_GPCHR : public PORTx_GPCyR {
    template <typename... Args>
    std::enable_if_t<
        std::conjunction<std::is_base_of<typename Args::register_t, PORTx_GPCHR>...>::value>
    set(util::Bitmask<std::uint32_t> bits, Args... args) volatile {
        write(bits.mask | value(args...));
    }
};

struct PORTx_ISFR : public Register<std::uint32_t> {
    template <typename... Bits>
    void clear(Bits... bits) volatile { write(util::Bitmask<std::uint32_t>{bits...}.mask); }
    template <typename... Bits>
    bool is_set(Bits... pins) const volatile { return read() & util::Bitmask<std::uint32_t>{pins...}.mask; }
};

struct PORTx_DFER : public Register<std::uint32_t> {
    template <typename... Bits>
    void enable_filter_for_pins(Bits... bits) volatile {
        write(read() | util::Bitmask<std::uint32_t>{bits...}.mask);
    }
    template <typename... Bits>
    void disable_filter_for_pins(Bits... bits) volatile {
        write(read() & ~util::Bitmask<std::uint32_t>{bits...}.mask);
    }
};

struct PORTx_DFCR : public Register<std::uint32_t> {
    using Clock_Source = Bitfield<PORTx_DFCR, 0>;
    auto CS() const volatile { return Clock_Source::decode(this); }
    auto CS(Clock_Source value) volatile { value.update(this); }
    static constexpr Clock_Source bus_clock {false};
    static constexpr Clock_Source LPO_1_kHz {true};
};

struct PORTx_DFWR : public Register<std::uint32_t> {
    void write_filter_length(std::uint32_t length) { write(length & 0b11111u); }
    std::uint32_t read_filter_length() { return read(); }
};

extern volatile PORTx_PCRn& PORTA_PCR0;
extern volatile PORTx_PCRn& PORTA_PCR1;
extern volatile PORTx_PCRn& PORTA_PCR2;
extern volatile PORTx_PCRn& PORTA_PCR3;
extern volatile PORTx_PCRn& PORTA_PCR4;
extern volatile PORTx_PCRn& PORTA_PCR5;
extern volatile PORTx_PCRn& PORTA_PCR6;
extern volatile PORTx_PCRn& PORTA_PCR7;
extern volatile PORTx_PCRn& PORTA_PCR8;
extern volatile PORTx_PCRn& PORTA_PCR9;
extern volatile PORTx_PCRn& PORTA_PCR10;
extern volatile PORTx_PCRn& PORTA_PCR11;
extern volatile PORTx_PCRn& PORTA_PCR12;
extern volatile PORTx_PCRn& PORTA_PCR13;
extern volatile PORTx_PCRn& PORTA_PCR14;
extern volatile PORTx_PCRn& PORTA_PCR15;
extern volatile PORTx_PCRn& PORTA_PCR16;
extern volatile PORTx_PCRn& PORTA_PCR17;
extern volatile PORTx_PCRn& PORTA_PCR18;
extern volatile PORTx_PCRn& PORTA_PCR19;
extern volatile PORTx_PCRn& PORTA_PCR20;
extern volatile PORTx_PCRn& PORTA_PCR21;
extern volatile PORTx_PCRn& PORTA_PCR22;
extern volatile PORTx_PCRn& PORTA_PCR23;
extern volatile PORTx_PCRn& PORTA_PCR24;
extern volatile PORTx_PCRn& PORTA_PCR25;
extern volatile PORTx_PCRn& PORTA_PCR26;
extern volatile PORTx_PCRn& PORTA_PCR27;
extern volatile PORTx_PCRn& PORTA_PCR28;
extern volatile PORTx_PCRn& PORTA_PCR29;
extern volatile PORTx_PCRn& PORTA_PCR30;
extern volatile PORTx_PCRn& PORTA_PCR31;
extern volatile PORTx_GPCLR& PORTA_GPCLR;
extern volatile PORTx_GPCHR& PORTA_GPCHR;
extern volatile PORTx_ISFR& PORTA_ISFR;
extern volatile PORTx_DFER& PORTA_DFER;
extern volatile PORTx_DFCR& PORTA_DFCR;
extern volatile PORTx_DFWR& PORTA_DFWR;

extern volatile PORTx_PCRn& PORTB_PCR0;
extern volatile PORTx_PCRn& PORTB_PCR1;
extern volatile PORTx_PCRn& PORTB_PCR2;
extern volatile PORTx_PCRn& PORTB_PCR3;
extern volatile PORTx_PCRn& PORTB_PCR4;
extern volatile PORTx_PCRn& PORTB_PCR5;
extern volatile PORTx_PCRn& PORTB_PCR6;
extern volatile PORTx_PCRn& PORTB_PCR7;
extern volatile PORTx_PCRn& PORTB_PCR8;
extern volatile PORTx_PCRn& PORTB_PCR9;
extern volatile PORTx_PCRn& PORTB_PCR10;
extern volatile PORTx_PCRn& PORTB_PCR11;
extern volatile PORTx_PCRn& PORTB_PCR12;
extern volatile PORTx_PCRn& PORTB_PCR13;
extern volatile PORTx_PCRn& PORTB_PCR14;
extern volatile PORTx_PCRn& PORTB_PCR15;
extern volatile PORTx_PCRn& PORTB_PCR16;
extern volatile PORTx_PCRn& PORTB_PCR17;
extern volatile PORTx_PCRn& PORTB_PCR18;
extern volatile PORTx_PCRn& PORTB_PCR19;
extern volatile PORTx_PCRn& PORTB_PCR20;
extern volatile PORTx_PCRn& PORTB_PCR21;
extern volatile PORTx_PCRn& PORTB_PCR22;
extern volatile PORTx_PCRn& PORTB_PCR23;
extern volatile PORTx_PCRn& PORTB_PCR24;
extern volatile PORTx_PCRn& PORTB_PCR25;
extern volatile PORTx_PCRn& PORTB_PCR26;
extern volatile PORTx_PCRn& PORTB_PCR27;
extern volatile PORTx_PCRn& PORTB_PCR28;
extern volatile PORTx_PCRn& PORTB_PCR29;
extern volatile PORTx_PCRn& PORTB_PCR30;
extern volatile PORTx_PCRn& PORTB_PCR31;
extern volatile PORTx_GPCLR& PORTB_GPCLR;
extern volatile PORTx_GPCHR& PORTB_GPCHR;
extern volatile PORTx_ISFR& PORTB_ISFR;
extern volatile PORTx_DFER& PORTB_DFER;
extern volatile PORTx_DFCR& PORTB_DFCR;
extern volatile PORTx_DFWR& PORTB_DFWR;

extern volatile PORTx_PCRn& PORTC_PCR0;
extern volatile PORTx_PCRn& PORTC_PCR1;
extern volatile PORTx_PCRn& PORTC_PCR2;
extern volatile PORTx_PCRn& PORTC_PCR3;
extern volatile PORTx_PCRn& PORTC_PCR4;
extern volatile PORTx_PCRn& PORTC_PCR5;
extern volatile PORTx_PCRn& PORTC_PCR6;
extern volatile PORTx_PCRn& PORTC_PCR7;
extern volatile PORTx_PCRn& PORTC_PCR8;
extern volatile PORTx_PCRn& PORTC_PCR9;
extern volatile PORTx_PCRn& PORTC_PCR10;
extern volatile PORTx_PCRn& PORTC_PCR11;
extern volatile PORTx_PCRn& PORTC_PCR12;
extern volatile PORTx_PCRn& PORTC_PCR13;
extern volatile PORTx_PCRn& PORTC_PCR14;
extern volatile PORTx_PCRn& PORTC_PCR15;
extern volatile PORTx_PCRn& PORTC_PCR16;
extern volatile PORTx_PCRn& PORTC_PCR17;
extern volatile PORTx_PCRn& PORTC_PCR18;
extern volatile PORTx_PCRn& PORTC_PCR19;
extern volatile PORTx_PCRn& PORTC_PCR20;
extern volatile PORTx_PCRn& PORTC_PCR21;
extern volatile PORTx_PCRn& PORTC_PCR22;
extern volatile PORTx_PCRn& PORTC_PCR23;
extern volatile PORTx_PCRn& PORTC_PCR24;
extern volatile PORTx_PCRn& PORTC_PCR25;
extern volatile PORTx_PCRn& PORTC_PCR26;
extern volatile PORTx_PCRn& PORTC_PCR27;
extern volatile PORTx_PCRn& PORTC_PCR28;
extern volatile PORTx_PCRn& PORTC_PCR29;
extern volatile PORTx_PCRn& PORTC_PCR30;
extern volatile PORTx_PCRn& PORTC_PCR31;
extern volatile PORTx_GPCLR& PORTC_GPCLR;
extern volatile PORTx_GPCHR& PORTC_GPCHR;
extern volatile PORTx_ISFR& PORTC_ISFR;
extern volatile PORTx_DFER& PORTC_DFER;
extern volatile PORTx_DFCR& PORTC_DFCR;
extern volatile PORTx_DFWR& PORTC_DFWR;

extern volatile PORTx_PCRn& PORTD_PCR0;
extern volatile PORTx_PCRn& PORTD_PCR1;
extern volatile PORTx_PCRn& PORTD_PCR2;
extern volatile PORTx_PCRn& PORTD_PCR3;
extern volatile PORTx_PCRn& PORTD_PCR4;
extern volatile PORTx_PCRn& PORTD_PCR5;
extern volatile PORTx_PCRn& PORTD_PCR6;
extern volatile PORTx_PCRn& PORTD_PCR7;
extern volatile PORTx_PCRn& PORTD_PCR8;
extern volatile PORTx_PCRn& PORTD_PCR9;
extern volatile PORTx_PCRn& PORTD_PCR10;
extern volatile PORTx_PCRn& PORTD_PCR11;
extern volatile PORTx_PCRn& PORTD_PCR12;
extern volatile PORTx_PCRn& PORTD_PCR13;
extern volatile PORTx_PCRn& PORTD_PCR14;
extern volatile PORTx_PCRn& PORTD_PCR15;
extern volatile PORTx_PCRn& PORTD_PCR16;
extern volatile PORTx_PCRn& PORTD_PCR17;
extern volatile PORTx_PCRn& PORTD_PCR18;
extern volatile PORTx_PCRn& PORTD_PCR19;
extern volatile PORTx_PCRn& PORTD_PCR20;
extern volatile PORTx_PCRn& PORTD_PCR21;
extern volatile PORTx_PCRn& PORTD_PCR22;
extern volatile PORTx_PCRn& PORTD_PCR23;
extern volatile PORTx_PCRn& PORTD_PCR24;
extern volatile PORTx_PCRn& PORTD_PCR25;
extern volatile PORTx_PCRn& PORTD_PCR26;
extern volatile PORTx_PCRn& PORTD_PCR27;
extern volatile PORTx_PCRn& PORTD_PCR28;
extern volatile PORTx_PCRn& PORTD_PCR29;
extern volatile PORTx_PCRn& PORTD_PCR30;
extern volatile PORTx_PCRn& PORTD_PCR31;
extern volatile PORTx_GPCLR& PORTD_GPCLR;
extern volatile PORTx_GPCHR& PORTD_GPCHR;
extern volatile PORTx_ISFR& PORTD_ISFR;
extern volatile PORTx_DFER& PORTD_DFER;
extern volatile PORTx_DFCR& PORTD_DFCR;
extern volatile PORTx_DFWR& PORTD_DFWR;

extern volatile PORTx_PCRn& PORTE_PCR0;
extern volatile PORTx_PCRn& PORTE_PCR1;
extern volatile PORTx_PCRn& PORTE_PCR2;
extern volatile PORTx_PCRn& PORTE_PCR3;
extern volatile PORTx_PCRn& PORTE_PCR4;
extern volatile PORTx_PCRn& PORTE_PCR5;
extern volatile PORTx_PCRn& PORTE_PCR6;
extern volatile PORTx_PCRn& PORTE_PCR7;
extern volatile PORTx_PCRn& PORTE_PCR8;
extern volatile PORTx_PCRn& PORTE_PCR9;
extern volatile PORTx_PCRn& PORTE_PCR10;
extern volatile PORTx_PCRn& PORTE_PCR11;
extern volatile PORTx_PCRn& PORTE_PCR12;
extern volatile PORTx_PCRn& PORTE_PCR13;
extern volatile PORTx_PCRn& PORTE_PCR14;
extern volatile PORTx_PCRn& PORTE_PCR15;
extern volatile PORTx_PCRn& PORTE_PCR16;
extern volatile PORTx_PCRn& PORTE_PCR17;
extern volatile PORTx_PCRn& PORTE_PCR18;
extern volatile PORTx_PCRn& PORTE_PCR19;
extern volatile PORTx_PCRn& PORTE_PCR20;
extern volatile PORTx_PCRn& PORTE_PCR21;
extern volatile PORTx_PCRn& PORTE_PCR22;
extern volatile PORTx_PCRn& PORTE_PCR23;
extern volatile PORTx_PCRn& PORTE_PCR24;
extern volatile PORTx_PCRn& PORTE_PCR25;
extern volatile PORTx_PCRn& PORTE_PCR26;
extern volatile PORTx_PCRn& PORTE_PCR27;
extern volatile PORTx_PCRn& PORTE_PCR28;
extern volatile PORTx_PCRn& PORTE_PCR29;
extern volatile PORTx_PCRn& PORTE_PCR30;
extern volatile PORTx_PCRn& PORTE_PCR31;
extern volatile PORTx_GPCLR& PORTE_GPCLR;
extern volatile PORTx_GPCHR& PORTE_GPCHR;
extern volatile PORTx_ISFR& PORTE_ISFR;
extern volatile PORTx_DFER& PORTE_DFER;
extern volatile PORTx_DFCR& PORTE_DFCR;
extern volatile PORTx_DFWR& PORTE_DFWR;

} // namespace platform::port

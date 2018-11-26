#pragma once

#include <util/bit_manipulation.hpp>
#include <platform/ARM/Cortex/M4/Freescale/register.hpp>

namespace platform::sim {
#if 0
struct SIM_SOPT1_t : public Register<SIM_SOPT1_t> {
    using Register<SIM_SOPT1_t>::Register;

    using USB_voltage_regulator_enable = Bitfield<SIM_SOPT1_t, 31>;
    using USB_voltage_regulator_in_standby = Bitfield<SIM_SOPT1_t, 30>;
    using USB_voltage_regulator_in_VLP = Bitfield<SIM_SOPT1_t, 29>;
    using oscillator_32k_clock_select = Bitfield<SIM_SOPT1_t, 18, 2>;
    using ram_size = Bitfield<SIM_SOPT1_t, 12, 4>;
};

struct SIM_SOPT1CFG_t : public Register<SIM_SOPT1CFG_t> {
    using Register<SIM_SOPT1CFG_t>::Register;

    using USB_voltage_regulator_in_standby_write_enable = Bitfield<SIM_SOPT1CFG_t, 26>;
    using USB_voltage_regulator_in_VLP_write_enable = Bitfield<SIM_SOPT1CFG_t, 25>;
    using USB_voltage_regulator_enable_write_enable = Bitfield<SIM_SOPT1CFG_t, 24>;
};

struct SIM_SOPT2_t : public Register<SIM_SOPT2_t> {
    using Register<SIM_SOPT2_t>::Register;

    using SDHC_clock_source = Bitfield<SIM_SOPT2_t, 28, 2>;
    using USB_clock_source = Bitfield<SIM_SOPT2_t, 18>;
    using PLL_FLL_clock_select = Bitfield<SIM_SOPT2_t, 16, 2>;
    using trace_clock_select = Bitfield<SIM_SOPT2_t, 12>;
    using PTD7_pad_drive_strength = Bitfield<SIM_SOPT2_t, 11>;
    using FlexBus_security_level = Bitfield<SIM_SOPT2_t, 9, 2>;
    using CLKOUT_select = Bitfield<SIM_SOPT2_t, 5, 3>;
    using RTC_clock_out_select = Bitfield<SIM_SOPT2_t, 4>;
};

struct SIM_SOPT4_t : public Register<SIM_SOPT4_t> {
    using Register<SIM_SOPT4_t>::Register;

    using FlexTimer_3_hardware_trigger_1_source = Bitfield<SIM_SOPT4_t, 31>;
    using FlexTimer_3_hardware_trigger_0_source = Bitfield<SIM_SOPT4_t, 30>;
    using FlexTimer_0_hardware_trigger_1_source = Bitfield<SIM_SOPT4_t, 29>;
    using FlexTimer_0_hardware_trigger_0_source = Bitfield<SIM_SOPT4_t, 28>;
    using FlexTimer_3_external_clock_pin = Bitfield<SIM_SOPT4_t, 27>;
    using FlexTimer_2_external_clock_pin = Bitfield<SIM_SOPT4_t, 26>;
    using FlexTimer_1_external_clock_pin = Bitfield<SIM_SOPT4_t, 25>;
    using FlexTimer_0_external_clock_pin = Bitfield<SIM_SOPT4_t, 24>;
    using FlexTimer_2_chanel_1_input_capture_source = Bitfield<SIM_SOPT4_t, 22>;
    // TODO: Finish this
};

struct SIM_SOPT5_t : public Register<SIM_SOPT5_t> {
    using Register<SIM_SOPT5_t>::Register;
};

struct SIM_SOPT7_t : public Register<SIM_SOPT7_t> {
    using Register<SIM_SOPT7_t>::Register;
};

struct SIM_SDID_t : public Register<SIM_SDID_t> {
    using Register<SIM_SDID_t>::Register;
};

struct SIM_SCGC1_t : public Register<SIM_SCGC1_t> {
    using Register<SIM_SCGC1_t>::Register;
};

struct SIM_SCGC2_t : public Register<SIM_SCGC2_t> {
    using Register<SIM_SCGC2_t>::Register;
};

struct SIM_SCGC3_t : public Register<SIM_SCGC3_t> {
    using Register<SIM_SCGC3_t>::Register;
};

struct SIM_SCGC4_t : public Register<SIM_SCGC4_t> {
    using Register<SIM_SCGC4_t>::Register;
};

struct SIM_SCGC5_t : public Register<SIM_SCGC5_t> {
    using Register<SIM_SCGC5_t>::Register;

    template <typename... Args>
    void enable_clock(const Args... args) const {
        write(args...);
    }

    template <typename... Args>
    void disable_clock(const Args... args) const {
        write(~args...);
    }

    template <std::size_t offset>
    using Clock_gate = Bitfield<SIM_SCGC5_t, offset>;

    static constexpr Clock_gate<9>  PORTA {true};
    static constexpr Clock_gate<10> PORTB {true};
    static constexpr Clock_gate<11> PORTC {true};
    static constexpr Clock_gate<12> PORTD {true};
    static constexpr Clock_gate<13> PORTE {true};
};

struct SIM_SCGC6_t : public Register<SIM_SCGC6_t> {
    using Register<SIM_SCGC6_t>::Register;
};

struct SIM_SCGC7_t : public Register<SIM_SCGC7_t> {
    using Register<SIM_SCGC7_t>::Register;
};

struct SIM_CLKDIV1_t : public Register<SIM_CLKDIV1_t> {
    using Register<SIM_CLKDIV1_t>::Register;
};

struct SIM_CLKDIV2_t : public Register<SIM_CLKDIV2_t> {
    using Register<SIM_CLKDIV2_t>::Register;
};

struct SIM_FCFG1_t : public Register<SIM_FCFG1_t> {
    using Register<SIM_FCFG1_t>::Register;
};

struct SIM_FCFG2_t : public Register<SIM_FCFG2_t> {
    using Register<SIM_FCFG2_t>::Register;
};

struct SIM_UIDH_t : public Register<SIM_UIDH_t> {
    using Register<SIM_UIDH_t>::Register;
};

struct SIM_UIDHM_t : public Register<SIM_UIDHM_t> {
    using Register<SIM_UIDHM_t>::Register;
};

struct SIM_UIDML_t : public Register<SIM_UIDML_t> {
    using Register<SIM_UIDML_t>::Register;
};

struct SIM_UIDL_t : public Register<SIM_UIDL_t> {
    using Register<SIM_UIDL_t>::Register;
};

extern const SIM_SOPT1_t    SIM_SOPT1;
extern const SIM_SOPT1CFG_t SIM_SOPT1CFG;
extern const SIM_SOPT2_t    SIM_SOPT2;
extern const SIM_SOPT4_t    SIM_SOPT4;
extern const SIM_SOPT5_t    SIM_SOPT5;
extern const SIM_SOPT7_t    SIM_SOPT7;
extern const SIM_SDID_t     SIM_SDID;
extern const SIM_SCGC1_t    SIM_SCGC1;
extern const SIM_SCGC2_t    SIM_SCGC2;
extern const SIM_SCGC3_t    SIM_SCGC3;
extern const SIM_SCGC4_t    SIM_SCGC4;
extern const SIM_SCGC5_t    SIM_SCGC5;
extern const SIM_SCGC6_t    SIM_SCGC6;
extern const SIM_SCGC7_t    SIM_SCGC7;
extern const SIM_CLKDIV1_t  SIM_CLKDIV1;
extern const SIM_CLKDIV2_t  SIM_CLKDIV2;
extern const SIM_FCFG1_t    SIM_FCFG1;
extern const SIM_FCFG2_t    SIM_FCFG2;
extern const SIM_UIDH_t     SIM_UIDH;
extern const SIM_UIDHM_t    SIM_UIDHM;
extern const SIM_UIDML_t    SIM_UIDML;
extern const SIM_UIDL_t     SIM_UIDL;
#endif
} // namespace platform::sim

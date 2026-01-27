#pragma once

#include <miotal/ARM/Cortex/M4/NXP/register.hpp>

namespace platform::sim {

struct SIM_SOPT1_t : public Register<std::uint32_t> {
};

struct SIM_SOPT1CFG_t : public Register<std::uint32_t> {
};

struct SIM_SOPT2_t : public Register<std::uint32_t> {
};

struct SIM_SOPT4_t : public Register<std::uint32_t> {
};

struct SIM_SOPT5_t : public Register<std::uint32_t> {
};

struct SIM_SOPT7_t : public Register<std::uint32_t> {
};

struct SIM_SDID_t : public Register<std::uint32_t> {
};

struct SIM_SCGC1_t : public Register<std::uint32_t> {
};

struct SIM_SCGC2_t : public Register<std::uint32_t> {
};

struct SIM_SCGC3_t : public Register<std::uint32_t> {
};

struct SIM_SCGC4_t : public Register<std::uint32_t> {
};

struct SIM_SCGC5_t : public Register<std::uint32_t> {

	template <typename... Args>
	void enable_clock(const Args... args) volatile {
		write(args...);
	}

	template <typename... Args>
	void disable_clock(const Args... args) volatile {
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

struct SIM_SCGC6_t : public Register<std::uint32_t> {
};

struct SIM_SCGC7_t : public Register<std::uint32_t> {
};

struct SIM_CLKDIV1_t : public Register<std::uint32_t> {
};

struct SIM_CLKDIV2_t : public Register<std::uint32_t> {
};

struct SIM_FCFG1_t : public Register<std::uint32_t> {
};

struct SIM_FCFG2_t : public Register<std::uint32_t> {
};

struct SIM_UIDH_t : public Register<std::uint32_t> {
};

struct SIM_UIDHM_t : public Register<std::uint32_t> {
};

struct SIM_UIDML_t : public Register<std::uint32_t> {
};

struct SIM_UIDL_t : public Register<std::uint32_t> {
};

extern volatile SIM_SOPT1_t&    SIM_SOPT1;
extern volatile SIM_SOPT1CFG_t& SIM_SOPT1CFG;
extern volatile SIM_SOPT2_t&    SIM_SOPT2;
extern volatile SIM_SOPT4_t&    SIM_SOPT4;
extern volatile SIM_SOPT5_t&    SIM_SOPT5;
extern volatile SIM_SOPT7_t&    SIM_SOPT7;
extern volatile SIM_SDID_t&     SIM_SDID;
extern volatile SIM_SCGC1_t&    SIM_SCGC1;
extern volatile SIM_SCGC2_t&    SIM_SCGC2;
extern volatile SIM_SCGC3_t&    SIM_SCGC3;
extern volatile SIM_SCGC4_t&    SIM_SCGC4;
extern volatile SIM_SCGC5_t&    SIM_SCGC5;
extern volatile SIM_SCGC6_t&    SIM_SCGC6;
extern volatile SIM_SCGC7_t&    SIM_SCGC7;
extern volatile SIM_CLKDIV1_t&  SIM_CLKDIV1;
extern volatile SIM_CLKDIV2_t&  SIM_CLKDIV2;
extern volatile SIM_FCFG1_t&    SIM_FCFG1;
extern volatile SIM_FCFG2_t&    SIM_FCFG2;
extern volatile SIM_UIDH_t&     SIM_UIDH;
extern volatile SIM_UIDHM_t&    SIM_UIDHM;
extern volatile SIM_UIDML_t&    SIM_UIDML;
extern volatile SIM_UIDL_t&     SIM_UIDL;

} // namespace platform::sim

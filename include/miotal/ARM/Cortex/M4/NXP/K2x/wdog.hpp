#pragma once

#include <miotal/ARM/Cortex/M4/NXP/register.hpp>

namespace platform::wdog {

struct WDOG_STCTRLH_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
	using Enable_Watchdog = Bitfield<WDOG_STCTRLH_t, 0>;
	auto WDOGEN() const volatile { return Enable_Watchdog::decode(this); }
	void WDOGEN(Enable_Watchdog value) volatile { value.update(this); }
	static constexpr Enable_Watchdog enable_watchdog {true};
	static constexpr Enable_Watchdog disable_watchdog {false};
};

struct WDOG_STCTRLL_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
};

struct WDOG_TOVALH_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
};

struct WDOG_TOVALL_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
};

struct WDOG_WINH_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
};

struct WDOG_WINL_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
};

struct WDOG_REFRESH_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
};

struct WDOG_UNLOCK_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
	void unlock() volatile {
		write(0xC520);
		write(0xD928);
	}
};

struct WDOG_TMROUTH_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
};

struct WDOG_TMROUTL_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
};

struct WDOG_RSTCNT_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
};

struct WDOG_PRESC_t : public Register<std::uint16_t> {
	using bitband_enabled = std::false_type;
};

extern volatile WDOG_STCTRLH_t& WDOG_STCTRLH;
extern volatile WDOG_STCTRLL_t& WDOG_STCTRLL;
extern volatile WDOG_TOVALH_t&  WDOG_TOVALH;
extern volatile WDOG_TOVALL_t&  WDOG_TOVALL;
extern volatile WDOG_WINH_t&    WDOG_WINH;
extern volatile WDOG_WINL_t&    WDOG_WINL;
extern volatile WDOG_REFRESH_t& WDOG_REFRESH;
extern volatile WDOG_UNLOCK_t&  WDOG_UNLOCK;
extern volatile WDOG_TMROUTH_t& WDOG_TMROUTH;
extern volatile WDOG_TMROUTL_t& WDOG_TMROUTL;
extern volatile WDOG_RSTCNT_t&  WDOG_RSTCNT;
extern volatile WDOG_PRESC_t&   WDOG_PRESC;

} // namespace platform::wdog

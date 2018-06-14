#pragma once

#include <util/bit_manipulation.hpp>
#include <platform/ARM/Cortex/M4/Freescale/register.hpp>

namespace platform::wdog {

struct WDOG_STCTRLH_t : public Register_16<WDOG_STCTRLH_t> {
    using Register_16<WDOG_STCTRLH_t>::Register_16;

    using Enable_Watchdog = Bitfield_16<WDOG_STCTRLH_t, 0>;
    auto WDOGEN() const { return Enable_Watchdog::read(*this); }
    auto WDOGEN(Enable_Watchdog val) const { Enable_Watchdog::write(*this, val); }
    static constexpr Enable_Watchdog enable_watchdog {true};
    static constexpr Enable_Watchdog disable_watchdog {false};
};

struct WDOG_STCTRLL_t : public Register_16<WDOG_STCTRLL_t> {
    using Register_16<WDOG_STCTRLL_t>::Register_16;
};

struct WDOG_TOVALH_t : public Register_16<WDOG_TOVALH_t> {
    using Register_16<WDOG_TOVALH_t>::Register_16;
};

struct WDOG_TOVALL_t : public Register_16<WDOG_TOVALL_t> {
    using Register_16<WDOG_TOVALL_t>::Register_16;
};

struct WDOG_WINH_t : public Register_16<WDOG_WINH_t> {
    using Register_16<WDOG_WINH_t>::Register_16;
};

struct WDOG_WINL_t : public Register_16<WDOG_WINL_t> {
    using Register_16<WDOG_WINL_t>::Register_16;
};

struct WDOG_REFRESH_t : public Register_16<WDOG_REFRESH_t> {
    using Register_16<WDOG_REFRESH_t>::Register_16;
};

struct WDOG_UNLOCK_t : public Register_16<WDOG_UNLOCK_t> {
    using Register_16<WDOG_UNLOCK_t>::Register_16;

    void unlock() const {
        write(0xC520);
        write(0xD928);
    }
};

struct WDOG_TMROUTH_t : public Register_16<WDOG_TMROUTH_t> {
    using Register_16<WDOG_TMROUTH_t>::Register_16;
};

struct WDOG_TMROUTL_t : public Register_16<WDOG_TMROUTL_t> {
    using Register_16<WDOG_TMROUTL_t>::Register_16;
};

struct WDOG_RSTCNT_t : public Register_16<WDOG_RSTCNT_t> {
    using Register_16<WDOG_RSTCNT_t>::Register_16;
};

struct WDOG_PRESC_t : public Register_16<WDOG_PRESC_t> {
    using Register_16<WDOG_PRESC_t>::Register_16;
};

extern const WDOG_STCTRLH_t WDOG_STCTRLH;
extern const WDOG_STCTRLL_t WDOG_STCTRLL;
extern const WDOG_TOVALH_t  WDOG_TOVALH;
extern const WDOG_TOVALL_t  WDOG_TOVALL;
extern const WDOG_WINH_t    WDOG_WINH;
extern const WDOG_WINL_t    WDOG_WINL;
extern const WDOG_REFRESH_t WDOG_REFRESH;
extern const WDOG_UNLOCK_t  WDOG_UNLOCK;
extern const WDOG_TMROUTH_t WDOG_TMROUTH;
extern const WDOG_TMROUTL_t WDOG_TMROUTL;
extern const WDOG_RSTCNT_t  WDOG_RSTCNT;
extern const WDOG_PRESC_t   WDOG_PRESC;

} // namespace platform::wdog

#include <miotal/ARM/Cortex/M4/NXP/K2x/wdog.hpp>

namespace platform::wdog {

volatile WDOG_STCTRLH_t& WDOG_STCTRLH = *reinterpret_cast<volatile WDOG_STCTRLH_t*> (0x4005'2000);
volatile WDOG_STCTRLL_t& WDOG_STCTRLL = *reinterpret_cast<volatile WDOG_STCTRLL_t*> (0x4005'2002);
volatile WDOG_TOVALH_t&  WDOG_TOVALH  = *reinterpret_cast<volatile WDOG_TOVALH_t*>  (0x4005'2004);
volatile WDOG_TOVALL_t&  WDOG_TOVALL  = *reinterpret_cast<volatile WDOG_TOVALL_t*>  (0x4005'2006);
volatile WDOG_WINH_t&    WDOG_WINH    = *reinterpret_cast<volatile WDOG_WINH_t*>    (0x4005'2008);
volatile WDOG_WINL_t&    WDOG_WINL    = *reinterpret_cast<volatile WDOG_WINL_t*>    (0x4005'200A);
volatile WDOG_REFRESH_t& WDOG_REFRESH = *reinterpret_cast<volatile WDOG_REFRESH_t*> (0x4005'200C);
volatile WDOG_UNLOCK_t&  WDOG_UNLOCK  = *reinterpret_cast<volatile WDOG_UNLOCK_t*>  (0x4005'200E);
volatile WDOG_TMROUTH_t& WDOG_TMROUTH = *reinterpret_cast<volatile WDOG_TMROUTH_t*> (0x4005'2010);
volatile WDOG_TMROUTL_t& WDOG_TMROUTL = *reinterpret_cast<volatile WDOG_TMROUTL_t*> (0x4005'2012);
volatile WDOG_RSTCNT_t&  WDOG_RSTCNT  = *reinterpret_cast<volatile WDOG_RSTCNT_t*>  (0x4005'2014);
volatile WDOG_PRESC_t&   WDOG_PRESC   = *reinterpret_cast<volatile WDOG_PRESC_t*>   (0x4005'2016);

} // namespace platform::wdog

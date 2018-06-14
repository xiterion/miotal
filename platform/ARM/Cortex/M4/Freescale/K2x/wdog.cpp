#include "wdog.hpp"

namespace platform::wdog {

extern const WDOG_STCTRLH_t WDOG_STCTRLH {0x4005'2000};
extern const WDOG_STCTRLL_t WDOG_STCTRLL {0x4005'2002};
extern const WDOG_TOVALH_t  WDOG_TOVALH  {0x4005'2004};
extern const WDOG_TOVALL_t  WDOG_TOVALL  {0x4005'2006};
extern const WDOG_WINH_t    WDOG_WINH    {0x4005'2008};
extern const WDOG_WINL_t    WDOG_WINL    {0x4005'200A};
extern const WDOG_REFRESH_t WDOG_REFRESH {0x4005'200C};
extern const WDOG_UNLOCK_t  WDOG_UNLOCK  {0x4005'200E};
extern const WDOG_TMROUTH_t WDOG_TMROUTH {0x4005'2010};
extern const WDOG_TMROUTL_t WDOG_TMROUTL {0x4005'2012};
extern const WDOG_RSTCNT_t  WDOG_RSTCNT  {0x4005'2014};
extern const WDOG_PRESC_t   WDOG_PRESC   {0x4005'2016};

} // namespace platform::wdog

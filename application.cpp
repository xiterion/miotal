#include <cstdint>
#include <climits>
#include <stdexcept>
#include <tuple>

#include <hal/pin.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/gpio.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/sim.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/wdog.hpp>

extern "C" void low_level_init() {
    using namespace platform::wdog;
    WDOG_UNLOCK.unlock();
    WDOG_STCTRLH.WDOGEN(WDOG_STCTRLH.enable_watchdog);
    WDOG_STCTRLH.WDOGEN();

    using namespace platform::sim;
    SIM_SCGC5.enable_clock(SIM_SCGC5.PORTA,
                           SIM_SCGC5.PORTB,
                           SIM_SCGC5.PORTC,
                           SIM_SCGC5.PORTD,
                           SIM_SCGC5.PORTE);
}

int main(void) {
    while(1) {}
}

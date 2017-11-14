#include <cstdint>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>

struct Driver {
    const platform::PORTx_PCRn& pcr;
};

Driver driver{platform::PORTA_PCR1};

int main(void)
{
    driver.pcr.LK(driver.pcr.locked);
    platform::PORTA_DFCR.CS();
}

#pragma once
#include <hal/pin.hpp>

namespace hal {

class GPIO : public DriveStrengthAdjustable,
             public OpenDrainCapable
{
public:
    GPIO(platform::PORTx_PCRn pcr) : pcr{pcr} {}

    float getDriveStrength() final { return 0.0f; }
    void setDriveStrengthAbove(float level) final {}
    void setDriveStrengthBelow(float level) final {}
    void setDriveStrengthBetween(float lower_level, float upper_level) final {}

    void enableOpenDrain() final { pcr.ODE.set(); }
    void disableOpenDrain() final { pcr.ODE.clear(); }
    bool openDrainEnabled() final { static_cast<bool>(pcr.ODE.read()); }

private:
    platform::PORTx_PCRn pcr;
};

} // namespace hal

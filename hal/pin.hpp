#pragma once

#include "../util/InheritsFrom.hpp"

namespace hal {

class InterruptCapable {
public:
    virtual void enableInterrupt() = 0;
    virtual void disableInterrupt() = 0;
    virtual bool interruptEnabled() = 0;
};

class OpenDrainCapable {
public:
    virtual void enableOpenDrain() = 0;
    virtual void disableOpenDrain() = 0;
    virtual bool openDrainEnabled() = 0;
};

} // namespace hal

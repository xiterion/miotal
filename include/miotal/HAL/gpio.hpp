#pragma once

namespace hal {

class Gpio {
public:
    virtual bool read() = 0;
    virtual void write() = 0;
    virtual bool toggle() = 0;
};

} // namespace hal


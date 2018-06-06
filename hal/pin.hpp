#pragma once

namespace hal {

class GPIO {
public:
    virtual bool read() = 0;
    virtual void write() = 0;
    virtual bool toggle() = 0;
protected:
    virtual ~GPIO() = default;
};

} // namespace hal

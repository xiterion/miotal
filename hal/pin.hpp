#pragma once

namespace hal {

template <typename impl>
class GPIO {
public:
    bool read() const { return static_cast<const impl*>(this)->_read(); }
    void write(bool val) const { static_cast<const impl*>(this)-> write(val); }
};

} // namespace hal

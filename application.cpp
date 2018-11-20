#include <cstdint>
#include <climits>
#include <stdexcept>
#include <tuple>

#include <hal/pin.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/gpio.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/sim.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/wdog.hpp>

template <typename R, std::size_t msb, std::size_t lsb=msb, typename AllowBitband = void>
struct Bitfield {
    const typename R::reg_t value;

    static_assert(msb < sizeof(typename R::reg_t)*CHAR_BIT, "Bitfield not inside parent type");
    static constexpr std::size_t offset = lsb;
    static constexpr std::size_t width = msb-lsb+1;
    static constexpr typename R::reg_t mask = ((1u << width) - 1u) << offset;

    constexpr Bitfield(typename R::reg_t raw) : value{raw} {}
    template <class>
    Bitfield(R* reg) : value{static_cast<typename R::reg_t>((reg->read() & mask) >> offset)} {}

    void update(volatile R* reg) { reg->write((reg->read() & ~mask) | (value << offset)); }
};

template <typename R, std::size_t bit>
struct Bitfield<R, bit, bit, std::enable_if_t<R::bitband_enabled::value>> {
    const typename R::reg_t value;

    static_assert(bit < sizeof(typename R::reg_t)*CHAR_BIT, "Bitfield not inside parent type");
    static constexpr std::size_t offset = bit;
    static constexpr std::size_t width = 1;
    static constexpr typename R::reg_t mask = 1u << offset;

    constexpr Bitfield(typename R::reg_t raw) : value{raw} {}
    template <class>
    Bitfield(R* reg) : value{bitband_register(reg, offset)} {}

    void update(volatile R* reg) { bitband_register(reg, offset) = value; }
};

template <typename R>
auto& bitband_register(R* reg, std::uint16_t offset) {
    return *reinterpret_cast<volatile std::uint16_t*>(
            0x2200'0000 + (((reinterpret_cast<std::uintptr_t>(reg)) * 32) + (offset * 4))
        );
};

template <typename T, T msb, T lsb>
constexpr auto operator~(const Bitfield<T, msb, lsb>& a) {
    return Bitfield<T, msb, lsb>{static_cast<T>(~a.value & (a.mask >> a.offset))};
}

template <typename T, typename... Args>
inline constexpr T mask(Args... args);

template <typename T, typename First, typename... Rest>
inline constexpr T mask(First first, Rest... rest) { return mask<T>(first) | mask<T>(rest...); }

template <typename T, typename Last>
inline constexpr T mask(Last last) { return last.mask; }

template <typename T, typename... Args>
inline constexpr T value(Args... args);

template <typename T, typename First, typename... Rest>
inline constexpr T value(First first, Rest... rest) { return value<T>(first) | value<T>(rest...); }

template <typename T, typename Last>
inline constexpr T value(Last last) { return last.value << last.offset; }

template <typename T>
class Register {
public:
    using bitband_enabled = std::true_type;
    typedef T reg_t;

    T read() const volatile { return raw(); }

    template <typename Number>
    typename std::enable_if_t<std::is_integral_v<Number>>
    write(Number value) volatile { raw() = value; }

    template <typename... Args>
    void write(Args... args) volatile { write((read() & ~mask<T>(args...)) | value<T>(args...)); }

private:
    auto& raw() volatile { return *reinterpret_cast<volatile T*>(this); }
    auto& raw() const volatile { return *reinterpret_cast<const volatile T*>(this); }
};

struct WDOG_STCTRLH_t : public Register<std::uint16_t> {
    using bitband_enabled = std::false_type;
    template <std::size_t msb, std::size_t lsb=msb>
    using Bits = Bitfield<WDOG_STCTRLH_t, msb, lsb>;

    using Enable_Watchdog = Bits<0>;
    //auto WDOGEN() const volatile { return Enable_Watchdog{this}; }
    void WDOGEN(Enable_Watchdog value) volatile { value.update(this); }
    static constexpr Enable_Watchdog enable_watchdog {1};
    static constexpr Enable_Watchdog disable_watchdog {0};
};

struct WDOG_UNLOCK_t : public Register<std::uint16_t> {
    using bitband_enabled = std::false_type;
    void unlock() volatile {
        write(0xC520);
        write(0xD928);
    }
};

struct SIM_SCGC5_t : public Register<std::uint32_t> {
    template <std::size_t msb, std::size_t lsb=msb>
    using Bits = Bitfield<SIM_SCGC5_t, msb, lsb>;

    template <typename... Args>
    void enable_clock(const Args... args) volatile { write(args...); }

    template <typename... Args>
    void disable_clock(const Args... args) volatile { write(~args...); }

    static constexpr Bits<9>  PORTA {true};
    static constexpr Bits<10> PORTB {true};
    static constexpr Bits<11> PORTC {true};
    static constexpr Bits<12> PORTD {true};
    static constexpr Bits<13> PORTE {true};
};

auto& WDOG_STCTRLH = *reinterpret_cast<volatile WDOG_STCTRLH_t*>(0x4005'2000);
auto& WDOG_UNLOCK = *reinterpret_cast<volatile WDOG_UNLOCK_t*>(0x4005'200E);
auto& SIM_SCGC5 = *reinterpret_cast<volatile SIM_SCGC5_t*>(0x4004'8038);

extern "C" void low_level_init() {
    WDOG_UNLOCK.unlock();
    WDOG_STCTRLH.WDOGEN(WDOG_STCTRLH.enable_watchdog);

    SIM_SCGC5.enable_clock(SIM_SCGC5.PORTA,
                           SIM_SCGC5.PORTB,
                           SIM_SCGC5.PORTC,
                           SIM_SCGC5.PORTD,
                           SIM_SCGC5.PORTE);
}

int main(void) {
    while(1) {}
}

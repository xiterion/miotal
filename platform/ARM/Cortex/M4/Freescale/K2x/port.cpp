#include "port.hpp"

namespace platform::port {
/*
constexpr PORTx_GPCyR::Lock_Register   PORTx_GPCyR::unlocked;
constexpr PORTx_GPCyR::Lock_Register   PORTx_GPCyR::locked;
constexpr PORTx_GPCyR::Pin_Mux_Control PORTx_GPCyR::disabled_analog;
constexpr PORTx_GPCyR::Pin_Mux_Control PORTx_GPCyR::alternative_1_GPIO;
constexpr PORTx_GPCyR::Pin_Mux_Control PORTx_GPCyR::alternative_2;
constexpr PORTx_GPCyR::Pin_Mux_Control PORTx_GPCyR::alternative_3;
constexpr PORTx_GPCyR::Pin_Mux_Control PORTx_GPCyR::alternative_4;
constexpr PORTx_GPCyR::Pin_Mux_Control PORTx_GPCyR::alternative_5;
constexpr PORTx_GPCyR::Pin_Mux_Control PORTx_GPCyR::alternative_6;
constexpr PORTx_GPCyR::Pin_Mux_Control PORTx_GPCyR::alternative_7;
constexpr PORTx_GPCyR::Drive_Strength  PORTx_GPCyR::low_drive;
constexpr PORTx_GPCyR::Drive_Strength  PORTx_GPCyR::high_drive;
constexpr PORTx_GPCyR::Open_Drain      PORTx_GPCyR::open_drain_disabled;
constexpr PORTx_GPCyR::Open_Drain      PORTx_GPCyR::open_drain_enabled;
constexpr PORTx_GPCyR::Passive_Filter  PORTx_GPCyR::passive_filter_disabled;
constexpr PORTx_GPCyR::Passive_Filter  PORTx_GPCyR::passive_filter_enabled;
constexpr PORTx_GPCyR::Slew_Rate       PORTx_GPCyR::fast_slew_rate;
constexpr PORTx_GPCyR::Slew_Rate       PORTx_GPCyR::slow_slew_rate;
constexpr PORTx_GPCyR::Internal_Pull   PORTx_GPCyR::internal_pull_disabled;
constexpr PORTx_GPCyR::Internal_Pull   PORTx_GPCyR::internal_pull_enabled ;
constexpr PORTx_GPCyR::Pull_Select     PORTx_GPCyR::pull_down;
constexpr PORTx_GPCyR::Pull_Select     PORTx_GPCyR::pull_up;

extern const PORTx_PCRn PORTA_PCR0 {0x4004'9000};
extern const PORTx_PCRn PORTA_PCR1 {0x4004'9004};
extern const PORTx_PCRn PORTA_PCR2 {0x4004'9008};
extern const PORTx_PCRn PORTA_PCR3 {0x4004'900C};
extern const PORTx_PCRn PORTA_PCR4 {0x4004'9010};
extern const PORTx_PCRn PORTA_PCR5 {0x4004'9014};
extern const PORTx_PCRn PORTA_PCR6 {0x4004'9018};
extern const PORTx_PCRn PORTA_PCR7 {0x4004'901C};
extern const PORTx_PCRn PORTA_PCR8 {0x4004'9020};
extern const PORTx_PCRn PORTA_PCR9 {0x4004'9024};
extern const PORTx_PCRn PORTA_PCR10 {0x4004'9028};
extern const PORTx_PCRn PORTA_PCR11 {0x4004'902C};
extern const PORTx_PCRn PORTA_PCR12 {0x4004'9030};
extern const PORTx_PCRn PORTA_PCR13 {0x4004'9034};
extern const PORTx_PCRn PORTA_PCR14 {0x4004'9038};
extern const PORTx_PCRn PORTA_PCR15 {0x4004'903C};
extern const PORTx_PCRn PORTA_PCR16 {0x4004'9040};
extern const PORTx_PCRn PORTA_PCR17 {0x4004'9044};
extern const PORTx_PCRn PORTA_PCR18 {0x4004'9048};
extern const PORTx_PCRn PORTA_PCR19 {0x4004'904C};
extern const PORTx_PCRn PORTA_PCR20 {0x4004'9050};
extern const PORTx_PCRn PORTA_PCR21 {0x4004'9054};
extern const PORTx_PCRn PORTA_PCR22 {0x4004'9058};
extern const PORTx_PCRn PORTA_PCR23 {0x4004'905C};
extern const PORTx_PCRn PORTA_PCR24 {0x4004'9060};
extern const PORTx_PCRn PORTA_PCR25 {0x4004'9064};
extern const PORTx_PCRn PORTA_PCR26 {0x4004'9068};
extern const PORTx_PCRn PORTA_PCR27 {0x4004'906C};
extern const PORTx_PCRn PORTA_PCR28 {0x4004'9070};
extern const PORTx_PCRn PORTA_PCR29 {0x4004'9074};
extern const PORTx_PCRn PORTA_PCR30 {0x4004'9078};
extern const PORTx_PCRn PORTA_PCR31 {0x4004'907C};
extern const PORTx_GPCLR PORTA_GPCLR {0x4004'9080};
extern const PORTx_GPCHR PORTA_GPCHR {0x4004'9084};
extern const PORTx_ISFR PORTA_ISFR {0x4004'90A0};
extern const PORTx_DFER PORTA_DFER {0x4004'90C0};
extern const PORTx_DFCR PORTA_DFCR {0x4004'90C4};
extern const PORTx_DFWR PORTA_DFWR {0x4004'90C8};

extern const PORTx_PCRn PORTB_PCR0 {0x4004'A000};
extern const PORTx_PCRn PORTB_PCR1 {0x4004'A004};
extern const PORTx_PCRn PORTB_PCR2 {0x4004'A008};
extern const PORTx_PCRn PORTB_PCR3 {0x4004'A00C};
extern const PORTx_PCRn PORTB_PCR4 {0x4004'A010};
extern const PORTx_PCRn PORTB_PCR5 {0x4004'A014};
extern const PORTx_PCRn PORTB_PCR6 {0x4004'A018};
extern const PORTx_PCRn PORTB_PCR7 {0x4004'A01C};
extern const PORTx_PCRn PORTB_PCR8 {0x4004'A020};
extern const PORTx_PCRn PORTB_PCR9 {0x4004'A024};
extern const PORTx_PCRn PORTB_PCR10 {0x4004'A028};
extern const PORTx_PCRn PORTB_PCR11 {0x4004'A02C};
extern const PORTx_PCRn PORTB_PCR12 {0x4004'A030};
extern const PORTx_PCRn PORTB_PCR13 {0x4004'A034};
extern const PORTx_PCRn PORTB_PCR14 {0x4004'A038};
extern const PORTx_PCRn PORTB_PCR15 {0x4004'A03C};
extern const PORTx_PCRn PORTB_PCR16 {0x4004'A040};
extern const PORTx_PCRn PORTB_PCR17 {0x4004'A044};
extern const PORTx_PCRn PORTB_PCR18 {0x4004'A048};
extern const PORTx_PCRn PORTB_PCR19 {0x4004'A04C};
extern const PORTx_PCRn PORTB_PCR20 {0x4004'A050};
extern const PORTx_PCRn PORTB_PCR21 {0x4004'A054};
extern const PORTx_PCRn PORTB_PCR22 {0x4004'A058};
extern const PORTx_PCRn PORTB_PCR23 {0x4004'A05C};
extern const PORTx_PCRn PORTB_PCR24 {0x4004'A060};
extern const PORTx_PCRn PORTB_PCR25 {0x4004'A064};
extern const PORTx_PCRn PORTB_PCR26 {0x4004'A068};
extern const PORTx_PCRn PORTB_PCR27 {0x4004'A06C};
extern const PORTx_PCRn PORTB_PCR28 {0x4004'A070};
extern const PORTx_PCRn PORTB_PCR29 {0x4004'A074};
extern const PORTx_PCRn PORTB_PCR30 {0x4004'A078};
extern const PORTx_PCRn PORTB_PCR31 {0x4004'A07C};
extern const PORTx_GPCLR PORTB_GPCLR {0x4004'A080};
extern const PORTx_GPCHR PORTB_GPCHR {0x4004'A084};
extern const PORTx_ISFR PORTB_ISFR {0x4004'A0A0};
extern const PORTx_DFER PORTB_DFER {0x4004'A0C0};
extern const PORTx_DFCR PORTB_DFCR {0x4004'A0C4};
extern const PORTx_DFWR PORTB_DFWR {0x4004'A0C8};

extern const PORTx_PCRn PORTC_PCR0 {0x4004'B000};
extern const PORTx_PCRn PORTC_PCR1 {0x4004'B004};
extern const PORTx_PCRn PORTC_PCR2 {0x4004'B008};
extern const PORTx_PCRn PORTC_PCR3 {0x4004'B00C};
extern const PORTx_PCRn PORTC_PCR4 {0x4004'B010};
extern const PORTx_PCRn PORTC_PCR5 {0x4004'B014};
extern const PORTx_PCRn PORTC_PCR6 {0x4004'B018};
extern const PORTx_PCRn PORTC_PCR7 {0x4004'B01C};
extern const PORTx_PCRn PORTC_PCR8 {0x4004'B020};
extern const PORTx_PCRn PORTC_PCR9 {0x4004'B024};
extern const PORTx_PCRn PORTC_PCR10 {0x4004'B028};
extern const PORTx_PCRn PORTC_PCR11 {0x4004'B02C};
extern const PORTx_PCRn PORTC_PCR12 {0x4004'B030};
extern const PORTx_PCRn PORTC_PCR13 {0x4004'B034};
extern const PORTx_PCRn PORTC_PCR14 {0x4004'B038};
extern const PORTx_PCRn PORTC_PCR15 {0x4004'B03C};
extern const PORTx_PCRn PORTC_PCR16 {0x4004'B040};
extern const PORTx_PCRn PORTC_PCR17 {0x4004'B044};
extern const PORTx_PCRn PORTC_PCR18 {0x4004'B048};
extern const PORTx_PCRn PORTC_PCR19 {0x4004'B04C};
extern const PORTx_PCRn PORTC_PCR20 {0x4004'B050};
extern const PORTx_PCRn PORTC_PCR21 {0x4004'B054};
extern const PORTx_PCRn PORTC_PCR22 {0x4004'B058};
extern const PORTx_PCRn PORTC_PCR23 {0x4004'B05C};
extern const PORTx_PCRn PORTC_PCR24 {0x4004'B060};
extern const PORTx_PCRn PORTC_PCR25 {0x4004'B064};
extern const PORTx_PCRn PORTC_PCR26 {0x4004'B068};
extern const PORTx_PCRn PORTC_PCR27 {0x4004'B06C};
extern const PORTx_PCRn PORTC_PCR28 {0x4004'B070};
extern const PORTx_PCRn PORTC_PCR29 {0x4004'B074};
extern const PORTx_PCRn PORTC_PCR30 {0x4004'B078};
extern const PORTx_PCRn PORTC_PCR31 {0x4004'B07C};
extern const PORTx_GPCLR PORTC_GPCLR {0x4004'B080};
extern const PORTx_GPCHR PORTC_GPCHR {0x4004'B084};
extern const PORTx_ISFR PORTC_ISFR {0x4004'B0A0};
extern const PORTx_DFER PORTC_DFER {0x4004'B0C0};
extern const PORTx_DFCR PORTC_DFCR {0x4004'B0C4};
extern const PORTx_DFWR PORTC_DFWR {0x4004'B0C8};

extern const PORTx_PCRn PORTD_PCR0 {0x4004'C000};
extern const PORTx_PCRn PORTD_PCR1 {0x4004'C004};
extern const PORTx_PCRn PORTD_PCR2 {0x4004'C008};
extern const PORTx_PCRn PORTD_PCR3 {0x4004'C00C};
extern const PORTx_PCRn PORTD_PCR4 {0x4004'C010};
extern const PORTx_PCRn PORTD_PCR5 {0x4004'C014};
extern const PORTx_PCRn PORTD_PCR6 {0x4004'C018};
extern const PORTx_PCRn PORTD_PCR7 {0x4004'C01C};
extern const PORTx_PCRn PORTD_PCR8 {0x4004'C020};
extern const PORTx_PCRn PORTD_PCR9 {0x4004'C024};
extern const PORTx_PCRn PORTD_PCR10 {0x4004'C028};
extern const PORTx_PCRn PORTD_PCR11 {0x4004'C02C};
extern const PORTx_PCRn PORTD_PCR12 {0x4004'C030};
extern const PORTx_PCRn PORTD_PCR13 {0x4004'C034};
extern const PORTx_PCRn PORTD_PCR14 {0x4004'C038};
extern const PORTx_PCRn PORTD_PCR15 {0x4004'C03C};
extern const PORTx_PCRn PORTD_PCR16 {0x4004'C040};
extern const PORTx_PCRn PORTD_PCR17 {0x4004'C044};
extern const PORTx_PCRn PORTD_PCR18 {0x4004'C048};
extern const PORTx_PCRn PORTD_PCR19 {0x4004'C04C};
extern const PORTx_PCRn PORTD_PCR20 {0x4004'C050};
extern const PORTx_PCRn PORTD_PCR21 {0x4004'C054};
extern const PORTx_PCRn PORTD_PCR22 {0x4004'C058};
extern const PORTx_PCRn PORTD_PCR23 {0x4004'C05C};
extern const PORTx_PCRn PORTD_PCR24 {0x4004'C060};
extern const PORTx_PCRn PORTD_PCR25 {0x4004'C064};
extern const PORTx_PCRn PORTD_PCR26 {0x4004'C068};
extern const PORTx_PCRn PORTD_PCR27 {0x4004'C06C};
extern const PORTx_PCRn PORTD_PCR28 {0x4004'C070};
extern const PORTx_PCRn PORTD_PCR29 {0x4004'C074};
extern const PORTx_PCRn PORTD_PCR30 {0x4004'C078};
extern const PORTx_PCRn PORTD_PCR31 {0x4004'C07C};
extern const PORTx_GPCLR PORTD_GPCLR {0x4004'C080};
extern const PORTx_GPCHR PORTD_GPCHR {0x4004'C084};
extern const PORTx_ISFR PORTD_ISFR {0x4004'C0A0};
extern const PORTx_DFER PORTD_DFER {0x4004'C0C0};
extern const PORTx_DFCR PORTD_DFCR {0x4004'C0C4};
extern const PORTx_DFWR PORTD_DFWR {0x4004'C0C8};

extern const PORTx_PCRn PORTE_PCR0 {0x4004'D000};
extern const PORTx_PCRn PORTE_PCR1 {0x4004'D004};
extern const PORTx_PCRn PORTE_PCR2 {0x4004'D008};
extern const PORTx_PCRn PORTE_PCR3 {0x4004'D00C};
extern const PORTx_PCRn PORTE_PCR4 {0x4004'D010};
extern const PORTx_PCRn PORTE_PCR5 {0x4004'D014};
extern const PORTx_PCRn PORTE_PCR6 {0x4004'D018};
extern const PORTx_PCRn PORTE_PCR7 {0x4004'D01C};
extern const PORTx_PCRn PORTE_PCR8 {0x4004'D020};
extern const PORTx_PCRn PORTE_PCR9 {0x4004'D024};
extern const PORTx_PCRn PORTE_PCR10 {0x4004'D028};
extern const PORTx_PCRn PORTE_PCR11 {0x4004'D02C};
extern const PORTx_PCRn PORTE_PCR12 {0x4004'D030};
extern const PORTx_PCRn PORTE_PCR13 {0x4004'D034};
extern const PORTx_PCRn PORTE_PCR14 {0x4004'D038};
extern const PORTx_PCRn PORTE_PCR15 {0x4004'D03C};
extern const PORTx_PCRn PORTE_PCR16 {0x4004'D040};
extern const PORTx_PCRn PORTE_PCR17 {0x4004'D044};
extern const PORTx_PCRn PORTE_PCR18 {0x4004'D048};
extern const PORTx_PCRn PORTE_PCR19 {0x4004'D04C};
extern const PORTx_PCRn PORTE_PCR20 {0x4004'D050};
extern const PORTx_PCRn PORTE_PCR21 {0x4004'D054};
extern const PORTx_PCRn PORTE_PCR22 {0x4004'D058};
extern const PORTx_PCRn PORTE_PCR23 {0x4004'D05C};
extern const PORTx_PCRn PORTE_PCR24 {0x4004'D060};
extern const PORTx_PCRn PORTE_PCR25 {0x4004'D064};
extern const PORTx_PCRn PORTE_PCR26 {0x4004'D068};
extern const PORTx_PCRn PORTE_PCR27 {0x4004'D06C};
extern const PORTx_PCRn PORTE_PCR28 {0x4004'D070};
extern const PORTx_PCRn PORTE_PCR29 {0x4004'D074};
extern const PORTx_PCRn PORTE_PCR30 {0x4004'D078};
extern const PORTx_PCRn PORTE_PCR31 {0x4004'D07C};
extern const PORTx_GPCLR PORTE_GPCLR {0x4004'D080};
extern const PORTx_GPCHR PORTE_GPCHR {0x4004'D084};
extern const PORTx_ISFR PORTE_ISFR {0x4004'D0A0};
extern const PORTx_DFER PORTE_DFER {0x4004'D0C0};
extern const PORTx_DFCR PORTE_DFCR {0x4004'D0C4};
extern const PORTx_DFWR PORTE_DFWR {0x4004'D0C8};
*/
} // namespace platform::port

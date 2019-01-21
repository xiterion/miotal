#include <miotal/ARM/Cortex/M4/NXP/K2x/port.hpp>

namespace platform::port {

volatile PORTx_PCRn& PORTA_PCR0 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9000);
volatile PORTx_PCRn& PORTA_PCR1 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9004);
volatile PORTx_PCRn& PORTA_PCR2 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9008);
volatile PORTx_PCRn& PORTA_PCR3 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'900C);
volatile PORTx_PCRn& PORTA_PCR4 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9010);
volatile PORTx_PCRn& PORTA_PCR5 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9014);
volatile PORTx_PCRn& PORTA_PCR6 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9018);
volatile PORTx_PCRn& PORTA_PCR7 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'901C);
volatile PORTx_PCRn& PORTA_PCR8 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9020);
volatile PORTx_PCRn& PORTA_PCR9 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9024);
volatile PORTx_PCRn& PORTA_PCR10 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9028);
volatile PORTx_PCRn& PORTA_PCR11 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'902C);
volatile PORTx_PCRn& PORTA_PCR12 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9030);
volatile PORTx_PCRn& PORTA_PCR13 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9034);
volatile PORTx_PCRn& PORTA_PCR14 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9038);
volatile PORTx_PCRn& PORTA_PCR15 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'903C);
volatile PORTx_PCRn& PORTA_PCR16 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9040);
volatile PORTx_PCRn& PORTA_PCR17 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9044);
volatile PORTx_PCRn& PORTA_PCR18 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9048);
volatile PORTx_PCRn& PORTA_PCR19 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'904C);
volatile PORTx_PCRn& PORTA_PCR20 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9050);
volatile PORTx_PCRn& PORTA_PCR21 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9054);
volatile PORTx_PCRn& PORTA_PCR22 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9058);
volatile PORTx_PCRn& PORTA_PCR23 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'905C);
volatile PORTx_PCRn& PORTA_PCR24 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9060);
volatile PORTx_PCRn& PORTA_PCR25 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9064);
volatile PORTx_PCRn& PORTA_PCR26 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9068);
volatile PORTx_PCRn& PORTA_PCR27 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'906C);
volatile PORTx_PCRn& PORTA_PCR28 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9070);
volatile PORTx_PCRn& PORTA_PCR29 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9074);
volatile PORTx_PCRn& PORTA_PCR30 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'9078);
volatile PORTx_PCRn& PORTA_PCR31 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'907C);
volatile PORTx_GPCLR& PORTA_GPCLR = *reinterpret_cast<volatile PORTx_GPCLR*>(0x4004'9080);
volatile PORTx_GPCHR& PORTA_GPCHR = *reinterpret_cast<volatile PORTx_GPCHR*>(0x4004'9084);
volatile PORTx_ISFR& PORTA_ISFR = *reinterpret_cast<volatile PORTx_ISFR*>(0x4004'90A0);
volatile PORTx_DFER& PORTA_DFER = *reinterpret_cast<volatile PORTx_DFER*>(0x4004'90C0);
volatile PORTx_DFCR& PORTA_DFCR = *reinterpret_cast<volatile PORTx_DFCR*>(0x4004'90C4);
volatile PORTx_DFWR& PORTA_DFWR = *reinterpret_cast<volatile PORTx_DFWR*>(0x4004'90C8);

volatile PORTx_PCRn& PORTB_PCR0 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A000);
volatile PORTx_PCRn& PORTB_PCR1 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A004);
volatile PORTx_PCRn& PORTB_PCR2 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A008);
volatile PORTx_PCRn& PORTB_PCR3 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A00C);
volatile PORTx_PCRn& PORTB_PCR4 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A010);
volatile PORTx_PCRn& PORTB_PCR5 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A014);
volatile PORTx_PCRn& PORTB_PCR6 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A018);
volatile PORTx_PCRn& PORTB_PCR7 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A01C);
volatile PORTx_PCRn& PORTB_PCR8 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A020);
volatile PORTx_PCRn& PORTB_PCR9 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A024);
volatile PORTx_PCRn& PORTB_PCR10 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A028);
volatile PORTx_PCRn& PORTB_PCR11 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A02C);
volatile PORTx_PCRn& PORTB_PCR12 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A030);
volatile PORTx_PCRn& PORTB_PCR13 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A034);
volatile PORTx_PCRn& PORTB_PCR14 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A038);
volatile PORTx_PCRn& PORTB_PCR15 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A03C);
volatile PORTx_PCRn& PORTB_PCR16 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A040);
volatile PORTx_PCRn& PORTB_PCR17 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A044);
volatile PORTx_PCRn& PORTB_PCR18 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A048);
volatile PORTx_PCRn& PORTB_PCR19 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A04C);
volatile PORTx_PCRn& PORTB_PCR20 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A050);
volatile PORTx_PCRn& PORTB_PCR21 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A054);
volatile PORTx_PCRn& PORTB_PCR22 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A058);
volatile PORTx_PCRn& PORTB_PCR23 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A05C);
volatile PORTx_PCRn& PORTB_PCR24 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A060);
volatile PORTx_PCRn& PORTB_PCR25 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A064);
volatile PORTx_PCRn& PORTB_PCR26 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A068);
volatile PORTx_PCRn& PORTB_PCR27 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A06C);
volatile PORTx_PCRn& PORTB_PCR28 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A070);
volatile PORTx_PCRn& PORTB_PCR29 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A074);
volatile PORTx_PCRn& PORTB_PCR30 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A078);
volatile PORTx_PCRn& PORTB_PCR31 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'A07C);
volatile PORTx_GPCLR& PORTB_GPCLR = *reinterpret_cast<volatile PORTx_GPCLR*>(0x4004'A080);
volatile PORTx_GPCHR& PORTB_GPCHR = *reinterpret_cast<volatile PORTx_GPCHR*>(0x4004'A084);
volatile PORTx_ISFR& PORTB_ISFR = *reinterpret_cast<volatile PORTx_ISFR*>(0x4004'A0A0);
volatile PORTx_DFER& PORTB_DFER = *reinterpret_cast<volatile PORTx_DFER*>(0x4004'A0C0);
volatile PORTx_DFCR& PORTB_DFCR = *reinterpret_cast<volatile PORTx_DFCR*>(0x4004'A0C4);
volatile PORTx_DFWR& PORTB_DFWR = *reinterpret_cast<volatile PORTx_DFWR*>(0x4004'A0C8);

volatile PORTx_PCRn& PORTC_PCR0 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B000);
volatile PORTx_PCRn& PORTC_PCR1 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B004);
volatile PORTx_PCRn& PORTC_PCR2 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B008);
volatile PORTx_PCRn& PORTC_PCR3 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B00C);
volatile PORTx_PCRn& PORTC_PCR4 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B010);
volatile PORTx_PCRn& PORTC_PCR5 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B014);
volatile PORTx_PCRn& PORTC_PCR6 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B018);
volatile PORTx_PCRn& PORTC_PCR7 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B01C);
volatile PORTx_PCRn& PORTC_PCR8 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B020);
volatile PORTx_PCRn& PORTC_PCR9 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B024);
volatile PORTx_PCRn& PORTC_PCR10 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B028);
volatile PORTx_PCRn& PORTC_PCR11 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B02C);
volatile PORTx_PCRn& PORTC_PCR12 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B030);
volatile PORTx_PCRn& PORTC_PCR13 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B034);
volatile PORTx_PCRn& PORTC_PCR14 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B038);
volatile PORTx_PCRn& PORTC_PCR15 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B03C);
volatile PORTx_PCRn& PORTC_PCR16 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B040);
volatile PORTx_PCRn& PORTC_PCR17 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B044);
volatile PORTx_PCRn& PORTC_PCR18 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B048);
volatile PORTx_PCRn& PORTC_PCR19 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B04C);
volatile PORTx_PCRn& PORTC_PCR20 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B050);
volatile PORTx_PCRn& PORTC_PCR21 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B054);
volatile PORTx_PCRn& PORTC_PCR22 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B058);
volatile PORTx_PCRn& PORTC_PCR23 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B05C);
volatile PORTx_PCRn& PORTC_PCR24 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B060);
volatile PORTx_PCRn& PORTC_PCR25 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B064);
volatile PORTx_PCRn& PORTC_PCR26 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B068);
volatile PORTx_PCRn& PORTC_PCR27 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B06C);
volatile PORTx_PCRn& PORTC_PCR28 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B070);
volatile PORTx_PCRn& PORTC_PCR29 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B074);
volatile PORTx_PCRn& PORTC_PCR30 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B078);
volatile PORTx_PCRn& PORTC_PCR31 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'B07C);
volatile PORTx_GPCLR& PORTC_GPCLR = *reinterpret_cast<volatile PORTx_GPCLR*>(0x4004'B080);
volatile PORTx_GPCHR& PORTC_GPCHR = *reinterpret_cast<volatile PORTx_GPCHR*>(0x4004'B084);
volatile PORTx_ISFR& PORTC_ISFR = *reinterpret_cast<volatile PORTx_ISFR*>(0x4004'B0A0);
volatile PORTx_DFER& PORTC_DFER = *reinterpret_cast<volatile PORTx_DFER*>(0x4004'B0C0);
volatile PORTx_DFCR& PORTC_DFCR = *reinterpret_cast<volatile PORTx_DFCR*>(0x4004'B0C4);
volatile PORTx_DFWR& PORTC_DFWR = *reinterpret_cast<volatile PORTx_DFWR*>(0x4004'B0C8);

volatile PORTx_PCRn& PORTD_PCR0 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C000);
volatile PORTx_PCRn& PORTD_PCR1 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C004);
volatile PORTx_PCRn& PORTD_PCR2 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C008);
volatile PORTx_PCRn& PORTD_PCR3 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C00C);
volatile PORTx_PCRn& PORTD_PCR4 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C010);
volatile PORTx_PCRn& PORTD_PCR5 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C014);
volatile PORTx_PCRn& PORTD_PCR6 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C018);
volatile PORTx_PCRn& PORTD_PCR7 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C01C);
volatile PORTx_PCRn& PORTD_PCR8 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C020);
volatile PORTx_PCRn& PORTD_PCR9 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C024);
volatile PORTx_PCRn& PORTD_PCR10 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C028);
volatile PORTx_PCRn& PORTD_PCR11 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C02C);
volatile PORTx_PCRn& PORTD_PCR12 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C030);
volatile PORTx_PCRn& PORTD_PCR13 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C034);
volatile PORTx_PCRn& PORTD_PCR14 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C038);
volatile PORTx_PCRn& PORTD_PCR15 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C03C);
volatile PORTx_PCRn& PORTD_PCR16 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C040);
volatile PORTx_PCRn& PORTD_PCR17 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C044);
volatile PORTx_PCRn& PORTD_PCR18 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C048);
volatile PORTx_PCRn& PORTD_PCR19 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C04C);
volatile PORTx_PCRn& PORTD_PCR20 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C050);
volatile PORTx_PCRn& PORTD_PCR21 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C054);
volatile PORTx_PCRn& PORTD_PCR22 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C058);
volatile PORTx_PCRn& PORTD_PCR23 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C05C);
volatile PORTx_PCRn& PORTD_PCR24 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C060);
volatile PORTx_PCRn& PORTD_PCR25 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C064);
volatile PORTx_PCRn& PORTD_PCR26 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C068);
volatile PORTx_PCRn& PORTD_PCR27 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C06C);
volatile PORTx_PCRn& PORTD_PCR28 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C070);
volatile PORTx_PCRn& PORTD_PCR29 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C074);
volatile PORTx_PCRn& PORTD_PCR30 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C078);
volatile PORTx_PCRn& PORTD_PCR31 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'C07C);
volatile PORTx_GPCLR& PORTD_GPCLR = *reinterpret_cast<volatile PORTx_GPCLR*>(0x4004'C080);
volatile PORTx_GPCHR& PORTD_GPCHR = *reinterpret_cast<volatile PORTx_GPCHR*>(0x4004'C084);
volatile PORTx_ISFR& PORTD_ISFR = *reinterpret_cast<volatile PORTx_ISFR*>(0x4004'C0A0);
volatile PORTx_DFER& PORTD_DFER = *reinterpret_cast<volatile PORTx_DFER*>(0x4004'C0C0);
volatile PORTx_DFCR& PORTD_DFCR = *reinterpret_cast<volatile PORTx_DFCR*>(0x4004'C0C4);
volatile PORTx_DFWR& PORTD_DFWR = *reinterpret_cast<volatile PORTx_DFWR*>(0x4004'C0C8);

volatile PORTx_PCRn& PORTE_PCR0 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D000);
volatile PORTx_PCRn& PORTE_PCR1 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D004);
volatile PORTx_PCRn& PORTE_PCR2 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D008);
volatile PORTx_PCRn& PORTE_PCR3 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D00C);
volatile PORTx_PCRn& PORTE_PCR4 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D010);
volatile PORTx_PCRn& PORTE_PCR5 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D014);
volatile PORTx_PCRn& PORTE_PCR6 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D018);
volatile PORTx_PCRn& PORTE_PCR7 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D01C);
volatile PORTx_PCRn& PORTE_PCR8 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D020);
volatile PORTx_PCRn& PORTE_PCR9 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D024);
volatile PORTx_PCRn& PORTE_PCR10 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D028);
volatile PORTx_PCRn& PORTE_PCR11 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D02C);
volatile PORTx_PCRn& PORTE_PCR12 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D030);
volatile PORTx_PCRn& PORTE_PCR13 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D034);
volatile PORTx_PCRn& PORTE_PCR14 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D038);
volatile PORTx_PCRn& PORTE_PCR15 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D03C);
volatile PORTx_PCRn& PORTE_PCR16 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D040);
volatile PORTx_PCRn& PORTE_PCR17 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D044);
volatile PORTx_PCRn& PORTE_PCR18 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D048);
volatile PORTx_PCRn& PORTE_PCR19 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D04C);
volatile PORTx_PCRn& PORTE_PCR20 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D050);
volatile PORTx_PCRn& PORTE_PCR21 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D054);
volatile PORTx_PCRn& PORTE_PCR22 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D058);
volatile PORTx_PCRn& PORTE_PCR23 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D05C);
volatile PORTx_PCRn& PORTE_PCR24 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D060);
volatile PORTx_PCRn& PORTE_PCR25 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D064);
volatile PORTx_PCRn& PORTE_PCR26 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D068);
volatile PORTx_PCRn& PORTE_PCR27 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D06C);
volatile PORTx_PCRn& PORTE_PCR28 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D070);
volatile PORTx_PCRn& PORTE_PCR29 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D074);
volatile PORTx_PCRn& PORTE_PCR30 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D078);
volatile PORTx_PCRn& PORTE_PCR31 = *reinterpret_cast<volatile PORTx_PCRn*>(0x4004'D07C);
volatile PORTx_GPCLR& PORTE_GPCLR = *reinterpret_cast<volatile PORTx_GPCLR*>(0x4004'D080);
volatile PORTx_GPCHR& PORTE_GPCHR = *reinterpret_cast<volatile PORTx_GPCHR*>(0x4004'D084);
volatile PORTx_ISFR& PORTE_ISFR = *reinterpret_cast<volatile PORTx_ISFR*>(0x4004'D0A0);
volatile PORTx_DFER& PORTE_DFER = *reinterpret_cast<volatile PORTx_DFER*>(0x4004'D0C0);
volatile PORTx_DFCR& PORTE_DFCR = *reinterpret_cast<volatile PORTx_DFCR*>(0x4004'D0C4);
volatile PORTx_DFWR& PORTE_DFWR = *reinterpret_cast<volatile PORTx_DFWR*>(0x4004'D0C8);

} // namespace platform::port
#include <miotal/ARM/Cortex/M4/NXP/K2x/sim.hpp>

namespace platform::sim {

volatile SIM_SOPT1_t&    SIM_SOPT1    = *reinterpret_cast<volatile SIM_SOPT1_t*> (0x4004'7000);
volatile SIM_SOPT1CFG_t& SIM_SOPT1CFG = *reinterpret_cast<volatile SIM_SOPT1CFG_t*> (0x4004'7004);
volatile SIM_SOPT2_t&    SIM_SOPT2    = *reinterpret_cast<volatile SIM_SOPT2_t*> (0x4004'8004);
volatile SIM_SOPT4_t&    SIM_SOPT4    = *reinterpret_cast<volatile SIM_SOPT4_t*> (0x4004'800C);
volatile SIM_SOPT5_t&    SIM_SOPT5    = *reinterpret_cast<volatile SIM_SOPT5_t*> (0x4004'8010);
volatile SIM_SOPT7_t&    SIM_SOPT7    = *reinterpret_cast<volatile SIM_SOPT7_t*> (0x4004'8018);
volatile SIM_SDID_t&     SIM_SDID     = *reinterpret_cast<volatile SIM_SDID_t*> (0x4004'8024);
volatile SIM_SCGC1_t&    SIM_SCGC1    = *reinterpret_cast<volatile SIM_SCGC1_t*> (0x4004'8028);
volatile SIM_SCGC2_t&    SIM_SCGC2    = *reinterpret_cast<volatile SIM_SCGC2_t*> (0x4004'802C);
volatile SIM_SCGC3_t&    SIM_SCGC3    = *reinterpret_cast<volatile SIM_SCGC3_t*> (0x4004'8030);
volatile SIM_SCGC4_t&    SIM_SCGC4    = *reinterpret_cast<volatile SIM_SCGC4_t*> (0x4004'8034);
volatile SIM_SCGC5_t&    SIM_SCGC5    = *reinterpret_cast<volatile SIM_SCGC5_t*> (0x4004'8038);
volatile SIM_SCGC6_t&    SIM_SCGC6    = *reinterpret_cast<volatile SIM_SCGC6_t*> (0x4004'803C);
volatile SIM_SCGC7_t&    SIM_SCGC7    = *reinterpret_cast<volatile SIM_SCGC7_t*> (0x4004'8040);
volatile SIM_CLKDIV1_t&  SIM_CLKDIV1  = *reinterpret_cast<volatile SIM_CLKDIV1_t*> (0x4004'8044);
volatile SIM_CLKDIV2_t&  SIM_CLKDIV2  = *reinterpret_cast<volatile SIM_CLKDIV2_t*> (0x4004'8048);
volatile SIM_FCFG1_t&    SIM_FCFG1    = *reinterpret_cast<volatile SIM_FCFG1_t*> (0x4004'804C);
volatile SIM_FCFG2_t&    SIM_FCFG2    = *reinterpret_cast<volatile SIM_FCFG2_t*> (0x4004'8050);
volatile SIM_UIDH_t&     SIM_UIDH     = *reinterpret_cast<volatile SIM_UIDH_t*> (0x4004'8054);
volatile SIM_UIDHM_t&    SIM_UIDHM    = *reinterpret_cast<volatile SIM_UIDHM_t*> (0x4004'8058);
volatile SIM_UIDML_t&    SIM_UIDML    = *reinterpret_cast<volatile SIM_UIDML_t*> (0x4004'805C);
volatile SIM_UIDL_t&     SIM_UIDL     = *reinterpret_cast<volatile SIM_UIDL_t*> (0x4004'8060);

} // namespace platform::sim

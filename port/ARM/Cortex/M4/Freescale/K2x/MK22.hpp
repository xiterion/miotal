#pragma once

#include <type_traits>

using BitBandEnabled = std::false_type;
#include <port/ARM/Cortex/M4/Freescale/register.hpp>

namespace port {

struct PORTx_PCRn : public Register<std::uint32_t>
{
    constexpr PORTx_PCRn(std::uint32_t address) : Register<std::uint32_t>(address),
        ISF(this, 24), IRQC(this, 23, 20), LK(this, 15), MUX(this, 11, 8),
        DSE(this, 6), ODE(this, 5), PFE(this, 4), SRE(this, 2), PE(this, 1), PS(this, 0) {};

    W1C  ISF;
    Bits IRQC;
    Bit  LK;
    Bits MUX;
    Bit  DSE;
    Bit  ODE;
    Bit  PFE;
    Bit  SRE;
    Bit  PE;
    Bit  PS;

    inline constexpr std::uint32_t initializer(
            bool LK, bool DSE, bool ODE, bool PFE, bool SRE, bool PE, bool PS);
};

constexpr std::uint32_t PORTx_PCRn::initializer(
        bool lk, bool dse, bool ode, bool pfe, bool sre, bool pe, bool ps)
{
    return (lk  ? LK.mask  : 0) |
           (dse ? DSE.mask : 0) |
           (ode ? ODE.mask : 0) |
           (pfe ? PFE.mask : 0) |
           (sre ? SRE.mask : 0) |
           (pe  ? PE.mask  : 0) |
           (ps  ? PS.mask  : 0);
}

PORTx_PCRn  PORTA_PCR0(0x40049000);
PORTx_PCRn  PORTA_PCR1(0x40049004);
PORTx_PCRn  PORTA_PCR2(0x40049008);
PORTx_PCRn  PORTA_PCR3(0x4004900C);
PORTx_PCRn  PORTA_PCR4(0x40049010);
PORTx_PCRn  PORTA_PCR5(0x40049014);
PORTx_PCRn  PORTA_PCR6(0x40049018);
PORTx_PCRn  PORTA_PCR7(0x4004901C);
PORTx_PCRn  PORTA_PCR8(0x40049020);
PORTx_PCRn  PORTA_PCR9(0x40049024);
PORTx_PCRn PORTA_PCR10(0x40049028);
PORTx_PCRn PORTA_PCR11(0x4004902C);
PORTx_PCRn PORTA_PCR12(0x40049030);
PORTx_PCRn PORTA_PCR13(0x40049034);
PORTx_PCRn PORTA_PCR14(0x40049038);
PORTx_PCRn PORTA_PCR15(0x4004903C);
PORTx_PCRn PORTA_PCR16(0x40049040);
PORTx_PCRn PORTA_PCR17(0x40049044);
PORTx_PCRn PORTA_PCR18(0x40049048);
PORTx_PCRn PORTA_PCR19(0x4004904C);
PORTx_PCRn PORTA_PCR20(0x40049050);
PORTx_PCRn PORTA_PCR21(0x40049054);
PORTx_PCRn PORTA_PCR22(0x40049058);
PORTx_PCRn PORTA_PCR23(0x4004905C);
PORTx_PCRn PORTA_PCR24(0x40049060);
PORTx_PCRn PORTA_PCR25(0x40049064);
PORTx_PCRn PORTA_PCR26(0x40049068);
PORTx_PCRn PORTA_PCR27(0x4004906C);
PORTx_PCRn PORTA_PCR28(0x40049070);
PORTx_PCRn PORTA_PCR29(0x40049074);
PORTx_PCRn PORTA_PCR30(0x40049078);
PORTx_PCRn PORTA_PCR31(0x4004907C);

} // namespace port

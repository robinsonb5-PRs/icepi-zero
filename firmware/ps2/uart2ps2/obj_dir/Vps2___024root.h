// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vps2.h for the primary calling header

#ifndef VERILATED_VPS2___024ROOT_H_
#define VERILATED_VPS2___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vps2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vps2___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ ps2kbd__DOT__clk;
    VL_OUT8(ps2_code,7,0);
    VL_OUT8(strobe,0,0);
    VL_OUT8(err,0,0);
    CData/*7:0*/ ps2kbd__DOT__uart_data;
    CData/*0:0*/ ps2kbd__DOT__uart_finish;
    CData/*0:0*/ ps2kbd__DOT__ps2_clk;
    CData/*0:0*/ ps2kbd__DOT__ps2_data;
    CData/*0:0*/ ps2kbd__DOT__serin;
    CData/*0:0*/ ps2kbd__DOT__bitclk;
    CData/*2:0*/ ps2kbd__DOT__stable;
    CData/*3:0*/ ps2kbd__DOT__bitcnt;
    CData/*0:0*/ ps2kbd__DOT__parity;
    CData/*3:0*/ ps2kbd__DOT__ps2_core__DOT__index;
    CData/*0:0*/ __Vtrigprevexpr___TOP__ps2kbd__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*8:0*/ ps2kbd__DOT__shift;
    SData/*8:0*/ ps2kbd__DOT__ps2_core__DOT__data_latch;
    SData/*15:0*/ ps2kbd__DOT__ps2_core__DOT__clkd;
    IData/*31:0*/ ps2kbd__DOT__ps2_core__DOT__state;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vps2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vps2___024root(Vps2__Syms* symsp, const char* v__name);
    ~Vps2___024root();
    VL_UNCOPYABLE(Vps2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vps2.h for the primary calling header

#include "Vps2__pch.h"
#include "Vps2__Syms.h"
#include "Vps2___024root.h"

VL_INLINE_OPT VlCoroutine Vps2___024root___eval_initial__TOP__Vtiming__0(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"test.vcd"});
    vlSymsp->_traceDumpOpen();
    vlSelfRef.ps2kbd__DOT__clk = 0U;
    vlSelfRef.ps2kbd__DOT__uart_data = 0xbU;
    vlSelfRef.ps2kbd__DOT__uart_finish = 0U;
    co_await vlSelfRef.__VdlySched.delay(0xaULL, nullptr, 
                                         "tb/ps2kbd.v", 
                                         27);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "tb/ps2kbd.v", 
                                         28);
    vlSelfRef.ps2kbd__DOT__uart_finish = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "tb/ps2kbd.v", 
                                         29);
    vlSelfRef.ps2kbd__DOT__uart_finish = 0U;
    vlSelfRef.ps2kbd__DOT__uart_data = 0x37U;
    vlSelfRef.ps2kbd__DOT__uart_finish = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7a120ULL, 
                                         nullptr, "tb/ps2kbd.v", 
                                         33);
    vlSelfRef.ps2kbd__DOT__uart_finish = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "tb/ps2kbd.v", 
                                         34);
    vlSelfRef.ps2kbd__DOT__uart_finish = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x186a0ULL, 
                                         nullptr, "tb/ps2kbd.v", 
                                         36);
    VL_FINISH_MT("tb/ps2kbd.v", 36, "");
}

VL_INLINE_OPT VlCoroutine Vps2___024root___eval_initial__TOP__Vtiming__1(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "tb/ps2kbd.v", 
                                             40);
        vlSelfRef.ps2kbd__DOT__clk = (1U & (~ (IData)(vlSelfRef.ps2kbd__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2___024root___dump_triggers__act(Vps2___024root* vlSelf);
#endif  // VL_DEBUG

void Vps2___024root___eval_triggers__act(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_triggers__act\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.ps2kbd__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ps2kbd__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__ps2kbd__DOT__clk__0 
        = vlSelfRef.ps2kbd__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vps2___024root___dump_triggers__act(vlSelf);
    }
#endif
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vps2.h for the primary calling header

#include "Vps2__pch.h"
#include "Vps2___024root.h"

VL_ATTR_COLD void Vps2___024root___eval_static__TOP(Vps2___024root* vlSelf);
VL_ATTR_COLD void Vps2___024root____Vm_traceActivitySetAll(Vps2___024root* vlSelf);

VL_ATTR_COLD void Vps2___024root___eval_static(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_static\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vps2___024root___eval_static__TOP(vlSelf);
    Vps2___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__ps2kbd__DOT__clk__0 
        = vlSelfRef.ps2kbd__DOT__clk;
}

VL_ATTR_COLD void Vps2___024root___eval_static__TOP(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_static__TOP\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ps2kbd__DOT__bitclk = 0U;
    vlSelfRef.ps2kbd__DOT__stable = 0U;
    vlSelfRef.ps2kbd__DOT__shift = 0U;
    vlSelfRef.ps2kbd__DOT__bitcnt = 0U;
    vlSelfRef.ps2kbd__DOT__parity = 0U;
}

VL_ATTR_COLD void Vps2___024root___eval_initial__TOP(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_initial__TOP\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ps2kbd__DOT__ps2_core__DOT__state = 0U;
    vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd = 0U;
    vlSelfRef.ps2kbd__DOT__ps2_core__DOT__data_latch = 0U;
    vlSelfRef.ps2kbd__DOT__ps2_core__DOT__index = 0U;
    vlSelfRef.ps2kbd__DOT__ps2_clk = 1U;
}

VL_ATTR_COLD void Vps2___024root___eval_final(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_final\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vps2___024root___eval_settle(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_settle\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2___024root___dump_triggers__act(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___dump_triggers__act\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge ps2kbd.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2___024root___dump_triggers__nba(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___dump_triggers__nba\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge ps2kbd.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vps2___024root____Vm_traceActivitySetAll(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root____Vm_traceActivitySetAll\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vps2___024root___ctor_var_reset(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___ctor_var_reset\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->ps2_code = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1088963279512782008ull);
    vlSelf->strobe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11782777908846002911ull);
    vlSelf->err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10541192957841604819ull);
    vlSelf->ps2kbd__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 346804435511260679ull);
    vlSelf->ps2kbd__DOT__uart_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10977354960152792384ull);
    vlSelf->ps2kbd__DOT__uart_finish = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12167299134039168692ull);
    vlSelf->ps2kbd__DOT__ps2_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7581588866483514754ull);
    vlSelf->ps2kbd__DOT__ps2_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3038262626297830034ull);
    vlSelf->ps2kbd__DOT__serin = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12739600385114992010ull);
    vlSelf->ps2kbd__DOT__bitclk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16057416153207281658ull);
    vlSelf->ps2kbd__DOT__stable = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12330548797581321070ull);
    vlSelf->ps2kbd__DOT__shift = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13222271670301522109ull);
    vlSelf->ps2kbd__DOT__bitcnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3399688553740502853ull);
    vlSelf->ps2kbd__DOT__parity = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13593664016598284850ull);
    vlSelf->ps2kbd__DOT__ps2_core__DOT__data_latch = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 11293079778714477306ull);
    vlSelf->ps2kbd__DOT__ps2_core__DOT__clkd = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7663122232003273793ull);
    vlSelf->ps2kbd__DOT__ps2_core__DOT__index = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10895918864399622120ull);
    vlSelf->ps2kbd__DOT__ps2_core__DOT__state = 0;
    vlSelf->__Vtrigprevexpr___TOP__ps2kbd__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12765205285390087473ull);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

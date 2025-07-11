// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vps2.h for the primary calling header

#include "Vps2__pch.h"
#include "Vps2___024root.h"

VL_ATTR_COLD void Vps2___024root___eval_initial__TOP(Vps2___024root* vlSelf);
VlCoroutine Vps2___024root___eval_initial__TOP__Vtiming__0(Vps2___024root* vlSelf);
VlCoroutine Vps2___024root___eval_initial__TOP__Vtiming__1(Vps2___024root* vlSelf);

void Vps2___024root___eval_initial(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_initial\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vps2___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vps2___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vps2___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vps2___024root___eval_act(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_act\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vps2___024root___nba_sequent__TOP__0(Vps2___024root* vlSelf);

void Vps2___024root___eval_nba(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_nba\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vps2___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

VL_INLINE_OPT void Vps2___024root___nba_sequent__TOP__0(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___nba_sequent__TOP__0\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __Vdly__ps2kbd__DOT__bitcnt;
    __Vdly__ps2kbd__DOT__bitcnt = 0;
    CData/*0:0*/ __Vdly__ps2kbd__DOT__parity;
    __Vdly__ps2kbd__DOT__parity = 0;
    SData/*8:0*/ __Vdly__ps2kbd__DOT__shift;
    __Vdly__ps2kbd__DOT__shift = 0;
    SData/*15:0*/ __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd;
    __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd = 0;
    CData/*3:0*/ __Vdly__ps2kbd__DOT__ps2_core__DOT__index;
    __Vdly__ps2kbd__DOT__ps2_core__DOT__index = 0;
    IData/*31:0*/ __Vdly__ps2kbd__DOT__ps2_core__DOT__state;
    __Vdly__ps2kbd__DOT__ps2_core__DOT__state = 0;
    SData/*8:0*/ __Vdly__ps2kbd__DOT__ps2_core__DOT__data_latch;
    __Vdly__ps2kbd__DOT__ps2_core__DOT__data_latch = 0;
    // Body
    __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd = vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd;
    __Vdly__ps2kbd__DOT__ps2_core__DOT__index = vlSelfRef.ps2kbd__DOT__ps2_core__DOT__index;
    __Vdly__ps2kbd__DOT__ps2_core__DOT__state = vlSelfRef.ps2kbd__DOT__ps2_core__DOT__state;
    __Vdly__ps2kbd__DOT__ps2_core__DOT__data_latch 
        = vlSelfRef.ps2kbd__DOT__ps2_core__DOT__data_latch;
    __Vdly__ps2kbd__DOT__bitcnt = vlSelfRef.ps2kbd__DOT__bitcnt;
    __Vdly__ps2kbd__DOT__parity = vlSelfRef.ps2kbd__DOT__parity;
    __Vdly__ps2kbd__DOT__shift = vlSelfRef.ps2kbd__DOT__shift;
    vlSelfRef.strobe = 0U;
    vlSelfRef.err = 0U;
    if (((~ (0U != (3U & (IData)(vlSelfRef.ps2kbd__DOT__stable)))) 
         & (IData)(vlSelfRef.ps2kbd__DOT__bitclk))) {
        if ((0U == (IData)(vlSelfRef.ps2kbd__DOT__bitcnt))) {
            if ((1U & (~ (IData)(vlSelfRef.ps2kbd__DOT__serin)))) {
                __Vdly__ps2kbd__DOT__bitcnt = (0xfU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.ps2kbd__DOT__bitcnt)));
            }
            __Vdly__ps2kbd__DOT__parity = 0U;
        } else if ((0xaU > (IData)(vlSelfRef.ps2kbd__DOT__bitcnt))) {
            __Vdly__ps2kbd__DOT__parity = ((IData)(vlSelfRef.ps2kbd__DOT__parity) 
                                           ^ (IData)(vlSelfRef.ps2kbd__DOT__serin));
            __Vdly__ps2kbd__DOT__shift = (((IData)(vlSelfRef.ps2kbd__DOT__serin) 
                                           << 8U) | 
                                          (0xffU & 
                                           ((IData)(vlSelfRef.ps2kbd__DOT__shift) 
                                            >> 1U)));
            __Vdly__ps2kbd__DOT__bitcnt = (0xfU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.ps2kbd__DOT__bitcnt)));
        } else {
            __Vdly__ps2kbd__DOT__bitcnt = 0U;
            if (((IData)(vlSelfRef.ps2kbd__DOT__parity) 
                 & (IData)(vlSelfRef.ps2kbd__DOT__serin))) {
                vlSelfRef.ps2_code = (0xffU & (IData)(vlSelfRef.ps2kbd__DOT__shift));
                vlSelfRef.strobe = 1U;
            } else {
                vlSelfRef.err = 1U;
            }
        }
    }
    vlSelfRef.ps2kbd__DOT__bitcnt = __Vdly__ps2kbd__DOT__bitcnt;
    vlSelfRef.ps2kbd__DOT__parity = __Vdly__ps2kbd__DOT__parity;
    vlSelfRef.ps2kbd__DOT__shift = __Vdly__ps2kbd__DOT__shift;
    vlSelfRef.ps2kbd__DOT__serin = vlSelfRef.ps2kbd__DOT__ps2_data;
    vlSelfRef.ps2kbd__DOT__stable = ((6U & ((IData)(vlSelfRef.ps2kbd__DOT__stable) 
                                            << 1U)) 
                                     | (IData)(vlSelfRef.ps2kbd__DOT__ps2_clk));
    if ((7U == (IData)(vlSelfRef.ps2kbd__DOT__stable))) {
        vlSelfRef.ps2kbd__DOT__bitclk = 1U;
    }
    if ((1U & (~ (0U != (IData)(vlSelfRef.ps2kbd__DOT__stable))))) {
        vlSelfRef.ps2kbd__DOT__bitclk = 0U;
    }
    if ((0U == vlSelfRef.ps2kbd__DOT__ps2_core__DOT__state)) {
        vlSelfRef.ps2kbd__DOT__ps2_data = 1U;
        __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd = 0U;
        __Vdly__ps2kbd__DOT__ps2_core__DOT__index = 0U;
        vlSelfRef.ps2kbd__DOT__ps2_clk = 1U;
        if (vlSelfRef.ps2kbd__DOT__uart_finish) {
            __Vdly__ps2kbd__DOT__ps2_core__DOT__state = 1U;
            __Vdly__ps2kbd__DOT__ps2_core__DOT__data_latch 
                = ((0x100U & ((~ VL_REDXOR_8(vlSelfRef.ps2kbd__DOT__uart_data)) 
                              << 8U)) | (IData)(vlSelfRef.ps2kbd__DOT__uart_data));
        }
    } else if ((1U == vlSelfRef.ps2kbd__DOT__ps2_core__DOT__state)) {
        vlSelfRef.ps2kbd__DOT__ps2_data = 0U;
        if ((0x1f4U == (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd))) {
            __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd 
                = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd)));
            vlSelfRef.ps2kbd__DOT__ps2_clk = 0U;
        }
        if ((0x3e7U > (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd))) {
            __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd 
                = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd)));
        } else {
            __Vdly__ps2kbd__DOT__ps2_core__DOT__state = 2U;
            __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd = 0U;
            vlSelfRef.ps2kbd__DOT__ps2_clk = 1U;
        }
    } else if ((2U == vlSelfRef.ps2kbd__DOT__ps2_core__DOT__state)) {
        vlSelfRef.ps2kbd__DOT__ps2_data = ((8U >= (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__index)) 
                                           && (1U & 
                                               ((IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__data_latch) 
                                                >> (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__index))));
        if ((0x1f4U == (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd))) {
            __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd 
                = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd)));
            vlSelfRef.ps2kbd__DOT__ps2_clk = 0U;
        }
        if ((0x3e7U > (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd))) {
            __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd 
                = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd)));
        } else {
            __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd = 0U;
            vlSelfRef.ps2kbd__DOT__ps2_clk = 1U;
            if ((8U > (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__index))) {
                __Vdly__ps2kbd__DOT__ps2_core__DOT__index 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__index)));
            } else {
                __Vdly__ps2kbd__DOT__ps2_core__DOT__index = 0U;
                __Vdly__ps2kbd__DOT__ps2_core__DOT__state = 3U;
            }
        }
    } else if ((3U == vlSelfRef.ps2kbd__DOT__ps2_core__DOT__state)) {
        vlSelfRef.ps2kbd__DOT__ps2_data = 1U;
        if ((0x1f4U == (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd))) {
            __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd 
                = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd)));
            vlSelfRef.ps2kbd__DOT__ps2_clk = 0U;
        }
        if ((0x3e7U > (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd))) {
            __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd 
                = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd)));
        } else {
            __Vdly__ps2kbd__DOT__ps2_core__DOT__state = 0U;
            __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd = 0U;
            vlSelfRef.ps2kbd__DOT__ps2_clk = 1U;
        }
    }
    vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd = __Vdly__ps2kbd__DOT__ps2_core__DOT__clkd;
    vlSelfRef.ps2kbd__DOT__ps2_core__DOT__index = __Vdly__ps2kbd__DOT__ps2_core__DOT__index;
    vlSelfRef.ps2kbd__DOT__ps2_core__DOT__state = __Vdly__ps2kbd__DOT__ps2_core__DOT__state;
    vlSelfRef.ps2kbd__DOT__ps2_core__DOT__data_latch 
        = __Vdly__ps2kbd__DOT__ps2_core__DOT__data_latch;
}

void Vps2___024root___timing_resume(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___timing_resume\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vps2___024root___eval_triggers__act(Vps2___024root* vlSelf);

bool Vps2___024root___eval_phase__act(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_phase__act\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vps2___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vps2___024root___timing_resume(vlSelf);
        Vps2___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vps2___024root___eval_phase__nba(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_phase__nba\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vps2___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2___024root___dump_triggers__nba(Vps2___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2___024root___dump_triggers__act(Vps2___024root* vlSelf);
#endif  // VL_DEBUG

void Vps2___024root___eval(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vps2___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/ps2kbd.v", 6, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vps2___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/ps2kbd.v", 6, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vps2___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vps2___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vps2___024root___eval_debug_assertions(Vps2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root___eval_debug_assertions\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vps2__Syms.h"


void Vps2___024root__trace_chg_0_sub_0(Vps2___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vps2___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root__trace_chg_0\n"); );
    // Init
    Vps2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vps2___024root*>(voidSelf);
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vps2___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vps2___024root__trace_chg_0_sub_0(Vps2___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root__trace_chg_0_sub_0\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.ps2kbd__DOT__ps2_clk));
        bufp->chgSData(oldp+1,(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__data_latch),9);
        bufp->chgSData(oldp+2,(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd),16);
        bufp->chgCData(oldp+3,(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__index),4);
        bufp->chgIData(oldp+4,(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__state),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+5,(vlSelfRef.ps2kbd__DOT__ps2_data));
        bufp->chgBit(oldp+6,(vlSelfRef.ps2kbd__DOT__serin));
        bufp->chgBit(oldp+7,(vlSelfRef.ps2kbd__DOT__bitclk));
        bufp->chgCData(oldp+8,(vlSelfRef.ps2kbd__DOT__stable),3);
        bufp->chgBit(oldp+9,(((~ (0U != (3U & (IData)(vlSelfRef.ps2kbd__DOT__stable)))) 
                              & (IData)(vlSelfRef.ps2kbd__DOT__bitclk))));
        bufp->chgSData(oldp+10,(vlSelfRef.ps2kbd__DOT__shift),9);
        bufp->chgCData(oldp+11,(vlSelfRef.ps2kbd__DOT__bitcnt),4);
        bufp->chgBit(oldp+12,(vlSelfRef.ps2kbd__DOT__parity));
    }
    bufp->chgCData(oldp+13,(vlSelfRef.ps2_code),8);
    bufp->chgBit(oldp+14,(vlSelfRef.strobe));
    bufp->chgBit(oldp+15,(vlSelfRef.err));
    bufp->chgBit(oldp+16,(vlSelfRef.ps2kbd__DOT__clk));
    bufp->chgCData(oldp+17,(vlSelfRef.ps2kbd__DOT__uart_data),8);
    bufp->chgBit(oldp+18,(vlSelfRef.ps2kbd__DOT__uart_finish));
}

void Vps2___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root__trace_cleanup\n"); );
    // Init
    Vps2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vps2___024root*>(voidSelf);
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vps2__Syms.h"


VL_ATTR_COLD void Vps2___024root__trace_init_sub__TOP__0(Vps2___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root__trace_init_sub__TOP__0\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+14,0,"ps2_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+15,0,"strobe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("ps2kbd", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+14,0,"ps2_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+15,0,"strobe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"uart_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+19,0,"uart_finish",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"ps2_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"ps2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"serin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"bitclk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"stable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+10,0,"bitedge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+12,0,"bitcnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+13,0,"parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ps2_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+17,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+19,0,"rts",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"ps2_clk",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"ps2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"CLK_DIVISOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"data_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+3,0,"clkd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vps2___024root__trace_init_top(Vps2___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root__trace_init_top\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vps2___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vps2___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vps2___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vps2___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vps2___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vps2___024root__trace_register(Vps2___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root__trace_register\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vps2___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vps2___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vps2___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vps2___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vps2___024root__trace_const_0_sub_0(Vps2___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vps2___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root__trace_const_0\n"); );
    // Init
    Vps2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vps2___024root*>(voidSelf);
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vps2___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vps2___024root__trace_const_0_sub_0(Vps2___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root__trace_const_0_sub_0\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+20,(2U),32);
    bufp->fullIData(oldp+21,(0x3e8U),32);
}

VL_ATTR_COLD void Vps2___024root__trace_full_0_sub_0(Vps2___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vps2___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root__trace_full_0\n"); );
    // Init
    Vps2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vps2___024root*>(voidSelf);
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vps2___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vps2___024root__trace_full_0_sub_0(Vps2___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2___024root__trace_full_0_sub_0\n"); );
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.ps2kbd__DOT__ps2_clk));
    bufp->fullSData(oldp+2,(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__data_latch),9);
    bufp->fullSData(oldp+3,(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__clkd),16);
    bufp->fullCData(oldp+4,(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__index),4);
    bufp->fullIData(oldp+5,(vlSelfRef.ps2kbd__DOT__ps2_core__DOT__state),32);
    bufp->fullBit(oldp+6,(vlSelfRef.ps2kbd__DOT__ps2_data));
    bufp->fullBit(oldp+7,(vlSelfRef.ps2kbd__DOT__serin));
    bufp->fullBit(oldp+8,(vlSelfRef.ps2kbd__DOT__bitclk));
    bufp->fullCData(oldp+9,(vlSelfRef.ps2kbd__DOT__stable),3);
    bufp->fullBit(oldp+10,(((~ (0U != (3U & (IData)(vlSelfRef.ps2kbd__DOT__stable)))) 
                            & (IData)(vlSelfRef.ps2kbd__DOT__bitclk))));
    bufp->fullSData(oldp+11,(vlSelfRef.ps2kbd__DOT__shift),9);
    bufp->fullCData(oldp+12,(vlSelfRef.ps2kbd__DOT__bitcnt),4);
    bufp->fullBit(oldp+13,(vlSelfRef.ps2kbd__DOT__parity));
    bufp->fullCData(oldp+14,(vlSelfRef.ps2_code),8);
    bufp->fullBit(oldp+15,(vlSelfRef.strobe));
    bufp->fullBit(oldp+16,(vlSelfRef.err));
    bufp->fullBit(oldp+17,(vlSelfRef.ps2kbd__DOT__clk));
    bufp->fullCData(oldp+18,(vlSelfRef.ps2kbd__DOT__uart_data),8);
    bufp->fullBit(oldp+19,(vlSelfRef.ps2kbd__DOT__uart_finish));
}

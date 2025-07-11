// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vps2.h for the primary calling header

#include "Vps2__pch.h"
#include "Vps2__Syms.h"
#include "Vps2___024root.h"

void Vps2___024root___ctor_var_reset(Vps2___024root* vlSelf);

Vps2___024root::Vps2___024root(Vps2__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vps2___024root___ctor_var_reset(this);
}

void Vps2___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vps2___024root::~Vps2___024root() {
}

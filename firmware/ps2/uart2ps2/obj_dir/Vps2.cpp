// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vps2__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vps2::Vps2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vps2__Syms(contextp(), _vcname__, this)}
    , ps2_code{vlSymsp->TOP.ps2_code}
    , strobe{vlSymsp->TOP.strobe}
    , err{vlSymsp->TOP.err}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vps2::Vps2(const char* _vcname__)
    : Vps2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vps2::~Vps2() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vps2___024root___eval_debug_assertions(Vps2___024root* vlSelf);
#endif  // VL_DEBUG
void Vps2___024root___eval_static(Vps2___024root* vlSelf);
void Vps2___024root___eval_initial(Vps2___024root* vlSelf);
void Vps2___024root___eval_settle(Vps2___024root* vlSelf);
void Vps2___024root___eval(Vps2___024root* vlSelf);

void Vps2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vps2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vps2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vps2___024root___eval_static(&(vlSymsp->TOP));
        Vps2___024root___eval_initial(&(vlSymsp->TOP));
        Vps2___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vps2___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vps2::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vps2::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vps2::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vps2::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vps2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vps2___024root___eval_final(Vps2___024root* vlSelf);

VL_ATTR_COLD void Vps2::final() {
    Vps2___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vps2::hierName() const { return vlSymsp->name(); }
const char* Vps2::modelName() const { return "Vps2"; }
unsigned Vps2::threads() const { return 1; }
void Vps2::prepareClone() const { contextp()->prepareClone(); }
void Vps2::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vps2::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vps2___024root__trace_decl_types(VerilatedVcd* tracep);

void Vps2___024root__trace_init_top(Vps2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vps2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vps2___024root*>(voidSelf);
    Vps2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vps2___024root__trace_decl_types(tracep);
    Vps2___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vps2___024root__trace_register(Vps2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vps2::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vps2::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vps2___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}

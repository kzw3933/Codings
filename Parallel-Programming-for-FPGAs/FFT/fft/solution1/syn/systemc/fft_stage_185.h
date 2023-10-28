// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2020.1
// Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _fft_stage_185_HH_
#define _fft_stage_185_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "sin_or_cos_double_s.h"
#include "fft_faddfsub_32nslbW.h"
#include "fft_fadd_32ns_32nmb6.h"
#include "fft_fmul_32ns_32nncg.h"
#include "fft_fptrunc_64ns_ocq.h"
#include "fft_fpext_32ns_64pcA.h"

namespace ap_rtl {

struct fft_stage_185 : public sc_module {
    // Port declarations 29
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_in< sc_logic > ap_continue;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<10> > X_R_8_address0;
    sc_out< sc_logic > X_R_8_ce0;
    sc_in< sc_lv<32> > X_R_8_q0;
    sc_out< sc_lv<10> > X_I_8_address0;
    sc_out< sc_logic > X_I_8_ce0;
    sc_in< sc_lv<32> > X_I_8_q0;
    sc_out< sc_lv<10> > Out_R_9_address0;
    sc_out< sc_logic > Out_R_9_ce0;
    sc_out< sc_logic > Out_R_9_we0;
    sc_out< sc_lv<32> > Out_R_9_d0;
    sc_out< sc_lv<10> > Out_R_9_address1;
    sc_out< sc_logic > Out_R_9_ce1;
    sc_out< sc_logic > Out_R_9_we1;
    sc_out< sc_lv<32> > Out_R_9_d1;
    sc_out< sc_lv<10> > Out_I_9_address0;
    sc_out< sc_logic > Out_I_9_ce0;
    sc_out< sc_logic > Out_I_9_we0;
    sc_out< sc_lv<32> > Out_I_9_d0;
    sc_out< sc_lv<10> > Out_I_9_address1;
    sc_out< sc_logic > Out_I_9_ce1;
    sc_out< sc_logic > Out_I_9_we1;
    sc_out< sc_lv<32> > Out_I_9_d1;
    sc_signal< sc_logic > ap_var_for_const0;


    // Module declarations
    fft_stage_185(sc_module_name name);
    SC_HAS_PROCESS(fft_stage_185);

    ~fft_stage_185();

    sc_trace_file* mVcdFile;

    sin_or_cos_double_s* grp_sin_or_cos_double_s_fu_189;
    sin_or_cos_double_s* grp_sin_or_cos_double_s_fu_208;
    fft_faddfsub_32nslbW<1,4,32,32,32>* fft_faddfsub_32nslbW_U146;
    fft_faddfsub_32nslbW<1,4,32,32,32>* fft_faddfsub_32nslbW_U147;
    fft_fadd_32ns_32nmb6<1,4,32,32,32>* fft_fadd_32ns_32nmb6_U148;
    fft_fadd_32ns_32nmb6<1,4,32,32,32>* fft_fadd_32ns_32nmb6_U149;
    fft_fmul_32ns_32nncg<1,3,32,32,32>* fft_fmul_32ns_32nncg_U150;
    fft_fmul_32ns_32nncg<1,3,32,32,32>* fft_fmul_32ns_32nncg_U151;
    fft_fmul_32ns_32nncg<1,3,32,32,32>* fft_fmul_32ns_32nncg_U152;
    fft_fptrunc_64ns_ocq<1,2,64,32>* fft_fptrunc_64ns_ocq_U153;
    fft_fptrunc_64ns_ocq<1,2,64,32>* fft_fptrunc_64ns_ocq_U154;
    fft_fpext_32ns_64pcA<1,2,32,64>* fft_fpext_32ns_64pcA_U155;
    sc_signal< sc_logic > ap_done_reg;
    sc_signal< sc_lv<21> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<32> > reg_267;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_lv<32> > reg_274;
    sc_signal< sc_lv<32> > grp_fu_227_p2;
    sc_signal< sc_lv<32> > reg_282;
    sc_signal< sc_logic > ap_CS_fsm_state20;
    sc_signal< sc_lv<32> > grp_fu_233_p2;
    sc_signal< sc_lv<32> > reg_289;
    sc_signal< sc_lv<32> > zext_ln39_fu_296_p1;
    sc_signal< sc_lv<32> > zext_ln39_reg_352;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<9> > j_fu_306_p2;
    sc_signal< sc_lv<9> > j_reg_360;
    sc_signal< sc_lv<64> > grp_fu_263_p1;
    sc_signal< sc_lv<64> > x_assign_reg_365;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<64> > grp_sin_or_cos_double_s_fu_189_ap_return;
    sc_signal< sc_lv<64> > tmp_i_i_reg_371;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_189_ap_ready;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_189_ap_done;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_208_ap_ready;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_208_ap_done;
    sc_signal< bool > ap_block_state5_on_subcall_done;
    sc_signal< sc_lv<64> > grp_sin_or_cos_double_s_fu_208_ap_return;
    sc_signal< sc_lv<64> > tmp_i_i1_reg_376;
    sc_signal< sc_lv<32> > a_reg_381;
    sc_signal< sc_lv<32> > grp_fu_257_p1;
    sc_signal< sc_lv<32> > c_reg_386;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<32> > grp_fu_260_p1;
    sc_signal< sc_lv<32> > s_reg_392;
    sc_signal< sc_lv<64> > sext_ln48_fu_334_p1;
    sc_signal< sc_lv<64> > sext_ln48_reg_400;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_lv<1> > icmp_ln46_fu_322_p2;
    sc_signal< sc_lv<32> > grp_fu_245_p2;
    sc_signal< sc_lv<32> > tmp_7_reg_416;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_lv<32> > grp_fu_249_p2;
    sc_signal< sc_lv<32> > tmp_8_reg_421;
    sc_signal< sc_lv<32> > grp_fu_253_p2;
    sc_signal< sc_lv<32> > tmp_9_reg_427;
    sc_signal< sc_lv<64> > sext_ln50_fu_340_p1;
    sc_signal< sc_lv<64> > sext_ln50_reg_432;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_lv<32> > i_4_fu_346_p2;
    sc_signal< sc_lv<32> > i_4_reg_448;
    sc_signal< sc_lv<32> > grp_fu_237_p2;
    sc_signal< sc_lv<32> > tmp_6_reg_453;
    sc_signal< sc_lv<32> > grp_fu_241_p2;
    sc_signal< sc_lv<32> > tmp_2_reg_458;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_189_ap_start;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_189_ap_idle;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_189_do_cos;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_208_ap_start;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_208_ap_idle;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_208_do_cos;
    sc_signal< sc_lv<32> > a_0_reg_156;
    sc_signal< bool > ap_block_state1;
    sc_signal< sc_lv<9> > i_reg_168;
    sc_signal< sc_lv<32> > i_0_reg_179;
    sc_signal< sc_logic > ap_CS_fsm_state21;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_189_ap_start_reg;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_logic > grp_sin_or_cos_double_s_fu_208_ap_start_reg;
    sc_signal< sc_lv<32> > grp_fu_227_p0;
    sc_signal< sc_lv<32> > grp_fu_227_p1;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_logic > ap_CS_fsm_state17;
    sc_signal< sc_lv<32> > grp_fu_233_p0;
    sc_signal< sc_lv<32> > grp_fu_233_p1;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<22> > tmp_12_fu_312_p4;
    sc_signal< sc_lv<32> > i_lower_fu_328_p2;
    sc_signal< sc_lv<2> > grp_fu_227_opcode;
    sc_signal< sc_lv<1> > icmp_ln39_fu_300_p2;
    sc_signal< sc_logic > grp_fu_227_ce;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_lv<2> > grp_fu_233_opcode;
    sc_signal< sc_lv<21> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<21> ap_ST_fsm_state1;
    static const sc_lv<21> ap_ST_fsm_state2;
    static const sc_lv<21> ap_ST_fsm_state3;
    static const sc_lv<21> ap_ST_fsm_state4;
    static const sc_lv<21> ap_ST_fsm_state5;
    static const sc_lv<21> ap_ST_fsm_state6;
    static const sc_lv<21> ap_ST_fsm_state7;
    static const sc_lv<21> ap_ST_fsm_state8;
    static const sc_lv<21> ap_ST_fsm_state9;
    static const sc_lv<21> ap_ST_fsm_state10;
    static const sc_lv<21> ap_ST_fsm_state11;
    static const sc_lv<21> ap_ST_fsm_state12;
    static const sc_lv<21> ap_ST_fsm_state13;
    static const sc_lv<21> ap_ST_fsm_state14;
    static const sc_lv<21> ap_ST_fsm_state15;
    static const sc_lv<21> ap_ST_fsm_state16;
    static const sc_lv<21> ap_ST_fsm_state17;
    static const sc_lv<21> ap_ST_fsm_state18;
    static const sc_lv<21> ap_ST_fsm_state19;
    static const sc_lv<21> ap_ST_fsm_state20;
    static const sc_lv<21> ap_ST_fsm_state21;
    static const sc_lv<32> ap_const_lv32_0;
    static const bool ap_const_boolean_1;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<32> ap_const_lv32_13;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_4;
    static const bool ap_const_boolean_0;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<9> ap_const_lv9_0;
    static const sc_lv<32> ap_const_lv32_14;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_BC490FDB;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<9> ap_const_lv9_100;
    static const sc_lv<9> ap_const_lv9_1;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<22> ap_const_lv22_1;
    static const sc_lv<32> ap_const_lv32_100;
    static const sc_lv<32> ap_const_lv32_200;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<2> ap_const_lv2_1;
    // Thread declarations
    void thread_ap_var_for_const0();
    void thread_ap_clk_no_reset_();
    void thread_Out_I_9_address0();
    void thread_Out_I_9_address1();
    void thread_Out_I_9_ce0();
    void thread_Out_I_9_ce1();
    void thread_Out_I_9_d0();
    void thread_Out_I_9_d1();
    void thread_Out_I_9_we0();
    void thread_Out_I_9_we1();
    void thread_Out_R_9_address0();
    void thread_Out_R_9_address1();
    void thread_Out_R_9_ce0();
    void thread_Out_R_9_ce1();
    void thread_Out_R_9_d0();
    void thread_Out_R_9_d1();
    void thread_Out_R_9_we0();
    void thread_Out_R_9_we1();
    void thread_X_I_8_address0();
    void thread_X_I_8_ce0();
    void thread_X_R_8_address0();
    void thread_X_R_8_ce0();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state15();
    void thread_ap_CS_fsm_state16();
    void thread_ap_CS_fsm_state17();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state20();
    void thread_ap_CS_fsm_state21();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_CS_fsm_state7();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state9();
    void thread_ap_block_state1();
    void thread_ap_block_state5_on_subcall_done();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_grp_fu_227_ce();
    void thread_grp_fu_227_opcode();
    void thread_grp_fu_227_p0();
    void thread_grp_fu_227_p1();
    void thread_grp_fu_233_opcode();
    void thread_grp_fu_233_p0();
    void thread_grp_fu_233_p1();
    void thread_grp_sin_or_cos_double_s_fu_189_ap_start();
    void thread_grp_sin_or_cos_double_s_fu_189_do_cos();
    void thread_grp_sin_or_cos_double_s_fu_208_ap_start();
    void thread_grp_sin_or_cos_double_s_fu_208_do_cos();
    void thread_i_4_fu_346_p2();
    void thread_i_lower_fu_328_p2();
    void thread_icmp_ln39_fu_300_p2();
    void thread_icmp_ln46_fu_322_p2();
    void thread_j_fu_306_p2();
    void thread_sext_ln48_fu_334_p1();
    void thread_sext_ln50_fu_340_p1();
    void thread_tmp_12_fu_312_p4();
    void thread_zext_ln39_fu_296_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif

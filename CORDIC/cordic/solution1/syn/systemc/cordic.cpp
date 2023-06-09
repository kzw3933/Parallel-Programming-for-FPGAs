// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2020.1
// Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "cordic.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic cordic::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic cordic::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<3> cordic::ap_ST_fsm_state1 = "1";
const sc_lv<3> cordic::ap_ST_fsm_state2 = "10";
const sc_lv<3> cordic::ap_ST_fsm_state3 = "100";
const sc_lv<32> cordic::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> cordic::ap_const_lv32_1 = "1";
const sc_lv<1> cordic::ap_const_lv1_0 = "0";
const sc_lv<32> cordic::ap_const_lv32_2 = "10";
const sc_lv<11> cordic::ap_const_lv11_200 = "1000000000";
const sc_lv<12> cordic::ap_const_lv12_0 = "000000000000";
const sc_lv<12> cordic::ap_const_lv12_136 = "100110110";
const sc_lv<5> cordic::ap_const_lv5_0 = "00000";
const sc_lv<1> cordic::ap_const_lv1_1 = "1";
const sc_lv<5> cordic::ap_const_lv5_10 = "10000";
const sc_lv<5> cordic::ap_const_lv5_1 = "1";
const sc_lv<32> cordic::ap_const_lv32_B = "1011";
const sc_lv<13> cordic::ap_const_lv13_0 = "0000000000000";
const sc_lv<9> cordic::ap_const_lv9_0 = "000000000";
const sc_lv<32> cordic::ap_const_lv32_9 = "1001";
const sc_lv<32> cordic::ap_const_lv32_14 = "10100";
const sc_lv<32> cordic::ap_const_lv32_A = "1010";
const sc_lv<11> cordic::ap_const_lv11_0 = "00000000000";
const bool cordic::ap_const_boolean_1 = true;

cordic::cordic(sc_module_name name) : sc_module(name), mVcdFile(0) {
    cordic_phase_V_U = new cordic_cordic_phabkb("cordic_phase_V_U");
    cordic_phase_V_U->clk(ap_clk);
    cordic_phase_V_U->reset(ap_rst);
    cordic_phase_V_U->address0(cordic_phase_V_address0);
    cordic_phase_V_U->ce0(cordic_phase_V_ce0);
    cordic_phase_V_U->q0(cordic_phase_V_q0);
    cordic_mac_mulsubcud_U1 = new cordic_mac_mulsubcud<1,1,11,13,21,21>("cordic_mac_mulsubcud_U1");
    cordic_mac_mulsubcud_U1->din0(grp_fu_293_p0);
    cordic_mac_mulsubcud_U1->din1(r_V_fu_179_p3);
    cordic_mac_mulsubcud_U1->din2(grp_fu_293_p2);
    cordic_mac_mulsubcud_U1->dout(grp_fu_293_p3);
    cordic_mac_muladddEe_U2 = new cordic_mac_muladddEe<1,1,11,13,21,21>("cordic_mac_muladddEe_U2");
    cordic_mac_muladddEe_U2->din0(grp_fu_302_p0);
    cordic_mac_muladddEe_U2->din1(r_V_1_fu_222_p3);
    cordic_mac_muladddEe_U2->din2(grp_fu_302_p2);
    cordic_mac_muladddEe_U2->dout(grp_fu_302_p3);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state3);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );

    SC_METHOD(thread_c_V);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );
    sensitive << ( temp_cos_V_reg_126 );

    SC_METHOD(thread_c_V_ap_vld);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );

    SC_METHOD(thread_cordic_phase_V_address0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( zext_ln26_fu_251_p1 );

    SC_METHOD(thread_cordic_phase_V_ce0);
    sensitive << ( ap_CS_fsm_state2 );

    SC_METHOD(thread_grp_fu_293_p0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );
    sensitive << ( sext_ln1118_1_fu_191_p1 );

    SC_METHOD(thread_grp_fu_293_p2);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );
    sensitive << ( temp_cos_V_reg_126 );

    SC_METHOD(thread_grp_fu_302_p0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );
    sensitive << ( sext_ln1118_1_fu_191_p1 );

    SC_METHOD(thread_grp_fu_302_p2);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );
    sensitive << ( p_Val2_2_reg_114 );

    SC_METHOD(thread_icmp_ln17_fu_149_p2);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( j_0_reg_138 );

    SC_METHOD(thread_j_fu_155_p2);
    sensitive << ( j_0_reg_138 );

    SC_METHOD(thread_r_V_1_fu_222_p3);
    sensitive << ( tmp_fu_161_p3 );
    sensitive << ( sext_ln1116_1_fu_212_p1 );
    sensitive << ( sub_ln1118_1_fu_216_p2 );

    SC_METHOD(thread_r_V_fu_179_p3);
    sensitive << ( tmp_fu_161_p3 );
    sensitive << ( sext_ln1116_fu_169_p1 );
    sensitive << ( sub_ln1118_fu_173_p2 );

    SC_METHOD(thread_s_V);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );
    sensitive << ( p_Val2_2_reg_114 );

    SC_METHOD(thread_s_V_ap_vld);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );

    SC_METHOD(thread_select_ln703_fu_276_p3);
    sensitive << ( cordic_phase_V_q0 );
    sensitive << ( tmp_reg_324 );
    sensitive << ( sub_ln703_1_fu_270_p2 );

    SC_METHOD(thread_sext_ln1116_1_fu_212_p1);
    sensitive << ( temp_cos_V_reg_126 );

    SC_METHOD(thread_sext_ln1116_fu_169_p1);
    sensitive << ( p_Val2_2_reg_114 );

    SC_METHOD(thread_sext_ln1118_1_fu_191_p1);
    sensitive << ( factor_0_reg_103 );

    SC_METHOD(thread_sext_ln1333_fu_266_p1);
    sensitive << ( trunc_ln_fu_256_p4 );

    SC_METHOD(thread_sext_ln703_fu_283_p1);
    sensitive << ( select_ln703_fu_276_p3 );

    SC_METHOD(thread_sub_ln1118_1_fu_216_p2);
    sensitive << ( sext_ln1116_1_fu_212_p1 );

    SC_METHOD(thread_sub_ln1118_fu_173_p2);
    sensitive << ( sext_ln1116_fu_169_p1 );

    SC_METHOD(thread_sub_ln703_1_fu_270_p2);
    sensitive << ( cordic_phase_V_q0 );

    SC_METHOD(thread_sub_ln703_fu_287_p2);
    sensitive << ( p_Val2_4_reg_93 );
    sensitive << ( sext_ln703_fu_283_p1 );

    SC_METHOD(thread_tmp_fu_161_p3);
    sensitive << ( p_Val2_4_reg_93 );

    SC_METHOD(thread_trunc_ln_fu_256_p4);
    sensitive << ( factor_0_reg_103 );

    SC_METHOD(thread_zext_ln26_fu_251_p1);
    sensitive << ( j_0_reg_138 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln17_fu_149_p2 );

    SC_THREAD(thread_hdltv_gen);
    sensitive << ( ap_clk.pos() );

    ap_CS_fsm = "001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "cordic_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, theta_V, "(port)theta_V");
    sc_trace(mVcdFile, s_V, "(port)s_V");
    sc_trace(mVcdFile, s_V_ap_vld, "(port)s_V_ap_vld");
    sc_trace(mVcdFile, c_V, "(port)c_V");
    sc_trace(mVcdFile, c_V_ap_vld, "(port)c_V_ap_vld");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, cordic_phase_V_address0, "cordic_phase_V_address0");
    sc_trace(mVcdFile, cordic_phase_V_ce0, "cordic_phase_V_ce0");
    sc_trace(mVcdFile, cordic_phase_V_q0, "cordic_phase_V_q0");
    sc_trace(mVcdFile, j_fu_155_p2, "j_fu_155_p2");
    sc_trace(mVcdFile, j_reg_319, "j_reg_319");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, tmp_fu_161_p3, "tmp_fu_161_p3");
    sc_trace(mVcdFile, tmp_reg_324, "tmp_reg_324");
    sc_trace(mVcdFile, icmp_ln17_fu_149_p2, "icmp_ln17_fu_149_p2");
    sc_trace(mVcdFile, current_cos_V_reg_329, "current_cos_V_reg_329");
    sc_trace(mVcdFile, current_sin_V_reg_334, "current_sin_V_reg_334");
    sc_trace(mVcdFile, sext_ln1333_fu_266_p1, "sext_ln1333_fu_266_p1");
    sc_trace(mVcdFile, sext_ln1333_reg_344, "sext_ln1333_reg_344");
    sc_trace(mVcdFile, sub_ln703_fu_287_p2, "sub_ln703_fu_287_p2");
    sc_trace(mVcdFile, ap_CS_fsm_state3, "ap_CS_fsm_state3");
    sc_trace(mVcdFile, p_Val2_4_reg_93, "p_Val2_4_reg_93");
    sc_trace(mVcdFile, factor_0_reg_103, "factor_0_reg_103");
    sc_trace(mVcdFile, p_Val2_2_reg_114, "p_Val2_2_reg_114");
    sc_trace(mVcdFile, temp_cos_V_reg_126, "temp_cos_V_reg_126");
    sc_trace(mVcdFile, j_0_reg_138, "j_0_reg_138");
    sc_trace(mVcdFile, zext_ln26_fu_251_p1, "zext_ln26_fu_251_p1");
    sc_trace(mVcdFile, sext_ln1116_fu_169_p1, "sext_ln1116_fu_169_p1");
    sc_trace(mVcdFile, sub_ln1118_fu_173_p2, "sub_ln1118_fu_173_p2");
    sc_trace(mVcdFile, r_V_fu_179_p3, "r_V_fu_179_p3");
    sc_trace(mVcdFile, grp_fu_293_p3, "grp_fu_293_p3");
    sc_trace(mVcdFile, sext_ln1116_1_fu_212_p1, "sext_ln1116_1_fu_212_p1");
    sc_trace(mVcdFile, sub_ln1118_1_fu_216_p2, "sub_ln1118_1_fu_216_p2");
    sc_trace(mVcdFile, r_V_1_fu_222_p3, "r_V_1_fu_222_p3");
    sc_trace(mVcdFile, grp_fu_302_p3, "grp_fu_302_p3");
    sc_trace(mVcdFile, trunc_ln_fu_256_p4, "trunc_ln_fu_256_p4");
    sc_trace(mVcdFile, sub_ln703_1_fu_270_p2, "sub_ln703_1_fu_270_p2");
    sc_trace(mVcdFile, select_ln703_fu_276_p3, "select_ln703_fu_276_p3");
    sc_trace(mVcdFile, sext_ln703_fu_283_p1, "sext_ln703_fu_283_p1");
    sc_trace(mVcdFile, grp_fu_293_p0, "grp_fu_293_p0");
    sc_trace(mVcdFile, sext_ln1118_1_fu_191_p1, "sext_ln1118_1_fu_191_p1");
    sc_trace(mVcdFile, grp_fu_293_p2, "grp_fu_293_p2");
    sc_trace(mVcdFile, grp_fu_302_p0, "grp_fu_302_p0");
    sc_trace(mVcdFile, grp_fu_302_p2, "grp_fu_302_p2");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
    mHdltvinHandle.open("cordic.hdltvin.dat");
    mHdltvoutHandle.open("cordic.hdltvout.dat");
}

cordic::~cordic() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    mHdltvinHandle << "] " << endl;
    mHdltvoutHandle << "] " << endl;
    mHdltvinHandle.close();
    mHdltvoutHandle.close();
    delete cordic_phase_V_U;
    delete cordic_mac_mulsubcud_U1;
    delete cordic_mac_muladddEe_U2;
}

void cordic::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        factor_0_reg_103 = sext_ln1333_reg_344.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        factor_0_reg_103 = ap_const_lv11_200;
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        j_0_reg_138 = j_reg_319.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        j_0_reg_138 = ap_const_lv5_0;
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        p_Val2_2_reg_114 = current_sin_V_reg_334.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        p_Val2_2_reg_114 = ap_const_lv12_0;
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        p_Val2_4_reg_93 = sub_ln703_fu_287_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        p_Val2_4_reg_93 = theta_V.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        temp_cos_V_reg_126 = current_cos_V_reg_329.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        temp_cos_V_reg_126 = ap_const_lv12_136;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln17_fu_149_p2.read(), ap_const_lv1_0))) {
        current_cos_V_reg_329 = grp_fu_293_p3.read().range(20, 9);
        current_sin_V_reg_334 = grp_fu_302_p3.read().range(20, 9);
        sext_ln1333_reg_344 = sext_ln1333_fu_266_p1.read();
        tmp_reg_324 = p_Val2_4_reg_93.read().range(11, 11);
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        j_reg_319 = j_fu_155_p2.read();
    }
}

void cordic::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void cordic::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void cordic::thread_ap_CS_fsm_state3() {
    ap_CS_fsm_state3 = ap_CS_fsm.read()[2];
}

void cordic::thread_ap_done() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln17_fu_149_p2.read(), ap_const_lv1_1))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void cordic::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void cordic::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln17_fu_149_p2.read(), ap_const_lv1_1))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void cordic::thread_c_V() {
    c_V = temp_cos_V_reg_126.read();
}

void cordic::thread_c_V_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln17_fu_149_p2.read(), ap_const_lv1_1))) {
        c_V_ap_vld = ap_const_logic_1;
    } else {
        c_V_ap_vld = ap_const_logic_0;
    }
}

void cordic::thread_cordic_phase_V_address0() {
    cordic_phase_V_address0 =  (sc_lv<4>) (zext_ln26_fu_251_p1.read());
}

void cordic::thread_cordic_phase_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        cordic_phase_V_ce0 = ap_const_logic_1;
    } else {
        cordic_phase_V_ce0 = ap_const_logic_0;
    }
}

void cordic::thread_grp_fu_293_p0() {
    grp_fu_293_p0 =  (sc_lv<11>) (sext_ln1118_1_fu_191_p1.read());
}

void cordic::thread_grp_fu_293_p2() {
    grp_fu_293_p2 = esl_concat<12,9>(temp_cos_V_reg_126.read(), ap_const_lv9_0);
}

void cordic::thread_grp_fu_302_p0() {
    grp_fu_302_p0 =  (sc_lv<11>) (sext_ln1118_1_fu_191_p1.read());
}

void cordic::thread_grp_fu_302_p2() {
    grp_fu_302_p2 = esl_concat<12,9>(p_Val2_2_reg_114.read(), ap_const_lv9_0);
}

void cordic::thread_icmp_ln17_fu_149_p2() {
    icmp_ln17_fu_149_p2 = (!j_0_reg_138.read().is_01() || !ap_const_lv5_10.is_01())? sc_lv<1>(): sc_lv<1>(j_0_reg_138.read() == ap_const_lv5_10);
}

void cordic::thread_j_fu_155_p2() {
    j_fu_155_p2 = (!j_0_reg_138.read().is_01() || !ap_const_lv5_1.is_01())? sc_lv<5>(): (sc_biguint<5>(j_0_reg_138.read()) + sc_biguint<5>(ap_const_lv5_1));
}

void cordic::thread_r_V_1_fu_222_p3() {
    r_V_1_fu_222_p3 = (!tmp_fu_161_p3.read()[0].is_01())? sc_lv<13>(): ((tmp_fu_161_p3.read()[0].to_bool())? sub_ln1118_1_fu_216_p2.read(): sext_ln1116_1_fu_212_p1.read());
}

void cordic::thread_r_V_fu_179_p3() {
    r_V_fu_179_p3 = (!tmp_fu_161_p3.read()[0].is_01())? sc_lv<13>(): ((tmp_fu_161_p3.read()[0].to_bool())? sub_ln1118_fu_173_p2.read(): sext_ln1116_fu_169_p1.read());
}

void cordic::thread_s_V() {
    s_V = p_Val2_2_reg_114.read();
}

void cordic::thread_s_V_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln17_fu_149_p2.read(), ap_const_lv1_1))) {
        s_V_ap_vld = ap_const_logic_1;
    } else {
        s_V_ap_vld = ap_const_logic_0;
    }
}

void cordic::thread_select_ln703_fu_276_p3() {
    select_ln703_fu_276_p3 = (!tmp_reg_324.read()[0].is_01())? sc_lv<11>(): ((tmp_reg_324.read()[0].to_bool())? sub_ln703_1_fu_270_p2.read(): cordic_phase_V_q0.read());
}

void cordic::thread_sext_ln1116_1_fu_212_p1() {
    sext_ln1116_1_fu_212_p1 = esl_sext<13,12>(temp_cos_V_reg_126.read());
}

void cordic::thread_sext_ln1116_fu_169_p1() {
    sext_ln1116_fu_169_p1 = esl_sext<13,12>(p_Val2_2_reg_114.read());
}

void cordic::thread_sext_ln1118_1_fu_191_p1() {
    sext_ln1118_1_fu_191_p1 = esl_sext<21,11>(factor_0_reg_103.read());
}

void cordic::thread_sext_ln1333_fu_266_p1() {
    sext_ln1333_fu_266_p1 = esl_sext<11,10>(trunc_ln_fu_256_p4.read());
}

void cordic::thread_sext_ln703_fu_283_p1() {
    sext_ln703_fu_283_p1 = esl_sext<12,11>(select_ln703_fu_276_p3.read());
}

void cordic::thread_sub_ln1118_1_fu_216_p2() {
    sub_ln1118_1_fu_216_p2 = (!ap_const_lv13_0.is_01() || !sext_ln1116_1_fu_212_p1.read().is_01())? sc_lv<13>(): (sc_biguint<13>(ap_const_lv13_0) - sc_bigint<13>(sext_ln1116_1_fu_212_p1.read()));
}

void cordic::thread_sub_ln1118_fu_173_p2() {
    sub_ln1118_fu_173_p2 = (!ap_const_lv13_0.is_01() || !sext_ln1116_fu_169_p1.read().is_01())? sc_lv<13>(): (sc_biguint<13>(ap_const_lv13_0) - sc_bigint<13>(sext_ln1116_fu_169_p1.read()));
}

void cordic::thread_sub_ln703_1_fu_270_p2() {
    sub_ln703_1_fu_270_p2 = (!ap_const_lv11_0.is_01() || !cordic_phase_V_q0.read().is_01())? sc_lv<11>(): (sc_biguint<11>(ap_const_lv11_0) - sc_biguint<11>(cordic_phase_V_q0.read()));
}

void cordic::thread_sub_ln703_fu_287_p2() {
    sub_ln703_fu_287_p2 = (!p_Val2_4_reg_93.read().is_01() || !sext_ln703_fu_283_p1.read().is_01())? sc_lv<12>(): (sc_biguint<12>(p_Val2_4_reg_93.read()) - sc_bigint<12>(sext_ln703_fu_283_p1.read()));
}

void cordic::thread_tmp_fu_161_p3() {
    tmp_fu_161_p3 = p_Val2_4_reg_93.read().range(11, 11);
}

void cordic::thread_trunc_ln_fu_256_p4() {
    trunc_ln_fu_256_p4 = factor_0_reg_103.read().range(10, 1);
}

void cordic::thread_zext_ln26_fu_251_p1() {
    zext_ln26_fu_251_p1 = esl_zext<64,5>(j_0_reg_138.read());
}

void cordic::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln17_fu_149_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state3;
            }
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_fsm_state2;
            break;
        default : 
            ap_NS_fsm = "XXX";
            break;
    }
}

void cordic::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst\" :  \"" << ap_rst.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"ap_start\" :  \"" << ap_start.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"ap_done\" :  \"" << ap_done.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_idle\" :  \"" << ap_idle.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_ready\" :  \"" << ap_ready.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"theta_V\" :  \"" << theta_V.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"s_V\" :  \"" << s_V.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"s_V_ap_vld\" :  \"" << s_V_ap_vld.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c_V\" :  \"" << c_V.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c_V_ap_vld\" :  \"" << c_V_ap_vld.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}


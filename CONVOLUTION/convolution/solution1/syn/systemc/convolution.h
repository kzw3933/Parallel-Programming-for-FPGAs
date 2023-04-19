// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2020.1
// Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _convolution_HH_
#define _convolution_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "Process_r.h"
#include "Offload_Out.h"
#include "convolution_Out_0_0.h"
#include "convolution_W_ddr_m_axi.h"
#include "convolution_Out_ddr_m_axi.h"

namespace ap_rtl {

template<unsigned int C_M_AXI_IN_DDR_ADDR_WIDTH = 32,
         unsigned int C_M_AXI_IN_DDR_ID_WIDTH = 1,
         unsigned int C_M_AXI_IN_DDR_AWUSER_WIDTH = 1,
         unsigned int C_M_AXI_IN_DDR_DATA_WIDTH = 32,
         unsigned int C_M_AXI_IN_DDR_WUSER_WIDTH = 1,
         unsigned int C_M_AXI_IN_DDR_ARUSER_WIDTH = 1,
         unsigned int C_M_AXI_IN_DDR_RUSER_WIDTH = 1,
         unsigned int C_M_AXI_IN_DDR_BUSER_WIDTH = 1,
         unsigned int C_M_AXI_W_DDR_ADDR_WIDTH = 32,
         unsigned int C_M_AXI_W_DDR_ID_WIDTH = 1,
         unsigned int C_M_AXI_W_DDR_AWUSER_WIDTH = 1,
         unsigned int C_M_AXI_W_DDR_DATA_WIDTH = 32,
         unsigned int C_M_AXI_W_DDR_WUSER_WIDTH = 1,
         unsigned int C_M_AXI_W_DDR_ARUSER_WIDTH = 1,
         unsigned int C_M_AXI_W_DDR_RUSER_WIDTH = 1,
         unsigned int C_M_AXI_W_DDR_BUSER_WIDTH = 1,
         unsigned int C_M_AXI_OUT_DDR_ADDR_WIDTH = 32,
         unsigned int C_M_AXI_OUT_DDR_ID_WIDTH = 1,
         unsigned int C_M_AXI_OUT_DDR_AWUSER_WIDTH = 1,
         unsigned int C_M_AXI_OUT_DDR_DATA_WIDTH = 32,
         unsigned int C_M_AXI_OUT_DDR_WUSER_WIDTH = 1,
         unsigned int C_M_AXI_OUT_DDR_ARUSER_WIDTH = 1,
         unsigned int C_M_AXI_OUT_DDR_RUSER_WIDTH = 1,
         unsigned int C_M_AXI_OUT_DDR_BUSER_WIDTH = 1>
struct convolution : public sc_module {
    // Port declarations 141
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst_n;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_logic > m_axi_In_ddr_AWVALID;
    sc_in< sc_logic > m_axi_In_ddr_AWREADY;
    sc_out< sc_uint<C_M_AXI_IN_DDR_ADDR_WIDTH> > m_axi_In_ddr_AWADDR;
    sc_out< sc_uint<C_M_AXI_IN_DDR_ID_WIDTH> > m_axi_In_ddr_AWID;
    sc_out< sc_lv<8> > m_axi_In_ddr_AWLEN;
    sc_out< sc_lv<3> > m_axi_In_ddr_AWSIZE;
    sc_out< sc_lv<2> > m_axi_In_ddr_AWBURST;
    sc_out< sc_lv<2> > m_axi_In_ddr_AWLOCK;
    sc_out< sc_lv<4> > m_axi_In_ddr_AWCACHE;
    sc_out< sc_lv<3> > m_axi_In_ddr_AWPROT;
    sc_out< sc_lv<4> > m_axi_In_ddr_AWQOS;
    sc_out< sc_lv<4> > m_axi_In_ddr_AWREGION;
    sc_out< sc_uint<C_M_AXI_IN_DDR_AWUSER_WIDTH> > m_axi_In_ddr_AWUSER;
    sc_out< sc_logic > m_axi_In_ddr_WVALID;
    sc_in< sc_logic > m_axi_In_ddr_WREADY;
    sc_out< sc_uint<C_M_AXI_IN_DDR_DATA_WIDTH> > m_axi_In_ddr_WDATA;
    sc_out< sc_uint<C_M_AXI_IN_DDR_DATA_WIDTH/8> > m_axi_In_ddr_WSTRB;
    sc_out< sc_logic > m_axi_In_ddr_WLAST;
    sc_out< sc_uint<C_M_AXI_IN_DDR_ID_WIDTH> > m_axi_In_ddr_WID;
    sc_out< sc_uint<C_M_AXI_IN_DDR_WUSER_WIDTH> > m_axi_In_ddr_WUSER;
    sc_out< sc_logic > m_axi_In_ddr_ARVALID;
    sc_in< sc_logic > m_axi_In_ddr_ARREADY;
    sc_out< sc_uint<C_M_AXI_IN_DDR_ADDR_WIDTH> > m_axi_In_ddr_ARADDR;
    sc_out< sc_uint<C_M_AXI_IN_DDR_ID_WIDTH> > m_axi_In_ddr_ARID;
    sc_out< sc_lv<8> > m_axi_In_ddr_ARLEN;
    sc_out< sc_lv<3> > m_axi_In_ddr_ARSIZE;
    sc_out< sc_lv<2> > m_axi_In_ddr_ARBURST;
    sc_out< sc_lv<2> > m_axi_In_ddr_ARLOCK;
    sc_out< sc_lv<4> > m_axi_In_ddr_ARCACHE;
    sc_out< sc_lv<3> > m_axi_In_ddr_ARPROT;
    sc_out< sc_lv<4> > m_axi_In_ddr_ARQOS;
    sc_out< sc_lv<4> > m_axi_In_ddr_ARREGION;
    sc_out< sc_uint<C_M_AXI_IN_DDR_ARUSER_WIDTH> > m_axi_In_ddr_ARUSER;
    sc_in< sc_logic > m_axi_In_ddr_RVALID;
    sc_out< sc_logic > m_axi_In_ddr_RREADY;
    sc_in< sc_uint<C_M_AXI_IN_DDR_DATA_WIDTH> > m_axi_In_ddr_RDATA;
    sc_in< sc_logic > m_axi_In_ddr_RLAST;
    sc_in< sc_uint<C_M_AXI_IN_DDR_ID_WIDTH> > m_axi_In_ddr_RID;
    sc_in< sc_uint<C_M_AXI_IN_DDR_RUSER_WIDTH> > m_axi_In_ddr_RUSER;
    sc_in< sc_lv<2> > m_axi_In_ddr_RRESP;
    sc_in< sc_logic > m_axi_In_ddr_BVALID;
    sc_out< sc_logic > m_axi_In_ddr_BREADY;
    sc_in< sc_lv<2> > m_axi_In_ddr_BRESP;
    sc_in< sc_uint<C_M_AXI_IN_DDR_ID_WIDTH> > m_axi_In_ddr_BID;
    sc_in< sc_uint<C_M_AXI_IN_DDR_BUSER_WIDTH> > m_axi_In_ddr_BUSER;
    sc_out< sc_logic > m_axi_W_ddr_AWVALID;
    sc_in< sc_logic > m_axi_W_ddr_AWREADY;
    sc_out< sc_uint<C_M_AXI_W_DDR_ADDR_WIDTH> > m_axi_W_ddr_AWADDR;
    sc_out< sc_uint<C_M_AXI_W_DDR_ID_WIDTH> > m_axi_W_ddr_AWID;
    sc_out< sc_lv<8> > m_axi_W_ddr_AWLEN;
    sc_out< sc_lv<3> > m_axi_W_ddr_AWSIZE;
    sc_out< sc_lv<2> > m_axi_W_ddr_AWBURST;
    sc_out< sc_lv<2> > m_axi_W_ddr_AWLOCK;
    sc_out< sc_lv<4> > m_axi_W_ddr_AWCACHE;
    sc_out< sc_lv<3> > m_axi_W_ddr_AWPROT;
    sc_out< sc_lv<4> > m_axi_W_ddr_AWQOS;
    sc_out< sc_lv<4> > m_axi_W_ddr_AWREGION;
    sc_out< sc_uint<C_M_AXI_W_DDR_AWUSER_WIDTH> > m_axi_W_ddr_AWUSER;
    sc_out< sc_logic > m_axi_W_ddr_WVALID;
    sc_in< sc_logic > m_axi_W_ddr_WREADY;
    sc_out< sc_uint<C_M_AXI_W_DDR_DATA_WIDTH> > m_axi_W_ddr_WDATA;
    sc_out< sc_uint<C_M_AXI_W_DDR_DATA_WIDTH/8> > m_axi_W_ddr_WSTRB;
    sc_out< sc_logic > m_axi_W_ddr_WLAST;
    sc_out< sc_uint<C_M_AXI_W_DDR_ID_WIDTH> > m_axi_W_ddr_WID;
    sc_out< sc_uint<C_M_AXI_W_DDR_WUSER_WIDTH> > m_axi_W_ddr_WUSER;
    sc_out< sc_logic > m_axi_W_ddr_ARVALID;
    sc_in< sc_logic > m_axi_W_ddr_ARREADY;
    sc_out< sc_uint<C_M_AXI_W_DDR_ADDR_WIDTH> > m_axi_W_ddr_ARADDR;
    sc_out< sc_uint<C_M_AXI_W_DDR_ID_WIDTH> > m_axi_W_ddr_ARID;
    sc_out< sc_lv<8> > m_axi_W_ddr_ARLEN;
    sc_out< sc_lv<3> > m_axi_W_ddr_ARSIZE;
    sc_out< sc_lv<2> > m_axi_W_ddr_ARBURST;
    sc_out< sc_lv<2> > m_axi_W_ddr_ARLOCK;
    sc_out< sc_lv<4> > m_axi_W_ddr_ARCACHE;
    sc_out< sc_lv<3> > m_axi_W_ddr_ARPROT;
    sc_out< sc_lv<4> > m_axi_W_ddr_ARQOS;
    sc_out< sc_lv<4> > m_axi_W_ddr_ARREGION;
    sc_out< sc_uint<C_M_AXI_W_DDR_ARUSER_WIDTH> > m_axi_W_ddr_ARUSER;
    sc_in< sc_logic > m_axi_W_ddr_RVALID;
    sc_out< sc_logic > m_axi_W_ddr_RREADY;
    sc_in< sc_uint<C_M_AXI_W_DDR_DATA_WIDTH> > m_axi_W_ddr_RDATA;
    sc_in< sc_logic > m_axi_W_ddr_RLAST;
    sc_in< sc_uint<C_M_AXI_W_DDR_ID_WIDTH> > m_axi_W_ddr_RID;
    sc_in< sc_uint<C_M_AXI_W_DDR_RUSER_WIDTH> > m_axi_W_ddr_RUSER;
    sc_in< sc_lv<2> > m_axi_W_ddr_RRESP;
    sc_in< sc_logic > m_axi_W_ddr_BVALID;
    sc_out< sc_logic > m_axi_W_ddr_BREADY;
    sc_in< sc_lv<2> > m_axi_W_ddr_BRESP;
    sc_in< sc_uint<C_M_AXI_W_DDR_ID_WIDTH> > m_axi_W_ddr_BID;
    sc_in< sc_uint<C_M_AXI_W_DDR_BUSER_WIDTH> > m_axi_W_ddr_BUSER;
    sc_out< sc_logic > m_axi_Out_ddr_AWVALID;
    sc_in< sc_logic > m_axi_Out_ddr_AWREADY;
    sc_out< sc_uint<C_M_AXI_OUT_DDR_ADDR_WIDTH> > m_axi_Out_ddr_AWADDR;
    sc_out< sc_uint<C_M_AXI_OUT_DDR_ID_WIDTH> > m_axi_Out_ddr_AWID;
    sc_out< sc_lv<8> > m_axi_Out_ddr_AWLEN;
    sc_out< sc_lv<3> > m_axi_Out_ddr_AWSIZE;
    sc_out< sc_lv<2> > m_axi_Out_ddr_AWBURST;
    sc_out< sc_lv<2> > m_axi_Out_ddr_AWLOCK;
    sc_out< sc_lv<4> > m_axi_Out_ddr_AWCACHE;
    sc_out< sc_lv<3> > m_axi_Out_ddr_AWPROT;
    sc_out< sc_lv<4> > m_axi_Out_ddr_AWQOS;
    sc_out< sc_lv<4> > m_axi_Out_ddr_AWREGION;
    sc_out< sc_uint<C_M_AXI_OUT_DDR_AWUSER_WIDTH> > m_axi_Out_ddr_AWUSER;
    sc_out< sc_logic > m_axi_Out_ddr_WVALID;
    sc_in< sc_logic > m_axi_Out_ddr_WREADY;
    sc_out< sc_uint<C_M_AXI_OUT_DDR_DATA_WIDTH> > m_axi_Out_ddr_WDATA;
    sc_out< sc_uint<C_M_AXI_OUT_DDR_DATA_WIDTH/8> > m_axi_Out_ddr_WSTRB;
    sc_out< sc_logic > m_axi_Out_ddr_WLAST;
    sc_out< sc_uint<C_M_AXI_OUT_DDR_ID_WIDTH> > m_axi_Out_ddr_WID;
    sc_out< sc_uint<C_M_AXI_OUT_DDR_WUSER_WIDTH> > m_axi_Out_ddr_WUSER;
    sc_out< sc_logic > m_axi_Out_ddr_ARVALID;
    sc_in< sc_logic > m_axi_Out_ddr_ARREADY;
    sc_out< sc_uint<C_M_AXI_OUT_DDR_ADDR_WIDTH> > m_axi_Out_ddr_ARADDR;
    sc_out< sc_uint<C_M_AXI_OUT_DDR_ID_WIDTH> > m_axi_Out_ddr_ARID;
    sc_out< sc_lv<8> > m_axi_Out_ddr_ARLEN;
    sc_out< sc_lv<3> > m_axi_Out_ddr_ARSIZE;
    sc_out< sc_lv<2> > m_axi_Out_ddr_ARBURST;
    sc_out< sc_lv<2> > m_axi_Out_ddr_ARLOCK;
    sc_out< sc_lv<4> > m_axi_Out_ddr_ARCACHE;
    sc_out< sc_lv<3> > m_axi_Out_ddr_ARPROT;
    sc_out< sc_lv<4> > m_axi_Out_ddr_ARQOS;
    sc_out< sc_lv<4> > m_axi_Out_ddr_ARREGION;
    sc_out< sc_uint<C_M_AXI_OUT_DDR_ARUSER_WIDTH> > m_axi_Out_ddr_ARUSER;
    sc_in< sc_logic > m_axi_Out_ddr_RVALID;
    sc_out< sc_logic > m_axi_Out_ddr_RREADY;
    sc_in< sc_uint<C_M_AXI_OUT_DDR_DATA_WIDTH> > m_axi_Out_ddr_RDATA;
    sc_in< sc_logic > m_axi_Out_ddr_RLAST;
    sc_in< sc_uint<C_M_AXI_OUT_DDR_ID_WIDTH> > m_axi_Out_ddr_RID;
    sc_in< sc_uint<C_M_AXI_OUT_DDR_RUSER_WIDTH> > m_axi_Out_ddr_RUSER;
    sc_in< sc_lv<2> > m_axi_Out_ddr_RRESP;
    sc_in< sc_logic > m_axi_Out_ddr_BVALID;
    sc_out< sc_logic > m_axi_Out_ddr_BREADY;
    sc_in< sc_lv<2> > m_axi_Out_ddr_BRESP;
    sc_in< sc_uint<C_M_AXI_OUT_DDR_ID_WIDTH> > m_axi_Out_ddr_BID;
    sc_in< sc_uint<C_M_AXI_OUT_DDR_BUSER_WIDTH> > m_axi_Out_ddr_BUSER;
    sc_signal< sc_logic > ap_var_for_const0;
    sc_signal< sc_logic > ap_var_for_const1;
    sc_signal< sc_lv<32> > ap_var_for_const2;
    sc_signal< sc_lv<1> > ap_var_for_const3;
    sc_signal< sc_lv<3> > ap_var_for_const4;
    sc_signal< sc_lv<2> > ap_var_for_const5;
    sc_signal< sc_lv<4> > ap_var_for_const6;


    // Module declarations
    convolution(sc_module_name name);
    SC_HAS_PROCESS(convolution);

    ~convolution();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    convolution_W_ddr_m_axi<0,32,32,5,16,16,16,16,C_M_AXI_W_DDR_ID_WIDTH,C_M_AXI_W_DDR_ADDR_WIDTH,C_M_AXI_W_DDR_DATA_WIDTH,C_M_AXI_W_DDR_AWUSER_WIDTH,C_M_AXI_W_DDR_ARUSER_WIDTH,C_M_AXI_W_DDR_WUSER_WIDTH,C_M_AXI_W_DDR_RUSER_WIDTH,C_M_AXI_W_DDR_BUSER_WIDTH,C_M_AXI_W_DDR_TARGET_ADDR,C_M_AXI_W_DDR_USER_VALUE,C_M_AXI_W_DDR_PROT_VALUE,C_M_AXI_W_DDR_CACHE_VALUE>* convolution_W_ddr_m_axi_U;
    convolution_Out_ddr_m_axi<0,32,32,5,16,16,16,16,C_M_AXI_OUT_DDR_ID_WIDTH,C_M_AXI_OUT_DDR_ADDR_WIDTH,C_M_AXI_OUT_DDR_DATA_WIDTH,C_M_AXI_OUT_DDR_AWUSER_WIDTH,C_M_AXI_OUT_DDR_ARUSER_WIDTH,C_M_AXI_OUT_DDR_WUSER_WIDTH,C_M_AXI_OUT_DDR_RUSER_WIDTH,C_M_AXI_OUT_DDR_BUSER_WIDTH,C_M_AXI_OUT_DDR_TARGET_ADDR,C_M_AXI_OUT_DDR_USER_VALUE,C_M_AXI_OUT_DDR_PROT_VALUE,C_M_AXI_OUT_DDR_CACHE_VALUE>* convolution_Out_ddr_m_axi_U;
    convolution_Out_0_0* Out_0_0_U;
    convolution_Out_0_0* Out_0_1_U;
    convolution_Out_0_0* Out_0_2_U;
    convolution_Out_0_0* Out_0_3_U;
    convolution_Out_0_0* Out_0_4_U;
    convolution_Out_0_0* Out_0_5_U;
    convolution_Out_0_0* Out_0_6_U;
    convolution_Out_0_0* Out_0_7_U;
    convolution_Out_0_0* Out_0_8_U;
    convolution_Out_0_0* Out_0_9_U;
    convolution_Out_0_0* Out_0_10_U;
    convolution_Out_0_0* Out_0_11_U;
    convolution_Out_0_0* Out_0_12_U;
    convolution_Out_0_0* Out_0_13_U;
    convolution_Out_0_0* Out_1_0_U;
    convolution_Out_0_0* Out_1_1_U;
    convolution_Out_0_0* Out_1_2_U;
    convolution_Out_0_0* Out_1_3_U;
    convolution_Out_0_0* Out_1_4_U;
    convolution_Out_0_0* Out_1_5_U;
    convolution_Out_0_0* Out_1_6_U;
    convolution_Out_0_0* Out_1_7_U;
    convolution_Out_0_0* Out_1_8_U;
    convolution_Out_0_0* Out_1_9_U;
    convolution_Out_0_0* Out_1_10_U;
    convolution_Out_0_0* Out_1_11_U;
    convolution_Out_0_0* Out_1_12_U;
    convolution_Out_0_0* Out_1_13_U;
    convolution_Out_0_0* Out_2_0_U;
    convolution_Out_0_0* Out_2_1_U;
    convolution_Out_0_0* Out_2_2_U;
    convolution_Out_0_0* Out_2_3_U;
    convolution_Out_0_0* Out_2_4_U;
    convolution_Out_0_0* Out_2_5_U;
    convolution_Out_0_0* Out_2_6_U;
    convolution_Out_0_0* Out_2_7_U;
    convolution_Out_0_0* Out_2_8_U;
    convolution_Out_0_0* Out_2_9_U;
    convolution_Out_0_0* Out_2_10_U;
    convolution_Out_0_0* Out_2_11_U;
    convolution_Out_0_0* Out_2_12_U;
    convolution_Out_0_0* Out_2_13_U;
    convolution_Out_0_0* Out_3_0_U;
    convolution_Out_0_0* Out_3_1_U;
    convolution_Out_0_0* Out_3_2_U;
    convolution_Out_0_0* Out_3_3_U;
    convolution_Out_0_0* Out_3_4_U;
    convolution_Out_0_0* Out_3_5_U;
    convolution_Out_0_0* Out_3_6_U;
    convolution_Out_0_0* Out_3_7_U;
    convolution_Out_0_0* Out_3_8_U;
    convolution_Out_0_0* Out_3_9_U;
    convolution_Out_0_0* Out_3_10_U;
    convolution_Out_0_0* Out_3_11_U;
    convolution_Out_0_0* Out_3_12_U;
    convolution_Out_0_0* Out_3_13_U;
    Process_r* grp_Process_r_fu_254;
    Offload_Out* grp_Offload_Out_fu_260;
    sc_signal< sc_logic > ap_rst_n_inv;
    sc_signal< sc_lv<2> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_logic > W_ddr_AWREADY;
    sc_signal< sc_logic > W_ddr_WREADY;
    sc_signal< sc_logic > W_ddr_ARVALID;
    sc_signal< sc_logic > W_ddr_ARREADY;
    sc_signal< sc_logic > W_ddr_RVALID;
    sc_signal< sc_logic > W_ddr_RREADY;
    sc_signal< sc_lv<32> > W_ddr_RDATA;
    sc_signal< sc_logic > W_ddr_RLAST;
    sc_signal< sc_lv<1> > W_ddr_RID;
    sc_signal< sc_lv<1> > W_ddr_RUSER;
    sc_signal< sc_lv<2> > W_ddr_RRESP;
    sc_signal< sc_logic > W_ddr_BVALID;
    sc_signal< sc_lv<2> > W_ddr_BRESP;
    sc_signal< sc_lv<1> > W_ddr_BID;
    sc_signal< sc_lv<1> > W_ddr_BUSER;
    sc_signal< sc_logic > Out_ddr_AWVALID;
    sc_signal< sc_logic > Out_ddr_AWREADY;
    sc_signal< sc_logic > Out_ddr_WVALID;
    sc_signal< sc_logic > Out_ddr_WREADY;
    sc_signal< sc_logic > Out_ddr_ARREADY;
    sc_signal< sc_logic > Out_ddr_RVALID;
    sc_signal< sc_lv<32> > Out_ddr_RDATA;
    sc_signal< sc_logic > Out_ddr_RLAST;
    sc_signal< sc_lv<1> > Out_ddr_RID;
    sc_signal< sc_lv<1> > Out_ddr_RUSER;
    sc_signal< sc_lv<2> > Out_ddr_RRESP;
    sc_signal< sc_logic > Out_ddr_BVALID;
    sc_signal< sc_logic > Out_ddr_BREADY;
    sc_signal< sc_lv<2> > Out_ddr_BRESP;
    sc_signal< sc_lv<1> > Out_ddr_BID;
    sc_signal< sc_lv<1> > Out_ddr_BUSER;
    sc_signal< sc_lv<32> > Out_0_0_q0;
    sc_signal< sc_lv<32> > Out_0_1_q0;
    sc_signal< sc_lv<32> > Out_0_2_q0;
    sc_signal< sc_lv<32> > Out_0_3_q0;
    sc_signal< sc_lv<32> > Out_0_4_q0;
    sc_signal< sc_lv<32> > Out_0_5_q0;
    sc_signal< sc_lv<32> > Out_0_6_q0;
    sc_signal< sc_lv<32> > Out_0_7_q0;
    sc_signal< sc_lv<32> > Out_0_8_q0;
    sc_signal< sc_lv<32> > Out_0_9_q0;
    sc_signal< sc_lv<32> > Out_0_10_q0;
    sc_signal< sc_lv<32> > Out_0_11_q0;
    sc_signal< sc_lv<32> > Out_0_12_q0;
    sc_signal< sc_lv<32> > Out_0_13_q0;
    sc_signal< sc_lv<32> > Out_1_0_q0;
    sc_signal< sc_lv<32> > Out_1_1_q0;
    sc_signal< sc_lv<32> > Out_1_2_q0;
    sc_signal< sc_lv<32> > Out_1_3_q0;
    sc_signal< sc_lv<32> > Out_1_4_q0;
    sc_signal< sc_lv<32> > Out_1_5_q0;
    sc_signal< sc_lv<32> > Out_1_6_q0;
    sc_signal< sc_lv<32> > Out_1_7_q0;
    sc_signal< sc_lv<32> > Out_1_8_q0;
    sc_signal< sc_lv<32> > Out_1_9_q0;
    sc_signal< sc_lv<32> > Out_1_10_q0;
    sc_signal< sc_lv<32> > Out_1_11_q0;
    sc_signal< sc_lv<32> > Out_1_12_q0;
    sc_signal< sc_lv<32> > Out_1_13_q0;
    sc_signal< sc_lv<32> > Out_2_0_q0;
    sc_signal< sc_lv<32> > Out_2_1_q0;
    sc_signal< sc_lv<32> > Out_2_2_q0;
    sc_signal< sc_lv<32> > Out_2_3_q0;
    sc_signal< sc_lv<32> > Out_2_4_q0;
    sc_signal< sc_lv<32> > Out_2_5_q0;
    sc_signal< sc_lv<32> > Out_2_6_q0;
    sc_signal< sc_lv<32> > Out_2_7_q0;
    sc_signal< sc_lv<32> > Out_2_8_q0;
    sc_signal< sc_lv<32> > Out_2_9_q0;
    sc_signal< sc_lv<32> > Out_2_10_q0;
    sc_signal< sc_lv<32> > Out_2_11_q0;
    sc_signal< sc_lv<32> > Out_2_12_q0;
    sc_signal< sc_lv<32> > Out_2_13_q0;
    sc_signal< sc_lv<32> > Out_3_0_q0;
    sc_signal< sc_lv<32> > Out_3_1_q0;
    sc_signal< sc_lv<32> > Out_3_2_q0;
    sc_signal< sc_lv<32> > Out_3_3_q0;
    sc_signal< sc_lv<32> > Out_3_4_q0;
    sc_signal< sc_lv<32> > Out_3_5_q0;
    sc_signal< sc_lv<32> > Out_3_6_q0;
    sc_signal< sc_lv<32> > Out_3_7_q0;
    sc_signal< sc_lv<32> > Out_3_8_q0;
    sc_signal< sc_lv<32> > Out_3_9_q0;
    sc_signal< sc_lv<32> > Out_3_10_q0;
    sc_signal< sc_lv<32> > Out_3_11_q0;
    sc_signal< sc_lv<32> > Out_3_12_q0;
    sc_signal< sc_lv<32> > Out_3_13_q0;
    sc_signal< sc_logic > grp_Process_r_fu_254_ap_start;
    sc_signal< sc_logic > grp_Process_r_fu_254_ap_done;
    sc_signal< sc_logic > grp_Process_r_fu_254_ap_idle;
    sc_signal< sc_logic > grp_Process_r_fu_254_ap_ready;
    sc_signal< sc_logic > grp_Process_r_fu_254_m_axi_W_ddr_AWVALID;
    sc_signal< sc_lv<32> > grp_Process_r_fu_254_m_axi_W_ddr_AWADDR;
    sc_signal< sc_lv<1> > grp_Process_r_fu_254_m_axi_W_ddr_AWID;
    sc_signal< sc_lv<32> > grp_Process_r_fu_254_m_axi_W_ddr_AWLEN;
    sc_signal< sc_lv<3> > grp_Process_r_fu_254_m_axi_W_ddr_AWSIZE;
    sc_signal< sc_lv<2> > grp_Process_r_fu_254_m_axi_W_ddr_AWBURST;
    sc_signal< sc_lv<2> > grp_Process_r_fu_254_m_axi_W_ddr_AWLOCK;
    sc_signal< sc_lv<4> > grp_Process_r_fu_254_m_axi_W_ddr_AWCACHE;
    sc_signal< sc_lv<3> > grp_Process_r_fu_254_m_axi_W_ddr_AWPROT;
    sc_signal< sc_lv<4> > grp_Process_r_fu_254_m_axi_W_ddr_AWQOS;
    sc_signal< sc_lv<4> > grp_Process_r_fu_254_m_axi_W_ddr_AWREGION;
    sc_signal< sc_lv<1> > grp_Process_r_fu_254_m_axi_W_ddr_AWUSER;
    sc_signal< sc_logic > grp_Process_r_fu_254_m_axi_W_ddr_WVALID;
    sc_signal< sc_lv<32> > grp_Process_r_fu_254_m_axi_W_ddr_WDATA;
    sc_signal< sc_lv<4> > grp_Process_r_fu_254_m_axi_W_ddr_WSTRB;
    sc_signal< sc_logic > grp_Process_r_fu_254_m_axi_W_ddr_WLAST;
    sc_signal< sc_lv<1> > grp_Process_r_fu_254_m_axi_W_ddr_WID;
    sc_signal< sc_lv<1> > grp_Process_r_fu_254_m_axi_W_ddr_WUSER;
    sc_signal< sc_logic > grp_Process_r_fu_254_m_axi_W_ddr_ARVALID;
    sc_signal< sc_lv<32> > grp_Process_r_fu_254_m_axi_W_ddr_ARADDR;
    sc_signal< sc_lv<1> > grp_Process_r_fu_254_m_axi_W_ddr_ARID;
    sc_signal< sc_lv<32> > grp_Process_r_fu_254_m_axi_W_ddr_ARLEN;
    sc_signal< sc_lv<3> > grp_Process_r_fu_254_m_axi_W_ddr_ARSIZE;
    sc_signal< sc_lv<2> > grp_Process_r_fu_254_m_axi_W_ddr_ARBURST;
    sc_signal< sc_lv<2> > grp_Process_r_fu_254_m_axi_W_ddr_ARLOCK;
    sc_signal< sc_lv<4> > grp_Process_r_fu_254_m_axi_W_ddr_ARCACHE;
    sc_signal< sc_lv<3> > grp_Process_r_fu_254_m_axi_W_ddr_ARPROT;
    sc_signal< sc_lv<4> > grp_Process_r_fu_254_m_axi_W_ddr_ARQOS;
    sc_signal< sc_lv<4> > grp_Process_r_fu_254_m_axi_W_ddr_ARREGION;
    sc_signal< sc_lv<1> > grp_Process_r_fu_254_m_axi_W_ddr_ARUSER;
    sc_signal< sc_logic > grp_Process_r_fu_254_m_axi_W_ddr_RREADY;
    sc_signal< sc_logic > grp_Process_r_fu_254_m_axi_W_ddr_BREADY;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_ap_start;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_ap_done;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_ap_idle;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_ap_ready;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWVALID;
    sc_signal< sc_lv<32> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWADDR;
    sc_signal< sc_lv<1> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWID;
    sc_signal< sc_lv<32> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWLEN;
    sc_signal< sc_lv<3> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWSIZE;
    sc_signal< sc_lv<2> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWBURST;
    sc_signal< sc_lv<2> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWLOCK;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWCACHE;
    sc_signal< sc_lv<3> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWPROT;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWQOS;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWREGION;
    sc_signal< sc_lv<1> > grp_Offload_Out_fu_260_m_axi_Out_ddr_AWUSER;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_m_axi_Out_ddr_WVALID;
    sc_signal< sc_lv<32> > grp_Offload_Out_fu_260_m_axi_Out_ddr_WDATA;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_m_axi_Out_ddr_WSTRB;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_m_axi_Out_ddr_WLAST;
    sc_signal< sc_lv<1> > grp_Offload_Out_fu_260_m_axi_Out_ddr_WID;
    sc_signal< sc_lv<1> > grp_Offload_Out_fu_260_m_axi_Out_ddr_WUSER;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARVALID;
    sc_signal< sc_lv<32> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARADDR;
    sc_signal< sc_lv<1> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARID;
    sc_signal< sc_lv<32> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARLEN;
    sc_signal< sc_lv<3> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARSIZE;
    sc_signal< sc_lv<2> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARBURST;
    sc_signal< sc_lv<2> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARLOCK;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARCACHE;
    sc_signal< sc_lv<3> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARPROT;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARQOS;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARREGION;
    sc_signal< sc_lv<1> > grp_Offload_Out_fu_260_m_axi_Out_ddr_ARUSER;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_m_axi_Out_ddr_RREADY;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_m_axi_Out_ddr_BREADY;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_0_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_0_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_1_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_1_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_2_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_2_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_3_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_3_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_4_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_4_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_5_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_5_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_6_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_6_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_7_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_7_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_8_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_8_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_9_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_9_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_10_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_10_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_11_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_11_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_12_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_12_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_0_13_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_0_13_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_0_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_0_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_1_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_1_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_2_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_2_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_3_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_3_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_4_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_4_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_5_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_5_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_6_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_6_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_7_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_7_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_8_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_8_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_9_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_9_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_10_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_10_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_11_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_11_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_12_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_12_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_1_13_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_1_13_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_0_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_0_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_1_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_1_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_2_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_2_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_3_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_3_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_4_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_4_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_5_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_5_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_6_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_6_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_7_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_7_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_8_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_8_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_9_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_9_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_10_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_10_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_11_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_11_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_12_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_12_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_2_13_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_2_13_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_0_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_0_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_1_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_1_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_2_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_2_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_3_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_3_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_4_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_4_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_5_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_5_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_6_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_6_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_7_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_7_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_8_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_8_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_9_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_9_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_10_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_10_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_11_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_11_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_12_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_12_ce0;
    sc_signal< sc_lv<4> > grp_Offload_Out_fu_260_Out_3_13_address0;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_Out_3_13_ce0;
    sc_signal< sc_logic > grp_Process_r_fu_254_ap_start_reg;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_logic > grp_Offload_Out_fu_260_ap_start_reg;
    sc_signal< bool > ap_block_state2_on_subcall_done;
    sc_signal< sc_lv<2> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<2> ap_ST_fsm_state1;
    static const sc_lv<2> ap_ST_fsm_state2;
    static const sc_lv<32> ap_const_lv32_0;
    static const int C_M_AXI_IN_DDR_TARGET_ADDR;
    static const int C_M_AXI_IN_DDR_USER_VALUE;
    static const int C_M_AXI_IN_DDR_PROT_VALUE;
    static const int C_M_AXI_IN_DDR_CACHE_VALUE;
    static const int C_M_AXI_W_DDR_TARGET_ADDR;
    static const int C_M_AXI_W_DDR_USER_VALUE;
    static const int C_M_AXI_W_DDR_PROT_VALUE;
    static const int C_M_AXI_W_DDR_CACHE_VALUE;
    static const int C_M_AXI_DATA_WIDTH;
    static const int C_M_AXI_OUT_DDR_TARGET_ADDR;
    static const int C_M_AXI_OUT_DDR_USER_VALUE;
    static const int C_M_AXI_OUT_DDR_PROT_VALUE;
    static const int C_M_AXI_OUT_DDR_CACHE_VALUE;
    static const sc_lv<32> ap_const_lv32_1;
    static const bool ap_const_boolean_0;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<8> ap_const_lv8_0;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_var_for_const0();
    void thread_ap_var_for_const1();
    void thread_ap_var_for_const2();
    void thread_ap_var_for_const3();
    void thread_ap_var_for_const4();
    void thread_ap_var_for_const5();
    void thread_ap_var_for_const6();
    void thread_ap_clk_no_reset_();
    void thread_Out_ddr_AWVALID();
    void thread_Out_ddr_BREADY();
    void thread_Out_ddr_WVALID();
    void thread_W_ddr_ARVALID();
    void thread_W_ddr_RREADY();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state2();
    void thread_ap_block_state2_on_subcall_done();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_rst_n_inv();
    void thread_grp_Offload_Out_fu_260_ap_start();
    void thread_grp_Process_r_fu_254_ap_start();
    void thread_m_axi_In_ddr_ARADDR();
    void thread_m_axi_In_ddr_ARBURST();
    void thread_m_axi_In_ddr_ARCACHE();
    void thread_m_axi_In_ddr_ARID();
    void thread_m_axi_In_ddr_ARLEN();
    void thread_m_axi_In_ddr_ARLOCK();
    void thread_m_axi_In_ddr_ARPROT();
    void thread_m_axi_In_ddr_ARQOS();
    void thread_m_axi_In_ddr_ARREGION();
    void thread_m_axi_In_ddr_ARSIZE();
    void thread_m_axi_In_ddr_ARUSER();
    void thread_m_axi_In_ddr_ARVALID();
    void thread_m_axi_In_ddr_AWADDR();
    void thread_m_axi_In_ddr_AWBURST();
    void thread_m_axi_In_ddr_AWCACHE();
    void thread_m_axi_In_ddr_AWID();
    void thread_m_axi_In_ddr_AWLEN();
    void thread_m_axi_In_ddr_AWLOCK();
    void thread_m_axi_In_ddr_AWPROT();
    void thread_m_axi_In_ddr_AWQOS();
    void thread_m_axi_In_ddr_AWREGION();
    void thread_m_axi_In_ddr_AWSIZE();
    void thread_m_axi_In_ddr_AWUSER();
    void thread_m_axi_In_ddr_AWVALID();
    void thread_m_axi_In_ddr_BREADY();
    void thread_m_axi_In_ddr_RREADY();
    void thread_m_axi_In_ddr_WDATA();
    void thread_m_axi_In_ddr_WID();
    void thread_m_axi_In_ddr_WLAST();
    void thread_m_axi_In_ddr_WSTRB();
    void thread_m_axi_In_ddr_WUSER();
    void thread_m_axi_In_ddr_WVALID();
    void thread_ap_NS_fsm();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif
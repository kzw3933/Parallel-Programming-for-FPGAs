// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2020.1
// Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="cordic,hls_ip_2020_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=1,HLS_INPUT_PART=xc7vx485t-ffg1157-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=7.882000,HLS_SYN_LAT=33,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=2,HLS_SYN_FF=107,HLS_SYN_LUT=209,HLS_VERSION=2020_1}" *)

module cordic (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        theta_V,
        s_V,
        s_V_ap_vld,
        c_V,
        c_V_ap_vld
);

parameter    ap_ST_fsm_state1 = 3'd1;
parameter    ap_ST_fsm_state2 = 3'd2;
parameter    ap_ST_fsm_state3 = 3'd4;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [11:0] theta_V;
output  [11:0] s_V;
output   s_V_ap_vld;
output  [11:0] c_V;
output   c_V_ap_vld;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg s_V_ap_vld;
reg c_V_ap_vld;

(* fsm_encoding = "none" *) reg   [2:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [3:0] cordic_phase_V_address0;
reg    cordic_phase_V_ce0;
wire   [10:0] cordic_phase_V_q0;
wire   [4:0] j_fu_155_p2;
reg   [4:0] j_reg_319;
wire    ap_CS_fsm_state2;
wire   [0:0] tmp_fu_161_p3;
reg   [0:0] tmp_reg_324;
wire   [0:0] icmp_ln17_fu_149_p2;
reg   [11:0] current_cos_V_reg_329;
reg   [11:0] current_sin_V_reg_334;
wire  signed [10:0] sext_ln1333_fu_266_p1;
reg  signed [10:0] sext_ln1333_reg_344;
wire   [11:0] sub_ln703_fu_287_p2;
wire    ap_CS_fsm_state3;
reg   [11:0] p_Val2_4_reg_93;
reg  signed [10:0] factor_0_reg_103;
reg  signed [11:0] p_Val2_2_reg_114;
reg  signed [11:0] temp_cos_V_reg_126;
reg   [4:0] j_0_reg_138;
wire   [63:0] zext_ln26_fu_251_p1;
wire  signed [12:0] sext_ln1116_fu_169_p1;
wire   [12:0] sub_ln1118_fu_173_p2;
wire  signed [12:0] r_V_fu_179_p3;
wire  signed [20:0] grp_fu_293_p3;
wire  signed [12:0] sext_ln1116_1_fu_212_p1;
wire   [12:0] sub_ln1118_1_fu_216_p2;
wire  signed [12:0] r_V_1_fu_222_p3;
wire  signed [20:0] grp_fu_302_p3;
wire   [9:0] trunc_ln_fu_256_p4;
wire   [10:0] sub_ln703_1_fu_270_p2;
wire   [10:0] select_ln703_fu_276_p3;
wire  signed [11:0] sext_ln703_fu_283_p1;
wire  signed [10:0] grp_fu_293_p0;
wire  signed [20:0] sext_ln1118_1_fu_191_p1;
wire   [20:0] grp_fu_293_p2;
wire  signed [10:0] grp_fu_302_p0;
wire   [20:0] grp_fu_302_p2;
reg   [2:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 3'd1;
end

cordic_cordic_phabkb #(
    .DataWidth( 11 ),
    .AddressRange( 16 ),
    .AddressWidth( 4 ))
cordic_phase_V_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(cordic_phase_V_address0),
    .ce0(cordic_phase_V_ce0),
    .q0(cordic_phase_V_q0)
);

cordic_mac_mulsubcud #(
    .ID( 1 ),
    .NUM_STAGE( 1 ),
    .din0_WIDTH( 11 ),
    .din1_WIDTH( 13 ),
    .din2_WIDTH( 21 ),
    .dout_WIDTH( 21 ))
cordic_mac_mulsubcud_U1(
    .din0(grp_fu_293_p0),
    .din1(r_V_fu_179_p3),
    .din2(grp_fu_293_p2),
    .dout(grp_fu_293_p3)
);

cordic_mac_muladddEe #(
    .ID( 1 ),
    .NUM_STAGE( 1 ),
    .din0_WIDTH( 11 ),
    .din1_WIDTH( 13 ),
    .din2_WIDTH( 21 ),
    .dout_WIDTH( 21 ))
cordic_mac_muladddEe_U2(
    .din0(grp_fu_302_p0),
    .din1(r_V_1_fu_222_p3),
    .din2(grp_fu_302_p2),
    .dout(grp_fu_302_p3)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        factor_0_reg_103 <= sext_ln1333_reg_344;
    end else if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        factor_0_reg_103 <= 11'd512;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        j_0_reg_138 <= j_reg_319;
    end else if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        j_0_reg_138 <= 5'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        p_Val2_2_reg_114 <= current_sin_V_reg_334;
    end else if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        p_Val2_2_reg_114 <= 12'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        p_Val2_4_reg_93 <= sub_ln703_fu_287_p2;
    end else if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        p_Val2_4_reg_93 <= theta_V;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        temp_cos_V_reg_126 <= current_cos_V_reg_329;
    end else if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        temp_cos_V_reg_126 <= 12'd310;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln17_fu_149_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        current_cos_V_reg_329 <= {{grp_fu_293_p3[20:9]}};
        current_sin_V_reg_334 <= {{grp_fu_302_p3[20:9]}};
        sext_ln1333_reg_344 <= sext_ln1333_fu_266_p1;
        tmp_reg_324 <= p_Val2_4_reg_93[32'd11];
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        j_reg_319 <= j_fu_155_p2;
    end
end

always @ (*) begin
    if (((icmp_ln17_fu_149_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln17_fu_149_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln17_fu_149_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        c_V_ap_vld = 1'b1;
    end else begin
        c_V_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        cordic_phase_V_ce0 = 1'b1;
    end else begin
        cordic_phase_V_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln17_fu_149_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        s_V_ap_vld = 1'b1;
    end else begin
        s_V_ap_vld = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((icmp_ln17_fu_149_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign c_V = temp_cos_V_reg_126;

assign cordic_phase_V_address0 = zext_ln26_fu_251_p1;

assign grp_fu_293_p0 = sext_ln1118_1_fu_191_p1;

assign grp_fu_293_p2 = {{temp_cos_V_reg_126}, {9'd0}};

assign grp_fu_302_p0 = sext_ln1118_1_fu_191_p1;

assign grp_fu_302_p2 = {{p_Val2_2_reg_114}, {9'd0}};

assign icmp_ln17_fu_149_p2 = ((j_0_reg_138 == 5'd16) ? 1'b1 : 1'b0);

assign j_fu_155_p2 = (j_0_reg_138 + 5'd1);

assign r_V_1_fu_222_p3 = ((tmp_fu_161_p3[0:0] === 1'b1) ? sub_ln1118_1_fu_216_p2 : sext_ln1116_1_fu_212_p1);

assign r_V_fu_179_p3 = ((tmp_fu_161_p3[0:0] === 1'b1) ? sub_ln1118_fu_173_p2 : sext_ln1116_fu_169_p1);

assign s_V = p_Val2_2_reg_114;

assign select_ln703_fu_276_p3 = ((tmp_reg_324[0:0] === 1'b1) ? sub_ln703_1_fu_270_p2 : cordic_phase_V_q0);

assign sext_ln1116_1_fu_212_p1 = temp_cos_V_reg_126;

assign sext_ln1116_fu_169_p1 = p_Val2_2_reg_114;

assign sext_ln1118_1_fu_191_p1 = factor_0_reg_103;

assign sext_ln1333_fu_266_p1 = $signed(trunc_ln_fu_256_p4);

assign sext_ln703_fu_283_p1 = $signed(select_ln703_fu_276_p3);

assign sub_ln1118_1_fu_216_p2 = ($signed(13'd0) - $signed(sext_ln1116_1_fu_212_p1));

assign sub_ln1118_fu_173_p2 = ($signed(13'd0) - $signed(sext_ln1116_fu_169_p1));

assign sub_ln703_1_fu_270_p2 = (11'd0 - cordic_phase_V_q0);

assign sub_ln703_fu_287_p2 = ($signed(p_Val2_4_reg_93) - $signed(sext_ln703_fu_283_p1));

assign tmp_fu_161_p3 = p_Val2_4_reg_93[32'd11];

assign trunc_ln_fu_256_p4 = {{factor_0_reg_103[10:1]}};

assign zext_ln26_fu_251_p1 = j_0_reg_138;

endmodule //cordic

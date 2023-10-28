// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2020.1
// Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module fft_stage86 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_continue,
        ap_idle,
        ap_ready,
        X_R9_address0,
        X_R9_ce0,
        X_R9_q0,
        X_I18_address0,
        X_I18_ce0,
        X_I18_q0,
        Out_R_address0,
        Out_R_ce0,
        Out_R_we0,
        Out_R_d0,
        Out_R_address1,
        Out_R_ce1,
        Out_R_we1,
        Out_R_d1,
        Out_I_address0,
        Out_I_ce0,
        Out_I_we0,
        Out_I_d0,
        Out_I_address1,
        Out_I_ce1,
        Out_I_we1,
        Out_I_d1
);

parameter    ap_ST_fsm_state1 = 21'd1;
parameter    ap_ST_fsm_state2 = 21'd2;
parameter    ap_ST_fsm_state3 = 21'd4;
parameter    ap_ST_fsm_state4 = 21'd8;
parameter    ap_ST_fsm_state5 = 21'd16;
parameter    ap_ST_fsm_state6 = 21'd32;
parameter    ap_ST_fsm_state7 = 21'd64;
parameter    ap_ST_fsm_state8 = 21'd128;
parameter    ap_ST_fsm_state9 = 21'd256;
parameter    ap_ST_fsm_state10 = 21'd512;
parameter    ap_ST_fsm_state11 = 21'd1024;
parameter    ap_ST_fsm_state12 = 21'd2048;
parameter    ap_ST_fsm_state13 = 21'd4096;
parameter    ap_ST_fsm_state14 = 21'd8192;
parameter    ap_ST_fsm_state15 = 21'd16384;
parameter    ap_ST_fsm_state16 = 21'd32768;
parameter    ap_ST_fsm_state17 = 21'd65536;
parameter    ap_ST_fsm_state18 = 21'd131072;
parameter    ap_ST_fsm_state19 = 21'd262144;
parameter    ap_ST_fsm_state20 = 21'd524288;
parameter    ap_ST_fsm_state21 = 21'd1048576;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
input   ap_continue;
output   ap_idle;
output   ap_ready;
output  [9:0] X_R9_address0;
output   X_R9_ce0;
input  [31:0] X_R9_q0;
output  [9:0] X_I18_address0;
output   X_I18_ce0;
input  [31:0] X_I18_q0;
output  [9:0] Out_R_address0;
output   Out_R_ce0;
output   Out_R_we0;
output  [31:0] Out_R_d0;
output  [9:0] Out_R_address1;
output   Out_R_ce1;
output   Out_R_we1;
output  [31:0] Out_R_d1;
output  [9:0] Out_I_address0;
output   Out_I_ce0;
output   Out_I_we0;
output  [31:0] Out_I_d0;
output  [9:0] Out_I_address1;
output   Out_I_ce1;
output   Out_I_we1;
output  [31:0] Out_I_d1;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg[9:0] X_R9_address0;
reg X_R9_ce0;
reg[9:0] X_I18_address0;
reg X_I18_ce0;
reg Out_R_ce0;
reg Out_R_we0;
reg Out_R_ce1;
reg Out_R_we1;
reg Out_I_ce0;
reg Out_I_we0;
reg Out_I_ce1;
reg Out_I_we1;

reg    ap_done_reg;
(* fsm_encoding = "none" *) reg   [20:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg   [31:0] reg_267;
wire    ap_CS_fsm_state9;
wire    ap_CS_fsm_state16;
reg   [31:0] reg_274;
wire   [31:0] grp_fu_227_p2;
reg   [31:0] reg_282;
wire    ap_CS_fsm_state20;
wire   [31:0] grp_fu_233_p2;
reg   [31:0] reg_289;
wire   [31:0] zext_ln39_fu_296_p1;
reg   [31:0] zext_ln39_reg_352;
wire    ap_CS_fsm_state2;
wire   [9:0] j_fu_306_p2;
reg   [9:0] j_reg_360;
wire   [63:0] grp_fu_263_p1;
reg   [63:0] x_assign_reg_365;
wire    ap_CS_fsm_state3;
wire   [63:0] grp_sin_or_cos_double_s_fu_189_ap_return;
reg   [63:0] tmp_i_i_reg_371;
wire    ap_CS_fsm_state5;
wire    grp_sin_or_cos_double_s_fu_189_ap_ready;
wire    grp_sin_or_cos_double_s_fu_189_ap_done;
wire    grp_sin_or_cos_double_s_fu_208_ap_ready;
wire    grp_sin_or_cos_double_s_fu_208_ap_done;
reg    ap_block_state5_on_subcall_done;
wire   [63:0] grp_sin_or_cos_double_s_fu_208_ap_return;
reg   [63:0] tmp_i_i1_reg_376;
reg   [31:0] a_reg_381;
wire   [31:0] grp_fu_257_p1;
reg   [31:0] c_reg_386;
wire    ap_CS_fsm_state7;
wire   [31:0] grp_fu_260_p1;
reg   [31:0] s_reg_392;
wire  signed [63:0] sext_ln48_fu_334_p1;
reg  signed [63:0] sext_ln48_reg_400;
wire    ap_CS_fsm_state8;
wire   [0:0] icmp_ln46_fu_322_p2;
wire   [31:0] grp_fu_245_p2;
reg   [31:0] tmp_7_reg_416;
wire    ap_CS_fsm_state12;
wire   [31:0] grp_fu_249_p2;
reg   [31:0] tmp_8_reg_421;
wire   [31:0] grp_fu_253_p2;
reg   [31:0] tmp_9_reg_427;
wire  signed [63:0] sext_ln50_fu_340_p1;
reg  signed [63:0] sext_ln50_reg_432;
wire    ap_CS_fsm_state15;
wire   [31:0] i_3_fu_346_p2;
reg   [31:0] i_3_reg_448;
wire   [31:0] grp_fu_237_p2;
reg   [31:0] tmp_6_reg_453;
wire   [31:0] grp_fu_241_p2;
reg   [31:0] tmp_2_reg_458;
wire    grp_sin_or_cos_double_s_fu_189_ap_start;
wire    grp_sin_or_cos_double_s_fu_189_ap_idle;
wire    grp_sin_or_cos_double_s_fu_189_do_cos;
wire    grp_sin_or_cos_double_s_fu_208_ap_start;
wire    grp_sin_or_cos_double_s_fu_208_ap_idle;
wire    grp_sin_or_cos_double_s_fu_208_do_cos;
reg   [31:0] a_0_reg_156;
reg    ap_block_state1;
reg   [9:0] i_reg_168;
reg  signed [31:0] i_0_reg_179;
wire    ap_CS_fsm_state21;
reg    grp_sin_or_cos_double_s_fu_189_ap_start_reg;
wire    ap_CS_fsm_state4;
reg    grp_sin_or_cos_double_s_fu_208_ap_start_reg;
reg   [31:0] grp_fu_227_p0;
reg   [31:0] grp_fu_227_p1;
wire    ap_CS_fsm_state13;
wire    ap_CS_fsm_state17;
reg   [31:0] grp_fu_233_p0;
reg   [31:0] grp_fu_233_p1;
wire    ap_CS_fsm_state10;
wire    ap_CS_fsm_state6;
wire   [21:0] tmp_11_fu_312_p4;
wire   [31:0] i_lower_fu_328_p2;
reg   [1:0] grp_fu_227_opcode;
wire   [0:0] icmp_ln39_fu_300_p2;
reg    grp_fu_227_ce;
wire    ap_CS_fsm_state11;
reg   [1:0] grp_fu_233_opcode;
reg   [20:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_done_reg = 1'b0;
#0 ap_CS_fsm = 21'd1;
#0 grp_sin_or_cos_double_s_fu_189_ap_start_reg = 1'b0;
#0 grp_sin_or_cos_double_s_fu_208_ap_start_reg = 1'b0;
end

sin_or_cos_double_s grp_sin_or_cos_double_s_fu_189(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_sin_or_cos_double_s_fu_189_ap_start),
    .ap_done(grp_sin_or_cos_double_s_fu_189_ap_done),
    .ap_idle(grp_sin_or_cos_double_s_fu_189_ap_idle),
    .ap_ready(grp_sin_or_cos_double_s_fu_189_ap_ready),
    .t_in(x_assign_reg_365),
    .do_cos(grp_sin_or_cos_double_s_fu_189_do_cos),
    .ap_return(grp_sin_or_cos_double_s_fu_189_ap_return)
);

sin_or_cos_double_s grp_sin_or_cos_double_s_fu_208(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_sin_or_cos_double_s_fu_208_ap_start),
    .ap_done(grp_sin_or_cos_double_s_fu_208_ap_done),
    .ap_idle(grp_sin_or_cos_double_s_fu_208_ap_idle),
    .ap_ready(grp_sin_or_cos_double_s_fu_208_ap_ready),
    .t_in(x_assign_reg_365),
    .do_cos(grp_sin_or_cos_double_s_fu_208_do_cos),
    .ap_return(grp_sin_or_cos_double_s_fu_208_ap_return)
);

fft_faddfsub_32nslbW #(
    .ID( 1 ),
    .NUM_STAGE( 4 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
fft_faddfsub_32nslbW_U160(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_227_p0),
    .din1(grp_fu_227_p1),
    .opcode(grp_fu_227_opcode),
    .ce(grp_fu_227_ce),
    .dout(grp_fu_227_p2)
);

fft_faddfsub_32nslbW #(
    .ID( 1 ),
    .NUM_STAGE( 4 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
fft_faddfsub_32nslbW_U161(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_233_p0),
    .din1(grp_fu_233_p1),
    .opcode(grp_fu_233_opcode),
    .ce(1'b1),
    .dout(grp_fu_233_p2)
);

fft_fadd_32ns_32nmb6 #(
    .ID( 1 ),
    .NUM_STAGE( 4 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
fft_fadd_32ns_32nmb6_U162(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(reg_267),
    .din1(reg_282),
    .ce(1'b1),
    .dout(grp_fu_237_p2)
);

fft_fadd_32ns_32nmb6 #(
    .ID( 1 ),
    .NUM_STAGE( 4 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
fft_fadd_32ns_32nmb6_U163(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(reg_274),
    .din1(reg_289),
    .ce(1'b1),
    .dout(grp_fu_241_p2)
);

fft_fmul_32ns_32nncg #(
    .ID( 1 ),
    .NUM_STAGE( 3 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
fft_fmul_32ns_32nncg_U164(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(reg_267),
    .din1(c_reg_386),
    .ce(1'b1),
    .dout(grp_fu_245_p2)
);

fft_fmul_32ns_32nncg #(
    .ID( 1 ),
    .NUM_STAGE( 3 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
fft_fmul_32ns_32nncg_U165(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(reg_274),
    .din1(s_reg_392),
    .ce(1'b1),
    .dout(grp_fu_249_p2)
);

fft_fmul_32ns_32nncg #(
    .ID( 1 ),
    .NUM_STAGE( 3 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
fft_fmul_32ns_32nncg_U166(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(reg_274),
    .din1(c_reg_386),
    .ce(1'b1),
    .dout(grp_fu_253_p2)
);

fft_fptrunc_64ns_ocq #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 64 ),
    .dout_WIDTH( 32 ))
fft_fptrunc_64ns_ocq_U167(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(tmp_i_i_reg_371),
    .ce(1'b1),
    .dout(grp_fu_257_p1)
);

fft_fptrunc_64ns_ocq #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 64 ),
    .dout_WIDTH( 32 ))
fft_fptrunc_64ns_ocq_U168(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(tmp_i_i1_reg_376),
    .ce(1'b1),
    .dout(grp_fu_260_p1)
);

fft_fpext_32ns_64pcA #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 32 ),
    .dout_WIDTH( 64 ))
fft_fpext_32ns_64pcA_U169(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(a_0_reg_156),
    .ce(1'b1),
    .dout(grp_fu_263_p1)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((1'b1 == ap_CS_fsm_state2) & (icmp_ln39_fu_300_p2 == 1'd1))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_sin_or_cos_double_s_fu_189_ap_start_reg <= 1'b0;
    end else begin
        if ((1'b1 == ap_CS_fsm_state4)) begin
            grp_sin_or_cos_double_s_fu_189_ap_start_reg <= 1'b1;
        end else if ((grp_sin_or_cos_double_s_fu_189_ap_ready == 1'b1)) begin
            grp_sin_or_cos_double_s_fu_189_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_sin_or_cos_double_s_fu_208_ap_start_reg <= 1'b0;
    end else begin
        if ((1'b1 == ap_CS_fsm_state4)) begin
            grp_sin_or_cos_double_s_fu_208_ap_start_reg <= 1'b1;
        end else if ((grp_sin_or_cos_double_s_fu_208_ap_ready == 1'b1)) begin
            grp_sin_or_cos_double_s_fu_208_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state8) & (icmp_ln46_fu_322_p2 == 1'd0))) begin
        a_0_reg_156 <= a_reg_381;
    end else if ((~((ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        a_0_reg_156 <= 32'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state21)) begin
        i_0_reg_179 <= i_3_reg_448;
    end else if ((1'b1 == ap_CS_fsm_state7)) begin
        i_0_reg_179 <= zext_ln39_reg_352;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state8) & (icmp_ln46_fu_322_p2 == 1'd0))) begin
        i_reg_168 <= j_reg_360;
    end else if ((~((ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        i_reg_168 <= 10'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state5) & (1'b0 == ap_block_state5_on_subcall_done))) begin
        a_reg_381 <= grp_fu_227_p2;
        tmp_i_i1_reg_376 <= grp_sin_or_cos_double_s_fu_208_ap_return;
        tmp_i_i_reg_371 <= grp_sin_or_cos_double_s_fu_189_ap_return;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        c_reg_386 <= grp_fu_257_p1;
        s_reg_392 <= grp_fu_260_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state15)) begin
        i_3_reg_448 <= i_3_fu_346_p2;
        sext_ln50_reg_432 <= sext_ln50_fu_340_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        j_reg_360 <= j_fu_306_p2;
        zext_ln39_reg_352[9 : 0] <= zext_ln39_fu_296_p1[9 : 0];
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state16) | (1'b1 == ap_CS_fsm_state9))) begin
        reg_267 <= X_R9_q0;
        reg_274 <= X_I18_q0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state20) | (1'b1 == ap_CS_fsm_state16))) begin
        reg_282 <= grp_fu_227_p2;
        reg_289 <= grp_fu_233_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state8) & (icmp_ln46_fu_322_p2 == 1'd1))) begin
        sext_ln48_reg_400 <= sext_ln48_fu_334_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state20)) begin
        tmp_2_reg_458 <= grp_fu_241_p2;
        tmp_6_reg_453 <= grp_fu_237_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state12)) begin
        tmp_7_reg_416 <= grp_fu_245_p2;
        tmp_8_reg_421 <= grp_fu_249_p2;
        tmp_9_reg_427 <= grp_fu_253_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        x_assign_reg_365 <= grp_fu_263_p1;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state21)) begin
        Out_I_ce0 = 1'b1;
    end else begin
        Out_I_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state21)) begin
        Out_I_ce1 = 1'b1;
    end else begin
        Out_I_ce1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state21)) begin
        Out_I_we0 = 1'b1;
    end else begin
        Out_I_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state21)) begin
        Out_I_we1 = 1'b1;
    end else begin
        Out_I_we1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state21)) begin
        Out_R_ce0 = 1'b1;
    end else begin
        Out_R_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state21)) begin
        Out_R_ce1 = 1'b1;
    end else begin
        Out_R_ce1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state21)) begin
        Out_R_we0 = 1'b1;
    end else begin
        Out_R_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state21)) begin
        Out_R_we1 = 1'b1;
    end else begin
        Out_R_we1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state15)) begin
        X_I18_address0 = sext_ln50_fu_340_p1;
    end else if ((1'b1 == ap_CS_fsm_state8)) begin
        X_I18_address0 = sext_ln48_fu_334_p1;
    end else begin
        X_I18_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state15) | (1'b1 == ap_CS_fsm_state8))) begin
        X_I18_ce0 = 1'b1;
    end else begin
        X_I18_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state15)) begin
        X_R9_address0 = sext_ln50_fu_340_p1;
    end else if ((1'b1 == ap_CS_fsm_state8)) begin
        X_R9_address0 = sext_ln48_fu_334_p1;
    end else begin
        X_R9_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state15) | (1'b1 == ap_CS_fsm_state8))) begin
        X_R9_ce0 = 1'b1;
    end else begin
        X_R9_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state2) & (icmp_ln39_fu_300_p2 == 1'd1))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = ap_done_reg;
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
    if (((1'b1 == ap_CS_fsm_state2) & (icmp_ln39_fu_300_p2 == 1'd1))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state9) | (1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state1) | (1'b1 == ap_CS_fsm_state6) | (1'b1 == ap_CS_fsm_state10) | (1'b1 == ap_CS_fsm_state21) | (1'b1 == ap_CS_fsm_state12) | (1'b1 == ap_CS_fsm_state8) | (1'b1 == ap_CS_fsm_state7) | ((1'b1 == ap_block_state5_on_subcall_done) & (1'b1 == ap_CS_fsm_state5)))) begin
        grp_fu_227_ce = 1'b0;
    end else begin
        grp_fu_227_ce = 1'b1;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state17) | (1'b1 == ap_CS_fsm_state13))) begin
        grp_fu_227_opcode = 2'd1;
    end else if (((icmp_ln39_fu_300_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        grp_fu_227_opcode = 2'd0;
    end else begin
        grp_fu_227_opcode = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state17)) begin
        grp_fu_227_p0 = reg_267;
    end else if ((1'b1 == ap_CS_fsm_state13)) begin
        grp_fu_227_p0 = tmp_7_reg_416;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        grp_fu_227_p0 = a_0_reg_156;
    end else begin
        grp_fu_227_p0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state17)) begin
        grp_fu_227_p1 = reg_282;
    end else if ((1'b1 == ap_CS_fsm_state13)) begin
        grp_fu_227_p1 = tmp_8_reg_421;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        grp_fu_227_p1 = 32'd3150516187;
    end else begin
        grp_fu_227_p1 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state17)) begin
        grp_fu_233_opcode = 2'd1;
    end else if ((1'b1 == ap_CS_fsm_state13)) begin
        grp_fu_233_opcode = 2'd0;
    end else begin
        grp_fu_233_opcode = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state17)) begin
        grp_fu_233_p0 = reg_274;
    end else if ((1'b1 == ap_CS_fsm_state13)) begin
        grp_fu_233_p0 = tmp_9_reg_427;
    end else begin
        grp_fu_233_p0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state17)) begin
        grp_fu_233_p1 = reg_289;
    end else if ((1'b1 == ap_CS_fsm_state13)) begin
        grp_fu_233_p1 = tmp_8_reg_421;
    end else begin
        grp_fu_233_p1 = 'bx;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if ((~((ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((1'b1 == ap_CS_fsm_state2) & (icmp_ln39_fu_300_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            if (((1'b1 == ap_CS_fsm_state5) & (1'b0 == ap_block_state5_on_subcall_done))) begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end
        end
        ap_ST_fsm_state6 : begin
            ap_NS_fsm = ap_ST_fsm_state7;
        end
        ap_ST_fsm_state7 : begin
            ap_NS_fsm = ap_ST_fsm_state8;
        end
        ap_ST_fsm_state8 : begin
            if (((1'b1 == ap_CS_fsm_state8) & (icmp_ln46_fu_322_p2 == 1'd0))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state9;
            end
        end
        ap_ST_fsm_state9 : begin
            ap_NS_fsm = ap_ST_fsm_state10;
        end
        ap_ST_fsm_state10 : begin
            ap_NS_fsm = ap_ST_fsm_state11;
        end
        ap_ST_fsm_state11 : begin
            ap_NS_fsm = ap_ST_fsm_state12;
        end
        ap_ST_fsm_state12 : begin
            ap_NS_fsm = ap_ST_fsm_state13;
        end
        ap_ST_fsm_state13 : begin
            ap_NS_fsm = ap_ST_fsm_state14;
        end
        ap_ST_fsm_state14 : begin
            ap_NS_fsm = ap_ST_fsm_state15;
        end
        ap_ST_fsm_state15 : begin
            ap_NS_fsm = ap_ST_fsm_state16;
        end
        ap_ST_fsm_state16 : begin
            ap_NS_fsm = ap_ST_fsm_state17;
        end
        ap_ST_fsm_state17 : begin
            ap_NS_fsm = ap_ST_fsm_state18;
        end
        ap_ST_fsm_state18 : begin
            ap_NS_fsm = ap_ST_fsm_state19;
        end
        ap_ST_fsm_state19 : begin
            ap_NS_fsm = ap_ST_fsm_state20;
        end
        ap_ST_fsm_state20 : begin
            ap_NS_fsm = ap_ST_fsm_state21;
        end
        ap_ST_fsm_state21 : begin
            ap_NS_fsm = ap_ST_fsm_state8;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign Out_I_address0 = sext_ln48_reg_400;

assign Out_I_address1 = sext_ln50_reg_432;

assign Out_I_d0 = reg_289;

assign Out_I_d1 = tmp_2_reg_458;

assign Out_R_address0 = sext_ln48_reg_400;

assign Out_R_address1 = sext_ln50_reg_432;

assign Out_R_d0 = reg_282;

assign Out_R_d1 = tmp_6_reg_453;

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state10 = ap_CS_fsm[32'd9];

assign ap_CS_fsm_state11 = ap_CS_fsm[32'd10];

assign ap_CS_fsm_state12 = ap_CS_fsm[32'd11];

assign ap_CS_fsm_state13 = ap_CS_fsm[32'd12];

assign ap_CS_fsm_state15 = ap_CS_fsm[32'd14];

assign ap_CS_fsm_state16 = ap_CS_fsm[32'd15];

assign ap_CS_fsm_state17 = ap_CS_fsm[32'd16];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state20 = ap_CS_fsm[32'd19];

assign ap_CS_fsm_state21 = ap_CS_fsm[32'd20];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

assign ap_CS_fsm_state7 = ap_CS_fsm[32'd6];

assign ap_CS_fsm_state8 = ap_CS_fsm[32'd7];

assign ap_CS_fsm_state9 = ap_CS_fsm[32'd8];

always @ (*) begin
    ap_block_state1 = ((ap_done_reg == 1'b1) | (ap_start == 1'b0));
end

always @ (*) begin
    ap_block_state5_on_subcall_done = ((grp_sin_or_cos_double_s_fu_208_ap_done == 1'b0) | (grp_sin_or_cos_double_s_fu_189_ap_done == 1'b0));
end

assign grp_sin_or_cos_double_s_fu_189_ap_start = grp_sin_or_cos_double_s_fu_189_ap_start_reg;

assign grp_sin_or_cos_double_s_fu_189_do_cos = 1'd1;

assign grp_sin_or_cos_double_s_fu_208_ap_start = grp_sin_or_cos_double_s_fu_208_ap_start_reg;

assign grp_sin_or_cos_double_s_fu_208_do_cos = 1'd0;

assign i_3_fu_346_p2 = ($signed(i_0_reg_179) + $signed(32'd1024));

assign i_lower_fu_328_p2 = ($signed(i_0_reg_179) + $signed(32'd512));

assign icmp_ln39_fu_300_p2 = ((i_reg_168 == 10'd512) ? 1'b1 : 1'b0);

assign icmp_ln46_fu_322_p2 = (($signed(tmp_11_fu_312_p4) < $signed(22'd1)) ? 1'b1 : 1'b0);

assign j_fu_306_p2 = (i_reg_168 + 10'd1);

assign sext_ln48_fu_334_p1 = $signed(i_lower_fu_328_p2);

assign sext_ln50_fu_340_p1 = i_0_reg_179;

assign tmp_11_fu_312_p4 = {{i_0_reg_179[31:10]}};

assign zext_ln39_fu_296_p1 = i_reg_168;

always @ (posedge ap_clk) begin
    zext_ln39_reg_352[31:10] <= 22'b0000000000000000000000;
end

endmodule //fft_stage86

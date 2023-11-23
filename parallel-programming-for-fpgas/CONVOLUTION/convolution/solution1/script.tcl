############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project convolution
set_top convolution
add_files 6.double_buffer/convolution.cpp
open_solution "solution1"
set_part {xc7vx485tffg1157-1}
create_clock -period 10 -name default
#source "./convolution/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog

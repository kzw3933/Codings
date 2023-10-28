############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project fft
set_top fft
add_files 2.streamlining_tasks/fft.cpp
add_files 2.streamlining_tasks/fft.h
open_solution "solution1"
set_part {xc7vx485tffg1157-1}
create_clock -period 10 -name default
#source "./fft/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog

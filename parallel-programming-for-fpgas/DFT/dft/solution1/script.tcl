############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project dft
set_top dft
add_files 2.data_partitioning/dft.cpp
add_files dft.h
open_solution "solution1"
set_part {xc7vx485tffg1157-1}
create_clock -period 10 -name default
#source "./dft/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog

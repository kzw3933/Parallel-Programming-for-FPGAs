############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project fir
set_top fir
add_files 5.loop_pipelining/fir.cpp
add_files fir.h
add_files input.dat
add_files out.gold.dat
add_files -tb fir_test.cpp
open_solution "solution1"
set_part {xc7vx485tffg1157-1}
create_clock -period 10 -name default
#source "./fir/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog

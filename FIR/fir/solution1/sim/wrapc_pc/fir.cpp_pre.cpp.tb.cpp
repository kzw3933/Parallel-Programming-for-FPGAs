// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "C:/Users/Administrator/Desktop/Parallel-Programming-for-FPGAs/FIR/baseline/fir.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "C:/Users/Administrator/Desktop/Parallel-Programming-for-FPGAs/FIR/baseline/fir.cpp"
# 1 "C:/Users/Administrator/Desktop/Parallel-Programming-for-FPGAs/FIR/baseline/fir.h" 1





const int N = 11;

typedef int coef_t;
typedef int data_t;
typedef int acc_t;


void fir(data_t *y, data_t x);
# 2 "C:/Users/Administrator/Desktop/Parallel-Programming-for-FPGAs/FIR/baseline/fir.cpp" 2

void fir(data_t *y, data_t x) {
    coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
    static data_t shift_reg[N];

    acc_t acc;
    int i;
    acc = 0;

    Shift_Accum_Loop:
        for(i = N - 1; i >= 0; i--) {
            if(i == 0) {
                acc += x * c[0];
                shift_reg[0] = x;
            } else {
                shift_reg[i] = shift_reg[i-1];
                acc += shift_reg[i] * c[i];
            }
        }

    *y = acc;
}
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
void apatb_fir_ir(int *, int);
#ifdef __cplusplus
extern "C"
#endif
void fir_hw_stub(int *y, int x){
fir(y, x);
return ;
}
#ifdef __cplusplus
extern "C"
#endif
void apatb_fir_sw(int *y, int x){
apatb_fir_ir(y, x);
return ;
}
#endif
# 23 "C:/Users/Administrator/Desktop/Parallel-Programming-for-FPGAs/FIR/baseline/fir.cpp"


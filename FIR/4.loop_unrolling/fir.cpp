// 循环展开
#include "../fir.h"

void fir(data_t *y, data_t x) {
    INIT:
    coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
    static data_t shift_reg[N];

    acc_t acc;
    int i;

    TDL:
     for(i = N-1; i > 1; i--) {
     #pragma HLS unroll factor=2
         shift_reg[i] = shift_reg[i-1];
     }
//
//    for(i = N-1; i > 1; i = i - 2) {
//        shift_reg[i] = shift_reg[i-1];
//        shift_reg[i-1] = shift_reg[i-2];
//    }
    if(i == 1) {
        shift_reg[1] = shift_reg[0];
    }
    shift_reg[0] = x;

    acc = 0;

    MAC:
     for(i = N - 1; i >= 3; i --) {
     #pragma HLS unroll factor=4
         acc += shift_reg[i] * c[i];
     }
//    for(i = N - 1; i >= 3; i -= 4) {
//        acc += shift_reg[i] * c[i]
//                + shift_reg[i-1] * c[i-1]
//                + shift_reg[i-2] * c[i-2]
//                + shift_reg[i-3] * c[i-3];
//    }
    for(; i >= 0; i--) {
        acc += shift_reg[i] * c[i];
    }
    
    *y = acc;
}

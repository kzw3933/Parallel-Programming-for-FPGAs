# 1 "C:/Users/Administrator/Desktop/Parallel-Programming-for-FPGAs/FIR/5.loop_pipelining/fir.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "C:/Users/Administrator/Desktop/Parallel-Programming-for-FPGAs/FIR/5.loop_pipelining/fir.cpp"
# 1 "C:/Users/Administrator/Desktop/Parallel-Programming-for-FPGAs/FIR/fir.h" 1





const int N = 11;

typedef int coef_t;
typedef int data_t;
typedef int acc_t;


void fir(data_t *y, data_t x);
# 2 "C:/Users/Administrator/Desktop/Parallel-Programming-for-FPGAs/FIR/5.loop_pipelining/fir.cpp" 2

void fir(data_t *y, data_t x) {
    INIT:
    coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
    static data_t shift_reg[N];

    acc_t acc;
    int i;

    TDL:
    for(i = N-1; i > 0; i--) {
#pragma HLS pipeline II=1
        shift_reg[i] = shift_reg[i-1];
    }
    shift_reg[0] = x;

    acc = 0;

    MAC:
    for(i = N - 1; i >= 0; i--) {
#pragma HLS pipeline II=1
        acc += shift_reg[i] * c[i];
    }

    *y = acc;
}

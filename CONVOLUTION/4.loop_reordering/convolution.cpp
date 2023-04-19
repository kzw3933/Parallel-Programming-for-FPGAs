#define CHin 4
#define CHout 4
#define R 14
#define C 14
#define Rin 16
#define Cin 16
#define K 3

void convolution() {
    float In[CHin][Rin][Cin];
    #pragma HLS array_partition variable=In complete dim=1
    float Out[CHout][R][C];
    #pragma HLS array_partition variable=Out complete dim=1
    float W[CHout][CHin][K][K];
    #pragma HLS array_partition variable=W complete dim=1
    #pragma HLS array_partition variable=W complete dim=2

    Kernel_Row:
    for(int kr = 0; kr < K; kr++) {
        Kernel_Column:
        for(int kc = 0; kc < K; kc++) {
            Row:
            for(int r = 0; r < R; r++) {
                Column:
                for(int c = 0; c < C; c++) {
                    #pragma HLS PIPELINE
                    Output_Channel:
                    for(int cho = 0; cho < CHout; cho++) {
                        Input_Channel:
                        for(int chi = 0; chi < CHin; chi++) {
                            Out[cho][r][c] += In[chi][r+kr][c+kc] * W[cho][chi][kr][kc];
                        }
                    }
                }
            }
        }
    }
}

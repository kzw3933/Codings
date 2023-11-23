#include "fft.h"

unsigned int reverse_bits(unsigned int input) {
    int i, rev = 0;
    for(i = 0; i < FFT_BITS; i++) {
        rev = (rev << 1) | (input & 1);
        input = input >> 1;
    }
    return rev;
}


void bit_reverse(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE O_R[SIZE], DTYPE O_I[SIZE]) {
    unsigned int reversed;
    unsigned int i;

    for(i = 0; i < SIZE; i++) {
        reversed = reverse_bits(i);
        if( i < reversed) {
            O_R[i] = X_R[reversed];
            O_R[reversed] = X_R[i];

            O_I[i] = X_I[reversed];
            O_I[reversed] = X_I[i];
        }
    }
}

void fft_stage(int stage, DTYPE X_R[SIZE], DTYPE X_I[SIZE],
                DTYPE Out_R[SIZE], DTYPE Out_I[SIZE]) {
    int DFTpts = 1 << stage;
    int numBF = DFTpts / 2;
    int step = SIZE >> stage;
    DTYPE k = 0;
    DTYPE e = -6.283185307178 / DFTpts;
    DTYPE a = 0.0;

    butterfly_loop:
    for(int j = 0; j < numBF; j++) {
        DTYPE c = cos(a);
        DTYPE s = sin(a);

        a += e;

        dft_loop:
        for(int i = j; i < SIZE; i += DFTpts) {
            int i_lower = i + numBF;
            DTYPE temp_R = X_R[i_lower] * c - X_I[i_lower] * s;
            DTYPE temp_I = X_I[i_lower] * c + X_I[i_lower] * s;
            Out_R[i_lower] = X_R[i] - temp_R;
            Out_I[i_lower] = X_I[i] - temp_I;
            Out_R[i] = X_R[i] + temp_R;
            Out_I[i] = X_I[i] + temp_I;
        }

        k += step;
    }
}

void fft(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
    #pragma HLS dataflow
    DTYPE Stage_R[M][SIZE], Stage_I[M][SIZE];
    
    #pragma HLS array partition variable=Stage_R dim=1 complete
    #pragma HLS array partition variable=Stage_I dim=1 complete

    bit_reverse(X_R, X_I, Stage_R[0], Stage_I[0]);

    stage_loop:
    for (int stage = 1; stage < M; stage++){ // Do Mâˆ?1 stages of butterflies
        #pragma HLS unroll
        fft_stage(stage, Stage_R[stage-1], Stage_I[stage-1], Stage_R[stage], Stage_I[stage]);
    }
    fft_stage(M, Stage_R[M-1], Stage_I[M-1], OUT_R, OUT_I);
}

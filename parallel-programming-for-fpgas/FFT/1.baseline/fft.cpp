#include "fft.h"

unsigned int reverse_bits(unsigned int input) {
    int i, rev = 0;
    for(i = 0; i < FFT_BITS; i++) {
        rev = (rev << 1) | (input & 1);
        input = input >> 1;
    }
    return rev;
}


void bit_reverse(DTYPE X_R[SIZE], DTYPE X_I[SIZE]) {
    unsigned int reversed;
    unsigned int i;
    DTYPE temp;

    for(i = 0; i < SIZE; i++) {
        reversed = reverse_bits(i);
        if( i < reversed) {
            temp = X_R[i];
            X_R[i] = X_R[reversed];
            X_R[reversed] = temp;

            temp = X_I[i];
            X_I[i] = X_I[reversed];
            X_I[reversed] = temp;
        }
    }
}


void fft(DTYPE X_R[SIZE], DTYPE X_I[SIZE]) {
    DTYPE temp_R;
    DTYPE temp_I;
    int i, j, k;
    int i_lower;
    int step, stage, DFTpts;
    int numBF; // Butterfly width
    int N2 = SIZE2; // N2 = N >> 1

    bit_reverse(X_R, X_I);

    step = N2;
    DTYPE a, e, c, s;

    stage_loop:
    for(stage = 1; stage <= M; stage++) {
        DFTpts = 1 << stage;
        numBF = DFTpts / 2;
        k = 0;
        e = -6.283185307178 / DFTpts;
        a = 0.0;

        butterfly_loop:
        for(j = 0; j < numBF; j++) {
            c = cos(a);
            s = sin(a);
            a = a + e;

            dft_loop:
            for(i = j; i < SIZE; i += DFTpts) {
                i_lower = i + numBF;
                temp_R = X_R[i_lower] * c - X_I[i_lower] * s;
                temp_I = X_I[i_lower] * c + X_R[i_lower] * s;
                X_R[i_lower] = X_R[i] - temp_R;
                X_I[i_lower] = X_I[i] - temp_I;
                X_R[i] = X_R[i] + temp_R;
                X_I[i] = X_I[i] + temp_I;
            }
            k += step;
        }
        step = step / 2;
    }
}

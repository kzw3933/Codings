#ifndef FFT_H
#define FFT_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef float DTYPE;

#define M 10 /* Number of Stages = LogN */
#define SIZE 1024
#define SIZE2 (SIZE >> 1)

#define FFT_BITS 10

void fft(DTYPE X_R[SIZE], DTYPE X_I[SIZE]);




#endif /* FFT_H */

#ifndef DFT_H
#define DFT_H

#include <math.h>

typedef double IN_TYPE;
typedef double TEMP_TYPE;

#define N 8

void dft(IN_TYPE sample_real[N], IN_TYPE sample_imag[N]);

#endif /* DFT_H */
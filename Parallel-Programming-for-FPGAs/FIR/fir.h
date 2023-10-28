#ifndef FIR_H
#define FIR_H



const int N = 11;

typedef int coef_t;
typedef int data_t;
typedef int acc_t;


void fir(data_t *y, data_t x);

#endif /* FIR_H */
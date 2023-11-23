// 循环拆分
#include "../fir.h"

void fir(data_t *y, data_t x) {
    INIT:
    coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
    static data_t shift_reg[N];

    acc_t acc;
    int i;

    TDL:
    for(i = N-1; i > 0; i--) {
        shift_reg[i] = shift_reg[i-1];
    }
    shift_reg[0] = x;

    acc = 0;

    MAC:
    for(i = N - 1; i >= 0; i--) {
        acc += shift_reg[i] * c[i];
    }
    
    *y = acc;
}
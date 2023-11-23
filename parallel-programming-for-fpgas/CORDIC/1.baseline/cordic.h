#ifndef CORDIC_H
#define CORDIC_H

#include <ap_fixed.h>

#define NUM_ITERATIONS 16

typedef ap_fixed<17,3> COS_SIN_TYPE;
typedef ap_fixed<16,2> THETA_TYPE;

void cordic(COS_SIN_TYPE theta, COS_SIN_TYPE &s, COS_SIN_TYPE &c);

#endif /* CORDIC_H */
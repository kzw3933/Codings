#include "cordic.h"

THETA_TYPE cordic_phase[NUM_ITERATIONS] = {
    45.0, 26.565, 14.036, 7.125,
    3.576, 1.789, 0.895, 0.448,
    0.224, 0.112, 0.056, 0.028,
    0.014, 0.007, 0.004, 0.002
};


void cordic(COS_SIN_TYPE theta, COS_SIN_TYPE &s, COS_SIN_TYPE &c) {
    COS_SIN_TYPE current_cos =0.60735;
    COS_SIN_TYPE current_sin = 0.0;

    COS_SIN_TYPE factor = 1.0;

    for(int j = 0; j < NUM_ITERATIONS; j++){

        int sigma = (theta < 0) ? -1 : 1;

        COS_SIN_TYPE temp_cos = current_cos;

        current_cos = current_cos - current_sin * sigma * factor;
        current_sin = temp_cos * sigma * factor + current_sin;

        theta = theta - sigma * cordic_phase[j];

        factor = factor >> 1;
    }

    s = current_sin;
    c = current_cos;

}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "fir.h"


int main() {
    const int SAMPLES = 600;
    FILE *fp, *fin;

    data_t signal, output;
    int i;
    signal = 0;

    fin = fopen("input.dat", "r");
    fp = fopen("out.dat", "w");

    for(i = 0; i < SAMPLES; i++) {
    	fscanf(fin, "%d\n", &signal);
        fir(&output, signal);
        fprintf(fp, "%d\n", output);
        printf("%i %d %d\n", i, signal, output);
    }

    fclose(fp);
    fclose(fin);

    printf("Comparing against output data \n");
    if(system("diff -w out.dat out.gold.dat")) {
        fprintf(stdout, "*********************************************\n");
        fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
        fprintf(stdout, "*********************************************\n");
        return 1;
    } else {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "PASS: The output matches the golden output!\n");
        fprintf(stdout, "*******************************************\n");
        return 0;
    }
    return 0;

}

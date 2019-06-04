//OpenMP version.  Edit and submit only this file.
/* Enter your details below
 * Name : Esther Li
 * UCLA ID : 604892225
 * Email : li.esther2000@gmail.com
 */

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#include "utils.h"

void work_it_par(long *old, long *new) {
    int i, j, k;
    int u;
    long compute_it, sum;
    long aggregate = 1.0;
    long sum0 = 0.0;
    long sum1 = 0.0;
    long sum2 = 0.0;
    long sum3 = 0.0;
    long sum4 = 0.0;
    long sum5 = 0.0;
    long sum6 = 0.0;
    long sum7 = 0.0;
    long sum8 = 0.0;
    long sum9 = 0.0;
    const long a = we_need_the_func();
    const long b = gimmie_the_func();
    
#pragma omp num_threads(16)
#pragma omp parallel for shared(old, new) private(i, j, k, compute_it, u) reduction\
(+:aggregate, sum, sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9)
    for (i = 1; i < DIM - 1; i++) {
        for (j = 1; j<DIM - 1; j++) {
            for (k = 1; k < DIM - 1; k++) {
                compute_it = old[i*DIM*DIM+j*DIM+k] * a / b;
                aggregate += compute_it;
                sum = 0.0;
                for (u=-1; u<=1; u++) {
                    sum+=old[(i+u)*DIM*DIM+(j-1)*DIM+(k-1)];
                    sum+=old[(i+u)*DIM*DIM+(j-1)*DIM+(k)];
                    sum+=old[(i+u)*DIM*DIM+(j-1)*DIM+(k+1)];
                    sum+=old[(i+u)*DIM*DIM+(j)*DIM+(k-1)];
                    sum+=old[(i+u)*DIM*DIM+(j)*DIM+(k)];
                    sum+=old[(i+u)*DIM*DIM+(j)*DIM+(k+1)];
                    sum+=old[(i+u)*DIM*DIM+(j+1)*DIM+(k-1)];
                    sum+=old[(i+u)*DIM*DIM+(j+1)*DIM+(k)];
                    sum+=old[(i+u)*DIM*DIM+(j+1)*DIM+(k+1)];
                }
                sum /= 27;
                new[i*DIM*DIM+j*DIM+k] = sum;
                u = sum/100;
                if (u<=0) sum0++;
                else if (u == 1) sum1++;
                else if (u == 2) sum2++;
                else if (u == 3) sum3++;
                else if (u == 4) sum4++;
                else if (u == 5) sum5++;
                else if (u == 6) sum6++;
                else if (u == 7) sum7++;
                else if (u == 8) sum8++;
                else if (u>=9) sum9++;
            }
        }
    }
    histogrammy[0] += sum0;
    histogrammy[1] += sum1;
    histogrammy[2] += sum2;
    histogrammy[3] += sum3;
    histogrammy[4] += sum4;
    histogrammy[5] += sum5;
    histogrammy[6] += sum6;
    histogrammy[7] += sum7;
    histogrammy[8] += sum8;
    histogrammy[9] += sum9;
    printf("AGGR:%ld\n",aggregate);
}




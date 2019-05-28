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
    int u, v, w;
    long compute_it, sum;
    long aggregate=1.0;
    
    
    
#pragma omp parallel for firstprivate(old, new) private(i, j, k, compute_it, u, v, w) reduction (+:aggregate, sum)
    for (i=1; i<DIM-1; i++) {
        for (j=1; j<DIM-1; j++) {
            for (k=1; k<DIM-1; k++) {
                compute_it = old[i*DIM*DIM+j*DIM+k] * we_need_the_func() / gimmie_the_func();
                aggregate += compute_it;
                sum = 0.0;
                for (u=-1; u<=1; u++) {
                    for (v=-1; v<=1; v++) {
                        for (w=-1; w<=1; w++) {
                            sum+=old[(i+u)*DIM*DIM+(j+v)*DIM+(k+w)];
                        }
                    }
                }
                new[i*DIM*DIM+j*DIM+k]=sum/27;
            }
        }
    }
    
    printf("AGGR:%ld\n",aggregate);
    
    /*
     #pragma omp parallel for firstprivate(new, old) private(i, j, k) reduction (+:sum)
     for (i=1; i<DIM-1; i++) {
     for (j=1; j<DIM-1; j++) {
     for (k=1; k<DIM-1; k++) {
     sum = 0.0;
     sum+=old[(i-1)*DIM*DIM+(j-1)*DIM+(k-1)];
     sum+=old[(i-1)*DIM*DIM+(j-1)*DIM+(k)];
     sum+=old[(i-1)*DIM*DIM+(j-1)*DIM+(k+1)];
     sum+=old[(i-1)*DIM*DIM+(j)*DIM+(k-1)];
     sum+=old[(i-1)*DIM*DIM+(j)*DIM+(k)];
     sum+=old[(i-1)*DIM*DIM+(j)*DIM+(k+1)];
     sum+=old[(i-1)*DIM*DIM+(j+1)*DIM+(k-1)];
     sum+=old[(i-1)*DIM*DIM+(j+1)*DIM+(k)];
     sum+=old[(i-1)*DIM*DIM+(j+1)*DIM+(k+1)];
     sum+=old[(i)*DIM*DIM+(j-1)*DIM+(k-1)];
     sum+=old[(i)*DIM*DIM+(j-1)*DIM+(k)];
     sum+=old[(i)*DIM*DIM+(j-1)*DIM+(k+1)];
     sum+=old[(i)*DIM*DIM+(j)*DIM+(k-1)];
     sum+=old[(i)*DIM*DIM+(j)*DIM+(k)];
     sum+=old[(i)*DIM*DIM+(j)*DIM+(k+1)];
     sum+=old[(i)*DIM*DIM+(j+1)*DIM+(k-1)];
     sum+=old[(i)*DIM*DIM+(j+1)*DIM+(k)];
     sum+=old[(i)*DIM*DIM+(j+1)*DIM+(k+1)];
     sum+=old[(i+1)*DIM*DIM+(j-1)*DIM+(k-1)];
     sum+=old[(i+1)*DIM*DIM+(j-1)*DIM+(k)];
     sum+=old[(i+1)*DIM*DIM+(j-1)*DIM+(k+1)];
     sum+=old[(i+1)*DIM*DIM+(j)*DIM+(k-1)];
     sum+=old[(i+1)*DIM*DIM+(j)*DIM+(k)];
     sum+=old[(i+1)*DIM*DIM+(j)*DIM+(k+1)];
     sum+=old[(i+1)*DIM*DIM+(j+1)*DIM+(k-1)];
     sum+=old[(i+1)*DIM*DIM+(j+1)*DIM+(k)];
     sum+=old[(i+1)*DIM*DIM+(j+1)*DIM+(k+1)];
     sum/=27;
     new[i*DIM*DIM+j*DIM+k] = sum;
     }
     }
     }
     */
    
    /*
     #pragma omp parallel for firstprivate(new, old) private(i, j, k, u, v, w) reduction(+:sum)
     for (i=1; i<DIM-1; i++) {
     for (j=1; j<DIM-1; j++) {
     for (k=1; k<DIM-1; k++) {
     
     }
     }
     }
     
     */
    
#pragma omp parallel for firstprivate(new, histogrammy) private(u, i, j, k)
    for (i=1; i<DIM-1; i++) {
        for (j=1; j<DIM-1; j++) {
            for (k=1; k<DIM-1; k++) {
                u=(new[i*DIM*DIM+j*DIM+k]/100);
                if (u<=0) u=0;
                if (u>=9) u=9;
                histogrammy[u]++;
            }
        }
    }
}


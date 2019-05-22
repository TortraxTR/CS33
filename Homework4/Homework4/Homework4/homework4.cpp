#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


#define N 1024
using namespace std;

void transpose(int *dst, int *src, int dim) {
	int i, j, k, m;
	for (i = 0; i < dim; i += 12) 
		for (j = 0; j < dim; j += 12) 
			for (k = i; (k < i + 12) & (k < dim); k++)
				for (m = j; (m < j + 12) & (m < dim); m++)
					dst[m + k * dim] = src[k + m * dim];

	for (; i < dim; i++)
		for (j = 0; j < dim; j++)
			dst[j * dim + i] = src[i * dim + j];
}


double test_transpose()
{
	int i, j;
	// 为dest分配内存
	int *dest = (int *)malloc(N * N * sizeof(int));
	// 为source分配内存,并初始化
	int *source = (int *)malloc(N * N * sizeof(int));
	for (i = 0; i < N; i++) {
		int num = i % 2;
		for (j = 0; j < N; j++)
			source[i*N + j] = num;
	}

	clock_t start;
	clock_t end;
	start = clock();
	for (int i = 0; i < 10000; i++)
		transpose(dest, source, N);
	end = clock();

	// 释放dest, source内存
	free(dest);
	free(source);

	return difftime(end, start) / CLOCKS_PER_SEC;
}

int main(void)
{
	double results[20];

	for (int j = 8; j < 13; j++) {
		cout << test_transpose(j) << endl;
	}
}
#include <stdio.h>
#include <omp.h>

#define N 5

void matrix_multiply (int A[N][N], int B[N][N], int C[N][N]) {
	int i, j, k;
	#pragma omp parallel for private(i, j, k) shared(A, B, C)
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

int main() {
	int A[N][N];
	int B[N][N];
	int C[N][N]; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = i + j;
			B[i][j] = i - j;
		}
	}
	matrix_multiply(A, B, C);
	printf("Resultant matrix C:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	return 0;
}


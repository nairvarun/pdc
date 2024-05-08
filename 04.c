#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 1000

void matrix_multiply (int (*A)[N][N], int (*B)[N][N], int (*C)[N][N]) {
	int num_devices = omp_get_num_devices();
	printf("Number of available devices %d\n", num_devices);
	int i, j, k;

	#pragma target 
	{
		if (omp_is_initial_device()) {
			printf("Running on host\n");
		} else {
			int nteams= omp_get_num_teams();
			int nthreads= omp_get_num_threads();
			printf("Running on device with %d teams in total and %d threads in each team\n",nteams,nthreads);
		}

		#pragma omp parallel for private(i, j, k) shared(A, B, C)
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				for (k = 0; k < N; k++) {
					(*C)[i][j] += (*A)[i][k] * (*B)[k][j];
				}
			}
		}
	}
}

int main() {
	int (*A)[N][N] = malloc(sizeof *A);
	int (*B)[N][N] = malloc(sizeof *B);
	int (*C)[N][N] = malloc(sizeof *C);

	// int A[N][N];
	// int B[N][N];
	// int C[N][N]; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			(*A)[i][j] = i + j;
			(*B)[i][j] = i - j;
		}
	}
	matrix_multiply(A, B, C);
	printf("Resultant matrix C:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", (*C)[i][j]);
		}
		printf("\n");
	}
	return 0;
}


/*
 * Name: Varun Nair
 * Reg. No.: 21BCE10090
 */

#include<stdio.h>
#include<omp.h>

#define ARRAY_SIZE 8
#define NUM_THREADS 4

int main (int argc, char *argv[]) {
	int n = ARRAY_SIZE;
	int total_threads = NUM_THREADS;

	int vec1[n], vec2[n];
	int result;

	printf("(i)\tvec1[i]\tvec2[i]\n");
	for(int i=0; i<n; i++) {
		vec1[i] = i;
		vec2[i] = i;
		printf(" %d\t  %d\t  %d\n", i, vec1[i], vec2[i]);
	}

	omp_set_num_threads(total_threads);

	int i;
	#pragma omp parallel for shared(vec1, vec2) private(i)
	for(int i=0; i<n; i++) {
		#pragma omp critical
		result += vec1[i] * vec2[i];
	}
	printf("\nresult: %d\n", result);

	return 0;
}

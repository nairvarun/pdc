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

	int vec1[n], vec2[n], result[n];

	for(int i=0; i<n; i++) {
		vec1[i] = i;
		vec2[i] = i;
	}

	omp_set_num_threads(total_threads);

	int i;
	#pragma omp parallel for shared(vec1, vec2, result) private(i)
	for(int i=0; i<n; i++) {
		result[i] = vec1[i] + vec2[i];
	}

	printf("(i)\tvec1[i]\tvec2[i]\tresult[i]\n");
	for(int i=0; i<n; i++) {
		printf(" %d\t  %d\t  %d\t   %d\n", i, vec1[i], vec2[i], result[i]);
	}

	return 0;
}

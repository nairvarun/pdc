#include<stdio.h>
#include<omp.h>

#define NUM_THREADS 10
int main() {
	int n = NUM_THREADS;
	#pragma omp parallel num_threads(n)
	{
		int ID = omp_get_thread_num();
		printf("hello from thread %d/%d\n", ID, n);
	}
	return 0;
}

#include<stdio.h>
#include<omp.h>

void funcA() {
	int ID = omp_get_thread_num();
	printf("Executing funcA (thread %d)\n", ID);
}

void funcB() {
	int ID = omp_get_thread_num();
	printf("Executing funcB (thread %d)\n", ID);
}

void funcC() {
	int ID = omp_get_thread_num();
	printf("Executing funcC (thread %d)\n", ID);
}

int main() {
	int num_threads;
	#pragma omp parallel sections
	{
		num_threads = omp_get_num_threads();
		#pragma omp section
		funcA();
		#pragma omp section
		funcB();
		#pragma omp section
		funcC();
	}
	printf("totoal threads: %d\n", num_threads);
}


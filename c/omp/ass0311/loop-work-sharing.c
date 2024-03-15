#include<stdio.h>
#include<omp.h>

#define NUM_THREADS 8

void func() {
    int ID = omp_get_thread_num();
    printf("Executing func() (thread %d)\n", ID);
}

int main() {
		int n = NUM_THREADS;
		int num_threads;
    #pragma omp parallel for num_threads(n) 
    for (int i = 0; i < 10; i++) {
        func();
    }
		printf("totoal threads: %d\n", n);
}


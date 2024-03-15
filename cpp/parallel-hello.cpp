#include <iostream>
#include <stdio.h>
#include <omp.h>

int main() {
    const int n = 5;

    #pragma omp parallel num_threads(4)
    {
        int ID = omp_get_thread_num();
        int numThreads = omp_get_num_threads();

        #pragma omp for
        for (int i = 0; i < n; ++i) {
						printf("Hello, World! (Thread %d/%d)\n", ID, n);

        }
    }

    return 0;
}


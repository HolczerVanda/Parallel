#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <pthread.h>

int main() {
    
    int num_threads = 60;
    double start = omp_get_wtime();

    #pragma omp parallel num_threads(num_threads)
    {
        double threadStart = omp_get_wtime();
        while(omp_get_wtime() - threadStart < 1)
        {
            for(int i = 0; i < 5000000; i++)
            {
                int j = i * j;
            }
        }
    }

    double end = omp_get_wtime();
    
    double elapsedTime = end - start;
    printf("Elapsed time: %f sec\n", elapsedTime);

    return 0;
}
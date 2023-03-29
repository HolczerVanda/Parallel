#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void calculateTime();

int main() {

    calculateTime();
    
    return 0;
}

void calculateTime()
{
    int i;
    long n = 1e8;
    double* randNums;
    randNums = (double*) malloc(n * sizeof(double));
    double sum=1;
    
    
    srand(time(0));

    clock_t begin = clock();
    printf("\nGenerate numbers\n");
    for( i = 0; i < n; i++)
    {
        randNums[i]=(double) rand()/RAND_MAX;
    }
    printf("Multiplying\n");
    for ( i = 0; i < n; i++)
    {
        sum *= randNums[i];
    }
    printf("\nSum: %f", sum);
    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %f", timeSpent);
}
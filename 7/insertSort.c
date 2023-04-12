#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertSort(int array[], int n)
{
    clock_t begin = clock();

    for(int j = 1; j < n; j++)
    {
        int key = array[j];
        int i = j - 1;
        while(i >= 0 && array[i] > key)
        {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }

    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed time: %lf\n", timeSpent);
}

int main() {
    int n = 1e5;
    srand(time(NULL));

    for (int i = 1e4; i < n; i)
    {
        i+=5000;
        int* array = (int*) malloc(n*sizeof(int));

        for(int i = 0; i < n; i++)
        {
            array[i] = rand() % 1001;
        }

        printf("%d element:", i);
        insertSort(array, i);
    }
    
    return 0;
}
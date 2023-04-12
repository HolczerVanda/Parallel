#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sequential(int array[], int n)
{
    clock_t begin = clock();

    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        if(array[i] != array[minIndex])
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
    
    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed time with sequential: %lf\n", timeSpent);
}

void recursive(int array[], int n, int index)
{
    clock_t begin = clock();

    if(index > n)
    {
        clock_t end = clock();
        double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("              Elapsed time with recursive: %lf\n", timeSpent);

        return;
    }

    int minIndex = index;

    for(int i = index + 1; i < n; i++)
    {
        if(array[i] < array[minIndex])
            minIndex = i;
    }

    if(array[index] != array[minIndex])
    {
        int temp = array[index];
        array[index] = array[minIndex];
        array[minIndex] = temp;
    }

    recursive(array, n, index + 1);
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
        sequential(array, i);
        recursive(array, i, 1);
    }
    
    return 0;
}
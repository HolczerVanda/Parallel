#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sequentialMergeSort.h"

int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        printf("Incorrect number of command line arguments!\n");
        return 1;
    }

    int N = atoi(argv[1]);
    int maxRecDepth = atoi(argv[2]);

    float *array;
    array = (float *)malloc(N * sizeof(float));

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {   
        array[i] = ((float) rand()) / RAND_MAX;
    }

    clock_t begin = clock();

    mergeSort(array, 0, N-1, 0, maxRecDepth);

    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed time: %lf\n", timeSpent);

    free(array);
    
    return 0;
}

void merge(float array[], int left, int middle, int right)
{
    int i, j, k;
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int tempLeft[leftSize], tempRight[rightSize];
    for(i = 0; i < leftSize; i++)
        tempLeft[i] = array[left + i];
    for(j = 0; j < rightSize; j++)
        tempRight[j] = array[middle + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while(i < leftSize && j < rightSize)
    {
        if(tempLeft[i] <= tempRight[j])
        {
            array[k] = tempLeft[i];
            i++;
        } 
        else
        {
            array[k] = tempRight[j];
            j++;
        }
        k++;
    }
    while(i < leftSize)
    {
        array[k] = tempLeft[i];
        i++;
        k++;
    }
    while(j < rightSize)
    {
        array[k] = tempRight[j];
        j++;
        k++;
    }
}

void mergeSort(float array[], int left, int right, int recursionDepth, int maxRecDepth)
{
    if(recursionDepth == maxRecDepth || left >= right)
        return;

    int middle = left + (right - left) / 2;
    mergeSort(array, left, middle, recursionDepth + 1, maxRecDepth);
    mergeSort(array, middle + 1, right, recursionDepth + 1, maxRecDepth);
    merge(array, left, middle, right);
}
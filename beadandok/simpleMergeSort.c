#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RECURSION_DEPTH 100

void merge(int array[], int left, int middle, int right);
void mergeSort(int array[], int left, int right, int recursionDepth);

int main() {
    int n = 521111;
    srand(time(NULL));

    for (int i = 1e5; i <= n; i)
    {
        int* array = (int*) malloc(n*sizeof(int));

        for(int i = 0; i < n; i++)
        {
            array[i] = rand() % 1001;
        }

        printf("%d element:", i);

        clock_t begin = clock();

        mergeSort(array, 0, n-1, 0);

        clock_t end = clock();
        double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

        printf("Elapsed time: %lf\n", timeSpent);

        free(array);

        i+=50000;
    }

    return 0;
}

void merge(int array[], int left, int middle, int right)
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

void mergeSort(int array[], int left, int right, int recursionDepth)
{
    if(recursionDepth == MAX_RECURSION_DEPTH || left >= right)
        return;

    int middle = left + (right - left) / 2;
    mergeSort(array, left, middle, recursionDepth + 1);
    mergeSort(array, middle + 1, right, recursionDepth + 1);
    merge(array, left, middle, right);
}
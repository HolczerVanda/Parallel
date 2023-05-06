#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int array[], int left, int middle, int right);
void mergeSort(int array[], int left, int right, int recursionDepth, int maxRecDepth);
void isSorted(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if(array[i] > array[i + 1])
        {
            printf("Array i+1, %d  array i: %d \n",array[i+1], array[i]);
            return;
        }
    }
    printf("Sorted\n");
}

int main(int argc, char *argv[]) {
    int n = 500000;
    srand(time(NULL));
    if (argc != 2) {
        printf("Error!\n");
        return 1;
    }

    int MAX_RECURSION_DEPTH = atoi(argv[1]);

    for (int i = 1e5; i <= n; i)
    {
        int* array = (int*) malloc(n*sizeof(int));

        for(int i = 0; i < n; i++)
        {
            array[i] = rand() % 1001;
        }

        printf("%d element:", i);

        clock_t begin = clock();

        mergeSort(array, 0, n-1, 0, MAX_RECURSION_DEPTH);
        isSorted(array, n);

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

void mergeSort(int array[], int left, int right, int recursionDepth, int maxRecDepth)
{
    if(recursionDepth == maxRecDepth || left >= right)
        return;

    int middle = left + (right - left) / 2;
    #pragma omp parallel sections
    {
         #pragma omp section
            {
                mergeSort(array, left, middle, recursionDepth + 1,maxRecDepth);
            }

            #pragma omp section
            {
                mergeSort(array, middle + 1, right, recursionDepth + 1,maxRecDepth);
            }
    }
    merge(array, left, middle, right);
}
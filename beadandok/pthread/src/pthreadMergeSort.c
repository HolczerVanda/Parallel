#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "pthreadMergeSort.h"

#define FILENAME "randomNumbers.txt"

typedef struct {
    float* array;
    int l;
    int r;
    int recursionDepth;
    int maxRecDepth;
    int maxThreads;
    int threads_created;
} MergeSortArgs;

int main(int argc, char *argv[]) {

    if (argc != 5) {
        printf("Error!\n");
        return 1;
    }

    int N = atoi(argv[1]);
    int maxRecDepth = atoi(argv[2]);
    int max_num_thread = atoi(argv[3]);
    int generated = atoi(argv[4]);

    float *array;
    array = (float *)malloc(N * sizeof(float));

    if(generated == 1)
    {
        FILE *file = fopen(FILENAME, "r");
        if (file == NULL) {
            printf("Error\n");
            return 1;
        }

        int i = 0;
        float number;
        while(fscanf(file, "%lf", &number) == 1)
        {
            array[i] = number;
            i++;
        }

        fclose(file);
    }

    else
    {
        srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        array[i] = ((float) rand()) / RAND_MAX;
    }
    }

    clock_t begin = clock();

    MergeSortArgs args = {array, 0, N-1, 0, maxRecDepth, max_num_thread, 0};

        pthread_t thread;
        pthread_create(&thread, NULL, mergeSort, (void *)&args);
        pthread_join(thread, NULL);

    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed time: %lf\n", timeSpent);

    FILE *output = fopen("output.txt", "a");
    if (output == NULL) {
        printf("Error\n");
        return 1;
    }

    fprintf(output, "%lf\n", timeSpent);
    fclose(output);

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

void *mergeSort(void *args) {
    MergeSortArgs *msa = (MergeSortArgs*)args;
    float* array = msa->array;
    int l = msa->l;
    int r = msa->r;
    int recursionDepth=msa->recursionDepth;
    int mrd= msa->maxRecDepth;
    int max_num_thread=msa->maxThreads;
    int threads_created=msa->threads_created;

    if(recursionDepth == mrd || l >= r)
        return 0;
    else
    {
        int m = l + (r - l) / 2;

        pthread_t left_thread, right_thread;
        
        if (threads_created < max_num_thread) {
            MergeSortArgs left_args = {array, l, m, (recursionDepth+1), mrd, max_num_thread, (threads_created+1) };
            pthread_create(&left_thread, NULL, mergeSort, (void *)&left_args);
            threads_created++;
        } else {
            mergeSort(&((MergeSortArgs){array, l, m, (recursionDepth+1), mrd, max_num_thread, (threads_created+1)}));
        }

        if (threads_created < max_num_thread) {
            MergeSortArgs right_args = {array, l, m, (recursionDepth+1), mrd, max_num_thread, (threads_created+1)};
            pthread_create(&right_thread, NULL, mergeSort, (void *)&right_args);
            threads_created++;
        } else {
            mergeSort(&((MergeSortArgs){array, l, m, (recursionDepth+1), mrd, max_num_thread, (threads_created+1)}));
        }

        if (threads_created < max_num_thread) {
            pthread_join(left_thread, NULL);
        }
        pthread_join(right_thread, NULL);

        merge(array, l, m, r);
    }
    pthread_exit(NULL);
}

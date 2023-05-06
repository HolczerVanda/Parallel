#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS 4

struct threadData{
    int *array;
    int size;
    int maxRecDepth;
    int recDepth;
};

void merge(int array[], int left[], int leftSize, int right[], int rightSize);
void *mergeSort(void *arg);

int main(int argc, char *argv[]) {
    int n = 1e5;
    srand(time(NULL));
    if (argc != 2) {
        printf("Error!\n");
        return 1;
    }

    int MAX_RECURSION_DEPTH = atoi(argv[1]);

    for (int i = 1e4; i <= n; i)
    {
        int* array = (int*) malloc(n*sizeof(int));

        for(int i = 0; i < n; i++)
        {
            array[i] = rand() % 1001;
        }

        printf("%d element:", i);

        clock_t begin = clock();

        pthread_t threads[THREADS];
        struct threadData data = {array, n, MAX_RECURSION_DEPTH, 0};

        for (int i = 0; i < THREADS; i++) {
            pthread_create(&threads[i], NULL, mergeSort, (void*) &data);
        }
        for (int i = 0; i < THREADS; i++) {
            pthread_join(threads[i], NULL);
        }

        clock_t end = clock();
        double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

        printf("Elapsed time: %lf\n", timeSpent);

        free(array);

        i+=5000;
    }

    return 0;
}

void merge(int array[], int left[], int leftSize, int right[], int rightSize)
{
    int i = 0, j = 0, k = 0;
    while(i < leftSize && j < rightSize)
    {
        if(left[i] < right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }
    while(i < leftSize)
    {
        array[k++] = left[i++];
    }
    while(j < rightSize)
    {
        array[k++] = right[j++];
    }
}

void *mergeSort(void *arg)
{
    struct threadData *data = (struct threadData*) arg;
    int *array = data->array;
    int size = data->size;
    int maxRecDepth = data->maxRecDepth;
    //printf("Max rec depth :%d \n",maxRecDepth);
    int recDepth = data->recDepth;
    //printf("Rec depth: %d \n",recDepth);

    if(size < 2 || recDepth == maxRecDepth){
        //printf("rec depth: %d, max rec depth: %d \n", recDepth, maxRecDepth);
        pthread_exit(NULL);
    }
    else
    {
        int mid = size / 2;
        struct threadData leftData = {array, mid, maxRecDepth, recDepth + 1};
        struct threadData rightData = {array + mid, size - mid, maxRecDepth, recDepth + 1};

        pthread_t threads[2];
        pthread_create(&threads[0], NULL, mergeSort, (void*) &leftData);
        pthread_create(&threads[1], NULL, mergeSort, (void*) &rightData);

        pthread_join(threads[0], NULL);
        pthread_join(threads[1], NULL);

        int *left = (int*) malloc(mid * sizeof(int));
        int *right = (int*) malloc((size - mid) * sizeof(int));
        for(int i = 0; i < mid; i++)
            left[i] = array[i];
        for(int i = mid; i < size; i++)
            right[i - mid] = array[i];
        merge(array, left, mid, right, size - mid);
        free(left);
        free(right);

        pthread_t thread_id = pthread_self();
        printf("Thread ID: %lu\n", thread_id);
        //printf("rec depth: %d, max rec depth: %d \n", recDepth, maxRecDepth);
        pthread_exit(NULL);
    }
}
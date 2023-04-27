#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_THREADS 4

// define a struct to hold the arguments for mergeSort
typedef struct {
    int* arr;
    int l;
    int r;
} MergeSortArgs;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void *mergeSort(void *args) {
    MergeSortArgs *msa = (MergeSortArgs*)args;
    int l = msa->l;
    int r = msa->r;
    int* arr = msa->arr;

    if (l < r) {
        int m = l + (r - l) / 2;

        // Create threads to sort left and right subarrays
        pthread_t left_thread, right_thread;
        int threads_created = 0;

        if (threads_created < MAX_THREADS) {
            MergeSortArgs left_args = {arr, l, m};
            pthread_create(&left_thread, NULL, mergeSort, (void *)&left_args);
            threads_created++;
        } else {
            mergeSort(&((MergeSortArgs){arr, l, m}));
        }

        if (threads_created < MAX_THREADS) {
            MergeSortArgs right_args = {arr, m+1, r};
            pthread_create(&right_thread, NULL, mergeSort, (void *)&right_args);
            threads_created++;
        } else {
            mergeSort(&((MergeSortArgs){arr, m+1, r}));
        }

        // Wait for threads to finish
        if (threads_created < MAX_THREADS) {
            pthread_join(left_thread, NULL);
        }
        pthread_join(right_thread, NULL);

        // Merge sorted subarrays
        merge(arr, l, m, r);
    }
    pthread_exit(NULL);
}

int main() {
    int n = 1e5;
    srand(time(NULL));

    for (int i = 1e4; i <= n; i)
    {
        int* array = (int*) malloc(n*sizeof(int));

        for(int i = 0; i < n; i++)
        {
            array[i] = rand() % 1001;
        }

        printf("%d element:", i);

        clock_t begin = clock();

        MergeSortArgs args = {array, 0, n-1};

        pthread_t thread;
        pthread_create(&thread, NULL, mergeSort, (void *)&args);
        pthread_join(thread, NULL);

        clock_t end = clock();
        double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

        printf("Elapsed time: %lf\n", timeSpent);

        free(array);

        i+=5000;
    }

    return 0;
}

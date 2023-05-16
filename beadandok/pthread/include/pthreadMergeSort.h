#ifndef PTHREADMERGESORT_H
#define PTHREADMERGESORT_H

void merge(float array[], int left, int middle, int right);
void *mergeSort(void *args);

#endif
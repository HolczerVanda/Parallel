#include <stdio.h>

void oddEvenMerge(int array[], int left, int right, int n);
void mergeSort(int array[], int left, int right);

int main() {
    int array[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(array) / sizeof(array[0]);
    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    mergeSort(array, 0, arr_size - 1);
    printf("\nSorted array is \n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void oddEvenMerge(int array[], int left, int middle, int right)
{
    int aSize = middle - left;
    int bSize = right - middle + 1;
    int A[aSize], B[bSize];
    for(int i = 0; i < aSize; i++)
        A[i] = array[left + i];
    for(int i = 0; i < bSize; i++)
        B[i] = array[middle + i];

    int a1Size, a2Size;
    if(aSize % 2 == 0)
    {
        a1Size = aSize / 2;
        a2Size = aSize - a1Size;
    }
    else
    {
        a1Size = aSize / 2 + 1;
        a2Size = aSize - a1Size;
    }
    int A1[a1Size], A2[a2Size];

    for(int i = 0; i < a1Size; i++)
    {
        if(i % 2 == 0)
            A1[i] = A[i];
        else
            A1[i] = A[i+1];
    }
    for(int i = 0; i < a2Size; i++)
    {
        if(i % 2 == 0)
            A2[i] = A[i+1];
        else
            A2[i] = A[i];
    }

    int b1Size, b2Size;
    if(bSize % 2 == 0)
    {
        b1Size = bSize / 2;
        b2Size = bSize - b1Size;
    }
    else
    {
        b1Size = bSize / 2 + 1;
        b2Size = bSize - b1Size;
    }
    int B1[b1Size], B2[b2Size];

    for(int i = 0; i < b1Size; i++)
    {
        if(i % 2 == 0)
            B1[i] = B[i];
        else
            B1[i] = B[i+1];
    }
    for(int i = 0; i < b2Size; i++)
    {
        if(i % 2 == 0)
            B2[i] = B[i+1];
        else
            B2[i] = B[i];
    }

    int uSize = a1Size + b2Size;
    int U[uSize];

    int a1 = 0, b2 = 0;
    for(int i = 0; i < uSize; i++)
    {
        if(i % 2 != 0 && i <= b2Size)
        {
            U[i] = B2[b2];
            b2++;
        }
        else
        {
             U[i] = A1[a1];
             a1++;
        }
    }

    int vSize = a2Size + b1Size;
    int V[vSize];

    int a2 = 0, b1 = 0;
    for(int i = 0; i < vSize; i++)
    {
        if(i % 2 != 0 && i <= a2Size)
        {
            V[i] = A2[a2];
            a2++;
            
        }
        else
        {
            V[i] = B1[b1];
            b1++;
        }
    }

    int u =0, v=0;
    for(int i = 0; i < (aSize + bSize); i++)
    {
        if(i % 2 != 0)
        {
            array[i] = V[v];
            v++;
        }
        else
        {
            array[i] = U[u];
            u++;
        }
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle+1, right);
        oddEvenMerge(array, left, middle, right);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void isUnique(int array[], int length);

int main()
{
    int n = 10;
    srand(time(0));
    int randNums[n];

    printf("Random numbers: ");
    clock_t start = clock();

    for(int i = 0; i < n; i++)
    {
        randNums[i] = i;
        if(rand() % 2 == 0)
        {
            randNums[i] = rand() % n;
        }
        printf("%d ", randNums[i]);
    }

    clock_t end = clock();

    printf("\nNumber of elements: %d\n", n);
    printf("Time taken: %f\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    isUnique(randNums, n);

    printf("The complexity of the function is O(n^2).");

    return 0;
}

void isUnique(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (array[i] == array[j])
            {
                printf("There are duplicated elements.\n");
                return;
            }
        }
    }
    printf("All elements are unique.\n");
}
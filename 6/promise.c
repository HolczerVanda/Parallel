#include <stdio.h>
#include <stdlib.h>

typedef struct Promise
{
    int isResolved;
    int result;
} Promise;

void storeResult(Promise* promise, int result)
{
    promise->isResolved = 1;
    promise->result = result;
}

int main() {
    Promise* promise = (Promise*) malloc(sizeof(Promise));
    promise->isResolved = 0;

    int calculationResult = 42;
    storeResult(promise, calculationResult);

    if(promise->isResolved)
        printf("Calculation result: %d\n", promise->result);
    else
        printf("The promise has not been resolved yet.\n");

    free(promise);
    return 0;
}
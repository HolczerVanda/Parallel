#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "randomNumbers.txt"

int main() {

    int N = 100000;
    srand(time(NULL));

    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error\n");
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        float randomNumber = (float)rand() / RAND_MAX;
        fprintf(file, "%f\n", randomNumber);
    }

    fclose(file);

    return 0;
}

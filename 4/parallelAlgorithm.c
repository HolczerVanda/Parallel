#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, intervalMin, intervalMax;
    int zeroCnt = 0, positiveCnt = 0, negativeCnt = 0, absoluteCnt = 0, intervalCnt = 0;
    float* array;
    
    srand(time(0));

    printf("Enter the lower and the upper boundary of the intervall: ");
    scanf("%d, %d", &intervalMin, &intervalMax);
    
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    
    array = (float*) malloc(n * sizeof(float)); 
    
    printf("The elements of the array: ");
    for(i = 0; i < n; i++)
    {
        array[i] = (float)(rand() % 100 - 50) / 10;
        printf("%.2lf ", array[i]);
    }
    
  
    for(i = 0; i < n; i++)
    {
        if(array[i] == 0)
            zeroCnt++;
        
        
        if(array[i] > 0)
            positiveCnt++;
        else if(array[i] < 0)
            negativeCnt++;
        
        
        if(array[i] < -1 || array[i] > 1)
            absoluteCnt++;
        
        
        if(array[i] >= intervalMin && array[i] <= intervalMax)
            intervalCnt++;
    }
    
    printf("\nNulls: %d\n", zeroCnt);
    printf("Positive numbers: %d\n", positiveCnt);
    printf("Negative numbers: %d\n", negativeCnt);
    printf("Numbers with an absolute value less than one: %d\n", absoluteCnt);
    printf("%d numbers fall in the given intervall.\n", intervalCnt);
    
    free(array);
    return 0;
}
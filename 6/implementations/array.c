#include <stdio.h>
#include <stdlib.h>

#define N 100

void push(int item, int* array, int top)
{
    if(top >= N-1)
    {
        printf("Overflow\n");
        return;
    }
    array[++top] = item;
}

int pop(int* array, int top)
{
    if(top < 0)
    {
        printf("Underflow\n");
        return -1;
    }
    return array[top--];
}

int peek(int* array, int top)
{
    if(top < 0)
    {
        printf("Empty\n");
        return -1;
    }
    return array[top];
}

int isEmpty(int top)
{
    return top == -1;
}

int main() {
    int array[N];
    int top = -1;
    push(1, array, top);
    pop(array, top);
    peek(array, top);
    isEmpty(top);
}
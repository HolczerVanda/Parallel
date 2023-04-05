#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100
int queue[QUEUE_SIZE];
int front = 0;
int rear = -1;

void enqueue(int item)
{
  if(rear == QUEUE_SIZE - 1)
  {
    printf("Overflow\n");
    return;
  }
  queue[++rear] = item;
}

int dequeue()
{
  if(front > rear)
  {
    printf("Underflow\n");
    return -1;
  }
  return queue[front++];
}

int isEmpty()
{
  return front > rear;
}

int main() {
    
}
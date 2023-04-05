#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
  int data;
  struct StackNode* next;
} StackNode;

StackNode* stackTop = NULL;

void pushStack(int item)
{
  StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));

  newNode->data = item;
  newNode->next = stackTop;
  stackTop = newNode;
}

int popStack()
{
  if(stackTop == NULL)
  {
    printf("Underflow\n");
    return -1;
  }
  StackNode* temp = stackTop;
}

int main() {
    
}
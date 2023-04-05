#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
} Node;

Node* head = NULL;

void insertAtBeginning(int item)
{
  Node* newNode = (Node*)malloc(sizeof(Node));

  newNode->data = item;
  newNode->next = head;
  head = newNode;
}

void insertAtEnd(int item)
{
  Node* newNode = (Node*)malloc(sizeof(Node));

  newNode->data = item;
  newNode->next = NULL;

  if(head == NULL)
  {
    head = newNode;
    return;
  }

  Node* current = head;
  while(current->next != NULL)
  {
    current = current->next;
  }
  current->next = newNode;
}

void deleteAtBeginning()
{
  if(head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  Node* temp = head;
  head = head->next;
  free(temp);
}

void deleteAtEnd()
{
  if(head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  if(head->next == NULL)
  {
    free(head);
    head = NULL;
    return;
  }

  Node* current = head;
  while(current->next->next != NULL)
  {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

void printList()
{
  if(head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  Node* current = head;
  while(current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
    
}
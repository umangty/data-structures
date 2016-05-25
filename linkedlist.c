//Singly Linked List important function implementation.

#include <stdio.h>
#include <stdlib.h>

// Define structure of a single node.
typedef struct Node{
  int data;
  struct Node *next;
} Node;

// Returns length of the linked list.
int Length(struct Node *head){
  struct Node *current = head;
  int count = 0;
  while(current != NULL){
    count++;
    current = current->next;
  }
  return count;
}
 
   
// Prints data stored in the Linked List.
void Print(struct Node *head){
  struct Node *current = head;
  int count = 0;
  while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }
}

// Method to insert a node at the beginning of the list.
void InsertAtBegin(struct Node *head, int data){
  struct Node *current = head;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = current;
  head = newNode;
} 

// Method to insert a node at last of the list.
void InsertAtLast(struct Node *head, int data){
  struct Node *current = head;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  while(current != NULL){
    current = current->next;
  }
  current->next = newNode;
}

// Method to insert a node at Nth postion from beginning (assume 0 indexing) in a list.
void InsertAtNth(struct Node *head, int data, int postion){
  struct Node *slow = head;
  struct Node *fast = head;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  int i = 0;
  while(i<postion && fast->next!=NULL){
    slow = fast;
    fast = fast->next;
    i++;
  }
  slow->next = newNode;
  newNode->next = fast;
}

// Method to delete beginning node.
void DeleteHeadNode(struct Node *head){
  struct Node *current = head;
  head = head->next;
  free(current);
}

// Method to delete tail node of the list.
void DeleteTailNode(struct Node *head){
  struct Node *slow = head;
  struct Node *fast = head->next;
  while(slow!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = NULL;
  free(fast);
}

// Method to delete a node from Nth postion from beginning.
void DeleteNthNode(struct Node *head, int position){
  struct Node *slow = head;
  struct Node *fast = head;
  int i = 0;
  while(i<position && slow!=NULL && fast->next!=NULL){
    slow = fast;
    fast = fast->next;
    i++;
  }
  slow->next = fast->next;
  free(fast);
}

// Reverse linked list.
void ReverseList(struct Node *head){
  struct Node *prev = NULL;
  struct Node *current = head;
  struct Node *next;
  while (current != NULL){
    next = current->next; 
    current->next = prev; 
    prev = current;
    current = next;
  }
  head = prev;
}

// Get node value counting backward from tail.
int GetNodeFromBack(struct Node *head, int position){
  struct Node *slow = head;
  struct Node *fast = head;
  int index = 0;
  while(index < position && fast != NULL){
    fast = fast->next;
    index++;
  }
  while(fast != NULL && slow != NULL){
    fast = fast->next;
    slow = slow->next;
  }
  return slow->data;
}

/* TODO: Code for removing duplicate nodes
         Detecting cycle in the list
         *
*/




int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
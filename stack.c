// Problem 1, Chapter Linked Lists - DSA made easy.
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} node;

void printstack(struct node *head){
	struct node *current = head;
	while(current != NULL){
		printf("%d-->", current->data);
		current = current->next;
	}
	printf("|NULL|\n");
}

void push(struct node **head, int data){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));	
	newNode->data = data;
	newNode->next = NULL;
	struct node *current = *head;
	if(current == NULL){
		*head = newNode;
		return;
	}
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newNode;
}

void pop(struct node *head){
	if(head == NULL){
  		return;
  	}
  	struct node *slow = head;
  	struct node *fast = head->next;
  	while(slow!=NULL && fast->next!=NULL){
    	slow = slow->next;
    	fast = fast->next;
	}
	slow->next = NULL;
	free(fast);
}

int main(){
	struct node *head = NULL;
 	pop(head);
 	push(&head, 1);
 	push(&head, 2);
 	push(&head, 3);
 	push(&head, 4);
 	pop(head);
 	push(&head, 5);
 	printstack(head);
 	
 }
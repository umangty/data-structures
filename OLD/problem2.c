//nth node from last.
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} node;

void printlist(struct node *head){
	struct node *current = head;
	while(current != NULL){
		printf("%d -> ", current->data);
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

int nthDataFromLast(struct node *head, int positionFromLast){
	struct node *fast = head;
	struct node *slow = head;
	int ind = 0;
	while(ind < positionFromLast){
		fast = fast->next;
		ind++;
	}
	while(fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
		ind++;
	}
	return slow->data;
}

int main(){
	struct node *head = NULL;
 	push(&head, 4);
 	push(&head, 3);
 	push(&head, 2);
 	push(&head, 1);
 	push(&head, 0);
 	printf("%d\n", nthDataFromLast(head, 4));
 	
 }
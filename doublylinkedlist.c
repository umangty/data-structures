#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
} node;

void add_front(struct node **head, int data){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;
	newNode->prev = NULL;
	
	if(*head != NULL){
		(*head)->prev = newNode;
	}
	*head = newNode;
}

void add_back(struct node **head, int data){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	struct node *current = *head;
	newNode->data = data;
	newNode->next = NULL;
	if(*head == NULL){
		newNode->prev = NULL;
		return;
	} 
	while(current->next != NULL){
		current = current->next;
	}

	current->next = newNode;
	newNode->prev = current;
}

void reverse(struct node **head){
    struct node *temp = NULL;  
    struct node *current = *head;
     while (current !=  NULL){
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;              
       current = current->prev;
    }      
      
    if(temp != NULL )
        *head = temp->prev;
}    

void printlist(struct node *head){
	struct node *current = head;
	printf("NULL<--->");
	while(current != NULL){
		printf("%d<--->", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

int main(){
	struct node *head = NULL;
	add_front(&head, 5);
	add_front(&head, 6);
	add_back(&head, 9);
	add_front(&head, 23);
	printlist(head);
	reverse(&head);
	printlist(head);
}
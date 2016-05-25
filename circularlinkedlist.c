#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void print_list(struct node *head){
	struct node *temp = head;
	if(temp != NULL){
		do{
			printf("%d", temp->data);
		}
		while(temp != head);
	}
}

void push(struct node **head, int data){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;
	
	struct node *temp = *head;
	if(*head != NULL){
		do{
			temp = temp->next;
		}
		while(temp->next != *head);
	}
}
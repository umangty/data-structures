#include <stdio.h>
#include <stdlib.h>

struct node{
	char charac;
	struct node* next;
};

struct node* head = NULL;

void print(){
	struct node* current = head;
	while(head->next != NULL){
		printf("%c -->", head->charac);
	}
	printf("\n");
}

void insert(int ch){
	struct node* newNode = (struct node *)malloc(sizeof(struct node));
	struct node* temp = head;
	newNode->charac = ch;
	newNode->next = NULL;
	if(head = NULL) head = newNode;
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

int main(){
	insert('c');
	print();
}
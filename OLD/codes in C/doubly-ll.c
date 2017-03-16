#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

void Print(struct Node* head){
	struct Node* current = head;
	while(current != NULL){
		printf("%d <-->", current->data);
		current = current->next;
	}
	printf("\n");
}

void Insert(struct Node** head, int position, int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = *head;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;


	if(*head == NULL){
		*head = newNode;
	}

	else{
		if(position == 0){
			newNode->next = *head;
			(*head)->prev = newNode;
			*head = newNode;
		}
		else{
			while(temp != NULL && position--){
				temp = temp->next;
			}
			temp->prev->next = newNode;
			newNode->prev = temp->prev;
			newNode->next = temp;
			temp->prev = newNode;
		}
	}
}

int main(){
	struct Node* head = (struct Node *)malloc(sizeof(struct Node));
	Insert(&head, 0, 4);
	Insert(&head, 1, 15);
	Insert(&head, 0, 7);
	Insert(&head, 3, 40);
	Print(head);
	return 0;
}
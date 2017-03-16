#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void Print(struct Node* head){
	if(head == NULL){
		return;
	}
	else{
		struct Node* current = head;
		do{
			printf("%d ", current->data);
			current = current->next;
		} while(current != head);
	}
}

void InsertEnd(struct Node** head, int data){
	struct Node* temp = *head;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = newNode;
	if(*head == NULL) *head = newNode;
	else{
		while(temp->next != *head){
			temp = temp->next;
		}
		newNode->next = *head;
		temp->next = newNode;
	}
}	

void InsertBegin(struct Node** head, int data){
	struct Node* temp = *head;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = newNode;
	if(*head == NULL){
		*head = newNode;
	}
	else{
		newNode->next = *head;
		while(temp->next != *head) temp = temp->next;
		temp->next = newNode;
		*head = newNode;
	}
}

void DeleteLast(struct Node** head){
	if(*head == NULL) free(*head);
	else{
		struct Node* slow = NULL;
		struct Node* fast = *head;
		while(fast->next != *head){
			slow = fast;
			fast = fast->next;
		}
		slow->next = *head;
		free(fast);
	} 
}

void DeleteFirst(struct Node** head){
	if(*head == NULL) free(*head);
	else{
		struct Node* temp = *head;
		while(temp->next != *head) temp = temp->next;
		temp->next = (*head)->next;
		struct Node* temp2 = *head;
		*head = (*head)->next;
		free(temp2);
	}
}

int main(){
	struct Node* head = NULL;
	InsertBegin(&head, 14);
	InsertBegin(&head, 1);
	InsertBegin(&head, 20);
	InsertBegin(&head, 0);
	InsertEnd(&head, 21);
	//DeleteLast(&head);
	DeleteFirst(&head);
	DeleteFirst(&head);
	DeleteFirst(&head);
	DeleteFirst(&head);
	Print(head);
	return 0;
}
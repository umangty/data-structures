#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
} node;

void traverse(struct node *head){
	struct node *current = head;
	while(current != NULL){
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("|NULL|\n");
}
// we have to use double pointer to swap the pointers. CARE
void addfront(struct node **head, int data){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void addend(struct node **head, int data){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	struct node *current = *head;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newNode;
}

// Given a ‘key’, delete the first occurrence of this key in linked list.
void delete_key(struct node **head, int key){
	struct node *current = *(head);
	struct node *prev = NULL;
	bool flag = false;
	while(current != NULL){
		if(current->data == key) {
			flag = true;
			break;
		}
		prev = current;
		current = current->next;
	}

	prev->next = current->next;
	free(current);
}

void delete_position(struct node **head, int position){
	int i = 0;
	struct node *current = *head;
	struct node *prev = NULL;
	while(i<position && current!=NULL){
		prev = current;
		current = current->next;
		i++;
	}
	prev->next = current->next;
	free(current);
}

// Length of the linked list by iterative manner.
void length_iter(struct node *head){
   int count = 0;  // Initialize count
   struct node* current = head;  // Initialize current
   while (current != NULL){
        count++;
        current = current->next;
    }
    printf("Length = %d ", count);
}

// Length of linked list by recursive aproach.
int length_recu(struct node *head){
	if(head == NULL){
		return 0;
	}
	else{
		return 1+length_recu(head->next);
	}
}

int main(){
	struct node *head;
	struct node *first;
	struct node *second;
	struct node *third;

	first = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));

	first->data = 1;
	first->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	head = first;

	addend(&head, 4);
	addfront(&head, 0);
	traverse(head);
	delete_key(&head, 3);
	traverse(head);
	addend(&head, 8);
	traverse(head);
	delete_position(&head, 2);
	traverse(head);
	length_iter(head);
	return 0;
}
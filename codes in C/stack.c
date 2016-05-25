#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int data;
	struct Node* next;
} node;

node* stacktop = NULL;
node* minstacktop = NULL;

void print(node* top){
	node* current = top;
	int count = 0;
	while(current != NULL){
		printf("%d(%d) --> ", current->data, count);
		count++;
		current = current->next;
	}
	printf("%s", "NULL\n");
}

void push(node** top, int data){
	node* newNode = (node *)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	if(*top == NULL){
		*top = newNode;
	}
	else{
		newNode->next = *top;
		*top = newNode;
	}
}

node* pop(node** top){
	if(*top == NULL){
		return *top;
	}
	else{
		node* temp = *top;
		(*top) = (*top)->next;
		free(temp);
	}
}

int top(node* top){
	return top == NULL ? -1 : top->data;
}

void push_wrapper(int data){
	if(data < top(minstacktop) || minstacktop == NULL){
		push(&minstacktop, data);
	}
	else{
		push(&minstacktop, top(minstacktop));
	}
	push(&stacktop, data);
}

node* pop_wrapper(){
	node* temp = pop(&minstacktop);
	return pop(&stacktop); 
}

// aim was top implement get_min() on any stack in O(1)
int get_min(){
	return top(minstacktop);
}

int main(){
	push_wrapper(2); 
	push_wrapper(6);
	push_wrapper(4);
	push_wrapper(1);
	push_wrapper(5); //top

	print(stacktop);
	print(minstacktop);

	pop_wrapper();
	pop_wrapper();

	printf("%d", get_min());
}
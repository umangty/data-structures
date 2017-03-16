#include <stdio.h>
#include <stdlib.h>

// use Node** head when head pointer can be manipulated in any method.

struct Node{
	int data;
	struct Node* next;
};

void Print(struct Node* head){
	struct Node* current = head;
	int count = 0;
	while(current != NULL){
		printf("%d(%d) --> ", current->data, count);
		count++;
		current = current->next;
	}
	printf("%s", "NULL\n");
}

void Insert(struct Node** head, int position, int data){
	struct Node* fast = *head;
	struct Node* slow;
	int count = 0;
	struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	if(head == NULL){
		*head = newNode;
	}
	else{
		if(position == 0){
			*head = newNode;
			newNode->next = fast->next;
		}
		else{
			while(fast != NULL && count<position){
				count++;
				slow = fast;
				fast = fast->next;
			}
			slow->next = newNode;
			newNode->next = fast;
		}
	}
}

void Delete(struct Node** head, int position){
	struct Node* slow;
	struct Node* fast = *head;
	if(position == 0){
		*head = (*head)->next;
		free(fast);
	}
	else{
		while(fast != NULL && position--){
			slow = fast;
			fast = fast->next;
		}
		slow->next = fast->next;
		free(fast);
	}
}

// To find nth element from last.
int nthFromLast(struct Node* head, int n){
	struct Node* slow = head;
	struct Node* fast = head;
	n--;
	while(n-- && fast->next != NULL) fast = fast->next;
	while(fast->next !=NULL){
		slow = slow->next;
		fast = fast->next;
	} 
	return slow->data;
}


// merge sorted lists
struct Node* MergeSortedLists(struct Node** head1, struct Node** head2){
	struct Node* temp;
	struct Node* new_head;
	if(*head1 == NULL) return *head2;
	else if(*head2 == NULL) return *head1;
	else{
		if((*head1)->data <= (*head2)->data) new_head = *head1;
		else new_head = *head2;

		while(*head1 && *head2){
			if((*head1)->data <= (*head2)->data){
				temp = (*head1)->next;
				(*head1)->next = (*head2);
				(*head1) = temp;
			} 
			else{
				temp = (*head2)->next;
				(*head2)->next = (*head1);
				(*head2) = temp;
			}
		}
	}
	return new_head;
} 

// reverse ll in pairs - does not work if length of l is odd. - seg fault
struct Node* ReverseLLPair(struct Node* head){
	struct Node* current = head;
	while(current){
		int temp = current->data;
		current->data = current->next->data;
		current->next->data = temp;

		current = current->next->next;
	}
	return head;
}

// find sqrt(n)th node of a linked list. assume n is not known.
int sqrtNthNode(struct Node* head){
	//struct Node* temp = *head;
	struct Node* sqrt = NULL;
	int i=1, j=1;
	for(; head != NULL ; head = head->next){
		if(i == j*j){
			if(sqrt == NULL) sqrt = head;
			else sqrt = sqrt->next;
			j++;
		}
		i++;
	}
	return sqrt->data;
}

// find fractional node - (n/k)t node.
int fractional(struct Node* head, int k){
	struct Node* fractional = NULL;
	int i = 0;
	for(; head != NULL ; head = head->next){
		if(i%k == 0){
			if(fractional == NULL) fractional = head;
			else fractional = fractional->next;
		}
		i++;
	}
	return fractional->data;
}

// find modular node. n=19, k=3 should return 18th node
int modular(struct Node** head, int k){
	int count = 0;
	int i = 0;
	struct Node* temp = NULL;
	while(*head != NULL){
		if(i%k == 0){
			count++;
			temp = *head;
		}
		i++;
		*head = (*head)->next;
	}
	printf("%d\n", count);
	return temp->data;
}

// merge 2 lists. Karumachi problem - NOT DONE
struct Node* merge(struct Node** head1, struct Node** head2){
	struct Node* temp1 = *head1;
	struct Node* temp2 = *head2;
	struct Node* newHead = *head1;
	while(*head1 != NULL && *head2 != NULL){
		temp1 = (*head1)->next;
		*head1 = *head2;
		temp2 = (*head2)->next;
		*head2 = temp1;
		*head1 = temp1;
		*head2 = temp2;
	}
	return newHead;
}

int main(){
	struct Node* head1 = (struct Node *)malloc(sizeof(struct Node));
	struct Node* head2 = (struct Node *)malloc(sizeof(struct Node));
	head1->next = NULL;
	head2->next = NULL;
	Insert(&head1, 0, 2);
	Insert(&head1, 1, 4);
	Insert(&head1, 2, 15);
	Insert(&head1, 3, 21);


	Insert(&head2, 0, 3);
	Insert(&head2, 1, 5);
	Insert(&head2, 2, 21);
	Insert(&head2, 3, 25);
	// Insert(&head1, 8, 26);


	Print(head1);
	Print(head2);
	Print(merge(&head1, &head2));
	return 0;
}
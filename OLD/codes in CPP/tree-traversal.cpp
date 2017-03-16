#include <iostream>
#include <stack>
#include "stdlib.h"
#include <typeinfo>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

// Iterative implementations.
void pre_order(struct Node* root){
	cout << root->data;
	stack<struct Node*> S;
	while(1){
		while(root){
			cout << root->data;
			S.push(root);
			root = root->left;
		}
		if(S.size() == 0){
			break;
		}
		cout << typeid(S.pop());
		root = root->right;
	}
}

int main(){
	struct Node* root = (struct Node *)malloc(sizeof(struct Node));
	struct Node* node2 = (struct Node *)malloc(sizeof(struct Node));
	struct Node* node3 = (struct Node *)malloc(sizeof(struct Node));
	struct Node* node4 = (struct Node *)malloc(sizeof(struct Node));
	struct Node* node5 = (struct Node *)malloc(sizeof(struct Node));
	struct Node* node6 = (struct Node *)malloc(sizeof(struct Node));
	struct Node* node7 = (struct Node *)malloc(sizeof(struct Node));

	root->data = 1;
	root->left = node2;
	root->right = node3;

	node2->data = 2;
	node2->left = node4;
	node2->right = node5;

	node3->data = 3;
	node3->left = node6;
	node3->right = node7;

	node4->data = 4;
	node4->left = NULL;
	node4->right = NULL;

	node5->data = 5;
	node5->left = NULL;
	node5->right = NULL;

	node6->data = 6;
	node6->left = NULL;
	node6->right = NULL;

	node7->data = 7;
	node7->left = NULL;
	node7->right = NULL;

	pre_order(root);

	return 0;
}
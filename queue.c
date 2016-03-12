/*
	Queue ADT:
		EnQueue(int data)
		int DeQueue()
		int Front()
		int QueueSize()
		int IsEmptyQueue()
		Exceptions : Empty Queue, Full Queue
 */
// implementation using circular array
#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int front;
	int back;
	int capacity;
	int *array;
};

struct Queue * createQueue(int size){
	struct Queue *Q = malloc(sizeof(struct Queue));
	Q->capacity = size;
	Q->front = -1;
	Q->front = -1;
	Q->array = malloc(Q->capacity*sizeof(int));
	return Q;
}

void EnQueue(struct Queue *Q, int data){
	if(IsQueueFull(Q)) printf("Queue is full.");
	Q->rear = (Q->rear - 1)%Q->capacity;
	Q->array[Q->rear] = data;
	if(Q->front == -1){
		Q->front = Q->rear;
	}
}

int DeQueue(struct Queue *Q){
	if(IsQueueEmpty(Q)){
		printf("Queue is empty.");
		return 0;
	} 
	int temp = Q->array[Q->front];
	if(Q->front == Q->rear) Q->front = Q->rear = -1;
	else Q->front = (Q->front + 1)%Q->capacity;
	return temp;
}

int QueueSize(struct Queue *Q){
	return (Q->capacity - Q->rear + Q->front)%Q->capacity;
}

int IsQueueEmpty(struct Queue *Q){
	return (Q->front==-1 ? 1 : 0);
}

int IsQueueFull(struct Queue *Q){
	return (Q->rear+1)%Q->capacity == Q->front;
}

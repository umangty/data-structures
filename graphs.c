// Adjacency List representation of graphs.
#include <stdio.h>
#include <stdlib.h>

struct ListNode{
	int data;
	struct ListNode *next;
};

struct AdjList{
	struct ListNode *head;
};

struct Graph{
	int V; //number of vertices in the graph.
	struct AdjList *array;
};

//utility functions.
struct ListNode * generateNode(int data){
	struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//initializes graph of size V.
struct Graph * initializeGraph(int V){
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->V = V;
	// it is wrong pratice to cast pointers.
	graph->array = (struct AdjList *)malloc(V*sizeof(struct AdjList));
	int i;
	for(i=0; i<V; i++){
		graph->array[i].head = NULL;
	}
	return graph;
}

// add new element in the graph.
void addEdge(struct Graph *graph, int source, int destination){
	struct ListNode *newNode = generateNode(destination);
	newNode->next = graph->array[source].head;
	graph->array[source].head = newNode;

	newNode = generateNode(source);
	newNode->next = graph->array[destination].head;
	graph->array[destination].head = newNode;
}

//print adjacency list.
void printGraph(struct Graph* graph){
    int v;
    for (v = 0; v < graph->V; ++v){
        struct ListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl){
            printf("-> %d", pCrawl->data);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

//main function.
int main(){
    int V = 5;
    struct Graph* graph = initializeGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 0, 3);
    printGraph(graph);
    return 0;
}
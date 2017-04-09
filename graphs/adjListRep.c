#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int dest;
	struct node* next;
}node;

typedef struct adjList{
	node* head;
}adjList;

typedef struct graph{
	int v;
	adjList *arr;
}graph;

node* createEdge(int dest){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

graph* createGraph(int v){
	graph *newGraph = (graph*)malloc(sizeof(graph));
	newGraph->v = v;
	newGraph->arr = (adjList*)malloc(sizeof(adjList) * v);
	for(int i = 0;i < v;i++ )
		newGraph->arr[i].head = NULL;
	return newGraph;
}

void addEdge(graph* g,int src,int dest){
	node* edge = createEdge(dest);
	edge->next = g->arr[src].head;
	g->arr[src].head = edge;

	edge = createEdge(src);
	edge->next = g->arr[dest].head;
	g->arr[dest].head = edge;
}

void display(graph* g){
	for(int v = 0;v<g->v;v++){
		printf("%d",v);
		node *temp = g->arr[v].head;
		while(temp){
			printf("->%d",temp->dest);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(){
	graph* g = createGraph(5);
	addEdge(g,0,4);
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,1,3);
	addEdge(g,1,2);
	addEdge(g,2,3);
	addEdge(g,3,4);
	display(g);
	return 0;
}
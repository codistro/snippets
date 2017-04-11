#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
typedef struct node{
	int dest;
	struct node* next;
}node;

typedef struct adjList{
	node* head;
}adjList;

typedef struct graph{
	int v;
	adjList* arr;
}graph;

node* createNode(int dest){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

graph* createGraph(int v){
	graph* newGraph = (graph*)malloc(sizeof(graph));
	newGraph->v = v;
	newGraph->arr = (adjList*)malloc(sizeof(adjList) * v);
	for(int i = 0; i < v;i++)
		newGraph->arr[i].head = NULL;
	return newGraph;
}

void addEdge(graph* g,int src,int dest){
	node* newEdge = createNode(dest);
	newEdge->next = g->arr[src].head;
	g->arr[src].head = newEdge;

	newEdge = createNode(src);
	newEdge->next = g->arr[dest].head;
	g->arr[dest].head = newEdge;
}

void display(graph* g){
	for(int i = 0; i < g->v;i++){
		node* temp = g->arr[i].head;
		printf("%d",i);
		while(temp){
			printf("->%d",temp->dest);
			temp = temp->next;
		}
		printf("\n");
	}
}

void BFS(graph* g,int start){
	int flag[g->v];
	for(int i = 0;i < g->v;i++)
		flag[i] = 0;
	queue* q = createQueue(g->v);
	flag[start] = 1;
	enQueue(q,start);
	while(!isEmpty(q)){
		start = frontData(q);
		printf("%d ",start);
		int temp = deQueue(q);
		node* crawl = g->arr[start].head;
		while(crawl){
			if(flag[crawl->dest] == 0){
				flag[crawl->dest] = 1;
				enQueue(q,crawl->dest);
			}
			crawl = crawl->next;
		}
	}
}

int main(){
	graph* g = createGraph(9);
    addEdge(g,8,2);
    addEdge(g,8,0);
    addEdge(g,8,6);
    addEdge(g,7,4);
    addEdge(g,7,6);
    addEdge(g,6,5);
    addEdge(g,5,2);
    addEdge(g,4,2);
    addEdge(g,3,2);
    addEdge(g,1,0);
    printf("BFS: ");
	BFS(g,0);
	printf("\n");
	printf("\n");
	printf("Adjacency List:\n");
	display(g);
	return 0;
}
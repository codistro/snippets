#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"unionFind.h"

int divide(edgeList* e,int low,int high){
	int mid = (low + high)/2;
	edgeList temp = e[mid];
	e[mid] = e[low];
	e[low] = temp;
	int lastsmall = low;
	int pivot = e[low].weight;
	for(int i = low + 1;i < high;i++){
		if(pivot > e[i].weight){
			++lastsmall;
			temp = e[i];
			e[i] = e[lastsmall];
			e[lastsmall] = e[i];
		}
	}
	temp = e[lastsmall];
	e[lastsmall] = e[low];
	e[low] = temp;
	return lastsmall;
}


void quickSort(edgeList* e,int low,int high){
	if(low < high){
		int pivot = divide(e,low,high);
		quickSort(e,low,pivot);
		quickSort(e,pivot+1,high);
	}
}

void kruskals(graph* g,edgeList* e,int size){
	node *set[g->v];
	for(int i = 0;i < g->v;i++){
		set[i] = makeSet(i);
	}

	for(int i = 0;i<size;i++){
		int a = e[i].src;
		int b = e[i].dest;
		if(findSet(set[a]) != findSet(set[b])){
			Union(set[a],set[b]);
			printf("%d->%d(%d)\n",e[i].src,e[i].dest,e[i].weight);
		}
	}
}

int main(){
	graph* g = createGraph(4);
	addEdge(g,0,1,2);
	addEdge(g,0,2,2);
	addEdge(g,2,3,3);
	addEdge(g,1,2,1);
	addEdge(g,1,3,5);
	edgeList e[20];
	int total = getEdge(g,e);
	quickSort(e,0,total);
	//kruskals(g,e,total);
	for(int i = 0;i < total;i++)
		printf("%d ",e[i].weight);
	printf("\n");
	return 0;
}
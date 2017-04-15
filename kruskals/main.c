#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"unionFind.h"
#include"sort.h"
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
	graph* g = createGraph(6);
	addEdge(g,0,3,1);
	addEdge(g,0,1,3);
	addEdge(g,1,3,3);
	addEdge(g,1,2,1);
	addEdge(g,2,3,1);
	addEdge(g,4,3,6);
	addEdge(g,4,5,2);
	addEdge(g,4,2,5);
	addEdge(g,5,2,4);
	edgeList e[20];
	int total = getEdge(g,e);
	quickSort(e,0,total);
	kruskals(g,e,total);
	return 0;
}
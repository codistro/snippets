typedef struct eNode{
	int dest;
	int weight;
	struct eNode* next;
}eNode;

typedef struct adjList{
	eNode* head;
}adjList;

typedef struct graph{
	int v;
	adjList *arr;
}graph;


typedef struct edgeList{
	int src;
	int dest;
	int weight;
}edgeList;

eNode* createEdge(int dest,int weight){
	eNode* neweNode = (eNode*)malloc(sizeof(eNode));
	neweNode->dest = dest;
	neweNode->next = NULL;
	neweNode->weight = weight;
	return neweNode;
}

graph* createGraph(int v){
	graph *newGraph = (graph*)malloc(sizeof(graph));
	newGraph->v = v;
	newGraph->arr = (adjList*)malloc(sizeof(adjList) * v);
	for(int i = 0;i < v;i++ )
		newGraph->arr[i].head = NULL;
	return newGraph;
}

void addEdge(graph* g,int src,int dest,int weight){
	eNode* edge = createEdge(dest,weight);
	edge->next = g->arr[src].head;
	g->arr[src].head = edge;

	edge = createEdge(src,weight);
	edge->next = g->arr[dest].head;
	g->arr[dest].head = edge;
}

void displayGraph(graph* g){
	for(int v = 0;v<g->v;v++){
		printf("%d",v);
		eNode *temp = g->arr[v].head;
		while(temp){
			printf("->%d",temp->dest);
			printf("(%d)",temp->weight);
			temp = temp->next;
		}
		printf("\n");
	}
}

int getEdge(graph* g,edgeList* e){
	int i = 0;
	for(int v = 0;v<g->v;v++){
		eNode *temp = g->arr[v].head;
		while(temp){
			e[i].src = v;
			e[i].dest = temp->dest;
			e[i].weight = temp->weight;
			temp = temp->next;
			++i;
		}
	}
	return i;
}
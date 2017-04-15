typedef struct node{
	int data;
	struct node* rep;
	struct node* next;
}node;

node* makeSet(int data){
	node* newHead = (node*)malloc(sizeof(node));
	newHead->data = 1;
	node* newNode = (node*)malloc(sizeof(node));
	newNode->rep = newHead;
	newNode->next = NULL;
	newNode->data = data;
	newHead->next = newNode;
	newHead->rep = newNode;
	return newNode;
}

node* findSet(node* s){
	return s->rep;
}

node* Union(node* u,node* v){
	node* headU = findSet(u);
	node* headV = findSet(v);
	node* lastU = headU->rep;
	node* lastV = headV->rep;
	if(headU->data <= headV->data){
		lastV->next = headU->next;
		node* temp = headU->next;
		node* prev;
		while(temp){
			++headV->data;
			temp->rep = headV;
			prev = temp;
			temp = temp->next;
		}
		headV->rep = prev;
		free(headU);
		return headV->next;
	}
	else{
		lastU->next = headV->next;
		node* temp = headV->next;
		node* prev;
		while(temp){
			++headU->data;
			temp->rep = headU;
			prev = temp;
			temp = temp->next;
		}
		headU->rep = prev;
		free(headV);
		return headU->next;
	}
}

void display(node* c){
	node* temp = c;
	while(temp){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
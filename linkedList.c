#include<stdio.h>
#include<stdlib.h>

//node structure
typedef struct node{
	int data;
	struct node* next;
}node;

//creating a node
node * createNode(int data){
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->next = NULL;
	return new;
}

//adding a node at the end
void addNode(node* head,node* new){
	if(head == NULL) return;
	while(head->next != NULL)
		head = head->next;
	head->next = new;
}


//deleting a node 
void delete(node *head,int data){
	if(head == NULL) return;
	node* temp = head;
	while(head->data != data && head->next != NULL){
		temp = head;
		head = head->next;
	}
	if(head->data == data)
		temp->next = head->next;
}

//displaying a list
void traverse(node* head){
	if(head == NULL) return;
	while(head != NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int main(){
	node* head = createNode(5);
	node* second = createNode(10);
	addNode(head,second);
	node* third = createNode(15);
	addNode(head,third);
	node* fourth = createNode(20);
	addNode(head,fourth);
	delete(head,10);
	traverse(head);
	return 0;
}
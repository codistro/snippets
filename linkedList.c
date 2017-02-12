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

//adding in sorted order
void addSorted(node** head,node* new){
	if((*head) == NULL || new->data < (*head)->data){
		new->next = (*head);
		(*head) = new;
		return;
	}
	node* prev;
	node* temp = (*head)->next;
	while(temp != NULL && new->data > temp->data){
		prev = temp;
		temp = temp->next;
	}
	new->next = prev->next;
	prev->next = new;
}

//adding a node at the end
void addNode(node** head,node* new){
	if((*head) == NULL){
		(*head) = new;
	 	return;
	};
	while((*head)->next != NULL)
		(*head) = (*head)->next;
	(*head)->next = new;
}

//adding node at front
void addNodeFront(node** head,node* new){
	if((*head) == NULL){
	 	(*head) = new;
	 	return;
	}
	new->next = (*head);
	(*head) = new;	
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

//reversing the linked list
void reverse(node** head){
	if((*head) == NULL || (*head)->next == NULL){
		return;
	}
	node* prev = NULL;
	node* current = (*head);
	node* next;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	(*head) = prev;
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
	node* head = NULL;
	node* first = createNode(10);
	addSorted(&head,first);
	node* second = createNode(1);
	addSorted(&head,second);
	node* third = createNode(0);
	addSorted(&head,third);
	node* fourth = createNode(20);
	addSorted(&head,fourth);
	node* fifth = createNode(5);
	addSorted(&head,fifth);
	node* seventh = createNode(4);
	addSorted(&head,seventh);
	traverse(head);
	reverse(&head);
	traverse(head);
	return 0;
}
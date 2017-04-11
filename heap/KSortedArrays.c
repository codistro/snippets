//Merging K Sorted Arrays in O(nklog(K))

#include<stdio.h>

typedef struct KSortedArrays{
	int a[100];
	int index;
}arr;

arr p[10];

typedef struct heapNode{
	int data;
	int number;
	int track;
}heapNode;

void minHeapify(heapNode *a,int size,int i){
	int l,r,smallest;
	l = 2 * i + 1;
	r = 2 * i + 2;
	smallest = i;
	if(l < size && a[l].data < a[smallest].data)
		smallest = l;
	if(r < size && a[r].data < a[smallest].data)
		smallest = r;
	if(smallest != i){
		heapNode temp = a[i];
		a[i] = a[smallest];
		a[smallest] = temp;
		minHeapify(a,size,smallest);
	}
}

void extractMin(heapNode *a,int *size){
	int n = *(size);
	a[0] = a[n-1];
	--(*size);
	minHeapify(a,n-1,0); 
}

void KSortedArrays(arr *p,int k){
	heapNode heap[k];
	int result[200];
	int x = 0;

	//initially populatting heap with 1st element of each array
	for(int i = 0;i < k;i++){
		heap[i].data = p[i].a[0];
		heap[i].number = i;
		heap[i].track = 0;
	}
	//building heap
	for(int i = k/2;i>=0;i--)
		minHeapify(heap,k,i);
	/*for(int i = 0;i<k;i++){
		printf("data %d\tnumber %d\ttrack %d\n",heap[i].data,heap[i].number,heap[i].track);
	}*/

	while(k != -1){
		int number = heap[0].number;
		int track = heap[0].track;
		track++;
		if(heap[0].track + 1 < p[number].index){
			result[x++] = heap[0].data;
			heap[0].data = p[number].a[track];
			++heap[0].track;
			minHeapify(heap,k,0);
		}
		else{
			result[x++] = heap[0].data;
			extractMin(heap,&k);
		}
	}


	printf("\n***************After Merging***************\n");

	for(int i = 0;i< x-1;i++)
		printf("%d ",result[i]);
	printf("\n");
}

int main(){
	printf("/******************/Merging K Sorted Arrays in O(nklog(K))\\******************/\n");
	int k;
	printf("Enter the number of arrays\n");
	scanf("%d",&k);
	for(int i = 0;i < k;i++){
		int n;
		printf("Enter the size of array %d\n",i+1);
		scanf("%d",&n);
		printf("Enter the values of array %d\n",i+1);
		p[i].index = n;
		for(int j =0;j < n;j++)
			scanf("%d",&p[i].a[j]);
	}
	printf("\n************\nEntered arrays are\n****************\n\n");
	for(int i = 0;i < k;i++){
		for(int j = 0;j < p[i].index;j++)
			printf("%d ",p[i].a[j]);
		printf("\n");
	}

	KSortedArrays(p,k);
	return 0;
}
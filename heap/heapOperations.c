#include<stdio.h>
void maxHeap(int *a,int i,int size){
	int l,r,temp,largest;
	l = 2*i+1;
	r = 2*i+2;
	largest = i;
	if(l < size && a[l]>a[i])
		largest = l;
	if(r < size && a[r]>a[largest])
		largest = r;
	if(largest != i){
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		maxHeap(a,largest,size);
	}
}

//getting minimum
int maxElement(int *a){
	return a[0];
}

//extracting max
int extractMax(int *a,int *size){
	int n = (*size),max = a[0];
	a[0] = a[n-1];
	maxHeap(a,0,n-1);
	--(*size);
	return max;
}


//increasing ith element
void increaseKey(int *a,int i,int key,int size){
	if(a[i] > key){
		printf("invalid key\n");
		return;
	}
	else{
		a[i] = key;
		int j = i;
		while(j>=0 && a[j/2] < a[j]){
			int temp = a[j];
			a[j] = a[j/2];
			a[j/2] = temp;
			j = j/2;
		} 
	}
}

//inserting an element
void insert(int *a,int size,int element){
	a[size-1] = element;
	int j = size-1;
	while(j>=0 && a[j/2] < a[j]){
		int temp = a[j];
		a[j] = a[j/2];
		a[j/2] = temp;
		j = j/2;
	}
}
int main(){
	int i,a[10] = {1,2,3,4,12,6,7,8,9,0};
	int size = sizeof(a)/4;
	for(i = 5;i>=0;i--)
		maxHeap(a,i,size);

	for(i = 0;i<10;i++)
		printf("%d ",a[i]);	//12 9 7 8 2 6 3 1 4 0
	increaseKey(a,5,10,size);
	printf("\n");

	for(i = 0;i<10;i++)
		printf("%d ",a[i]);	//12 9 7 8 2 6 3 1 4 0
	printf("\n");
	insert(a,size,5);

	for(i = 0;i<10;i++)
		printf("%d ",a[i]);	//12 10 9 8 5 7 3 1 4 2 
	printf("\n");

	printf("%d\n",extractMax(a,&size));
	for(i = 0;i<size;i++)
		printf("%d ",a[i]);	//12 10 9 8 5 7 3 1 4 2 
	printf("\n");
	return 0;
}
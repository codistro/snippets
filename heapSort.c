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
void heapSort(int *a,int size){
	
	int i;

	//building heap
	for(i = size/2;i>=0;i--)
		maxHeap(a,i,10);

	//sorting
	for(i = size-1;i>=1;i--){
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		maxHeap(a,0,i);
	}
}
int main(){
	int i,a[10] = {9,8,7,6,5,4,3,2,1,0};
	heapSort(a,10);
	for(i = 0;i<10;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
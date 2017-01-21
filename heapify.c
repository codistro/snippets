#include<stdio.h>
void minHeap(int *a,int i,int size){
	int l,r,temp,smallest;
	l = 2*i+1;
	r = 2*i+2;
	smallest = i;
	if(l < size && a[l]<a[i])
		smallest = l;
	if(r < size && a[r]<a[smallest])
		smallest = r;
	if(smallest != i){
		temp = a[i];
		a[i] = a[smallest];
		a[smallest] = temp;
		minHeap(a,smallest,size);
	}
}
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
int main(){
	int i,a[10] = {9,8,7,6,5,4,3,2,1,0};
	for(i = 5;i>=0;i--)
		minHeap(a,i,10);
	for(i = 0;i<10;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
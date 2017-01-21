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
int main(){
	int i,a[10] = {0,1,2,3,4,5,6,7,8,9};
	for(i = 5;i>=0;i--)
		maxHeap(a,i,10);
	for(i = 0;i<10;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
//k smallest elements in the stream of n elements k<<n

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
	int n,k,i,x;
	printf("Enter n and k\n");
	scanf("%d%d",&n,&k);
	int a[k];
	for(i = 0;i<n;i++){
		scanf("%d",&x);
		if(i<k){
			a[i] = x;
			maxHeap(a,0,i);
		}
		else{
			if(x<a[0]){
				a[0] = x;
				maxHeap(a,0,k);
			}
		}
	}
	for(i = 0;i<k;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
int divide(edgeList* e,int low,int high){
	int mid = (low + high)/2;
	edgeList temp = e[mid];
	e[mid] = e[low];
	e[low] = temp;
	int lastsmall = low;
	int pivot = e[low].weight;
	for(int i = low + 1;i < high;i++){
		if(pivot > e[i].weight){
			++lastsmall;
			temp = e[i];
			e[i] = e[lastsmall];
			e[lastsmall] = temp;
		}
	}
	temp = e[lastsmall];
	e[lastsmall] = e[low];
	e[low] = temp;
	return lastsmall;
}


void quickSort(edgeList* e,int low,int high){
	if(low < high){
		int pivot = divide(e,low,high);
		quickSort(e,low,pivot);
		quickSort(e,pivot+1,high);
	}
}
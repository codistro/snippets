#define INF 100000
typedef struct queue{
	int front,rear,size;
	unsigned capacity;
	int *a;
}queue;

queue* createQueue(int capacity){
	queue* newQueue = (queue*)malloc(sizeof(queue));
	newQueue->capacity = capacity;
	newQueue->a = (int*)malloc(sizeof(int) * newQueue->capacity);
	newQueue->front = 0;
	newQueue->rear = newQueue->capacity - 1;
	newQueue->size = 0;
	return newQueue;
};

int isEmpty(queue* q){
	return q->size == 0;
}

int isFull(queue* q){
	return q->size == q->capacity;
}

void enQueue(queue* q,int data){
	if(isFull(q)) return;
	q->rear = (q->rear + 1)%q->capacity;
	q->a[q->rear] = data;
	q->size++;
}

int deQueue(queue* q){
	if(isEmpty(q)) return INF;
	int temp = q->a[q->front];
	q->front = (q->front + 1)%q->capacity;
	q->size--;
	return temp;
}

int frontData(queue* q){
	if(isEmpty(q)) return INF;
	return q->a[q->front]; 
}

int rearData(queue *q){
	if(isEmpty(q)) return INF;
	return q->a[q->rear];
}

void displayQueue(queue* q){
	if(isEmpty(q)) return;
	printf("queue data : ");
	for(int i = q->front; i <= q->rear;i++)
		printf("%d ",q->a[i]);
	printf("\n");
}

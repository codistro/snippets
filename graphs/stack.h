#define INF 100000
typedef struct stack{
	unsigned capacity;
	int top;
	int *a;
}stack;

stack* createStack(int capacity){
	stack* newStack = (stack*)malloc(sizeof(stack));
	newStack->capacity = capacity;
	newStack->a = (int*)malloc(sizeof(int) * newStack->capacity);
	newStack->top = -1;
}

int isFull(stack* s){
	return (s->top == (s->capacity - 1));
}

int isEmpty(stack* s){
	return (s->top == -1);
}

void push(stack* s,int data){
	if(isFull(s)) return;
	s->a[++s->top] = data;
}

int pop(stack* s){
	if(isEmpty(s)) return INF;
	return s->a[s->top--];
}

int peek(stack* s){
	if(isEmpty(s)) return INF;
	return s->a[s->top];
}

void displayStack(stack* s){
	for(int i = 0;i <= s->top;i++)
		printf("%d ",s->a[i]);
	printf("\n");
}

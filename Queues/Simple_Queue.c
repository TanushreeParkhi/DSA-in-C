#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

typedef struct{
int arr[SIZE];
int front, rear;}queue;

//Simple linear queue

int isfull(queue *q)
{
	return (q->rear==SIZE-1);
}

int isempty(queue *q)
{
	return (q->front>q->rear);
}

void enqueue(queue *q, int n)
{
	if (isfull(q))
	{
		printf("Overflow\n");
		return;
	}
	q->arr[++(q->rear)]=n;
	return;
}

int dequeue(queue *q)
{
	if (isempty(q))
	{
		printf("Underflow\n");
		return -1;
	}
	return q->arr[q->front++];
}

void display(queue *q)
{
	if (isempty(q))
	{
		printf("Empty queue\n");
		return;
	}
	for (int i=q->front; i<=q->rear; i++)
		printf("%5d", q->arr[i]);
	printf("\n");
}

int main()
{
	queue q;
	q.front=0;
	q.rear=-1;
	int ch, num;
	while (1)
	{
	printf("1.Enqueue 2.Dequeue 3. Display Enter choice: ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: printf("Enter num to insert:");
		scanf("%d", &num);
		enqueue(&q, num);
		break;
		case 2: num=dequeue(&q);
			if (num!=-1) printf("Num dequeued: %d\n", num);
			break;
		case 3: display(&q);
			break;
		default: exit(0);
	}}
	return 0;
}

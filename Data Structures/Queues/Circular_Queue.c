#include<stdio.h>
#include<stdlib.h>
#define MAX 30

typedef struct Queue{
    int a[MAX];
    int front,rear;
}queue;


int isempty(queue *q)
{
    return (q->front==-1);
}

int isfull(queue *q)
{
    return ((q->rear+1)%MAX==q->front);
}

void enq(queue *q, int n)
{
    if (isfull(q))
        printf("Overflow\n");
    else{
        if (isempty(q)) q->front=0;
        q->rear=(q->rear+1)%MAX;
        q->a[q->rear]=n;
    }
}

int deq(queue *q)
{
    if (isempty(q))
    {   printf("Underflow\n");
        return -1;
    }
    else{
        int n=q->a[q->front];
        if (q->front==q->rear) q->front=q->rear=-1;
        else q->front=(q->front+1)%MAX;
        return n;   
    }
}

void display(queue *q)
{
    if (isempty(q)) return;
    for (int i=q->front; i!=q->rear; i=(i+1)%MAX)
    {
        printf("%5d", q->a[i]);
    }
    printf("%5d\n", q->a[q->rear]);
}

int main()
{
    queue q; q.front=q.rear=-1;

    int n,ch;
    for (;;)
    {
        printf("\n1.Enq 2.Deq 3.Display\nEnter choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1: scanf("%d", &n);
                    enq(&q, n);
                    break;
            case 2: n=deq(&q);
                    if (n!=-1) printf("%d", n); 
                    break;
            case 3: display(&q);
                    break;
            default: exit(0);
        }
    }
    return 0;
}
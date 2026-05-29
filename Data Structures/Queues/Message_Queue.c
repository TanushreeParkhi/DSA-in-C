#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
char arr[MAX][MAX];
int front, rear;
}queue;

int isfull(queue *q)
{
return ((q->rear+1)%MAX==q->front);
}

int isempty(queue *q)
{
return (q->front==-1);
}

void enqueue(queue *q, char msg[])
{
if (isfull(q))
{
printf("Overflow\n");
return;
}
q->rear=(q->rear+1)%MAX;
strcpy(q->arr[q->rear], msg);
if (isempty(q)) q->front=0;
return;
}

char *dequeue(queue *q, char *msg)
{
if (isempty(q))
{
printf("Underflow\n");
return '\0';
}
strcpy(msg, q->arr[q->front]);
if (q->front==q->rear) q->front=q->rear=-1;
else q->front=(q->front+1)%MAX;
return msg;
}

void display(queue *q)
{
if (isempty(q))
{
printf("Empty queue!\n");
return;
}
for (int i=q->front; i!=q->rear; i=(i+1)%MAX)
printf("%s\t", q->arr[i]);
printf("%s\n", q->arr[q->rear]);
return;
}

int main()
{
queue q; q.front=q.rear=-1;
int ch;
char msg[MAX];

while (1)
{
printf("1.En 2. De 3. Display Enter choice:");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("Enter message to en:");
scanf("%s", msg);
enqueue(&q, msg);
break;
case 2: strcpy(msg, dequeue(&q, msg));
if (msg) printf("Message de : %s\n", msg);
break;
case 3: display(&q);
break;
default: exit(1);
}

}
return 0;
}

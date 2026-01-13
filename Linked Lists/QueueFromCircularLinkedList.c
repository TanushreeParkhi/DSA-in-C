#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
int val;
struct node *next;
};
typedef struct node node;

node *getnode(int val)
{
node *new=malloc(sizeof(node));
if (!new){
printf("Memerror\n");
exit(1);
}
new->val=val;
new->next=new;
return new;
}

node *enq(node *head, int n)
{
node *new=getnode(n);
if (!head) head=new;
else{
node *t=head;
while (t->next!=head) t=t->next;
new->next=head;
t->next=new;
}
return head;
}

node *deq(node *head)
{ if (!head){
printf("Empty\n");
return NULL;
}
node *t=head;
while (t->next!=head) t=t->next;
t->next=head->next;
printf("Deleted: %d\n", head->val);
free(head);
head=t->next;
return head;
}

void display(node *head)
{
if (!head) return;
node *t=head;
while (t->next!=head)
{ printf("%5d", t->val);
t=t->next;
}
printf("%5d\n", t->val);
}

int main()
{
node *q=NULL;
int ch, num;
while (1){
printf("1.Enq 2. Deq 3. Display Enter choice:");
scanf("%d", &ch);
switch(ch)
{ case 1: scanf("%d", &num);
q=enq(q, num);
break;
case 2: q=deq(q);
break;
case 3: display(q);
break;
default: exit(1);
}
}
return 0;
}

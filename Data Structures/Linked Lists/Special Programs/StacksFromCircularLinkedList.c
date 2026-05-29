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

node *push(node *head, int n)
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

node *pop(node *head)
{ if (!head){
printf("Empty\n");
return NULL;
}
node *t1, *t2;
t1=t2=head;
while (t1->next!=head){
t2=t1;
t1=t1->next;
}
t2->next=head;
printf("Deleted: %d\n", t1->val);
free(t1);
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
node *stack=NULL;
int ch, num;
while (1){
printf("1.Push 2. Pop 3. Display Enter choice:");
scanf("%d", &ch);
switch(ch)
{ case 1: scanf("%d", &num);
stack=push(stack, num);
break;
case 2: stack=pop(stack);
break;
case 3: display(stack);
break;
default: exit(1);
}
}
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
int coeff,degree;
struct node *next;
};
typedef struct node node;

node *getnode(int c,int d)
{
node *new=malloc(sizeof(node));
if (!new){
printf("Memerror");
exit(1);
}

new->coeff=c;
new->degree=d;
new->next=NULL;
return new;
}

node *insert(node *head, int c, int d)
{
if (!head) return getnode(c,d);
node *temp=head;
while (temp->next) temp=temp->next;
temp->next=getnode(c,d);
return head;
}

node *organise(node *head, int c, int d)
{
if (!head){
head=getnode(c,d);
return head;
}
else{
node *temp=head;
while(temp!=NULL)
{ if (temp->degree==d)
{ temp->coeff+=c;
return head;
}
temp=temp->next;
}
return insert(head, c,d);
}
}


node *multiply(node *p1, node *p2, node *res)
{
if (!p1) return p2;
if (!p2) return p1;
node *t1,*t2;
t1=p1;
while (t1)
{ t2=p2;
while (t2)
{ res=organise(res, t1->coeff*t2->coeff, t1->degree+t2->degree);
t2=t2->next;
}
t1=t1->next;
}
return res;
}

void display(node *head)
{ node *temp=head;
while(temp)
{ printf("%dx^%d", temp->coeff, temp->degree);
if (temp->next) printf("+");
temp=temp->next;
}
printf("\n");
}

int main()
{ node *p1, *p2;
p1=p2=NULL;
int c,d;
printf("Enter degrees of both poly:");
int n1,n2;
scanf("%d%d", &n1, &n2);
int i;
for(i=0; i<=n1; i++)
{ printf("Enter coeff, degree:");
scanf("%d%d", &c, &d);
p1=insert(p1, c,d);
}
for(i=0; i<=n2; i++)
{ printf("Enter coeff, degree:");
scanf("%d%d", &c, &d);
p2=insert(p2, c,d);
}
node *res=NULL;

res=multiply(p1,p2,res);
display(res);
return 0;
}

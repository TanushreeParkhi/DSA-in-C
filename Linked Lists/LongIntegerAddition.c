#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
int data;
struct node *next;};

typedef struct node node;

node *getnode(int a)
{
node *new=(node *)malloc(sizeof(node));
if (!new)
{
return NULL;
}
new->data=a; new->next=NULL;
return new;
}


node *insert_front(node *head, int a)
{
node *new=getnode(a);
if (!head) return new;
new->next=head;
return new;
}

node *add(node *num1, node *num2, node *res)
{
int carry=0, sum=0;
if (!num1) return num2;
if (!num2) return num1;
node *p1,*p2;
p1=num1, p2=num2;

while (p1 && p2)
{
sum=p1->data+p2->data+carry;
carry=sum/10;
res=insert_front(res, sum%10);
p1=p1->next; p2=p2->next;
}
while (p1)
{
sum=p1->data+carry;
carry=sum/10;
res=insert_front(res, sum%10);
p1=p1->next;
}
while (p2)
{
sum=p2->data+carry;
carry=sum/10;
res=insert_front(res, sum%10);
p2=p2->next;
}
while (carry)
{
res=insert_front(res, carry);
carry/=10;
}
return res;
}

int main()
{
node *h1, *h2, *res;
h1=h2=res=NULL;

printf("Enter first num:\n");
char num1[20], num2[20];
scanf("%s", num1);
printf("Enter second num:\n");
scanf("%s", num2);

int i;
for(i=0; num1[i]!='\0'; i++) h1=insert_front(h1, num1[i]-'0');
for(i=0; num2[i]!='\0'; i++) h2=insert_front(h2, num2[i]-'0');
res=add(h1,h2,res);
printf("Sum:");
node *t=res;
while (t){
printf("%d", t->data);
t=t->next;
}
//free(h1); free(h2); free(t); free(res);
return 0;
}

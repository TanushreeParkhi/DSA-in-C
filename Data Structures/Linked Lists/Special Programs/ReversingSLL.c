#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}node;

node *getnode(int val)
{
    node *new=malloc(sizeof(node));
    if (!new)
    {
        printf("Memerror\n");
        exit(1);
    }
    new->data=val; new->link=NULL;
    return new;
}

node *insert(node *head, int val)
{
    if (!head) return getnode(val);
    node *new=getnode(val);
    new->link=head;
    return new;
}

node *reverse(node *head)
{
    node *temp,*prev;
    prev=NULL;
    while (head)
    {
        temp=head->link;
        head->link=prev;
        prev=head;
        head=temp;
    }
    return prev;
}

void display(node *head)
{
    if (!head) return;
    node *t=head;
    while (t)
    {
        printf("%5d", t->data);
        t=t->link;
    }
}


int main()
{   node *ll=NULL;
    int n,ch;
    while (1)
    {
        printf("1.Insert 2.Reverse 3.Display\nEnter choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: scanf("%d", &n);
                    ll=insert(ll, n);
                    break;
            case 2: ll=reverse(ll);
                    break;
            case 3: display(ll);
                    break;
            default: exit(0);
        }

    }
}
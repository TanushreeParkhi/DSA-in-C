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
    new->data=val; new->link=new;
    return new;
}

node *insert_front(node *head, int val)
{
    if (!head) return getnode(val);
    node *new=getnode(val);
    new->link=head;
    node *t=head;
    while (t->link!=head) t=t->link;
    t->link=new;
    return new;
}

node *insert_rear(node *head, int val)
{
    if (!head) return getnode(val);
    node *new=getnode(val);
    node *temp=head;
    while (temp->link!=head) temp=temp->link;
    temp->link=new;
    new->link=head;
    return head;
}

void display(node *head)
{
    if (!head) return;
    node *t=head;
    while (t->link!=head)
    {
        printf("%5d", t->data);
        t=t->link;
    }
    printf("%5d\n", t->data);
}

node *delete_front(node *head)
{
    if (!head) return NULL;
    if (head==head->link){
        printf("Deleted %d\n", head->data);
        free(head);
        return NULL;
    }
    node *t=head;
    while (t->link!=head) t=t->link;
    t->link=head->link;
    t=head->link;
    printf("Deleted %d\n", head->data);
    free(head);
    return t;
}

node *delete_rear(node *head)
{
    if (!head) return NULL;
    if (head==head->link){
        printf("Deleted %d\n", head->data);
        free(head);
        return NULL;
    }
    node *prev, *curr;
    prev=curr=head;
    while (curr->link!=head)
    {
        prev=curr;
        curr=curr->link;
    }
    printf("Deleted %d\n", curr->data);
    prev->link=head;
    free(curr);
    return head;
}


int main()
{
	node *ll=NULL;
	int ch,n;
	while (1)
	{
		printf("1. Insert front, 2. Insert rear, 3.Delete front, 4.Delete rear, 5.Display\nEnter choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: scanf("%d", &n);
				ll=insert_front(ll, n);
				break;
			case 2: scanf("%d", &n);
				ll=insert_rear(ll, n);
				break;
			case 3: ll=delete_front(ll);
				break;
			case 4: ll=delete_rear(ll);
				break;
			case 5: display(ll);
			    break;
			default: exit(0);
		}
	}
	return 0;
}
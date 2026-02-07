#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev, *next;
}node;

node *getnode(int val)
{
    node *new=malloc(sizeof(node));
    if (!new)
    {
        printf("Memerror\n");
        exit(1);
    }
    new->data=val; new->prev=new->next=NULL;
    return new;
}

node *insert_front(node *head, int val)
{
    if (!head) return getnode(val);
    node *new=getnode(val);
    new->next=head;
    head->prev=new;
    return new;
}

node *insert_rear(node *head, int val)
{
    if (!head) return getnode(val);
    node *new=getnode(val);
    node *temp=head;
    while (temp->next!=NULL) temp=temp->next;
    temp->next=new;
    new->prev=temp;
    return head;
}

void display(node *head)
{
    if (!head) return;
    node *t=head;
    while (t)
    {
        printf("%5d", t->data);
        t=t->next;
    }
}

node *delete_front(node *head)
{
    if (!head) return NULL;
    if (head->next==NULL){
        printf("Deleted %d\n", head->data);
        free(head);
        return NULL;
    }
    node *t=head->next;
    t->prev=NULL;
    printf("Deleted %d\n", head->data);
    free(head);
    return t;
}

node *delete_rear(node *head)
{
    if (!head) return NULL;
    if (!head->next) return delete_front(head);
    node *curr=head;
    while (curr->next)
        curr=curr->next;
    printf("Deleted %d\n", curr->data);
    curr->prev->next=NULL;
    free(curr);
    return head;
}

int main()
{
	node *ll=NULL;
	int ch,n, pos;
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
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

node *insert_front(node *head, int val)
{
    if (!head) return getnode(val);
    node *new=getnode(val);
    new->link=head;
    return new;
}

node *insert_rear(node *head, int val)
{
    if (!head) return getnode(val);
    node *new=getnode(val);
    node *temp=head;
    while (temp->link!=NULL) temp=temp->link;
    temp->link=new;
    return head;
}

node *insert_pos(node *head, int n, int val)
{
    if (!head || n==1) return insert_front(head, val);
    node *new=getnode(val);
    node *temp=head;
    int i=0;
    for (; i<n-1 && temp->link!=NULL; i++)
        temp=temp->link;
    new->link=temp->link;
    temp->link=new;
    return head;
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

node *delete_front(node *head)
{
    if (!head) return NULL;
    node *t=head->link;
    printf("Deleted %d\n", head->data);
    free(head);
    return t;
}

node *delete_rear(node *head)
{
    if (!head) return NULL;
    if (!head->link) return delete_front(head);
    node *prev, *curr;
    prev=curr=head;
    while (curr->link)
    {
        prev=curr;
        curr=curr->link;
    }
    printf("Deleted %d\n", curr->data);
    prev->link=NULL;
    free(curr);
    return head;
}

node *delete_pos(node *head, int n)
{
    if (!head) return NULL;
    if (n==1) return delete_front(head);
    node *prev,*curr;
    prev=curr=head;
    int i;
    for (i=1; i<n && curr->link!=NULL; i++)
    {
        prev=curr;
        curr=curr->link;
    }
    prev->link=curr->link;
    printf("Deleted %d\n", curr->data);
    free(curr);
    return head;
}

int main()
{
	node *ll=NULL;
	int ch,n, pos;
	while (1)
	{
		printf("1. Insert front, 2. Insert rear, 3.Insert position, 4.Delete front, 5.Delete rear, 6.Delete position, 7.Display\nEnter choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: scanf("%d", &n);
				ll=insert_front(ll, n);
				break;
			case 2: scanf("%d", &n);
				ll=insert_rear(ll, n);
				break;
			case 3: scanf("%d", &n);
                    printf("Enter position to insert: ");
                    scanf("%d", &pos);
                    ll=insert_pos(ll, pos, n);
                    break;
            case 4: ll=delete_front(ll);
				break;
			case 5: ll=delete_rear(ll);
				break;
			case 6: printf("Enter position to delete: ");
                    scanf("%d", &pos);
                    ll=delete_pos(ll, pos);
                    break;
            case 7: display(ll);
			        break;
			default: exit(0);
		}
	}
	return 0;
}
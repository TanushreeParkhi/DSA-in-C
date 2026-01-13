#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
int val;
struct node *next,*prev;
};
typedef struct node node;

node *getnode(int a)
{
	node *new=malloc(sizeof(node));
	if (!new){	printf("Memerror\n");
	exit(1);
	}
	
	new->val=a;
	new->next=new->prev=new;
	return new;
}

node *insert_front(node *head, int a)
{
	node *new=getnode(a);
	if (!head) return new;
	new->prev=head->prev;
	head->prev->next=new;
	head->prev=new;
	new->next=head;
	return new;
}

node *delete_front(node *head)
{
	if (!head){ printf("Empty LL\n");
	return NULL;}
	head->prev->next=head->next;
	head->next->prev=head->prev;
	printf("Deleted: %d\n", head->val);
	node *t=head->next;
	free(head);
	return t;
}




node *insert_rear(node *head, int a)
{
	node *new=getnode(a);
	if (!head) return new;
	new->prev=head->prev;
	head->prev->next=new;
	head->prev=new;
	new->next=head;
	return head;
}

node *delete_rear(node *head)
{
	if (!head){ printf("Empty LL\n");
	return NULL;}
	node *t=head->prev;
	
	head->prev=t->prev;
	t->prev->next=head;
	printf("Deleted: %d\n", t->val);
	free(t);
	return head;
}

void display(node *head)
{
	node *t=head;
	if (!t){
		printf("Empty list\n");
		return;
	}
	while (t->next!=head)
	{
		printf("%5d", t->val);
		t=t->next;
	}
	printf("%d\n", t->val);
	return;
}

int main()
{
	node *ll=NULL;
	int ch,n;
	while (1)
	{
		printf("1. Ins f, 2. ins rear, 3. delete fr, 4. delete rear, 5. dispaly Enter ch:");
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

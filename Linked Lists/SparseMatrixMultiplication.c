#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
int row, col, val;
struct node *next;
};
typedef struct node node;

node *getnode(int c, int r, int val)
{
	node *new=malloc(sizeof(node));
	if (!new){
		printf("Memerror\n");
		exit(1);
	}
	new->val=val;
	new->col=c;
	new->row=r;
	new->next=NULL;
	return new;
}

node *insert(node *head, int n, int r, int c)
{	
	node *new=getnode(n,r,c);
	if (!head) head=new;
	else{
		node *t=head;
		while (t->next!=NULL) t=t->next;
		t->next=new;
	}
	return head;
}

void display(node *head, int rows, int cols)
{	node *t=head;
	int i,j;
	for (i=0; i<rows; i++)
	{
		for (j=0; j<cols; j++)
		{
			if (t && t->row==i && t->col==j)
			{	printf("%5d", t->val);
				 t=t->next;
			}
			else
				printf("%5d", 0);
		}
		printf("\n");
	}
}

int main()
{
	node *mat=NULL;
	printf("ENter no. of rows, cols, non-zero entries:");
	int rows, cols, n;
	scanf("%d%d%d", &rows, &cols, &n);
	int i;
	for (i=0; i<n; i++)
	{
		printf("Enter row, col, value:");
		int rno, cno, value;
		scanf("%d%d%d", &rno, &cno, &value);
		mat=insert(mat, rno, cno, value);
	}
	display(mat, rows, cols);
	return 0;
}

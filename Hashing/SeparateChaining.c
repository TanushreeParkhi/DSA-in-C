#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct Node{
    int data;
    struct Node *link;
}node;

node *table[SIZE];

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

node *insert_rear(node *head, int val)
{
    if (!head) return getnode(val);
    node *new=getnode(val);
    node *temp=head;
    while (temp->link!=NULL) temp=temp->link;
    temp->link=new;
    return head;
}

int hash(int x)
{
    return x%SIZE; 
}

void initialise()
{
    for (int i=0; i<SIZE; i++)  table[i]=NULL;
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d : ", i);
        if (!table[i])
        {
            printf("Empty");
        }
        else
        {
            node *temp = table[i];
            while (temp)
            {
                printf("%d -> ", temp->data);
                temp = temp->link;
            }
            printf("NULL");
        }
        printf("\n");
    }
}


void insert(int x)
{
    int h=hash(x);
    table[h]=insert_rear(table[h], x);
}

/*
int find(int x)
{
    int h=hash(x);
    if (table[h]==x)
        {
            return h;
        }
    }
    return -1;
}

*/

int main()
{
    initialise();
    int ch, num;
    while(1)
    {
        printf("1.Insert 2.Display\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter element to insert: ");
                    scanf("%d", &num);
                    insert(num);
                    break;
            case 2: display();
                    break;
            default: exit(0);
        }
    }
    return 0;
}
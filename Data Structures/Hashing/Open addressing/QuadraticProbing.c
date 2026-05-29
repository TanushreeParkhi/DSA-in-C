#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int table[SIZE];

int hash(int x)
{
    return x%SIZE; 
}

void initialise()
{
    for (int i=0; i<SIZE; i++)  table[i]=-1;
}

void display()
{
    for (int i=0; i<SIZE; i++)
    {
        if (table[i]==-1)   printf("Empty\n");
        else printf("%d\n", table[i]);
    }
}

void insert(int x)
{
    for (int i=0; i<SIZE; i++)
    {
        int h=(hash(x)+i*i)%SIZE;
        if (table[h]==-1)
        {
            table[h]=x;
            return;
        }
    }
    printf("Table is full\n");
}

int find(int x)
{
    for (int i=0; i<SIZE; i++)
    {
        int h=(hash(x)+i*i)%SIZE;
        if (table[h]==x)
        {
            return h;
        }
    }
    return -1;
}

void delete(int x)
{
    int h=find(x);
    if (h==-1)
    { printf("Element not present");
    return;}
    table[h]=-1;
    printf("Deleted %d at %d\n", x, h);
    return;
}

int main()
{
    int n,i,ch;
    initialise();
    while (1)
    {
        printf("1.Insert 2.Delete 3.Search 4.Display\nEnter choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: scanf("%d", &n);
                    insert(n);
                    break;
            case 2: scanf("%d", &n);
                    delete(n);
                    break;
            case 3: scanf("%d", &n);
                    i=find(n);
                    if (i!=-1) printf("Element %d found at %d\n", n, i);
                    else printf("Element not found\n");
                    break;
            case 4: display();
                    break;
            default: exit(0);
        }
    }
}
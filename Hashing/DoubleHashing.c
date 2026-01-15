#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define R 7

int table[SIZE];

void init()
{
    int i;
    for (i=0; i<SIZE; i++)
        table[i]=-1;
}

int h1(int x)
{
    return x%SIZE;
}

int h2(int x)
{
    return R-x%R;
}

void insert(int x)
{
    int i;
    for (i=0; i<SIZE; i++)
    {
        int num=(h1(x)+i*h2(x))%SIZE;
        if (table[num]==-1)
        {
            table[num]=x;
            return;
        }
    }
    printf("Table full.No more insertions\n");
}

int search(int x)
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        int n=(h1(x)+i*h2(x))%SIZE;
        if (table[n]==x)
        {
            return n;
        }
    }
    return -1;
}

void delete(int x)
{
    int num=search(x);
    if (num==-1)
    {
        printf("Element not present in the table.\n");
        return;
    }
    table[num]=-1;
}

void display()
{
    int i;
    for (i=0; i<SIZE; i++)
    {
        if (table[i]==-1)
        {
            printf("EMpty at index %d\n", i);
        }
        else printf("%d at index %d\n", table[i], i);
    }
}
int main()
{
    init();
    int ch, num, res;
    while(1)
    {
        printf("1.Insert 2.Delete 3.Search 4.Display\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter element to insert: ");
                    scanf("%d", &num);
                    insert(num);
                    break;
            case 2: printf("Enter element to delete: ");
                    scanf("%d", &num);
                    delete(num);
                    break;
            case 3: printf("Enter element to search: ");
                    scanf("%d", &num);
                    res=search(num);
                    if (res==-1) printf("Element not present\n");
                    else printf("Element present at index %d\n", res);
                    break;
            case 4: display();
                    break;
            default: exit(0);
        }
    }
    return 0;
}
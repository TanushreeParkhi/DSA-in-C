#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20

typedef struct Node{
    char data;
    struct Node *left, *right;
}node;

typedef struct Stacks{
    node *arr[MAX];
    int top;
}stack;

void push(node *root, stack *s)
{
    if (s->top==MAX-1)
        exit(1);
    s->arr[++(s->top)]=root;
}

node *pop(stack *s)
{
    if (s->top==-1)
        exit(1);
    return s->arr[s->top--];
}

node *createnode(char c)
{
    node *new=malloc(sizeof(node));
    if (!new) exit(1);
    new->data=c; new->left=new->right=NULL;
    return new;
}

int precedence(char c)
{
    switch(c)
    {
        case '^':
        case '$': return 5;
        case '*':
        case'/': return 3;
        case  '+':
        case '-': return 1;
        default: return 0;
    }
}

node *expTree(char exp[])
{
    node *symb=NULL;
    int i;
    stack TS; TS.top=-1;
    stack OS; OS.top=-1;

    for(i=0; exp[i]!='\0'; i++)
    {
        symb=createnode(exp[i]);
        if (isalnum(symb->data))
        {
            push(symb, &TS);
        }
        else if (symb->data=='(')
            push(symb, &OS);
        else if (symb->data==')')
        {
            while(OS.top!=-1 && OS.arr[OS.top]->data!='(')
            {
                node *temp=pop(&OS);
                    node *rop=pop(&TS);
                    node *lop=pop(&TS);
                    temp->left=lop; temp->right=rop;
                    push(temp, &TS);
            }
            pop(&OS);
            
        }
        else{
            if (OS.top==-1)
                push(symb, &OS);
            else if (precedence(symb->data)<=precedence(OS.arr[OS.top]->data))
            {
                while (OS.top!=-1 && precedence(symb->data)<=precedence(OS.arr[OS.top]->data))
                {
                    node *temp=pop(&OS);
                    node *rop=pop(&TS);
                    node *lop=pop(&TS);
                    temp->left=lop; temp->right=rop;
                    push(temp, &TS);
                }
                push(symb, &OS);
            }
            else push(symb, &OS);
        }
    }
    while (OS.top!=-1)
    {
        node *temp=pop(&OS);
        node *rop=pop(&TS);
        node *lop=pop(&TS);
        temp->left=lop; temp->right=rop;
        push(temp, &TS);
    }
    return pop(&TS);
}

void inorder(node *tree)
{
    if (tree)
    {
        inorder(tree->left);
        printf("%c", tree->data);
        inorder(tree->right);
    }
}

void preorder(node *tree)
{
    if (tree)
    {
        printf("%c", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(node *tree)
{
    if (tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%c", tree->data);
    }
}

int main()
{
    printf("Enter an infix expression:");;
    char exp[MAX];
    scanf("%s", exp);
    node *tree=expTree(exp);
    printf("\nInfix exp: "); inorder(tree);
    printf("\nPrefix exp: "); preorder(tree);
    printf("\nPostfix exp: "); postorder(tree);
    return 0;
}
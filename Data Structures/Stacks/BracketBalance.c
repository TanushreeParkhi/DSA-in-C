#include<stdio.h>
#include<stdlib.h>
#define MAX 20

//BRACKET BALANCING PROGRAM

struct STACK{
char arr[MAX];
int top;
};

typedef struct STACK stack;

void push(stack *s, char ch)
{ if (s->top==MAX-1)
{ printf("Overflow\n");
exit(1);
}
s->arr[++(s->top)]=ch;
}

char pop(stack *s)
{ if (s->top==-1)
{ printf("Underflow\n");
exit(1);
}
return s->arr[s->top--];
}

int main()
{ stack s; s.top=-1;
char c, x;
char expression[MAX];
printf("Enter an expression to check for brackets balancing:\n");
scanf("%s", expression);

int i=0;
while (expression[i]!='\0')
{ c=expression[i++];
if (c==')' || c==']' || c=='}')
{
x=pop(&s);
if ((x!='(' && c==')') || (x!='{' && c=='}') || (x!='[' && c==']'))
{ printf("Unbalanced brackets\n");
exit(0);
}
}
else push(&s, c);
}
if (s.top!=-1)
{ printf("Unbalanced brackets\n");
return 0;
}
printf("Balanced expression\n");
return 0;
}

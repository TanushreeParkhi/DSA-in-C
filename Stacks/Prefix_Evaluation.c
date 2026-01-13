#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 20

typedef struct{
int a[MAX];
int top;
}stack;

void push(stack *s, int c)
{
if (s->top==MAX-1)
{ printf("Overflow\n");
exit(1);
}
s->a[++(s->top)]=c;
}

char pop(stack *s)
{ if (s->top==-1)
{ printf("Underflow\n");
exit(1);
}
return s->a[s->top--];
}

int compute(int op1, int op2, char c)
{ switch(c)
{ case '$':return pow(op2, op1);
case '*':return op2*op1;
case '/':return op2/op1;
case '+':return op2+op1;
case '-': return op2-op1;
default: return 0;
}
}

int main()
{
stack s;
s.top=-1;
char pre[MAX];
printf("Enter a postfix expression:\n");
scanf("%s", pre);

int i,j=0;
while(pre[j++]!='\0');
j--;
for (i=j-1; i!=0; i--)
{ char chr=pre[i];
if(isdigit(chr))
push(&s, chr-'0');
else
{ int op1=pop(&s);
int op2=pop(&s);
push(&s, compute(op1, op2, chr));
}
}

printf("Evaluated expression: %d\n", pop(&s));
return 0;
}

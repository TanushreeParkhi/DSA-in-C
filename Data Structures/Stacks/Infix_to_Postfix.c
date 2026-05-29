#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 20

struct STACK {
char arr[MAX];
int top;
};

typedef struct STACK stack;

void push(stack *, char);
char pop(stack *);

int precedence(char);

int main()
{ int i,j=0;
stack s;
s.top=-1;

char infix[MAX], postfix[MAX];
printf("Enter an infix expression:\n");
gets(infix);

for(i=0; infix[i]!='\0'; i++)
{ char c=infix[i];
if (c=='(')
push(&s, c);
else if(isalpha(c))
postfix[j++]=c;
else if (c==')')
{ while(s.top!=-1 && s.arr[s.top]!='(')
postfix[j++]=pop(&s);
pop(&s); //to eliminate ((
}
//operator condition
else if (s.arr[s.top]=='$' && c=='$')
push(&s, c);
else if (precedence(s.arr[s.top])>=precedence(c))
{ while(precedence(s.arr[s.top])>=precedence(c))
postfix[j++]=pop(&s);
push(&s, c);
}
else push(&s, c);
}

while(s.top!=-1)
postfix[j++]=pop(&s);
postfix[j]='\0';
printf("Postfix for of the above expression is: %s\n", postfix);

return 0;
}

void push(stack *s, char ch)
{ if (s->top==MAX-1)
{ printf("Overflow\n");
exit(1);
}
s->arr[++(s->top)]= ch;
}

char pop(stack *s)
{ if (s->top==-1)
{ printf("Underflow\n");
exit(1);
}
return s->arr[s->top--];
}

int precedence(char c)
{ if (c=='$')
return 7;
else if (c=='*' || c=='/')
return 5;
else if (c=='+' || c=='-')
return 3;
else return 1;
}

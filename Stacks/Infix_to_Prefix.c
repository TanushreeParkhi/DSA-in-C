#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 20

typedef struct{
char a[MAX];
int top;
}stack;

void push(stack *s, char c)
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

int precedence(char c)
{ switch(c)
{ case '$':return 7;
case '*':
case '/':return 5;
case '+':
case '-': return 3;
default: return 1;
}
}

int main()
{ stack s;
s.top=-1;

char inf[MAX], pre[MAX], rev[MAX];
int i, j=0;

printf("Enter the infix expression:\n");
scanf("%s", inf);
int n=strlen(inf);

for(i=n-1; i>=0; i--)
{ switch(inf[i])
{ case '(': rev[j++]=')';
 break;
case ')': rev[j++]='(';
 break;
default:rev[j++]=inf[i];
}
}
i=j=0;

for(i=0; inf[i]!='\0'; i++)
{ char c=rev[i];

if (c=='(')
push(&s, c);
else if (c==')')
{ while(s.top!=-1 && s.a[s.top]!='(')
pre[j++]=pop(&s);
pop(&s);
}
else if (isalnum(c))
pre[j++]=c;
else if(c=='$' && s.a[s.top]=='$')
{ pre[j++]=pop(&s);
push(&s, c);
}
else if (precedence(c)<precedence(s.a[s.top]))
{ while(s.top!=-1 && precedence(c)<precedence(s.a[s.top]))
pre[j++]=pop(&s);
push(&s, c);
}
else push(&s, c);
}
while(s.top!=-1)
pre[j++]=pop(&s);

pre[j]='\0';
char rev_pre[MAX];

for (i=0; i<j; i++)
rev_pre[i]=pre[j-i-1];
rev_pre[j]='\0';
printf("Prefix form of expression: %s\n", rev_pre);

return 0;
}



#include<stdio.h>

#define MAX 256

char text[100], pattern[30];
int table[MAX];
int m=0, n=0;
    
    
void shiftTable(char pattern[], int m)
{
    for (int i=0; i<MAX; i++) table[i]=m;
    
    for (int i=0; i<m-1; i++) table[(int)pattern[i]]=m-i-1;
}

int Horspool(char pattern[], int m, char text[],int n)
{
    shiftTable(pattern, m);
    
    int i,k,j;
    i=m-1;
    
    while (i<n)
    {
        k=0;
        while (k<m && pattern[m-1-k]==text[i-k]) k++;
        if (k==m) return i-m+1; //position
        //else
        i+=table[(unsigned char)text[i]];
    }
    return -1;
}

int main()
{
    printf("Enter a sentence:\n");
    while ((text[n++]=getchar())!='\n');
    n--;
    printf("Enter a pattern:");
    while ((pattern[m++]=getchar())!='\n');
    m--;
    
    int res=Horspool(pattern, m, text, n);
    if (res==-1) printf("Pattern not found");
    else printf("Pattern found at position %d", res);
    return 0;
}

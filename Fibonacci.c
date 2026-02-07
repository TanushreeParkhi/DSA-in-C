#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n)
{
    if (n<=1)
        return 0;
    if (n==2)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    printf("Enter no of terms: ");
    int n;
    scanf("%d", &n);
    printf("Sequence is:\n");
    for (int i=1; i<=n; i++)
        printf("%5d", fibonacci(i));
}

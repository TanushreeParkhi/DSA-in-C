//Knapsack using memory function

#include<stdio.h>
#include<string.h>


int ks[30][30];

int knapsack(int n, int caps, int wt[], int val[])
{
    if ((n&&caps)==0) return 0;  //Either of them is 0-> leave
    
    if (ks[n][caps]!=-1) return ks[n][caps]; //Pre-calculated
    
    if (wt[n-1]>caps) return ks[n][caps]=knapsack(n-1, caps, wt, val); //too heavy
    
    
    int c1, c2;
    c1=val[n-1]+knapsack(n-1, caps-wt[n-1], wt, val);
    
    c2=knapsack(n-1, caps, wt, val);
    
    ks[n][caps]=c1>c2? c1: c2;
    
    return ks[n][caps];
}


int main()
{
    int n, caps, wt[30], val[30];
    printf("Enter capacity, no. of items:");
    scanf("%d%d", &caps, &n);
    
    printf("Enter weights array:\n");
    for (int i=0; i<n; i++) scanf("%d", &wt[i]);
    
    printf("Enter values array:\n");
    for (int i=0; i<n; i++) scanf("%d", &val[i]);
    
    memset(ks, -1, sizeof(ks));
    
    int res=knapsack(n, caps, wt, val);
    printf("Max value= %d", res);
    return 0;
}

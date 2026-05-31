#include <stdio.h>

void BFS(int a[10][10], int n, int start)
{
    //Perform BFS traversal here
    int i,j, v, q[10], visited[10], front=0, rear=0;
    for (i=0; i<n; i++) visited[i]=0;
    visited[start]=1;
    q[rear++]=start;
    
    while (front<rear)
    {
        v=q[front++];
        for(i=0; i<n; i++)
        {   if (a[v][i] && !(visited[i]))
        //edge
            { q[rear++]=i; visited[i]=1; }
        }
        printf("%5d", v);
    }
}


int main()
{
    int n,i,j, a[10][10];
    printf("Enter no. of nodes:");
    scanf("%d", &n);
    printf("Enter adjacency matrix:");;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++)
        scanf("%d", &a[i][j]);
    }
    printf("BFS traversal:\n");
    BFS(a,n,0);
    
    return 0;
}

//Floyd Warshall algorithm

#include<stdio.h>

#define INF 999

int g[10][10];

void fw_algo(int g[10][10], int n)
{
    int i,j,k;
    for (i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            for (k=0; k<n; k++)
            {
                if (g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            printf("%5d", g[i][j]);
        printf("\n");
    }
}


int main()
{
    printf("Enter vertices, distance matrix (999 for infinity):\n");
    int n;
    scanf("%d", &n);
    int i,j;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++)
            scanf("%d", &g[i][j]);
    }
    printf("Shortest paths:\n");
    fw_algo(g,n);
    return 0;
}

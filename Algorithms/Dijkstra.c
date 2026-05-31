#include <stdio.h>

#define INF 999

int g[10][10];
int visited[10], dist[10];

void dijkstra(int g[10][10], int n, int src)
{
    int i, j, v, min;

    // initialize
    for(i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(i = 0; i < n - 1; i++)
    {
        min = INF;
        v = -1;

        // pick nearest unvisited vertex
        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                v = j;
            }
        }

        // safety check
        if(v == -1) break;

        visited[v] = 1;

        // relax neighbors
        for(j = 0; j < n; j++)
        {
            if(g[v][j] &&
               !visited[j] &&
               dist[v] + g[v][j] < dist[j])
            {
                dist[j] = dist[v] + g[v][j];
            }
        }
    }
}

int main()
{
    int n, i, j;

    printf("Enter no. of vertices:\n");
    scanf("%d", &n);

    printf("Enter weighted matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    dijkstra(g, n, 0);

    printf("Vertex\tDistance\n");

    for(i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);

    return 0;
}

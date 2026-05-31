//Topological sorting using DFS

#include<stdio.h>

int a[10][10], temp[10], visited[10], n, i, j, k;

void DFS(int a[10][10], int s)
{
	visited[s]=1;
	for (int v=0; v<n; v++)
	{
		if (!visited[v]  && a[s][v])//not visited neighbour
			DFS(a,v);
	}
	temp[k++]=s;
}

void TS(int a[10][10], int n)
{
	for (int i=0; i<n; i++)
	{
	   if (!visited[i]) DFS(a, i);
	}
	for (i=k-1; i>=0; i--) printf("%5d", temp[i]);
}


int main()
{
	printf("Enter no. of nodes:");
	scanf("%d", &n);
	printf("Enter adjacency matrix:");;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	}
	printf("Topological sorting:\n");
	TS(a,n);
	return 0;
}

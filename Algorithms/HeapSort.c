//Heapsort
#include<stdio.h>

int a[30],n;

void Heapify(int a[10], int n)
{
	//Build a max heap from a

	int i,j,k,parent, heap;

	for (i=n/2-1; i>=0; i--) {
		parent=a[i];
		int k=2*i+1;
		heap=0;
		while (!heap && k<n) //Has children
		{
			if (k+1<n) //Second child exists
				k=a[k]>a[k+1]? k:k+1; //Maximum  of both children

			if (parent>=a[k]) heap=1;
			else {
				a[(k-1)/2]=a[k];
				k=2*k+1;
			}
			a[(k-1)/2]=parent;
		}
	}
}


void Heapsort(int a[30], int n)
{
	if (n<=0) return;

	while (n>0)
	{
		printf("%5d", a[0]);
		a[0]=a[n-1];
		n--;
		Heapify(a,n);
	}
}


int main()
{
	printf("Enter size, elements of heap:");
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	Heapify(a, n);

	Heapsort(a, n);
	return 0;
}

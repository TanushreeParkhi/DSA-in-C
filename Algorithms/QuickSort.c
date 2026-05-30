#include<stdio.h>

int partition(int a[], int low, int high)
{
    int p=a[low],i=low+1, j=high;
    while (i<=j)
    {
        while (i<=high && a[i]<=p) i++;
        while (j>=low && a[j]>p) j--;
        if (i<j)
        {
                int t=a[i]; a[i]=a[j]; a[j]=t;
        }
    }
    int t=a[j]; a[j]=p; a[low]=t;
    return j;
}

void QuickSort(int a[], int low, int high)
{
    if (low>=high) return;
    int p=partition(a, low, high);
    QuickSort(a, low, p-1);
    QuickSort(a, p+1, high);
}

int main()
{
    printf("Enter size of array, elements of array:");
    int n, a[30];
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    printf("\nArray before sorting:\n");
    for (int i=0; i<n; i++) printf("%5d",a[i]);

    QuickSort(a, 0, n-1);

    printf("\nArray after sorting:\n");
    for (int i=0; i<n; i++) printf("%5d",a[i]);
    return 0;
}
#include<stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    //Merges 2 arrays
    int new[30];

    int i,j,k; i=low; j=mid+1; k=0;

    while (i<=mid && j<=high)
    {
        if (arr[i]<arr[j]) new[k++]=arr[i++];
        else new[k++]=arr[j++];
    }
    while (i<=mid) new[k++]=arr[i++];
    while (j<=high) new[k++]=arr[j++];
    for (i=low; i<=high; i++) arr[i]=new[i-low];
}

void MergeSort(int arr[], int low, int high)
{
    if (low>=high) return;
    int mid=(high+low)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main()
{
    printf("Enter size of array, elements of array:");
    int n, arr[30];
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);

    printf("\nArray before sorting:\n");
    for (int i=0; i<n; i++) printf("%5d",arr[i]);

    MergeSort(arr, 0, n-1);

    printf("\nArray after sorting:\n");
    for (int i=0; i<n; i++) printf("%5d",arr[i]);
    return 0;
}
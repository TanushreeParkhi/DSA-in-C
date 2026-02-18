#include<stdio.h>

int binSearch(int key, int low, int high, int arr[])
{
    if (low>high)   return -1;
    int mid=low+(high-low)/2;
    if (key==arr[mid])
        return mid;
    else if (key>arr[mid])
        return binSearch(key,mid+1,high,arr);
    else  
        return binSearch(key,low,mid-1,arr);
}

int main()
{
    printf("How many elements? Enter.\n");
    int n, arr[20];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("Enter key to search:");
    int key;
    scanf("%d", &key);
    int res=binSearch(key, 0, n-1, arr);
    if (res==-1)
        printf("Not found\n");
    else    printf("Found at position %d",res);
    return 0;

}
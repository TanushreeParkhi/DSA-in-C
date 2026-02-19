#include<stdio.h>
#include<stdlib.h>

int heap[30];
int n;

void heapify(int heap[], int i)
{
    int left=2*i, right=2*i+1;
    int largest;
    largest=i;
    if (left<=n && heap[left]>heap[largest])
        largest=left;

    if (right<=n && heap[right]>heap[largest])
        largest=right;

    if (largest!=i)
    {
        int t=heap[i];
        heap[i]=heap[largest];
        heap[largest]=t;
        heapify(heap, largest);
    }
}

void buildHeap()
{
    for (int i=n/2; i>=1; i--)
        heapify(heap, i);
}


int maximum()
{
    if (n==0){
        printf("Empty heap\n");
        return -1;
    }
    int m=heap[1];
    heap[1]=heap[n];
    n--;
    heapify(heap, 1);
    return m;
}

int main()
{
    int ch, res;
    while (1)
    {
        printf("\n1.Build Heap 2. Extact Max\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:printf("How many elements? Enter\n");
                scanf("%d", &n);
                for(int i=1; i<=n; i++)   scanf("%d", &heap[i]);
                buildHeap(heap, n);
                for (int i=1; i<=n; i++) printf("%5d", heap[i]);
            break;
        case 2: res=maximum();
                if (res!=-1) printf("Max is: %d\n", res);
                for (int i=1; i<=n; i++) printf("%5d", heap[i]);
                break;
        default:exit(0);
        }
    }
}

#include <stdio.h>

int binary_search(int A[], int beg, int end, int ele)
{
    if (end >= beg)
    {
        int mid = (beg + end - 1) / 2;

        if (A[mid] == ele)
            return mid;
        else if (A[mid] > ele)
            return binary_search(A, beg, mid, ele);
        else
            return binary_search(A, mid + 1, end, ele);
    }
    return -1;
}
void main()
{
    int n, A[50], ele, index;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &ele);
    index = binary_search(A, 0, n-1, ele);
    if(index!=-1)
        printf("Element found at index %d", index);
    else 
        printf("Element not found!");
}
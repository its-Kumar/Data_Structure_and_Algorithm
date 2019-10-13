/*
Name : Kumar Shanu
DAA LAB
//////////Program 1.A Recursive Binary Search////////////////
 */

#include <stdio.h>
int binary_search(int arr[], int data, int beg, int end)
{
    if (end == beg)
    {
        if (data == arr[beg])
            return beg;
        else
            return -1;
    }
    else
    {
        int mid = (beg + end) / 2;
        if (arr[mid] == data)
            return mid;
        else if (arr[mid] < data)
            return binary_search(arr, data, mid + 1, end);
        else
            return binary_search(arr, data, beg, mid - 1);
    }
}

int main(void)
{
    int arr[20], n, item, index = -1;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of array: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nThe array is : \n");
    for (int i = 0; i < n; i++)
        printf("%4d", arr[i]);

    printf("\nEnter the item to be searched : ");
    scanf("%d", &item);
    index = binary_search(arr, item, 0, n - 1);
    if (index != -1)
        printf("\n%d found at %dth index in array.\n", item, index);
    else
        printf("\n%d does not found in array.\n", item);

    return 0;
}

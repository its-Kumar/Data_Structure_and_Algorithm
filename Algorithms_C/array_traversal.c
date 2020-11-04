#include<stdio.h>

int main(void){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    // traversing the array and printing elements
    printf("Array is : \n");
    for(int i=0; i<n; i++)
        printf("%5d", arr[i]);
    printf("\n");
    return 0;
}

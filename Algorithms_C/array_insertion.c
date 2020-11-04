#include<stdio.h>
#include<stdlib.h>


int main(void){
    int MAX=50;
    int n, index, item, arr[MAX];
    printf("Enter no of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("Array is :\n");
    for (int i=0;i<n;i++)
        printf("%5d", arr[i]);
    printf("\nEnter element to insert: ");
    scanf("%d", &item);
    printf("\nEnter index of element to insert: ");
    scanf("%d", &index);
    if(index<0 || index>=n || index>=MAX){
        printf("Insertion is not possible at this index....");
        exit(0);
    }

    // algorithm
    int i=n;
    while(i>=index){
        arr[i+1] = arr[i];
        i--;
    }
    arr[index] = item;
    n = n+1;
    printf("Now Array is :\n");
    for (int i=0;i<n;i++)
        printf("%5d", arr[i]);

    return 0;
}

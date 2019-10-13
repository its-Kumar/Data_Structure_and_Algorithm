/*
Name : Kumar Shanu
DAA LAB
//////////Program 1.B Recursive Linear Search////////////////
*/


#include<stdio.h>

int linear_search(int arr[],int item,int first,int last){

    if(last < first)
        return -1;

    if(arr[first] == item)
        return first;

    if(arr[last] == item)
        return last;

    return linear_search(arr,item,first+1,last-1);
}

int main(void){
    int arr[20],n,item;
    int first=0,last,index;

    printf("Enter the size of array: ");
    scanf("%d",&n);
    last = n-1;

    printf("Enter the elements of array: ");

    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    printf("\nThe array is : \n");
    for(int i=0; i<n; i++)
        printf("%4d",arr[i]);

    printf("\nEnter any item to search : ");
    scanf("%d",&item);
    index = linear_search(arr,item,first,last);
    if(index ==-1)
        printf("Item doesnot found in array.");
    else
        printf("Item found at %dth index in array",index);

    return 0;
}

/*
Name : Kumar Shanu
DAA LAB
//////////Program  Merge Sort////////////////
*/

#include<stdio.h>
void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int n1 = mid-low +1;
    int n2 = high-mid;

    //Create temp arrays
    int L[n1],R[n2];

    //copy data to temp aarays L[] and R[]
    for (i=0; i<n1; i++)
        L[i] = arr[low +i];
    for (j=0; j<n2; j++)
        R[j] = arr[mid+1 +j];

    //Merge the temp array back into arr[]
    i=0,j=0;    //initialize index of arrays
    k=low;
    while(i<n1 && j< n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] =R[j];
            j++;
        }
        k++;
    }
    //copy remaining elements of L[]
    while( i<n1){
        arr[k] = L[i];
        i++;    k++;
    }
    //copy remaining elements of R[]
    while( j<n2){
        arr[k] = R[j];
        j++;    k++;
    }
}

void merge_sort(int arr[],int low,int high){
    int mid;
    if(low < high){
        // Divide into subproblems.
            // Find where to split the set.
        mid = low+ (high -low)/2;

        // Solve the subproblems.
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);

        // Combine the solution
        merge(arr,low,mid,high);
    }
}

int main(void){
    int arr[20],n,item;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    printf("Enter the elements of array: ");

    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    printf("\nThe array is : \n");
    for(int i=0; i<n; i++)
        printf("%4d",arr[i]);

    merge_sort(arr,0,n-1);
    printf("\nAfter Sorting The array is : \n");
    for(int i=0; i<n; i++)
        printf("%4d",arr[i]);
}

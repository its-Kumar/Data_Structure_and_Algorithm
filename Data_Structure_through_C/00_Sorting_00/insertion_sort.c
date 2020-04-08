/*
Name : Kumar Shanu
DAA LAB
//////////Program  Insertion Sort////////////////
*/

void insertion_sort(int arr[],int n){
    int i,j;

    for(i=1; i<n; i++){
        int key = arr[i];
        j= i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
            arr[j+1] = key;
        }
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

    insertion_sort(arr,n);
    printf("\nAfter Sorting The array is : \n");
    for(int i=0; i<n; i++)
        printf("%4d",arr[i]);
}

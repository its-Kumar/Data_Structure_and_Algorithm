//C program to find transpose of a matrix using pointers

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j;
    int *arr;//declaring a pointer
    printf("Enter order of matrix\n");
    scanf("%d",&n);
    arr=(int*)malloc(n*n*sizeof(int));//dynamic memory allocation for the pointer using malloc function
    printf("Enter matrix values\n");
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        scanf("%d",(arr+i*n+j)); 
    printf("The given matrix is\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",*(arr+i*n+j));
        }
        printf("\n");
    }
    printf("Transpose matrix is\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",*(arr+j*n+i));
        }
        printf("\n");
    }

}

#include<stdio.h>
int summation(int arr[],int low,int high);

int summation(int arr[],int low,int high)
    {  
     int sum=0;
    int i;
    for(i=low;i<=high; i++)
       {
      sum=sum+arr[i];
       }
      return sum;
    }
int  main()
{
    int a[10],n;
    int start;
    int end;
    int j;
    printf("enter no of elements you wnt in array");
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[j]);
    }
int max=0;
    for(start=0;start<n;start++)
    {
        for(end=start;end<n;end++)
        {
                int sum=summation(a,start,end);
                if(sum>=max)
                {

                 max=sum;
                 }
        }

     }
  
  printf("%d \n",max);
 }

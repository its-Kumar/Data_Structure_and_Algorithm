#include <stdio.h>

int main() {
	int a[10], n, i,j, temp, ch, key;
	printf("\nMenu:\n1.Bubble sort\n2.Insertion\n3.Selection");
	printf("\nEnter your choice:");
	scanf("%d", &ch);
	switch(ch)
	{
	    case 1: printf("\nEnter the size of array:");
	            scanf("%d", &n);
	            printf("\nEnter all the elements in array \n");
	            for(i=0; i<n; i++)
	              scanf("%d", &a[i]);
	            printf("\nApplying the logic of bubble sort:\n");
	            for(i=0; i<n-1; i++)
	            {
	                for(int j=0; j<n-1-i; j++)
	                {
	                    if(a[j]>a[j+1]);
	                    {
	                        temp= a[j];
	                        a[j]= a[j+1];
	                        a[j+1]= temp;
	                    }
	                }
	            }
	            printf("\nSorted array is:");
	            for(i=0; i<n; i++)
	              printf("%d\n", a[i]);
	   
	   break;
	   case 2: printf("\nEnter the size of array:");
	           scanf("%d", &n);
	           printf("\nEnter all the elements in array \n");
	           for(i=0; i<n; i++)
	              scanf("%d", &a[i]);
	           printf("\nApplying the logic of insertion sort:\n");
	           for (i = 1; i < n; i++) {
                    key = a[i];
                    j = i - 1;
	                 while (j >= 0 && a[j] > key) {
                        a[j + 1] = a[j];
                        j = j - 1;
	                 }
                     a[j + 1] = key;
               }
               printf("\nSorted array is:");
	              for(i=0; i<n; i++)
	                 printf("%d\n", a[i]);
	   break;
       case 3: printf("\nEnter the size of array:");
	           scanf("%d", &n);
	           printf("\nEnter all the elements in array \n");
	           for(i=0; i<n; i++)
	              scanf("%d", &a[i]);
	           printf("\nApplying the logic of selection sort:\n");
	           for(i=0;i<n;i++){
                 for(j=i+1;j<n;j++){
                  if(a[i]>a[j]){
                  temp=a[i];
                  a[i]=a[j];
                  a[j]=temp;
                  }
                 }
               printf("\nSorted array is:");
	           for(i=0; i<n; i++)
	              printf("%d\n", a[i]);
       break;
       
	}
      default :
          {
              printf("Invalid choice!!!!");
              break;
          }

      
	}   
	   
	
	
	return 0;
}
#include <stdio.h>
#define MAX 100

int main(void)
{
	int arr[MAX], i, j, n, temp, xchanges;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter element %d :  ", i + 1);
		scanf("%d", &arr[i]);
	}
	//bubble sort
	for (i = 0; i < n - 1; i++)
	{
		xchanges = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				xchanges++;
			}
		}
		if (xchanges == 0)
			break;
	}
	printf("Sorted list is : ");
	for (i = 0; i < n; i++)
		printf("%d  ", arr[i]);
	printf("\n");
	return 0;
}

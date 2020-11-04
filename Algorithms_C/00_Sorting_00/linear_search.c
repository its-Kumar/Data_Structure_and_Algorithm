#include <stdio.h>
#include <stdlib.h>

void LSearch(int[], int, int);
void main()
{
	int a[30], n, item;
	int i;
	printf("Enter the no of elements:\n");
	scanf("%d", &n);
	printf("Enter Elements:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Array is:-\n");
	for (i = 0; i < n; i++)
		printf("  %d", a[i]);
	printf("\nenter the item you want to search:\n");
	scanf("%d", &item);
	LSearch(a, n, item);
}

void LSearch(int a[30], int n, int item)
{
	int i;
	if (n == 0)
	{
		printf("Array is Empty...");
		exit(0);
	}

	for (i = 0; i <= n; i++)
	{
		if (a[i] == item)
		{
			printf("Search successfull.....\nItem is present at position %d ", i + 1);
			exit(0);
		}
	}
	printf("Search unsuccessfull.....");
}

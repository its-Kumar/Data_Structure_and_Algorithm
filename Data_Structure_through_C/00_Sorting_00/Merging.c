#include <stdio.h>
#define MAX 100

void merge(int[], int[], int[], int, int);
int main(void)
{
	int arr1[MAX], arr2[MAX], arr3[2 * MAX], n1, n2, i;

	printf("Enter the number of elements of array 1 : ");
	scanf("%d", &n1);
	for (i = 0; i < n1; i++)
	{
		printf("Enter element %d :  ", i + 1);
		scanf("%d", &arr1[i]);
	}
	printf("Enter the number of elements of array 2 : ");
	scanf("%d", &n2);
	for (i = 0; i < n2; i++)
	{
		printf("Enter element %d :  ", i + 1);
		scanf("%d", &arr2[i]);
	}
	merge(arr1, arr2, arr3, n1, n2);
	printf("Merged list : ");
	for (i = 0; i < n1 + n2; i++)
		printf("%d  ", arr3[i]);
	printf("\n");
	return 0;
}
void merge(int a1[], int a2[], int a3[], int n1, int n2)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while ((i <= n1 - 1) && (j <= n2 - 1))
	{
		if (a1[i] < a2[j])
			a3[k++] = a1[i++];
		else
			a3[k++] = a2[j++];
	}
	while (i <= n1 - 1)
		a3[k++] = a1[i++];
	while (j <= n2 - 1)
		a3[k++] = a2[j++];
}

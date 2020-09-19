#include <stdio.h>

int main()
{
   int c, first, last, middle, n, search, array[100];
   printf("Enter number of elements\n");
   scanf("%d", &n);
   printf("Enter %d integers\n", n);
   for (c = 0; c < n; c++)
   {
      scanf("%d", &array[c]);
   }
   printf("Enter value to find\n");
   scanf("%d", &search);
   first = 0;
   last = n - 1;
   middle = (first + last) / 2;
   while (first <= last && array[middle] != search)
   {
      if (array[middle] < search)
         first = middle + 1;
      else
         last = middle - 1;
      middle = (first + last) / 2;
   }
   if (first > last)
      printf("Not found! %d is not present in the list.\n", search);
   else
      printf("%d found at location number %d :-", search, middle + 1);
   return 0;
}

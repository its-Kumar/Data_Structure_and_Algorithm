/** kumar shanu
1773513025
*/

//linked list implimentation of stack
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int info;
  struct node *link;
};
struct node *top = NULL;
int isEmpty()
{
  if (top == NULL)
    return 1;
  else
    return 0;
}
void push(int item)
{
  struct node *tmp;
  tmp = (struct node *)malloc(sizeof(struct node));
  if (tmp == NULL)
  {
    printf("Stack Overflow\n");
    return;
  }
  tmp->info = item;
  tmp->link = top;
  top = tmp;
}
int pop()
{
  struct node *tmp;
  int item;
  if (isEmpty())
  {
    printf("Stack Underflow\n");
    return;
  }
  tmp = top;
  item = tmp->info;
  top = top->link;
  free(tmp);
  return item;
}
int peek()
{
  if (isEmpty())
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  return (top->info);
}
void display()
{
  struct node *ptr;
  if (isEmpty())
  {
    printf("Stack Underflow\n");
    return;
  }
  printf("Stack Elements are:\n");
  ptr = top;
  while (ptr != NULL)
  {
    printf("%d\n", ptr->info);
    ptr = ptr->link;
  }
  printf("\n");
}
void main()
{
  int choice, item;
  while (1)
  {
    printf("\n1.Push\n2.Pop\n3.Display item at the top of the stack");
    printf("\n4.Display all elements of the stack\n5.Quit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the  element to be pushed:");
      scanf("%d", &item);
      push(item);
      break;
    case 2:
      item = pop();
      printf("poped item is = %d\n", item);
      break;
    case 3:
      printf("Item at the top of the stack is %d\n", peek());
      break;
    case 4:
      display();
      break;
    case 5:
      exit(0);
    default:
      printf("Wrong choice\n");
    }
  }
}

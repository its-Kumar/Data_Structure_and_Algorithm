//program of expression tree

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int top = -1;

struct node
{
  struct node *lchild;
  char info;
  struct node *rchild;
};
typedef struct node node;

struct node *stack[MAX];
int isFull()
{
  if (top == MAX - 1)
    return 1;
  return 0;
}
int isEmpty()
{
  if (top == -1)
    return 1;
  return 0;
}

void push(struct node *item)
{
  if (isFull())
  {
    printf("Stack overflow..!!");
    return;
  }
  stack[++top] = item;
}

struct node *pop()
{
  if (isEmpty())
  {
    printf("Stack underflow..!!");
    return NULL;
  }
  return stack[top--];
}

void display(struct node *ptr, int level)
{
  int i;
  if (ptr != NULL)
  {
    display(ptr->rchild, level + 1);
    printf("\n");
    for (i = 0; i < level; i++)
      printf("\t");
    printf("%c", ptr->info);
    display(ptr->lchild, level + 1);
  }
}

void inorder(node *ptr)
{
  if (ptr == NULL)
    return;
  inorder(ptr->lchild);
  printf("%c  ", ptr->info);
  inorder(ptr->rchild);
}

int check(char element)
{
  switch (element)
  {
  case '^':
  case '*':
  case '/':
  case '+':
  case '-':
    return 0;
    break;
  default:
    return 1;
  }
}

node *build_tree(char postfix[], int size)
{
  int i;
  node *new_node = NULL, *t1 = NULL, *t2 = NULL;
  for (i = 0; i < size; i++)
  {
    if (check(postfix[i]))
    {
      new_node = (node *)malloc(sizeof(node));
      if (!new_node)
      {
        printf("Memory Error..!!!");
        return NULL;
      }
      new_node->info = postfix[i];
      new_node->lchild = NULL;
      new_node->rchild = NULL;
      push(new_node);
    }
    else
    {
      t2 = pop();
      t1 = pop();
      new_node = (node *)malloc(sizeof(node));
      if (!new_node)
      {
        printf("Memory Error..!!!");
        return NULL;
      }
      new_node->info = postfix[i];
      new_node->lchild = t1;
      new_node->rchild = t2;
      push(new_node);
    }
  }
  return stack[top];
}

void main()
{
  int i, n;
  char postfix[50];
  node *root = NULL;
  printf("Enter size: ");
  scanf("%d", &n);
  fflush(stdin);
  printf("\nEnter the postfix expression: ");
  gets(postfix);
  root = build_tree(postfix, n);

  printf("\n\n Inorder :\n\n");
  inorder(root);
  printf("\n\nExpression Tree is :\n\n");
  display(root, 0);
}

//program of construct binary tree from inorder and Preorder

#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *lchild;
  int info;
  struct node *rchild;
};
typedef struct node node;
node *root = NULL;
typedef struct listnode listnode;
struct listnode
{
  struct listnode *prev;
  int info;
  struct listnode *next;
} *in = NULL, *pre = NULL;

void preorder(node *ptr)
{
  if (ptr == NULL)
    return;
  printf("%d  ", ptr->info);
  preorder(ptr->lchild);
  preorder(ptr->rchild);
}
void inorder(node *ptr)
{
  if (ptr == NULL)
    return;
  inorder(ptr->lchild);
  printf("%d  ", ptr->info);
  inorder(ptr->rchild);
}
void postorder(node *ptr)
{
  if (ptr == NULL)
    return;
  postorder(ptr->lchild);
  postorder(ptr->rchild);
  printf("%d  ", ptr->info);
}
listnode *addtoempty(listnode *start, int data)
{
  listnode *tmp;
  tmp = (listnode *)malloc(sizeof(listnode));
  tmp->info = data;
  tmp->prev = NULL;
  tmp->next = NULL;
  start = tmp;
  return start;
}
listnode *addtoend(listnode *start, int data)
{
  listnode *tmp, *p;
  tmp = (listnode *)malloc(sizeof(listnode *));
  tmp->info = data;
  p = start;
  while (p->next != NULL)
    p = p->next;
  p->next = tmp;
  tmp->next = NULL;
  tmp->prev = p;
  return start;
}

listnode *create_list(listnode *start, int n)
{
  int i, data;
  start = NULL;
  for (i = 1; i <= n; i++)
  {
    printf("Enter the element to be inserted:");
    scanf("%d", &data);
    if (start == NULL)
      start = addtoempty(start, data);
    else
      start = addtoend(start, data);
  }
  return start;
}

node *construct(listnode *in, listnode *pre, int n)
{
  node *tmp;
  listnode *q;
  int i, j;
  if (n == 0)
    return NULL;
  tmp = (node *)malloc(sizeof(node));
  tmp->info = pre->info;
  tmp->lchild = NULL;
  tmp->rchild = NULL;
  if (n == 1)
    return tmp;
  q = in;
  for (i = 0; q->info != pre->info; i++)
    q = q->next;
  tmp->lchild = construct(in, pre->next, i);
  for (j = 1; j <= i + 1; j++)
    pre = pre->next;
  tmp->rchild = construct(q->next, pre, n - i - 1);
  return tmp;
}
void display(node *ptr, int level)
{
  int i;
  if (ptr != NULL)
  {
    display(ptr->rchild, level + 1);
    printf("\n");
    for (i = 0; i < level; i++)
      printf("\t");
    printf("%d", ptr->info);
    display(ptr->lchild, level + 1);
  }
}

void main()
{
  int n;

  printf("\nEnter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter inorder:\n");
  in = create_list(in, n);

  printf("Enter preorder:\n");
  pre = create_list(pre, n);

  root = construct(in, pre, n);

  display(root, 0);

  printf("\nInorder is:");
  inorder(root);
  printf("\nPreorder is:");
  preorder(root);
  printf("\nPostorder is:");
  postorder(root);
}

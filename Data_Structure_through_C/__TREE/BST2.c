//program of binary search tree and its non recursive operations

#include <stdlib.h>
#include <stdio.h>

struct node
{
  struct node *lchild;
  int info;
  struct node *rchild;
};
typedef struct node node;
node *root = NULL;

node *stack[100];
int top = -1;
int stack_full()
{
  if (top == 99)
    return 1;
  else
    return 0;
}
int stack_empty()
{
  if (top == -1)
    return 1;
  else
    return 0;
}
void push_stack(node *ptr)
{
  if (stack_full())
  {
    printf("Stack is full\n");
    return;
  }
  top = top + 1;
  stack[top] = ptr;
}
node *pop_stack()
{
  if (stack_empty())
  {
    printf("Stack is Empty\n");
    return NULL;
  }
  return stack[top--];
}
//non recursive preorder traversal of binary tree

void nrec_preorder(node *root)
{
  node *ptr = root;
  if (ptr == NULL)
  {
    printf("Tree is Empty\n");
    return;
  }
  push_stack(ptr);
  while (!stack_empty())
  {
    ptr = pop_stack();
    printf("%d  ", ptr->info);
    if (ptr->rchild != NULL)
      push_stack(ptr->rchild);
    if (ptr->lchild != NULL)
      push_stack(ptr->lchild);
  }
  printf("\n");
}

//non recursive inorder traversal of the binary Tree

void nrec_inorder(node *root)
{
  node *ptr = root;
  if (ptr == NULL)
  {
    printf("Tree is Empty:");
    return;
  }
  while (1)
  {
    while (ptr->lchild != NULL)
    {
      push_stack(ptr);
      ptr = ptr->lchild;
    }
    while (ptr->rchild == NULL)
    {
      printf("%d  ", ptr->info);
      if (stack_empty())
        return;
      ptr = pop_stack();
    }
    printf("%d  ", ptr->info);
    ptr = ptr->rchild;
  }
  printf("\n");
}

void nrec_postorder(node *root)
{
  node *ptr, *q;
  ptr = root;
  if (ptr == NULL)
  {
    printf("Tree is Empty\n");
    return;
  }
  q = root;

  while (1)
  {
    while (ptr->lchild != NULL)
    {
      push_stack(ptr);
      ptr = ptr->lchild;
    }
    while (ptr->rchild == NULL || ptr->rchild == q)
    {
      printf("%d  ", ptr->info);
      q = ptr;
      if (stack_empty())
        return;
      ptr = pop_stack();
    }
    push_stack(ptr);
    ptr = ptr->rchild;
  }
  printf("\n");
}

node *nrec_search(node *ptr, int key)
{
  while (ptr != NULL)
  {
    if (key < ptr->info)
      ptr = ptr->lchild;
    else if (key > ptr->info)
      ptr = ptr->rchild;
    else
      return ptr;
  }
  return NULL;
}
node *nrec_Min(node *ptr)
{
  if (ptr != NULL)
    while (ptr->lchild != NULL)
      ptr = ptr->lchild;
  return ptr;
}
node *nrec_Max(node *ptr)
{
  if (ptr != NULL)
    while (ptr->rchild != NULL)
      ptr = ptr->rchild;
  return ptr;
}

node *nrec_insert(node *root, int key)
{
  node *tmp, *ptr, *par;
  ptr = root;
  par = NULL;
  while (ptr != NULL)
  {
    par = ptr;
    if (key < ptr->info)
      ptr = ptr->lchild;
    else if (key > ptr->info)
      ptr = ptr->rchild;
    else
    {
      printf("Duplicate key");
      return root;
    }
  }
  tmp = (node *)malloc(sizeof(node));
  tmp->info = key;
  tmp->lchild = NULL;
  tmp->rchild = NULL;
  if (par == NULL)
    root = tmp;
  else if (key < par->info)
    par->lchild = tmp;
  else
    par->rchild = tmp;
  return root;
}
node *case_a(node *root, node *par, node *ptr)
{
  if (par == NULL)
    root = NULL;
  else if (ptr == par->lchild)
    par->lchild = NULL;
  else
    par->rchild = NULL;
  free(ptr);
  return root;
}
node *case_b(node *root, node *par, node *ptr)
{
  node *child;
  if (ptr->lchild != NULL)
    child = ptr->lchild;
  else
    child = ptr->rchild;
  if (par == NULL)
    root = child;
  else if (ptr == par->lchild)
    par->lchild = child;
  else
    par->rchild = child;
  free(ptr);
  return root;
}
node *case_c(node *root, node *par, node *ptr)
{
  node *succ, *parsucc;
  parsucc = ptr;
  succ = ptr->lchild;
  while (succ->lchild != NULL)
  {
    parsucc = succ;
    succ = succ->lchild;
  }
  ptr->info = succ->info;
  if (succ->lchild == NULL && succ->rchild == NULL)
    root = case_a(root, parsucc, succ);
  else
    root = case_b(root, parsucc, succ);
  return root;
}

node *nrec_del(node *root, int key)
{
  node *ptr, *par;
  ptr = root;
  par = NULL;
  while (ptr != NULL)
  {
    if (key == ptr->info)
      break;
    par = ptr;
    if (key < ptr->info)
      ptr = ptr->lchild;
    else
      ptr = ptr->rchild;
  }
  if (ptr == NULL)
    printf("Key not found in tree:\n");
  else if (ptr->rchild != NULL && ptr->rchild != NULL)
    root = case_c(root, par, ptr);
  else if (ptr->lchild != NULL)
    root = case_b(root, par, ptr);
  else if (ptr->rchild != NULL)
    root = case_b(root, par, ptr);
  else
    root = case_a(root, par, ptr);
  return root;
}
void main()
{
  int choice, k;
  node *ptr = NULL;

  while (1)
  {
    printf("\n1. Search");
    printf("\n2. Insert");
    printf("\n3. Delete");
    printf("\n4. Find Max and Min ");
    printf("\n5. Inorder Traversal");
    printf("\n6. Postorder Traversal");
    printf("\n7. Preorder Traversal");
    printf("\n0. Exit....");
    printf("\nEnter Your Choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("\nEnter the key to be searched: ");
      scanf("%d", &k);
      ptr = nrec_search(root, k);
      if (ptr != NULL)
        printf("Key found");
      else
        printf("key not found");
      break;
    case 2:
      printf("\nEnter the key to be Inserted: ");
      scanf("%d", &k);
      root = nrec_insert(root, k);
      break;
    case 3:
      printf("\nEnter the key to be Deleted: ");
      scanf("%d", &k);
      root = nrec_del(root, k);
      break;

    case 4:
      printf("\nMax key is: %d", nrec_Max(root)->info);
      printf("\nMin key is: %d", nrec_Min(root)->info);
      break;

    case 5:
      nrec_inorder(root);
      break;
    case 6:
      nrec_postorder(root);
      break;
    case 7:
      nrec_preorder(root);
      break;

    case 0:
      exit(0);
    default:
      printf("Wrong choice..!!");
    }
  }
}

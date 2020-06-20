//progaram to construct binary tree from inorder and postorder

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
  node *lchild;
  int info;
  node *rchild;
} *root = NULL;

typedef struct listnode listnode;

struct listnode
{
  listnode *prev;
  int info;
  listnode *next;
} *in = NULL, *post = NULL;

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
  tmp->prev = NULL;
  tmp->next = NULL;
  tmp->info = data;
  start = tmp;
  return start;
}
listnode *addtoend(listnode *start, int data)
{
  listnode *tmp, *p;
  tmp = (listnode *)malloc(sizeof(listnode));
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
  int data, i;
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

node *construct(listnode *in, listnode *post, int n)
{
  node *temp;
  listnode *q, *ptr;
  int i, j;
  if (n == 0)
    return NULL;
  ptr = post;
  for (i = 1; i < n; i++)
    ptr = ptr->next;
  temp = (node *)malloc(sizeof(node));
  temp->info = ptr->info;
  temp->lchild = NULL;
  temp->rchild = NULL;
  if (n == 1)
    return temp;

  q = in;

  for (i = 0; q->info != ptr->info; i++)
    q = q->next;

  temp->lchild = construct(in, post, i);

  for (j = 1; j <= i; j++)
    post = post->next;

  temp->rchild = construct(q->next, post, n - i - 1);
  return temp;
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
node *queue[100];
int front = -1, rear = -1;
void insert_queue(node *item)
{
  if (rear == 99)
  {
    printf("Queue overflow\n");
    return;
  }
  if (front == -1)
    front = 0;
  rear = rear + 1;
  queue[rear] = item;
}
node *del_queue()
{
  node *item;
  if (front == -1 || front == rear + 1)
  {
    printf("Queue underflow\n");
    return 0;
  }
  item = queue[front];
  front++;
  return item;
}

int queue_empty()
{
  if (front == -1 || front == rear + 1)
    return 1;
  else
    return 0;
}

void level_trav(node *root)
{
  node *ptr;
  ptr = root;
  if (ptr == NULL)
  {
    printf("Tree is Empty\n");
    return;
  }
  insert_queue(ptr);
  while (!queue_empty())
  {
    ptr = del_queue();
    printf("%d  ", ptr->info);
    if (ptr->lchild != NULL)
      insert_queue(ptr->lchild);
    if (ptr->rchild != NULL)
      insert_queue(ptr->rchild);
  }
  printf("\n");
}

int height(node *ptr)
{
  int h_left, h_right;
  if (ptr == NULL)
    return 0;
  h_left = height(ptr->lchild);
  h_right = height(ptr->rchild);
  if (h_right > h_left)
    return h_right + 1;
  else
    return h_left + 1;
}

main()
{
  int n;

  printf("Enter the no of nodes:");
  scanf("%d", &n);

  printf("Enter Inorder:\n");
  in = create_list(in, n);

  printf("Enter postorder:\n");
  post = create_list(post, n);

  root = construct(in, post, n);

  printf("\nPreorder is:"); //preorder(root);
  nrec_preorder(root);
  printf("\nInorder is:"); //inorder(root);
  nrec_inorder(root);

  printf("\nPostorder is:"); //postorder(root);
  nrec_postorder(root);

  printf("\nLevel Traversinf of tree is:\n");
  level_trav(root);

  printf("\nTree is (Root->Leaf):\n");
  display(root, 0);

  printf("\nHeight of the tree is: ");
  printf("%d ", height(root));
}

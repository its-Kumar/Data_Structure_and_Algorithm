//program of binary search tree and its operations

#include <stdlib.h>
#include <stdio.h>

// Tree node
struct node
{
  struct node *lchild; //left child
  int info;            //data
  struct node *rchild; //right child
};
typedef struct node node; //Tree node
node *root = NULL;        // Tree root

// preorder traversal of tree
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

/**
 * @brief Search element in the tree
 *
 * @param root of the tree
 * @param key to be searcheed
 * @return node* adress of the node
 */
node *search(node *root, int key)
{
  node *ptr = root;
  if (ptr == NULL)
    return NULL;
  else if (ptr->info == key)
    return ptr;
  else if (ptr->info < key)
    return search(ptr->rchild, key);
  else
    return search(ptr->lchild, key);
}

/**
 * @brief Insert node into the tree
 *
 * @param ptr where to insert
 * @param key what to be insert
 * @return node*
 */
node *insert(node *ptr, int key)
{
  if (ptr == NULL)
  {
    ptr = (node *)malloc(sizeof(node));
    ptr->info = key;
    ptr->lchild = NULL;
    ptr->rchild = NULL;
  }
  else if (key < ptr->info)
    ptr->lchild = insert(ptr->lchild, key);
  else if (key > ptr->info)
    ptr->rchild = insert(ptr->rchild, key);
  else
    printf("Duplicate key\n");
  return ptr;
}
/**
 * @brief Delete given key from the tree
 *
 * @param ptr
 * @param key
 * @return node*
 */
node *del(node *ptr, int key)
{
  node *tmp, *succ;
  if (ptr == NULL)
  {
    printf("Key not found\n");
    return ptr;
  }
  if (key < ptr->info)
    ptr->lchild = del(ptr->lchild, key);
  else if (key > ptr->info)
    ptr->rchild = del(ptr->rchild, key);
  else
  {
    if (ptr->lchild != NULL && ptr->rchild != NULL)
    {
      succ = ptr->rchild;
      while (succ->lchild)
        succ = succ->lchild;
      ptr->info = succ->info;
      ptr->rchild = del(ptr->rchild, succ->info);
    }
    else
    {
      tmp = ptr;
      if (ptr->lchild != NULL)
        ptr = ptr->lchild;
      else if (ptr->rchild != NULL)
        ptr = ptr->rchild;
      else
        ptr = NULL;
      free(tmp);
    }
  }
  return ptr;
}

node *Min(node *ptr)
{
  if (ptr == NULL)
    return NULL;
  else if (ptr->lchild == NULL)
    return ptr;
  else
    return Min(ptr->lchild);
}
node *Max(node *ptr)
{
  if (ptr == NULL)
    return NULL;
  else if (ptr->rchild == NULL)
    return ptr;
  else
    return Max(ptr->rchild);
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
      ptr = search(root, k);
      if (ptr != NULL)
        printf("Key found");
      else
        printf("key not found");
      break;
    case 2:
      printf("\nEnter the key to be Inserted: ");
      scanf("%d", &k);
      root = insert(root, k);
      break;
    case 3:
      printf("\nEnter the key to be Deleted: ");
      scanf("%d", &k);
      root = del(root, k);
      break;

    case 4:
      printf("\nMax key is: %d", Max(root)->info);
      printf("\nMin key is: %d", Min(root)->info);
      break;

    case 5:
      inorder(root);
      break;
    case 6:
      postorder(root);
      break;
    case 7:
      preorder(root);
      break;

    case 0:
      exit(0);
    default:
      printf("Wrong choice..!!");
    }
  }
}

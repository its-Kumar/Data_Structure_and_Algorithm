// program of AVL tree
// @its-Kumar

#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

/**
 * @brief  Tree node
 *
 */
typedef struct
{
  struct node *lchild; //left child
  int info;            // data
  struct node *rchild; //right child
  int balance;         // balance factor
} node;
void inorder();
node *rotate_left(node *pptr);
node *rotate_right(node *pptr);
node *insert(node *pptr, int ikey);
node *insert_left_check(node *pptr, int *ptaller);
node *insert_right_check(node *pptr, int *ptaller);
node *insert_leftbalance(node *pptr);
node *insert_rightbalance(node *pptr);
node *del(node *pptr, int dkey);
node *del_left_check(node *pptr, int *pshorter);
node *del_right_check(node *pptr, int *pshorter);
node *del_leftbalance(node *pptr, int *pshorter);
node *del_rightbalance(node *pptr, int *pshorter);

main()
{
  int choice, key;
  node *root = NULL; //root of the tree

  while (1)
  {
    printf("\n\n1.Insert\n");
    printf("2. Delete\n");
    printf("3. Inorder Traversal\n");
    printf("4. Quit\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the key to be inserted:");
      scanf("%d", &key);
      root = insert(root, key);
      break;
    case 2:
      printf("Enter the key to be deleted: ");
      scanf("%d", &key);
      root = del(root, key);
      break;
    case 3:
      printf("Inorder : ");
      inorder(root);
      break;
    case 4:
      exit(1);
    default:
      printf("Wrong choice..!!\n");
    }
  }
}

// inorder traversal of the tree
void inorder(node *ptr)
{
  if (ptr == NULL)
    return;
  inorder(ptr->lchild);
  printf("%d  ", ptr->info);
  inorder(ptr->rchild);
}
node *rotate_left(node *pptr)
{
  node *aptr;
  aptr = pptr->rchild;
  pptr->rchild = aptr->lchild;
  aptr->lchild = pptr;
  return aptr;
}
node *rotate_right(node *pptr)
{
  node *aptr;
  aptr = pptr->lchild;
  pptr->lchild = aptr->rchild;
  aptr->rchild = pptr;
  return aptr;
}

/**
 * @brief insert node into the tree
 *
 * @param pptr parent pointer
 * @param ikey key to be inserted
 * @return node* new pointer
 */
node *insert(node *pptr, int ikey)
{
  static int taller;
  if (pptr == NULL)
  {
    pptr = (node *)malloc(sizeof(node));
    pptr->info = ikey;
    pptr->lchild = NULL;
    pptr->rchild = NULL;
    pptr->balance = 0;
    taller = TRUE;
  }
  else if (ikey < pptr->info)
  {
    pptr->lchild = insert(pptr->lchild, ikey);
    if (taller == TRUE)
      pptr = insert_left_check(pptr, &taller);
  }
  else if (ikey > pptr->info)
  {
    pptr->rchild = insert(pptr->rchild, ikey);
    if (taller == TRUE)
      pptr = insert_right_check(pptr, &taller);
  }
  else
  {
    printf("Duplicate key..!!");
    taller = FALSE;
  }
  return pptr;
}

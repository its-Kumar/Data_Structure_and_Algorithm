//program of fully in-threaded binary tree

#include<stdio.h>
#include<stdlib.h>

typedef enum {false,true} boolean;

struct th_node{
  struct th_node *left;
  boolean lthread;
  int info;
  boolean rthread;
  struct th_node *right;
};
typedef struct th_node th_node;

th_node* in_succ(th_node *ptr){
  if(ptr->rthread == true)
    return ptr->right;
  else{
    ptr=ptr->right;
    while( ptr->lthread ==false)
      ptr=ptr->left;
    return ptr;
  }
}
th_node* in_pred(th_node *ptr){
  if(ptr->lthread ==true)
    return ptr->left;
  else{
    ptr=ptr->left;
    while(ptr->rthread ==false)
      ptr=ptr->right;
    return ptr;
  }
}
void inorder(th_node *root){
  th_node *ptr;
  if(root ==NULL){
    printf("Tree is empty"  );
    return;
  }
  ptr=root;
  while(ptr->lthread ==false)
    ptr=ptr->left;
  while(ptr !=NULL){
    printf("%d  ",ptr->info);
    ptr=in_succ(ptr);
  }
}

void preorder(th_node *root){
  th_node *ptr;
  if(root==NULL){
    printf("Tree empty\n");
    return;
  }
  ptr=root;
  while(ptr!=NULL){
    printf("%d  ",ptr->info);
    if(ptr->lthread==false)
      ptr=ptr->left;
    else if(ptr->rthread ==false)
      ptr=ptr->right;
    else{
      while(ptr !=NULL && ptr->rthread==true)
        ptr=ptr->right;
      if(ptr !=NULL)
        ptr=ptr->right;
    }
  }
}

th_node* insert(th_node *root, int key){
	th_node *tmp,*par,*ptr;
  int found =0;
  ptr=root;   par=NULL;
  while(ptr !=NULL){
    if(key ==ptr->info){
      found =1;
      break;
    }
    par=ptr;
    if(key < ptr->info){
      if(ptr->lthread ==false)
        ptr=ptr->left;
      else
        break;

    }
    else{
      if(ptr->rthread ==false)
        ptr=ptr->right;
      else
        break;
    }
  }
  if(found)
    printf("Duplicate key");
  else{
    tmp=(th_node*)malloc(sizeof(th_node));
    tmp->info=key;
    tmp->lthread=true;
    tmp->rthread=true;
    if(par ==NULL){
      root=tmp;
      tmp->left=NULL;
      tmp->right=NULL;
    }
    else if(key <par->info){
      tmp->left=par->left;
      tmp->right=par;
      par->lthread=false;
      par->left=tmp;
    }
    else{
      tmp->left=par;
      tmp->right=par->right;
      par->rthread=false;
      par->right=tmp;
    }
  }
  return root;
}
th_node* case_a(th_node *root, th_node *par, th_node *ptr){
  if(par == NULL)
    root = NULL;
  else if(ptr == par->left){
    par->lthread =true;
    par->left = ptr->left;
  }
  else{
    par->rthread =true;
    par->right = ptr->right;
  }
  free(ptr);
  return root;
}
th_node* case_b(th_node* root, th_node* par, th_node* ptr){
  th_node *child,*s,*p;

  if(ptr->lthread ==false)
    child=ptr->left;
  else
    child = ptr->right;
  if(par == NULL)
    root= child;
  else if(ptr == par->left)
    par->left=child;
  else
    par->right = child;
  s = in_succ(ptr);
  p = in_pred(ptr);
  if(ptr->lthread == false)
    p->right= s;
  else{
    if(ptr->rthread == false)
      s->left = p;
  }
  free(ptr);
  return root;
}
th_node* case_c(th_node* root,th_node* par, th_node* ptr){
  th_node *succ,*parsucc;

  parsucc = par;
  succ=ptr->right;
  while(succ->left != NULL){
    parsucc = succ;
    succ=succ->left;
  }
  ptr->info =succ->info;
  if(succ->lthread == true && succ->rthread == true)
    root= case_a(root,parsucc,ptr);
  else
    root= case_b(root, parsucc, succ);
  return root;
}

th_node* del(th_node *root,int key){
  th_node *par,*ptr;
  int found=0;
  ptr=root;   par=NULL;
  while(ptr !=NULL)
    {
      if(key  == ptr->info){
        found =1;
        break;
      }
      par=ptr;
      if(key < ptr->info){
        if(ptr->lthread==false)
          ptr=ptr->left;
        else
          break;
      }
      else{
        if(ptr->rthread==false)
          ptr=ptr->right;
        else
          break;
      }
    }
    if(found == 0)
      printf("key is not present in the tree..!!\n");
    else if(ptr->lthread==false && ptr->rthread==false)
      root= case_c(root,par,ptr);
    else if(ptr->lthread==false)
      root= case_b(root,par,ptr);
    else if(ptr->rthread==false)
      root= case_b(root,par,ptr);
    else
      root= case_a(root,par,ptr);
    return root;
}


main(){
  int choice,num;
  th_node *root=NULL;
  while(1){
    printf("\n\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Inorder Traversal");
    printf("\n4. Preorder Traversal");
    printf("\n5. Postorder Traversal");
    printf("\n6. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter the number to be inserted: ");
        scanf("%d", &num);
        root=insert(root,num);
        break;
      case 2:
        printf("Enter the number to be deleted: ");
        scanf("%d", &num);
        root=del(root,num);
        break;
      case 3:
        inorder(root);
        break;
      case 4:
        preorder(root);
        break;
      case 5:
        //postorder(root);
        break;
      case 6:
        exit(1);
      default:
        printf("\nWrong Choice..!!\n");
            }
  }
}

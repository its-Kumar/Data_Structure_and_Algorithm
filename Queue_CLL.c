//Circular linked list implimentation of a linear Queue

#include <stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node *link;
};
struct node *rear=NULL;
int isEmpty(){
  if(rear==NULL)
    return 1;
  else
    return 0;
}
void display(){
  struct node *p;
  if(isEmpty()){
    printf("Queue is Empty:\n");
    return;
  }
  printf("Queue is:\n" );
  p=rear->link;
  do{
    printf("%d  ",p->info );
    p=p->link;
  }while(p!=rear->link);
}

int peek(){
  if(isEmpty()){
    printf("Queue is Empty\n" );
    return;
  }
  return(rear->link->info);
}
void enqueue(int item){
  struct node *tmp;
  tmp=(struct node*)malloc(sizeof(struct node));
  tmp->info=item;
  if(tmp==NULL){
    printf("Memory not available...\n" );
    return;
  }
  if(isEmpty()){
    rear=tmp;
    tmp->link=rear;
  }
  else{
    tmp->link=rear->link;
    rear->link=tmp;
    rear=tmp;
  }
}
del(){
  int item;
  struct node *tmp;
  if(isEmpty()){
    printf("Queue underflow....");
    return;
  }
  if(rear->link==rear)    //if only one element
  {
    tmp=rear;
    rear=NULL;
  }
  else{
    tmp=rear->link;
    rear->link=rear->link->link;
  }
  item=tmp->info;
  free(tmp);
  return item;
}

void main(){
  int choice,item;
  while(1){
    printf("\n1.Enqueue\n2.Dequeue");
    printf("\n3.value at the front of the queue");
    printf("\n4.Display Queue\n5.Exit" );
    printf("\n\nEnter your choice:\n");
    scanf("%d",&choice );
    switch (choice) {
      case 1:
        printf("Enter the value to be inserted:\n");
        scanf("%d",&item);
        enqueue(item);  break;
      case 2:
        item=del();
        printf("Deleted value is %d\n",item);
        break;
      case 3:
        printf("Value at the front of queue :  %d\n",peek());
        break;
      case 4:
        display();
        break;
      case 5:
        exit(1);
      default:
        printf("Wrong choice.....");
    }
  }
}

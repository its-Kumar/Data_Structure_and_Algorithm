//linked list implimentation of a linear Queue

#include <stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node *link;
};
struct node *front=NULL,*rear=NULL;
int isEmpty(){
  if(front==NULL)
    return 1;
  else
    return 0;
}
void display() {
  struct node *ptr;
  ptr=front;
  if(isEmpty()){
    printf("Queue is Empty\n" );
    return;
  }
  printf("Queue is:\n" );
  while(ptr!=NULL){
    printf(" %d\t",ptr->info );
    ptr=ptr->link;
  }
  printf("\n\n" );
}
int peek(){
  if(isEmpty()){
    printf("Queue is Empty\n" );
    return;
  }
  return(front->info);
}
void enqueue(int item){
  struct node *tmp;
  tmp=(struct node*)malloc(sizeof(struct node));
  tmp->info=item;
  tmp->link=NULL;
  if(isEmpty()){
    front=tmp;
    rear=tmp;
  }
  else{
      rear->link=tmp;
      rear=tmp;
  }
}
int dequeue(){
  struct node *tmp;
  int item;
  if(isEmpty()){
  	printf("Queue is Empty\n");
  	return;
  }
  tmp=front;
  front=front->link;
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
        item=dequeue();
        printf("Deleted value is %d\n",item);
        break;
      case 3:
        printf("Value at the front of queue :  %d\n",peek());
        break;
      case 4:
        display();
        break;
      case 5:
        exit(0);
      default:
        printf("Wrong choice.....");
    }
  }
}

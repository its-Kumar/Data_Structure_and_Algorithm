//array implimentation of a Circular Queue

#include <stdio.h>
#include<stdlib.h>
#define MAX 10
int front = -1, rear = -1;
int cqueue_arr[MAX];
int isEmpty(){
  if(front==-1)
    return 1;
  else
    return 0;
}
int isFull(){
  if((front==0 && rear==MAX-1)||(front== rear + 1))
    return 1;
  else
    return 0;
}
void insert(int item){
  if(isFull()){
    printf("Queue overflow.....\n" );
    return;
  }
  if(front== -1)
    front=0;
  if(rear== MAX-1)
    rear=0;
  else
    rear =rear+1;
  cqueue_arr[rear]=item;
}
int del(){
  int item;
  if(isEmpty()){
    printf("Queue Underflow....\n" );
    return;
  }
  item=cqueue_arr[front];
  if(front == rear)				//only one element
  {
    front=-1;
    rear=-1;
  }
  else if(front == MAX-1)
    front=0;
  else
    front= front+1;
  return item;
}
int peek(){
  if(isEmpty()){
    printf("Queue Underflow....\n" );
    exit(1);
  }
  return cqueue_arr[front];
}
void display(){
	int i;
	if(isEmpty()){
    printf("Queue Underflow....\n" );
    return;
  }
  printf("Queue Elements are:\n" );
  i=front;
  if(front<=rear){
    while(i<=rear)
      printf("  %d", cqueue_arr[i++]);
  }
  else{
    while (i<=MAX-1)
      printf("  %d", cqueue_arr[i++] );
    i=0;
    while(i<=rear)
        printf("  %d", cqueue_arr[i++] );
  }
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
        insert(item);  break;
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
        exit(0);
      default:
        printf("Wrong choice.....");
    }
  }
}

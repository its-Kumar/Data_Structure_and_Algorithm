//array implimentation of a linear Queue

#include <stdio.h>
#include<stdlib.h>
#define MAX 10
int front=-1,rear=-1;
int queue_arr[MAX];
int isEmpty(){
  if(front==-1||front>rear)
    return 1;
  else
    return 0;
}
int isFull(){
  if(rear==MAX-1)
    return 1;
  else
    return 0;
}
void display(){
  int i;
  if(isEmpty()){
    printf("Queue is Empty\n" );
    return;
  }
  printf("Queue is :\n\n");
  for (i=front;i<=rear;i++)
    printf("%d\t",queue_arr[i]);
  printf("\n\n");
}
int peek(){
  if(isEmpty()){
    printf("Queue is Empty\n" );
    return;
  }
  return (queue_arr[front]);
}
int dequeue(){
  int item;
  if(isEmpty()){
    printf("Queue is Empty\n" );
    return;
  }
  item=queue_arr[front];
  front++;
  return item;
}
void enqueue(int item){
  if(isFull()){
    printf("Queue is Full\n" );
    return;
  }
  rear++;
  if(front==-1)
     front=0;
  queue_arr[rear]=item;
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

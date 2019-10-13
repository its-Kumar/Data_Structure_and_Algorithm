//array implimentation of a Deque

#include <stdio.h>
#include<stdlib.h>
#define MAX 10
int front=-1,rear=-1;
int deque_arr[MAX];
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
void insert_atrear(int item){
  if(isFull()){
    printf("Queue overflow...\n" );
    return;
  }
  if(front==-1)
    front=0;
  if(rear == MAX-1)
    rear=0;
  else
    rear+=1;
  deque_arr[rear]=item;
}
void insert_atfront(int item){
  
}

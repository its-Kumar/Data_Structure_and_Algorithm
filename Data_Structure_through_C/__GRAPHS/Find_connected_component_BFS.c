/*
Program to find connected component in an undirected graph
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int state[MAX];     int label[MAX];
void create_graph();    void BF_Traversal();
void BFS(int v,int component_Num);
int queue[MAX],front = -1, rear = -1;
void insert_queue(int vertex);  int del_queue();
int isEmpty_queue();

void main(void){
    create_graph();
    BF_Traversal();
    getch();
}

void BF_Traversal(){
    int v, components = 0;
    for(v=0; v<n; v++)
        state[v] = initial;
    components++;
    BFS(0,components);      //starts BFS from vertex 0

    for(v=0;v<n;v++){
        if(state[v] == initial){
            components++;
            BFS(v,components);
        }
    }
    printf("Number of connected components = %d\n ",components);
    if(components ==1)
        printf("Connected graph\n");
    else
        printf("Not a connected graph\n");
}

void BFS(int v, int component_Num){
    int i;
    insert_queue(v);
    state[v] = waiting;
    while(!(isEmpty_queue())){

        v =del_queue();
        state[v] = visited;
        label[v] =component_Num;
        printf("Vertex %d component = %d\n", v,label[v]);
        for(i=0; i<n; i++){
            if(adj[v][i] ==1 && state[i] ==initial){
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}


void insert_queue(int vertex){

    if(rear == MAX-1)
        printf("Queue Overflow...!!!\n");
    else{
        if(front == -1)
            front =0;
        rear =rear +1;
        queue[rear] = vertex;
    }
}

int isEmpty_queue(){
    if(front == -1 || front >rear)
        return 1;
    else
    {
        return 0;
    }
    
}

int del_queue(){
    int del_item;

    if(front == -1 || front >rear)
    {
        printf("Queue Underflow...!!!\n");
        exit(1);
    }
    del_item =queue[front];
    front +=1;
    return del_item;
}

void create_graph(){

    int i,max_edge,origin,destin;
    printf("Enter the no of verticex : ");
    scanf("%d", &n);
    max_edge = n* (n-1);
    for(i=1; i<=max_edge; i++){

        printf("Enter edge %d( -1 -1 ) to quit : ",i);
        scanf("%d%d",&origin, &destin);
        if( (origin == -1) && (destin == -1))
            break;
        if( origin >=n || destin >=n || origin<0 || destin <0)
        {
            printf("Invalid Edge : \n");
            i--;
        }
        else
            adj[origin][destin] = 1;
        
    }
}


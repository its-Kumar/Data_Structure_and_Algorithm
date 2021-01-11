/*Program for traversing a directed graph through BFS,
    visiting only those vertices that are reachable from start vertex

    @its-Kumar
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// states of vertex
#define initial 1
#define waiting 2
#define visited 3

int n;               //no of vertex
int adj[MAX][MAX];   //adjacency matrix
int state[MAX];      // state matrix
void create_graph(); // create graph
void BF_Traversal(); // BFS traversal
void BFS(int v);
int queue[MAX], front = -1, rear = -1; //queue
void insert_queue(int vertex);
int del_queue();
int isEmpty_queue();

main()
{

    create_graph();
    BF_Traversal();
}

/*
void BF_Traversal(){
    int v;

    for(v=0; v<n; v++)
        state[v] = initial;
    printf("\nEnter Starting Vertex for Breath First search : ");
    scanf("%d",&v);
    BFS(v);
}
*/

/*if you want to visit all the vertices even if they are not reachable from
the starting vertex, then use the following function otherwise the upper function
*/

void BF_Traversal()
{
    int v;

    for (v = 0; v < n; v++)
        state[v] = initial;
    printf("\nEnter Starting Vertex for Breath First search : ");
    scanf("%d", &v);
    BFS(v);
    for (v = 0; v < n; v++)
        if (state[v] == initial)
            BFS(v);
}

/**
 * @brief BSF from vertex v
 *
 * @param vertex starting vertex
 */
void BFS(int vertex)
{
    int i;
    insert_queue(vertex);
    state[vertex] = waiting;

    while (!isEmpty_queue())
    {
        vertex = del_queue();
        printf("%4d", vertex);
        state[vertex] = visited;

        for (i = 0; i < n; i++)
        {

            if (adj[vertex][i] == 1 && state[i] == initial)
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

// insert vertex into the queue
void insert_queue(int vertex)
{

    if (rear == MAX - 1)
        printf("Queue Overflow...!!!\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

// returns true if queue is empty
int isEmpty_queue()
{
    if (front == -1 || front > rear)
        return 1;
    else
    {
        return 0;
    }
}

// delete/remove  item from the queue
int del_queue()
{
    int del_item;

    if (front == -1 || front > rear)
    {
        printf("Queue Underflow...!!!\n");
        exit(1);
    }
    del_item = queue[front];
    front += 1;
    return del_item;
}

// create graph
void create_graph()
{

    int i, max_edge, origin, destin;
    printf("Enter the no of verticex : ");
    scanf("%d", &n);
    max_edge = n * (n - 1);
    for (i = 1; i <= max_edge; i++)
    {

        printf("Enter edge %d( -1 -1 ) to quit : ", i);
        scanf("%d%d", &origin, &destin);
        if ((origin == -1) && (destin == -1))
            break;
        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("Invalid Edge : \n");
            i--;
        }
        else
            adj[origin][destin] = 1;
    }
}

/*
*Program for traversing a directed graph through BFS, and finding shortest distance and
shortest path of any vertex from start
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define infinity 99999
#define NIL -1
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[MAX][MAX];
int state[MAX];
int distance[MAX];
int predecessor[MAX];
void create_graph();
void BF_Traversal();
void BFS(int v);
int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int del_queue();
int isEmpty_queue();

int main(void)
{

    int u, v, i, count, path[MAX];
    create_graph();
    BF_Traversal();
    while (1)
    {
        printf("Enter destination vertex (-1 to quit ) : ");
        scanf("%d", &v);

        if (v < -1 || v > n - 1)
        {
            printf("Destination vertex doesnot exixts . \n");
            continue;
        }
        if (v == -1)
            break;
        count = 0;
        if (distance[v] == infinity)
        {
            printf("No path from start vertex to destination vertex..\n");
            continue;
        }
        else
            printf("Shortest distance is : %d\n", distance[v]);

        while (v != NIL)
        {
            count++;
            path[count] = v;
            u = predecessor[v];
            v = u;
        }
        printf("Shortest path is : ");
        for (i = count; i > 1; i--)
            printf("%d -> ", path[i]);
        printf("%d", path[i]);
        printf("\n");
    }
}

void BF_Traversal()
{
    int v;
    for (v = 0; v < n; v++)
    {
        state[v] = initial;
        predecessor[v] = NIL;
        distance[v] = infinity;
    }
    printf("Enter starting vertex for  B F S. : ");
    scanf("%d", &v);
    BFS(v);
    printf("\n");
}

void BFS(int v)
{
    int i;
    insert_queue(v);
    state[v] = waiting;
    distance[v] = 0;
    predecessor[v] = NIL;

    while (!(isEmpty_queue()))
    {
        v = del_queue();
        printf("Vertex %d visited.\n", v);
        state[v] = visited;
        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && state[i] == initial)
            {

                insert_queue(i);
                state[i] = waiting;
                printf("-------Tree edge - (%d,%d) \n", v, i);
                predecessor[i] = v;
                distance[i] = distance[v] + 1;
            }
        }
    }
}

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

int isEmpty_queue()
{
    if (front == -1 || front > rear)
        return 1;
    else
    {
        return 0;
    }
}

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

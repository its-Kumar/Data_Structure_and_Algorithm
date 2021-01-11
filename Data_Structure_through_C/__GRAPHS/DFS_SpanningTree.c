/*
Program for traversing a directed graph through DFS, visiting all vertices
which are reached from start vertex or not.
*/
// @its-Kumar

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define NIL -1
#define initial 1
#define visited 2
int n;                //no of vertex
int adj[MAX][MAX];    //adjacency matrix
int state[MAX];       //state matrix
int predecessor[MAX]; // predecessors
void DF_Traversal();
void DFS(int v);
void create_graph();
int stack[MAX], top = -1; //stack for DFS
void push(int v);
int pop();
int isEmpty_stack();

main(void)
{
    create_graph();
    DF_Traversal();
}

void DF_Traversal()
{
    int v;
    for (v = 0; v < n; v++)
    {
        state[v] = initial;
        predecessor[v] = NIL;
    }
    printf("Enter starting vertex for Depth First Search : ");
    scanf("%d", &v);
    DFS(v);
    for (v = 0; v < n; v++)
    {
        if (state[v] == initial)
            DFS(v);
    }
    printf("\n");
    for (v = 0; v < n; v++)
        printf("Vertex %d, Predecessor %d\n", v, predecessor[v]);
    printf("Tree Edges : ");
    for (v = 0; v < n; v++)
    {
        if (predecessor[v] != -1)
            printf("Tree Edge : %d -> %d\n", predecessor[v], v);
    }
}
/**
 * @brief DFS from given vertex
 *
 * @param v vertex
 */
void DFS(int v)
{
    int i;
    push(v);
    while (!isEmpty_stack())
    {

        v = pop();
        if (state[v] == initial)
        {
            printf("%d  ", v);
            state[v] = visited;
        }
        for (i = n - 1; i >= 0; i--)
        {
            if (adj[v][i] == 1 && state[i] == initial)
            {
                push(i);
                predecessor[i] = v;
            }
        }
    }
}

void push(int v)
{
    if (top == (MAX - 1))
    {
        printf("Stack overflow....\n");
        return;
    }
    top += 1;
    stack[top] = v;
}

int pop()
{
    int v;
    if (top == -1)
    {
        printf("Stcak Underflow ... \n");
        exit(1);
    }
    else
    {
        v = stack[top];
        top -= 1;
        return v;
    }
}

int isEmpty_stack()
{
    if (top == -1)
        return 1;
    else
        return 0;
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

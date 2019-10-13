/*
*
    Program for traversing a directed graph through recursive DFS
*
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define visited 2
#define finished 3


int n;
int adj[MAX][MAX];
int state[MAX];
void DF_Traversal();
void DFS(int v);
void create_graph();

main(void)
{
    create_graph();
    DF_Traversal();
}

void DF_Traversal(){
    int v;
    for(v=0; v<n; v++)
        state[v] = initial;
    printf("Enter starting vertex of Dept First Search : ");
    scanf("%d", &v);
    DFS(v);
    for(v=0; v<n; v++)
    {
        if(state[v] == initial)
            DFS(v);
    }
    printf("\n");

}
void DFS(int v){
    int i;
    printf("%d ",v);
    state[v] = visited;
    for(i=0; i<n; i++){
        if(adj[v][i] = 1 && state[i]==initial)
            DFS(i);
    }
    state[v] = finished;
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

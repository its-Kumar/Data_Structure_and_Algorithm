/*
Program to find path matrix by Warshall's Algorithm.
*/

#include <stdio.h>
#define MAX 100
void display(int mat[MAX][MAX], int n);
int adj[MAX][MAX];
int n;
void create_graph();

int main(void)
{
    int i, j, k;
    int P[MAX][MAX];
    create_graph();
    printf("\nThe Adjacency Matrix is : \n ");
    display(adj, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            P[i][j] = adj[i][j];

    for (k = 0; k < n; k++)
    {

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                P[i][j] = (P[i][j] || (P[i][k] && P[k][j]));
        printf("P%d is : \n", k);
        display(P, n);
    }
    printf("P%d is the path matrix of the given graph.\n", k - 1);
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

void display(int matrix[][MAX], int n)
{

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

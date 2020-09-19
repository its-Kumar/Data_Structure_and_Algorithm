#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct Edge
{
    // Edge object will contain source vertex, destination vertex and cost/weight
    int source;
    int dest;
    int weight;
};
//edges contains edges of graph and MST contains edges of Minimal Spanning Tree
struct Edge edges[MAX], MST[MAX];

void sort(int n)
{
    int i, j;
    struct Edge tmp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                tmp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = tmp;
            }
        }
}
int Kruskal(int n)
{
    struct Edge tmp;
    int v1, v2, root_v1, root_v2;
    int Father[MAX]; //parent of each edge
    int i, count = 0, min_cost = 0;
    for (i = 0; i <= n; i++)
        Father[i] = -1;

    i = 0;
    while (i < n && count < n - 1)
    {
        tmp = edges[i++];
        v1 = tmp.source;
        v2 = tmp.dest;

        //check for parent of source
        while (v1 != -1)
        {
            root_v1 = v1;
            v1 = Father[v1];
        }

        //check for parent of dest
        while (v2 != -1)
        {
            root_v2 = v2;
            v2 = Father[v2];
        }
        //if parents are same the edge will make cycle
        if (root_v1 != root_v2)
        {
            MST[count++] = tmp;
            min_cost += tmp.weight;
            Father[root_v2] = root_v1;
        }
    }
    //if all edges are checked and tree is having less than n-1 edges
    if (i < n && count < n - 1)
    {
        printf("No spanning Tree is possible.\n");
        exit(1);
    }
    return min_cost;
}

int main(void)
{
    int n, i;
    int mct = 0;
    struct Edge tmp;

    printf("Enter the no of edges : ");
    scanf("%d", &n);

    printf("Enter edges with weights(u,v,w) : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tmp.source, &tmp.dest, &tmp.weight);
        edges[i] = tmp;
    }
    // sort the edges by their weights
    sort(n);
    mct = Kruskal(n);
    printf("\nMinimum Spanning Tree is : \n");
    printf("\n\tSource\tDest.\tWeight\n");
    for (i = 0; i < n - 1; i++)
    {
        if (MST[i].source < MST[i].dest)
            printf("\n\t%d\t%d\t%d", MST[i].source, MST[i].dest, MST[i].weight);
        else
            printf("\n\t%d\t%d\t%d", MST[i].dest, MST[i].source, MST[i].weight);
    }
    printf("\nMinimum Cost is = %d", mct);
    return 0;
}

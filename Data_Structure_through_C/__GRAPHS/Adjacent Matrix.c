#include <stdio.h>
#define MAX 50
int adj[MAX][MAX];
int n; //no of vertices
void main()
{
	int i, j, max_edges, source, dest;
	int graph_type;
	printf("Enter the graph type(1 for undirected and 2 for directed):\n");
	scanf("%d", &graph_type);
	printf("Enter the no of vertices:");
	scanf("%d", &n);
	if (graph_type == 1)
		max_edges = n * (n - 1) / 2;
	else
		max_edges = n * (n - 1);
	for (i = 1; i <= max_edges; i++)
	{
		printf("Enter edge %d(-1,-1 to quit):\n", i);
		scanf("%d%d", &source, &dest);
		if (source == -1 && dest == -1)
			break;
		if (source >= n || dest >= n || source < 0 || dest < 0)
		{
			printf("Invalid vertex:\n");
			i--;
		}
		else
		{
			adj[source][dest] = 1;
			if (graph_type == 1)
				adj[dest][source] = 1;
		}
	}
	printf("The Adjacent Matrix is:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%3d", adj[i][j]);
		printf("\n");
	}
	//getch();
}

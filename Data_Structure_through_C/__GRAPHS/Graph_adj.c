#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int adj[MAX][MAX];
int n; // no of edges
//program of directed graph

void display()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%3d", adj[i][j]);
		printf("\n");
	}
}
void del_edge(int source, int dest)
{
	if (source < 0 || source >= n || dest < 0 || dest >= n || adj[source][dest] == 0)
	{
		printf("This edge does not exist...");
		return;
	}
	adj[source][dest] = 0;
}
void insert_edge(int source, int dest)
{
	if (source < 0 || source >= n)
	{
		printf("Source vertex does not exist.");
		return;
	}
	if (dest < 0 || dest >= n)
	{
		printf("Source vertex does not exist.");
		return;
	}
	adj[source][dest] = 1;
}
void create_graph()
{
	int i, max_edges, source, dest;
	printf("Enter no of vertices: ");
	scanf("%d", &n);
	max_edges = n * (n - 1);
	for (i = 1; i <= max_edges; i++)
	{
		printf("Enter the edge %d(-1 -1 for exit): ", i);
		scanf("%d%d", &source, &dest);
		if (source == -1 && dest == -1)
			break;
		if (dest < 0 || dest >= n || source < 0 || source >= n)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[source][dest] = 1;
	}
}
int main()
{
	int choice, source, dest;
	create_graph();
	while (1)
	{
		printf("\n1. Insert edge\n");
		printf("2. Delete an edge\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter an edge to be insert: ");
			scanf("%d %d", &source, &dest);
			insert_edge(source, dest);
			break;
		case 2:
			printf("Enter an edge to be delete: ");
			scanf("%d %d", &source, &dest);
			del_edge(source, dest);
			break;
		case 3:
			display();
			break;
		case 4:
			exit(1);
		default:
			printf("Wrong Choice:;:;:");
			break;
		}
	}
	return 0;
}

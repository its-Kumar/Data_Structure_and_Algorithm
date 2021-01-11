//graph using adjacency list
// @its-Kumar

#include <stdio.h>
#include <stdlib.h>

// edges contains pointers destination vertex and next edge
struct edge;
// vertex contains info and pointers to first_edge and next vertex
struct vertex
{
	struct vertex *next_vertex;
	int info;
	struct edge *first_edge;
} *start = NULL;
struct edge
{
	struct vertex *dest_vertex;
	struct edge *next_edge;
};

// display the graph
void display()
{
	struct vertex *ptr;
	struct edge *q;
	ptr = start;
	while (ptr != NULL)
	{
		printf("%d -> ", ptr->info);
		q = ptr->first_edge;
		while (q != NULL)
		{
			printf(" %d", q->dest_vertex->info);
			q = q->next_edge;
		}
		printf("\n");
		ptr = ptr->next_vertex;
	}
}

/**
 * @brief insert a new vertex with given info
 *
 * @param u info to the vertex
 */
void insert_vertex(int u)
{
	struct vertex *tmp, *ptr;
	tmp = malloc(sizeof(struct vertex));
	tmp->info = u;
	tmp->next_vertex = NULL;
	tmp->first_edge = NULL;

	if (start == NULL)
	{
		start = tmp;
		return;
	}
	ptr = start;
	while (ptr->next_vertex != NULL)
		ptr = ptr->next_vertex;
	ptr->next_vertex = tmp;
}

// delete vertex from the graph having u info/val
void delete_vertex(int u)
{
	struct edge *p, *temporary;
	struct vertex *tmp, *q;
	if (start == NULL)
	{
		printf("No vertices to be deleted\n");
		return;
	}
	if (start->info == u)
	{
		tmp = start;
		start = start->next_vertex;
	}
	else
	{
		q = start;
		while (q->next_vertex != NULL)
		{
			if (q->next_vertex->info == u)
				break;
			q = q->next_vertex;
		}
		if (q->next_vertex == NULL)
		{
			printf("Vertex not found .... \n");
			return;
		}
		else
		{
			tmp = q->next_vertex;
			q->next_vertex = tmp->next_vertex;
		}

		p = tmp->first_edge;
		while (p != NULL)
		{
			temporary = p;
			p = p->next_edge;
			free(temporary);
		}
		free(tmp);
	}
}

// delete incoming edge to vertex u
void deleteIncomingEdge(int u)
{
	struct vertex *ptr;
	struct edge *q, *tmp;
	ptr = start;
	while (ptr != NULL)
	{

		if (ptr->first_edge == NULL)
		{
			ptr = ptr->next_vertex;
			continue;
		}
		if (ptr->first_edge->dest_vertex->info == u)
		{
			tmp = ptr->first_edge;
			ptr->first_edge = ptr->first_edge->next_edge;
			free(tmp);
			continue;
		}
		q = ptr->first_edge;
		while (q->next_edge != NULL)
		{
			if (q->next_edge->dest_vertex->info == u)
			{
				tmp = q->next_edge;
				q->next_edge = tmp->next_edge;
				free(tmp);
				continue;
			}
			q = q->next_edge;
		}
		ptr = ptr->next_vertex;
	}
}

/**
 * @brief Find the vertex having info u
 *
 * @param u info/ vertex to find
 * @return struct vertex* - the pointer to the vertex
 */
struct vertex *findVertex(int u)
{
	struct vertex *ptr, *loc;
	ptr = start;
	while (ptr != NULL)
	{
		if (ptr->info == u)
		{
			loc = ptr;
			return loc;
		}
		else
			ptr = ptr->next_vertex;
	}
}

/**
 * @brief Insert an edge between vertex u and v
 *
 * @param u vertex 1
 * @param v vertex 2
 */
void insert_edge(int u, int v)
{
	struct vertex *locu, *locv;
	struct edge *ptr, *tmp;
	locu = findVertex(u);
	locv = findVertex(v);
	if (locu == NULL)
	{
		printf("Start vertex not present first insert the vertex %d\n", u);
		return;
	}
	if (locv == NULL)
	{
		printf("End vertex not present first insert the vertex %d\n", v);
		return;
	}
	tmp = malloc(sizeof(struct edge));
	tmp->dest_vertex = locv;
	tmp->next_edge = NULL;
	if (locu->first_edge == NULL)
	{
		locu->first_edge = tmp;
		return;
	}
	ptr = locu->first_edge;
	while (ptr->next_edge != NULL)
		ptr = ptr->next_edge;
	ptr->next_edge = tmp;
}

/**
 * @brief Delete edge between vertex u and vertex v
 *
 * @param u vertex
 * @param v vertex
 */
void delete_edge(int u, int v)
{
	struct vertex *locu;
	struct edge *tmp, *q;
	locu = findVertex(u);
	if (locu == NULL)
	{
		printf("Start Vertex not present...\n");
		return;
	}
	if (locu->first_edge == NULL)
	{
		printf("Edge not present .... \n");
		return;
	}
	if (locu->first_edge->dest_vertex->info == v)
	{
		tmp = locu->first_edge;
		locu->first_edge = locu->first_edge->next_edge;
		free(tmp);
		return;
	}
	q = locu->first_edge;
	while (q->next_edge != NULL)
	{

		if (q->next_edge->dest_vertex->info == v)
		{
			tmp = q->next_edge;
			q->next_edge = tmp->next_edge;
			free(tmp);
			return;
		}
		q = q->next_edge;
	}
	printf("This Edge not present in the graph .... \n");
}

// main function
main()
{
	int choice, u, source, dest;
	while (1)
	{
		printf("\n1.Insert a vertex\n2.Insert an Edge\n");
		printf("3.Delete a vertex\n4.Delete an Edge\n");
		printf("5.Display\n6.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter a vertex to be inserted: ");
			scanf("%d", &u);
			insert_vertex(u);
			break;
		case 2:
			printf("Enter an Edge to be inserted: ");
			scanf("%d %d", &source, &dest);
			insert_edge(source, dest);
			break;
		case 3:
			printf("Enter a vertex to be deleted: ");
			scanf("%d", &u);
			deleteIncomingEdge(u);
			delete_vertex(u);
			break;

		case 4:
			printf("Enter an Edge to be deleted: ");
			scanf("%d %d", &source, &dest);
			delete_edge(source, dest);
			break;
		case 5:
			display();
			break;
		case 6:
			exit(1);
		default:
			printf("Wrong Choice");
			break;
		}
	}
}

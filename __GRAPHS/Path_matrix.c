//program to find out the path matrix by powers of adjacency matrix

#include<stdio.h>
#define MAX 100

void display(int matrix[][MAX]);
void pow_matrix(int p, int adjp[][MAX]);
void multiply(int mat1[][MAX],int mat2[][MAX],int mat3[][MAX]);
void create_graph();
int adj[MAX][MAX];
int n;

int main(void){

    int adjp[MAX][MAX];
    int x[MAX][MAX],path[MAX][MAX],i,j,p;
    create_graph();

    printf("The adjacency matrix is :  \n");
    display(adj);

    for (i=0; i<n; i++){
        for(j=0; j<n; j++)
            x[i][j] = 0;
    }

    for(p=1; p<=n; p++){

        pow_matrix(p,adjp);
        printf("Adjacency matrix raised to power %d is - \n",p);
        display(adjp);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                x[i][j] +=adjp[i][j];
    }
    printf("The matrix x is : \n");
    display(x);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(x[i][j] == 0)
                path[i][j] =0;
            else 
                path[i][j] =1;
    printf("The path matrix is : \n");
    display(path);
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


void pow_matrix(int p, int adjp[][MAX]){
	
    int i,j,k,tmp[MAX][MAX];

    for (i=0; i<n; i++)
        for(j=0; j<n; j++)
            adjp[i][j] = adj[i][j];
    
    for(k=1; k<p; k++){
        multiply(adjp,adj, tmp);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                adjp[i][j] = tmp[i][j];
    }
	
}

void multiply(int mat1[][MAX],int mat2[][MAX],int mat3[][MAX]){
	int i,j,k;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            mat3[i][j]  =0;
            for(k=0; k<n; k++)
                mat3 [i][j] += mat1[i][k] * mat2[k][j];
        }
    }	
}



void display(int matrix[][MAX]){

    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf("%4d",matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}


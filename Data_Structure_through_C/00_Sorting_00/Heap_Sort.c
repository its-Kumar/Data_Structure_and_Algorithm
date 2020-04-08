#include<stdio.h>

void Max_Heapify(int A[],int n,int i){
	int largest,tmp;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && A[l]>A[i])
		largest = l;
	else
		largest = i;
	if(r<n && A[r]>A[largest])
		largest = r;
	if(largest!=i){
		tmp = A[i];
		A[i] = A[largest];
		A[largest] = tmp;
		Max_Heapify(A,n,largest);
	}

}

void Build_Max_Heap(int A[],int n){
	int i;
	for(i=n/2-1;i>=0;i--)
		Max_Heapify(A,n,i);
}

void Heap_Sort(int A[],int n){
	int i,tmp;
	Build_Max_Heap(A,n);
	for(i=n-1;i>=0;i--){
		tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;
		n -= 1;
		Max_Heapify(A,n,0);
	}
}

int main(){
	int A[30],i,n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter elements of array:");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("\nGiven Array: ");
	for(i=0;i<n;i++)
		printf("%d  ",A[i]);
	Heap_Sort(A,n);
	printf("\nAfter sorted Array: ");
	for(i=0;i<n;i++)
		printf("%d  ",A[i]);
}

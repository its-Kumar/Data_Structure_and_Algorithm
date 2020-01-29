//function pointers as arguments
//program of quick sort using fuction pointers

#include<stdio.h>
#include<stdlib.h>

int compare(const void*,const void*);

void main(){
	int arr[5]={52,23,56,19,4};
	int num,width,i;
	
	num= sizeof(arr)/sizeof(arr[0]);
	width= sizeof(arr[0]);
	qsort((void*)arr,num,width,compare);
	
	for(i=0;i<5;i++)
		printf("%d ",arr[i]);
		
	getch();
	
}
int compare(const void *ele1, const void *ele2){
	if( (*(int *)ele1) == (*(int *)ele2))
		return 0;
	else if( (*(int *)ele1) < (*(int *)ele2))
		return -1;
	else
		return 1;
}


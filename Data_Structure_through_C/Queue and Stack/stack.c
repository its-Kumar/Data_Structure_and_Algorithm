//implimentation of stack through Array

#include<stdio.h>
#include<stdlib.h>

int push(char s[],int t){
	t++;
	printf("Enter the value to be pushed:");
	fflush(stdin);
	scanf("%c",&s[t]);
	return t;	
}
void pop(int *t){
	(*t)--;
}
char peak(char s[],int *t){
	char ch;
	ch=s[*t];
	*(t)--;
	return ch;
}
void main(){
	char p,s[10];
	int i,choice,top=-1;
	while(1){
	printf("\n1.push\n2.pop\n3.peak");
	printf("\n4.view stack");
	printf("\n0.Exit");
	printf("\nEnter choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			top=push(s,top);  break;
		case 2:
			pop(&top);  break;
		case 3:
			p=peak(s,&top);
			printf("\npeaked value is %c",p);
			break;
		case 4:
			for(i=0;i<=top;i++){
				printf("\t%c",s[i]);
			}  break;
		case 0:
			exit(-1);
		default:
			printf("wrong choice");
	}
		}
}

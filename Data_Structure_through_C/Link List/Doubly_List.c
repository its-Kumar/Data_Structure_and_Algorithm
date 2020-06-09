/*Program of doubly linked list*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int info;
	struct Node *next;
};
typedef struct Node node;
node *start = NULL;

void create_list();
void display();
void addtoempty(int data);
void addatbeg(int data);
void addatend(int data);
void addafter(int data,int item);
void addbefore(int data,int item);
void del(int data);
void reverse();


int main()
{
	int choice,data,item;
	while(1)
	{
		printf("\n1.Create List\n");
		printf("2.Display\n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after\n");
		printf("7.Add before\n");
		printf("8.Delete\n");
		printf("9.Reverse\n");
		printf("10.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			create_list();
			break;
		 case 2:
			display();
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			addtoempty(data);
			break;
		 case 4:
	        printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			addatbeg(data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			addatend(data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			addafter(data,item);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&item);
			addbefore(data,item);
			break;
		 case 8:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			del(data);
	   		break;
		 case 9:
		 	reverse();
			break;
		 case 10:
			exit(1);
		 default:
			printf("Wrong choice\n");
	}/*End of switch*/
   }/*End of while*/
}/*End of main()*/

void create_list()
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	addtoempty(data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		addatend(data);
	}
	return;
}/*End of create_list()*/

void display()
{
	node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d -> ",p->info);
		p=p->next;
	}
	printf("\n");
}/*End of display() */

void addtoempty(int data)
{
	node *tmp;
	tmp=(node *)malloc(sizeof(node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return;
}/*End of addtoempty( )*/

void addatbeg(int data)
{
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
	return;
}/*End of addatbeg( )*/

void addatend(int data)
{
	node *tmp,*p;
	tmp=(node *)malloc(sizeof(node));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return;
}/*End of addatend( )*/

void addafter(int data,int item)
{
	node *tmp,*p;
	tmp=(node *)malloc(sizeof(node));
	tmp->info=data;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp->prev=p;
			tmp->next=p->next;
			if(p->next!=NULL)
				p->next->prev=tmp;
			p->next=tmp;
			return;
		}
		p=p->next;
	}
	printf("%d not present in the list\n\n",item);
	return;
}/*End of addafter()*/

void addbefore(int data,int item)
{
	node *tmp,*q;
	if(start==NULL )
	{
		printf("List is empty\n");
		return;
	}
    tmp = (node *)malloc(sizeof(node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;

	if(start->info==item)
	{
		tmp->next=start;
		start->prev=tmp;
		start=tmp;
		return;
	}
	q=start;
	while(q!=NULL)
	{
		if(q->info==item)
		{
			tmp->prev=q->prev;
			tmp->next = q;
			q->prev->next=tmp;
			q->prev=tmp;
			return;
		}
		q=q->next;
	}
	printf("%d not present in the list\n",item);
	return;
}/*End of addbefore()*/

void del(int data){
	node *tmp;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(start->next==NULL)	/*only one node in the list*/
		if(start->info==data)
		{
			tmp=start;
			start=NULL;
			free(tmp);
			return;
		}
		else
		{
			printf("Element %d not found\n",data);
			return;
		}
	/*Deletion of first node*/
	if(start->info==data)
	{
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);
		return;
	}
	/*Deletion in between*/
	tmp=start->next;
	while(tmp->next!=NULL )
	{
		if(tmp->info==data){
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			return;
		}
		tmp=tmp->next;
	}
	/*Deletion of last node*/
	if(tmp->info==data)
	{
		tmp->prev->next=NULL;
		free(tmp);
		return;
	}
	printf("Element %d not found\n",data);
	return;
}/*End of del()*/

void reverse(){
	node *p1,*p2;
	p1=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	start=p1;
	printf("List reversed\n");
}/*End of reverse()*/

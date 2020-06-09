/* Program of sorted linked list*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};
typedef struct Node node;
node *start = NULL;

void insert_s(int data);
void search(int data);
void display();
main()
{
    int choice, data;
    while (1)
    {
        printf("1.Insert\n");
        printf("2.Display\n");
        printf("3.Search\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            insert_s(data);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("Enter the element to be searched : ");
            scanf("%d", &data);
            search(data);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice\n");
        } /*End of switch*/
    }     /*End of while*/
} /*end of main */

void insert_s(int data)
{
    node *p, *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->info = data;
    tmp->link = NULL;
    /*list empty or new node to be added before first node*/
    if (start == NULL || data < start->info)
    {
        tmp->link = start;
        start = tmp;
        return;
    }
    else
    {
        p = start;
        while (p->link != NULL && p->link->info < data)
            p = p->link;
        tmp->link = p->link;
        p->link = tmp;
    }
    return;
} /*End of insert()*/
void search(int data)
{
    node *p;
    int pos;
    if (start == NULL || data < start->info)
    {
        printf("%d not found in list\n", data);
        return;
    }
    p = start;
    pos = 1;
    while (p != NULL && p->info <= data)
    {
        if (p->info == data)
        {
            printf("%d found at position %d\n", data, pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("%d not found in list\n", data);
} /*End of search()*/

void display()
{
    node *q;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    q = start;
    printf("List is :\n");
    while (q != NULL)
    {
        printf("%d -> ", q->info);
        q = q->link;
    }
    printf("\n");
} /*End of display() */

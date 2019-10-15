/* Program of sorting a single linked list*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;
node *start = NULL;

void create_list();
void display();
void addatbeg(int data);
void addatend(int data);
void selection();
void bubble();
void selection_l();
void bubble_l();

main()
{
    int choice;
    while (1)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Bubble Sort\n");
        printf("4.Selection Sort\n");
        printf("5.Bubble Sort by changing links\n");
        printf("6.Selection Sort by changing links\n");
        printf("7.Quit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_list();
            break;
        case 2:
            display();
            break;
        case 3:
            bubble();
            break;
        case 4:
            selection();
            break;
        case 5:
            bubble_l();
            break;
        case 6:
            selection_l();
            break;
        case 7:
            exit(1);
        default:
            printf("Wrong choice\n\n");
        } /*End of switch */
    }     /*End of while */
} /*End of main()*/

void create_list()
{
    int i, n, data;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return;

    printf("Enter the element to be inserted : ");
    scanf("%d", &data);
    addatbeg(data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &data);
        addatend(data);
    }
} /*End of create_list()*/

void display()
{
    node *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    p = start;
    printf("List is : ");
    while (p != NULL)
    {
        printf("%d -> ", p->info);
        p = p->link;
    }
    printf("\n");
} /*End of display() */

void addatbeg(int data)
{
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
} /*End of addatbeg()*/

void addatend(int data)
{
    node *p, *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->info = data;
    p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = tmp;
    tmp->link = NULL;
} /*End of addatend()*/

void selection()
{
    node *p, *q;
    int tmp;
    p = start;
    for (p = start; p->link != NULL; p = p->link)
    {
        for (q = p->link; q != NULL; q = q->link)
        {
            if (p->info > q->info)
            {
                tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
} /*End of selection( )*/

void bubble()
{
    node *end, *p, *q;
    int tmp;
    for (end = NULL; end != start->link; end = q)
    {
        for (p = start; p->link != end; p = p->link)
        {
            q = p->link;
            if (p->info > q->info)
            {
                tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
} /*End of bubble( )*/
void selection_l()
{
    node *p, *q, *r, *s, *tmp;

    for (r = p = start; p->link != NULL; r = p, p = p->link)
    {
        for (s = q = p->link; q != NULL; s = q, q = q->link)
        {
            if (p->info > q->info)
            {
                tmp = p->link;
                p->link = q->link;
                q->link = tmp;
                if (p != start)
                    r->link = q;
                s->link = p;
                if (p == start)
                    start = q;
                tmp = p;
                p = q;
                q = tmp;
            }
        }
    }
    return;
} /*End of selection_l( )*/

void bubble_l()
{
    node *end, *r, *p, *q, *tmp;

    for (end = NULL; end != start->link; end = q)
    {
        for (r = p = start; p->link != end; r = p, p = p->link)
        {
            q = p->link;
            if (p->info > q->info)
            {
                p->link = q->link;
                q->link = p;
                if (p != start)
                    r->link = q;
                else
                    start = q;
                tmp = p;
                p = q;
                q = tmp;
            }
        }
    }
    return;
} /*End of bubble_l( )*/

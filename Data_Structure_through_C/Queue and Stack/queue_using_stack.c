/*
Author: Kumar Shanu
Program: Implement queue datastructure using stack.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10      // size of queue
int s1[N], s2[N]; // two stacks
int top1 = -1, top2 = -1;
int count = 0;

// push operation of stack
void push(int *stack, int x)
{
    if (stack == s1)
    {
        if (top1 == N - 1)
        {
            printf("Overflow");
            return;
        }
        top1++;
        s1[top1] = x;
    }
    if (stack == s2)
    {
        if (top2 == N - 1)
        {
            printf("Overflow");
            return;
        }
        top2++;
        s2[top2] = x;
    }
}

// pop operation of stack
int pop(int *stack)
{
    if (stack == s1)
    {
        if (top1 == -1)
        {
            printf("Underflow....");
        }
        else
            return s1[top1--];
    }
    if (stack == s2)
    {
        if (top2 == -1)
        {
            printf("Underflow....");
        }
        else
            return s2[top2--];
    }
}

// enqueue operation of queue
void enqueue(int x)
{
    if (top1 == N - 1)
    {
        printf("Queue is full");
        return;
    }
    // insert data into stack 1
    push(s1, x);
}

// dequeue operation of queue
int dequeue()
{
    int val, tmp;
    if (top1 == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        // remove elements from stack 1 and insert into stack 2
        while (top1 != -1)
        {
            tmp = pop(s1);
            push(s2, tmp);
        }

        // store value to return
        val = pop(s2);

        // move data back into stack 1
        while (top2 != -1)
        {
            tmp = pop(s2);
            push(s1, tmp);
        }
        return val;
    }
}

// print the queue
void display()
{
    printf("Queue is: \n");
    for (int i = 0; i <= top1; i++)
    {
        printf("%5d", s1[i]);
    }
    printf("\n");
}

// main function
int main()
{
    int choice, val;
    while (1)
    {
        printf("\nProgram of Queue using stack\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display queue\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            printf("%d", val);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

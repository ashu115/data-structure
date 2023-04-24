// Circular Queue implementation in C
/*Create a Circular Queue structure with following Data members:
1. Integer Array
2. Size of the Array

Perform the following operations on Circular queue using user-defined functions:
1. Insert an element
2. Remove an element
3. Display
4. Isfull
5. Isempty
Create a file which stores all values of Array*/

#include <stdio.h>
#include<stdlib.h>
#define max 3

struct queue
{
    int que[max];
    int size;
};
typedef struct queue QUEUE;
QUEUE q;
int front = -1, rear = -1;

// Check if the queue is full
int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == q.size - 1))
        return 1;
    return 0;
}

// Check if the queue is empty
int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

// Adding an element
void enqueue(int element)
{
    if (isFull())
        printf("\n Queue is full!! \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % q.size;
        q.que[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}

// Removing an element
int dequeue()
{
    int element;
    if (isEmpty())
    {
        printf("\n Queue is empty !! \n");
        return (-1);
    }
    else
    {
        element = q.que[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        // Q has only one element, so we reset the
        // queue after dequeing it. ?
        else
        {
            front = (front + 1) % q.size;
        }
        printf("\n Deleted element -> %d \n", element);
        return (element);
    }
}

// Display the queue
void display()
{
    int i;
    if (isEmpty())
        printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ", front);
        printf("\n ques -> ");
        for (i = front; i != rear; i = (i + 1) % q.size)
        {
            printf("%d ", q.que[i]);
        }
        printf("%d ", q.que[i]);
        printf("\n Rear -> %d \n", rear);
    }
}
void writetofile()
{
    FILE *out_file = fopen("cqdata.txt", "w"); // write only
    int i = front;

    if (out_file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }
    else
    {
        if (isEmpty() != 1)
        {
            for (i = front; i != rear; i = (i + 1) % q.size)
            {

                fprintf(out_file, "\t%d", q.que[i]);
            }
            fprintf(out_file, "\t%d ", q.que[i]);
            printf("Queue elements are sucessfully written into a file.");
        }
    }
}

void main()
{
    int choice = 1, x;
    q.size = max;
    while (choice < 5 && choice != 0) // while loop
    {
        printf("\n1.Insert an element");
        printf("\n2: Delete an element");
        printf("\n3: Display the element");
        printf("\n4: write to file");
        printf("\n5: exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter the element which is to be inserted:");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            writetofile();
            break;
        case 5:
            printf("Exiting....");
            break;
        }
    }
}
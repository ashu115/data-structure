#include <stdio.h>
#include <stdlib.h>
#define MAX 3

struct queue
{
    int queue_array[MAX];
    int size;
};
typedef struct queue QUEUE;
QUEUE q;
void insert();
void delete();
void display();
void writetofile();

int rear = -1;
int front = -1;
int main()
{
    int choice;

    q.size = MAX;
    while (1)
    {
        printf("\n1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Write queue elements to file \n");
        printf("5.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            writetofile();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }
}
void writetofile()
{
    int i;
    FILE *out_file = fopen("QUEUE_elements.TXT", "w"); // write only
    if (out_file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }
    for (i = front; i <= rear; i++)
    {
        fprintf(out_file, "%d", q.queue_array[i]);
        fprintf(out_file, "\t");
    }
    printf("Queue elements are sucessfully written into a file.");
}

int isfull()
{
    int item;
    if (rear == q.size - 1)
    {
        printf("Queue Overflow \n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert()
{
    int item;
    int temp = isfull();
    if (temp != 1)
    {
        if (front == -1)
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &item);
        rear = rear + 1;
        q.queue_array[rear] = item;
    }
}

int isempty()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void delete()
{
    int temp = isempty();
    if (temp != 1)
    {
        printf("Element deleted from queue is : %d\n", q.queue_array[front]);
        front = front + 1;
    }
}
void display()
{
    int i;
    int temp = isempty();
    if (temp != 1)
    {
        printf("Queue is :  ");
        for (i = front; i <= rear; i++)
        {
            printf("\t%d", q.queue_array[i]);
        }
    }
}
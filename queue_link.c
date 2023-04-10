#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;

void insert();
void delete();
void display();
void writetofile();

void main()
{
    int choice;
    while (choice != 5)
    {
        printf("\nMain Menu");
        printf("\n1.insert an element \n2.Delete an elementn \n3.Display the queue \n4.Write to file \n5.Exit");
        printf("\nEnter your choice:");
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
            exit(0);
            break;
        default:
            printf("\nEnter valid choice");
        }
    }
}
int isfull(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("OVERFLOW");
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert()
{
    struct node *ptr;
    int item;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (isfull(ptr) != 1)
    {
        printf("\nEnter value:");
        scanf("%d", &item);
        ptr->data = item;
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
int isempty()
{
    if (front == NULL)
    {
        printf("\nUNDERFLOW");
        return 1;
    }
    else
    {
        return 0;
    }
}

void delete()
{
    struct node *ptr;
    if (isempty() != 1)
    {
        ptr = front;
        printf("deleted:%d", front->data);
        front = front->next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if (isempty() != 1)
    {
        printf("\nprinting values .....:");
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
    }
}
void writetofile()
{
    FILE *out_file = fopen("queuedata.txt", "w"); // write only
    struct node *ptr;
    ptr = front;

    if (out_file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }
    else
    {
        while (ptr != NULL)
        {
            fprintf(out_file, "\t%d", ptr->data);
            ptr = ptr->next;
        }
        printf("Queue elements are sucessfully written into a file.");
    }
}
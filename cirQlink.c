#include <stdio.h>
#include<stdlib.h>
// Declaration of struct type node
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int x);
void dequeue();
int isempty();
int isfull(struct node *ptr);
void writetofile();
void display();
// function to insert the element in the Queue
void enqueue(int x)
{
    struct node *newnode; // declaration of pointer of struct node type.
    newnode = (struct node *)malloc(sizeof(struct node));
    // allocating the memory to the newnode
    if (isfull(newnode) != 1)
    {
        newnode->data = x;
        newnode->next = 0;
        if (rear == NULL)
        // checking whether the Queue is empty or not.
        {
            front = rear = newnode;
            rear->next = front;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
            rear->next = front;
        }
    }
}
// function to delete the element from the queue
void dequeue()
{
    struct node *temp; // declaration of pointer of node type
    temp = front;
    if (!isempty())
    {
        if (front == rear)
        // checking whether the single element is left in the queue
        {
            front = rear = NULL;
            free(temp);
        }
        else
        {
            front = front->next;
            rear->next = front;
            free(temp);
        }
    }
}

// function to get the front of the queue
int isempty()
{
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is empty");
        return 1;
    }
    return 0;
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

// function to display all the elements of the queue
void display()
{
    struct node *temp;
    temp = front;
    printf("\n The elements in a Queue are : ");
    if ((front == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
    }

    else
    {
        while (temp->next != front)
        {
            printf("%d,", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

void writetofile()
{
    FILE *out_file = fopen("queuedata.txt", "w"); // write only
    struct node *temp;
    temp = front;
    fprintf(out_file, "\n The elements in a Queue are : ");
    if ((front == NULL) && (rear == NULL))
    {
        fprintf(out_file, "Queue is empty");
    }

    else
    {
        while (temp->next != front)
        {
            fprintf(out_file, "%d,", temp->data);
            temp = temp->next;
        }
        fprintf(out_file, "%d", temp->data);
    }
}

/* Driver of the program */

void main()
{
    int choice = 1, x;
              //  Queue *q;
    front, rear = NULL;

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
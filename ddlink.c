#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    struct SSL *prevs;
    int data;
    struct SLL *next;
};
typedef struct SLL node;
node *start = NULL, *rear = NULL;
int choice, i;
struct node *copyList(node *head);
void create()
{
    node *temp;
    printf("\nCreating List\nEnter Data (Enter -1 to stop)...\n");
    scanf("%d", &i);
    while (i != -1)
    {
        temp = (node *)malloc(sizeof(node));
        temp->prevs=NULL;
        temp->next = NULL;
        temp->data = i;
        if (start == NULL)
        {
            start = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            temp->prevs=rear;
            rear = temp;
        }
        scanf("%d", &i);
    }
    printf("\n-1 encountered\n");
}
void traverse()
{
    node *temp;
    if (start == NULL)
    {
        printf("\nCreate A LIST first...");
        create();
    }
    else
    {
        temp = start;
        printf("\nThe list as below\n");
        while (temp->next != NULL)
        {
            printf(" %d - >", temp->data);
            temp = temp->next;
        }
        printf(" %d", temp->data);
    }
}
void delete_first()
{
    node *temp;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
    }
    else
    {
        temp = start;
        start = start->next;
        start->prevs=NULL;
        printf("\nDeleted element is %d\n", temp->data);
        free(temp);
    }
}
void delete_last()
{
    node *temp;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            rear = temp;
            temp = temp->next;
        }
        rear->next = NULL;
        printf("\nDeleted element is %d\n", temp->data);
        free(temp);
    }
}
void delete_before()
{
    node *temp, *prev;
    int flag = 0, count = 0;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
        return;
    }
    printf("\nEnter value before to be deleted\n");
    scanf("%d", &i);
    temp = start;
    while (temp != NULL)
    {
        count++;
        if (temp->data == i)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
    {
        if (count == 1)
        {
            printf("Cannot delete before element of %d\n", i);
        }
        else if (count == 2)
        {
            temp = start;
            start = start->next;
            start->prevs=NULL;
            free(temp);
        }
        else
        {
            temp = start;
            while (temp != NULL)
            {
                prev = temp;
                temp = temp->next;
                if (temp->next->data == i)
                {
                    prev->next = temp->next;
                    temp->next->prevs=prev;
                    free(temp);
                    break;
                }
            }
        }
    }
    else
    {
        printf("\nValue is not found\n");
    }
}
void insert_first()
{
    node *temp;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
        return;
    }
    temp = (node *)malloc(sizeof(node));
    printf("Enter value to insert: ");
    scanf("%d", &i);
    temp->data = i;
    temp->next=NULL;
    temp->prevs=NULL;
    
    temp->next = start;
    temp->prevs=NULL;
    start->prevs=temp;
    start = temp;
}
void insert_last()
{
    node *temp;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
        return;
    }
    temp = (node *)malloc(sizeof(node));
    printf("Enter value to insert: ");
    scanf("%d", &i);
    temp->data = i;
    temp->next = NULL;
    temp->prevs=NULL;
    temp->prevs=rear;
    rear->next = temp;
    rear = temp;
}
void insert_before()
{
    node *temp, *trav, *prev;
    int val, flag = 0, count = 0;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
        return;
    }
    printf("Enter before value to insert: ");
    scanf("%d", &val);
    temp = start;
    while (temp != NULL)
    {
        count++;
        if (temp->data == val)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
    {
        temp = (node *)malloc(sizeof(node));
        printf("Enter value to insert: ");
        scanf("%d", &i);
        temp->data = i;
        temp->next = NULL;
        temp->prevs=NULL;
        if (count == 1)
        {
            temp->next = start;
            start->prevs=temp;
            start = temp;
            start->prevs=NULL;
        }
        else
        {
            trav = start;
            while (trav != NULL)
            {
                prev = trav;
                trav = trav->next;
                if (trav->data == val)
                {
                    prev->next = temp;
                    temp->prevs=prev;
                    temp->next = trav;
                    trav->prevs=temp;
                    break;
                }
            }
        }
    }
    else
    {
        printf("\nValue is not found\n");
    }
}
void insert_specified()
{
    node *temp, *trav, *prev;
    int val, flag = 0, count = 0;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
        return;
    }
    printf("Enter position to insert: ");
    scanf("%d", &val);
    val--;
    if (val < 1)
    {
        insert_first();
    }
    else
    {
        trav = start;
        while (count != val && trav->next != NULL)
        {
            count++;
            prev = trav;
            trav = trav->next;
        }
        if (count == val)
        {
            temp = (node *)malloc(sizeof(node));
            printf("Enter value to insert: ");
            scanf("%d", &i);
            temp->data = i;
            temp->next = trav;
            temp->prevs=prev;
            trav->prevs=temp;
            prev->next = temp;
        }
        else
        {
            insert_last();
        }
    }
}
void count()
{
    node *temp;
    int count = 0;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
        return;
    }
    temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("\nTotal Nodes: %d\n", count);
}
void reverse_list()
{
    node *temp;
    int count = 0, *rev_array;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
        return;
    }
    temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    rev_array = (int *)malloc(count * sizeof(int));
    temp = start;
    for (i = 0; i < count; i++)
    {
        *(rev_array + i) = temp->data;
        temp = temp->next;
    }
    // printf("%d\n%d\n",sizeof(rev_array),count);
    temp = start;
    for (i = count - 1; i >= 0; i--)
    {
        temp->data = *(rev_array + i);
        rear = temp;
        temp = temp->next;
    }
}
void search()
{
    node *temp;
    int count = 0, flag = 0, val;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
        return;
    }
    printf("Enter value to search: ");
    scanf("%d", &val);
    temp = start;
    while (temp != NULL)
    {
        count++;
        if (val == temp->data)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("Entered value is not found...\n");
    }
    else
    {
        printf("%d is found at position: %d\n", val, count);
    }
}
void sort_list()
{
    node *temp, *temp2;
    int temp3;
    if (start == NULL)
    {
        printf("\nThere is no list created\n");
        return;
    }
    temp = start;
    while (temp != NULL)
    {
        temp2 = temp->next;
        while (temp2 != NULL)
        {
            // printf("%d\t%d\n",temp->data,temp2->data);
            if (temp2->data < temp->data)
            {
                temp3 = temp2->data;
                temp2->data = temp->data;
                temp->data = temp3;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}
void save()
{
    node *temp;
    if (start != NULL)
    {
        FILE *fptr;
        fptr = fopen("custom_list.txt", "w");
        if (fptr == NULL)
        {
            printf("Error in file!");
            exit(0);
        }
        temp = start;
        while (temp->next != NULL)
        {
            fprintf(fptr, " %d -> ", temp->data);
            temp = temp->next;
        }
        fprintf(fptr, " %d", temp->data);
        printf("\n File is saved");
        fclose(fptr);
    }
    else
    {
        printf("\n The Queue is empty");
    }
}

// Function to create a copy of a linked list
struct node *copyList(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {

        // Allocate the memory for new Node
        // in the heap and set its data
        node *newNode = (node *)malloc(
            sizeof(node));

        newNode->data = head->data;

        // Recursively set the next pointer of
        // the new Node by recurring for the
        // remaining nodes
        newNode->next = copyList(head->next);

        return newNode;
    }
}
void printList(node *head)
{
    node *ptr = head;
    while (ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    };
}
int main()
{
    struct Node *dup;
    // clrscr();
    do
    {
        printf("\n\t Queue OPERATIONS USING LINKED LIST");
        printf("\n\t--------------------------------");
        printf("\n\t 1. Create a list\n\t 2. Traverse the whole list\n\t 3. Delete first node\n\t 4. Delete last node\n\t 5. Delete a node before specified data\n\t 6. Insert at first position\n\t 7. Insert at last position\n\t 8. Insert a node before specified data\n\t 9. Insert a node at specified position\n\t 10. Count\n\t 11. Copy\n\t 12. Reverse\n\t 13. Search\n\t 14. Sort\n\t 15. Save\n\t 16. Exit");
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            create();
            break;
        }
        case 2:
        {
            traverse();
            break;
        }
        case 3:
        {
            delete_first();
            break;
        }
        case 4:
        {
            delete_last();
            break;
        }
        case 5:
        {
            delete_before();
            break;
        }
        case 6:
        {
            insert_first();
            break;
        }
        case 7:
        {
            insert_last();
            break;
        }

        case 8:
        {
            insert_before();
            break;
        }
        case 9:
        {
            insert_specified();
            break;
        }
        case 10:
        {
            count();
            break;
        }
        case 11:
        {
            // Head of the duplicate Linked List
            dup = copyList(start);
            printf("Original list:");
            printList(start);
            printf("\nDuplicate list:");
            printList(dup);
            break;
        }
        /*case 12:
        {
        break;
        } */
        case 12:
        {
            reverse_list();
            break;
        }
        case 13:
        {
            search();
            break;
        }
        case 14:
        {
            sort_list();
            break;
        }
        case 15:
        {
            save();
            break;
        }
        case 16:
        {
            printf("\nExit point...\n");
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1 to 17)");
        }
        }
    } while (choice != 16);
    return 0;
}
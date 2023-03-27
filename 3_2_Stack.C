#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
void write();
struct node
{
	int val;
	struct node *next;
};
struct node *head;

int main()
{
	int choice = 0;
	printf("*********Stack operations using linked list*********");
	//   printf("\n----------------------------------------------\n");
	while (choice != 5)
	{
		printf("\nChose one from the below options...");
		printf("\n1.Push\t2.Pop\t3.Show\t4.write to file \t5.Exit");
		printf("\n Enter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			push();
			break;
		}
		case 2:
		{
			pop();
			break;
		}
		case 3:
		{
			display();
			break;
		}
		case 4:
		{
			write();
			break;
		}
		case 5:
		{
			printf("Exiting....");
			break;
		}
		default:
		{
			printf("Please Enter valid choice ");
		}
		};
	}
	return 0;
}
void push()
{
	int val;
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	if (ptr == NULL)
	{
		printf("not able to push the element");
	}
	else
	{
		printf("Enter the value:");
		scanf("%d", &val);
		if (head == NULL)
		{
			ptr->val = val;
			ptr->next = NULL;
			head = ptr;
		}
		else
		{
			ptr->val = val;
			ptr->next = head;
			head = ptr;
		}
		printf("Item pushed");
	}
}

void pop()
{
	int item;
	struct node *ptr;
	if (head == NULL)
	{
		printf("Underflow");
	}
	else
	{
		item = head->val;
		ptr = head;
		head = head->next;
		free(ptr);
		printf("Item popped");
	}
}
void display()
{
	int i;
	struct node *ptr;
	ptr = head;
	if (ptr == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Printing Stack elements: \t");
		while (ptr != NULL)
		{
			printf("%d\t", ptr->val);
			ptr = ptr->next;
		}
	}
}
void write()
{
	FILE *out_file = fopen("stackdata.TXT", "w");
	// write only
	struct node *ptr;
	ptr = head;
	if (out_file == NULL)
	{
		printf("Error! Could not open file\n");
		//  exit(-1); // must include stdlib.h
	}
	else
	{
		while (ptr != NULL)
		{
			fprintf(out_file, "\t%d", ptr->val);
			ptr = ptr->next;
		}
		printf("Stack elements are sucessfully written into a file.");
	}
}

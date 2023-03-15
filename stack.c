#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// structure declaration
struct stack
{
    int stk[SIZE];
    int top;
};
typedef struct stack STACK;
STACK s;

// Function prototype
void push(int);
int pop();
void display();
void peep(int);
void writeToFile();

// main function
void main()
{
    int ch = 0, num = 0;
    s.top = -1;

    while (1)
    {
        printf("\n1.push \n");
        printf("2.pop \n");
        printf("3.display \n");
        printf("4.peep \n");
        printf("5.Write to file \n");
        printf("6.Quit \n");
        printf("Enter the choice :-");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element to push:- ");
            scanf("%d", &num);
            push(num);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Enter position:- ");
            scanf("%d", &num);
            peep(num);
            break;

        case 5:
            writeToFile();
            break;

        case 6:
            exit(1);
            break;

        default:
            printf("!Wrong choice");
        }
    }
}

// push defination
void push(int num)
{
    int val = 0;
    val = isfull();
    if (val == 0)
    {
        s.top += 1;
        s.stk[s.top] = num;
    }
    else
    {
        printf("Unable to push element, Stack is full");
    }
}

// pop defination
int pop()
{
    int val = 0, num = 0;
    val = isempty();
    if (val == 0)
    {
        num = s.stk[s.top];
        printf("%d is popped out of stack successfully", num);
        s.top -= 1;
        return num;
    }
}

// peep defination
void peep(int pos)
{
    int val = 0, num;
    val = isempty();
    if (val == 0)
    {
        num = s.stk[s.top - pos + 1];
        printf("%d th Element from top of Stack is %d", pos, num);
    }
    else
    {
        printf("No elements to peep");
    }
    
}

//display defination
void display()
{
    int i, val = 0;
    val = isempty();
    if (val != 0)
    {
        printf("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf("%d\t", s.stk[i]);
        }
    }
    printf("\n");
}
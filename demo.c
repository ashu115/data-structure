#include <stdio.h>

#define MAXSIZE 3

struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;
// stack s;

void push(int);
int pop(void);
void display(void);
void peep(int);

void main()
{

    int choice = 0, num = 0;
    clrscr();
    s.top = -1;
    while (1)
    {
        printf("\n1.push \n");
        printf("2.pop \n");
        printf("3.peep \n");
        printf("4.display \n");
        printf("5.Write to file \n");
        printf("6.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter element to push:");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("enter position:");
            scanf("%d", &num);
            peep(num);
            break;
        case 4:
            display();
        case 5:
            writetofile();
            break;
        case 6:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }

    getch();
}
/*  Function to add an element to the stack */
void push(int num)
{
    int val = 0;

    val = isfull();

    if (val != 1)
    {
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    else
    {
        printf("\n Stack is full we can not push element : %d", num);
    }
}
/*  Function to delete an element from the stack */
int pop()
{
    int num, val = 0;

    val = isempty();
    if (val != 0)
    {
        num = s.stk[s.top];
        printf("poped element is = %d", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return (num);
}

int isempty()
{
    if (s.top == -1)
    {
        printf("\n Stack is empty");
        return 0;
    }
    else
    {
        return 1;
    }
}
int isfull()
{
    if (s.top == MAXSIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void peep(int pos)
{
    int num, val = 0;
    val = isempty();
    if (val != 0)
    {
        num = s.stk[s.top - pos + 1];
        printf("%d th Element from top of Stack is %d", pos, num);
    }
    else
    {
        printf("No elements to peep");
    }
}

/*  Function to display the status of the stack */
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
writetofile()
{
    int i;
    FILE *out_file = fopen("stack_elements.TXT", "w"); // write only
    if (out_file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }
    for (i = s.top; i >= 0; i--)
    {
        fprintf(out_file, "%d\t", s.stk[i]);
    }
    printf("stack elements are sucessfully written into a file.");
}
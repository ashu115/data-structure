#include <stdio.h>
struct arrStruct
{
    int arr[20];
    int arrSize;
} a1;
void main()
{
    int i, s, f = 0;
    printf("Enter the size of Array(<20)==>");
    scanf("%d", &a1.arrSize);

    printf("Enter the Elements of array ==>");
    for (i = 0; i < a1.arrSize; i++)
    {
        scanf("%d", &a1.arr[i]);
    }

    printf("Enter the value to be find:-");
    scanf("%d", &s);
    f = 0;
    for (i = 0; i < a1.arrSize; i++)
    {
        if (a1.arr[i] == s)
        {
            f = 1;
            break;
        }
    }
    if (f = 1)
    {
        printf("\n%d is found on index no %d", s, i);
    }
    else
    {
        printf("\n!404 %d not found in Array", s);
    }
}
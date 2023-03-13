#include <stdio.h>
#include <string.h>
struct myStruct
{
    int num;
    char letter;
    char string[30];
};

void main()
{
    int i;
    struct myStruct s1[3];
    s1[0].num = 10;
    s1[0].letter = 'A';
    strcpy(s1[0].string, "Hello World");

    s1[1].num = 20;
    s1[1].letter = 'B';
    strcpy(s1[1].string, "Good Morning");

    s1[2].num = 30;
    s1[2].letter = 'c';
    strcpy(s1[2].string, "Good Bye World");
    for (i = 0; i < 3; i++)
    {
        printf("\n%d %c %s", s1[i].num, s1[i].letter, s1[i].string);
    }
}
#include <stdio.h>
struct weight
{
    int kg;
    int gm;
} ob1, ob2, res;

void main()
{
    printf("Enter weight of first object==>");
    scanf("%d %d", &ob1.kg, &ob1.gm);

    printf("Enter weight of Second object==>");
    scanf("%d %d", &ob2.kg, &ob2.gm);

    res.kg = ob1.kg + ob2.kg;
    res.gm = ob1.gm + ob2.gm;

    if (res.gm > 1000)
    {
        res.kg += 1;
        res.gm -= 1000;
    }
    printf("The Result is==> %d.%d", res.kg, res.gm);
}
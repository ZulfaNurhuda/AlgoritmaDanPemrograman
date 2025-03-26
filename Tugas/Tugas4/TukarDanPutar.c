#include <stdio.h>

void Tukar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Putar3Bil(int *a, int *b, int *c)
{
    Tukar(a, c); // Tukar a dan c
    Tukar(a, b); // Tukar a dan b
}

int main()
{
    int a = 1, b = 2, c = 3;
    Putar3Bil(&a, &b, &c);
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}
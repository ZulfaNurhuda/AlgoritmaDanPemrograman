#include <stdio.h>

int main()
{
    float v, jarak;
    int h;

    scanf("%f" , &v);
    scanf("%d" , &h);

    jarak = v * h;

    printf ("%.2f\n", jarak);

    return 0 ;
}
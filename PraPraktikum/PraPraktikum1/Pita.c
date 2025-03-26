#include <stdio.h>

int cariFPB(int bilangan_1, int bilangan_2)
{
    while (bilangan_2 != 0)
    {
        int temp = bilangan_2;
        bilangan_2 = bilangan_1 % bilangan_2;
        bilangan_1 = temp;
    }
    return bilangan_1;
}
int main()
{
    int Bilangan_1, Bilangan_2;
    scanf("%d", &Bilangan_1);
    scanf("%d", &Bilangan_2);
    
    int hasil = cariFPB(Bilangan_1, Bilangan_2);

    printf("%d\n", hasil);
    return 0;
}
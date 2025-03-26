#include <stdio.h>

int main()
{
    int n, rotasi;
    scanf("%d", &n);
    scanf("%d", &rotasi);

    int barisanNimons[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &barisanNimons[i]);
    }

    int barisanRotasi[rotasi];
    for (int i = 0; i < rotasi; i++)
    {
        scanf("%d", &barisanRotasi[i]);
    }

    int hasilRotasi[n];
    for (int i = 0; i < rotasi; i++)
    {
        int currentRotasi = barisanRotasi[i] % n;
        for (int j = 0; j < n; j++)
        {
            if (j + currentRotasi < n)
            {
                hasilRotasi[j + currentRotasi] = barisanNimons[j];
            }
            else
            {
                hasilRotasi[j + currentRotasi - n] = barisanNimons[j];
            }
        }

        printf("[");
        for (int j = 0; j < n; j++)
        {
            printf("%d", hasilRotasi[j]);
            if (j != (n - 1))
            {
                printf(", ");
            }
        }
        printf("]\n");
    }

    return 0;
}

#include <stdio.h>

int main()
{
    int n, target;
    scanf("%d %d", &n, &target);

    int berat[n];
    for (int i = n - 1; i >= 0; i--)
    {
        scanf("%d", &berat[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (berat[i] == target)
        {
            if (i == 0)
            {
                berat[i] = berat[i + 1];
            }
            else if (i == n - 1)
            {
                berat[i] = berat[i - 1];
            }
            else
            {
                berat[i] = berat[i - 1] + berat[i + 1];
            }

            int kiri = i + 1;
            int kanan = n - 1;
            while (kiri < kanan)
            {
                int temp = berat[kiri];
                berat[kiri] = berat[kanan];
                berat[kanan] = temp;
                kiri++;
                kanan--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", berat[i]);
        if (i < n - 1)
            printf(" ");
        else
            printf("\n");
    }

    return 0;
}
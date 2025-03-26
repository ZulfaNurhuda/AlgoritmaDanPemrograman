#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int tengah = (N + 1) / 2;
    for (int i = 1; i <= N; i++)
    {
        int min = (i - 1 < N - i) ? i - 1 : N - i;
        for (int j = 1; j <= N; j++)
        {
            int jangkauan = (j > tengah) ? j - tengah : tengah - j;
            if (jangkauan == min)
            {
                printf("*");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}
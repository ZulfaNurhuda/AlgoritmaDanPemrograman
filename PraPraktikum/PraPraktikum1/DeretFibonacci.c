#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    if (N >= 1) {
        printf("0");

        if (N >= 2) {
            printf(" 1");
            int bilangan_sebelumnya = 0;
            int bilangan_saat_ini = 1;

            for (int i = 2; i < N; i++)
            {
                int next = bilangan_sebelumnya + bilangan_saat_ini;
                printf(" %d", next);
                bilangan_sebelumnya = bilangan_saat_ini;
                bilangan_saat_ini = next;
            }
        }
    }

    printf("\n");
    return 0;
}
#include <stdio.h>

int main()
{
    int n, i, k;
    scanf("%d %d %d", &n, &i, &k);

    int nimons[1001] = {0};
    for (int j = 0; j < n; j++)
    {
        nimons[j] = j + 1;
    }

    int tersisa = n;
    int saatIni = i - 1;

    while (tersisa > 1)
    {
        int nilaiKeff = k % tersisa;
        if (nilaiKeff == 0)
            nilaiKeff = tersisa;

        int total = 0;
        int eliminasi = saatIni;
        while (total < nilaiKeff)
        {
            eliminasi = (eliminasi + 1) % n;
            if (nimons[eliminasi] != 0)
            {
                total++;
            }
        }

        nimons[eliminasi] = 0;
        tersisa--;
        saatIni = eliminasi;

        while (nimons[saatIni] == 0 && tersisa > 0)
        {
            saatIni = (saatIni + 1) % n;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (nimons[j] != 0)
        {
            printf("%d\n", nimons[j]);
            break;
        }
    }
    return 0;
}
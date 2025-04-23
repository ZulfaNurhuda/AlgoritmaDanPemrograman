#include <stdio.h>

int main()
{
    int n, t, luas;
    scanf("%d %d", &n, &t);

    for (int i = 0; i < t; i++)
    {
        luas = n + 9 * (i + 1);
        printf("tahun ke-%d = %d\n", i + 1, luas);
    }

    return 0;
}
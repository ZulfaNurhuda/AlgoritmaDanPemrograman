#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int count = 0;
    int i = 5;
    while (i <= N)
    {
        count += N / i;
        i *= 5;
    }
    printf("%d\n", count);
    return 0;
}
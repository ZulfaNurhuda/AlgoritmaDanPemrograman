#include <stdio.h>

int main()
{
    int N, T, x;
    scanf("%d", &N);
    scanf("%d", &T);
    scanf("%d", &x);

    long long total = N;
    long long previous = N;

    for (int i = 1; i <= T; i++)
    {
        long long current = previous * x;
        total += current;
        previous = current;
    }

    printf("Terdapat %lld Virus Nimons Gila pada jam ke-%d\n", total, T);

    return 0;
}

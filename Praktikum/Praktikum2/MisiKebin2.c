#include <stdio.h>

int totalDigit(int n)
{
    int total = 0;
    while (n > 0)
    {
        total += n % 10;
        n /= 10;
    }
    return total;
}

int isPrime(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int countPrime(int A, int B, int total)
{
    for (int i = A; i <= B; i++)
    {
        if (isPrime(i) && isPrime(totalDigit(i)))
        {
            total++;
        }
    }

    return total;
}

long long integerToBingro(int n)
{
    long long bingro = 0;

    while (n > 0)
    {
        bingro = bingro * 10 + n % 2;
        n /= 2;
    }

    return bingro;
}

int main()
{
    int A, B, total;
    long long bingro;

    scanf("%d %d", &A, &B);

    total = countPrime(A, B, total);
    bingro = integerToBingro(total);

    printf("%lld\n", bingro);

    return 0;
}
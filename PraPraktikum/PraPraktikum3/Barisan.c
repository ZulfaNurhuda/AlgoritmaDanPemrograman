#include <stdio.h>

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a / gcd(a, b)) * b;
}

int main()
{
    int N;
    scanf("%d", &N);
    long long A[1000];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }

    if (N == 0)
    {
        printf("0\n");
        return 0;
    }

    if (N == 1)
    {
        printf("%lld\n", A[0] * A[0]);
        return 0;
    }

    long long prefix_gcd[1000], suffix_gcd[1000];
    long long prefix_lcm[1000], suffix_lcm[1000];

    prefix_gcd[0] = A[0];
    prefix_lcm[0] = A[0];
    for (int i = 1; i < N; i++)
    {
        prefix_gcd[i] = gcd(prefix_gcd[i - 1], A[i]);
        prefix_lcm[i] = lcm(prefix_lcm[i - 1], A[i]);
    }

    suffix_gcd[N - 1] = A[N - 1];
    suffix_lcm[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        suffix_gcd[i] = gcd(suffix_gcd[i + 1], A[i]);
        suffix_lcm[i] = lcm(suffix_lcm[i + 1], A[i]);
    }

    long long max_score = prefix_gcd[N - 1] * prefix_lcm[N - 1];

    for (int i = 0; i < N; i++)
    {
        long long current_gcd, current_lcm;

        if (i == 0)
        {
            current_gcd = suffix_gcd[1];
            current_lcm = suffix_lcm[1];
        }
        else if (i == N - 1)
        {
            current_gcd = prefix_gcd[N - 2];
            current_lcm = prefix_lcm[N - 2];
        }
        else
        {
            current_gcd = gcd(prefix_gcd[i - 1], suffix_gcd[i + 1]);
            current_lcm = lcm(prefix_lcm[i - 1], suffix_lcm[i + 1]);
        }

        long long score = current_gcd * current_lcm;
        if (score > max_score)
            max_score = score;
    }

    printf("%lld\n", max_score);
    return 0;
}
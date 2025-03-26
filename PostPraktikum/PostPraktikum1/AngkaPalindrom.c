#include <stdio.h>

int main()
{
    int N, manpulated_N;
    scanf("%d", &N);

    manpulated_N = N;
    int reverse = 0;

    while (manpulated_N > 0)
    {
        int digit = manpulated_N % 10;
        reverse = reverse * 10 + digit;
        manpulated_N /= 10;
    }

    int palindrom = (N == reverse) ? 1 : 0;
    printf("%d\n", palindrom);

    return 0;
}

#include <stdio.h>
#include <string.h>

int isPalindrom(char *s, int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n < 2)
    {
        return 1;
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

void shift(char *s, int n)
{
    char temp = s[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        s[i] = s[i - 1];
    }
    s[0] = temp;
}

int main()
{
    char s[1001];

    scanf("%s", s);

    int n = strlen(s);

    if (isPalindrom(s, n))
    {
        printf("YES\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        shift(s, n);
        if (isPalindrom(s, n))
        {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
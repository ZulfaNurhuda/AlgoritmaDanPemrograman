#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void equalizeLength(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    bool isNeg1 = (num1[0] == '-');
    bool isNeg2 = (num2[0] == '-');

    int effLen1 = isNeg1 ? len1 - 1 : len1;
    int effLen2 = isNeg2 ? len2 - 1 : len2;

    int maxEffLen = (effLen1 > effLen2) ? effLen1 : effLen2;

    if (effLen1 < maxEffLen)
    {
        int shift = maxEffLen - effLen1;
        if (isNeg1)
        {

            for (int i = len1; i > 1; i--)
            {
                num1[i + shift - 1] = num1[i - 1];
            }

            for (int i = 1; i <= shift; i++)
            {
                num1[i] = '0';
            }
        }
        else
        {

            for (int i = len1; i >= 0; i--)
            {
                num1[i + shift] = num1[i];
            }

            for (int i = 0; i < shift; i++)
            {
                num1[i] = '0';
            }
        }
    }

    if (effLen2 < maxEffLen)
    {

        int shift = maxEffLen - effLen2;
        if (isNeg2)
        {

            for (int i = len2; i > 1; i--)
            {
                num2[i + shift - 1] = num2[i - 1];
            }

            for (int i = 1; i <= shift; i++)
            {
                num2[i] = '0';
            }
        }
        else
        {

            for (int i = len2; i >= 0; i--)
            {
                num2[i + shift] = num2[i];
            }

            for (int i = 0; i < shift; i++)
            {
                num2[i] = '0';
            }
        }
    }
}

void reverseStr(char *str)
{
    int n = strlen(str);
    int i;
    for (i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void removeLeadingZeros(char *str)
{
    int i = 0;

    if (str[0] == '-')
    {
        i = 1;
    }

    while (str[i] == '0' && str[i + 1] != '\0')
    {
        i++;
    }

    if (i > 0 && (str[0] != '-' || i > 1))
    {
        int j = 0;
        if (str[0] == '-')
        {
            j = 1;
            i--;

            while (str[i + j] != '\0')
            {
                str[j] = str[i + j];
                j++;
            }
            str[j] = '\0';
        }
        else
        {
            while (str[i + j] != '\0')
            {
                str[j] = str[i + j];
                j++;
            }
            str[j] = '\0';
        }
    }

    if (strcmp(str, "0") == 0 || strcmp(str, "-0") == 0)
    {
        str[0] = '0';
        str[1] = '\0';
    }
}

int compareAbs(const char *num1, const char *num2)
{

    if (num1[0] == '-')
        num1++;
    if (num2[0] == '-')
        num2++;

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;

    return strcmp(num1, num2);
}

char *addPositive(const char *num1, const char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int maxLen = (len1 > len2) ? len1 : len2;
    char *result = (char *)malloc((maxLen + 2) * sizeof(char));

    int carry = 0;
    int i = len1 - 1, j = len2 - 1, k = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += (num1[i--] - '0');
        if (j >= 0)
            sum += (num2[j--] - '0');

        result[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    result[k] = '\0';

    reverseStr(result);
    removeLeadingZeros(result);

    return result;
}

char *subtractPositive(const char *num1, const char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    char *result = (char *)malloc((len1 + 1) * sizeof(char));

    int borrow = 0;
    int i = len1 - 1, j = len2 - 1, k = 0;

    while (i >= 0)
    {
        int diff = (num1[i--] - '0') - borrow;
        if (j >= 0)
            diff -= (num2[j--] - '0');

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result[k++] = diff + '0';
    }

    result[k] = '\0';

    reverseStr(result);
    removeLeadingZeros(result);

    return result;
}

char *add(const char *num1, const char *num2)
{

    bool isNeg1 = (num1[0] == '-');
    bool isNeg2 = (num2[0] == '-');

    const char *absNum1 = isNeg1 ? num1 + 1 : num1;
    const char *absNum2 = isNeg2 ? num2 + 1 : num2;

    char *result;

    if (!isNeg1 && !isNeg2)
    {
        result = addPositive(absNum1, absNum2);
    }

    else if (isNeg1 && isNeg2)
    {
        result = addPositive(absNum1, absNum2);

        int len = strlen(result);
        for (int i = len; i >= 0; i--)
        {
            result[i + 1] = result[i];
        }
        result[0] = '-';
    }
    else
    {
        int cmp = compareAbs(absNum1, absNum2);

        const char *larger = (cmp >= 0) ? absNum1 : absNum2;
        const char *smaller = (cmp >= 0) ? absNum2 : absNum1;

        result = subtractPositive(larger, smaller);

        if ((cmp < 0 && isNeg2) || (cmp >= 0 && isNeg1))
        {

            if (strcmp(result, "0") != 0)
            {
                int len = strlen(result);
                for (int i = len; i >= 0; i--)
                {
                    result[i + 1] = result[i];
                }
                result[0] = '-';
            }
        }
    }

    return result;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    m = (m < 0) ? -m : m;
    n = (n < 0) ? -n : n;

    char number1[m + 2];
    char number2[n + 2];

    scanf("%s", number1);
    scanf("%s", number2);

    char *result = add(number1, number2);
    printf("%s\n", result);

    free(result);

    return 0;
}
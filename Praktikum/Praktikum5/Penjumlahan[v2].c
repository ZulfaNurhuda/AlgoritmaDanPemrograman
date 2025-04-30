#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListStatik.h"

void reverseList(ListStatik *num1)
{
    int n = num1->ukuran;

    for (int i = 0; i < n / 2; i++)
    {
        int temp = num1->data[i];
        num1->data[i] = num1->data[n - i - 1];
        num1->data[n - i - 1] = temp;
    }
}

void removeLeadingZeros(ListStatik *num)
{
    int leadingZeroCount = 0;
    bool foundNonZero = false;

    for (int i = 0; i < num->ukuran && !foundNonZero; ++i)
    {
        if (num->data[i] == 0)
        {
            ++leadingZeroCount;
        }
        else
        {
            foundNonZero = true;
        }
    }

    if (leadingZeroCount == num->ukuran)
    {
        num->ukuran = 1;
        num->data[0] = 0;
    }
    else if (leadingZeroCount > 0)
    {
        for (int i = 0; i < num->ukuran - leadingZeroCount; ++i)
        {
            num->data[i] = num->data[i + leadingZeroCount];
        }

        num->ukuran -= leadingZeroCount;
    }
}

int compareAbs(ListStatik *num1, ListStatik *num2)
{
    int len1 = num1->ukuran;
    int len2 = num2->ukuran;

    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;

    for (int i = 0; i < len1; i++)
    {
        if (num1->data[i] > num2->data[i])
        {
            return 1;
        }
        else if (num1->data[i] < num1->data[i])
        {
            return -1;
        }
    }

    return 1;
}

ListStatik *addPositive(ListStatik *num1, ListStatik *num2)
{
    int len1 = num1->ukuran;
    int len2 = num2->ukuran;
    int maxLen = (len1 > len2) ? len1 : len2;

    ListStatik *result = (ListStatik *)malloc(sizeof(ListStatik));
    if (result == NULL)
    {
        return NULL;
    }

    inisialisasiList(result, maxLen + 2);
    if (result->data == NULL)
    {
        free(result);
        return NULL;
    }

    int carry = 0;
    int i = len1 - 1, j = len2 - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += num1->data[i--];
        if (j >= 0)
            sum += num2->data[j--];

        result->data[result->ukuran++] = (sum % 10);
        carry = sum / 10;
    }

    reverseList(result);
    removeLeadingZeros(result);

    return result;
}

ListStatik *subtractPositive(ListStatik *num1, ListStatik *num2)
{
    int len1 = num1->ukuran;
    int len2 = num2->ukuran;
    int maxLen = (len1 > len2) ? len1 : len2;

    ListStatik *result = (ListStatik *)malloc(sizeof(ListStatik));
    if (result == NULL)
    {
        return NULL;
    }

    inisialisasiList(result, maxLen + 2);
    if (result->data == NULL)
    {
        free(result);
        return NULL;
    }

    int borrow = 0;
    int i = len1 - 1, j = len2 - 1;

    while (i >= 0)
    {
        int diff = num1->data[i--] - borrow;
        if (j >= 0)
            diff -= num2->data[j--];

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result->data[result->ukuran++] = diff;
    }

    reverseList(result);
    removeLeadingZeros(result);

    return result;
}

ListStatik *add(bool isNeg1, bool isNeg2, ListStatik *num1, ListStatik *num2)
{
    ListStatik *result;

    if (!isNeg1 && !isNeg2)
    {
        result = addPositive(num1, num2);
        if (result == NULL)
        {
            return NULL;
        }
    }
    else if (isNeg1 && isNeg2)
    {
        result = addPositive(num1, num2);
        if (result == NULL)
        {
            return NULL;
        }

        result->data[0] = -1 * result->data[0];
    }
    else
    {
        int cmp = compareAbs(num1, num2);

        ListStatik *larger = (cmp >= 0) ? num1 : num2;
        ListStatik *smaller = (cmp >= 0) ? num2 : num1;

        result = subtractPositive(larger, smaller);
        if (result == NULL)
        {
            return NULL;
        }

        if ((cmp < 0 && isNeg2) || (cmp >= 0 && isNeg1))
        {
            result->data[0] = -1 * result->data[0];
        }
    }

    return result;
}

void stringToList(const char *str, ListStatik *list)
{
    int len = strlen(str);

    list->ukuran = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] != '-')
        {
            tambahElemen(list, str[i] - '0');
        }
    }
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

    ListStatik num1, num2;
    inisialisasiList(&num1, m + 2);
    if (num1.data == NULL)
    {
        return 1;
    }

    inisialisasiList(&num2, n + 2);
    if (num2.data == NULL)
    {
        free(num1.data);
        return 1;
    }

    stringToList(number1, &num1);
    stringToList(number2, &num2);

    bool isNeg1 = (number1[0] == '-');
    bool isNeg2 = (number2[0] == '-');

    ListStatik *result = add(isNeg1, isNeg2, &num1, &num2);
    if (result == NULL)
    {
        free(num1.data);
        free(num2.data);
        return 1;
    }

    tampilkanList(*result);

    free(result->data);
    free(result);
    free(num1.data);
    free(num2.data);

    return 0;
}
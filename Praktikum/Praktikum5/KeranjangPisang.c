#include <stdio.h>
#include "keranjangpisang.h"

void CreateKeranjang(KeranjangPisang *k)
{
    for (IdxType i = IDX_MIN; i < CAPACITY; i++)
    {
        ELMT(*k, i) = MARK;
    }
}

int lengthKeranjang(KeranjangPisang k)
{
    int count = 0;
    for (IdxType i = IDX_MIN; i < CAPACITY; i++)
    {
        if (ELMT(k, i) != MARK)
        {
            count++;
        }
    }
    return count;
}

IdxType getFirstIdx(KeranjangPisang k)
{
    IdxType i = IDX_MIN;
    while (i < CAPACITY && ELMT(k, i) == MARK)
    {
        i++;
    }

    if (ELMT(k, i) == MARK)
    {
        i = IDX_UNDEF;
    }

    return i;
}

IdxType getLastIdx(KeranjangPisang k)
{
    IdxType i = CAPACITY - 1;
    while (i >= IDX_MIN && ELMT(k, i) == MARK)
    {
        i--;
    }

    if (ELMT(k, i) == MARK)
    {
        i = IDX_UNDEF;
    }

    return i;
}

boolean isIdxValid(KeranjangPisang k, IdxType i)
{
    return (i >= IDX_MIN && i < CAPACITY);
}

boolean isIdxEff(KeranjangPisang k, IdxType i)
{
    return (isIdxValid(k, i) && ELMT(k, i) != MARK);
}

boolean isEmpty(KeranjangPisang k)
{
    return (lengthKeranjang(k) == 0);
}

boolean isFull(KeranjangPisang k)
{
    return (lengthKeranjang(k) == CAPACITY);
}

void readKeranjang(KeranjangPisang *k)
{
    CreateKeranjang(k);

    int n;
    scanf("%d", &n);

    if (n > CAPACITY)
    {
        n = CAPACITY;
    }

    for (IdxType i = IDX_MIN; i < n; i++)
    {
        scanf("%d", &ELMT(*k, i));
    }
}

void printKeranjang(KeranjangPisang k)
{
    int length = lengthKeranjang(k);
    printf("[");
    for (IdxType i = IDX_MIN; i < length; i++)
    {
        printf("%d", ELMT(k, i));
        if (i < length - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

void insertFirst(KeranjangPisang *k, ElType val)
{
    int length = lengthKeranjang(*k);

    if (!isFull(*k))
    {
        for (IdxType i = length; i > IDX_MIN; i--)
        {
            ELMT(*k, i) = ELMT(*k, i - 1);
        }
        ELMT(*k, IDX_MIN) = val;
    }
}

void insertAt(KeranjangPisang *k, ElType val, IdxType idx)
{
    int length = lengthKeranjang(*k);

    if (!isFull(*k) && isIdxValid(*k, idx))
    {
        for (IdxType i = length; i > idx; i--)
        {
            ELMT(*k, i) = ELMT(*k, i - 1);
        }
        ELMT(*k, idx) = val;
    }
}

void insertLast(KeranjangPisang *k, ElType val)
{
    int length = lengthKeranjang(*k);

    if (!isFull(*k))
    {
        ELMT(*k, length) = val;
    }
}

void deleteFirst(KeranjangPisang *k, ElType *val)
{
    int length = lengthKeranjang(*k);

    if (!isEmpty(*k))
    {
        *val = ELMT(*k, IDX_MIN);

        for (IdxType i = IDX_MIN; i < length - 1; i++)
        {
            ELMT(*k, i) = ELMT(*k, i + 1);
        }
        ELMT(*k, length - 1) = MARK;
    }
}

void deleteAt(KeranjangPisang *k, ElType *val, IdxType idx)
{
    int length = lengthKeranjang(*k);

    if (!isEmpty(*k) && isIdxEff(*k, idx))
    {
        *val = ELMT(*k, idx);

        for (IdxType i = idx; i < length - 1; i++)
        {
            ELMT(*k, i) = ELMT(*k, i + 1);
        }
        ELMT(*k, length - 1) = MARK;
    }
}

void deleteLast(KeranjangPisang *k, ElType *val)
{
    int length = lengthKeranjang(*k);

    if (!isEmpty(*k))
    {
        *val = ELMT(*k, length - 1);
        ELMT(*k, length - 1) = MARK;
    }
}

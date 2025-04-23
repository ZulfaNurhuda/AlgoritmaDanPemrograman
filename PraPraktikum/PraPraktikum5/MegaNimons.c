#include <stdio.h>
#include "MegaNimons.h"

void createLabTrack(LabTrack *L)
{
    L->nEff = 0;
}

int length(LabTrack L)
{
    return L.nEff;
}

int maxCapacity()
{
    return CAPACITY;
}

IdxType firstIdx(LabTrack L)
{
    return 0;
}

IdxType lastIdx(LabTrack L)
{
    return L.nEff - 1;
}

MegaNimons getElmt(LabTrack L, IdxType i)
{
    return L.contents[i];
}

void setElmt(LabTrack *L, IdxType i, MegaNimons val)
{
    if (isIdxValid(i))
    {
        L->contents[i] = val;
        if (!isIdxEff(*L, i))
        {
            setLength(L, i);
        }
    }
}

void setLength(LabTrack *L, int N)
{
    if (isIdxValid(N))
    {
        L->nEff = N;
    }
}

boolean isIdxValid(IdxType i)
{
    return (i >= 0 && i < CAPACITY);
}

boolean isIdxEff(LabTrack L, IdxType i)
{
    return (i >= 0 && i < L.nEff);
}

boolean isEmpty(LabTrack L)
{
    return (L.nEff == 0);
}

boolean isFull(LabTrack L)
{
    return (L.nEff == CAPACITY);
}

void insertAt(LabTrack *L, MegaNimons m, IdxType idx)
{
    if (isIdxValid(idx) && !isFull(*L))
    {
        for (IdxType i = L->nEff; i > idx; i--)
        {
            L->contents[i] = L->contents[i - 1];
        }

        L->contents[idx] = m;

        /**
         * @note BAGIAN INI TIDAK ADA DI BRIEF FILE HEADER
         * 
         * Ini Anstisipasi tambahan yang dilakukan untuk menghindari
         * terjadinya error saat menambahkan elemen diluar index efektif.
         */
        if (isIdxEff(*L, idx))
        {
            L->nEff++;
        }
        else
        {
            setLength(L, idx + 1);
        }
    }
}

void insertFirst(LabTrack *L, MegaNimons m)
{
    insertAt(L, m, 0);
}

void insertLast(LabTrack *L, MegaNimons m)
{
    insertAt(L, m, L->nEff);
}

void deleteAt(LabTrack *L, IdxType idx, MegaNimons *m)
{
    if (isIdxEff(*L, idx) && !isEmpty(*L))
    {
        *m = L->contents[idx];
        for (IdxType i = idx; i < L->nEff - 1; i++)
        {
            L->contents[i] = L->contents[i + 1];
        }
        L->nEff--;
    }
}

void deleteFirst(LabTrack *L, MegaNimons *m)
{
    deleteAt(L, 0, m);
}

void deleteLast(LabTrack *L, MegaNimons *m)
{
    deleteAt(L, L->nEff - 1, m);
}

IdxType indexOf(LabTrack L, int id)
{
    for (IdxType i = 0; i < L.nEff; i++)
    {
        if (L.contents[i].id == id)
        {
            return i;
        }
    }
    return IDX_UNDEF;
}

void printLabTrack(LabTrack L)
{
    for (IdxType i = 0; i < L.nEff; i++)
    {
        printf("[%d] ID=%d NAME=%s POWER=%.1f MUT=%s STABLE=%s\n", i, L.contents[i].id, L.contents[i].name, L.contents[i].powerLevel, L.contents[i].mutationType, L.contents[i].isStable ? "Yes" : "No");
    }
}

void ejectUnstable(LabTrack *L)
{
    IdxType i = 0;
    while (i < L->nEff)
    {
        if (L->contents[i].isStable == FALSE)
        {
            MegaNimons m;
            deleteAt(L, i, &m);
            printf("EJECTED: %s\n", m.name);
        }
        else
        {
            i++;
        }
    }
}

void filterByPower(LabTrack L, float minPower)
{
    IdxType idx = 0;
    for (IdxType i = 0; i < L.nEff; i++)
    {
        if (L.contents[i].powerLevel >= minPower)
        {
            printf("[%d] ID=%d NAME=%s POWER=%.1f MUT=%s STABLE=%s\n", idx, L.contents[i].id, L.contents[i].name, L.contents[i].powerLevel, L.contents[i].mutationType, L.contents[i].isStable ? "Yes" : "No");
            idx++;
        }
    }
}
#include <stdio.h>
#include "NimonsBaris.h"

void MakeEmpty(BarisanNimons *T)
{
    T->Neff = 0;
}

int NbElmt(BarisanNimons T)
{
    return T.Neff;
}

int MaxNbEl(BarisanNimons T)
{
    return (IdxMax - IdxMin + 1);
}

IdxType GetFirstIdx(BarisanNimons T)
{
    return IdxMin;
}

IdxType GetLastIdx(BarisanNimons T)
{
    return T.Neff;
}

ElType GetElmt(BarisanNimons T, IdxType i)
{
    return T.baris[i];
}

void SetTab(BarisanNimons Tin, BarisanNimons *Tout)
{
    Tout->Neff = Tin.Neff;
    for (int i = IdxMin; i < Tin.Neff + IdxMin; i++)
    {
        Tout->baris[i] = Tin.baris[i];
    }
}

void SetEl(BarisanNimons *T, IdxType i, ElType v)
{

    if (IsIdxValid(*T, i))
    {
        T->baris[i] = v;

        /**
         * @note BAGIAN INI TIDAK ADA DI BRIEF FILE HEADER
         *
         * Ini Anstisipasi tambahan yang dilakukan untuk menghindari
         * terjadinya error saat menambahkan elemen diluar index efektif.
         */
        if (!IsIdxEff(*T, i)) {
            SetNeff(T, i);
        }
    }
}

void SetNeff(BarisanNimons *T, IdxType N)
{
    if (N >= 0 && N <= MaxNbEl(*T))
    {
        T->Neff = N;
    }
}

boolean IsIdxValid(BarisanNimons T, IdxType i)
{
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff(BarisanNimons T, IdxType i)
{
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

boolean IsEmpty(BarisanNimons T)
{
    return (T.Neff == 0);
}

boolean IsFull(BarisanNimons T)
{
    return (T.Neff == MaxNbEl(T));
}

void TulisIsi(BarisanNimons T)
{
    if (IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        for (int i = IdxMin; i < T.Neff + IdxMin; i++)
        {
            printf("%d:%d\n", i - 1, T.baris[i]);
        }
    }
}

BarisanNimons PlusTab(BarisanNimons T1, BarisanNimons T2)
{
    BarisanNimons T3;
    T3.Neff = T1.Neff;
    for (int i = IdxMin; i < T1.Neff + IdxMin; i++)
    {
        T3.baris[i] = T1.baris[i] + T2.baris[i];
    }
    return T3;
}

BarisanNimons MinusTab(BarisanNimons T1, BarisanNimons T2)
{
    BarisanNimons T3;
    T3.Neff = T1.Neff;
    for (int i = IdxMin; i < T1.Neff + IdxMin; i++)
    {
        T3.baris[i] = T1.baris[i] - T2.baris[i];
    }
    return T3;
}

ElType ValMax(BarisanNimons T)
{
    ElType max = T.baris[IdxMin];
    for (int i = IdxMin + 1; i < T.Neff + IdxMin; i++)
    {
        if (T.baris[i] > max)
        {
            max = T.baris[i];
        }
    }
    return max;
}

ElType ValMin(BarisanNimons T)
{
    ElType min = T.baris[IdxMin];
    for (int i = IdxMin + 1; i < T.Neff + IdxMin; i++)
    {
        if (T.baris[i] < min)
        {
            min = T.baris[i];
        }
    }
    return min;
}

IdxType IdxMaxTab(BarisanNimons T)
{
    int imax = IdxMin;
    for (int i = IdxMin + 1; i < T.Neff + IdxMin; i++)
    {
        if (T.baris[i] > T.baris[imax])
        {
            imax = i;
        }
    }
    return imax;
}

IdxType IdxMinTab(BarisanNimons T)
{
    int imin = IdxMin;
    for (int i = IdxMin + 1; i < T.Neff + IdxMin; i++)
    {
        if (T.baris[i] < T.baris[imin])
        {
            imin = i;
        }
    }
    return imin;
}
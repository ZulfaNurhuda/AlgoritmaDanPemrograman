#include "listlinier.h"

boolean IsEmpty(List L)
{
    return First(L) == Nil;
}

void CreateEmpty(List *L)
{
    First(*L) = Nil;
}

address Alokasi(infotype X)
{
    address P = (address)malloc(sizeof(ElmtList));
    if (P != NULL)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P)
{
    free(*P);
    *P = Nil;
}

address Search(List L, infotype X)
{
    address P = First(L);
    while (P != Nil && Info(P) != X)
    {
        P = Next(P);
    }
    return P;
}

void InsVFirst(List *L, infotype X)
{
    address P = Alokasi(X);
    if (P != NULL)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast(List *L, infotype X)
{
    address P = Alokasi(X);
    if (P != NULL)
    {
        if (IsEmpty(*L))
        {
            First(*L) = P;
        }
        else
        {
            address Q = First(*L);
            while (Next(Q) != Nil)
            {
                Q = Next(Q);
            }
            Next(Q) = P;
        }
    }
}

void DelVFirst(List *L, infotype *X)
{
    address P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
{
    address prev = Nil;
    address current = First(*L);

    while (Next(current) != Nil)
    {
        prev = current;
        current = Next(current);
    }

    (*X) = Info(current);

    if (prev != Nil)
    {
        Next(prev) = Nil;
    }
    else
    {
        First(*L) = Nil;
    }

    Dealokasi(&current);
}

void InsertFirst(List *L, address P)
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(address P, address Prec)
{
    if (Prec != Nil)
    {
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

void InsertLast(List *L, address P)
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
    }
    else
    {
        address Q = First(*L);
        while (Next(Q) != Nil)
        {
            Q = Next(Q);
        }
        Next(Q) = P;
    }
}

void DelFirst(List *L, address *P)
{
    (*P) = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelP(List *L, infotype X)
{
    address prev = Nil;
    address current = First(*L);

    while (current != Nil && Info(current) != X)
    {
        prev = current;
        current = Next(current);
    }

    if (current != Nil)
    {
        if (prev != Nil)
        {
            Next(prev) = Next(current);
        }
        else
        {
            First(*L) = Next(current);
        }
        Dealokasi(&current);
    }
}

void DelLast(List *L, address *P)
{
    address prev = Nil;
    address current = First(*L);

    while (Next(current) != Nil)
    {
        prev = current;
        current = Next(current);
    }

    (*P) = current;

    if (prev != Nil)
    {
        Next(prev) = Nil;
    }
    else
    {
        First(*L) = Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec)
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

void PrintInfo(List L)
{
    address P = First(L);

    printf("[");
    while (P != Nil)
    {
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil)
        {
            printf(",");
        }
    }
    printf("]\n");
}

int NbElmt(List L)
{
    int NbElmt = 0;
    address P = First(L);
    while (P != Nil)
    {
        NbElmt++;
        P = Next(P);
    }
    return NbElmt;
}

infotype Max(List L)
{
    address P = First(L);
    infotype Max = Info(P);
    while (P != Nil)
    {
        if (Info(P) > Max)
        {
            Max = Info(P);
        }
        P = Next(P);
    }
    return Max;
}

address AdrMax(List L)
{
    address P = First(L);
    infotype Max = Info(P);
    address AdrMax = P;
    while (P != Nil)
    {
        if (Info(P) > Max)
        {
            Max = Info(P);
            AdrMax = P;
        }
        P = Next(P);
    }
    return AdrMax;
}

infotype Min(List L)
{
    address P = First(L);
    infotype Min = Info(P);
    while (P != Nil)
    {
        if (Info(P) < Min)
        {
            Min = Info(P);
        }
        P = Next(P);
    }
    return Min;
}

address AdrMin(List L)
{
    address P = First(L);
    infotype Min = Info(P);
    address AdrMin = P;
    while (P != Nil)
    {
        if (Info(P) < Min)
        {
            Min = Info(P);
            AdrMin = P;
        }
        P = Next(P);
    }
    return AdrMin;
}

float Average(List L)
{
    float avg = 0.0;

    if (!IsEmpty(L))
    {
        float total = 0.0;
        int count = 0;
        address P = First(L);
        while (P != Nil)
        {
            total += Info(P);
            count++;
            P = Next(P);
        }
        avg = total / count;
    }

    return avg;
}

void InversList(List *L)
{
    address current = First(*L);
    address prev = Nil;
    address next = Nil;

    while (current != Nil)
    {
        next = Next(current);
        Next(current) = prev;
        prev = current;
        current = next;
    }

    First(*L) = prev;
}

void Konkat1(List *L1, List *L2, List *L3)
{
    First(*L3) = First(*L1);
    address P = First(*L1);
    while (Next(P) != Nil)
    {
        P = Next(P);
    }
    Next(P) = First(*L2);

    CreateEmpty(L1);
    CreateEmpty(L2);
}

void SortListAsc(List *L)
{
    if (!IsEmpty(*L))
    {
        boolean swapped;
        address ptr1;
        address lptr = Nil;

        do
        {
            swapped = false;
            ptr1 = First(*L);

            while (Next(ptr1) != lptr)
            {
                if (Info(ptr1) > Info(Next(ptr1)))
                {
                    infotype temp = Info(ptr1);
                    Info(ptr1) = Info(Next(ptr1));
                    Info(Next(ptr1)) = temp;
                    swapped = true;
                }
                ptr1 = Next(ptr1);
            }
            lptr = ptr1;
        } while (swapped);
    }
}

void RemoveDuplicate(List *L)
{
    if (!IsEmpty(*L))
    {
        address current = First(*L);
        while (current != Nil)
        {
            address runner = current;
            while (Next(runner) != Nil)
            {
                if (Info(Next(runner)) == Info(current))
                {
                    address temp = Next(runner);
                    Next(runner) = Next(temp);
                    Dealokasi(&temp);
                }
                else
                {
                    runner = Next(runner);
                }
            }
            current = Next(current);
        }
    }
}
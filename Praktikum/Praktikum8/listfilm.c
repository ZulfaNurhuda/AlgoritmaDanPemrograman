#include "listfilm.h"

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

void InsertAfter(List *L, address P, address Prec)
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

void RemoveGenre(List *L, infotype X)
{
    if (!IsEmpty(*L))
    {
        int count = 0;

        address prev = Nil;
        address current = First(*L);

        while (current != Nil)
        {
            if (Info(current) == X)
            {
                if (prev != Nil)
                {

                    Next(prev) = Next(current);
                }
                else
                {

                    First(*L) = Next(current);
                }

                address temp = current;
                current = Next(current);
                Dealokasi(&temp);
                count++;
            }
            else
            {

                prev = current;
                current = Next(current);
            }
        }

        if (count > 0)
        {
            printf("Berhasil menghapus %d film\n", count);
        }
        else
        {
            printf("Tidak ada film yang memiliki genre dengan ID: %d\n", X);
        }
    }
    else
    {
        printf("Tidak ada film yang memiliki genre dengan ID: %d\n", X);
    }
}

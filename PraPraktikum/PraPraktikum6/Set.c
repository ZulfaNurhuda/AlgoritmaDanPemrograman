#include "Set.h" // OR: #include "set.h"

void CreateEmpty(Set *S)
{
    S->Count = Nil;
}

boolean IsEmpty(Set S)
{
    return (S.Count == Nil);
}

boolean IsFull(Set S)
{
    return (S.Count == MaxEl);
}

void Insert(Set *S, int Elmt)
{
    if (!IsFull(*S))
    {
        int i = 0;
        while (i < S->Count && S->Elements[i] < Elmt)
        {
            i++;
        }
        if (S->Elements[i] != Elmt)
        {
            for (int j = S->Count; j > i; j--)
            {
                S->Elements[j] = S->Elements[j - 1];
            }
            S->Elements[i] = Elmt;
            S->Count++;
        }
    }
}

void Delete(Set *S, int Elmt)
{
    if (!IsEmpty(*S))
    {
        int i = 0;
        while (i < S->Count && S->Elements[i] < Elmt)
        {
            i++;
        }
        if (S->Elements[i] == Elmt)
        {
            for (int j = i; j < S->Count - 1; j++)
            {
                S->Elements[j] = S->Elements[j + 1];
            }
            S->Count--;
        }
    }
}

boolean IsMember(Set S, int Elmt)
{
    boolean member = false;
    int i = 0;
    while (i < S.Count && !member)
    {
        if (S.Elements[i] == Elmt)
        {
            member = true;
        }
        else
        {
            i++;
        }
    }
    return member;
}
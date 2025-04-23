#include <stdio.h>
#include <string.h>
#include "listnimons.h"

void CreateListNimons(ListNimons *l)
{
    for (int i = 0; i < NIMONS_CAPACITY; i++)
    {
        strcpy(l->contents[i].name, "");
        l->contents[i].age = -1;
        l->contents[i].height = -1;
    }
}

int listNimonsLength(ListNimons l)
{
    int nEff = 0;
    for (int i = 0; i < NIMONS_CAPACITY; i++)
    {
        if (l.contents[i].age != -1 && l.contents[i].height != -1 && strcmp(l.contents[i].name, "") != 0)
        {
            nEff++;
        }
    }
    return nEff;
}

boolean isIdxValidNimons(ListNimons l, int i)
{
    return (i >= IDX_MIN && i < NIMONS_CAPACITY);
}

boolean isIdxEffNimons(ListNimons l, int i)
{
    return (i >= IDX_MIN && i < listNimonsLength(l));
}

boolean isNimonsEmpty(ListNimons l)
{
    return (listNimonsLength(l) == 0);
}

boolean isNimonsFull(ListNimons l)
{
    return (listNimonsLength(l) >= NIMONS_CAPACITY);
}

void readNimonsList(ListNimons *l)
{
    int n;
    CreateListNimons(l);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", l->contents[i].name, &l->contents[i].age, &l->contents[i].height);
    }
}

void printNimonsList(ListNimons l)
{
    int length = listNimonsLength(l);
    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf("%s-%d-%d", l.contents[i].name, l.contents[i].age, l.contents[i].height);
        if (i < length - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void insertNimonsLast(ListNimons *l, Nimons m)
{
    if (!isNimonsFull(*l))
    {
        int idx = listNimonsLength(*l);
        l->contents[idx] = m;
    }
}

void deleteNimonsLast(ListNimons *l, Nimons *m)
{
    if (!isNimonsEmpty(*l))
    {
        int idx = listNimonsLength(*l) - 1;
        *m = l->contents[idx];
        l->contents[idx].age = -1;
        l->contents[idx].height = -1;
        strcpy(l->contents[idx].name, "");
    }
}

int indexOfNimons(ListNimons l, char *name)
{
    for (int i = 0; i < listNimonsLength(l); i++)
    {
        if (strcmp(l.contents[i].name, name) == 0)
        {
            return i;
        }
    }
    return IDX_UNDEF;
}

void findTallestShortest(ListNimons l, Nimons *tallest, Nimons *shortest)
{
    if (!isNimonsEmpty(l))
    {
        int tallestIdx = 0;
        int shortestIdx = 0;

        for (int i = 1; i < listNimonsLength(l); i++)
        {
            if (l.contents[i].height > l.contents[tallestIdx].height)
            {
                tallestIdx = i;
            }
            if (l.contents[i].height < l.contents[shortestIdx].height)
            {
                shortestIdx = i;
            }
        }

        *tallest = l.contents[tallestIdx];
        *shortest = l.contents[shortestIdx];
    }
}
#include "ListStatik.h"
#include <stdlib.h>

void inisialisasiList(ListStatik *list, int capacity)
{
    list->data = (int *)malloc(capacity * sizeof(int));
    list->kapasitas = capacity;
    list->ukuran = 0;
}

bool tambahElemen(ListStatik *list, int nilai)
{
    if (list->ukuran < list->kapasitas)
    {
        list->data[list->ukuran] = nilai;
        list->ukuran++;
        return true;
    }
    else
    {
        return false;
    }
}

bool hapusElemenAkhir(ListStatik *list)
{
    if (list->ukuran > 0)
    {
        list->ukuran--;
        return true;
    }
    else
    {
        return false;
    }
}

void tampilkanList(ListStatik list)
{
    if (list.ukuran == 0)
    {
        printf("List kosong\n");
    }
    else
    {
        for (int i = 0; i < list.ukuran; i++)
        {
            printf("%d", list.data[i]);
        }
        printf("\n");
    }
}

int cariElemen(ListStatik list, int nilai)
{
    int indeks = -1;
    for (int i = 0; i < list.ukuran && indeks == -1; i++)
    {
        if (list.data[i] == nilai)
        {
            indeks = i;
        }
    }
    return indeks;
}

bool ubahElemen(ListStatik *list, int index, int nilaiBaru)
{
    if (index >= 0 && index < list->ukuran)
    {
        list->data[index] = nilaiBaru;
        return true;
    }
    else
    {
        return false;
    }
}
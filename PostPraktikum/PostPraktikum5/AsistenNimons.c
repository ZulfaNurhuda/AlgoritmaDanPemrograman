#include "AsistenNimons.h"

void MakeEmpty(ListNilaiNimons *L)
{
    L->Neff = 0;
}

int NbElmt(ListNilaiNimons L)
{
    return L.Neff;
}

int MaxNbEl(ListNilaiNimons L)
{
    return MAX_CAPACITY;
}

IdxType GetFirstIdx(ListNilaiNimons L)
{
    return 0;
}

IdxType GetLastIdx(ListNilaiNimons L)
{
    return L.Neff - 1;
}

ElType GetElmt(ListNilaiNimons L, IdxType i)
{
    return L.daftar[i];
}

void SetTab(ListNilaiNimons Lin, ListNilaiNimons *Lout)
{
    Lout->Neff = Lin.Neff;
    for (int i = 0; i < Lin.Neff; i++)
    {
        Lout->daftar[i] = Lin.daftar[i];
    }
}

void SetEl(ListNilaiNimons *L, IdxType i, ElType v)
{
    L->daftar[i] = v;
    if (L->Neff < i + 1)
    {
        L->Neff = i + 1;
    }
}

void SetNeff(ListNilaiNimons *L, IdxType N)
{
    L->Neff = N;
}

boolean IsIdxValid(ListNilaiNimons L, IdxType i)
{
    return (i >= GetFirstIdx(L) && i < MAX_CAPACITY);
}

boolean IsIdxEff(ListNilaiNimons L, IdxType i)
{
    return (i >= GetFirstIdx(L) && i <= GetLastIdx(L));
}

boolean IsEmpty(ListNilaiNimons L)
{
    return (L.Neff == 0);
}

boolean IsFull(ListNilaiNimons L)
{
    return (L.Neff == MAX_CAPACITY);
}

void PrintIsi(ListNilaiNimons L)
{
    if (IsEmpty(L))
    {
        printf("List kosong\n");
    }
    else
    {
        for (IdxType i = 0; i < L.Neff; i++)
        {
            printf("%s - %d - %d\n", L.daftar[i].nama, L.daftar[i].praktikum, L.daftar[i].nilai);
        }
    }
}

ElType MakeNilai(char *nama, int prakke, int nilai)
{
    ElType NilaiNimons;

    strcpy(NilaiNimons.nama, nama);
    NilaiNimons.praktikum = prakke;
    NilaiNimons.nilai = nilai;

    return NilaiNimons;
}

float AvgNilaiNama(ListNilaiNimons L, char *nama)
{
    int total = 0;
    int count = 0;

    for (int i = 0; i < L.Neff; i++)
    {
        if (strcmp(L.daftar[i].nama, nama) == 0)
        {
            total += L.daftar[i].nilai;
            count++;
        }
    }

    float avg;
    if (count == 0)
    {
        avg = (float)0;
    }
    else
    {
        avg = (float)total / count;
    }

    return avg;
}

int MaxNilaiNama(ListNilaiNimons L, char *nama)
{
    int max = -1;
    for (int i = 0; i < L.Neff; i++)
    {
        if (strcmp(L.daftar[i].nama, nama) == 0 && L.daftar[i].nilai > max)
        {
            max = L.daftar[i].nilai;
        }
    }
    return max;
}

int MinNilaiNama(ListNilaiNimons L, char *nama)
{
    int min = 101;
    for (int i = 0; i < L.Neff; i++)
    {
        if (strcmp(L.daftar[i].nama, nama) == 0 && L.daftar[i].nilai < min)
        {
            min = L.daftar[i].nilai;
        }
    }
    return min;
}

float AvgNilai(ListNilaiNimons L)
{
    int total = 0;

    for (int i = 0; i < L.Neff; i++)
    {
        total += L.daftar[i].nilai;
    }

    float avg;
    if (L.Neff == 0)
    {
        avg = (float)0;
    }
    else
    {
        avg = (float)total / L.Neff;
    }

    return avg;
}

int MaxNilai(ListNilaiNimons L)
{
    int max = -1;
    for (int i = 0; i < L.Neff; i++)
    {
        if (L.daftar[i].nilai > max)
        {
            max = L.daftar[i].nilai;
        }
    }
    return max;
}

int MinNilai(ListNilaiNimons L)
{
    int min = 101;
    for (int i = 0; i < L.Neff; i++)
    {
        if (L.daftar[i].nilai < min)
        {
            min = L.daftar[i].nilai;
        }
    }
    return min;
}

int CountTotalPraktikum(ListNilaiNimons L)
{
    int list_temp[MAX_CAPACITY] = {0};
    int count = 0;

    for (int i = 0; i < L.Neff; i++)
    {
        if (list_temp[L.daftar[i].praktikum - 1] == 0)
        {
            list_temp[L.daftar[i].praktikum - 1] = 1;
            count++;
        }
    }

    return count;
}

void DisplayStatistic(ListNilaiNimons L)
{
    int total_praktikum = CountTotalPraktikum(L);
    float avg_nilai = AvgNilai(L);
    int max_nilai = MaxNilai(L);
    int min_nilai = MinNilai(L);

    printf("- Total praktikum: %d\n", total_praktikum);
    printf("- Rata-rata: %.2f\n", avg_nilai);
    printf("- Nilai maksimum: %d\n", max_nilai);
    printf("- Nilai minimum: %d\n", min_nilai);
}

void DisplayStatisticNimons(ListNilaiNimons L, char *nama)
{
    printf("Nama: %s\n", nama);

    for (IdxType i = 0; i < L.Neff; i++)
    {
        if (strcmp(L.daftar[i].nama, nama) == 0)
        {
            printf("Praktikum %d: %d\n", L.daftar[i].praktikum, L.daftar[i].nilai);
        }
    }

    printf("\n");

    float avg_nilai = AvgNilaiNama(L, nama);
    int max_nilai = MaxNilaiNama(L, nama);
    int min_nilai = MinNilaiNama(L, nama);

    printf("Rata-rata: %.2f\n", avg_nilai);
    printf("Nilai maksimum: %d\n", max_nilai);
    printf("Nilai minimum: %d\n", min_nilai);

    int avg_floor = (int)avg_nilai;
    char indexNilai = KonversiNilai(avg_nilai);
    printf("Nilai akhir: %c\n", indexNilai);
}

char KonversiNilai(int nilai)
{
    char indexNilai;

    if (nilai >= 80)
    {
        indexNilai = 'A';
    }
    else if (nilai >= 65)
    {
        indexNilai = 'B';
    }
    else if (nilai >= 50)
    {
        indexNilai = 'C';
    }
    else if (nilai >= 35)
    {
        indexNilai = 'D';
    }
    else if (nilai >= 0)
    {
        indexNilai = 'E';
    }
    else
    {
        indexNilai = 'I';
    }

    return indexNilai;
}
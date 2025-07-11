/**
 * --------------------------------------------------------------
 * | @file NimonsBaris.c                                        |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT untuk merepresentasikan barisan Nimons    |
 * | dengan indeks yang dimulai dari 1 (1-based).               |
 * --------------------------------------------------------------
 */

#include "NimonsBaris.h"

void makeEmpty(BarisanNimons *tab)
{
    // Mengatur jumlah elemen efektif menjadi 0
    setNEff(tab, 0);
}

int numberOfElements(BarisanNimons tab)
{
    // Mengembalikan jumlah elemen efektif dalam barisan
    return tab.nEff;
}

int maxNumberOfElements(BarisanNimons tab)
{
    // Mengembalikan kapasitas maksimum barisan (dari indeks min ke indeks max)
    return (IDX_MAX - IDX_MIN + 1);
}

IdxType getFirstIndex(BarisanNimons tab)
{
    // Mengembalikan indeks pertama (konstan, 1)
    return IDX_MIN;
}

IdxType getLastIndex(BarisanNimons tab)
{
    // Mengembalikan indeks terakhir yang terisi (1-based)
    return tab.nEff;
}

ElType getElement(BarisanNimons tab, IdxType idx)
{
    // Mengembalikan nilai elemen di indeks tertentu (asumsinya valid)
    return tab.baris[idx];
}

void setTab(BarisanNimons tabIn, BarisanNimons *tabOut)
{
    // Menyalin jumlah elemen efektif dari input ke output
    setNEff(tabOut, numberOfElements(tabIn));

    // Menyalin elemen satu per satu
    for (int i = IDX_MIN; i <= numberOfElements(tabIn); i++)
    {
        setElement(tabOut, i, getElement(tabIn, i));
    }
}

void setElement(BarisanNimons *tab, IdxType idx, ElType value)
{
    // Menetapkan nilai elemen di indeks tertentu jika valid
    if (isIndexValid(*tab, idx))
    {
        tab->baris[idx] = value;

        // Jika indeks lebih besar dari jumlah elemen, perbarui nEff
        if (idx > tab->nEff)
        {
            tab->nEff = idx;
        }
    }
}

void setNEff(BarisanNimons *tab, IdxType nEff)
{
    // Menetapkan nilai nEff hanya jika dalam batas kapasitas
    if (nEff >= 0 && nEff <= maxNumberOfElements(*tab))
    {
        tab->nEff = nEff;
    }
}

bool isIndexValid(BarisanNimons tab, IdxType idx)
{
    // Mengecek apakah indeks berada dalam batas IDX_MIN hingga IDX_MAX
    return (idx >= IDX_MIN && idx <= IDX_MAX);
}

bool isIndexEff(BarisanNimons tab, IdxType idx)
{
    // Mengecek apakah indeks berada dalam rentang indeks efektif
    return (idx >= getFirstIndex(tab) && idx <= getLastIndex(tab));
}

bool isEmpty(BarisanNimons tab)
{
    // Barisan kosong jika jumlah elemen = 0
    return (numberOfElements(tab) == 0);
}

bool isFull(BarisanNimons tab)
{
    // Barisan penuh jika jumlah elemen = kapasitas maksimum
    return (numberOfElements(tab) == maxNumberOfElements(tab));
}

void printTab(BarisanNimons tab)
{
    if (isEmpty(tab))
    {
        // Tampilkan pesan jika barisan kosong
        printf("Tabel kosong\n");
    }
    else
    {
        // Tampilkan semua elemen dari indeks pertama ke terakhir
        for (int i = getFirstIndex(tab); i <= getLastIndex(tab); i++)
        {
            // Format: 0:val, 1:val, ...
            printf("%d:%d\n", i - 1, getElement(tab, i));
        }
    }
}

BarisanNimons plusTab(BarisanNimons tab1, BarisanNimons tab2)
{
    BarisanNimons result;
    makeEmpty(&result); // Inisialisasi kosong

    // Asumsi kedua barisan memiliki jumlah elemen sama
    setNEff(&result, numberOfElements(tab1));

    // Penjumlahan elemen per indeks
    for (int i = getFirstIndex(tab1); i <= getLastIndex(tab1); i++)
    {
        setElement(&result, i, getElement(tab1, i) + getElement(tab2, i));
    }

    return result;
}

BarisanNimons minusTab(BarisanNimons tab1, BarisanNimons tab2)
{
    BarisanNimons result;
    makeEmpty(&result); // Inisialisasi kosong

    // Asumsi kedua barisan memiliki jumlah elemen sama
    setNEff(&result, numberOfElements(tab1));

    // Pengurangan elemen per indeks
    for (int i = getFirstIndex(tab1); i <= getLastIndex(tab1); i++)
    {
        setElement(&result, i, getElement(tab1, i) - getElement(tab2, i));
    }

    return result;
}

ElType valueMax(BarisanNimons tab)
{
    // Ambil elemen pertama sebagai nilai awal maksimum
    ElType maxValue = getElement(tab, getFirstIndex(tab));

    // Bandingkan dengan elemen lainnya
    for (int i = getFirstIndex(tab) + 1; i <= getLastIndex(tab); i++)
    {
        if (getElement(tab, i) > maxValue)
        {
            maxValue = getElement(tab, i);
        }
    }

    return maxValue;
}

ElType valueMin(BarisanNimons tab)
{
    // Ambil elemen pertama sebagai nilai awal minimum
    ElType minValue = getElement(tab, getFirstIndex(tab));

    // Bandingkan dengan elemen lainnya
    for (int i = getFirstIndex(tab) + 1; i <= getLastIndex(tab); i++)
    {
        if (getElement(tab, i) < minValue)
        {
            minValue = getElement(tab, i);
        }
    }

    return minValue;
}

IdxType indexMaxTab(BarisanNimons tab)
{
    // Inisialisasi indeks maksimum dengan indeks pertama
    IdxType maxIndex = getFirstIndex(tab);

    // Cari indeks dengan elemen terbesar
    for (int i = getFirstIndex(tab) + 1; i <= getLastIndex(tab); i++)
    {
        if (getElement(tab, i) > getElement(tab, maxIndex))
        {
            maxIndex = i;
        }
    }

    return maxIndex;
}

IdxType indexMinTab(BarisanNimons tab)
{
    // Inisialisasi indeks minimum dengan indeks pertama
    IdxType minIndex = getFirstIndex(tab);

    // Cari indeks dengan elemen terkecil
    for (int i = getFirstIndex(tab) + 1; i <= getLastIndex(tab); i++)
    {
        if (getElement(tab, i) < getElement(tab, minIndex))
        {
            minIndex = i;
        }
    }

    return minIndex;
}
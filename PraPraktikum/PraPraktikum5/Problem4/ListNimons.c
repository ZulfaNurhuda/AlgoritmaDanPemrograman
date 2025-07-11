/**
 * --------------------------------------------------------------
 * | @file ListNimons.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT untuk mengelola daftar Nimons.            |
 * --------------------------------------------------------------
 */

#include "ListNimons.h"

void createListNimons(ListNimons *list)
{
    // Mengosongkan seluruh isi list dengan nilai default (name kosong, age = -1)
    for (int i = 0; i < NIMONS_CAPACITY; i++)
    {
        // Menandai elemen sebagai tidak terisi
        strcpy(NIMONS_ELEMENT(*list, i).name, "");
        NIMONS_ELEMENT(*list, i).age = -1;
    }
}

int listNimonsLength(ListNimons list)
{
    int count = 0;

    // Hitung jumlah elemen efektif (berhenti jika age = -1)
    while (count < NIMONS_CAPACITY && NIMONS_ELEMENT(list, count).age != -1)
    {
        count++;
    }

    return count;
}

bool isIdxValidNimons(ListNimons list, int idx)
{
    // Cek apakah idx berada dalam kapasitas array
    return (idx >= IDX_MIN && idx < NIMONS_CAPACITY);
}

bool isIdxEffNimons(ListNimons list, int idx)
{
    // Cek apakah idx adalah indeks elemen yang sudah terisi
    return (idx >= IDX_MIN && idx < listNimonsLength(list));
}

bool isNimonsEmpty(ListNimons list)
{
    // List kosong jika panjang = 0
    return (listNimonsLength(list) == 0);
}

bool isNimonsFull(ListNimons list)
{
    // List penuh jika panjang = kapasitas maksimum
    return (listNimonsLength(list) == NIMONS_CAPACITY);
}

/* ********** BACA dan TULIS ********** */
void readNimonsList(ListNimons *list)
{
    createListNimons(list); // Kosongkan list terlebih dahulu

    int n;
    scanf("%d", &n); // Baca jumlah elemen yang ingin dimasukkan

    // Jika melebihi kapasitas, batasi
    if (n > NIMONS_CAPACITY)
    {
        n = NIMONS_CAPACITY;
    }

    for (int i = 0; i < n; i++)
    {
        // Baca nama, usia, dan tinggi Nimon
        scanf("%s %d %d",
              NIMONS_ELEMENT(*list, i).name,
              &NIMONS_ELEMENT(*list, i).age,
              &NIMONS_ELEMENT(*list, i).height);
    }
}

void printNimonsList(ListNimons list)
{
    int length = listNimonsLength(list);
    printf("[");
    for (int i = 0; i < length; i++)
    {
        // Format: Nama-Umur-Tinggi
        printf("%s-%d-%d",
               NIMONS_ELEMENT(list, i).name,
               NIMONS_ELEMENT(list, i).age,
               NIMONS_ELEMENT(list, i).height);

        // Tampilkan koma jika belum elemen terakhir
        if (i < length - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void insertNimonsLast(ListNimons *list, Nimons newNimons)
{
    if (!isNimonsFull(*list))
    {
        // Tempatkan elemen di indeks setelah elemen terakhir
        int lastIndex = listNimonsLength(*list);
        NIMONS_ELEMENT(*list, lastIndex) = newNimons;
    }
}

void deleteNimonsLast(ListNimons *list, Nimons *newNimons)
{
    if (!isNimonsEmpty(*list))
    {
        // Ambil elemen terakhir
        int lastIndex = listNimonsLength(*list) - 1;
        *newNimons = NIMONS_ELEMENT(*list, lastIndex);

        // Tandai elemen sebagai kosong
        strcpy(NIMONS_ELEMENT(*list, lastIndex).name, "");
        NIMONS_ELEMENT(*list, lastIndex).age = -1;
    }
}

int indexOfNimons(ListNimons list, char *name)
{
    int foundIndex = IDX_UNDEF;
    int length = listNimonsLength(list);

    for (int i = 0; i < length && foundIndex == IDX_UNDEF; i++)
    {
        if (strcmp(NIMONS_ELEMENT(list, i).name, name) == 0)
        {
            foundIndex = i;
        }
    }

    return foundIndex;
}

void findTallestShortest(ListNimons list, Nimons *tallest, Nimons *shortest)
{
    if (!isNimonsEmpty(list))
    {
        // Inisialisasi dengan elemen pertama
        *tallest = NIMONS_ELEMENT(list, 0);
        *shortest = NIMONS_ELEMENT(list, 0);

        int length = listNimonsLength(list);
        for (int i = 1; i < length; i++)
        {
            // Jika lebih tinggi, ganti tertinggi
            if (NIMONS_ELEMENT(list, i).height > tallest->height)
            {
                *tallest = NIMONS_ELEMENT(list, i);
            }

            // Jika lebih pendek, ganti terpendek
            if (NIMONS_ELEMENT(list, i).height < shortest->height)
            {
                *shortest = NIMONS_ELEMENT(list, i);
            }
        }
    }
}
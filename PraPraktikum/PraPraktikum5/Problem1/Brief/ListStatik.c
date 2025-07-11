/**
 * --------------------------------------------------------------
 * | @file ListStatik.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT List menggunakan alokasi dinamis, sesuai  |
 * | dengan struktur pada header ListStatik.h                   |
 * --------------------------------------------------------------
 */

#include "ListStatik.h"

void initializeList(ListStatik *list, int capacity)
{
    // Alokasi memori untuk array sebesar 'capacity'
    list->data = (int *)malloc(capacity * sizeof(int));

    // Inisialisasi awal: kapasitas 0 dan ukuran 0
    list->capacity = 0;
    list->size = 0;

    // Jika alokasi berhasil, set kapasitas aktual
    if (list->data != NULL)
    {
        list->capacity = capacity;
    }
}

bool addElement(ListStatik *list, int value)
{
    bool isSuccess = false;

    // Tambahkan elemen hanya jika masih ada ruang
    if (list->size < list->capacity)
    {
        // Simpan elemen di akhir dan naikkan ukuran
        list->data[list->size] = value;
        list->size++;
        isSuccess = true;
    }

    return isSuccess;
}

bool removeLastElement(ListStatik *list)
{
    bool isSuccess = false;

    // Hapus elemen terakhir hanya jika list tidak kosong
    if (list->size > 0)
    {
        list->size--; // Elemen terakhir tidak perlu benar-benar dihapus
        isSuccess = true;
    }

    return isSuccess;
}

void displayList(ListStatik list)
{
    // Jika list kosong, cetak pesan khusus
    if (list.size == 0)
    {
        printf("List kosong\n");
    }
    else
    {
        // Tampilkan semua elemen secara berurutan tanpa spasi
        for (int i = 0; i < list.size; i++)
        {
            printf("%d", list.data[i]);
        }
        printf("\n"); // Baris baru setelah selesai mencetak
    }
}

int searchElement(ListStatik list, int value)
{
    int foundIndex = -1;

    // Telusuri list untuk menemukan elemen pertama yang cocok
    for (int i = 0; i < list.size && foundIndex == -1; i++)
    {
        if (list.data[i] == value)
        {
            foundIndex = i; // Simpan indeks pertama yang ditemukan
        }
    }

    return foundIndex;
}

bool updateElement(ListStatik *list, int index, int newValue)
{
    bool isSuccess = false;

    // Hanya update jika index valid
    if (index >= 0 && index < list->size)
    {
        list->data[index] = newValue;
        isSuccess = true;
    }

    return isSuccess;
}
/**
 * --------------------------------------------------------------
 * | @file ListStatik.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT List Statik yang sesuai dengan header     |
 * | ListStatik.h                                              |
 * --------------------------------------------------------------
 */

#include "ListStatik.h"

void initializeList(ListStatik *list)
{
    // Set jumlah elemen efektif menjadi 0.
    // Array data[] sudah otomatis teralokasi dengan ukuran CAPACITY.
    list->size = 0;
}

bool addElement(ListStatik *list, int value)
{
    bool isSuccess = false;

    // Tambahkan elemen hanya jika list belum penuh.
    if (list->size < CAPACITY)
    {
        // Tempatkan nilai pada indeks berikutnya dan tingkatkan ukuran.
        list->data[list->size] = value;
        list->size++;
        isSuccess = true;
    }

    return isSuccess;
}

bool removeLastElement(ListStatik *list)
{
    bool isSuccess = false;

    // Hanya dapat menghapus jika list tidak kosong.
    if (list->size > 0)
    {
        // Kurangi ukuran list (data tidak perlu dihapus secara eksplisit).
        list->size--;
        isSuccess = true;
    }

    return isSuccess;
}

void displayList(ListStatik list)
{
    // Jika list kosong, tampilkan pesan khusus.
    if (list.size == 0)
    {
        printf("List kosong\n");
    }
    else
    {
        // Tampilkan semua elemen secara berurutan.
        for (int i = 0; i < list.size; i++)
        {
            printf("%d", list.data[i]);
        }
        printf("\n"); // Baris baru setelah selesai menampilkan
    }
}

int searchElement(ListStatik list, int value)
{
    int foundIndex = -1;

    // Telusuri list dari awal sampai akhir.
    for (int i = 0; i < list.size && foundIndex == -1; i++)
    {
        if (list.data[i] == value)
        {
            // Jika ditemukan, simpan indeks dan keluar dari loop.
            foundIndex = i;
        }
    }

    return foundIndex;
}

bool updateElement(ListStatik *list, int index, int newValue)
{
    bool isSuccess = false;

    // Pastikan indeks berada dalam batas ukuran efektif.
    if (index >= 0 && index < list->size)
    {
        // Ganti nilai pada posisi tersebut.
        list->data[index] = newValue;
        isSuccess = true;
    }

    return isSuccess;
}
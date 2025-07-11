/**
 * --------------------------------------------------------------
 * | @file Set.c                                                |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Set dengan elemen terurut.                |
 * --------------------------------------------------------------
 */

#include "Set.h"

void createEmpty(Set *set)
{
    // Set jumlah elemen efektif menjadi 0
    set->count = NIL;
}

bool isEmpty(Set set)
{
    // Mengembalikan true jika set kosong
    return (set.count == NIL);
}

bool isFull(Set set)
{
    // Mengembalikan true jika set penuh
    return (set.count == MAX_ELEMENTS);
}

bool isMember(Set set, int queryElement)
{
    // Menggunakan pencarian linear sederhana.
    bool found = false;
    int i = 0;
    // Karena elemen terurut, kita bisa berhenti jika elemen saat ini lebih besar.
    while (i < set.count && set.elements[i] <= queryElement && !found)
    {
        if (set.elements[i] == queryElement)
        {
            found = true;
        }
        i++;
    }
    return found;
}

/**
 * *************************************
 * ********** PENCARIAN BINER **********
 * *************************************
 *
 * Catatan: Implementasi alternatif untuk IsMember menggunakan pencarian biner.
 * Jika elemen-elemen dalam Set sudah terurut, kita bisa menggunakan pencarian biner untuk efisiensi yang lebih baik.
 * Pencarian biner memiliki kompleksitas O(log n), sedangkan pencarian linear memiliki kompleksitas O(n).
 * Contoh implementasi pencarian biner:
 *
 * @example Pencarian Biner untuk isMember
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │  bool isMemberWithBinarySearch(Set set, int queryElement)               │
 * │  {                                                                      │
 * │      // Menggunakan pencarian biner (efisiensi O(log n))                │
 * │      int low = 0;                                                       │
 * │      int high = set.count - 1;                                          │
 * │      bool found = false;                                                │
 * │                                                                         │
 * │      while (low <= high && !found)                                      │
 * │      {                                                                  │
 * │          int mid = low + (high - low) / 2; // Menghindari overflow      │
 * │          if (set.elements[mid] == queryElement)                         │
 * │          {                                                              │
 * │              found = true;                                              │
 * │          }                                                              │
 * │          else if (set.elements[mid] < queryElement)                     │
 * │          {                                                              │
 * │              low = mid + 1;                                             │
 * │          }                                                              │
 * │          else                                                           │
 * │          {                                                              │
 * │              high = mid - 1;                                            │
 * │          }                                                              │
 * │      }                                                                  │
 * │      return found;                                                      │
 * │  }                                                                      │
 * └─────────────────────────────────────────────────────────────────────────┘
 */

void insert(Set *set, int newElement)
{
    // Hanya insert jika elemen belum ada dan set tidak penuh
    if (!isFull(*set) && !isMember(*set, newElement))
    {
        int i = 0;
        // Cari posisi yang tepat untuk menyisipkan elemen baru
        while (i < set->count && set->elements[i] < newElement)
        {
            i++;
        }
        // Geser semua elemen yang lebih besar ke kanan
        for (int j = set->count; j > i; j--)
        {
            set->elements[j] = set->elements[j - 1];
        }
        // Sisipkan elemen baru dan perbarui jumlah
        set->elements[i] = newElement;
        set->count++;
    }
}

void delete(Set *set, int elementToDelete)
{
    // Cari posisi elemen yang akan dihapus
    int i = 0;
    bool found = false;
    while (i < set->count && set->elements[i] < elementToDelete)
    {
        i++;
    }

    // Cek apakah elemen ditemukan di posisi saat ini
    if (i < set->count && set->elements[i] == elementToDelete)
    {
        found = true;
    }

    // Jika elemen ditemukan, hapus dan geser elemen lain
    if (found)
    {
        for (int j = i; j < set->count - 1; j++)
        {
            set->elements[j] = set->elements[j + 1];
        }
        set->count--;
    }
}
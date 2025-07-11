#ifndef LIST_STATIK_H
#define LIST_STATIK_H

#include <stdio.h>
#include <stdbool.h>

// Definisi kapasitas maksimum untuk list statik
#define CAPACITY 100

// Definisi struct untuk list statik yang sebenarnya
typedef struct listStatik
{
    int data[CAPACITY];  // Array untuk menyimpan elemen, memori dialokasikan secara statik.
    int size;            // Jumlah elemen efektif yang saat ini ada di dalam list.
} ListStatik;

/**
 * @brief Menginisialisasi list statik.
 *
 * Fungsi ini mempersiapkan struct ListStatik untuk digunakan dengan mengatur
 * ukurannya menjadi 0. Kapasitas sudah ditentukan oleh CAPACITY.
 *
 * @param list Pointer ke struct ListStatik yang akan diinisialisasi.
 */
void initializeList(ListStatik *list);

/**
 * @brief Menambahkan sebuah nilai ke akhir list statik.
 *
 * @param list Pointer ke struct ListStatik.
 * @param value Nilai integer yang akan ditambahkan ke list.
 * 
 * @return true jika elemen berhasil ditambahkan, false jika list sudah penuh.
 */
bool addElement(ListStatik *list, int value);

/**
 * @brief Menghapus elemen terakhir dari list statik.
 *
 * @param list Pointer ke struct ListStatik.
 * 
 * @return true jika elemen berhasil dihapus, false jika list kosong.
 */
bool removeLastElement(ListStatik *list);

/**
 * @brief Menampilkan semua elemen yang ada di dalam list statik.
 *
 * @param list Struct ListStatik yang akan ditampilkan.
 */
void displayList(ListStatik list);

/**
 * @brief Mencari apakah suatu nilai terdapat di dalam list statik.
 *
 * @param list Struct ListStatik yang akan dicari.
 * @param value Nilai integer yang ingin dicari.
 * 
 * @return Indeks pertama tempat nilai ditemukan atau -1 jika tidak ada.
 */
int searchElement(ListStatik list, int value);

/**
 * @brief Mengubah nilai elemen pada indeks tertentu dalam list statik.
 *
 * @param list Pointer ke struct ListStatik.
 * @param index Indeks dari elemen yang ingin diubah.
 * @param newValue Nilai integer baru yang akan disimpan.
 * 
 * @return true jika perubahan berhasil, false jika indeks tidak valid.
 */
bool updateElement(ListStatik *list, int index, int newValue);

#endif /* LIST_STATIK_H */

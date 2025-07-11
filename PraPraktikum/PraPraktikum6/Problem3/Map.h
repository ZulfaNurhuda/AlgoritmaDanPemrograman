#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

/* ****************************** */
/* ********* TIPE DATA ********** */
/* ****************************** */

/* ------------------------------ */
/* ----- Struktur Map Entry ----- */
/* ------------------------------ */

typedef struct mapEntry
{
    int key;     // Key (integer)
    char *value; // Nilai (string)
} MapEntry;

/* ------------------------------ */
/* -------- Struktur Map -------- */
/* ------------------------------ */

typedef struct map
{
    MapEntry *entries; // Array dinamis dari MapEntry
    int capacity;      // Kapasitas maksimum array
    int size;          // Jumlah elemen yang saat ini ada di Map
} Map;

/**
 * @brief Membuat dan menginisialisasi Map baru.
 *
 * @param capacity Kapasitas maksimum Map. Asumsikan bahwa nilai capacity selalu > 0.
 * 
 * @return Pointer ke objek Map yang baru dibuat, atau NULL jika alokasi gagal
 * atau kapasitas tidak valid.
 */
Map *createMap(int capacity);

/**
 * @brief Menyisipkan pasangan key-value baru ke dalam Map, atau memperbarui
 * value jika key sudah ada.
 *
 * @param map Pointer ke objek Map.
 * @param key Kunci yang akan disisipkan atau diperbarui.
 * @param queryKey Nilai yang akan diasosiasikan dengan kunci.
 *
 * @return true jika berhasil (penyisipan atau pembaruan), false jika Map penuh
 * atau input tidak valid.
 *
 * @note String yang dijadikan value harus dialokasikan ulang agar
 * kepemilikan string tersebut berpindah ke map.
 */
bool mapInsert(Map *map, int newKey, const char *queryKey);

/**
 * @brief Mengambil value yang terikat dengan key tertentu.
 *
 * @param map Pointer ke objek Map.
 * @param queryKey Kunci yang nilainya akan diambil.
 *
 * @return nilai jika kunci ditemukan, atau NULL jika kunci
 * tidak ditemukan atau input tidak valid.
 */
char *mapGet(const Map *map, int queryKey);

/**
 * @brief Menghapus pasangan key-value dari Map berdasarkan key.
 *
 * @param map Pointer ke objek Map.
 * @param keyToDelete Kunci elemen yang akan dihapus.
 *
 * @return true jika berhasil dihapus, false jika kunci tidak ditemukan atau
 * input tidak valid.
 */
bool mapDelete(Map *map, int keyToDelete);

/**
 * @brief Mendapatkan jumlah elemen (pasangan key-value) dalam Map.
 *
 * @param map Pointer ke objek Map.
 * 
 * @return Jumlah elemen dalam Map.
 */
int mapSize(const Map *map);

/**
 * @brief Memeriksa apakah kunci tertentu ada di dalam Map.
 *
 * @param map Pointer ke objek Map.
 * @param queryKey Kunci yang akan diperiksa keberadaannya.
 *
 * @return true jika kunci ada, false jika kunci tidak ada.
 */
bool mapContainsKey(const Map *map, int queryKey);

#endif /* MAP_H */
/**
 * ----------------------
 * | Modul Hash HashMap |
 * ----------------------
 * - Implementasi Hash HashMap dengan Open Addressing
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>
#include "Boolean.h"

/* ****************************** */
/* ********* KONSTANTA ********** */
/* ****************************** */

#define NIL 0
#define MAX_ELEMENTS 16
#define UNDEFINED -9999

/* ****************************** */
/* ********* TIPE DATA ********** */
/* ****************************** */

typedef int KeyType;   // Tipe data untuk key
typedef int ValueType; // Tipe data untuk value
typedef int Address;   // Tipe data untuk alamat penyimpanan

/* ------------------------------ */
/* ----- Struktur InfoType ------ */
/* ------------------------------ */

typedef struct infoType
{
    KeyType key;
    ValueType value;
} InfoType;

/* ------------------------------ */
/* ------ Struktur HashMap ------ */
/* ------------------------------ */

typedef struct hashMap
{
    InfoType elements[MAX_ELEMENTS]; // List of key-value pairs with maximum size MAX_ELEMENTS
    int count;                       // Jumlah elemen dalam HashMap
} HashMap;

/* ****************************** */
/* ********** DEFINISI ********** */
/* ****************************** */

/* Definisi HashMap kosong : map.Count = NIL */
/* map.Count = jumlah element HashMap */
/* map.Elements = tempat penyimpanan element HashMap */

/* ***************************** */
/* ********* Prototype ********* */
/* ***************************** */

/* *************************** */
/* *** Konstruktor/Kreator *** */
/* *************************** */

// TODO: 1. CreateEmpty
/**
 * @brief Menginisialisasi struktur HashMap menjadi kosong.
 *
 * Menandai semua slot sebagai UNDEFINED dan menyetel jumlah elemen ke 0.
 * Digunakan sebelum HashMap digunakan untuk pertama kali.
 *
 * @param map Pointer ke struktur HashMap yang akan diinisialisasi.
 */
void createEmpty(HashMap *map);

/* *************************************** */
/* *** Index Penyimpanan dengan modulo *** */
/* *************************************** */

/**
 * @brief Menghitung indeks hash dari sebuah key.
 *
 * Fungsi hash menggunakan operasi modulo dengan MAX_ELEMENTS.
 * Jika hasilnya negatif, akan disesuaikan agar tetap dalam rentang valid.
 *
 * @param key Kunci integer yang akan dihitung hash-nya.
 * @return Address Hasil indeks dalam array (selalu positif).
 */
Address hash(KeyType key);

/* ******************************************* */
/* ********** Operator Dasar HashMap ********* */
/* ******************************************* */

// TODO: 2. Value
/**
 * @brief Mengambil nilai yang berasosiasi dengan queryKey.
 *
 * Melakukan pencarian linear mulai dari hash(queryKey). Jika queryKey ditemukan,
 * mengembalikan value-nya. Jika tidak, mengembalikan UNDEFINED.
 *
 * @param map HashMap tempat pencarian.
 * @param queryKey Kunci yang ingin dicari.
 * @return ValueType Nilai yang terkait dengan key, atau UNDEFINED jika tidak ditemukan.
 */
ValueType value(HashMap map, KeyType queryKey);

// TODO: 3. Insert
/**
 * @brief Menyisipkan pasangan key-value ke dalam HashMap.
 *
 * Jika newKey sudah ada, fungsi akan memperbarui nilainya.
 * Jika newKey belum ada dan masih tersedia slot kosong, maka akan disisipkan ke slot kosong.
 * Penyisipan menggunakan open addressing (linear probing).
 *
 * @param map Pointer ke struktur HashMap.
 * @param newKey Kunci yang akan ditambahkan atau diperbarui.
 * @param newValue Nilai yang akan diasosiasikan dengan kunci.
 */
void insert(HashMap *map, KeyType newKey, ValueType newValue);

// TODO: 4. printHashMap
/**
 * @brief Menampilkan isi dari HashMap ke layar.
 *
 * Mencetak seluruh slot dalam HashMap (termasuk yang belum terisi),
 * dengan informasi posisi indeks, key, dan value.
 *
 * @param map Struktur HashMap yang ingin ditampilkan.
 */
void printHashMap(HashMap map);

#endif /* HASHMAP_H */
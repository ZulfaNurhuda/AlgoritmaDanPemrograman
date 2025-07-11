/**
 * --------------------------------------------------------------
 * | @file Hashmap.c                                            |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT HashMap dengan open addressing.           |
 * --------------------------------------------------------------
 */

#include "Hashmap.h"

void createEmpty(HashMap *map)
{
    // Inisialisasi jumlah elemen dalam hashmap ke 0
    map->count = 0;

    // Tandai semua slot sebagai UNDEFINED (kosong)
    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        map->elements[i].key = UNDEFINED;
        map->elements[i].value = UNDEFINED;
    }
}

Address hash(KeyType key)
{
    // Fungsi hash sederhana menggunakan modulo untuk menentukan indeks
    int hashValue = key % MAX_ELEMENTS;

    // Jika hasil negatif (misalnya key negatif), sesuaikan ke indeks positif
    if (hashValue < 0)
    {
        hashValue += MAX_ELEMENTS;
    }

    return hashValue;
}

ValueType value(HashMap map, KeyType queryKey)
{
    Address index = hash(queryKey); // Hitung indeks awal berdasarkan key
    int attempts = 0;               // Untuk mencegah infinite loop
    ValueType foundValue = UNDEFINED;

    // Lakukan pencarian linear probing sampai key ditemukan atau slot kosong
    while (attempts < MAX_ELEMENTS &&
           map.elements[index].key != UNDEFINED &&
           foundValue == UNDEFINED)
    {
        // Jika ditemukan key yang dicari, ambil nilainya
        if (map.elements[index].key == queryKey)
        {
            foundValue = map.elements[index].value;
        }

        // Probing ke indeks selanjutnya (linear probing)
        index = (index + 1) % MAX_ELEMENTS;
        attempts++;
    }

    // Kembalikan nilai jika ditemukan, atau UNDEFINED jika tidak
    return foundValue;
}

void insert(HashMap *map, KeyType newkey, ValueType newValue)
{
    Address index = hash(newkey); // Hitung indeks awal
    int attempts = 0;
    bool keyExists = false;

    // Tahap 1: Cek apakah key sudah ada di hashmap
    while (attempts < MAX_ELEMENTS &&
           map->elements[index].key != UNDEFINED &&
           !keyExists)
    {
        // Jika ditemukan key yang sama
        if (map->elements[index].key == newkey)
        {
            keyExists = true;
        }

        // Lanjut probing
        index = (index + 1) % MAX_ELEMENTS;
        attempts++;
    }

    // Tahap 2: Lakukan aksi berdasarkan hasil pencarian
    if (keyExists)
    {
        // Jika key sudah ada, perbarui nilai
        map->elements[index].value = newValue;
    }
    else
    {
        // Jika key belum ada dan masih ada slot kosong
        if (map->count < MAX_ELEMENTS)
        {
            index = hash(newkey); // Mulai lagi dari indeks awal

            // Cari slot kosong pertama
            while (map->elements[index].key != UNDEFINED)
            {
                index = (index + 1) % MAX_ELEMENTS;
            }

            // Masukkan pasangan key-value ke slot kosong
            map->elements[index].key = newkey;
            map->elements[index].value = newValue;
            map->count++; // Tambah jumlah elemen
        }
        // Jika map penuh, tidak melakukan apa-apa
    }
}

void printHashMap(HashMap map)
{
    // Cetak semua slot (baik yang kosong maupun terisi)
    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        printf("%d:\n", i); // Indeks array
        printf("  Key: %d\n", map.elements[i].key);
        printf("  Value: %d\n", map.elements[i].value);
    }
}
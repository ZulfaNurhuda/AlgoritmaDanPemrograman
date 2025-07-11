/**
 * --------------------------------------------------------------
 * | @file Map.c                                                |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Map dinamis.                              |
 * --------------------------------------------------------------
 */

#include "Map.h"

/**
 * Fungsi bantu privat untuk mencari indeks key dalam map
 * @param map Pointer ke map yang sedang diperiksa
 * @param queryKey Nilai key yang dicari
 * @return Indeks key jika ditemukan, -1 jika tidak ditemukan
 */
static int findKeyIndex(const Map *map, int queryKey)
{
    int index = -1;
    int i = 0;

    // Iterasi elemen map untuk mencari key
    while (i < mapSize(map) && index == -1)
    {
        if (map->entries[i].key == queryKey)
        {
            index = i; // Ditemukan
        }
        else
        {
            i++;
        }
    }

    return index;
}

Map *createMap(int capacity)
{
    Map *newMap = (Map *)malloc(sizeof(Map)); // Alokasi struct Map

    if (newMap != NULL)
    {
        // Alokasi array entry (key-value)
        newMap->entries = (MapEntry *)malloc(sizeof(MapEntry) * capacity);

        if (newMap->entries == NULL)
        {
            // Jika gagal alokasi entries, hapus struct map
            free(newMap);
            newMap = NULL;
        }
        else
        {
            // Inisialisasi atribut
            newMap->capacity = capacity;
            newMap->size = 0;
        }
    }

    return newMap;
}

bool mapInsert(Map *map, int newKey, const char *newValue)
{
    bool success = false;
    int index = findKeyIndex(map, newKey); // Cek apakah key sudah ada

    // Alokasi string baru untuk disalin ke dalam map
    char *newValue = (char *)malloc(strlen(newValue) + 1);
    if (newValue != NULL)
    {
        strcpy(newValue, newValue); // Salin isi string

        if (index != -1)
        {
            // Key sudah ada, update value lama
            free(map->entries[index].value); // Hapus value lama
            map->entries[index].value = newValue;
            success = true;
        }
        else if (mapSize(map) < map->capacity)
        {
            // Key baru, dan masih ada ruang
            map->entries[mapSize(map)].key = newKey;
            map->entries[mapSize(map)].value = newValue;
            map->size++;
            success = true;
        }
        else
        {
            // Map sudah penuh, tidak bisa menambah
            free(newValue);
        }
    }

    return success;
}

char *mapGet(const Map *map, int queryKey)
{
    char *result = NULL;

    // Cari index dengan menggunakan fungsi bantu
    int index = findKeyIndex(map, queryKey);

    // Jika ditemukan, assign result dengan value
    if (index != -1)
    {
        result = map->entries[index].value;
    }

    return result;
}

bool mapDelete(Map *map, int keyToDelete)
{
    bool success = false;

    // Cari index dengan menggunakan fungsi bantu
    int index = findKeyIndex(map, keyToDelete);

    if (index != -1)
    {
        // Hapus value string yang dialokasikan
        free(map->entries[index].value);

        // Geser semua elemen setelahnya ke kiri
        for (int i = index; i < mapSize(map) - 1; i++)
        {
            map->entries[i] = map->entries[i + 1];
        }

        // Kurangi ukuran
        map->size--;
        success = true;
    }

    return success;
}

int mapSize(const Map *map)
{
    // Mengembalikan jumlah elemen dalam Map
    return map->size;
}

bool mapContainsKey(const Map *map, int queryKey)
{
    // Cari index dengan menggunakan fungsi bantu
    // Jika hasilnya -1, key tidak ditemukan
    return (findKeyIndex(map, queryKey) != -1);
}
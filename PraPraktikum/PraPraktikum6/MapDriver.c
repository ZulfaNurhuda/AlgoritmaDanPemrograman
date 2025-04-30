#include <stdio.h>
#include "Map.h" // OR #include "map.h"

/**
 * Fungsi yang digunakan untuk membebaskan memori
 * yang dialokasikan untuk map dan semua entri di dalamnya
 * Fungsi ini harus dipanggil setelah selesai menggunakan map
 */
void destroy_map(Map *map)
{

    for (int i = 0; i < map->capacity; i++)
    {
        free(map->entries[i].value);
    }
    free(map->entries);
    free(map);
}

int main()
{
    Map *map = create_map(5);
    char *nimons[] = {"Kebin", "Stuart", "Dave", "Pop", "Larry", "Mel"};

    for (int i = 0; i <= 5; i++)
    {
        if (!map_insert(map, i, nimons[i]))
        {
            printf("Terjadi error ketika memasukkan %s ke bilik %d\n",
                   nimons[i], i);
        }
    }

    for (int i = 0; i <= 5; i++)
    {
        const char *nimon = map_get(map, i);
        if (nimon != NULL)
        {
            printf("Bilik ke-%d diisi oleh %s\n", i, nimon);
        }
        else
        {
            printf("Terjadi error ketika melakukan pengecekan ke bilik %d\n",
                   i);
        }
    }

    if (map_delete(map, 1))
    {
        printf("Bilik ke-1 berhasil dikosongkan\n");
    }

    if (!map_delete(map, 1))
    {
        printf("Terjadi error ketika ingin melakukan pengosongan bilik ke 1\n");
    }
    printf("Ukuran map saat ini %d\n", map_size(map));

    destroy_map(map);

    return 0;
}
#include "Map.h"

/**
 * @brief Membebaskan memori yang dialokasikan untuk Map.
 *
 * Fungsi ini menghapus semua pasangan key-value dalam Map dengan membebaskan
 * memori yang digunakan oleh setiap nilai string, array entries, dan struct Map
 * itu sendiri. Pastikan untuk memanggil fungsi ini saat Map tidak lagi diperlukan
 * untuk mencegah kebocoran memori.
 *
 * @param map Pointer ke objek Map yang akan dihancurkan. Jika map adalah NULL,
 * fungsi tidak melakukan apa-apa.
 */
static void destroyMap(Map *map)
{
    if (map != NULL)
    {
        for (int i = 0; i < mapSize(map); i++)
        {
            free(map->entries[i].value); // Bebaskan setiap string value
        }
        free(map->entries);              // Bebaskan array of entries
        free(map);                       // Bebaskan struct Map itu sendiri
    }
}

int main(void)
{
    int capacity = 5;

    // Buat map dinamis dengan kapasitas 5
    Map *map = createMap(capacity);

    // Daftar nama Nimons yang ingin dimasukkan ke map
    // Jumlahnya 6 (sengaja melebihi kapasitas untuk menguji kegagalan insert)
    char *nimons[] = {"Kebin", "Stuart", "Dave", "Pop", "Larry", "Mel"};

    // Masukkan pasangan key-value ke dalam map
    for (int i = 0; i <= capacity; i++) // i dari 0 hingga 5 (total 6 iterasi)
    {
        // Jika gagal memasukkan (karena kapasitas penuh), cetak pesan error
        if (!mapInsert(map, i, nimons[i]))
        {
            printf("Terjadi error ketika memasukkan %s ke bilik %d\n", nimons[i], i);
        }
    }

    // Ambil dan tampilkan isi setiap bilik berdasarkan key
    for (int i = 0; i <= capacity; i++)
    {
        const char *nimon = mapGet(map, i);
        if (nimon != NULL)
        {
            printf("Bilik ke-%d diisi oleh %s\n", i, nimon);
        }
        else
        {
            // Jika key tidak ditemukan (misalnya karena gagal insert sebelumnya)
            printf("Terjadi error ketika melakukan pengecekan ke bilik %d\n", i);
        }
    }

    // Coba hapus bilik ke-1 (dengan key = 1)
    if (mapDelete(map, 1))
    {
        printf("Bilik ke-1 berhasil dikosongkan\n");
    }

    // Coba hapus lagi bilik ke-1 (harus gagal karena sudah dihapus sebelumnya)
    if (!mapDelete(map, 1))
    {
        printf("Terjadi error ketika ingin melakukan pengosongan bilik ke 1\n");
    }

    // Tampilkan jumlah entri map saat ini
    printf("Ukuran map saat ini %d\n", mapSize(map));

    // Dealokasi seluruh isi map
    destroyMap(map);

    return 0;
}
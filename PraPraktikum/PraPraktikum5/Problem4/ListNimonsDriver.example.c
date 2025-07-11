#include "ListNimons.h"

#define COLOR_GREEN "\e[0;32m"
#define COLOR_RESET "\e[0m"

int main(void)
{
    ListNimons nimonsList;
    Nimons nimon, tallest, shortest, deleted;

    // 1. Inisialisasi list
    printf("--- 1. Membuat List Baru ---\n");
    createListNimons(&nimonsList);
    printf("List Nimons berhasil dibuat.\n");
    printf("Panjang awal list: %d\n", listNimonsLength(nimonsList));
    printf("Tes isNimonsEmpty(): %s\n", isNimonsEmpty(nimonsList) ? "true" : "false");
    printNimonsList(nimonsList); // Harusnya mencetak []

    // 2. Menambahkan 3 Nimons
    printf("\n--- 2. Menambahkan 3 Nimons ---\n");

    // Nimon 1
    strcpy(nimon.name, "Kevin");
    nimon.age = 10;
    nimon.height = 120;
    insertNimonsLast(&nimonsList, nimon);

    // Nimon 2
    strcpy(nimon.name, "Stuart");
    nimon.age = 8;
    nimon.height = 95;
    insertNimonsLast(&nimonsList, nimon);

    // Nimon 3
    strcpy(nimon.name, "Bob");
    nimon.age = 7;
    nimon.height = 135;
    insertNimonsLast(&nimonsList, nimon);

    // Tampilkan hasil
    printf("Panjang list sekarang: %d\n", listNimonsLength(nimonsList));
    printf("Tes isNimonsFull(): %s\n", isNimonsFull(nimonsList) ? "true" : "false");
    printNimonsList(nimonsList);

    // 3. Mencari Nimon berdasarkan nama
    char *searchName = "Stuart";
    printf("\n--- 3. Mencari Nimon bernama '%s' ---\n", searchName);
    int idx = indexOfNimons(nimonsList, searchName);
    if (idx != IDX_UNDEF)
    {
        printf("Ditemukan pada indeks: %d\n", idx);
    }
    else
    {
        printf("Tidak ditemukan.\n");
    }

    // Cari nama yang tidak ada
    searchName = "Dave";
    printf("--- Mencari Nimon bernama '%s' ---\n", searchName);
    idx = indexOfNimons(nimonsList, searchName);
    if (idx != IDX_UNDEF)
    {
        printf("Ditemukan pada indeks: %d\n", idx);
    }
    else
    {
        printf("Tidak ditemukan.\n");
    }

    // 4. Cari tertinggi dan terpendek
    printf("\n--- 4. Mencari Nimon tertinggi dan terpendek ---\n");
    findTallestShortest(nimonsList, &tallest, &shortest);
    printf("Tertinggi: %s (%d cm)\n", tallest.name, tallest.height);
    printf("Terpendek: %s (%d cm)\n", shortest.name, shortest.height);

    // 5. Hapus elemen terakhir
    printf("\n--- 5. Menghapus Nimon terakhir ---\n");
    deleteNimonsLast(&nimonsList, &deleted);
    printf("Nimon yang dihapus: %s\n", deleted.name);
    printf("List sekarang:\n");
    printNimonsList(nimonsList);
    printf("Panjang list akhir: %d\n", listNimonsLength(nimonsList));

    printf(COLOR_GREEN "\n[ ☑ ] - Pengujian selesai.\n" COLOR_RESET);

    return 0;
}
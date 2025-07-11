#include "ListStatik.h"

#define COLOR_GREEN "\e[0;32m"
#define COLOR_RESET "\e[0m"

/**
 * @brief Melakukan dealokasi terhadap list statik (dinamis).
 *
 * Fungsi ini membebaskan memori yang dialokasikan untuk array `data`
 * di dalam list, serta mengatur ulang nilai size dan capacity menjadi 0.
 * Harus dipanggil setelah selesai menggunakan list agar tidak terjadi memory leak.
 *
 * @param list Pointer ke struct ListStatik yang ingin didealokasi.
 */
static void deallocateList(ListStatik *list)
{
    // Bebaskan memori array dinamis
    free(list->data);

    // Set ulang semua atribut ke 0
    list->size = 0;
    list->capacity = 0;
}

int main(void)
{
    ListStatik bananaList;
    int capacity = 10;

    // 1. Inisialisasi list dengan kapasitas 10
    initializeList(&bananaList, capacity);
    printf("List dinamis dibuat dengan kapasitas %d.\n", capacity);

    // Menampilkan isi list awal (harus kosong)
    displayList(bananaList);

    // 2. Menambahkan elemen
    printf("\nMenambahkan 5 elemen: 10, 20, 30, 40, 50\n");

    // Tambahkan 10
    addElement(&bananaList, 10);
    printf("(+10): ");
    displayList(bananaList);

    // Tambahkan 20
    addElement(&bananaList, 20);
    printf("(+20): ");
    displayList(bananaList);

    // Tambahkan 30
    addElement(&bananaList, 30);
    printf("(+30): ");
    displayList(bananaList);

    // Tambahkan 40
    addElement(&bananaList, 40);
    printf("(+40): ");
    displayList(bananaList);

    // Tambahkan 50
    addElement(&bananaList, 50);
    printf("(+50): ");
    displayList(bananaList);

    // 3. Menghapus elemen terakhir (yaitu 50)
    printf("\nMenghapus elemen terakhir.\n");
    removeLastElement(&bananaList);
    displayList(bananaList);

    // 4. Dealokasi memori list
    deallocateList(&bananaList);
    printf("\nMemori list telah dilepaskan.\n");

    // Indikasi bahwa program selesai
    printf(COLOR_GREEN "\n[ ☑ ] - Pengujian selesai.\n" COLOR_RESET);

    return 0;
}
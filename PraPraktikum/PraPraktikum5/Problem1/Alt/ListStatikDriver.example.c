#include "ListStatik.h"

#define COLOR_GREEN "\e[0;32m"
#define COLOR_RESET "\e[0m"

int main(void)
{
    // Deklarasi variabel list statik.
    // Memori untuk 'data' sudah termasuk di dalam 'bananaList'.
    ListStatik bananaList;

    // 1. Inisialisasi List
    // Mengatur ukuran list menjadi 0 (kosong).
    initializeList(&bananaList);
    printf("List statik berhasil dibuat.\n");

    // Tampilkan kapasitas maksimum dari list (konstanta CAPACITY).
    printf("Kapasitas maksimum: %d\n", CAPACITY);

    // Menampilkan list yang baru dibuat (harusnya kosong).
    displayList(bananaList); // Output: "List kosong"

    // 2. Menambahkan elemen ke list
    printf("\nMenambahkan 3 elemen: 15, 25, 35\n");

    // Tambahkan elemen 15
    addElement(&bananaList, 15);
    printf("(+15): ");
    displayList(bananaList);

    // Tambahkan elemen 25
    addElement(&bananaList, 25);
    printf("(+25): ");
    displayList(bananaList);

    // Tambahkan elemen 35
    addElement(&bananaList, 35);
    printf("(+35): ");
    displayList(bananaList);

    // 3. Mengubah elemen
    // Ubah elemen pada indeks ke-0 menjadi 99
    printf("\nMengubah elemen di indeks 0 menjadi 99.\n");
    updateElement(&bananaList, 0, 99);
    displayList(bananaList);

    // 4. Menghapus elemen terakhir
    // Elemen terakhir (35) akan dihapus
    printf("\nMenghapus elemen terakhir.\n");
    removeLastElement(&bananaList);
    displayList(bananaList);

    // Informasi tambahan: tidak perlu free() karena list statik
    printf("\nINFO: Tidak perlu ada pembebasan memory karena menggunakan list statik.\n");

    // Penanda bahwa semua pengujian telah selesai
    printf(COLOR_GREEN "\n[ ☑ ] - Pengujian selesai.\n" COLOR_RESET);

    return 0;
}
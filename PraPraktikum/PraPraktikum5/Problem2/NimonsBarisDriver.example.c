#include "NimonsBaris.h"

#define COLOR_GREEN "\e[0;32m"
#define COLOR_RESET "\e[0m"

int main(void)
{
    // Deklarasi tiga barisan: dua input dan satu hasil
    BarisanNimons lineup1, lineup2, lineupResult;

    // 1. Membuat barisan kosong
    makeEmpty(&lineup1); // Inisialisasi lineup1 menjadi kosong (nEff = 0)
    printf("Barisan 1 dibuat.\n");
    printTab(lineup1); // Harus menampilkan "Tabel kosong" karena belum diisi

    // 2. Mengisi Barisan 1 dengan 5 elemen
    printf("\nMengisi Barisan 1 dengan 5 elemen...\n");

    // Set jumlah elemen efektif ke 5
    setNEff(&lineup1, 5);

    // Isi elemen 1 hingga 5
    setElement(&lineup1, 1, 10);
    setElement(&lineup1, 2, 50);
    setElement(&lineup1, 3, 20);
    setElement(&lineup1, 4, 80);
    setElement(&lineup1, 5, 40);

    printf("Isi Barisan 1:\n");
    printTab(lineup1); // Cetak elemen barisan 1

    // 3. Menguji selektor nilai ekstrem (maksimum dan minimum)
    printf("\n--- Pengujian Nilai Ekstrem Barisan 1 ---\n");

    // Nilai maksimum dari barisan 1
    printf("Nilai Maksimum: %d\n", valueMax(lineup1));

    // Indeks dari elemen maksimum
    printf("Indeks Nilai Maksimum: %d\n", indexMaxTab(lineup1));

    // Nilai minimum dari barisan 1
    printf("Nilai Minimum: %d\n", valueMin(lineup1));

    // Indeks dari elemen minimum
    printf("Indeks Nilai Minimum: %d\n", indexMinTab(lineup1));

    // 4. Membuat dan mengisi Barisan 2
    printf("\nMembuat dan mengisi Barisan 2...\n");

    // Salin seluruh isi lineup1 ke lineup2
    setTab(lineup1, &lineup2);

    // Ubah beberapa elemen dari lineup2 agar berbeda dengan lineup1
    setElement(&lineup2, 1, 5);
    setElement(&lineup2, 3, 15);
    setElement(&lineup2, 5, 25);

    printf("Isi Barisan 2:\n");
    printTab(lineup2); // Cetak isi lineup2 yang telah dimodifikasi

    // 5. Menguji operator aritmatika antar barisan
    printf("\n--- Pengujian Operator Aritmatika ---\n");

    // Penjumlahan barisan 1 dan 2
    printf("Barisan 1 + Barisan 2:\n");
    lineupResult = plusTab(lineup1, lineup2);
    printTab(lineupResult);

    // Pengurangan barisan 1 dan 2
    printf("\nBarisan 1 - Barisan 2:\n");
    lineupResult = minusTab(lineup1, lineup2);
    printTab(lineupResult);

    // Penanda akhir program
    printf(COLOR_GREEN "\n[ ☑ ] - Pengujian selesai.\n" COLOR_RESET);

    return 0;
}
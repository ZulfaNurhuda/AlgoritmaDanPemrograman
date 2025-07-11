/**
 * --------------------------------------------------------------
 * | @file LaporanPisang.c                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program interaktif untuk mencatat dan melaporkan status    |
 * | kematangan pisang. Pengguna dapat memasukkan data pisang   |
 * | baru atau meminta laporan ringkasan.                       |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk jumlah total operasi yang diizinkan.
    int numberOfOperations;
    // Variabel untuk menyimpan jumlah pisang dalam setiap kategori kematangan.
    int unripeCount = 0;
    int ripeCount = 0;
    int overripeCount = 0;

    // Membaca jumlah total operasi dari pengguna.
    scanf("%d", &numberOfOperations);

    // Variabel untuk menghitung jumlah operasi input pisang yang telah dilakukan.
    int operationsDone = 0;
    // Loop berjalan selama jumlah operasi yang dilakukan kurang dari yang diizinkan.
    while (operationsDone < numberOfOperations)
    {
        // Variabel untuk menyimpan pilihan menu dari pengguna.
        int menuOption;
        // Membaca pilihan menu.
        scanf("%d", &menuOption);

        // Opsi 1: Input data pisang baru.
        if (menuOption == 1)
        {
            // Variabel untuk menyimpan hari kematangan pisang.
            int ripenessDay;
            scanf("%d", &ripenessDay);

            // Mengkategorikan pisang berdasarkan hari kematangannya.
            if (ripenessDay >= 0 && ripenessDay <= 2)
            {
                printf("Kategori: Mentah\n");
                unripeCount++;
            }
            else if (ripenessDay >= 3 && ripenessDay <= 5)
            {
                printf("Kategori: Matang\n");
                ripeCount++;
            }
            else // Hari > 5 atau hari < 0 (meskipun negatif tidak secara eksplisit ditangani berbeda di sini)
            {
                printf("Kategori: Terlalu matang\n");
                overripeCount++;
            }
            // Hanya increment operationsDone jika itu adalah operasi input pisang yang valid.
            operationsDone++;
        }
        // Opsi 2: Tampilkan laporan kematangan pisang.
        else if (menuOption == 2)
        {
            printf("Laporan Kematangan Pisang\n");
            printf("Mentah: %d\n", unripeCount);
            printf("Matang: %d\n", ripeCount);
            printf("Terlalu matang: %d\n", overripeCount);
            // Menampilkan laporan tidak dihitung sebagai salah satu dari N operasi input pisang.
            // Jika N adalah total interaksi, maka operationsDone++ harusnya ada di sini juga.
            // Berdasarkan loop `while (i < N)` dan `i++` hanya di blok `option == 1` pada kode asli,
            // N merujuk pada jumlah pisang yang akan diinput.
        }
        // Opsi tidak valid.
        else
        {
            printf("Input salah. Masukkan kembali input dengan benar.\n");
            // Input salah tidak dihitung sebagai operasi yang mengurangi numberOfOperations.
        }
    }

    // Pesan akhir setelah semua operasi input pisang selesai.
    printf("Program selesai\n");
    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
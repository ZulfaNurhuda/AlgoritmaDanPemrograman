/**
 * --------------------------------------------------------------
 * | @file LuasRumah.c                                          |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menghitung dan menampilkan perkiraan luas    |
 * | rumah selama beberapa tahun ke depan, berdasarkan luas     |
 * | awal dan penambahan luas tahunan.                          |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk luas awal (initialArea) dan jumlah tahun (numberOfYears).
    int initialArea;
    int numberOfYears;
    // Variabel untuk menyimpan luas rumah pada tahun tertentu.
    int currentArea;

    // Membaca input luas awal dan jumlah tahun dari pengguna.
    scanf("%d %d", &initialArea, &numberOfYears);

    // Loop untuk menghitung dan menampilkan luas rumah setiap tahun.
    // Loop berjalan dari tahun ke-1 hingga tahun ke-numberOfYears.
    for (int year = 1; year <= numberOfYears; year++)
    {
        // Menghitung luas rumah pada tahun saat ini.
        // Rumus dari kode asli: n + 9 * (i + 1), dimana i adalah 0-based index.
        // Jika i adalah 0-based, maka (i + 1) adalah tahun ke- (1-based).
        // Jadi, luas = initialArea + 9 * tahun_ke.
        currentArea = initialArea + (9 * year);
        // Mencetak luas rumah untuk tahun saat ini.
        printf("tahun ke-%d = %d\n", year, currentArea);
    }

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
/**
 * --------------------------------------------------------------
 * | @file NimonsAttackDriver.c                                 |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Driver program utama untuk menjalankan simulasi serangan   |
 * | Nimons. Program ini hanya memanggil fungsi utama dari      |
 * | modul NimonsAttack.                                        |
 * --------------------------------------------------------------
 */

#include "NimonsAttack.h" // Menginclude header file yang berisi deklarasi fungsi findAndReportNearbyShips

/**
 * @brief Fungsi utama program (entry point).
 * @details Memanggil fungsi `findAndReportNearbyShips` untuk memulai
 *          simulasi dan pemrosesan serangan Nimons.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Memanggil fungsi utama dari modul NimonsAttack untuk menjalankan seluruh logika program.
    findAndReportNearbyShips();

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
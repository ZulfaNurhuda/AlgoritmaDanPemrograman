/**
 * --------------------------------------------------------------
 * | @file NimonsBruteforceDriver.c                             |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Driver program untuk menguji fungsi NimonsBruteforce.      |
 * | Membaca sebuah integer dan mencetak semua permutasi        |
 * | digitnya.                                                  |
 * --------------------------------------------------------------
 */

#include "NimonsBruteforce.h" // Menginclude header file yang berisi deklarasi fungsi
#include <stdio.h>           // Untuk scanf dan printf

/**
 * @brief Fungsi utama program.
 * @details Membaca sebuah bilangan integer dari input standar,
 *          kemudian memanggil fungsi `nimonBruteforce` untuk
 *          mencetak semua permutasi digit dari bilangan tersebut.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk menyimpan input dari pengguna.
    int inputNumber;

    // Membaca bilangan integer dari pengguna.
    // Diasumsikan input selalu valid (berupa integer).
    scanf("%d", &inputNumber);

    // Memanggil fungsi untuk menghasilkan dan mencetak permutasi digit.
    nimonBruteforce(inputNumber);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
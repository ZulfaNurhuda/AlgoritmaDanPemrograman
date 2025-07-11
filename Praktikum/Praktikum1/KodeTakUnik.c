/**
 * --------------------------------------------------------------
 * | @file KodeTakUnik.c                                        |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menghitung "kode tak unik" dari sebuah       |
 * | bilangan. Kode tak unik adalah hasil penjumlahan digit     |
 * | secara berulang hingga hasilnya menjadi satu digit.        |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Menghitung total dari semua digit dalam sebuah bilangan.
 * @param number Angka (long) yang digit-digitnya akan dijumlahkan.
 * @return long Total dari digit-digit angka tersebut.
 */
long sumOfDigits(long number)
{
    long totalSum = 0;

    // Loop selama angka masih memiliki digit (lebih besar dari 0).
    while (number > 0)
    {
        // Tambahkan digit terakhir ke total.
        totalSum += number % 10;
        // Hilangkan digit terakhir dari angka.
        number /= 10;
    }

    return totalSum;
}

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk kode awal dan kode tak unik.
    long initialCode;
    long nonUniqueCode;

    // Membaca input kode awal dari pengguna.
    scanf("%ld", &initialCode);

    // Proses untuk mendapatkan kode tak unik (satu digit).
    // Loop berjalan selama hasil penjumlahan digit masih lebih dari satu digit ( > 9).
    do
    {
        // Hitung total digit dari kode saat ini.
        nonUniqueCode = sumOfDigits(initialCode);
        // Jika hasilnya masih lebih dari satu digit,
        // maka hasil tersebut menjadi input untuk iterasi selanjutnya.
        if (nonUniqueCode > 9)
        {
            initialCode = nonUniqueCode;
        }
    } while (nonUniqueCode > 9);

    // Mencetak kode tak unik (hasil akhir yang berupa satu digit).
    printf("%ld\n", nonUniqueCode);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
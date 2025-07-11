/**
 * --------------------------------------------------------------
 * | @file AngkaPalindrom.c                                     |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk mengecek apakah sebuah bilangan bulat        |
 * | merupakan angka palindrom atau bukan.                      |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk menyimpan angka input dan angka yang akan dimanipulasi.
    int originalNumber;
    int manipulatedNumber;

    // Membaca input angka dari pengguna.
    scanf("%d", &originalNumber);

    // Salin angka asli ke variabel yang akan dimanipulasi untuk proses pembalikan.
    manipulatedNumber = originalNumber;
    // Variabel untuk menyimpan angka yang sudah dibalik.
    int reversedNumber = 0;

    // Proses membalikkan angka.
    // Loop berjalan selama manipulatedNumber masih memiliki digit (lebih besar dari 0).
    while (manipulatedNumber > 0)
    {
        // Mengambil digit terakhir dari manipulatedNumber.
        int digit = manipulatedNumber % 10;
        // Membangun angka terbalik dengan menambahkan digit terakhir.
        reversedNumber = reversedNumber * 10 + digit;
        // Menghapus digit terakhir dari manipulatedNumber.
        manipulatedNumber /= 10;
    }

    // Mengecek apakah angka asli sama dengan angka yang sudah dibalik.
    // Jika sama, maka itu adalah palindrom (hasil 1), jika tidak maka bukan (hasil 0).
    int isPalindrome = (originalNumber == reversedNumber) ? 1 : 0;

    // Mencetak hasil pengecekan (1 jika palindrom, 0 jika tidak).
    printf("%d\n", isPalindrome);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}

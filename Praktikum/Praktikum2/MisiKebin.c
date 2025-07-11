/**
 * --------------------------------------------------------------
 * | @file MisiKebin.c                                          |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menghitung jumlah bilangan prima dalam       |
 * | sebuah rentang [A, B] inklusif.                            |
 * --------------------------------------------------------------
 */

#include <stdio.h>
#include <stdbool.h> // Untuk menggunakan tipe data bool secara eksplisit jika diinginkan

/**
 * @brief Menghitung jumlah bilangan prima dalam rentang [rangeStart, rangeEnd].
 * @details Sebuah bilangan dianggap prima jika lebih besar dari 1 dan hanya habis
 *          dibagi oleh 1 dan dirinya sendiri.
 * @param rangeStart Batas bawah rentang (inklusif).
 * @param rangeEnd Batas atas rentang (inklusif).
 * @param[out] totalPrimes Pointer ke integer yang akan menyimpan jumlah total bilangan prima yang ditemukan.
 *                         Nilai yang ditunjuk oleh pointer ini akan diincrement setiap kali bilangan prima ditemukan.
 * @note I.S. : rangeStart, rangeEnd terdefinisi. totalPrimes adalah pointer valid ke integer yang sudah diinisialisasi (misal, ke 0).
 * @note F.S. : Integer yang ditunjuk oleh totalPrimes berisi jumlah bilangan prima dalam rentang [rangeStart, rangeEnd].
 */
void countPrimesInRange(int rangeStart, int rangeEnd, int *totalPrimes)
{
    // Loop melalui setiap angka dalam rentang yang diberikan.
    for (int number = rangeStart; number <= rangeEnd; number++)
    {
        bool isCurrentlyPrime = true; // Asumsikan angka saat ini prima.

        // Bilangan prima harus lebih besar dari 1.
        if (number <= 1)
        {
            isCurrentlyPrime = false;
        }
        else
        {
            // Cek pembagi dari 2 hingga akar kuadrat dari angka tersebut.
            // Jika ditemukan pembagi, angka tersebut bukan prima.
            for (int divisor = 2; divisor * divisor <= number; divisor++)
            {
                if (number % divisor == 0)
                {
                    isCurrentlyPrime = false;
                    break; // Tidak perlu cek pembagi lain.
                }
            }
        }
        
        // Jika angka tersebut terkonfirmasi prima, increment total.
        if (isCurrentlyPrime)
        {
            (*totalPrimes)++; // Perbarui nilai total melalui pointer.
        }
    }
}

/**
 * @brief Fungsi utama program.
 * @details Membaca dua bilangan integer A dan B sebagai batas rentang,
 *          kemudian menghitung dan mencetak jumlah bilangan prima
 *          dalam rentang [A, B].
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk batas bawah dan atas rentang.
    int rangeStartA, rangeEndB;
    // Variabel untuk menyimpan total bilangan prima, diinisialisasi ke 0.
    int primeCount = 0;

    // Membaca dua bilangan integer A (rangeStartA) dan B (rangeEndB) dari satu baris input.
    scanf("%d %d", &rangeStartA, &rangeEndB);

    // Memanggil prosedur untuk menghitung bilangan prima dalam rentang yang diberikan.
    // Alamat dari primeCount (&primeCount) dilewatkan agar nilainya dapat diubah oleh fungsi.
    countPrimesInRange(rangeStartA, rangeEndB, &primeCount);

    // Mencetak total bilangan prima yang ditemukan.
    printf("%d\n", primeCount);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
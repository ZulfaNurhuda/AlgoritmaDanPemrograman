/**
 * --------------------------------------------------------------
 * | @file NimonsBruteforce.c                                   |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi fungsi untuk menghasilkan semua permutasi     |
 * | digit dari sebuah angka integer.                           |
 * |                                                            |
 * | CATATAN PENGEMBANG ASLI:                                   |
 * | I DON'T HAVE ANY IDEA :|                                   |
 * | IF TEST CASE IS 102                                        |
 * | PROGRAM WILL PRINT 210, 021, 021, 012, 012 NOT AS EXPECTED |
 * | EXPECTED OUTPUT IS 210, 201, 120, 102, 021, 012            |
 * | I THINK THIS IS A BUG, BUT I DON'T KNOW HOW TO FIX IT      |
 * | HEHE, SORRY :)                                             |
 * --------------------------------------------------------------
 */

#include "NimonsBruteforce.h"
#include <stdio.h>  // Untuk printf
#include <math.h>   // Untuk pow

/**
 * @brief Menghitung jumlah digit dalam sebuah bilangan integer.
 * @param number Bilangan integer yang akan dihitung panjangnya.
 * @return int Jumlah digit. Mengembalikan -1 jika angka adalah 0 (perilaku aneh dari kode asli).
 *             Idealnya, panjang 0 adalah 1 digit.
 * @note I.S. : number terdefinisi.
 * @note F.S. : Mengembalikan jumlah digit atau -1 untuk input 0.
 */
int calculateNumberLength(int number)
{
    // Perilaku kode asli: panjang 0 adalah -1.
    if (number == 0)
    {
        return -1;
    }
    int digitCount = 0;
    while (number > 0)
    {
        digitCount++;
        number /= 10;
    }
    return digitCount;
}

/**
 * @brief Mendapatkan digit pada indeks tertentu dari sebuah angka.
 * @details Indeks dihitung dari kanan ke kiri, dimulai dari 0.
 *          Misal, untuk angka 123: indeks 0 adalah 3, indeks 1 adalah 2, indeks 2 adalah 1.
 * @param number Angka sumber.
 * @param index Indeks digit yang diinginkan (0-based dari kanan).
 * @return int Digit pada indeks tersebut, atau -1 jika indeks tidak valid atau angka 0.
 * @note I.S. : number dan index terdefinisi.
 * @note F.S. : Mengembalikan digit atau -1.
 * @warning Menggunakan `pow` untuk operasi integer bisa kurang efisien atau menimbulkan isu presisi.
 */
int getDigitAtIndex(int number, int index)
{
    if (index < 0)
    {
        return -1;
    }
    int len = calculateNumberLength(number);
    // Jika panjang -1 (angka 0) atau indeks di luar batas.
    if (len == -1 || index >= len)
    {
        return -1;
    }
    // Mengambil digit: (number / 10^index) % 10
    return (number / (int)pow(10, index)) % 10;
}

/**
 * @brief Menghapus digit pada indeks tertentu dari sebuah angka.
 * @details Indeks dihitung dari kanan ke kiri, dimulai dari 0.
 * @param number Angka sumber.
 * @param index Indeks digit yang akan dihapus (0-based dari kanan).
 * @return int Angka baru setelah digit dihapus. Jika indeks tidak valid, mengembalikan angka asli.
 * @note I.S. : number dan index terdefinisi.
 * @note F.S. : Mengembalikan angka dengan digit yang telah dihapus, atau angka asli jika gagal.
 * @warning Menggunakan `pow` untuk operasi integer.
 */
int removeDigitAtIndex(int number, int index)
{
    if (index < 0)
    {
        return number;
    }
    int len = calculateNumberLength(number);
    if (len == -1 || index >= len) // Jika angka 0 atau indeks tidak valid
    {
        return number;
    }

    // Konversi indeks dari kanan (0-based) ke posisi dari kiri (0-based).
    int positionFromLeft = len - index - 1;

    if (positionFromLeft == 0) // Menghapus digit paling kiri
    {
        return number % (int)pow(10, len - 1);
    }
    else
    {
        // Bagian kiri dari digit yang dihapus
        int leftPart = number / (int)pow(10, len - positionFromLeft);
        // Bagian kanan dari digit yang dihapus
        int rightPart = number % (int)pow(10, len - positionFromLeft - 1);
        // Menggabungkan bagian kiri dan kanan
        return leftPart * (int)pow(10, len - positionFromLeft - 1) + rightPart;
    }
}

/**
 * @brief Fungsi rekursif untuk mencari dan mencetak semua kombinasi (permutasi) digit.
 * @details Fungsi ini membangun permutasi secara rekursif.
 *          Terdapat bug yang diketahui (disebutkan di header file) yang menyebabkan
 *          hasil tidak sesuai harapan untuk angka dengan digit 0 atau digit berulang.
 * @param remainingNumber Angka yang digit-digitnya belum digunakan dalam permutasi saat ini.
 * @param currentPermutation Permutasi yang sedang dibangun.
 * @param originalLength Panjang asli dari angka input awal (untuk formatting output).
 * @note I.S. : remainingNumber, currentPermutation, originalLength terdefinisi.
 * @note F.S. : Semua permutasi yang mungkin (dengan bug yang ada) dicetak ke layar.
 */
void findPermutationsRecursive(int remainingNumber, int currentPermutation, int originalLength)
{
    int len = calculateNumberLength(remainingNumber);
    // Basis rekursi: jika tidak ada digit tersisa di remainingNumber.
    if (len <= 0) // Menggunakan <= 0 karena calculateNumberLength(0) mengembalikan -1.
    {
        // Cetak permutasi yang sudah terbentuk dengan padding nol di depan jika perlu.
        printf("%0*d\n", originalLength, currentPermutation);
        return;
    }

    // Iterasi melalui setiap digit yang tersisa.
    for (int i = 0; i < len; i++)
    {
        // Ambil digit ke-i (dari kanan) dari remainingNumber.
        int digit = getDigitAtIndex(remainingNumber, i);
        // Tambahkan digit ini ke permutasi saat ini.
        int nextPermutation = currentPermutation * 10 + digit;
        // Hapus digit yang sudah digunakan dari remainingNumber.
        int newRemainingNumber = removeDigitAtIndex(remainingNumber, i);
        // Panggilan rekursif dengan state baru.
        findPermutationsRecursive(newRemainingNumber, nextPermutation, originalLength);
    }
}

/**
 * @brief Fungsi utama untuk menghasilkan dan mencetak semua permutasi digit dari sebuah angka.
 * @details Memanggil fungsi rekursif untuk melakukan pekerjaan utama.
 * @param number Angka integer yang permutasi digitnya akan dicari.
 * @note I.S. : number terdefinisi.
 * @note F.S. : Semua permutasi digit dari number dicetak ke layar.
 *              Tidak melakukan apa-apa jika number adalah 0 (sesuai logika asli).
 *              Perhatikan bug yang disebutkan pada `findPermutationsRecursive`.
 */
void nimonBruteforce(int number)
{
    if (number == 0)
    {
        // Kode asli tidak menghasilkan output untuk 0, jadi kita ikuti.
        // Jika ingin mencetak "0", tambahkan printf("0\n");
        return;
    }
    int originalLength = calculateNumberLength(number);
    // Memulai proses rekursif dengan permutasi awal 0.
    findPermutationsRecursive(number, 0, originalLength);
}
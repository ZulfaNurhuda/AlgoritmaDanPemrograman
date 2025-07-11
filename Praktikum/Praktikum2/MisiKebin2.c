/**
 * --------------------------------------------------------------
 * | @file MisiKebin2.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk mencari bilangan "spesial" dalam rentang     |
 * | [A, B]. Bilangan spesial adalah bilangan prima yang hasil   |
 * | penjumlahan digit-digitnya juga merupakan bilangan prima.  |
 * | Hasil akhir (jumlah bilangan spesial) dikonversi ke        |
 * | representasi "Bingro" (representasi biner terbalik).       |
 * --------------------------------------------------------------
 */

#include <stdio.h>
#include <stdbool.h> // Untuk tipe data bool pada isPrimeNumber

/**
 * @brief Menghitung jumlah dari digit-digit sebuah bilangan integer.
 * @param number Bilangan integer yang akan dihitung jumlah digitnya.
 * @return int Jumlah dari digit-digit bilangan tersebut.
 * @note I.S. : number adalah bilangan integer positif.
 * @note F.S. : Mengembalikan hasil penjumlahan semua digit dari number.
 */
int sumOfDigits(int number)
{
    int sum = 0;
    // Loop selama number masih memiliki digit.
    while (number > 0)
    {
        sum += number % 10; // Tambahkan digit terakhir ke sum.
        number /= 10;     // Hilangkan digit terakhir.
    }
    return sum;
}

/**
 * @brief Memeriksa apakah sebuah bilangan adalah bilangan prima.
 * @param number Bilangan integer yang akan diperiksa.
 * @return bool Mengembalikan true jika number adalah prima, false jika bukan.
 * @note I.S. : number terdefinisi.
 * @note F.S. : Mengembalikan status keprimaan dari number.
 */
bool isPrimeNumber(int number)
{
    // Bilangan prima harus lebih besar dari 1.
    if (number <= 1)
    {
        return false;
    }
    // Cek pembagi dari 2 hingga akar kuadrat dari number.
    for (int divisor = 2; divisor * divisor <= number; divisor++)
    {
        if (number % divisor == 0)
        {
            return false; // Ditemukan pembagi, bukan prima.
        }
    }
    return true; // Tidak ditemukan pembagi selain 1 dan dirinya sendiri.
}

/**
 * @brief Menghitung jumlah bilangan "spesial" dalam rentang [rangeStart, rangeEnd].
 * @details Bilangan spesial adalah bilangan prima yang hasil penjumlahan digit-digitnya
 *          juga merupakan bilangan prima.
 * @param rangeStart Batas bawah rentang (inklusif).
 * @param rangeEnd Batas atas rentang (inklusif).
 * @return int Jumlah total bilangan spesial yang ditemukan dalam rentang.
 * @note I.S. : rangeStart dan rangeEnd terdefinisi.
 * @note F.S. : Mengembalikan jumlah bilangan spesial.
 */
int countSpecialPrimesInRange(int rangeStart, int rangeEnd)
{
    int specialPrimeCount = 0; // Inisialisasi penghitung bilangan spesial.
    // Loop melalui setiap angka dalam rentang yang diberikan.
    for (int currentNumber = rangeStart; currentNumber <= rangeEnd; currentNumber++)
    {
        // Cek apakah angka saat ini prima DAN jumlah digitnya juga prima.
        if (isPrimeNumber(currentNumber) && isPrimeNumber(sumOfDigits(currentNumber)))
        {
            specialPrimeCount++;
        }
    }
    return specialPrimeCount;
}

/**
 * @brief Mengonversi bilangan desimal ke representasi "Bingro".
 * @details Representasi Bingro adalah representasi biner dari bilangan,
 *          namun digit-digit binernya dibaca terbalik dan disusun sebagai angka desimal.
 *          Contoh: 5 (desimal) = 101 (biner). Bingro = 101 (desimal, dari biner 101 dibaca terbalik).
 *                   6 (desimal) = 110 (biner). Bingro = 011 -> 11 (desimal, dari biner 011 dibaca terbalik).
 * @param decimalNumber Bilangan desimal integer yang akan dikonversi.
 * @return long long Representasi Bingro dari decimalNumber.
 * @note I.S. : decimalNumber adalah integer non-negatif.
 * @note F.S. : Mengembalikan representasi Bingro.
 */
long long convertToBingroRepresentation(int decimalNumber)
{
    long long bingroResult = 0;
    long long multiplier = 1; // Untuk menempatkan digit biner pada posisi yang benar

    if (decimalNumber == 0) {
        return 0; // Kasus khusus untuk input 0
    }

    // Proses konversi ke biner dan membangun representasi Bingro (biner terbalik)
    // Algoritma asli di soal menghasilkan biner yang digitnya dibaca dari kanan ke kiri
    // lalu disusun menjadi angka desimal.
    // Contoh: 6 (110_bin) -> 0*1 + 1*10 + 1*100 = 110. Ini biner biasa jika dibaca sbg desimal.
    // Jika maksudnya adalah digit biner dibalik: 6 (110_bin) -> 011_bin -> 11_desimal.
    // Kode asli: bingro = bingro * 10 + n % 2; ini membangun angka desimal dari digit biner terbalik.
    // Misal n=6 (110):
    // iter 1: n=6, rem=0, bingro=0*10+0=0, n=3
    // iter 2: n=3, rem=1, bingro=0*10+1=1, n=1
    // iter 3: n=1, rem=1, bingro=1*10+1=11, n=0
    // Hasil untuk 6 adalah 11. Ini sesuai dengan pembalikan digit biner (011 -> 11).

    // Implementasi sesuai logika kode asli yang menghasilkan digit biner terbalik sebagai angka desimal.
    long long tempBingro = 0;
    int tempDecimalNumber = decimalNumber;
    while (tempDecimalNumber > 0)
    {
        tempBingro = tempBingro * 10 + (tempDecimalNumber % 2);
        tempDecimalNumber /= 2;
    }

    // Membalikkan tempBingro untuk mendapatkan urutan yang benar jika interpretasi "Bingro"
    // adalah biner yang dibaca dari kiri ke kanan tapi digitnya disusun jadi desimal.
    // Namun, berdasarkan output contoh dan logika kode asli, sepertinya `tempBingro` sudah hasil akhir.
    // Kita ikuti logika kode asli.
    bingroResult = tempBingro;


    return bingroResult;
}

/**
 * @brief Fungsi utama program.
 * @details Membaca rentang [A, B], menghitung jumlah bilangan spesial,
 *          mengonversi jumlah tersebut ke representasi Bingro, dan mencetaknya.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk batas rentang dan hasil perhitungan.
    int rangeStartA, rangeEndB;
    int specialPrimeCountResult;
    long long bingroRepresentation;

    // Membaca input rentang [A, B] dari pengguna.
    scanf("%d %d", &rangeStartA, &rangeEndB);

    // Menghitung jumlah bilangan spesial dalam rentang.
    specialPrimeCountResult = countSpecialPrimesInRange(rangeStartA, rangeEndB);

    // Mengonversi jumlah bilangan spesial ke representasi Bingro.
    bingroRepresentation = convertToBingroRepresentation(specialPrimeCountResult);

    // Mencetak hasil representasi Bingro.
    printf("%lld\n", bingroRepresentation);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
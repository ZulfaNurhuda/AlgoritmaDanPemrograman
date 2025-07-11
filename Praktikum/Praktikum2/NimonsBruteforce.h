/**
 * --------------------------------------------------------------
 * | @file NimonsBruteforce.h                                   |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Header file untuk fungsi-fungsi yang berkaitan dengan      |
 * | pembuatan permutasi digit dari sebuah angka integer.       |
 * | Termasuk fungsi utilitas untuk menghitung panjang angka,   |
 * | mendapatkan digit, dan menghapus digit.                    |
 * |                                                            |
 * | CATATAN PENGEMBANG ASLI (dari .c):                         |
 * | Terdapat bug yang diketahui pada logika permutasi,         |
 * | terutama untuk angka dengan digit 0 atau digit berulang.   |
 * | Contoh: input 102 menghasilkan output yang tidak sesuai    |
 * | harapan (misal, duplikasi atau format salah).              |
 * | Output yang diharapkan: 210, 201, 120, 102, 021, 012.      |
 * | Output aktual mungkin: 210, 021, 021, 012, 012.            |
 * --------------------------------------------------------------
 */

#ifndef NIMONSBRUTEFORCE_H
#define NIMONSBRUTEFORCE_H

// Tidak perlu include <math.h> dan <stdio.h> di file header jika hanya untuk deklarasi.
// Ini adalah praktik yang baik untuk mengurangi dependensi dan waktu kompilasi.
// Jika tipe data dari library tersebut digunakan (seperti FILE*), maka perlu.

/**
 * @brief Menghitung jumlah digit dalam sebuah bilangan integer.
 * @param number Bilangan integer yang akan dihitung panjangnya.
 * @return int Jumlah digit. Mengembalikan -1 jika `number` adalah 0 (perilaku dari kode implementasi asli).
 * @note I.S. : `number` terdefinisi.
 * @note F.S. : Mengembalikan jumlah digit dari `number`.
 */
int calculateNumberLength(int number);

/**
 * @brief Mendapatkan digit pada indeks tertentu dari sebuah angka (0-based dari kanan).
 * @details Indeks dihitung dari digit paling kanan (indeks 0).
 *          Contoh: untuk angka 123, `getDigitAtIndex(123, 0)` -> 3, `getDigitAtIndex(123, 1)` -> 2.
 * @param number Angka integer sumber.
 * @param index Indeks digit yang diinginkan (0-based dari kanan).
 * @return int Digit pada indeks tersebut. Mengembalikan -1 jika `index` tidak valid
 *             atau jika `number` adalah 0 (berdasarkan perilaku `calculateNumberLength`).
 * @note I.S. : `number` dan `index` terdefinisi.
 * @note F.S. : Mengembalikan digit yang diminta atau -1 jika tidak valid.
 */
int getDigitAtIndex(int number, int index);

/**
 * @brief Menghapus digit pada indeks tertentu dari sebuah angka (0-based dari kanan).
 * @details Contoh: `removeDigitAtIndex(1234, 1)` (menghapus digit '3') akan menghasilkan 124.
 *          Indeks dihitung dari digit paling kanan (indeks 0).
 * @param number Angka integer sumber.
 * @param index Indeks digit yang akan dihapus.
 * @return int Angka baru setelah digit pada `index` dihapus.
 *             Mengembalikan `number` asli jika `index` tidak valid.
 * @note I.S. : `number` dan `index` terdefinisi.
 * @note F.S. : Mengembalikan angka dengan digit yang telah dihapus, atau angka asli jika `index` tidak valid.
 */
int removeDigitAtIndex(int number, int index);

/**
 * @brief Fungsi rekursif pembantu untuk menghasilkan dan mencetak semua permutasi digit.
 * @details Fungsi ini tidak dimaksudkan untuk dipanggil langsung oleh pengguna ADT,
 *          melainkan sebagai helper untuk `nimonBruteforce`.
 *          Perhatikan bahwa fungsi ini memiliki bug yang diketahui (lihat catatan di atas file).
 * @param remainingNumber Angka yang digit-digitnya belum digunakan dalam permutasi saat ini.
 * @param currentPermutation Permutasi angka yang sedang dibangun.
 * @param originalLength Panjang asli dari angka input awal (digunakan untuk formatting output).
 * @note I.S. : `remainingNumber`, `currentPermutation`, `originalLength` terdefinisi.
 * @note F.S. : Semua permutasi yang mungkin dari `remainingNumber` (dengan bug yang ada)
 *              dicetak ke layar, diawali dengan `currentPermutation` dan diformat
 *              sesuai `originalLength`.
 */
void findPermutationsRecursive(int remainingNumber, int currentPermutation, int originalLength);

/**
 * @brief Menghasilkan dan mencetak semua permutasi digit dari sebuah angka integer.
 * @details Fungsi ini menginisialisasi pemanggilan ke fungsi rekursif `findPermutationsRecursive`.
 * @param number Angka integer yang permutasi digitnya akan dicari dan dicetak.
 * @note I.S. : `number` terdefinisi.
 * @note F.S. : Semua permutasi digit dari `number` dicetak ke standar output, satu per baris.
 *              Jika `number` adalah 0, tidak ada output yang dihasilkan (sesuai implementasi asli).
 *              Fungsi ini mewarisi bug dari `findPermutationsRecursive`.
 */
void nimonBruteforce(int number);

#endif // NIMONSBRUTEFORCE_H
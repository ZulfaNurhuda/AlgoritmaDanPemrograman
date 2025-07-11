/**
 * --------------------------------------------------------------
 * | @file polynomialDriver.example.c                           |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Contoh program driver untuk menguji fungsionalitas ADT     |
 * | Polinomial. Program ini akan membaca dua polinomial,       |
 * | melakukan operasi penjumlahan, perkalian, turunan, dan     |
 * | evaluasi, kemudian mencetak hasilnya.                      |
 * --------------------------------------------------------------
 */

#include "polynomial.h" // Menginclude header file ADT Polynomial
#include <stdio.h>      // Untuk printf (meskipun ReadPolynomial dan WritePolynomial sudah menggunakannya)

/**
 * @brief Fungsi utama program driver.
 * @details Menjalankan serangkaian tes pada ADT Polynomial:
 *          1. Membaca dua polinomial (P1 dan P2) dari input pengguna.
 *          2. Mencetak P1 dan P2.
 *          3. Menghitung dan mencetak P1 + P2.
 *          4. Menghitung dan mencetak P1 * P2.
 *          5. Menghitung dan mencetak turunan pertama dari P1 (P1').
 *          6. Menghitung dan mencetak turunan pertama dari P2 (P2').
 *          7. Mengevaluasi dan mencetak P1(2).
 *          8. Mengevaluasi dan mencetak P2(2).
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Deklarasi dua buah polinomial.
    Polynomial polynomial1, polynomial2;

    // Membaca polinomial pertama dari input pengguna.
    printf("Input P1:\n");
    // printf("degree = "); // Komentar ini bisa diaktifkan jika ReadPolynomial tidak mencetak prompt sendiri.
                         // Asumsi ReadPolynomial sudah menangani prompt input derajat.
    ReadPolynomial(&polynomial1);

    // Membaca polinomial kedua dari input pengguna.
    printf("Input P2:\n");
    // printf("degree = ");
    ReadPolynomial(&polynomial2);

    // Mencetak kedua polinomial yang sudah dibaca.
    printf("P1: ");
    WritePolynomial(polynomial1);

    printf("P2: ");
    WritePolynomial(polynomial2);

    // Menjumlahkan P1 dan P2, lalu mencetak hasilnya.
    Polynomial sumResult = AddPolynomial(polynomial1, polynomial2);
    printf("P1 + P2: ");
    WritePolynomial(sumResult);

    // Mengalikan P1 dan P2, lalu mencetak hasilnya.
    Polynomial productResult = MultiplyPolynomial(polynomial1, polynomial2);
    printf("P1 * P2: ");
    WritePolynomial(productResult);

    // Menghitung turunan pertama dari P1, lalu mencetak hasilnya.
    Polynomial derivativeP1 = DerivativePolynomial(polynomial1);
    printf("(d/dx) P1: ");
    WritePolynomial(derivativeP1);

    // Menghitung turunan pertama dari P2, lalu mencetak hasilnya.
    Polynomial derivativeP2 = DerivativePolynomial(polynomial2);
    printf("(d/dx) P2: ");
    WritePolynomial(derivativeP2);

    // Mengevaluasi P1 pada x=2 dan P2 pada x=2, lalu mencetak hasilnya.
    printf("P1(2) = %d\n", EvaluatePolynomial(polynomial1, 2));
    printf("P2(2) = %d\n", EvaluatePolynomial(polynomial2, 2));

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
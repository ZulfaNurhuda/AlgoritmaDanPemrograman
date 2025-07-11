/**
 * --------------------------------------------------------------
 * | @file polynomial.h                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Header file untuk Abstract Data Type (ADT) Polinomial.     |
 * | Mendefinisikan struktur data Polinomial dan prototipe      |
 * | fungsi untuk operasi-operasi dasar polinomial.             |
 * --------------------------------------------------------------
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

// Sebaiknya hanya include yang benar-benar dibutuhkan untuk deklarasi di header.
// stdio.h, stdlib.h, math.h lebih cocok di .c jika hanya untuk implementasi.
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

/* ***************************************************** */
/* ********************** KONSTANTA ******************** */
/* ***************************************************** */

#define MAX_DEGREE 100 // Derajat maksimum polinomial yang bisa disimpan.

/* ***************************************************** */
/* ********************** TIPE DATA ******************** */
/* ***************************************************** */

/**
 * @struct Polynomial
 * @brief Merepresentasikan sebuah polinomial P(x) = a_n*x^n + ... + a_1*x + a_0.
 * @details
 *   - `degree`: Derajat tertinggi polinomial (n) yang koefisiennya non-nol.
 *   - `coef`: Array yang menyimpan koefisien. `coef[i]` adalah koefisien untuk x^i.
 *             Array berukuran `MAX_DEGREE + 1` untuk menyimpan koefisien dari x^0 hingga x^MAX_DEGREE.
 */
typedef struct Polynomial // Memberi nama pada struct untuk kejelasan
{
    int degree;               /**< Derajat polinomial (pangkat tertinggi dengan koefisien non-nol). */
    int coef[MAX_DEGREE + 1]; /**< Array koefisien, coef[i] adalah koefisien x^i. */
} Polynomial;

/* ***************************************************** */
/* ******************** KONSTRUKTOR ******************** */
/* ***************************************************** */

/**
 * @brief Menginisialisasi sebuah polinomial dengan derajat tertentu dan semua koefisien nol.
 * @param polynomial Pointer ke `Polynomial` yang akan diinisialisasi.
 * @param degree Derajat dari polinomial yang akan dibuat.
 * @note I.S. : `polynomial` adalah pointer valid, `degree` terdefinisi (diasumsikan <= MAX_DEGREE).
 * @note F.S. : `polynomial->degree` diisi dengan `degree`, dan semua `polynomial->coef[i]` diisi 0.
 */
void CreatePolynomial(Polynomial *polynomial, int degree);

/* ***************************************************** */
/* *************** INPUT/OUTPUT POLINOMIAL ************* */
/* ***************************************************** */

/**
 * @brief Membaca data polinomial dari input standar.
 * @details Pertama membaca derajat, kemudian koefisien dari x^0 hingga x^derajat.
 *          Contoh input untuk 3x^2 + 2x + 1:
 *          2 (derajat)
 *          1 (koef x^0)
 *          2 (koef x^1)
 *          3 (koef x^2)
 * @param polynomial Pointer ke `Polynomial` yang akan diisi.
 * @note I.S. : `polynomial` adalah pointer valid.
 * @note F.S. : `polynomial` terisi berdasarkan input pengguna.
 */
void ReadPolynomial(Polynomial *polynomial);

/**
 * @brief Menulis (mencetak) representasi string dari polinomial ke output standar.
 * @details Format: `ax^n + bx^(n-1) - cx + d`. Suku dengan koefisien 0 tidak dicetak.
 *          Menangani kasus khusus untuk koefisien 1/-1 dan pangkat 0/1.
 * @param polynomial Polinomial yang akan dicetak.
 * @note I.S. : `polynomial` terdefinisi.
 * @note F.S. : Representasi string polinomial dicetak, diakhiri newline.
 */
void WritePolynomial(Polynomial polynomial);

/* ***************************************************** */
/* *********** OPERASI ARITMATIKA POLINOMIAL *********** */
/* ***************************************************** */

/**
 * @brief Menjumlahkan dua polinomial.
 * @param polynomial1 Polinomial pertama.
 * @param polynomial2 Polinomial kedua.
 * @return Polynomial Hasil penjumlahan `polynomial1` + `polynomial2`.
 * @note I.S. : `polynomial1` dan `polynomial2` terdefinisi.
 * @note F.S. : Mengembalikan polinomial baru. Derajat hasil disesuaikan.
 */
Polynomial AddPolynomial(Polynomial polynomial1, Polynomial polynomial2);

/**
 * @brief Mengalikan dua polinomial.
 * @param polynomial1 Polinomial pertama.
 * @param polynomial2 Polinomial kedua.
 * @return Polynomial Hasil perkalian `polynomial1` * `polynomial2`.
 * @note I.S. : `polynomial1` dan `polynomial2` terdefinisi.
 * @note F.S. : Mengembalikan polinomial baru. Derajat hasil adalah sum dari derajat input.
 */
Polynomial MultiplyPolynomial(Polynomial polynomial1, Polynomial polynomial2);

/* ***************************************************** */
/* *************** OPERASI LAIN POLINOMIAL ************* */
/* ***************************************************** */

/**
 * @brief Mengevaluasi nilai polinomial P pada suatu nilai integer x.
 * @param polynomial Polinomial yang akan dievaluasi.
 * @param x Nilai integer untuk substitusi.
 * @return int Hasil evaluasi P(x).
 * @note I.S. : `polynomial` dan `x` terdefinisi.
 * @note F.S. : Mengembalikan P(x).
 */
int EvaluatePolynomial(Polynomial polynomial, int x);

/**
 * @brief Menghitung turunan pertama dari sebuah polinomial.
 * @details Jika P(x) = a_n*x^n + ... + a_0, maka P'(x) = n*a_n*x^(n-1) + ... + a_1.
 *          Turunan dari konstanta adalah 0.
 * @param polynomial Polinomial yang akan diturunkan.
 * @return Polynomial Polinomial baru yang merupakan turunan pertama.
 * @note I.S. : `polynomial` terdefinisi.
 * @note F.S. : Mengembalikan turunan P'(x).
 */
Polynomial DerivativePolynomial(Polynomial polynomial);

#endif // POLYNOMIAL_H
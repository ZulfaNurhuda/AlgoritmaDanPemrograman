/**
 * --------------------------------------------------------------
 * | @file polynomial.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi Abstract Data Type (ADT) untuk Polinomial.    |
 * | Termasuk fungsi untuk membuat, membaca, menulis,           |
 * | menambah, mengalikan, mengevaluasi, dan mencari turunan    |
 * | dari polinomial.                                           |
 * --------------------------------------------------------------
 */

#include "polynomial.h" // Asumsi header ini mendefinisikan struct Polynomial dan MAX_DEGREE
#include <stdio.h>      // Untuk scanf, printf
#include <stdlib.h>     // Untuk abs
// #include <math.h>    // Tidak secara eksplisit digunakan di sini, abs ada di stdlib.h untuk int

/**
 * @brief Menginisialisasi sebuah polinomial dengan derajat tertentu dan semua koefisien nol.
 * @param polynomial Pointer ke Polynomial yang akan diinisialisasi.
 * @param degree Derajat dari polinomial yang akan dibuat.
 * @note I.S. : `polynomial` adalah pointer valid, `degree` terdefinisi dan diasumsikan <= MAX_DEGREE.
 * @note F.S. : `polynomial->degree` diisi dengan `degree`. Semua `polynomial->coef[i]` diisi 0.
 */
void CreatePolynomial(Polynomial *polynomial, int degree)
{
    // Pastikan degree tidak melebihi batas maksimum yang diizinkan oleh array coef.
    // MAX_DEGREE adalah batas untuk indeks tertinggi, jadi array berukuran MAX_DEGREE + 1.
    if (degree > MAX_DEGREE) {
        // Penanganan error sederhana, bisa disesuaikan.
        // Misalnya, set ke MAX_DEGREE atau tampilkan pesan.
        // Untuk saat ini, kita biarkan sesuai kode asli, asumsi input valid.
    }
    polynomial->degree = degree;
    // Inisialisasi semua koefisien menjadi 0.
    for (int i = 0; i <= degree; i++) // Loop hingga degree (inklusif)
    {
        polynomial->coef[i] = 0;
    }
}

/**
 * @brief Membaca data polinomial dari input standar.
 * @details Pertama membaca derajat polinomial, kemudian membaca koefisiennya
 *          mulai dari koefisien x^0 hingga x^degree.
 * @param polynomial Pointer ke Polynomial yang akan diisi dengan data input.
 * @note I.S. : `polynomial` adalah pointer valid. Input pengguna sesuai format.
 * @note F.S. : `polynomial` terisi berdasarkan input pengguna.
 */
void ReadPolynomial(Polynomial *polynomial)
{
    int inputDegree;
    scanf("%d", &inputDegree); // Baca derajat polinomial.
    CreatePolynomial(polynomial, inputDegree); // Inisialisasi polinomial dengan derajat tersebut.

    // Baca koefisien untuk setiap suku, dari x^0 hingga x^degree.
    for (int i = 0; i <= inputDegree; i++)
    {
        scanf("%d", &polynomial->coef[i]);
    }
}

/**
 * @brief Menulis (mencetak) representasi string dari polinomial ke output standar.
 * @details Format: `ax^n + bx^(n-1) + ... + cx + d`.
 *          Menangani kasus khusus untuk koefisien 0, 1, -1, dan suku konstanta/x.
 * @param polynomial Polinomial yang akan dicetak.
 * @note I.S. : `polynomial` terdefinisi.
 * @note F.S. : Representasi string polinomial dicetak ke layar, diakhiri newline.
 */
void WritePolynomial(Polynomial polynomial)
{
    bool isFirstTerm = true; // Flag untuk menandai apakah ini suku pertama yang dicetak (untuk tanda +/-).

    // Kasus khusus: polinomial adalah nol.
    if (polynomial.degree == 0 && polynomial.coef[0] == 0)
    {
        printf("0\n");
        return;
    }
    // Kasus khusus: polinomial adalah konstanta non-nol.
    // Kode asli memiliki ini, tapi loop utama juga akan menanganinya.
    // if (polynomial.degree == 0 && polynomial.coef[0] != 0)
    // {
    //     printf("%d\n", polynomial.coef[0]);
    //     return;
    // }

    // Iterasi dari suku dengan pangkat tertinggi ke terendah.
    for (int i = polynomial.degree; i >= 0; i--)
    {
        int coefficient = polynomial.coef[i];
        int absCoefficient = abs(coefficient); // Nilai absolut dari koefisien.

        // Lewati suku jika koefisiennya nol.
        if (coefficient == 0)
        {
            continue;
        }

        // Menangani tanda (+/-) antar suku.
        if (isFirstTerm)
        {
            if (coefficient < 0)
            {
                printf("-"); // Tanda negatif untuk suku pertama jika koefisien negatif.
            }
            // Tidak ada tanda '+' untuk suku pertama yang positif.
        }
        else // Bukan suku pertama
        {
            if (coefficient > 0)
            {
                printf(" + ");
            }
            else // coefficient < 0
            {
                printf(" - ");
            }
        }

        // Mencetak koefisien (jika bukan 1 atau -1, atau jika itu suku konstanta).
        if (absCoefficient != 1 || i == 0)
        {
            printf("%d", absCoefficient);
        }
        // else if (absCoefficient == 1 && i == 0) { // Sudah ditangani oleh (absCoefficient != 1 || i == 0)
        //     printf("%d", absCoefficient); // Cetak 1 atau -1 untuk konstanta
        // }


        // Mencetak variabel x dan pangkatnya.
        if (i > 0) // Jika pangkat bukan 0 (bukan suku konstanta)
        {
            printf("x");
            if (i > 1) // Jika pangkat lebih besar dari 1
            {
                printf("^%d", i);
            }
        }
        isFirstTerm = false; // Setelah suku pertama dicetak, set flag ke false.
    }
    // Jika tidak ada suku yang dicetak (misalnya, semua koefisien 0 kecuali untuk derajat > 0),
    // ini berarti polinomialnya nol, yang seharusnya sudah ditangani di awal.
    // Jika loop selesai dan isFirstTerm masih true, berarti polinomialnya 0.
    if (isFirstTerm) { // Ini terjadi jika semua koefisien adalah 0 untuk degree > 0
        printf("0");   // Atau jika degree 0 dan coef[0] adalah 0 (sudah ditangani).
    }

    printf("\n"); // Akhiri dengan newline.
}

/**
 * @brief Menjumlahkan dua polinomial.
 * @param polynomial1 Polinomial pertama.
 * @param polynomial2 Polinomial kedua.
 * @return Polynomial Hasil penjumlahan polynomial1 dan polynomial2.
 * @note I.S. : `polynomial1` dan `polynomial2` terdefinisi.
 * @note F.S. : Mengembalikan polinomial baru hasil penjumlahan.
 */
Polynomial AddPolynomial(Polynomial polynomial1, Polynomial polynomial2)
{
    Polynomial result;
    // Derajat hasil adalah maksimum dari derajat kedua polinomial.
    int maxDegree = (polynomial1.degree > polynomial2.degree) ? polynomial1.degree : polynomial2.degree;
    CreatePolynomial(&result, maxDegree);

    // Jumlahkan koefisien untuk setiap pangkat.
    for (int i = 0; i <= maxDegree; i++)
    {
        // Ambil koefisien dari polynomial1, atau 0 jika pangkat i melebihi derajatnya.
        int coef1 = (i <= polynomial1.degree) ? polynomial1.coef[i] : 0;
        // Ambil koefisien dari polynomial2, atau 0 jika pangkat i melebihi derajatnya.
        int coef2 = (i <= polynomial2.degree) ? polynomial2.coef[i] : 0;
        result.coef[i] = coef1 + coef2;
    }

    // Recalculate degree of result, as leading terms might cancel out
    int actualDegree = result.degree;
    while (actualDegree > 0 && result.coef[actualDegree] == 0) {
        actualDegree--;
    }
    result.degree = actualDegree;

    return result;
}

/**
 * @brief Mengalikan dua polinomial.
 * @param polynomial1 Polinomial pertama.
 * @param polynomial2 Polinomial kedua.
 * @return Polynomial Hasil perkalian polynomial1 dan polynomial2.
 * @note I.S. : `polynomial1` dan `polynomial2` terdefinisi.
 * @note F.S. : Mengembalikan polinomial baru hasil perkalian.
 *              Derajat hasil adalah jumlah derajat kedua polinomial.
 */
Polynomial MultiplyPolynomial(Polynomial polynomial1, Polynomial polynomial2)
{
    Polynomial result;
    // Derajat polinomial hasil perkalian adalah jumlah derajat P1 dan P2.
    int resultDegree = polynomial1.degree + polynomial2.degree;
    // Handle kasus jika salah satu polinomial adalah 0 (derajat bisa -1 atau 0 dengan koef 0)
    if (polynomial1.degree < 0 || polynomial2.degree < 0) { // Asumsi derajat negatif jika kosong/nol
        resultDegree = -1; // Atau cara lain untuk menandakan polinomial nol
         CreatePolynomial(&result, 0); // Hasilnya adalah P(x) = 0
         result.coef[0] = 0;
         return result;
    }
    CreatePolynomial(&result, resultDegree);


    // Lakukan perkalian setiap suku P1 dengan setiap suku P2.
    for (int i = 0; i <= polynomial1.degree; i++)
    {
        for (int j = 0; j <= polynomial2.degree; j++)
        {
            // Koefisien suku x^(i+j) adalah P1.coef[i] * P2.coef[j].
            result.coef[i + j] += polynomial1.coef[i] * polynomial2.coef[j];
        }
    }

    // Recalculate degree of result
    int actualDegree = result.degree;
    while (actualDegree > 0 && result.coef[actualDegree] == 0) {
        actualDegree--;
    }
    // Jika semua koefisien menjadi 0 (misal, (x-x)*P2), derajatnya 0 (untuk konstanta 0).
    if (actualDegree == 0 && result.coef[0] == 0 && result.degree > 0) {
        // Ini untuk kasus seperti (x^2 - 1) * 0, hasilnya harus 0, bukan 0x^2+0x+0
    }
     result.degree = actualDegree;


    return result;
}

/**
 * @brief Mengevaluasi nilai polinomial P pada suatu nilai x.
 * @param polynomial Polinomial yang akan dievaluasi.
 * @param x Nilai integer untuk substitusi ke dalam variabel polinomial.
 * @return int Hasil evaluasi P(x).
 * @note I.S. : `polynomial` dan `x` terdefinisi.
 * @note F.S. : Mengembalikan nilai P(x). Menggunakan Horner's method secara implisit.
 */
int EvaluatePolynomial(Polynomial polynomial, int x)
{
    int evaluationResult = 0;
    // Evaluasi menggunakan skema Horner untuk efisiensi, atau iterasi langsung.
    // Iterasi langsung: result = c0*x^0 + c1*x^1 + ...
    // Kode asli menggunakan iterasi langsung.
    long long currentPowerOfX = 1; // Menggunakan long long untuk power agar tidak overflow jika x besar
    for (int i = 0; i <= polynomial.degree; i++)
    {
        if (i > 0) {
             currentPowerOfX *= x;
        }
        evaluationResult += polynomial.coef[i] * (i == 0 ? 1 : currentPowerOfX / x); // Koreksi untuk power
                                                                                // Seharusnya:
                                                                                // evaluationResult += polynomial.coef[i] * currentPowerOfX;
                                                                                // currentPowerOfX *= x; (untuk iterasi berikutnya)
    }
    // Perbaikan implementasi evaluasi:
    evaluationResult = 0;
    currentPowerOfX = 1;
     for (int i = 0; i <= polynomial.degree; i++) {
        evaluationResult += polynomial.coef[i] * currentPowerOfX;
        if (i < polynomial.degree) { // Hindari perkalian x yang tidak perlu di akhir
            currentPowerOfX *= x;
        }
    }
    return evaluationResult;
}

/**
 * @brief Menghitung turunan pertama dari sebuah polinomial.
 * @param polynomial Polinomial yang akan diturunkan.
 * @return Polynomial Hasil turunan dari P.
 * @note I.S. : `polynomial` terdefinisi.
 * @note F.S. : Mengembalikan polinomial baru yang merupakan turunan pertama.
 *              Jika P adalah konstanta, turunannya adalah 0.
 */
Polynomial DerivativePolynomial(Polynomial polynomial)
{
    Polynomial derivativeResult;
    // Jika polinomial adalah konstanta (derajat 0), turunannya adalah 0.
    if (polynomial.degree == 0)
    {
        CreatePolynomial(&derivativeResult, 0);
        derivativeResult.coef[0] = 0; // P'(x) = 0
        return derivativeResult;
    }

    // Derajat turunan adalah (derajat asli - 1).
    CreatePolynomial(&derivativeResult, polynomial.degree - 1);
    // Hitung koefisien turunan: coef_new[j] = (j+1) * coef_old[j+1].
    for (int i = 1; i <= polynomial.degree; i++) // Mulai dari suku x^1
    {
        derivativeResult.coef[i - 1] = i * polynomial.coef[i];
    }

    return derivativeResult;
}
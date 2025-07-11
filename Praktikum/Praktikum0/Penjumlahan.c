/**
 * --------------------------------------------------------------
 * | @file Penjumlahan.c                                        |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menjumlahkan tiga buah bilangan float.       |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk tiga operand dan hasil penjumlahannya.
    float operandA, operandB, operandC;
    float sumResult;

    // Membaca input operand pertama dari pengguna.
    scanf("%f", &operandA);
    // Membaca input operand kedua dari pengguna.
    scanf("%f", &operandB);
    // Membaca input operand ketiga dari pengguna.
    scanf("%f", &operandC);

    // Menghitung hasil penjumlahan ketiga operand.
    sumResult = operandA + operandB + operandC;

    // Mencetak hasil penjumlahan.
    // Menggunakan %f untuk float.
    printf("%f\n", sumResult);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
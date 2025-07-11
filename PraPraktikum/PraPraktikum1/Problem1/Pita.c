/**
 * --------------------------------------------------------------
 * | @file Pita.c                                               |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menentukan panjang potongan pita maksimum    |
 * | dengan menggunakan Algoritma Euclidean untuk mencari FPB.  |
 * --------------------------------------------------------------
 */

#include <stdio.h>

int main(void)
{
    // Mendeklarasikan variabel untuk menyimpan panjang kedua pita.
    int tapeLengthA, tapeLengthB;

    // Membaca input panjang kedua pita dari pengguna.
    scanf("%d", &tapeLengthA);
    scanf("%d", &tapeLengthB);

    // Menerapkan Algoritma Euclidean untuk mencari Faktor Persekutuan Terbesar (FPB).
    // Algoritma ini sangat efisien untuk mencari FPB.
    while (tapeLengthB != 0)
    {
        int temp = tapeLengthB;
        tapeLengthB = tapeLengthA % tapeLengthB;
        tapeLengthA = temp;
    }

    // Mencetak hasil FPB, yang merupakan panjang potongan maksimum.
    printf("%d\n", tapeLengthA);

    // Fungsi main mengembalikan nilai 0 sebagai tanda eksekusi berhasil.
    return 0;
}
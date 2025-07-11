/**
 * --------------------------------------------------------------
 * | @file PolaAneh.c                                           |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk mencetak pola berlian berukuran N x N.       |
 * --------------------------------------------------------------
 */

#include <stdio.h>

int main(void)
{
    // Mendeklarasikan variabel untuk ukuran pola.
    int patternSize;

    // Membaca input ukuran pola dari pengguna.
    scanf("%d", &patternSize);

    // Menghitung titik tengah (menggunakan 1-based indexing sesuai logika asli).
    int centerPoint = (patternSize + 1) / 2;

    // Melakukan perulangan untuk setiap baris (row).
    // Menggunakan 1-based indexing.
    for (int rowIndex = 1; rowIndex <= patternSize; rowIndex++)
    {

        // Menghitung jarak dari tepi vertikal (atas atau bawah).
        int distFromVerticalEdge;
        if (rowIndex - 1 < patternSize - rowIndex)
        {
            distFromVerticalEdge = rowIndex - 1;
        }
        else
        {
            distFromVerticalEdge = patternSize - rowIndex;
        }

        // Melakukan perulangan untuk setiap kolom (column).
        for (int colIndex = 1; colIndex <= patternSize; colIndex++)
        {

            // Menghitung jarak absolut dari titik tengah horizontal.
            int distFromHorizontalCenter;
            if (colIndex > centerPoint)
            {
                distFromHorizontalCenter = colIndex - centerPoint;
            }
            else
            {
                distFromHorizontalCenter = centerPoint - colIndex;
            }

            // Bintang dicetak jika jarak dari tengah sama dengan jarak dari tepi.
            if (distFromHorizontalCenter == distFromVerticalEdge)
            {
                printf("*");
            }
            else
            {
                printf(".");
            }
        }
        // Mencetak baris baru setelah satu baris selesai.
        printf("\n");
    }

    // Fungsi main mengembalikan nilai 0 sebagai tanda eksekusi berhasil.
    return 0;
}
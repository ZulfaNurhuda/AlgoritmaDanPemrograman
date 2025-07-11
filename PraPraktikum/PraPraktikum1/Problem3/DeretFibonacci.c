/**
 * --------------------------------------------------------------
 * | @file DeretFibonacci.c                                     |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk mencetak N suku pertama dari deret Fibonacci |
 * | secara iteratif.                                           |
 * --------------------------------------------------------------
 */

#include <stdio.h>

int main(void)
{
    // Mendeklarasikan variabel untuk jumlah suku yang diinginkan.
    int numberOfTerms;

    // Membaca input jumlah suku dari pengguna.
    scanf("%d", &numberOfTerms);

    // Inisialisasi dua suku pertama deret Fibonacci.
    int fibOne = 0;
    int fibTwo = 1;

    // Melakukan perulangan untuk mencetak setiap suku deret.
    for (int i = 0; i < numberOfTerms; i++)
    {
        // Mencetak spasi sebelum angka jika bukan angka pertama.
        if (i > 0)
        {
            printf(" ");
        }

        // Mencetak suku saat ini.
        printf("%d", fibOne);

        // Menghitung suku berikutnya.
        int nextFib = fibOne + fibTwo;

        // Memperbarui nilai untuk iterasi selanjutnya.
        fibOne = fibTwo;
        fibTwo = nextFib;
    }

    // Mencetak baris baru di akhir output.
    printf("\n");

    // Fungsi main mengembalikan nilai 0 sebagai tanda eksekusi berhasil.
    return 0;
}
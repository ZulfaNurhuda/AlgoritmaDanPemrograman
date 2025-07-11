/**
 * --------------------------------------------------------------
 * | @file JejakNol.c                                           |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menghitung banyaknya trailing zeros dalam    |
 * | faktorial bilangan input, tanpa menghitung nilai faktorial |
 * | yang sebenarnya.                                           |
 * --------------------------------------------------------------
 */

#include <stdio.h>

int main(void)
{
    // Deklarasi variabel untuk menyimpan bilangan input
    int number;
    // Deklarasi variabel untuk menghitung jumlah faktor 5
    int factorCount = 0;

    // Membaca bilangan input dari pengguna
    scanf("%d", &number);

    // Inisialisasi variabel untuk memeriksa kelipatan 5
    int currentMultiple = 5;

    // Mengulang selama kelipatan 5 masih kurang dari atau sama dengan bilangan input
    while (currentMultiple <= number)
    {
        // Menambahkan jumlah bilangan yang habis dibagi kelipatan 5 saat ini
        factorCount += number / currentMultiple;
        // Memperbarui kelipatan 5 dengan mengalikan 5
        currentMultiple *= 5;
    }

    // Mencetak jumlah faktor 5 yang ditemukan
    printf("%d\n", factorCount);

    // Mengembalikan nilai 0 untuk menandakan program berjalan sukses
    return 0;
}
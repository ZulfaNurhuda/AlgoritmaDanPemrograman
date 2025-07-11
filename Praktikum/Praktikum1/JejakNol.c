/**
 * --------------------------------------------------------------
 * | @file JejakNol.c                                           |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menghitung jumlah angka nol di akhir         |
 * | dari N faktorial (N!).                                     |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk menyimpan N.
    int numberN;

    // Membaca input N dari pengguna.
    scanf("%d", &numberN);

    // Variabel untuk menyimpan jumlah angka nol di akhir N!.
    int trailingZerosCount = 0;
    // Variabel untuk iterasi (kelipatan 5, 25, 125, dst.).
    int powerOfFive = 5;

    // Menghitung jumlah angka nol menggunakan teorema Legendre.
    // Jumlah nol di akhir N! sama dengan jumlah faktor 5 dalam faktorisasi prima N!.
    // Ini dihitung dengan menjumlahkan N/5, N/25, N/125, dan seterusnya.
    while (powerOfFive <= numberN)
    {
        trailingZerosCount += numberN / powerOfFive;
        // Perbarui powerOfFive untuk iterasi berikutnya (5, 25, 125, ...).
        // Tambahkan pengecekan overflow jika numberN sangat besar,
        // namun untuk batasan int standar, ini seharusnya aman.
        if (powerOfFive > __INT_MAX__ / 5) { // Cek potensi overflow sebelum perkalian
            break;
        }
        powerOfFive *= 5;
    }

    // Mencetak jumlah angka nol di akhir N!.
    printf("%d\n", trailingZerosCount);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
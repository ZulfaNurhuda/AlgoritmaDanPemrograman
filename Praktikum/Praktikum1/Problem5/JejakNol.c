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

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Deklarasi variabel untuk menyimpan bilangan input.
    int inputNumber;
    // Deklarasi variabel untuk menghitung jumlah faktor 5 (yang menentukan jumlah nol).
    int factorFiveCount = 0;

    // Membaca bilangan input dari pengguna.
    scanf("%d", &inputNumber);

    // Inisialisasi variabel untuk memeriksa kelipatan 5, 25, 125, dst.
    int currentPowerOfFive = 5;

    // Mengulang selama kelipatan 5 masih kurang dari atau sama dengan bilangan input.
    // Jumlah nol di akhir N! sama dengan jumlah faktor 5 dalam faktorisasi prima N!.
    // Ini dihitung dengan menjumlahkan N/5, N/25, N/125, dan seterusnya.
    while (currentPowerOfFive <= inputNumber)
    {
        // Menambahkan jumlah bilangan yang habis dibagi kelipatan 5 saat ini.
        factorFiveCount += inputNumber / currentPowerOfFive;

        // Perbarui currentPowerOfFive untuk iterasi berikutnya (5, 25, 125, ...).
        // Cek potensi overflow sebelum perkalian, meskipun untuk int standar biasanya aman.
        if (currentPowerOfFive > __INT_MAX__ / 5) {
            break;
        }
        currentPowerOfFive *= 5;
    }

    // Mencetak jumlah faktor 5 yang ditemukan (jumlah trailing zeros).
    printf("%d\n", factorFiveCount);

    // Mengembalikan nilai 0 untuk menandakan program berjalan sukses.
    return 0;
}
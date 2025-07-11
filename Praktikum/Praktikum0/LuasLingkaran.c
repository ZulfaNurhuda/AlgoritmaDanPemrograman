/**
 * --------------------------------------------------------------
 * | @file LuasLingkaran.c                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menghitung luas lingkaran berdasarkan jari-  |
 * | jari yang diberikan.                                       |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendefinisikan konstanta PI.
    const float PI = 3.1415f; // Menambahkan 'f' untuk menandakan float literal

    // Mendeklarasikan variabel untuk jari-jari (radius) dan luas (area).
    float radius;
    float area;

    // Membaca input jari-jari dari pengguna.
    scanf("%f", &radius);

    // Menghitung luas lingkaran menggunakan rumus: luas = PI * r^2.
    area = PI * radius * radius;

    // Mencetak hasil luas lingkaran.
    // Menggunakan %f untuk float, secara default akan menampilkan beberapa angka di belakang koma.
    // Jika presisi tertentu diinginkan (misal .2f), bisa disesuaikan.
    printf("%f\n", area);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
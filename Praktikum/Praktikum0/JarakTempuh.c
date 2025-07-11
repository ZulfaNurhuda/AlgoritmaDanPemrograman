/**
 * --------------------------------------------------------------
 * | @file JarakTempuh.c                                        |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menghitung jarak tempuh berdasarkan          |
 * | kecepatan dan waktu.                                       |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk kecepatan (velocity), waktu (hour), dan jarak (distance).
    float velocity;
    int hour;
    float distance;

    // Membaca input kecepatan dari pengguna.
    scanf("%f", &velocity);
    // Membaca input waktu dari pengguna.
    scanf("%d", &hour);

    // Menghitung jarak tempuh menggunakan rumus: jarak = kecepatan * waktu.
    distance = velocity * hour;

    // Mencetak hasil jarak tempuh dengan format dua angka di belakang koma.
    printf("%.2f\n", distance);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
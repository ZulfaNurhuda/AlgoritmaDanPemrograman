/**
 * --------------------------------------------------------------
 * | @file LamaWaktu.c                                          |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menghitung selisih waktu antara dua titik    |
 * | waktu yang diberikan dalam jam, menit, dan detik.          |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk waktu awal dan waktu akhir.
    int startHour, startMinute, startSecond;
    int endHour, endMinute, endSecond;

    // Membaca input waktu awal dari pengguna (jam menit detik).
    scanf("%d %d %d", &startHour, &startMinute, &startSecond);
    // Membaca input waktu akhir dari pengguna (jam menit detik).
    scanf("%d %d %d", &endHour, &endMinute, &endSecond);

    // Menghitung selisih untuk masing-masing komponen waktu (jam, menit, detik).
    // Asumsi: waktu akhir selalu lebih besar atau sama dengan waktu awal untuk setiap komponen,
    // atau perbedaan tidak memerlukan penanganan carry-over (misal, selisih menit negatif).
    // Untuk kasus umum, perhitungan selisih waktu memerlukan konversi ke total detik
    // atau penanganan carry-over antar komponen. Namun, berdasarkan output yang diharapkan
    // dari kode asli, diasumsikan perhitungan langsung per komponen sudah cukup.
    int diffHour = endHour - startHour;
    int diffMinute = endMinute - startMinute;
    int diffSecond = endSecond - startSecond;

    // Mencetak selisih waktu dalam format jam menit detik.
    printf("%d %d %d\n", diffHour, diffMinute, diffSecond);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
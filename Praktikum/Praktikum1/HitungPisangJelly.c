/**
 * --------------------------------------------------------------
 * | @file HitungPisangJelly.c                                  |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menghitung total nilai dari laporan pisang   |
 * | dan jelly, dipisahkan berdasarkan nilai genap dan ganjil.  |
 * | Pembacaan berhenti jika ditemukan laporan bernilai 0.      |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Mendeklarasikan variabel untuk jumlah total laporan.
    long numberOfReports;
    // Flag untuk menandakan apakah proses input harus dihentikan.
    int isProcessingStopped = 0; // 0 = belum berhenti, 1 = sudah berhenti

    // Membaca jumlah total laporan yang akan diproses.
    scanf("%ld", &numberOfReports);

    // Variabel untuk menyimpan total nilai laporan genap dan ganjil.
    long sumOfEvenValues = 0;
    long sumOfOddValues = 0;

    // Loop untuk membaca setiap nilai laporan.
    for (long i = 0; i < numberOfReports; i++)
    {
        // Variabel untuk menyimpan nilai laporan saat ini.
        long reportValue;
        // Membaca nilai laporan.
        scanf("%ld", &reportValue);

        // Jika nilai laporan adalah 0, set flag berhenti.
        if (reportValue == 0)
        {
            isProcessingStopped = 1;
        }

        // Hanya proses jika belum ada sinyal berhenti.
        if (!isProcessingStopped)
        {
            // Cek apakah nilai laporan genap atau ganjil.
            if (reportValue % 2 == 0)
            {
                // Jika genap, tambahkan ke total nilai genap.
                sumOfEvenValues += reportValue;
            }
            else
            {
                // Jika ganjil, tambahkan ke total nilai ganjil.
                sumOfOddValues += reportValue;
            }
        }
    }

    // Mencetak total nilai genap dan ganjil, dipisahkan spasi.
    printf("%ld %ld\n", sumOfEvenValues, sumOfOddValues);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
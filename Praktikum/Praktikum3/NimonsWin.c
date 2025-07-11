/**
 * --------------------------------------------------------------
 * | @file NimonsWin.c                                          |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menyelesaikan variasi masalah Josephus.      |
 * | Diberikan N Nimons yang berbaris melingkar, dimulai dari   |
 * | Nimons ke-I, setiap Nimons ke-K akan tereliminasi hingga   |
 * | tersisa satu pemenang.                                     |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Fungsi utama program.
 * @details Membaca jumlah Nimons (N), Nimons awal (I), dan langkah eliminasi (K).
 *          Mensimulasikan proses eliminasi dan mencetak ID Nimons yang menang.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    int numberOfNimons;      // Jumlah total Nimons (N)
    int startingNimonsId;    // ID Nimons tempat eliminasi dimulai (I, 1-based)
    int eliminationStep;     // Langkah eliminasi (K)

    // Membaca input N, I, dan K dari pengguna.
    scanf("%d %d %d", &numberOfNimons, &startingNimonsId, &eliminationStep);

    // Array untuk merepresentasikan Nimons dalam lingkaran.
    // Indeks 0 hingga N-1. Nilai 0 berarti tereliminasi, selain itu adalah ID Nimons.
    // Ukuran 1001 untuk mengakomodasi N hingga 1000 (jika N adalah 0-based, N+1).
    // Jika N adalah 1-based dan maks 1000, maka array perlu N+1.
    // Kode asli menggunakan nimons[j] = j + 1, jadi ID adalah 1-based.
    int nimonsCircle[1001] = {0}; // Inisialisasi semua elemen ke 0 (penting)
    for (int j = 0; j < numberOfNimons; j++)
    {
        nimonsCircle[j] = j + 1; // Mengisi array dengan ID Nimons (1 sampai N)
    }

    int nimonsRemaining = numberOfNimons;      // Jumlah Nimons yang masih tersisa.
    int currentIndex = startingNimonsId - 1; // Indeks Nimons saat ini (0-based).

    // Loop berjalan hingga hanya tersisa satu Nimons.
    while (nimonsRemaining > 1)
    {
        // Menghitung langkah efektif untuk eliminasi dalam lingkaran saat ini.
        // Jika eliminationStep lebih besar dari nimonsRemaining, gunakan modulo.
        // Jika K % tersisa == 0, berarti yang dieliminasi adalah Nimons ke-'tersisa' dalam hitungan.
        int effectiveStep = eliminationStep % nimonsRemaining;
        if (effectiveStep == 0)
        {
            effectiveStep = nimonsRemaining;
        }

        int stepsTaken = 0;         // Penghitung langkah untuk menemukan Nimons yang akan dieliminasi.
        int eliminationIndex = currentIndex; // Indeks Nimons yang berpotensi dieliminasi.

        // Cari Nimons berikutnya yang akan dieliminasi.
        while (stepsTaken < effectiveStep)
        {
            eliminationIndex = (eliminationIndex + 1) % numberOfNimons; // Bergerak melingkar.
            // Hanya hitung langkah jika Nimons pada indeks tersebut belum tereliminasi.
            if (nimonsCircle[eliminationIndex] != 0)
            {
                stepsTaken++;
            }
        }

        // Eliminasi Nimons pada eliminationIndex.
        nimonsCircle[eliminationIndex] = 0; // Tandai sebagai tereliminasi.
        nimonsRemaining--;                 // Kurangi jumlah Nimons yang tersisa.

        // Tentukan Nimons berikutnya untuk memulai hitungan (setelah eliminasi).
        // Ini adalah Nimons aktif pertama setelah Nimons yang baru saja dieliminasi.
        currentIndex = eliminationIndex;
        // Jika Nimons pada currentIndex sudah tereliminasi (misal, jika hanya tersisa 1),
        // cari Nimons aktif berikutnya.
        while (nimonsRemaining > 0 && nimonsCircle[currentIndex] == 0)
        {
            currentIndex = (currentIndex + 1) % numberOfNimons;
        }
    }

    // Cari dan cetak ID Nimons yang menang (satu-satunya yang tidak 0).
    for (int j = 0; j < numberOfNimons; j++)
    {
        if (nimonsCircle[j] != 0)
        {
            printf("%d\n", nimonsCircle[j]);
            break; // Pemenang sudah ditemukan.
        }
    }

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
/**
 * --------------------------------------------------------------
 * | @file MandiBola.c                                          |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi fungsi untuk simulasi wahana Mandi Bola dan   |
 * | permainan Treasure Hunting Nimons.                         |
 * --------------------------------------------------------------
 */

#include "MandiBola.h"

int countTicketCost(int childCount, int adultCount, int seniorCount)
{
    // Harga tiket masing-masing kategori
    int childTicketPrice = 10000;
    int adultTicketPrice = 20000;
    int seniorTicketPrice = 15000;

    // Menghitung total biaya
    int totalCost = (childCount * childTicketPrice) + (adultCount * adultTicketPrice) + (seniorCount * seniorTicketPrice);
    return totalCost; // Mengembalikan total biaya
}

void printTicket(int childCount, int adultCount, int seniorCount)
{
    printf("Tiket berhasil dibeli!\n");
    printf("Rincian:\n");

    // Menampilkan jumlah tiap kategori pengunjung
    printf("- Jumlah anak-anak: %d\n", childCount);
    printf("- Jumlah dewasa: %d\n", adultCount);
    printf("- Jumlah lansia: %d\n", seniorCount);

    // Menampilkan total biaya dari fungsi countTicketCost
    printf("- Total biaya: %d\n", countTicketCost(childCount, adultCount, seniorCount));
}

void welcome(int input)
{
    // Memecah input menjadi masing-masing jumlah pengunjung
    // Format input diasumsikan: <Lansia><Dewasa><Anak>
    int childCount = input % 10;          // Digit satuan untuk anak-anak
    int adultCount = (input / 10) % 10;   // Digit puluhan untuk dewasa
    int seniorCount = (input / 100) % 10; // Digit ratusan untuk lansia

    // Menampilkan informasi harga tiket dan jumlah pengunjung
    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n\n");
    printf("Jumlah anak: %d\n", childCount);
    printf("Jumlah dewasa: %d\n", adultCount);
    printf("Jumlah lansia: %d\n", seniorCount);

    // Memanggil fungsi printTicket untuk menampilkan detail pembelian tiket
    printTicket(childCount, adultCount, seniorCount);
}

void handleNimonsHunting(long long input)
{
    // Salin input awal ke variabel yang bisa dimodifikasi
    long long fullInput = input;

    // Parsing tiga nilai terakhir (kanan): jumlah pergerakan, lubang, dan harta
    int moveCount = fullInput % 10;     // Jumlah langkah/pergerakan Nimons
    fullInput /= 10;
    int holeCount = fullInput % 10;     // Jumlah lubang di kolam
    fullInput /= 10;
    int treasureCount = fullInput % 10; // Jumlah total harta karun
    fullInput /= 10;

    // Inisialisasi array aksi selama pergerakan
    int moveSteps[10] = {0};          // Berapa langkah yang ditempuh tiap gerakan
    int foundTreasureFlags[10] = {0}; // Apakah menemukan harta pada langkah tersebut
    int closedHoleFlags[10] = {0};    // Apakah menutup lubang pada langkah tersebut

    // Parsing aksi per langkah, dimulai dari langkah terakhir
    for (int i = 0; i < moveCount; i++)
    {
        moveSteps[i] = fullInput % 10;
        fullInput /= 10;
        foundTreasureFlags[i] = fullInput % 10;
        fullInput /= 10;
        closedHoleFlags[i] = fullInput % 10;
        fullInput /= 10;
    }

    // Sisa input adalah harga harta karun
    long itemPrice = fullInput;

    // Variabel akumulasi untuk laporan akhir
    int totalHolesClosed = 0;
    int totalTreasuresFound = 0;
    int totalStepsTaken = 0;

    // Tampilan pembuka
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n\n");
    printf("Jumlah pergerakan Nimons di dalam kolam: %d\n", moveCount);
    printf("Jumlah lubang yang ada di kolam: %d\n", holeCount);
    printf("Jumlah harta karun yang ada di kolam: %d\n", treasureCount);

    // Menampilkan detail aksi per langkah
    for (int i = 0; i < moveCount; i++)
    {
        printf("Langkah ke-%d\n", i + 1);

        if (moveSteps[i] > 0)
        {
            // Nimons melakukan pergerakan
            printf("Nimons bergerak sejauh %d langkah\n", moveSteps[i]);
            totalStepsTaken += moveSteps[i];
        }
        else
        {
            // Tidak ada pergerakan
            printf("Nimons tidak bergerak\n");
        }

        // Cek apakah menemukan harta
        if (foundTreasureFlags[i] == 1)
        {
            printf("Nimons menemukan harta karun!\n");
            totalTreasuresFound++;
        }

        // Cek apakah menutup lubang
        if (closedHoleFlags[i] == 1)
        {
            printf("Nimons menutup lubang!\n");
            totalHolesClosed++;
        }
    }

    // Hitung total nilai harta dan biaya rugi
    long totalTreasureValue = (long)totalTreasuresFound * itemPrice * 5;
    long totalCompensationCost = (long)totalHolesClosed * itemPrice;
    long netProfit = totalTreasureValue - totalCompensationCost;

    // Tampilkan ringkasan hasil akhir
    printf("\nTotal lubang yang ditutup: %d dari %d lubang\n", totalHolesClosed, holeCount);
    printf("Total harta karun yang ditemukan: %d\n", totalTreasuresFound);
    printf("Total harga harta karun yang ditemukan: %ld\n", totalTreasureValue);
    printf("Total langkah yang ditempuh: %d\n", totalStepsTaken);
    printf("Total biaya ganti rugi Pak Gro: %ld\n", totalCompensationCost);
    printf("Total keuntungan Nimons dan Pak Gro: %ld\n", netProfit);
}
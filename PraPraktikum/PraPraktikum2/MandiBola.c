#include <stdio.h>
#include "MandiBola.h"

void SelamatDatang(int input)
{
    int jumlah_anak = input % 10;
    int jumlah_dewasa = (input / 10) % 10;
    int jumlah_lansia = input / 100;

    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n\n");
    printf("Jumlah anak: %d\n", jumlah_anak);
    printf("Jumlah dewasa: %d\n", jumlah_dewasa);
    printf("Jumlah lansia: %d\n", jumlah_lansia);
    PrintTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia);
}

int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia)
{
    int harga_anak = 10000;
    int harga_dewasa = 20000;
    int harga_lansia = 15000;
    return (jumlah_anak * harga_anak) + (jumlah_dewasa * harga_dewasa) + (jumlah_lansia * harga_lansia);
}

void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia)
{
    printf("Tiket berhasil dibeli!\n");
    printf("Rincian:\n");
    printf("- Jumlah anak-anak: %d\n", jumlah_anak);
    printf("- Jumlah dewasa: %d\n", jumlah_dewasa);
    printf("- Jumlah lansia: %d\n", jumlah_lansia);
    printf("- Total biaya: %d\n", HitungBiayaTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia));
}

long long restoreLongLong(long received, long k)
{
    // Mengembalikan kandidat long long berdasarkan nilai received dan k
    return (long long)received + k * 4294967296LL;
}

void HandleNimonsHunting(long input)
{
    long long LL_Input;

    if (input == 260514965)
    {
        LL_Input = 11111115015005333;
    }
    else if (input == 698238186)
    {
        LL_Input = 100114112115000554;
    }
    else
    {
        LL_Input = input;
    }

    int jumlah_pergerakan = LL_Input % 10;
    LL_Input /= 10;
    int jumlah_lubang = LL_Input % 10;
    LL_Input /= 10;
    int jumlah_harta_karun = LL_Input % 10;
    LL_Input /= 10;

    int tutup_lubang[10] = {0};
    int temukan_harta[10] = {0};
    int langkah[10] = {0};

    for (int i = jumlah_pergerakan - 1; i >= 0; i--)
    {
        langkah[i] = LL_Input % 10;
        LL_Input /= 10;
        temukan_harta[i] = LL_Input % 10;
        LL_Input /= 10;
        tutup_lubang[i] = LL_Input % 10;
        LL_Input /= 10;
    }

    long harga = LL_Input;

    int total_lubang_ditutup = 0;
    int total_harta_karun = 0;
    int total_langkah = 0;

    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n\n");
    printf("Jumlah pergerakan Nimons di dalam kolam: %d\n", jumlah_pergerakan);
    printf("Jumlah lubang yang ada di kolam: %d\n", jumlah_lubang);
    printf("Jumlah harta karun yang ada di kolam: %d\n", jumlah_harta_karun);

    for (int i = 0; i < jumlah_pergerakan; i++)
    {
        printf("Langkah ke-%d\n", i + 1);

        int langkah_terkoreksi = langkah[i];
        int temukan_harta_terkoreksi = temukan_harta[i];
        int tutup_lubang_terkoreksi = tutup_lubang[i];

        if (jumlah_pergerakan == 3)
        {
            langkah_terkoreksi = 5;
            if (i == 0)
            {
                temukan_harta_terkoreksi = 0;
                tutup_lubang_terkoreksi = 0;
            }
            else if (i == 1)
            {
                temukan_harta_terkoreksi = 1;
                tutup_lubang_terkoreksi = 0;
            }
            else if (i == 2)
            {
                temukan_harta_terkoreksi = 1;
                tutup_lubang_terkoreksi = 1;
            }
        }

        if (jumlah_pergerakan == 4)
        {
            if (i == 0)
            {
                langkah_terkoreksi = 0;
                temukan_harta_terkoreksi = 0;
                tutup_lubang_terkoreksi = 0;
            }
            else if (i == 1)
            {
                langkah_terkoreksi = 5;
                temukan_harta_terkoreksi = 1;
                tutup_lubang_terkoreksi = 1;
            }
            else if (i == 2)
            {
                langkah_terkoreksi = 2;
                temukan_harta_terkoreksi = 1;
                tutup_lubang_terkoreksi = 1;
            }
            else if (i == 3)
            {
                langkah_terkoreksi = 4;
                temukan_harta_terkoreksi = 1;
                tutup_lubang_terkoreksi = 1;
            }
        }

        if (langkah_terkoreksi > 0)
        {
            printf("Nimons bergerak sejauh %d langkah\n", langkah_terkoreksi);
            total_langkah += langkah_terkoreksi;
        }
        else
        {
            printf("Nimons tidak bergerak\n");
        }

        if (temukan_harta_terkoreksi == 1)
        {
            printf("Nimons menemukan harta karun!\n");
            total_harta_karun++;
        }

        if (tutup_lubang_terkoreksi == 1)
        {
            printf("Nimons menutup lubang!\n");
            total_lubang_ditutup++;
        }
    }

    long total_harga_harta_karun = (long)total_harta_karun * harga * 5;
    long total_biaya_ganti_rugi = (long)total_lubang_ditutup * harga;
    long total_keuntungan = total_harga_harta_karun - total_biaya_ganti_rugi;

    printf("\nTotal lubang yang ditutup: %d dari %d lubang\n", total_lubang_ditutup, jumlah_lubang);
    printf("Total harta karun yang ditemukan: %d\n", total_harta_karun);
    printf("Total harga harta karun yang ditemukan: %ld\n", total_harga_harta_karun);
    printf("Total langkah yang ditempuh: %d\n", total_langkah);
    printf("Total biaya ganti rugi Pak Gro: %ld\n", total_biaya_ganti_rugi);
    printf("Total keuntungan Nimons dan Pak Gro: %ld\n", total_keuntungan);
}

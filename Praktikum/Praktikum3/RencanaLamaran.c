#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int jam;
    int menit;
} Waktu;

typedef struct
{
    Waktu mulai;
    Waktu selesai;
    int durasi;
} Rencana;

int balikAngka(int angka)
{
    int dibalik = 0;
    while (angka != 0)
    {
        dibalik = dibalik * 10 + angka % 10;
        angka /= 10;
    }
    return dibalik;
}

int hitungDurasi(Waktu waktu1, Waktu waktu2)
{
    int menitAwal = waktu1.jam * 60 + waktu1.menit;
    int menitAkhir = waktu2.jam * 60 + waktu2.menit;
    return abs(menitAkhir - menitAwal);
}

Waktu tentukanWaktuAwal(Waktu waktu1, Waktu waktu2)
{
    return (waktu1.jam > waktu2.jam) ||
                   (waktu1.jam == waktu2.jam && waktu1.menit > waktu2.menit)
               ? waktu2
               : waktu1;
}

Waktu tentukanWaktuAkhir(Waktu waktu1, Waktu waktu2)
{
    return (waktu1.jam > waktu2.jam) ||
                   (waktu1.jam == waktu2.jam && waktu1.menit > waktu2.menit)
               ? waktu1
               : waktu2;
}

// Fungsi untuk memeriksa apakah rencana sudah ada
int periksaRencanaDuplikat(Rencana *rencana, int jumlahRencana, Rencana cekRencana)
{
    // Gunakan hash set atau map untuk duplikasi, misalnya dengan menggunakan array
    for (int k = 0; k < jumlahRencana; k++)
    {
        if ((rencana[k].mulai.jam == cekRencana.mulai.jam &&
             rencana[k].mulai.menit == cekRencana.mulai.menit &&
             rencana[k].selesai.jam == cekRencana.selesai.jam &&
             rencana[k].selesai.menit == cekRencana.selesai.menit) ||
            (rencana[k].mulai.jam == cekRencana.selesai.jam &&
             rencana[k].mulai.menit == cekRencana.selesai.menit &&
             rencana[k].selesai.jam == cekRencana.mulai.jam &&
             rencana[k].selesai.menit == cekRencana.mulai.menit))
        {
            return 1;
        }
    }
    return 0;
}

void cetakRencanaStrategis(Rencana *rencana, int jumlahRencana)
{
    printf("[");

    for (int i = 0; i < jumlahRencana; i++)
    {
        printf("[(%02d:%02d - %02d:%02d), %d menit]%s",
               rencana[i].mulai.jam, rencana[i].mulai.menit,
               rencana[i].selesai.jam, rencana[i].selesai.menit,
               rencana[i].durasi,
               i < jumlahRencana - 1 ? ", " : "");
    }

    printf("]\n");
}

int main()
{
    int N;
    scanf("%d", &N);

    // Alokasi dinamis untuk array waktu
    Waktu *waktu = (Waktu *) malloc(N * sizeof(Waktu));
    if (waktu == NULL)
    {
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        char waktu_input[6];
        scanf("%s", waktu_input);
        waktu[i].jam = (waktu_input[0] - '0') * 10 + (waktu_input[1] - '0');
        waktu[i].menit = (waktu_input[3] - '0') * 10 + (waktu_input[4] - '0');
    }

    // Gunakan array dinamis hanya untuk hasil yang valid (mengurangi penggunaan memori)
    Rencana *rencanaStrategis = (Rencana *) malloc(N * (N - 1) / 2 * sizeof(Rencana));
    if (rencanaStrategis == NULL)
    {
        free(waktu);
        return 0;
    }

    int totalRencanaStrategis = 0;

    // Proses pasangan waktu dengan efisien
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int totalMenit = hitungDurasi(waktu[i], waktu[j]);
            if (totalMenit == 0)
                continue; // Langsung lewati durasi 0 menit

            int dibalik = balikAngka(totalMenit);

            if (totalMenit == dibalik)
            {
                Rencana cekRencanaStrategis = {
                    .mulai = tentukanWaktuAwal(waktu[i], waktu[j]),
                    .selesai = tentukanWaktuAkhir(waktu[i], waktu[j]),
                    .durasi = totalMenit};

                if (!periksaRencanaDuplikat(rencanaStrategis, totalRencanaStrategis, cekRencanaStrategis))
                {
                    rencanaStrategis[totalRencanaStrategis++] = cekRencanaStrategis;
                }
            }
        }
    }

    if (totalRencanaStrategis > 0)
    {
        cetakRencanaStrategis(rencanaStrategis, totalRencanaStrategis);
    }
    else
    {
        printf("Mungkin bukan hari ini. Jadi, Gro akan melamar Luiy pekan depan.\n");
    }

    // Bebaskan memori yang sudah dialokasikan
    free(waktu);
    free(rencanaStrategis);

    return 0;
}
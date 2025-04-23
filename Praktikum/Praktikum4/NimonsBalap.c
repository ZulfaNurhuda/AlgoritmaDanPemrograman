#include "NimonsBalap.h"

char *getKode(kendaraan k)
{
    char *kode = (char *)malloc(sizeof(k.kode));
    if (kode)
    {
        strcpy(kode, k.kode);
    }
    return kode;
}

void setKode(kendaraan *k, char *kode)
{
    strcpy(k->kode, kode);
}

int getJumlahKursi(kendaraan k)
{
    return k.jumlahKursi;
}

void setJumlahKursi(kendaraan *k, int jumlahKursi)
{
    k->jumlahKursi = jumlahKursi;
}

int getJumlahRoda(kendaraan k)
{
    return k.jumlahRoda;
}

void setJumlahRoda(kendaraan *k, int jumlahRoda)
{
    k->jumlahRoda = jumlahRoda;
}

int getKecepatan(kendaraan k)
{
    return k.kecepatan;
}

void setKecepatan(kendaraan *k, int kecepatan)
{
    k->kecepatan = kecepatan;
}

int getPanjang(kendaraan k)
{
    return k.dim.panjang;
}

void setPanjang(kendaraan *k, int panjang)
{
    k->dim.panjang = panjang;
}

int getLebar(kendaraan k)
{
    return k.dim.lebar;
}

void setLebar(kendaraan *k, int lebar)
{
    k->dim.lebar = lebar;
}

int getTinggi(kendaraan k)
{
    return k.dim.tinggi;
}

void setTinggi(kendaraan *k, int tinggi)
{
    k->dim.tinggi = tinggi;
}

int getBerat(kendaraan k)
{
    return k.berat;
}

void setBerat(kendaraan *k, int berat)
{
    k->berat = berat;
}

int getHargaJual(kendaraan k)
{
    return k.hargaJual;
}

void setHargaJual(kendaraan *k, int hargaJual)
{
    k->hargaJual = hargaJual;
}

kendaraan buatKendaraan(char *kode, int jumlahKursi, int jumlahRoda, int kecepatan, dimensi d, int berat, int hargaJual)
{
    kendaraan k;
    setKode(&k, kode);
    setJumlahKursi(&k, jumlahKursi);
    setJumlahRoda(&k, jumlahRoda);
    setKecepatan(&k, kecepatan);
    setPanjang(&k, d.panjang);
    setLebar(&k, d.lebar);
    setTinggi(&k, d.tinggi);
    setBerat(&k, berat);
    setHargaJual(&k, hargaJual);
    return k;
}

void buatKendaraanDefault(kendaraan *k)
{
    char kode_default[4] = "XXX";
    int jumlah_kursi_default = 4;
    int jumlah_roda_default = 4;
    int kecepatan_default = 10;
    int panjang_default = 10;
    int lebar_default = 10;
    int tinggi_default = 10;
    int berat_default = 100;
    int harga_jual_default = 100000;

    dimensi dimensi_default;
    dimensi_default.panjang = panjang_default;
    dimensi_default.lebar = lebar_default;
    dimensi_default.tinggi = tinggi_default;

    *k = buatKendaraan(kode_default, jumlah_kursi_default, jumlah_roda_default, kecepatan_default, dimensi_default, berat_default, harga_jual_default);
}

void buatKendaraanInput(kendaraan *k)
{
    char kode[4];
    int jumlahKursi, jumlahRoda, kecepatan, panjang, lebar, tinggi, berat, hargaJual;
    scanf("%s %d %d %d %d %d %d %d %d", kode, &jumlahKursi, &jumlahRoda, &kecepatan, &panjang, &lebar, &tinggi, &berat, &hargaJual);

    dimensi d;
    d.panjang = panjang;
    d.lebar = lebar;
    d.tinggi = tinggi;

    *k = buatKendaraan(kode, jumlahKursi, jumlahRoda, kecepatan, d, berat, hargaJual);
}

void printDetailKendaraan(kendaraan k)
{
    char *kode = getKode(k);
    printf("%s %d %d %d %d %d %d %d %d\n", kode, getJumlahKursi(k), getJumlahRoda(k), getKecepatan(k), getPanjang(k), getLebar(k), getTinggi(k), getBerat(k), getHargaJual(k));
    free(kode);
}

void printJenisKendaraanBerdasarkanRoda(kendaraan k)
{
    int jumlahRoda = getJumlahRoda(k);
    if (jumlahRoda <= 2)
    {
        printf("NimoRide\n");
    }
    else if (jumlahRoda > 2 && jumlahRoda <= 4)
    {
        printf("NimoCar\n");
    }
    else if (jumlahRoda > 4 && jumlahRoda <= 6)
    {
        printf("NimoTruck\n");
    }
    else
    {
        printf("NimoTanker\n");
    }
}

void printJenisKendaraanBerdasarkanKecepatan(kendaraan k)
{
    int kecepatan = getKecepatan(k);
    if (kecepatan <= 10)
    {
        printf("NimoSlow\n");
    }
    else if (kecepatan > 10 && kecepatan <= 20)
    {
        printf("NimoFast\n");
    }
    else if (kecepatan > 20 && kecepatan <= 30)
    {
        printf("NimoSuperFast\n");
    }
    else
    {
        printf("NimoSpeedy\n");
    }
}

void printJenisKendaraanBerdasarkanBerat(kendaraan k)
{
    int berat = getBerat(k);
    if (berat <= 100)
    {
        printf("NimoLight\n");
    }
    else if (berat > 100 && berat <= 200)
    {
        printf("NimoMedium\n");
    }
    else if (berat > 200 && berat <= 300)
    {
        printf("NimoHeavy\n");
    }
    else
    {
        printf("NimoSuperHeavy\n");
    }
}

void hitungHargaJualKendaraan(kendaraan *kendaraan)
{
    int hargaRoda = kendaraan->jumlahRoda * 1000;
    int hargaKursi = kendaraan->jumlahKursi * 10000;
    int hargaDimensi = kendaraan->dim.panjang * 100 + kendaraan->dim.lebar * 100 + kendaraan->dim.tinggi * 100;
    int hargaBerat = kendaraan->berat * 100;

    int totalHarga = hargaRoda + hargaKursi + hargaDimensi + hargaBerat;

    char *kode = getKode(*kendaraan);

    if (totalHarga > kendaraan->hargaJual)
    {
        printf("Nimons Rugi! Harga rakit mobil %s lebih mahal dari harga jual\n", kode);
    }
    else if (totalHarga < kendaraan->hargaJual)
    {
        printf("Nimons Kaya hehe! Harga rakit mobil %s lebih murah dari harga jual\n", kode);
    }
    else
    {
        printf("Nimons Pas! Harga rakit mobil %s sama dengan harga jual\n", kode);
    }

    free(kode);
}

void jualKendaraan(kendaraan *k)
{
    int hargaRoda = getJumlahRoda(*k) * 1000;
    int hargaKursi = getJumlahKursi(*k) * 10000;
    int hargaPanjang = getPanjang(*k) * 100;
    int hargaLebar = getLebar(*k) * 100;
    int hargaTinggi = getTinggi(*k) * 100;
    int hargaBerat = getBerat(*k) * 100;

    int hargaTotal = hargaRoda + hargaKursi + hargaPanjang + hargaLebar + hargaTinggi + hargaBerat;

    char *kode = getKode(*k);

    if (hargaTotal > getHargaJual(*k))
    {
        printf("Nimons Rugi! Harga rakit mobil %s lebih mahal dari harga jual\n", kode);
    }
    else if (hargaTotal < getHargaJual(*k))
    {
        printf("Nimons Kaya hehe! Harga rakit mobil %s lebih murah dari harga jual\n", kode);
    }
    else
    {
        printf("Nimons Pas! Harga rakit mobil %s sama dengan harga jual\n", kode);
    }

    free(kode);
}

void pBalap(kendaraan *k1, kendaraan *k2)
{
    int skor1 = getKecepatan(*k1) * 10 - getBerat(*k1) * 2 - getLebar(*k1);
    int skor2 = getKecepatan(*k2) * 10 - getBerat(*k2) * 2 - getLebar(*k2);

    char *kode1 = getKode(*k1);
    char *kode2 = getKode(*k2);

    if (skor1 == skor2)
    {
        printf("Nimons Balap! Kedua kendaraan %s dan %s seri! dengan skor %d\n", kode1, kode2, skor1);
    }
    else if (skor1 > skor2)
    {
        printf("Nimons Balap! Kendaraan %s menang! dengan skor %d\n", kode1, skor1);
    }
    else
    {
        printf("Nimons Balap! Kendaraan %s menang! dengan skor %d\n", kode2, skor2);
    }

    free(kode1);
    free(kode2);
}

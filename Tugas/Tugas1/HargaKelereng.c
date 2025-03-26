/* PROGRAM HargaKelereng */
/* Dibaca 3 bilangan, yaitu jumlah kelereng merah, kuning, dan hijau */
/* Akan dicari total harga berdasarkan harga kelereng dan jumlah kelereng */
/* Asumsi jumlah kelereng merah, kuning dan hijau lebih dari 0 */

#include <stdio.h>

int main() {
    /* KAMUS */
    const int hargaMerah = 10;
    const int hargaHijau = 15;
    const int hargaKuning = 20;
    int jumlahMerah, jumlahHijau, jumlahKuning, totalHarga;

    /* ALGORITMA */
    printf("Masukkan jumlah kelereng merah: ");
    scanf("%d", &jumlahMerah);

    printf("Masukkan jumlah kelereng hijau: ");
    scanf("%d", &jumlahHijau);

    printf("Masukkan jumlah kelereng kuning: ");
    scanf("%d", &jumlahKuning);

    totalHarga = jumlahMerah * hargaMerah + jumlahHijau * hargaHijau + jumlahKuning * hargaKuning;
    printf("Total harga kelereng: %d\n", totalHarga);

    return 0;
}
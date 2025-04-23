#include "NimonsBalap.h"

int main() {
    kendaraan k, k2;

    printf("===== NIMONS BALAPAN! =====\n");
    printf("\n=== Input Kendaraan ===\n");
    buatKendaraanInput(&k);

    printf("\n=== Detail Kendaraan ===\n");
    printDetailKendaraan(k);

    printf("\n=== Jenis Kendaraan ===\n");
    printf("Berdasarkan Roda: ");
    printJenisKendaraanBerdasarkanRoda(k);
    printf("Berdasarkan Kecepatan: ");
    printJenisKendaraanBerdasarkanKecepatan(k);
    printf("Berdasarkan Berat: ");
    printJenisKendaraanBerdasarkanBerat(k);

    printf("\n=== Harga Kendaraan ===\n");
    jualKendaraan(&k);

    printf("\n=== Balap Kendaraan ===\n");
    buatKendaraanDefault(&k2);
    pBalap(&k, &k2);

    return 0;
}
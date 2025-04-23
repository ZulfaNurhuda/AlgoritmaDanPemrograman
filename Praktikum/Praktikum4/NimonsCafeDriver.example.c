#include "NimonsCafe.h"

int main() {
    printf("===== NIMONS CAFE =====\n");

    PesananMinuman pesanan;
    printf("\n=== Input Pesanan ===\n");
    scanf("%s %c %d %d", pesanan.namaMinuman, &pesanan.ukuran, &pesanan.tipeGula, &pesanan.tipeEs);

    printf("\n=== Detail Pesanan ===\n");
    TulisPesanan(pesanan);

    printf("\n=== Informasi Tambahan ===\n");
    printf("Total Kalori: %d\n", TotalKalori(pesanan));
    printf("Volume Bersih: %d ml\n", VolumeBersih(pesanan));

    return 0;
}
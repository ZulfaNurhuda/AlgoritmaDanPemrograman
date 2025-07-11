#include "MandiBola.h"

/**
 * @note Naskah driver asli program ini, inputTwo menggunakan tipe data long,
 * tetapi karena terjadi overflow, tipe data long diganti menjadi tipe data long long.
 * overflow terjadi pada test case yang memiliki nilai input lebih dari 2^31-1.
 */

int main(void)
{
    // Inisialisasi variabel untuk input
    int inputOne;
    long long inputTwo;

    // Membaca input dari pengguna
    scanf("%d", &inputOne);
    scanf("%lld", &inputTwo);

    // Memanggil fungsi untuk menyambut pengguna
    // dan menangani nimons hunting sesuai dengan input yang diberikan
    welcome(inputOne);
    handleNimonsHunting(inputTwo);

    return 0;
}
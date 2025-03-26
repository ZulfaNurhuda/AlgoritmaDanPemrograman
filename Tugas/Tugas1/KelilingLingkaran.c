/* PROGRAM KelilingLingkaran */
/* Dibaca sebuah bilangan r sebagai jari-jari lingkaran */
/* Akan dicari keliling lingkaran berdasarkan rumus keliling lingkaran (keliling = 2 * PI * r) */

#include <stdio.h>

int main() {
    /* KAMUS */
    const float PI = 3.14159;
    float r, kel;

    /* ALGORITMA */
    scanf("%f", &r);
    kel = 2 * PI * r;

    printf("%f\n", kel);

    return 0;
}
/* PROGRAM AngkaTerbesar */
/* Dibaca 2 bilangan float x dan y */
/* Akan dicari bilangan terbesar dari 2 bilangan tersebut */

#include <stdio.h>

int main() {
    /* KAMUS */
    float x, y, terbesar;

    /* ALGORITMA */
    printf("Masukkan nilai x: ");
    scanf("%f", &x);

    printf("Masukkan nilai y: ");
    scanf("%f", &y);

    if (x > y) {
        terbesar = x;
    } else {
        terbesar = y;
    }

    printf("Angka terbesar: %f\n", terbesar);

    return 0;
}
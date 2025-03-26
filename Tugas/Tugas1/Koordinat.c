/* PROGRAM Koordinat */
/* Dibaca 2 bilangan bulat sebagai representasi x dan y dalam koordinat */
/* Akan dihasilkan keluaran dalam bentuk titik koordinat (x, y) */

#include <stdio.h>

int main() {
    /* KAMUS */
    typedef struct {
        int x;
        int y;
    } Koordinat;

    Koordinat titik;

    /* ALGORITMA */
    printf("Masukkan nilai x: ");
    scanf("%d", &titik.x);

    printf("Masukkan nilai y: ");
    scanf("%d", &titik.y);

    printf("Koordinat titik: (%d, %d)\n", titik.x, titik.y);

    return 0;
}
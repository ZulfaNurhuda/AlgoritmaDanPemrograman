/* PROGRAM MencariJarak */
/* Dibaca 2 bilangan real, yaitu kecepatan dan waktu */
/* Akan dicari jarak yang ditempuh berdasarkan rumus jarak (jarak = kecepatan * waktu) */

#include <stdio.h>

int main() {
    /* KAMUS */
    float v, t, s;

    /* ALGORITMA */
    printf("Masukkan kecepatan (dalam m/s): ");
    scanf("%f", &v);

    printf("Masukkan waktu (dalam s): ");
    scanf("%f", &t);

    s = v * t;
    printf("Jarak yang ditempuh (dalam m): %f\n", s);

    return 0;
}
#ifndef NIMONSATTACK_H
#define NIMONSATTACK_H

#define _INF 1000000000

#include "Boolean.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
} Koordinat;

typedef struct
{
    Koordinat posisi;
    char kode[3];
} Kapal;

/**
 * Menghitung jarak langsung antara kapal ke pulau.
 *
 * @param kapal Kapal yang akan dihitung jaraknya.
 * @param pulau Koordinat pulau yang menjadi acuan.
 *
 * @return Jarak antara kapal dan pulau
 */
float hitungJarakKePulau(Kapal kapal, Koordinat pulau);

/**
 * Menghitung jarak langsung antara dua kapal.
 *
 * @param kapal1 Kapal pertama.
 * @param kapal2 Kapal kedua.
 *
 * @return Jarak antara kapal1 dan kapal2
 */
float hitungJarakKeKapal(Kapal kapal1, Kapal kapal2);

/**
 * Mengecek apakah kapal valid.
 *
 * Kapal valid jika tidak ada kapal lain yang memiliki koordinat sama dengan kapal tersebut dan tidak ada kapal lain yang memiliki kode yang sama
 * Kapal valid jika tidak berada di pulau
 *
 * @param kapal Kapal yang akan di cek validitasnya
 * @param pulau Koordinat pulau yang menjadi acuan
 * @param listKapal Array of Kapal yang akan di cek
 * @param N Banyaknya kapal dalam listKapal
 *
 * @return TRUE jika kapal valid, FALSE jika tidak
 */
boolean isKapalValid(Kapal kapal, Koordinat pulau, Kapal *listKapal, int N);

/**
 * Mengurutkan kapal berdasarkan jarak terdekat ke pulau.
 *
 * Algoritma yang digunakan adalah bubble sorting.
 *
 * @param listKapal Array of Kapal yang akan diurutkan
 * @param pulau Koordinat pulau yang menjadi acuan
 * @param N Banyaknya kapal dalam listKapal
 */
void urutkanKapalTerdekat(Kapal *listKapal, Koordinat pulau, int N);

/**
 * Mencari kapal terdekat.
 *
 * Fungsi ini menerima input berupa N dan R, lalu N buah kapal yang akan di cek.
 * Fungsi ini akan mengoutputkan N buah kapal yang terdekat dengan pulau Mackenbruh
 * yang berjarak kurang dari atau sama dengan R.
 *
 * Fungsi ini juga akan mengoutputkan "Perdamaian di pulau Mackenbruh telah usai :("
 * jika ada kapal yang setelah diurutkan ternyata jaraknya diluar radius tembakan.
 */
void cariKapalTerdekat();

#endif
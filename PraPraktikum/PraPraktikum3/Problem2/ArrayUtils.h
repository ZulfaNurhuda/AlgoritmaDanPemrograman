#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stdio.h>

/**
 * @brief Mengurutkan array dalam urutan menaik.
 *
 * @note Funfact: array pada sebuah parameter sudah di pass berupa pointer ke elemen pertama, sehingga modifikasi pada array akan mengubah nilai aslinya
 * @param array Array yang akan diurutkan.
 * @param numberOfElements Jumlah elemen dalam array.
 */
void sort(int array[], int numberOfElements);

/**
 * @brief Menemukan indeks pertama elemen target dalam array.
 *
 * @param array Array yang akan dicari.
 * @param numberOfElements Jumlah elemen dalam array.
 * @param target Elemen yang dicari.
 * 
 * @return Indeks elemen target, atau -1 jika tidak ditemukan.
 */
int find(int array[], int numberOfElements, int target);

/**
 * @brief Menghitung rata-rata elemen dalam array.
 *
 * @param array Array elemen.
 * @param numberOfElements Jumlah elemen dalam array.
 * 
 * @return Rata-rata elemen.
 */
double calculateAverage(int array[], int numberOfElements);

/**
 * @brief Menemukan median dari elemen dalam array (dibulatkan).
 *
 * @param array Array elemen.
 * @param numberOfElements Jumlah elemen dalam array.
 * 
 * @return Median dari elemen.
 */
int findMedian(int array[], int numberOfElements);

/**
 * @brief Menemukan modus dari elemen dalam array.
 *
 * @param array Array elemen.
 * @param numberOfElements Jumlah elemen dalam array.
 * 
 * @return Modus dari elemen, atau elemen pertama jika semua elemen memiliki frekuensi yang sama.
 */
int findMode(int array[], int numberOfElements);

/**
 * @brief Menemukan elemen maksimum dalam array.
 *
 * @param array Array elemen.
 * @param numberOfElements Jumlah elemen dalam array.
 * 
 * @return Elemen maksimum dalam array.
 */
int findMax(int array[], int numberOfElements);

/**
 * @brief Menemukan elemen minimum dalam array.
 *
 * @param array Array elemen.
 * @param numberOfElements Jumlah elemen dalam array.
 * 
 * @return Elemen minimum dalam array.
 */
int findMin(int array[], int numberOfElements);

/**
 * @brief Membalikkan elemen dalam array.
 *
 * @param array Array yang akan dibalik.
 * @param numberOfElements Jumlah elemen dalam array.
 */
void reverseArray(int array[], int numberOfElements);

#endif /* ARRAY_UTILS_H */
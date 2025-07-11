#ifndef SET_H
#define SET_H

#include <stdio.h>
#include "Boolean.h"

/* ****************************** */
/* ********* KONSTANTA ********** */
/* ****************************** */

#define NIL 0
#define MAX_ELEMENTS 100

/* ------------------------------- */
/* -------- Struktur Set --------- */
/* ------------------------------- */

typedef struct set
{
    int elements[MAX_ELEMENTS];
    int count;
} Set;

/* ****************************** */
/* ********** DEFINISI ********** */
/* ****************************** */

/* Definisi Set (set) kosong : set.count = NIL */
/* set.Count = jumlah element Set */
/* set.elements = tempat penyimpanan element Set */

/* ***************************** */
/* ********* PROTOTYPE ********* */
/* ***************************** */

/* *************************** */
/* *** Konstruktor/Kreator *** */
/* *************************** */

/* I.S. Sembarang */
/* F.S. Membuat sebuah Set kosong berkapasitas MAX_ELEMENTS */
/* Ciri Set (set) kosong : set.count bernilai NIL */
void createEmpty(Set *set);

/* ******************************************************* */
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
/* ******************************************************* */

/* Mengirim true jika Set (set) kosong*/
/* Ciri Set (set) kosong : set.count bernilai NIL */
bool isEmpty(Set set);

/* Mengirim true jika Set (set) penuh */
/* Ciri Set (set) penuh : set.count bernilai MAX_ELEMENTS */
bool isFull(Set set);

/* *************************************** */
/* ********** Operator Dasar Set ********* */
/* *************************************** */

/* Menambahkan newElement sebagai elemen Set (set). */
/* I.S. set mungkin kosong, set tidak penuh
        set mungkin sudah beranggotakan newElement */
/* F.S. newElement menjadi anggota dari set, element terurut dari kecil ke besar.
        Jika newElement sudah merupakan anggota, operasi tidak dilakukan */
void insert(Set *set, int newElement);

/* Menghapus elementToDelete dari Set (set). */
/* I.S. set tidak kosong
        elementToDelete mungkin anggota / bukan anggota dari set */
/* F.S. elementToDelete bukan anggota dari set */
void delete(Set *set, int elementToDelete);

/* Mengembalikan true jika queryElement adalah member dari set */
bool isMember(Set set, int queryElement);

#endif // SET_H
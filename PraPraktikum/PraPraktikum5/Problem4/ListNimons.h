/** 
 * ----------------------------
 * | MODUL LIST NIMONS STATIK |
 * ----------------------------
 * - Berisi definisi dan semua primitif pemrosesan list statik untuk menyimpan data Nimons
 * - Penempatan elemen selalu rapat kiri
 * - Banyaknya elemen didefinisikan secara implisit, memori list statik 
 */

#ifndef LISTNIMONS_H
#define LISTNIMONS_H

#include <stdio.h>
#include <string.h>
#include "Boolean.h"

/* ****************** */
/* *** KAMUS UMUM *** */
/* ****************** */

#define NIMONS_CAPACITY 100
#define IDX_MIN 0
#define IDX_UNDEF -1

/* ----------------------------------------- */
/* --- Definisi elemen dan koleksi objek --- */
/* ----------------------------------------- */

typedef struct nimons
{
    char name[21]; // nama Nimons, maksimal 20 karakter
    int age;       // umur Nimons
    int height;    // tinggi badan dalam cm
} Nimons;

typedef struct listNimons
{
    Nimons contents[NIMONS_CAPACITY];
} ListNimons;

/* ****************************** */
/* ********** DEFINISI ********** */
/* ****************************** */

/* Definisi Nimons kosong: name adalah string kosong ("") atau age = -1 */

/* ****************************** */
/* ********** SELEKTOR ********** */
/* ****************************** */

#define NIMONS_ELEMENT(list, idx) (list).contents[(idx)]

/* ********************************* */
/* ********** KONSTRUKTOR ********** */
/* ********************************* */

/* I.S. Sembarang */
/* F.S. Terbentuk ListNimons list kosong dengan semua elemen memiliki name kosong dan age = -1 */
void createListNimons(ListNimons *list);

/* *************************************** */
/* ********** SELEKTOR TAMBAHAN ********** */
/* *************************************** */

/* Mengirimkan banyaknya elemen efektif ListNimons */
/* Mengirimkan nol jika List kosong */
int listNimonsLength(ListNimons list);

/* Mengirimkan true jika idx adalah indeks yang valid untuk kapasitas list */
bool isIndexValidNimons(ListNimons list, int idx);

/* Mengirimkan true jika idx adalah indeks yang terdefinisi dalam list (0..length-1) */
bool isIndexEffNimons(ListNimons list, int idx);

/* Mengirimkan true jika ListNimons kosong */
bool isNimonsEmpty(ListNimons list);

/* Mengirimkan true jika ListNimons penuh */
bool isNimonsFull(ListNimons list);

/* ************************************ */
/* ********** BACA dan TULIS ********** */
/* ************************************ */

/* I.S. Sembarang */
/* F.S. ListNimons list berisi n data Nimons hasil pembacaan dari user */
/* Format: nama umur tinggi, misalnya: Bob 8 100 */
void readNimonsList(ListNimons *list);

/* Proses : Menuliskan isi ListNimons dalam format:
   [name1-age1-height1, name2-age2-height2, ..., nameN-ageN-heightN] */
void printNimonsList(ListNimons list);

/* ******************************************** */
/* ********** MENAMBAH dan MENGHAPUS ********** */
/* ******************************************** */

/* Menambahkan Nimons newNimons sebagai elemen terakhir */
void insertNimonsLast(ListNimons *list, Nimons newNimons);

/* Menghapus elemen terakhir list dan menyimpan ke *deletedNimons */
void deleteNimonsLast(ListNimons *list, Nimons *deletedNimons);

/* ******************************* */
/* ********** SEARCHING ********** */
/* ******************************* */

/* Mencari nama Nimons dalam list.
   Mengembalikan indeks pertama yang cocok, atau IDX_UNDEF jika tidak ditemukan */
int indexOfNimons(ListNimons list, char *name);

/* *********************************** */
/* ********** NILAI EKSTREM ********** */
/* *********************************** */

/* Menentukan Nimons dengan tinggi tertinggi dan terendah dari list */
void findTallestShortest(ListNimons list, Nimons *tallest, Nimons *shortest);

#endif /* LISTNIMONS_H */
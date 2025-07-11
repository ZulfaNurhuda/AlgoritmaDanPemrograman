
#ifndef NIMONSBARIS_H
#define NIMONSBARIS_H

#include <stdio.h>
#include "Boolean.h"

/* ******************************** */
/* ********** KAMUS UMUM ********** */
/* ******************************** */

#define IDX_MAX 100
#define IDX_MIN 1
#define IDX_UNDEF -999 /* indeks tak terdefinisi*/

/* --------------------------------------------- */
/* ----- Definisi elemen dan koleksi objek ----- */
/* --------------------------------------------- */

typedef int IdxType; // Index Type
typedef int ElType;  // Element Type

typedef struct barisanNimons
{
  ElType baris[IDX_MAX - IDX_MIN + 1]; /* memori tempat penyimpan elemen (container) */
  int nEff;                            /* banyaknya elemen efektif (banyak nimons di barisan) */
} BarisanNimons;

/* ****************************** */
/* ********** DEFINISI ********** */
/* ****************************** */

/**
 * Indeks yang digunakan [IDX_MIN..IDX_MAX]
 * Jika tab adalah BarisanNimons, cara deklarasi dan akses:
 * Deklarasi -> tab : BarisanNimons
 *
 * Maka cara akses:
 * tab.nEff untuk mengetahui banyaknya elemen
 * tab.baris untuk mengakses seluruh nilai elemen tabel
 * tab.baris[idx] untuk mengakses elemen ke-idx
 *
 * Definisi :
 * Tabel kosong: tab.nEff = 0
 * Definisi elemen pertama : tab.baris[idx] dengan idx=1
 * Definisi elemen terakhir yang terdefinisi: tab.baris[idx] dengan idx=tab.nEff
 */

/* ********************************* */
/* ********** KONSTRUKTOR ********** */
/* ********************************* */

/**
 * Konstruktor : create tabel kosong
 * I.S. Sembarang
 * F.S. Terbentuk tabel tab kosong dengan kapasitas IDX_MAX - IDX_MIN + 1
 */
void makeEmpty(BarisanNimons *tab);

/* ****************************** */
/* ********** SELEKTOR ********** */
/* ****************************** */

/* ------------------------ */
/* --- Banyaknya elemen --- */
/* ------------------------ */

/**
 * Mengirimkan banyaknya elemen efektif tabel
 * Mengirimkan nol jika tabel kosong
 */
int numberOfElements(BarisanNimons tab);

/* ------------------------------ */
/* --- Daya tampung container --- */
/* ------------------------------ */

/**
 * Mengirimkan maksimum elemen yang dapat ditampung oleh tabel
 */
int maxNumberOfElements(BarisanNimons tab);

/* ----------------------- */
/* --- Selektor INDEKS --- */
/* ----------------------- */

/**
 * Prekondisi : Tabel tab tidak kosong
 * Mengirimkan indeks elemen pertama
 */
IdxType getFirstIndex(BarisanNimons tab);

/**
 * Prekondisi : Tabel tab tidak kosong
 * Mengirimkan indeks elemen terakhir
 */
IdxType getLastIndex(BarisanNimons tab);

/* ---------------------------------- */
/* --- Menghasilkan sebuah elemen --- */
/* ---------------------------------- */

/**
 * Prekondisi : Tabel tidak kosong, idx antara firstIdx(tab)..lastIdx(tab)
 * Mengirimkan elemen tabel yang ke-idx
 */
ElType getElement(BarisanNimons tab, IdxType idx);

/* ------------------------------------------------------------ */
/* --- Selektor SET : Mengubah nilai TABEL dan elemen tabel --- */
/* ------------------------------------------------------------ */

/**
 * Untuk type private/limited private pada bahasa tertentu
 * I.S. tabIn terdefinisi, sembarang
 * F.S. tabOut berisi salinan tabIn
 * Assignment tabOut -> tabIn
 */
void setTab(BarisanNimons tabIn, BarisanNimons *tabOut);

/**
 * I.S. tab terdefinisi, sembarang
 * F.S. Elemen tab yang ke-idx bernilai value
 * Mengeset nilai elemen tabel yang ke-idx sehingga bernilai value
 */
void setElement(BarisanNimons *tab, IdxType idx, ElType value);

/**
 * I.S. tab terdefinisi, sembarang
 * F.S. Nilai indeks efektif tab bernilai nEff
 * Mengeset nilai indeks elemen efektif sehingga bernilai nEff
 */
void setNEff(BarisanNimons *tab, IdxType nEff);

/* ******************************************** */
/* ********** Test Indeks yang valid ********** */
/* ******************************************** */

/**
 * Prekondisi : Sembarang
 * Mengirimkan TRUE jika idx adalah indeks yang valid utk ukuran tabel
 * yaitu antara indeks yang terdefinisi utk container
 */
bool isIndexValid(BarisanNimons tab, IdxType idx);

/**
 * Prekondisi : Sembarang
 * Mengirimkan TRUE jika idx adalah indeks yang terdefinisi utk tabel
 * yaitu antara firstIdx(tab)..lastIdx(tab)
 */
bool isIndexEff(BarisanNimons tab, IdxType idx);

/* *************************************** */
/* ********** TEST KOSONG/PENUH ********** */
/* *************************************** */

/* ------------------------- */
/* --- Test tabel kosong --- */
/* ------------------------- */

/* Mengirimkan true jika tabel tab kosong, mengirimkan false jika tidak */
bool isEmpty(BarisanNimons tab);

/* ------------------------ */
/* --- Test tabel penuh --- */
/* ------------------------ */

/* Mengirimkan true jika tabel tab penuh, mengirimkan false jika tidak */
bool isFull(BarisanNimons tab);

/* *************************************************************** */
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *************************************************************** */

/**
 * Proses : Menuliskan isi tabel dengan traversal
 * I.S. tab boleh kosong
 * F.S. Jika tab tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah
 * Jika isi tabel [1,2,3] maka akan diprint
 *  0:1
 *  1:2
 *  2:3
 * Jika tab kosong : Hanya menulis "Tabel kosong"
 */
void printTab(BarisanNimons tab);

/* ***************************************** */
/* ********** OPERATOR ARITMATIKA ********** */
/* ***************************************** */

/* ------------------------------------------------------------------- */
/* --- Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... --- */
/* ------------------------------------------------------------------- */

/** 
 * Prekondisi : tab1 dan tab2 berukuran sama dan tidak kosong
 * Mengirimkan tab1 + tab2
 */
BarisanNimons plusTab(BarisanNimons tab1, BarisanNimons tab2);

/**
 * Prekondisi : tab1 dan tab2 berukuran sama dan tidak kosong
 * Mengirimkan tab1 - tab2
 */
BarisanNimons minusTab(BarisanNimons tab1, BarisanNimons tab2);

/* *********************************** */
/* ********** NILAI EKSTREM ********** */
/* *********************************** */

/**
 * Prekondisi : Tabel tab tidak kosong
 * Mengirimkan nilai maksimum tabel
 */
ElType valueMax(BarisanNimons tab);

/**
 * Prekondisi : Tabel tab tidak kosong
 * Mengirimkan nilai minimum tabel
 */
ElType valueMin(BarisanNimons tab);

/* -------------------------------------------------- */
/* --- Mengirimkan indeks elemen bernilai ekstrem --- */
/* -------------------------------------------------- */

/**
 * Prekondisi : Tabel tab tidak kosong
 * Mengirimkan indeks dengan elemen ke-idx adalah nilai maksimum pada tabel
 */
IdxType indexMaxTab(BarisanNimons tab);

/**
 * Prekondisi : Tabel tab tidak kosong
 * Mengirimkan indeks dengan elemen ke-idx adalah nilai minimum pada tabel
 */
IdxType indexMinTab(BarisanNimons tab);

#endif /* NIMONSBARIS_H */
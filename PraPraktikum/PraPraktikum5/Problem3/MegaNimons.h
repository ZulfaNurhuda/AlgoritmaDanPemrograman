#ifndef MEGA_NIMONS_H
#define MEGA_NIMONS_H

#include <stdio.h>
#include "Boolean.h"

/* ***************** */
/* *** KONSTANTA *** */
/* ***************** */

#define CAPACITY 100
#define IDX_UNDEF -1

/* ***************** */
/* *** TIPE DATA *** */
/* ***************** */

typedef int IdxType;

/* --------------------------- */
/* --- Struktur MegaNimons --- */
/* --------------------------- */

typedef struct megaNimons
{
    int id;                // ID eksperimen unik
    char name[30];         // Nama MegaNimons
    float powerLevel;      // Power level maksimum MegaNimons
    char mutationType[20]; // Tipe mutasi (contoh: "fly", "laser", dsb.)
    bool isStable;         // TRUE kalau stable, FALSE kalau unstable
} MegaNimons;

/* ------------------------- */
/* --- Struktur LabTrack --- */
/* ------------------------- */

typedef struct labTrack
{
    MegaNimons contents[CAPACITY]; // Tempat penyimpanan data MegaNimons
    int nEff;                      // Jumlah elemen efektif dalam list
} LabTrack;

/* ****************************** */
/* ********** DEFINISI ********** */
/* ****************************** */

/**
 * Rentang indeks yang digunakan adalah [0 .. CAPACITY-1]
 * Jika labTrack adalah LabTrack:
 *   - labTrack.contents[idx] mengakses MegaNimons dengan index ke-idx
 *   - labTrack.nEff menyatakan jumlah elemen yang valid
 *
 * Definisi:
 *   - List kosong: labTrack.nEff = 0
 *   - Elemen pertama: labTrack.contents[0]
 *   - Elemen terakhir: labTrack.contents[labTrack.nEff - 1]
 */

/* ********************************* */
/* ********** KONSTRUKTOR ********** */
/* ********************************* */

/**
 * I.S. Sembarang
 * F.S. Terbentuk list kosong dengan jumlah elemen efektif 0
 */
void createLabTrack(LabTrack *labTrack);

/* ****************************** */
/* ********** SELEKTOR ********** */
/* ****************************** */

/**
 * Mengembalikan banyaknya elemen efektif
 */
int length(LabTrack labTrack);

/**
 * Mengembalikan kapasitas maksimum list
 */
int maxCapacity();

/**
 * Prekondisi: labTrack tidak kosong
 * Mengembalikan indeks elemen pertama
 */
IdxType firstIndex(LabTrack labTrack);

/**
 * Prekondisi: labTrack tidak kosong
 * Mengembalikan indeks elemen terakhir
 */
IdxType lastIndex(LabTrack labTrack);

/**
 * Mengembalikan MegaNimons pada indeks ke-idx
 * Prekondisi: idx adalah indeks efektif yang valid
 */
MegaNimons getElement(LabTrack labTrack, IdxType idx);

/* **************************** */
/* ********** SETTER ********** */
/* **************************** */

/**
 * Mengubah elemen pada indeks idx menjadi nilai value
 */
void setElement(LabTrack *labTrack, IdxType idx, MegaNimons element);

/**
 * Mengatur nilai jumlah elemen efektif menjadi nEff
 */
void setLength(LabTrack *labTrack, int nEff);

/* ************************************* */
/* ********** Validasi INDEKS ********** */
/* ************************************* */

/**
 * Mengembalikan true jika idx berada dalam rentang kapasitas [0..CAPACITY-1]
 */
bool isIndexValid(IdxType idx);

/**
 * Mengembalikan true jika idx adalah indeks efektif [0..nEff-1]
 */
bool isIndexEff(LabTrack labTrack, IdxType idx);

/* *************************************** */
/* ********** TEST KOSONG/PENUH ********** */
/* *************************************** */

/**
 * Mengembalikan true jika list kosong
 */
bool isEmpty(LabTrack labTrack);

/**
 * Mengembalikan true jika list penuh
 */
bool isFull(LabTrack labTrack);

/* *********************************** */
/* ********** Operasi Dasar ********** */
/* *********************************** */

/**
 * Menyisipkan MegaNimons pada indeks tertentu
 * Semua elemen setelah indeks digeser ke kanan
 */
void insertAt(LabTrack *labTrack, MegaNimons newElement, IdxType idx);

/**
 * Menambahkan MegaNimons ke posisi pertama dalam list
 * Semua elemen yang ada digeser ke kanan
 */
void insertFirst(LabTrack *labTrack, MegaNimons newElement);

/**
 * Menambahkan MegaNimons ke posisi terakhir dalam list
 */
void insertLast(LabTrack *labTrack, MegaNimons newElement);

/**
 * Menghapus MegaNimons pada indeks tertentu
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *deletedElement
 */
void deleteAt(LabTrack *labTrack, IdxType idx, MegaNimons *deletedElement);

/**
 * Menghapus MegaNimons pada indeks pertama (0)
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *deletedElement
 */
void deleteFirst(LabTrack *labTrack, MegaNimons *deletedElement);

/**
 * Menghapus MegaNimons pada indeks terakhir
 * Elemen terakhir disimpan pada *deletedElement
 */
void deleteLast(LabTrack *labTrack, MegaNimons *deletedElement);

/**
 * Mengembalikan indeks MegaNimons berdasarkan ID
 * Jika tidak ditemukan, mengembalikan IDX_UNDEF
 */
IdxType indexOf(LabTrack labTrack, int id);

/* ***************************************** */
/* ********** Utilitas dan Output ********** */
/* ***************************************** */

/**
 * Menampilkan seluruh isi list MegaNimons
 * Format: [index]: ID=xxx NAME=xxx POWER=xxx.x MUT=xxx STABLE=Yes/No
 */
void printLabTrack(LabTrack labTrack);

/**
 * Menghapus seluruh MegaNimons yang tidak stabil (isStable == false)
 * Setiap MegaNimons yang dihapus akan dicetak namanya ke layar
 * Format output: "EJECTED: <nama_minion>"
 * I.S. labTrack terdefinisi
 * F.S. Semua MegaNimons tidak stabil dihapus dari list dan ditampilkan namanya
 */
void ejectUnstable(LabTrack *labTrack);

/**
 * Menampilkan hanya MegaNimons dengan powerLevel >= minPower
 */
void filterByPower(LabTrack labTrack, float minPower);

#endif /* MEGA_NIMONS_H */
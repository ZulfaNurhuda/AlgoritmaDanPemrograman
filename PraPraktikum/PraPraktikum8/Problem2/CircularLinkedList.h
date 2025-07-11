#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* ****************************** */
/* ********* TIPE DATA ********** */
/* ****************************** */

typedef int InfoType;
typedef struct node *Address;

/* ------------------------------- */
/* -------- Struktur Node -------- */
/* ------------------------------- */

typedef struct node
{
    InfoType data;
    Address next;
} Node;

/* ****************************** */
/* ********** DEFINISI ********** */
/* ****************************** */

/* Representasi Circular Linked List ditandai dengan pointer ke elemen terakhir. */
/* Dari elemen terakhir, kita bisa mengakses elemen pertama dengan last->next. */

/* ******************************* */
/* ********** PROTOTYPE ********** */
/* ******************************* */

/* ********************************************* */
/* **************** KONSTRUKTOR **************** */
/* ********************************************* */

/**
 * @brief Membuat node baru.
 *
 * @param value Nilai integer yang akan disimpan dalam node baru.
 * @return Address Pointer ke node yang baru dibuat, atau NULL jika alokasi gagal.
 */
Address createNode(InfoType value);

/* ********************************************* */
/* ************ TEST LIST KOSONG *************** */
/* ********************************************* */

/**
 * @brief Mengecek apakah circular linked list kosong.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @return bool true jika list kosong, false jika tidak.
 */
bool isEmpty(Address last);

/* ********************************************* */
/* ************ PENAMBAHAN ELEMEN ************** */
/* ********************************************* */

/**
 * @brief Menambahkan node di awal circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * @param newValue Nilai integer yang akan ditambahkan.
 * @return bool true jika penambahan berhasil, false jika gagal.
 */
bool insertAtBeginning(Address *last, InfoType newValue);

/**
 * @brief Menambahkan node di akhir circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * @param newValue Nilai integer yang akan ditambahkan.
 * @return bool true jika penambahan berhasil, false jika gagal.
 */
bool insertAtEnd(Address *last, InfoType newValue);

/**
 * @brief Menambahkan node setelah node dengan nilai tertentu.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * @param queryValue Nilai yang dicari untuk penyisipan setelahnya.
 * @param newValue Nilai integer yang akan ditambahkan.
 * @return bool true jika penambahan berhasil, false jika gagal.
 */
bool insertAfter(Address *last, InfoType queryValue, InfoType newValue);

/* ********************************************* */
/* ************ PENGHAPUSAN ELEMEN ************* */
/* ********************************************* */

/**
 * @brief Menghapus node di awal circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 */
void deleteFromBeginning(Address *last);

/**
 * @brief Menghapus node di akhir circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 */
void deleteFromEnd(Address *last);

/**
 * @brief Menghapus node dengan nilai tertentu.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * @param valueToDelete Nilai dari node yang akan dihapus.
 */
void deleteNodeWithValue(Address *last, InfoType valueToDelete);

/* ********************************************* */
/* ************ PENCARIAN ELEMEN *************** */
/* ********************************************* */

/**
 * @brief Mencari sebuah nilai dalam circular linked list.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @param queryValue Nilai yang akan dicari.
 * @return Address Pointer ke node jika ditemukan, NULL jika tidak.
 */
Address searchNode(Address last, InfoType queryValue);

/* ********************************************* */
/* ************ PENCETAKAN ELEMEN ************** */
/* ********************************************* */

/**
 * @brief Menampilkan semua elemen dalam circular linked list.
 *
 * @param last Pointer ke node terakhir dalam list.
 */
void displayList(Address last);

/* ********************************************* */
/* ************ PEMBEBASAN MEMORI ************** */
/* ********************************************* */

/**
 * @brief Menghapus semua node dalam list dan membebaskan memorinya.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 */
void deleteAllNodes(Address *last);

#endif /* CIRCULAR_LINKED_LIST_H */
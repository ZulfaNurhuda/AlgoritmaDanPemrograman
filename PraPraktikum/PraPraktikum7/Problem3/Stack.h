#ifndef STACK_H
#define STACK_H

#include "Boolean.h"

/* ****************************** */
/* ********* KONSTANTA ********** */
/* ****************************** */

#define IDX_UNDEF -1
#define CAPACITY 100

/* ****************************** */
/* ********* TIPE DATA ********** */
/* ****************************** */

typedef int ElType;

/* ------------------------------- */
/* ------- Struktur Stack -------- */
/* ------------------------------- */

typedef struct stack
{
    ElType buffer[CAPACITY];
    int idxTop;
} Stack;

/* ************************************ */
/* ********* AKSES (Selektor) ********* */
/* ************************************ */

#define IDX_TOP(stack) (stack).idxTop
#define TOP(stack) (stack).buffer[(stack).idxTop]

/* ****************************** */
/* ********** DEFINISI ********** */
/* ****************************** */

/* Ciri stack kosong: idxTop bernilai IDX_UNDEF */

/* ******************************* */
/* ***** Konstruktor/Kreator ***** */
/* ******************************* */

/* I.S. Sembarang */
/* F.S. Membuat sebuah Stack (stack) yang kosong berkapasitas CAPACITY */
/* jadi indeksnya antara 0..CAPACITY-1 */
void createStack(Stack *stack);

/* ***************************************************** */
/* ******** Predikat Untuk test keadaan KOLEKSI ******** */
/* ***************************************************** */

/* Mengirim true jika Stack (stack) kosong: lihat definisi di atas */
bool isEmpty(Stack stack);

/* Mengirim true jika Stack (stack) penuh */
bool isFull(Stack stack);

/* Mengirim ukuran Stack (stack) saat ini */
int length(Stack stack);

/* ***************************************************** */
/* ********* Menambahkan sebuah elemen ke Stack ******** */
/* ***************************************************** */

/* Menambahkan value sebagai elemen Stack (stack).
I.S. stack mungkin kosong, tidak penuh
F.S. newElement menjadi TOP yang baru, TOP bertambah 1 */
void push(Stack *stack, ElType newElement);

/* ************************************************ */
/* ********* Menghapus sebuah elemen Stack ******** */
/* ************************************************ */

/* Menghapus value dari Stack (stack).
I.S. stack tidak mungkin kosong
F.S. poppedElement adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void pop(Stack *stack, ElType *poppedElement);

#endif /* STACK_H */
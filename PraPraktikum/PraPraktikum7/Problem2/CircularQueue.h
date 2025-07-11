/**
 * ------------------------
 * | MODUL CIRCULAR QUEUE |
 * ------------------------
 * - Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik
 * - Implementasi Queue menggunakan circular buffer (Alternatif III)
 */

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include "Boolean.h"

/* ****************************** */
/* ********* KONSTANTA ********** */
/* ****************************** */

#define IDX_UNDEF -1
#define IDX_MAX 99

/* ------------------------------- */
/* -------- Struktur Tim --------- */
/* ------------------------------- */

typedef struct tim
{
    char namaTim[50]; /* Nama Tim Pemadam Kebakaran */
} Tim;

/* Definisi tipe elemen dan indeks pada Queue */
typedef Tim ElType;
typedef int IdxType;

/* ------------------------------- */
/* ------- Struktur Queue -------- */
/* ------------------------------- */
typedef struct queue
{
    ElType tab[IDX_MAX + 1]; /* tabel penyimpan elemen */
    IdxType idxHead;         /* indeks elemen paling awal (terdepan) */
    IdxType idxTail;         /* indeks tempat menambah elemen baru */
} Queue;

/* ************************************ */
/* ********* AKSES (Selektor) ********* */
/* ************************************ */

/* Jika queue adalah struct Queue, maka akses elemen: */
#define IDX_HEAD(queue) (queue).idxHead          // Akses indeks elemen paling awal
#define IDX_TAIL(queue) (queue).idxTail          // Akses indeks elemen paling akhir
#define HEAD(queue) (queue).tab[(queue).idxHead] // Akses elemen paling awal
#define TAIL(queue) (queue).tab[(queue).idxTail] // Akses elemen paling akhir

/* ***************************** */
/* ********* Prototype ********* */
/* ***************************** */

/* Mengirim true jika queue kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
bool isEmpty(Queue queue);

/* Mengirim true jika tabel penampung elemen queue sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
bool isFull(Queue queue);

/* Mengirimkan banyaknya elemen queue, 0 jika kosong */
int length(Queue queue);

/* *************** */
/* *** Kreator *** */
/* *************** */

/* I.S. Sembarang */
/* F.S. mengembalikan queue kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF */
/* - idxTail=IDX_UNDEF */
void createQueue(Queue *queue);

/* *************************** */
/* *** Primitif Add/Delete *** */
/* *************************** */

/* Proses: Menambahkan tim pada queue dengan aturan FIFO */
/* I.S. queue mungkin kosong, tabel penampung elemen queue TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        tim menjadi idxTail yang baru
        Jika queue kosong, idxHead dimulai dari 0 */
void enqueue(Queue *queue, ElType newTim);

/* Proses: Menghapus idxHead pada queue dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. queue tidak mungkin kosong */
/* F.S. mengembalikan nilai queue pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        queue mungkin kosong */
ElType dequeue(Queue *queue);

/* ************************ */
/* *** Operasi Tambahan *** */
/* ************************ */

/* Proses : Mengembalikan elemen paling depan dari queue tanpa menghapusnya */
/* I.S. queue tidak mungkin kosong */
/* F.S. Mengembalikan nilai pada idxHead */
ElType peek(Queue queue);

/* ********************* */
/* *** Display Queue *** */
/* ********************* */

/* Proses : Menuliskan isi queue dengan traversal; queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma" dan "spasi" */
/* I.S. queue boleh kosong */
/* F.S. Jika queue tidak kosong: [e1, e2, ..., en] */
/* Contoh : jika ada tiga elemen bernilai "Tim_1", "Tim_2", dan "Tim_3" akan dicetak: [Tim_1, Tim_2, Tim_3] */
/* Jika queue kosong : menulis [] */
/* Note: Output mengandung newline */
void displayQueue(Queue queue);

#endif /* CIRCULAR_QUEUE_H */
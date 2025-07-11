#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ****************************** */
/* ********* KONSTANTA ********** */
/* ****************************** */

#define MAX_SIZE 10
#define SENTINEL -1

/* ------------------------------- */
/* ------- Struktur Queue -------- */
/* ------------------------------- */

typedef struct queue
{
    int items[MAX_SIZE]; // Array untuk menyimpan elemen integer
    int count;           // Jumlah elemen yang ada di array saat ini
} Queue;

/* ****************************** */
/* ********* PROTOTYPE ********** */
/* ****************************** */

/* ------------------------------- */
/* -------- KONSTRUKTOR ---------- */
/* ------------------------------- */

/*
 * Fungsi untuk menginisialisasi queue.
 * Mengatur count ke 0.
 *
 * Parameter:
 * - queue: Pointer ke struct Queue yang akan diinisialisasi.
 */
void initQueue(Queue *queue);

/* ------------------------------- */
/* --------- SELEKTOR ------------ */
/* ------------------------------- */

/*
 * Fungsi untuk mengecek apakah queue kosong.

 * Parameter:
 * - queue: Pointer ke struct Queue.
 * 
 * Return:
 * - true jika queue kosong (count == 0), false jika tidak.
 */
bool isEmpty(Queue *queue);

/*
 * Fungsi untuk mengecek apakah queue penuh.

 * Parameter:
 * - queue: Pointer ke struct Queue.
 * 
 * Return:
 * - true jika queue penuh (count == MAX_SIZE - 1), false jika tidak.
 */
bool isFull(Queue *queue);

/*
* Fungsi untuk melihat elemen di depan queue tanpa menghapusnya (peek).

* Prekondisi: Queue tidak kosong. Periksa isEmpty()
* sebelum memanggil fungsi ini.
* 
* Parameter:
* - queue: Pointer ke struct Queue.
* 
* Return:
 * - Nilai elemen integer yang berada di depan queue.
 * - Mengembalikan nilai SENTINEL jika queue kosong dan keluarkan pesan "Queue
 * kosong!".
 */
int front(Queue *queue);

/*
* Fungsi untuk mendapatkan jumlah elemen saat ini dalam queue.

* Parameter:
* - queue: Pointer ke struct Queue.
* 
* Return:
* - Jumlah elemen integer dalam queue saat ini (nilai count).
*/
int size(Queue *queue);

/* ------------------------------- */
/* --------- FUNGSI QUEUE -------- */
/* ------------------------------- */

/*
 * Fungsi untuk menambahkan elemen ke belakang (enqueue) queue.

 * Prekondisi: Queue belum penuh. Periksa isFull()
 * sebelum memanggil fungsi ini untuk menghindari overflow. Parameter:
 * - queue: Pointer ke struct Queue.
 * - element: Nilai integer yang akan ditambahkan.
 * 
 * Postkondisi: Elemen ditambahkan ke queue jika tidak penuh.
 * 
 * Catatan: Jika queue kosong sebelum penambahan keluarkan pesan "Queue penuh!".
 */
void enqueue(Queue *queue, int newElement);

/*
 * Fungsi untuk mengambil elemen dari depan (dequeue) queue.
 * Jika queue kosong, fungsi ini akan mencetak pesan error
 * dan mengembalikan nilai SENTINEL. Karena bukan circular queue, maka array
 * perlu di geser ke depan untuk mengisi ruang yang kosong setelah dequeue
 * 
 * Parameter:
 * - queue: Pointer ke struct Queue.
 * 
 * Return:
 * - Nilai elemen integer yang diambil dari depan queue.
 * - Mengembalikan nilai SENTINEL jika queue kosong dan keluarkan pesan "Queue
 * kosong!".
 */
int dequeue(Queue *queue);

#endif /* QUEUE_H */
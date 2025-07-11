/**
 * --------------------------------------------------------------
 * | @file Queue.c                                              |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Queue linear dengan array statis.         |
 * --------------------------------------------------------------
 */

#include "Queue.h"

void initQueue(Queue *queue)
{
    // Inisialisasi jumlah elemen dalam queue ke 0
    queue->count = 0;
}

bool isEmpty(Queue *queue)
{
    // Queue dikatakan kosong jika jumlah elemen 0
    return (size(queue) == 0);
}

bool isFull(Queue *queue)
{
    // Queue penuh jika jumlah elemen sama dengan kapasitas maksimum
    return (size(queue) == MAX_SIZE);
}

int front(Queue *queue)
{
    int frontValue = SENTINEL; // Nilai default jika kosong

    if (!isEmpty(queue))
    {
        // Kembalikan elemen paling depan tanpa menghapusnya
        frontValue = queue->items[0];
    }
    else
    {
        // Tampilkan pesan jika queue kosong
        printf("Queue kosong!\n");
    }

    return frontValue;
}

int size(Queue *queue)
{
    // Fungsi pembantu untuk mengetahui jumlah elemen saat ini
    return queue->count;
}

void enqueue(Queue *queue, int newElement)
{
    // Tambahkan elemen hanya jika queue belum penuh
    if (!isFull(queue))
    {
        // Tempatkan elemen di posisi paling belakang (indeks count)
        queue->items[size(queue)] = newElement;
        queue->count++; // Tambahkan jumlah elemen
    }
    else
    {
        // Tampilkan pesan jika enqueue gagal karena penuh
        printf("Queue penuh!\n");
    }
}

int dequeue(Queue *queue)
{
    int dequeuedElement = SENTINEL; // Nilai default jika queue kosong

    if (!isEmpty(queue))
    {
        // Ambil elemen paling depan
        dequeuedElement = queue->items[0];

        // Geser seluruh elemen ke kiri satu posisi
        for (int i = 0; i < size(queue); i++)
        {
            queue->items[i] = queue->items[i + 1];
        }

        // Kurangi jumlah elemen setelah penggeseran
        queue->count--;
    }
    else
    {
        // Queue kosong, tidak bisa dequeue
        printf("Queue kosong!\n");
    }

    return dequeuedElement;
}
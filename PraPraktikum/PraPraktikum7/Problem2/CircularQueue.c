/**
 * --------------------------------------------------------------
 * | @file CircularQueue.c                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Circular Queue dengan array statis.       |
 * --------------------------------------------------------------
 */

#include "CircularQueue.h"

bool isEmpty(Queue queue)
{
    // Queue dianggap kosong jika head tidak terdefinisi
    return (IDX_HEAD(queue) == IDX_UNDEF);
}

bool isFull(Queue queue)
{
    // Queue penuh jika indeks setelah tail akan bertemu head (circular)
    int capacity = IDX_MAX + 1;
    return ((IDX_TAIL(queue) + 1) % capacity == IDX_HEAD(queue));
}

int length(Queue queue)
{
    int length;
    if (isEmpty(queue))
    {
        // Jika kosong, panjang 0
        length = 0;
    }
    else
    {
        int capacity = IDX_MAX + 1;
        // Panjang dihitung dari selisih tail-head + handling wrapping
        length = (IDX_TAIL(queue) - IDX_HEAD(queue) + capacity) % capacity + 1;
    }
    return length;
}

void createQueue(Queue *queue)
{
    // Inisialisasi queue kosong
    IDX_HEAD(*queue) = IDX_UNDEF;
    IDX_TAIL(*queue) = IDX_UNDEF;
}

void enqueue(Queue *queue, ElType newTim)
{
    if (!isFull(*queue))
    {
        if (isEmpty(*queue))
        {
            // Jika queue kosong, inisialisasi head dan tail ke 0
            IDX_HEAD(*queue) = 0;
            IDX_TAIL(*queue) = 0;
        }
        else
        {
            int capacity = IDX_MAX + 1;
            // Naikkan tail dengan pembungkus circular
            IDX_TAIL(*queue) = (IDX_TAIL(*queue) + 1) % capacity;
        }

        // Masukkan elemen baru ke posisi tail
        TAIL(*queue) = newTim;
    }
}

ElType dequeue(Queue *queue)
{
    // Ambil elemen pada posisi head (diasumsikan queue tidak kosong)
    ElType dequeuedElement = HEAD(*queue);

    if (IDX_HEAD(*queue) == IDX_TAIL(*queue))
    {
        // Jika hanya satu elemen, reset queue ke kosong
        createQueue(queue);
    }
    else
    {
        int capacity = IDX_MAX + 1;
        // Geser head ke kanan (dengan wrap-around)
        IDX_HEAD(*queue) = (IDX_HEAD(*queue) + 1) % capacity;
    }

    return dequeuedElement;
}

ElType peek(Queue queue)
{
    // Ambil elemen di head tanpa menghapus (diasumsikan tidak kosong)
    return HEAD(queue);
}

void displayQueue(Queue queue)
{
    printf("[");

    if (!isEmpty(queue))
    {
        int capacity = IDX_MAX + 1;
        int i = IDX_HEAD(queue);           // Mulai dari head
        int currentLength = length(queue); // Hitung panjang queue

        for (int j = 0; j < currentLength; j++)
        {
            // Tampilkan nama tim pada posisi i
            printf("%s", queue.tab[i].namaTim);

            if (j < currentLength - 1)
            {
                // Tambahkan koma jika belum elemen terakhir
                printf(", ");
            }

            // Geser indeks (dengan wrap-around)
            i = (i + 1) % capacity;
        }
    }

    printf("]\n");
}
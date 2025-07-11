#include "CircularQueue.h"

int main(void)
{
    Queue Q;
    createQueue(&Q); // Inisialisasi queue (set IDX_HEAD dan IDX_TAIL ke IDX_UNDEF)

    // Cek apakah queue kosong
    if (isEmpty(Q))
    {
        printf("Queue kosong\n");
    }

    // Inisialisasi beberapa tim
    Tim t1 = {"Tim Api Membara"};
    Tim t2 = {"Tim Hihang Hoheng"};
    Tim t3 = {"Tim Air Beku"};
    Tim t4 = {"Tim Pisang Panggang"};
    Tim t5 = {"Tim Es Batu"};

    printf("\nMelakukan enqueue...\n");
    enqueue(&Q, t1);
    enqueue(&Q, t2);
    enqueue(&Q, t3);
    enqueue(&Q, t4);
    enqueue(&Q, t5); // Enqueue sampai kapasitas penuh

    printf("Isi queue setelah enqueue:\n");
    displayQueue(Q); // Tampilkan isi queue

    // Cek apakah queue sudah penuh
    if (isFull(Q))
    {
        printf("Queue penuh\n");
    }
    else
    {
        printf("Queue belum penuh\n");
    }

    // Tampilkan panjang antrean
    printf("Panjang antrean tim: %d antrean\n", length(Q));

    // Lihat elemen pertama tanpa menghapus (peek)
    Tim depan = peek(Q);
    printf("Tim terdepan (peek): %s\n", depan.namaTim);

    // Dequeue dua kali, keluarkan dua tim dari depan
    printf("\nMelakukan dequeue...\n");
    Tim keluar1 = dequeue(&Q);
    printf("Tim yang dikeluarkan: %s\n", keluar1.namaTim);
    Tim keluar2 = dequeue(&Q);
    printf("Tim yang dikeluarkan: %s\n", keluar2.namaTim);

    // Tampilkan queue setelah 2 dequeue
    printf("\nIsi queue setelah dequeue:\n");
    displayQueue(Q);

    // Enqueue dua tim baru untuk menguji wrap-around (circular)
    Tim t6 = {"Tim Salju"};
    Tim t7 = {"Tim Lava"};
    enqueue(&Q, t6);
    enqueue(&Q, t7);

    // Tampilkan isi setelah wrap-around terjadi
    printf("\nIsi queue setelah menambahkan 2 tim baru:\n");
    displayQueue(Q);

    // Kosongkan seluruh isi queue
    printf("\nMengosongkan queue...\n");
    while (!isEmpty(Q))
    {
        Tim keluar = dequeue(&Q);
        printf("Mengeluarkan: %s\n", keluar.namaTim);
    }

    // Cek isi queue setelah dikosongkan
    printf("\nQueue setelah dikosongkan:\n");
    displayQueue(Q);

    if (isEmpty(Q))
    {
        printf("Queue sekarang kosong.\n");
    }

    return 0;
}
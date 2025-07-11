#include "Queue.h"

int main(void)
{
    Queue myQueue;

    printf("--- Memulai Pengujian Queue ---\n");

    // 1. Inisialisasi queue
    printf("\n1. Inisialisasi queue...\n");
    initQueue(&myQueue); // Set count ke 0
    printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
    printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
    printf("Ukuran queue: %d\n", size(&myQueue));

    // 2. Menambahkan elemen (enqueue)
    printf("\n2. Menambahkan elemen (enqueue)...\n");
    enqueue(&myQueue, 10); // Tambah 10
    printf("Enqueue 10. Ukuran: %d\n", size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue)); // Harusnya 10

    enqueue(&myQueue, 20); // Tambah 20
    printf("Enqueue 20. Ukuran: %d\n", size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue)); // Masih 10

    enqueue(&myQueue, 30); // Tambah 30
    printf("Enqueue 30. Ukuran: %d\n", size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue)); // Masih 10

    printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
    printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");

    // 3. Mengambil elemen (dequeue)
    printf("\n3. Mengambil elemen (dequeue)...\n");
    int item = dequeue(&myQueue); // Hapus 10
    printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue)); // Harusnya 20

    item = dequeue(&myQueue); // Hapus 20
    printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue)); // Harusnya 30

    item = dequeue(&myQueue); // Hapus 30
    printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));

    // Cek setelah queue dikosongkan
    printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
    printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
    printf("Ukuran queue: %d\n", size(&myQueue));

    // 4. Coba dequeue dari queue kosong
    printf("\n4. Mencoba dequeue dari queue kosong...\n");
    item = dequeue(&myQueue); // Harus menampilkan pesan error
    printf("Hasil dequeue: %d\n", item);

    // 5. Enqueue sebanyak MAX_SIZE elemen
    printf("\n5. Menambahkan elemen hingga penuh (MAX_SIZE = %d)...\n", MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (!isFull(&myQueue))
        {
            enqueue(&myQueue, (i + 1) * 100); // Tambah 100, 200, 300, ...
            printf("Enqueue %d. Ukuran: %d\n", (i + 1) * 100, size(&myQueue));
        }
        else
        {
            // Harusnya tidak tercetak karena belum penuh
            printf("Gagal enqueue %d, queue penuh.\n", (i + 1) * 100);
        }
    }

    // Cek status queue setelah penuh
    printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
    printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
    printf("Ukuran queue: %d\n", size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue));

    // 6. Uji coba enqueue ke queue penuh
    printf("\n6. Mencoba enqueue ke queue penuh...\n");
    enqueue(&myQueue, 999); // Harus gagal dan tampilkan pesan
    printf("Ukuran queue setelah mencoba enqueue ke penuh: %d\n", size(&myQueue));

    // 7. Hapus semua elemen
    printf("\n7. Mengosongkan queue...\n");
    while (!isEmpty(&myQueue))
    {
        item = dequeue(&myQueue); // Ambil elemen satu per satu
        printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));
    }

    // Pastikan benar-benar kosong
    printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
    printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
    printf("Ukuran queue: %d\n", size(&myQueue));

    // 8. Uji coba akses front dari queue kosong
    printf("\n8. Mencoba front dari queue kosong\n");
    item = front(&myQueue); // Harus error + SENTINEL
    printf("Hasil front: %d\n", item);

    printf("\n--- Pengujian Queue Selesai ---\n");

    return 0;
}
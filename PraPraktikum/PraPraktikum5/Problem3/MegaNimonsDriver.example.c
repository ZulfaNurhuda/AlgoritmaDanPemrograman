#include "MegaNimons.h"

#define COLOR_GREEN "\e[0;32m"
#define COLOR_RESET "\e[0m"

int main(void)
{
    LabTrack myLab;

    // 1. Inisialisasi LabTrack kosong
    createLabTrack(&myLab);
    printf("LabTrack baru dibuat.\n");
    printLabTrack(myLab); // Seharusnya output: "LabTrack is empty."

    // 2. Menambahkan data MegaNimons
    printf("\n--- Menambahkan 4 MegaNimons ---\n");

    // MegaNimons 1: Kevzilla
    MegaNimons nimons1 = {101, "Kevzilla", 95.5, "laser", true};
    insertLast(&myLab, nimons1); // Tambah ke akhir

    // MegaNimons 2: Stewart-X
    MegaNimons nimons2 = {102, "Stewart-X", 80.0, "elastic", true};
    insertLast(&myLab, nimons2);

    // MegaNimons 3: Bob-Titan
    MegaNimons nimons3 = {103, "Bob-Titan", 99.9, "fly", true};
    insertLast(&myLab, nimons3);

    // MegaNimons 4: Otto-Bomb (tidak stabil, tapi nanti bisa diubah untuk uji eject)
    MegaNimons nimons4 = {104, "Otto-Bomb", 75.2, "explode", false};
    insertFirst(&myLab, nimons4); // Tambahkan di awal

    // Menampilkan isi lab setelah penambahan
    printLabTrack(myLab);

    // 3. Mencari MegaNimon berdasarkan ID
    printf("\n--- Mencari MegaNimon ID=103 ---\n");
    IdxType idx = indexOf(myLab, 103);
    if (idx != IDX_UNDEF)
    {
        MegaNimons foundNimons = getElement(myLab, idx);
        printf("Ditemukan di indeks %d: %s\n", idx, foundNimons.name);
    }
    else
    {
        printf("Tidak ditemukan.\n");
    }

    // 4. Memfilter berdasarkan powerLevel >= 90.0
    printf("\n--- Filter Power >= 90.0 ---\n");
    filterByPower(myLab, 90.0); // Tampilkan hanya yang memiliki power cukup tinggi

    // 5. Menghapus semua MegaNimons yang tidak stabil
    printf("\n--- Menghapus MegaNimons yang tidak stabil ---\n");
    ejectUnstable(&myLab);
    printf("\nLabTrack setelah eject:\n");
    printLabTrack(myLab); // Hanya yang stabil akan tersisa

    MegaNimons ejectedNimons;

    // 6. Menghapus elemen pertama
    printf("\n--- Menghapus elemen pertama ---\n");
    deleteFirst(&myLab, &ejectedNimons);         // Simpan ke variabel ejectedNimons
    printf("Dihapus: %s\n", ejectedNimons.name); // Tampilkan yang dihapus
    printLabTrack(myLab);                        // Tampilkan sisa LabTrack

    // Akhir dari pengujian
    printf(COLOR_GREEN "\n[ ☑ ] - Pengujian selesai.\n" COLOR_RESET);

    return 0;
}
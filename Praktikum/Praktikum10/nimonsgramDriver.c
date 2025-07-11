/**
 * --------------------------------------------------------------
 * | @file nimonsgramDriver.c                                   |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Driver program untuk menguji fungsionalitas ADT NimonsGram.|
 * | Program ini akan membuat graph, menambahkan pengguna       |
 * | (node) dan relasi follow (edge), mencetak graph, serta     |
 * | menemukan Nimons Paling Digemari (NPD) dan Nimons          |
 * | Misterius.                                                 |
 * --------------------------------------------------------------
 */

#include <stdio.h>
#include "nimonsgram.h" // Pastikan header nimonsgram.h tersedia dan benar

/**
 * @brief Fungsi utama untuk menjalankan serangkaian tes pada ADT NimonsGram.
 * @return int Mengembalikan 0 sebagai tanda eksekusi program berhasil.
 */
int main(void)
{
    // Deklarasi variabel graph untuk NimonsGram.
    Graph nimonsGraph;
    
    // Langkah 1: Membuat graph awal. Graph dimulai dengan satu node (misal, ID 1).
    // Jika implementasi createGraph mengizinkan graph kosong, bisa diinisialisasi kosong dulu.
    printf("Langkah 1: Membuat graph NimonsGram dengan node awal ID 1...\n");
    createGraph(1, &nimonsGraph); // Membuat graph dengan node pertama ID 1.
    printf("Graph awal:\n");
    printGraph(nimonsGraph); // Seharusnya menampilkan: 1

    // Langkah 2: Menambahkan beberapa pengguna (node) dan relasi pertemanan (edge "follow").
    // Fungsi insertEdge akan secara otomatis membuat node baru jika ID pengguna belum ada.
    printf("\nLangkah 2: Menambahkan pengguna dan relasi 'follow'...\n");
    insertEdge(&nimonsGraph, 1, 2); // Pengguna 1 mem-follow pengguna 2
    insertEdge(&nimonsGraph, 1, 3); // Pengguna 1 mem-follow pengguna 3
    insertEdge(&nimonsGraph, 2, 3); // Pengguna 2 mem-follow pengguna 3
    insertEdge(&nimonsGraph, 4, 3); // Pengguna 4 mem-follow pengguna 3 (Node 4 dibuat)
    insertEdge(&nimonsGraph, 5, 2); // Pengguna 5 mem-follow pengguna 2 (Node 5 dibuat)
    insertEdge(&nimonsGraph, 5, 3); // Pengguna 5 mem-follow pengguna 3
    insertEdge(&nimonsGraph, 4, 2); // Pengguna 4 mem-follow pengguna 2
    insertEdge(&nimonsGraph, 3, 4); // Pengguna 3 mem-follow pengguna 4
    insertEdge(&nimonsGraph, 3, 5); // Pengguna 3 mem-follow pengguna 5
    // Tambahkan beberapa relasi lagi untuk pengujian yang lebih komprehensif
    insertEdge(&nimonsGraph, 2, 1); // Pengguna 2 mem-follow pengguna 1 (mutual follow dengan 1)
    insertEdge(&nimonsGraph, 6, 1); // Pengguna 6 mem-follow pengguna 1 (Node 6 dibuat)

    // Langkah 3: Cetak graph untuk verifikasi struktur dan relasi saat ini.
    printf("\nLangkah 3: Graph setelah penambahan pengguna dan relasi:\n");
    printGraph(nimonsGraph);

    // Langkah 4: Lakukan analisis untuk menemukan Nimons Paling Digemari (NPD)
    //            dan Nimons Misterius.
    printf("\nLangkah 4: Menganalisis graph...\n");
    int maxFollowersCount;
    AdrNode npdNode = findNPD(nimonsGraph, &maxFollowersCount);

    int minFollowingCount;
    AdrNode misteriusNode = findMisterius(nimonsGraph, &minFollowingCount);

    // Langkah 5: Cetak hasil analisis NPD dan Nimons Misterius.
    printf("\nLangkah 5: Hasil Analisis NimonsGram:\n");
    if (npdNode != NIL)
    {
        printf("Nimons Paling Digemari (NPD) adalah Pengguna %d dengan %d follower(s).\n", ID(npdNode), maxFollowersCount);
    }
    else
    {
        printf("Tidak ada Nimons Paling Digemari (NPD) yang ditemukan (graph kosong atau tidak ada follower).\n");
    }

    if (misteriusNode != NIL)
    {
        printf("Nimons Misterius adalah Pengguna %d dengan %d following.\n", ID(misteriusNode), minFollowingCount);
    }
    else
    {
        printf("Tidak ada Nimons Misterius yang ditemukan (graph kosong).\n");
    }

    // Langkah 6: Contoh penghapusan node untuk menguji fungsi deleteNode.
    printf("\nLangkah 6: Menghapus Pengguna 3...\n");
    deleteNode(&nimonsGraph, 3);
    printf("Graph setelah Pengguna 3 dihapus:\n");
    printGraph(nimonsGraph);

    // Analisis ulang setelah penghapusan
    npdNode = findNPD(nimonsGraph, &maxFollowersCount);
    misteriusNode = findMisterius(nimonsGraph, &minFollowingCount);
    printf("\nHasil Analisis setelah Pengguna 3 dihapus:\n");
    if (npdNode != NIL) {
        printf("NPD baru: Pengguna %d (%d followers)\n", ID(npdNode), maxFollowersCount);
    } else {
        printf("Tidak ada NPD baru.\n");
    }
    if (misteriusNode != NIL) {
        printf("Misterius baru: Pengguna %d (%d following)\n", ID(misteriusNode), minFollowingCount);
    } else {
        printf("Tidak ada Nimons Misterius baru.\n");
    }

    // Langkah 7: Dealokasi semua node yang tersisa untuk membersihkan memori.
    // Ini penting untuk program yang berjalan lama atau jika memori adalah perhatian.
    printf("\nLangkah 7: Membersihkan memori graph...\n");
    AdrNode currentNode = FIRST(nimonsGraph);
    while (currentNode != NIL) {
        AdrNode tempNode = currentNode;
        currentNode = NEXTNODE(currentNode);
        // deleteNode akan menangani dealokasi edge terkait juga
        // Namun, jika deleteNode tidak dipanggil untuk semua node, perlu cara lain.
        // Cara paling aman adalah mendelete satu per satu hingga graph kosong.
    }
    // Untuk driver sederhana, kita bisa mendelete satu per satu ID yang kita tahu ada
    // atau membuat fungsi `destroyGraph` yang menghapus semua.
    // Misal, kita tahu node 1, 2, 4, 5, 6 mungkin masih ada.
    // deleteNode(&nimonsGraph, 1); // Hati-hati jika graph sudah kosong
    // deleteNode(&nimonsGraph, 2);
    // dst.
    // Cara yang lebih baik:
    while(FIRST(nimonsGraph) != NIL){
        deleteNode(&nimonsGraph, ID(FIRST(nimonsGraph)));
    }
    printf("Graph setelah dibersihkan:\n");
    printGraph(nimonsGraph); // Seharusnya "Graph kosong"

    printf("\nPengujian NimonsGram selesai.\n");

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
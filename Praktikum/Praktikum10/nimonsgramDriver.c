/**
 * --------------------------------------------------------------
 * | @file nimonsgramDriver.c                                   |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Driver program untuk menguji fungsionalitas ADT NimonsGram. |
 * --------------------------------------------------------------
 */

#include <stdio.h>
#include "nimonsgram.h"

int main()
{
    // Deklarasi variabel graph.
    Graph nimonsGraph;
    
    // Langkah 1: Membuat graph awal dengan node pertama (ID 1).
    printf("Membuat graph NimonsGram...\n");
    createGraph(1, &nimonsGraph);

    // Langkah 2: Menambahkan beberapa relasi pertemanan (edge).
    // Ini akan secara otomatis membuat node baru jika belum ada.
    printf("Menambahkan relasi pertemanan...\n");
    insertEdge(&nimonsGraph, 1, 2); // 1 follow 2
    insertEdge(&nimonsGraph, 1, 3); // 1 follow 3
    insertEdge(&nimonsGraph, 2, 3); // 2 follow 3
    insertEdge(&nimonsGraph, 4, 3); // 4 follow 3
    insertEdge(&nimonsGraph, 5, 2); // 5 follow 2
    insertEdge(&nimonsGraph, 5, 3); // 5 follow 3
    insertEdge(&nimonsGraph, 4, 2); // 4 follow 2
    insertEdge(&nimonsGraph, 3, 4); // 3 follow 4
    insertEdge(&nimonsGraph, 3, 5); // 3 follow 5

    // Langkah 3: Cetak graph untuk verifikasi.
    printf("\nGraph saat ini:\n");
    printGraph(nimonsGraph);

    // Langkah 4: Lakukan analisis untuk menemukan Nimons Paling Digemari (NPD)
    // dan Nimons Misterius.
    int maxFollower, minFollowing;
    AdrNode npd = findNPD(nimonsGraph, &maxFollower);
    AdrNode misterius = findMisterius(nimonsGraph, &minFollowing);

    // Langkah 5: Cetak hasil analisis.
    printf("\nHasil Analisis:\n");
    if (npd != NIL)
    {
        printf("Si NPD adalah Nimons %d dengan %d followers.\n", ID(npd), maxFollower);
    }
    else
    {
        printf("Tidak ada Nimons NPD.\n");
    }

    if (misterius != NIL)
    {
        printf("Si Misterius adalah Nimons %d dengan %d following.\n", ID(misterius), minFollowing);
    }
    else
    {
        printf("Tidak ada Nimons Misterius.\n");
    }

    // Di sini bisa ditambahkan dealokasi graph jika diperlukan.
    // Contoh: deleteNode(&nimonsGraph, 1); ...dst

    return 0;
}
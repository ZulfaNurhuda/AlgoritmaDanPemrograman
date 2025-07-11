/**
 * --------------------------------------------------------------
 * | @file graphDriver.c                                        |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Driver program untuk menguji fungsionalitas ADT Graph      |
 * | yang diimplementasikan menggunakan Adjacency Matrix.       |
 * --------------------------------------------------------------
 */

#include "graph.h"
#include <stdio.h>

/**
 * @brief Mencetak adjacency matrix dari sebuah graph.
 * @param g Pointer ke Graph yang akan dicetak.
 */
void printGraph(Graph *g)
{
    printf("Adjacency Matrix:\n");
    // Iterasi melalui setiap baris dan kolom matriks.
    for (int i = 0; i < g->nVertices; i++)
    {
        for (int j = 0; j < g->nVertices; j++)
        {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Deklarasi variabel graph.
    Graph myGraph;

    // Langkah 1: Inisialisasi graph dengan 5 simpul.
    printf("Menginisialisasi graph dengan 5 simpul...\n");
    initGraph(&myGraph, 5);

    // Langkah 2: Tambahkan beberapa sisi (edge) dengan bobot.
    printf("Menambahkan sisi-sisi ke dalam graph...\n");
    addEdge(&myGraph, 0, 1, 10);
    addEdge(&myGraph, 0, 2, 20);
    addEdge(&myGraph, 1, 2, 30);
    addEdge(&myGraph, 1, 3, 40);
    addEdge(&myGraph, 3, 4, 50);

    // Langkah 3: Cetak graph untuk verifikasi.
    printf("\nGraph setelah penambahan sisi:\n");
    printGraph(&myGraph);

    // Langkah 4: Cek ketetanggaan antara beberapa simpul.
    printf("\nMemeriksa ketetanggaan...\n");
    printf("Apakah 0 dan 1 bertetangga? %s (Bobot: %d)\n", isAdjacent(&myGraph, 0, 1) ? "Ya" : "Tidak", isAdjacent(&myGraph, 0, 1));
    printf("Apakah 2 dan 4 bertetangga? %s (Bobot: %d)\n", isAdjacent(&myGraph, 2, 4) ? "Ya" : "Tidak", isAdjacent(&myGraph, 2, 4));

    // Langkah 5: Hapus sebuah sisi dan cetak ulang graph.
    printf("\nMenghapus sisi antara 1 dan 2...\n");
    int removedWeight;
    removeEdge(&myGraph, 1, 2, &removedWeight);
    printf("Sisi yang dihapus memiliki bobot: %d\n", removedWeight);
    
    printf("\nGraph setelah menghapus sisi antara 1 dan 2:\n");
    printGraph(&myGraph);

    return 0;
}
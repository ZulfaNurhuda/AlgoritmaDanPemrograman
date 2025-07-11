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
#include <stdio.h> // Untuk printf

/**
 * @brief Mencetak representasi matriks ketetanggaan (adjacency matrix) dari sebuah graph.
 * @details Fungsi ini menampilkan seluruh isi matriks ketetanggaan ke standar output,
 *          yang merepresentasikan hubungan antar simpul dalam graph.
 *          Nilai pada baris `i` dan kolom `j` menunjukkan bobot sisi dari simpul `i` ke `j`.
 *          Jika tidak ada sisi, nilai NO_EDGE (-1) akan ditampilkan.
 * @param graph Pointer ke Graph yang akan dicetak.
 *              Jika graph NULL atau tidak memiliki simpul, perilaku tidak terdefinisi
 *              (diasumsikan graph valid dan memiliki nVertices > 0 untuk pencetakan).
 * @note Fungsi ini tidak melakukan validasi input graph.
 */
void printGraph(Graph *graph)
{
    // Pastikan graph tidak NULL dan memiliki simpul sebelum mencetak.
    if (graph == NULL || graph->nVertices <= 0)
    {
        printf("Graph tidak valid atau kosong.\n");
        return;
    }

    printf("Adjacency Matrix:\n");
    // Iterasi melalui setiap baris (source vertex) dan kolom (destination vertex) matriks.
    for (int i = 0; i < graph->nVertices; i++)
    {
        for (int j = 0; j < graph->nVertices; j++)
        {
            // Cetak bobot sisi, atau representasi NO_EDGE.
            printf("%3d ", graph->adjMatrix[i][j]); // %3d untuk format agar lebih rapi
        }
        printf("\n"); // Baris baru setelah setiap baris matriks selesai dicetak.
    }
}

/**
 * @brief Fungsi utama untuk menjalankan serangkaian tes pada ADT Graph.
 * @return int Mengembalikan 0 sebagai tanda eksekusi program berhasil.
 */
int main(void)
{
    // Deklarasi variabel graph.
    Graph myGraph;

    // Langkah 1: Inisialisasi graph dengan 5 simpul.
    printf("Menginisialisasi graph dengan 5 simpul...\n");
    initGraph(&myGraph, 5); // Graph akan memiliki vertex 0, 1, 2, 3, 4.

    // Langkah 2: Tambahkan beberapa sisi (edge) berarah dengan bobot.
    printf("Menambahkan sisi-sisi ke dalam graph...\n");
    addEdge(&myGraph, 0, 1, 10); // Sisi dari 0 ke 1 dengan bobot 10
    addEdge(&myGraph, 0, 2, 20); // Sisi dari 0 ke 2 dengan bobot 20
    addEdge(&myGraph, 1, 2, 30); // Sisi dari 1 ke 2 dengan bobot 30
    addEdge(&myGraph, 1, 3, 40); // Sisi dari 1 ke 3 dengan bobot 40
    addEdge(&myGraph, 3, 4, 50); // Sisi dari 3 ke 4 dengan bobot 50
    // Contoh menambahkan sisi ke vertex yang sama atau sisi paralel jika diizinkan (tidak umum untuk adj matrix sederhana)
    // addEdge(&myGraph, 2, 2, 5); // Loop pada vertex 2

    // Langkah 3: Cetak graph untuk verifikasi status saat ini.
    printf("\nGraph setelah penambahan sisi:\n");
    printGraph(&myGraph);

    // Langkah 4: Cek ketetanggaan antara beberapa simpul.
    printf("\nMemeriksa ketetanggaan...\n");
    int weight01 = isAdjacent(&myGraph, 0, 1);
    printf("Apakah 0 dan 1 bertetangga? %s (Bobot: %d)\n", (weight01 != 0) ? "Ya" : "Tidak", weight01);

    int weight24 = isAdjacent(&myGraph, 2, 4);
    printf("Apakah 2 dan 4 bertetangga? %s (Bobot: %d)\n", (weight24 != 0) ? "Ya" : "Tidak", weight24);

    int weightNonExistent = isAdjacent(&myGraph, 4, 0); // Sisi yang tidak ada
    printf("Apakah 4 dan 0 bertetangga? %s (Bobot: %d)\n", (weightNonExistent != 0) ? "Ya" : "Tidak", weightNonExistent);

    // Langkah 5: Hapus sebuah sisi dan cetak ulang graph untuk verifikasi.
    printf("\nMenghapus sisi antara 1 dan 2...\n");
    int removedWeight;
    removeEdge(&myGraph, 1, 2, &removedWeight); // Hapus sisi dari 1 ke 2
    printf("Sisi yang dihapus (1->2) memiliki bobot: %d\n", removedWeight);
    
    printf("\nGraph setelah menghapus sisi antara 1 dan 2:\n");
    printGraph(&myGraph);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
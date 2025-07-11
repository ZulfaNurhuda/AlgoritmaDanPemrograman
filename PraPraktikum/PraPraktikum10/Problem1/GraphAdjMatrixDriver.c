#include "GraphAdjMatrix.h"

/* Untuk keperluan menampilkan isi Graph */
#include <stdio.h>

/**
 * @brief Menampilkan representasi matriks ketetanggaan (adjacency matrix) dari suatu graf.
 *
 * Fungsi ini digunakan untuk mencetak seluruh isi dari matriks ketetanggaan ke layar,
 * yang menunjukkan hubungan antar simpul dalam graf.
 *
 * Nilai pada baris `i` dan kolom `j` bernilai:
 * - 1 jika terdapat edge (sisi) antara simpul `i` dan `j`,
 * - 0 jika tidak terdapat edge di antara keduanya.
 *
 * Catatan:
 * - Jika graf bersifat **tidak berarah**, maka matrix-nya simetris (i.e., M[i][j] == M[j][i]).
 * - Fungsi ini hanya mencetak matriks, tidak memvalidasi input.
 *
 * @param graph Pointer ke struktur Graph yang akan dicetak.
 */
static void printGraph(Graph *graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numberOfVertices; i++)
    {
        for (int j = 0; j < graph->numberOfVertices; j++)
        {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    Graph g;

    // Inisialisasi graph dengan 5 simpul (vertex 0 sampai 4)
    initializeGraph(&g, 5);

    // Tambahkan edge antara simpul-simpul berikut:
    // 0-1, 0-2, 1-2, 1-3, 3-4
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 3, 4);

    // Tampilkan adjacency matrix hasil
    printGraph(&g);

    // Cek ketetanggaan antar simpul
    printf("Apakah 0 dan 1 bertetangga? %s\n", isAdjacent(&g, 0, 1) ? "Ya" : "Tidak");
    printf("Apakah 2 dan 4 bertetangga? %s\n", isAdjacent(&g, 2, 4) ? "Ya" : "Tidak");

    // Hapus edge antara simpul 1 dan 2
    removeEdge(&g, 1, 2);

    // Cetak kembali adjacency matrix setelah penghapusan edge
    printf("\nSetelah menghapus edge antara 1 dan 2:\n");
    printGraph(&g);

    return 0;
}
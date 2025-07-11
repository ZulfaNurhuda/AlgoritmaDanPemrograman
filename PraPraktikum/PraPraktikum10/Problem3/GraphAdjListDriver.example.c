#include <stdio.h>
#include "GraphAdjList.h"

#define COLOR_GREEN "\e[0;32m"
#define COLOR_RESET "\e[0m"

/**
 * @brief Menampilkan struktur graf yang direpresentasikan dalam bentuk adjacency list.
 *
 * Fungsi ini mencetak semua vertex beserta daftar tetangganya.
 * Jika pointer graph bernilai NULL, akan ditampilkan pesan bahwa graph tidak tersedia.
 *
 * @param graph Pointer ke objek Graph.
 */
static void printGraph(Graph *graph)
{
    if (graph == NULL)
    {
        printf("Graph tidak ada.\n");
        return;
    }

    printf("Adjacency List dari Graph:\n");
    for (int i = 0; i < graph->numberOfVertices; i++)
    {
        AddressNode current = graph->adjList[i];
        printf("Vertex %d: [", i);
        while (current != NULL)
        {
            printf("%d", current->vertex);
            current = current->next;
            if (current != NULL)
            {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int main(void)
{
    int numVertices = 5;
    Graph *myGraph;

    // 1. Membuat graph dengan 5 vertex
    printf("--- 1. Membuat Graph dengan %d vertices ---\n", numVertices);
    myGraph = createGraph(numVertices); // Alokasi graph dan inisialisasi adjacency list

    if (myGraph != NULL)
    {
        printf("Graph berhasil dibuat.\n");
        printGraph(myGraph); // Menampilkan adjacency list (kosong)
    }
    else
    {
        printf("Gagal membuat graph.\n");
        return 1; // Keluar program jika gagal alokasi
    }

    // 2. Menambahkan edges ke graph (undirected)
    printf("\n--- 2. Menambahkan Edges ---\n");
    addEdge(myGraph, 0, 1); // Tambah edge antara vertex 0 dan 1
    addEdge(myGraph, 0, 4); // Tambah edge antara vertex 0 dan 4
    addEdge(myGraph, 1, 2); // Tambah edge antara vertex 1 dan 2
    addEdge(myGraph, 1, 3); // Tambah edge antara vertex 1 dan 3
    addEdge(myGraph, 1, 4); // Tambah edge antara vertex 1 dan 4
    addEdge(myGraph, 2, 3); // Tambah edge antara vertex 2 dan 3
    addEdge(myGraph, 3, 4); // Tambah edge antara vertex 3 dan 4

    printf("Graph setelah ditambahkan edges:\n");
    printGraph(myGraph); // Menampilkan adjacency list setelah penambahan edge

    // 3. Menguji penambahan edge yang tidak valid
    printf("\n--- 3. Menguji Penambahan Edge Tidak Valid ---\n");
    printf("Mencoba menambahkan edge (0, 6)...\n");
    addEdge(myGraph, 0, 6); // Vertex 6 tidak valid karena di luar range
    printGraph(myGraph);    // Graph tidak berubah karena edge tidak valid

    // 4. Menghapus semua memori yang dialokasikan untuk graph
    printf("\n--- 4. Melepaskan Memori Graph ---\n");
    freeGraph(myGraph); // Dealokasi seluruh adjacency list dan graph
    myGraph = NULL;     // Hindari dangling pointer
    printf("Memori graph telah dilepaskan.\n");
    printGraph(myGraph); // Mencetak: "Graph tidak ada."

    printf(COLOR_GREEN "\n[ ☑ ] - Pengujian selesai.\n" COLOR_RESET);

    return 0;
}
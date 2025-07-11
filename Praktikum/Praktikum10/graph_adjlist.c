/**
 * --------------------------------------------------------------
 * | @file graph_adjlist.c                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Graph menggunakan representasi Adjacency  |
 * | List. Graph yang diimplementasikan adalah tidak berarah    |
 * | dan tidak berbobot.                                        |
 * --------------------------------------------------------------
 */

#include "graph_adjlist.h"
#include <stdio.h>  // Untuk printf (digunakan pada addEdge jika gagal)
#include <stdlib.h> // Untuk malloc dan free

/**
 * @brief Membuat sebuah node baru untuk adjacency list.
 * @details Node ini akan menyimpan nomor vertex tujuan dan pointer ke node berikutnya
 *          dalam daftar ketetanggaan.
 * @param vertexValue Nilai (nomor) vertex yang akan disimpan di dalam node.
 * @return Node* Pointer ke Node yang baru dibuat, atau NULL jika alokasi memori gagal.
 * @note I.S. : vertexValue terdefinisi.
 * @note F.S. : Sebuah Node dialokasikan dengan `vertex = vertexValue` dan `next = NULL`.
 */
Node *createNode(int vertexValue)
{
    // Alokasi memori untuk node baru.
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        // Gagal alokasi, kembalikan NULL.
        // Pertimbangkan untuk menambahkan penanganan error yang lebih robust jika diperlukan.
        return NULL;
    }

    // Inisialisasi nilai vertex dan pointer next dari node baru.
    newNode->vertex = vertexValue;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Membuat sebuah graph baru dengan jumlah vertex tertentu.
 * @details Graph direpresentasikan sebagai array dari adjacency list.
 *          Setiap elemen array adalah pointer ke head dari linked list yang berisi
 *          tetangga-tetangga dari vertex tersebut.
 * @param numberOfVertices Jumlah total vertex yang akan ada dalam graph.
 *                         Diasumsikan numberOfVertices >= 0.
 * @return Graph* Pointer ke Graph yang baru dibuat, atau NULL jika alokasi memori gagal.
 * @note I.S. : numberOfVertices terdefinisi.
 * @note F.S. : Graph dialokasikan dengan `numVertices = numberOfVertices`.
 *              `adjList` dialokasikan sebagai array Node* berukuran numberOfVertices.
 *              Setiap `adjList[i]` diinisialisasi ke NULL.
 */
Graph *createGraph(int numberOfVertices)
{
    // Alokasi memori untuk struktur Graph.
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    if (newGraph == NULL)
    {
        return NULL; // Gagal alokasi Graph struct.
    }

    // Inisialisasi jumlah vertex.
    newGraph->numVertices = numberOfVertices;

    // Alokasi memori untuk array adjacency list (array of Node pointers).
    // Ukuran array adalah numberOfVertices.
    newGraph->adjList = (Node **)malloc(numberOfVertices * sizeof(Node *));
    if (newGraph->adjList == NULL)
    {
        // Jika alokasi array list gagal, bebaskan memori graph struct yang sudah teralokasi.
        free(newGraph);
        return NULL;
    }

    // Inisialisasi setiap head dari adjacency list dengan NULL (menandakan list kosong).
    for (int i = 0; i < numberOfVertices; i++)
    {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

/**
 * @brief Menambahkan sebuah edge (sisi) tak berarah antara dua vertex.
 * @details Karena graph tak berarah, sisi ditambahkan ke adjacency list
 *          dari kedua vertex. Sisi baru ditambahkan di akhir list.
 * @param graph Pointer ke Graph yang akan dimodifikasi.
 * @param vertex1 Vertex pertama dari sisi.
 * @param vertex2 Vertex kedua dari sisi.
 * @note I.S. : graph, vertex1, vertex2 terdefinisi.
 *              vertex1 dan vertex2 harus merupakan indeks yang valid dalam graph.
 * @note F.S. : Sisi (vertex1, vertex2) ditambahkan ke graph.
 *              Jika alokasi node gagal atau vertex tidak valid, pesan error dicetak.
 */
void addEdge(Graph *graph, int vertex1, int vertex2)
{
    // Validasi dasar: graph tidak boleh NULL dan kedua vertex harus dalam rentang yang valid.
    if (graph == NULL || vertex1 >= graph->numVertices || vertex2 >= graph->numVertices || vertex1 < 0 || vertex2 < 0)
    {
        printf("Penambahan edge gagal.\n"); // Pesan error sesuai spesifikasi.
        return;
    }

    // Tambahkan edge dari vertex1 ke vertex2.
    // Buat node baru untuk vertex2 yang akan ditambahkan ke list vertex1.
    Node *newNodeForV1 = createNode(vertex2);
    if (newNodeForV1 == NULL) {
        printf("Penambahan edge gagal.\n"); // Gagal alokasi node.
        return;
    }
    // Tambahkan node baru ke akhir adjacency list dari vertex1.
    if (graph->adjList[vertex1] == NULL) // Jika list vertex1 kosong
    {
        graph->adjList[vertex1] = newNodeForV1;
    }
    else // Jika list vertex1 tidak kosong, cari elemen terakhir
    {
        Node *temp = graph->adjList[vertex1];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNodeForV1;
    }

    // Tambahkan edge dari vertex2 ke vertex1 (karena graph tak berarah).
    // Buat node baru untuk vertex1 yang akan ditambahkan ke list vertex2.
    Node *newNodeForV2 = createNode(vertex1);
    if (newNodeForV2 == NULL) {
        // Jika pembuatan node kedua gagal, batalkan penambahan edge pertama (rollback).
        // Ini penting untuk menjaga konsistensi data jika terjadi kegagalan parsial.
        // Hapus newNodeForV1 dari adjList[vertex1]
        if (graph->adjList[vertex1] == newNodeForV1) { // Jika newNodeForV1 adalah head
            graph->adjList[vertex1] = NULL;
        } else { // Jika newNodeForV1 bukan head, cari dan hapus
            Node *temp = graph->adjList[vertex1];
            while (temp->next != newNodeForV1) {
                temp = temp->next;
            }
            temp->next = NULL; // Hapus referensi ke newNodeForV1
        }
        free(newNodeForV1); // Bebaskan memori yang sudah dialokasi untuk newNodeForV1
        printf("Penambahan edge gagal.\n"); // Gagal alokasi node.
        return;
    }
    // Tambahkan node baru ke akhir adjacency list dari vertex2.
    if (graph->adjList[vertex2] == NULL) // Jika list vertex2 kosong
    {
        graph->adjList[vertex2] = newNodeForV2;
    }
    else // Jika list vertex2 tidak kosong, cari elemen terakhir
    {
        Node *temp = graph->adjList[vertex2];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNodeForV2;
    }
}

/**
 * @brief Membebaskan semua memori yang dialokasikan untuk graph.
 * @details Fungsi ini akan mengiterasi melalui setiap adjacency list, membebaskan
 *          semua node di dalamnya, kemudian membebaskan array adjacency list,
 *          dan terakhir membebaskan struktur Graph itu sendiri.
 * @param graph Pointer ke Graph yang akan dibebaskan memorinya.
 *              Jika graph adalah NULL, fungsi tidak melakukan apa-apa.
 * @note I.S. : graph mungkin telah dialokasikan atau NULL.
 * @note F.S. : Semua memori yang terkait dengan graph telah dibebaskan.
 *              Pointer graph sebaiknya diatur ke NULL setelah pemanggilan fungsi ini
 *              oleh pemanggil untuk menghindari dangling pointer.
 */
void freeGraph(Graph *graph)
{
    // Jika graph sudah NULL, tidak ada yang perlu dilakukan.
    if (graph == NULL)
    {
        return;
    }

    // Iterasi melalui setiap vertex dalam graph.
    for (int i = 0; i < graph->numVertices; i++)
    {
        // Bebaskan semua node dalam adjacency list untuk vertex i.
        Node *current = graph->adjList[i];
        while (current != NULL)
        {
            Node *temp = current;    // Simpan pointer ke node saat ini.
            current = current->next; // Pindah ke node berikutnya.
            free(temp);              // Bebaskan memori node yang disimpan.
        }
    }

    // Bebaskan array dari adjacency list itu sendiri.
    free(graph->adjList);
    // Bebaskan struktur Graph.
    free(graph);
}

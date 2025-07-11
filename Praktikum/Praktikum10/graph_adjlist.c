/**
 * --------------------------------------------------------------
 * | @file graph_adjlist.c                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Graph menggunakan representasi Adjacency  |
 * | List.                                                      |
 * --------------------------------------------------------------
 */

#include "graph_adjlist.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Membuat sebuah node baru untuk adjacency list.
 * @param v Nilai vertex yang akan disimpan di dalam node.
 * @return Pointer ke Node yang baru dibuat, atau NULL jika alokasi gagal.
 */
Node *createNode(int v)
{
    // Alokasi memori untuk node baru.
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        // Gagal alokasi, kembalikan NULL.
        return NULL;
    }

    // Inisialisasi nilai vertex dan pointer next.
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Membuat sebuah graph baru dengan jumlah vertex tertentu.
 * @param numVertices Jumlah total vertex dalam graph.
 * @return Pointer ke Graph yang baru dibuat, atau NULL jika alokasi gagal.
 */
Graph *createGraph(int numVertices)
{
    // Alokasi memori untuk struktur Graph.
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    if (newGraph == NULL)
    {
        return NULL;
    }

    // Inisialisasi jumlah vertex.
    newGraph->numVertices = numVertices;
    // Alokasi memori untuk array adjacency list.
    newGraph->adjList = (Node **)malloc(numVertices * sizeof(Node *));
    if (newGraph->adjList == NULL)
    {
        // Jika alokasi list gagal, bebaskan memori graph yang sudah teralokasi.
        free(newGraph);
        return NULL;
    }

    // Inisialisasi setiap head dari adjacency list dengan NULL.
    for (int i = 0; i < numVertices; i++)
    {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

/**
 * @brief Menambahkan sebuah edge (sisi) tak berarah antara dua vertex.
 * @param graph Pointer ke Graph.
 * @param v1 Vertex pertama.
 * @param v2 Vertex kedua.
 */
void addEdge(Graph *graph, int v1, int v2)
{
    // Validasi dasar: graph tidak boleh NULL dan vertex harus dalam rentang yang valid.
    if (graph == NULL || v1 >= graph->numVertices || v2 >= graph->numVertices || v1 < 0 || v2 < 0)
    {
        printf("Penambahan edge gagal.\n");
        return;
    }

    // Tambahkan edge dari v1 ke v2.
    // Buat node baru untuk v2.
    Node *newNode1 = createNode(v2);
    if (newNode1 == NULL) {
        printf("Penambahan edge gagal.\n");
        return;
    }
    // Tambahkan node ke akhir list dari v1.
    if (graph->adjList[v1] == NULL)
    {
        graph->adjList[v1] = newNode1;
    }
    else
    {
        Node *temp = graph->adjList[v1];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode1;
    }

    // Tambahkan edge dari v2 ke v1 (karena graph tak berarah).
    // Buat node baru untuk v1.
    Node *newNode2 = createNode(v1);
    if (newNode2 == NULL) {
        // Jika pembuatan node kedua gagal, batalkan penambahan edge pertama.
        // Ini adalah langkah rollback yang penting untuk menjaga konsistensi.
        if (graph->adjList[v1] == newNode1) {
            graph->adjList[v1] = NULL;
        } else {
            Node *temp = graph->adjList[v1];
            while (temp->next != newNode1) {
                temp = temp->next;
            }
            temp->next = NULL;
        }
        free(newNode1);
        printf("Penambahan edge gagal.\n");
        return;
    }
    // Tambahkan node ke akhir list dari v2.
    if (graph->adjList[v2] == NULL)
    {
        graph->adjList[v2] = newNode2;
    }
    else
    {
        Node *temp = graph->adjList[v2];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode2;
    }
}

/**
 * @brief Membebaskan semua memori yang dialokasikan untuk graph.
 * @param graph Pointer ke Graph yang akan dibebaskan.
 */
void freeGraph(Graph *graph)
{
    // Jika graph sudah NULL, tidak ada yang perlu dilakukan.
    if (graph == NULL)
        return;

    // Iterasi melalui setiap vertex.
    for (int i = 0; i < graph->numVertices; i++)
    {
        // Bebaskan semua node dalam adjacency list untuk vertex i.
        Node *current = graph->adjList[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    // Bebaskan array adjacency list itu sendiri.
    free(graph->adjList);
    // Bebaskan struktur Graph.
    free(graph);
}

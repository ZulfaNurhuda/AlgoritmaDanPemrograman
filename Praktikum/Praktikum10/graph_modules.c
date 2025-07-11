/**
 * --------------------------------------------------------------
 * | @file graph_modules.c                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Modul tambahan untuk operasi pada ADT Graph, seperti       |
 * | mencetak dan menghapus edge.                               |
 * --------------------------------------------------------------
 */

#include "graph_modules.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Mencetak representasi adjacency list dari sebuah graph.
 * @param graph Pointer ke Graph yang akan dicetak.
 */
void printGraph(Graph *graph)
{
    // Validasi graph.
    if (graph == NULL)
    {
        printf("Graph is NULL\n");
        return;
    }

    // Iterasi melalui setiap vertex dalam graph.
    for (int i = 0; i < graph->numVertices; i++)
    {
        // Cetak nomor vertex saat ini.
        printf("%d: ", i);

        // Mulai dari head adjacency list untuk vertex ini.
        Node *current = graph->adjList[i];
        // Penanda untuk mengetahui apakah vertex ini memiliki edge.
        bool edgeExists = false;

        // Telusuri semua node (tetangga) dalam list.
        while (current != NULL)
        {
            // Tandai bahwa ada edge.
            edgeExists = true;

            // Cetak vertex tetangga.
            printf("%d", current->vertex);
            // Jika ada node berikutnya, cetak panah.
            if (current->next != NULL)
            {
                printf(" -> ");
            }
            // Pindah ke node berikutnya.
            current = current->next;
        }

        // Jika tidak ada edge sama sekali untuk vertex ini.
        if (!edgeExists)
        {
            printf("Kosong");
        }
        printf("\n");
    }
}

/**
 * @brief Menghapus sebuah edge (sisi) tak berarah antara v1 dan v2.
 * @param graph Pointer ke Graph yang akan dimodifikasi.
 * @param v1 Vertex pertama.
 * @param v2 Vertex kedua.
 */
void deleteEdge(Graph *graph, int v1, int v2)
{
    // Validasi input dasar.
    if (graph == NULL || v1 < 0 || v1 >= graph->numVertices || v2 < 0 || v2 >= graph->numVertices)
    {
        printf("Penghapusan edge gagal.\n");
        return;
    }

    // Langkah 1: Hapus edge dari v1 ke v2.
    Node *current = graph->adjList[v1];
    Node *prev = NULL;
    bool edgeFound = false;

    // Cari node v2 di dalam list v1.
    while (current != NULL && !edgeFound)
    {
        if (current->vertex == v2)
        {
            // Jika node ditemukan di head list.
            if (prev == NULL)
            {
                graph->adjList[v1] = current->next;
            }
            // Jika node ditemukan di tengah atau akhir list.
            else
            {
                prev->next = current->next;
            }
            // Bebaskan memori node yang dihapus.
            free(current);
            edgeFound = true;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    // Langkah 2: Jika edge dari v1 ke v2 ditemukan, hapus juga edge dari v2 ke v1.
    if (edgeFound)
    {
        current = graph->adjList[v2];
        prev = NULL;
        bool secondEdgeFound = false;
        // Cari node v1 di dalam list v2.
        while (current != NULL && !secondEdgeFound)
        {
            if (current->vertex == v1)
            {
                if (prev == NULL)
                {
                    graph->adjList[v2] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                free(current);
                secondEdgeFound = true;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
    // Jika edge dari v1 ke v2 tidak ada, maka penghapusan gagal.
    else
    {
        printf("Penghapusan edge gagal.\n");
    }
}

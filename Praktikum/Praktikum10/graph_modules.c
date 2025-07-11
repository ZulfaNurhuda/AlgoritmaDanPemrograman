/**
 * --------------------------------------------------------------
 * | @file graph_modules.c                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Modul tambahan untuk operasi pada ADT Graph yang           |
 * | direpresentasikan menggunakan Adjacency List. Termasuk     |
 * | fungsi untuk mencetak graph dan menghapus sisi (edge).     |
 * --------------------------------------------------------------
 */

#include "graph_modules.h"
#include <stdio.h>  // Untuk printf
#include <stdlib.h> // Untuk free

/**
 * @brief Mencetak representasi adjacency list dari sebuah graph.
 * @details Fungsi ini mengiterasi melalui setiap vertex dalam graph dan
 *          mencetak daftar tetangganya. Format output per vertex adalah:
 *          `vertex_idx: tetangga1 -> tetangga2 -> ...`
 *          Jika sebuah vertex tidak memiliki tetangga, akan dicetak `Kosong`.
 * @param graph Pointer ke Graph yang akan dicetak.
 * @note I.S. : graph mungkin NULL atau graph terdefinisi.
 * @note F.S. : Isi graph dicetak ke layar. Jika graph NULL, pesan "Graph is NULL" dicetak.
 *              Setiap baris diakhiri dengan newline.
 */
void printGraph(Graph *graph)
{
    // Validasi apakah pointer graph NULL.
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

        // Mulai dari head adjacency list untuk vertex i.
        Node *current = graph->adjList[i];
        // Penanda untuk mengetahui apakah vertex ini memiliki setidaknya satu edge (tetangga).
        bool edgeExists = false;

        // Telusuri semua node (tetangga) dalam adjacency list untuk vertex i.
        while (current != NULL)
        {
            // Tandai bahwa ada edge.
            edgeExists = true;

            // Cetak nomor vertex tetangga.
            printf("%d", current->vertex);
            // Jika ada node tetangga berikutnya dalam list, cetak separator " -> ".
            if (current->next != NULL)
            {
                printf(" -> ");
            }
            // Pindah ke node tetangga berikutnya.
            current = current->next;
        }

        // Jika tidak ada edge (tetangga) sama sekali untuk vertex ini.
        if (!edgeExists)
        {
            printf("Kosong"); // Sesuai format output yang diharapkan.
        }
        printf("\n"); // Pindah ke baris baru setelah mencetak semua tetangga untuk vertex i.
    }
}

/**
 * @brief Menghapus sebuah sisi (edge) tak berarah antara vertex1 dan vertex2.
 * @details Karena graph tak berarah, fungsi ini akan menghapus node vertex2 dari
 *          adjacency list vertex1, dan menghapus node vertex1 dari adjacency list vertex2.
 *          Jika salah satu atau kedua vertex tidak valid, atau graph NULL, atau
 *          sisi tidak ditemukan, fungsi akan mencetak "Penghapusan edge gagal.\n".
 * @param graph Pointer ke Graph yang akan dimodifikasi.
 * @param vertex1 Nomor vertex pertama dari sisi yang akan dihapus.
 * @param vertex2 Nomor vertex kedua dari sisi yang akan dihapus.
 * @note I.S. : graph, vertex1, vertex2 terdefinisi.
 * @note F.S. : Sisi antara vertex1 dan vertex2 dihapus dari graph.
 *              Jika penghapusan gagal, pesan error dicetak.
 */
void deleteEdge(Graph *graph, int vertex1, int vertex2)
{
    // Validasi input dasar: graph tidak NULL dan kedua vertex valid.
    if (graph == NULL || vertex1 < 0 || vertex1 >= graph->numVertices || vertex2 < 0 || vertex2 >= graph->numVertices)
    {
        printf("Penghapusan edge gagal.\n"); // Sesuai pesan error spesifikasi.
        return;
    }

    // Langkah 1: Hapus edge dari vertex1 ke vertex2 (hapus node vertex2 dari list vertex1).
    Node *current = graph->adjList[vertex1];
    Node *prev = NULL;
    bool edge1Found = false;

    // Cari node vertex2 di dalam adjacency list dari vertex1.
    while (current != NULL && !edge1Found)
    {
        if (current->vertex == vertex2)
        {
            // Jika node yang dicari ditemukan di head list.
            if (prev == NULL)
            {
                graph->adjList[vertex1] = current->next;
            }
            // Jika node yang dicari ditemukan di tengah atau akhir list.
            else
            {
                prev->next = current->next;
            }
            // Bebaskan memori node yang dihapus.
            free(current);
            edge1Found = true; // Tandai bahwa sisi pertama ditemukan dan dihapus.
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    // Langkah 2: Jika edge dari vertex1 ke vertex2 berhasil ditemukan dan dihapus,
    //            maka hapus juga edge dari vertex2 ke vertex1 (hapus node vertex1 dari list vertex2).
    if (edge1Found)
    {
        current = graph->adjList[vertex2];
        prev = NULL;
        bool edge2Found = false;
        // Cari node vertex1 di dalam adjacency list dari vertex2.
        while (current != NULL && !edge2Found)
        {
            if (current->vertex == vertex1)
            {
                if (prev == NULL)
                {
                    graph->adjList[vertex2] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                free(current);
                edge2Found = true; // Tandai bahwa sisi kedua juga ditemukan dan dihapus.
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        // Jika sisi kedua (v2 ke v1) tidak ditemukan setelah sisi pertama (v1 ke v2) dihapus,
        // ini mengindikasikan inkonsistensi data atau graph tidak simetris sebagaimana mestinya.
        // Namun, berdasarkan logika soal, jika v1-v2 ada, maka v2-v1 juga seharusnya ada.
        // Jika edge2Found adalah false di sini, itu bisa jadi masalah, tapi kode asli tidak
        // secara eksplisit menangani kasus ini dengan pesan error tambahan selain yang pertama.
    }
    // Jika edge dari vertex1 ke vertex2 tidak ada (edge1Found == false),
    // maka penghapusan dianggap gagal.
    else
    {
        printf("Penghapusan edge gagal.\n");
    }
}

/**
 * --------------------------------------------------------------
 * | @file graph.c                                              |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Graph menggunakan representasi Adjacency  |
 * | Matrix untuk graph berbobot dan berarah.                   |
 * --------------------------------------------------------------
 */

#include "graph.h"

#define NO_EDGE -1

/**
 * @brief Menginisialisasi sebuah graph dengan jumlah vertex tertentu.
 * @details Matriks adjasensi diinisialisasi dengan nilai NO_EDGE (-1)
 *          untuk menandakan tidak ada sisi (edge) antar vertex.
 * @param g Pointer ke Graph yang akan diinisialisasi.
 * @param nVertices Jumlah vertex yang akan dimiliki graph.
 */
void initGraph(Graph *g, int nVertices)
{
    if (g != NULL)
    {
        // Batasi jumlah vertex antara 0 dan MAX_VERTICES.
        if (nVertices < 0)
        {
            nVertices = 0;
        }
        if (nVertices > MAX_VERTICES)
        {
            nVertices = MAX_VERTICES;
        }

        g->nVertices = nVertices;
        // Inisialisasi seluruh matriks dengan NO_EDGE.
        for (int i = 0; i < MAX_VERTICES; i++)
        {
            for (int j = 0; j < MAX_VERTICES; j++)
            {
                g->adjMatrix[i][j] = NO_EDGE;
            }
        }
    }
}

/**
 * @brief Memeriksa apakah sebuah vertex valid (dalam rentang 0 sampai nVertices-1).
 * @param G Graph yang akan diperiksa.
 * @param v Nomor vertex yang akan divalidasi.
 * @return 1 jika valid, 0 jika tidak.
 */
int isValidVertex(Graph G, int v)
{
    return (v >= 0 && v < G.nVertices);
}

/**
 * @brief Menambahkan sebuah sisi berarah dari 'src' ke 'dest' dengan bobot 'weight'.
 * @param g Pointer ke Graph yang akan dimodifikasi.
 * @param src Vertex sumber.
 * @param dest Vertex tujuan.
 * @param weight Bobot sisi.
 */
void addEdge(Graph *g, int src, int dest, int weight)
{
    if (g != NULL)
    {
        // Tambahkan sisi hanya jika kedua vertex valid.
        if (isValidVertex(*g, src) && isValidVertex(*g, dest))
        {
            g->adjMatrix[src][dest] = weight;
        }
    }
}

/**
 * @brief Menghapus sebuah sisi berarah dari 'src' ke 'dest'.
 * @param g Pointer ke Graph yang akan dimodifikasi.
 * @param src Vertex sumber.
 * @param dest Vertex tujuan.
 * @param weight Pointer untuk menyimpan bobot dari sisi yang dihapus.
 */
void removeEdge(Graph *g, int src, int dest, int *weight)
{
    if (g != NULL && weight != NULL)
    {
        if (isValidVertex(*g, src) && isValidVertex(*g, dest))
        {
            // Simpan bobot sisi yang akan dihapus.
            *weight = g->adjMatrix[src][dest];
            // Hapus sisi dengan mengaturnya ke NO_EDGE.
            g->adjMatrix[src][dest] = NO_EDGE;
        }
        else
        {
            // Jika vertex tidak valid, kembalikan bobot NO_EDGE.
            *weight = NO_EDGE;
        }
    }
}

/**
 * @brief Memeriksa apakah ada sisi dari 'src' ke 'dest'.
 * @param g Pointer ke Graph.
 * @param src Vertex sumber.
 * @param dest Vertex tujuan.
 * @return Bobot sisi jika ada dan tidak sama dengan 0. Mengembalikan 0 jika
 *         sisi tidak ada atau jika bobotnya 0.
 */
int isAdjacent(Graph *g, int src, int dest)
{
    if (g != NULL)
    {
        if (isValidVertex(*g, src) && isValidVertex(*g, dest))
        {
            int edgeWeight = g->adjMatrix[src][dest];
            // Mengembalikan bobot jika sisi ada, jika tidak 0.
            return (edgeWeight != NO_EDGE) ? edgeWeight : 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

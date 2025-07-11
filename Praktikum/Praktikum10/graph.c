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

// Nilai untuk menandakan tidak ada sisi (edge) antar vertex.
// Umumnya, nilai 0 bisa berarti tidak ada sisi atau sisi dengan bobot 0.
// Menggunakan nilai khusus seperti -1 (NO_EDGE) membantu membedakan kasus ini.
#define NO_EDGE -1

/**
 * @brief Menginisialisasi sebuah graph dengan jumlah vertex tertentu.
 * @details Matriks adjasensi diinisialisasi dengan nilai NO_EDGE (-1)
 *          untuk menandakan tidak ada sisi (edge) antar vertex.
 *          Jumlah vertex dibatasi antara 0 dan MAX_VERTICES.
 * @param graph Pointer ke Graph yang akan diinisialisasi.
 * @param numberOfVertices Jumlah vertex yang akan dimiliki graph.
 *                         Jika kurang dari 0, akan diatur menjadi 0.
 *                         Jika lebih dari MAX_VERTICES, akan diatur menjadi MAX_VERTICES.
 */
void initGraph(Graph *graph, int numberOfVertices)
{
    // Pastikan pointer graph tidak NULL sebelum melanjutkan.
    if (graph != NULL)
    {
        // Batasi jumlah vertex antara 0 dan MAX_VERTICES.
        int actualVertices = numberOfVertices;
        if (actualVertices < 0)
        {
            actualVertices = 0;
        }
        if (actualVertices > MAX_VERTICES)
        {
            actualVertices = MAX_VERTICES;
        }

        graph->nVertices = actualVertices;
        // Inisialisasi seluruh matriks adjasensi dengan NO_EDGE.
        for (int i = 0; i < MAX_VERTICES; i++)
        {
            for (int j = 0; j < MAX_VERTICES; j++)
            {
                graph->adjMatrix[i][j] = NO_EDGE;
            }
        }
    }
}

/**
 * @brief Memeriksa apakah sebuah nomor vertex valid dalam graph.
 * @details Vertex valid jika berada dalam rentang [0, nVertices-1].
 * @param graph Graph yang akan diperiksa.
 * @param vertex Nomor vertex yang akan divalidasi.
 * @return bool True jika vertex valid, false jika tidak.
 *              Mengembalikan false jika graph adalah NULL.
 */
bool isValidVertex(Graph graph, int vertex)
{
    // Vertex valid jika berada dalam rentang 0 hingga nVertices-1.
    return (vertex >= 0 && vertex < graph.nVertices);
}

/**
 * @brief Menambahkan sebuah sisi berarah dari sourceVertex ke destinationVertex dengan bobot tertentu.
 * @details Sisi hanya ditambahkan jika kedua vertex valid dan graph tidak NULL.
 *          Jika sisi sudah ada, bobotnya akan diperbarui.
 * @param graph Pointer ke Graph yang akan dimodifikasi.
 * @param sourceVertex Vertex sumber.
 * @param destinationVertex Vertex tujuan.
 * @param weight Bobot sisi yang akan ditambahkan.
 */
void addEdge(Graph *graph, int sourceVertex, int destinationVertex, int weight)
{
    // Pastikan pointer graph tidak NULL.
    if (graph != NULL)
    {
        // Tambahkan sisi hanya jika kedua vertex (sumber dan tujuan) valid.
        if (isValidVertex(*graph, sourceVertex) && isValidVertex(*graph, destinationVertex))
        {
            graph->adjMatrix[sourceVertex][destinationVertex] = weight;
        }
    }
}

/**
 * @brief Menghapus sebuah sisi berarah dari sourceVertex ke destinationVertex.
 * @details Jika sisi ditemukan, bobotnya akan disimpan ke dalam pointer weight,
 *          dan sisi tersebut akan dihilangkan dari graph (diatur ke NO_EDGE).
 * @param graph Pointer ke Graph yang akan dimodifikasi.
 * @param sourceVertex Vertex sumber.
 * @param destinationVertex Vertex tujuan.
 * @param weight Pointer untuk menyimpan bobot dari sisi yang dihapus.
 *               Jika sisi tidak ada atau vertex tidak valid, *weight akan diatur ke NO_EDGE.
 */
void removeEdge(Graph *graph, int sourceVertex, int destinationVertex, int *weight)
{
    // Pastikan pointer graph dan weight tidak NULL.
    if (graph != NULL && weight != NULL)
    {
        // Periksa apakah kedua vertex valid.
        if (isValidVertex(*graph, sourceVertex) && isValidVertex(*graph, destinationVertex))
        {
            // Simpan bobot sisi yang akan dihapus.
            *weight = graph->adjMatrix[sourceVertex][destinationVertex];
            // Hapus sisi dengan mengaturnya kembali ke NO_EDGE.
            graph->adjMatrix[sourceVertex][destinationVertex] = NO_EDGE;
        }
        else
        {
            // Jika salah satu atau kedua vertex tidak valid, tandai bobot sebagai NO_EDGE.
            *weight = NO_EDGE;
        }
    } else if (weight != NULL) {
        // Jika graph NULL tapi weight tidak, set weight ke NO_EDGE.
        *weight = NO_EDGE;
    }
}

/**
 * @brief Memeriksa apakah ada sisi dari sourceVertex ke destinationVertex dan mengembalikan bobotnya.
 * @param graph Pointer ke Graph.
 * @param sourceVertex Vertex sumber.
 * @param destinationVertex Vertex tujuan.
 * @return int Bobot sisi jika ada dan tidak sama dengan NO_EDGE.
 *             Mengembalikan 0 jika sisi tidak ada (NO_EDGE), atau jika vertex tidak valid,
 *             atau jika graph adalah NULL.
 *             Catatan: Jika sebuah sisi ada dengan bobot 0, fungsi ini akan mengembalikan 0,
 *             yang bisa ambigu dengan tidak adanya sisi. Untuk pembedaan yang lebih jelas,
 *             pertimbangkan untuk mengembalikan NO_EDGE jika sisi tidak ada.
 *             Namun, mengikuti logika kode asli, 0 dikembalikan jika tidak ada edge.
 */
int isAdjacent(Graph *graph, int sourceVertex, int destinationVertex)
{
    // Pastikan pointer graph tidak NULL.
    if (graph != NULL)
    {
        // Periksa apakah kedua vertex valid.
        if (isValidVertex(*graph, sourceVertex) && isValidVertex(*graph, destinationVertex))
        {
            int edgeWeight = graph->adjMatrix[sourceVertex][destinationVertex];
            // Mengembalikan bobot jika sisi ada (bukan NO_EDGE), jika tidak (NO_EDGE), kembalikan 0.
            return (edgeWeight != NO_EDGE) ? edgeWeight : 0;
        }
        else
        {
            // Jika vertex tidak valid, kembalikan 0.
            return 0;
        }
    }
    else
    {
        // Jika graph NULL, kembalikan 0.
        return 0;
    }
}

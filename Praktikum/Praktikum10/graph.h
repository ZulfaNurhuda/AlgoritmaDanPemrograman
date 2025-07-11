/**
 * --------------------------------------------------------------
 * | @file graph.h                                              |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Definisi ADT Graph menggunakan representasi Adjacency      |
 * | Matrix untuk graph berbobot dan berarah.                   |
 * | Sisi direpresentasikan dengan bobotnya; nilai NO_EDGE (-1) |
 * | menandakan tidak ada sisi.                                 |
 * --------------------------------------------------------------
 */

#ifndef GRAPH_H // Mengganti nama header guard agar lebih generik dan sesuai nama file
#define GRAPH_H

#include <stdio.h>
#include "boolean.h" // Menggunakan boolean.h yang sudah distandarisasi

/* ****************************** */
/* ********* KONSTANTA ********** */
/* ****************************** */

// Maksimum jumlah simpul (vertices) dalam graph.
#define MAX_VERTICES 100
// #define NO_EDGE -1 // Sebaiknya didefinisikan di .c atau sebagai bagian dari ADT jika diperlukan di interface

/* ------------------------------- */
/* ------- Struktur Graph -------- */
/* ------------------------------- */

/**
 * @struct Graph
 * @brief Struktur data Graph menggunakan adjacency matrix.
 * @details
 *   - `nVertices`: Jumlah simpul (vertices) aktual dalam graph.
 *   - `adjMatrix`: Matriks ketetanggaan (adjacency matrix) berukuran MAX_VERTICES x MAX_VERTICES.
 *                  Nilai `adjMatrix[i][j]` menyimpan bobot sisi dari simpul `i` ke simpul `j`.
 *                  Jika tidak ada sisi, nilainya adalah NO_EDGE (biasanya -1, didefinisikan di .c).
 */
typedef struct graph // Memberikan nama pada struct untuk kejelasan
{
    int nVertices;                             // Jumlah simpul (vertices) dalam graph
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Matriks ketetanggaan (adjacency matrix)
} Graph;

/* ********************************* */
/* ********** KONSTRUKTOR ********** */
/* ********************************* */

/**
 * @brief Menginisialisasi sebuah graph dengan jumlah vertex tertentu.
 * @details Matriks adjasensi diinisialisasi dengan nilai NO_EDGE (-1)
 *          untuk menandakan tidak ada sisi (edge) antar vertex.
 *          Jumlah vertex dibatasi antara 0 dan MAX_VERTICES.
 * @param graph Pointer ke Graph yang akan diinisialisasi.
 * @param numberOfVertices Jumlah vertex yang akan dimiliki graph.
 *                         Jika kurang dari 0, akan diatur menjadi 0.
 *                         Jika lebih dari MAX_VERTICES, akan diatur menjadi MAX_VERTICES.
 * @note I.S. : graph sembarang, numberOfVertices terdefinisi.
 * @note F.S. : graph terinisialisasi dengan numberOfVertices (aktual) dan semua sisi NO_EDGE.
 */
void initGraph(Graph *graph, int numberOfVertices);

/* ********************************* */
/* ********* OPERASI GRAF ********** */
/* ********************************* */

/* ----------------------------------------------- */
/* ----- Pengecekan validasi simpul (vertex) ----- */
/* ----------------------------------------------- */

/**
 * @brief Memeriksa apakah sebuah nomor vertex valid dalam graph.
 * @details Vertex valid jika berada dalam rentang [0, nVertices-1].
 * @param graph Graph yang akan diperiksa.
 * @param vertex Nomor vertex yang akan divalidasi.
 * @return bool True jika vertex valid, false jika tidak.
 */
bool isValidVertex(Graph graph, int vertex);

/* ----------------------------------------------- */
/* ------------ Tambah dan Hapus Edge ------------ */
/* ----------------------------------------------- */

/**
 * @brief Menambahkan sebuah sisi berarah dari sourceVertex ke destinationVertex dengan bobot tertentu.
 * @details Sisi hanya ditambahkan jika kedua vertex valid dan graph tidak NULL.
 *          Jika sisi sudah ada, bobotnya akan diperbarui.
 * @param graph Pointer ke Graph yang akan dimodifikasi.
 * @param sourceVertex Vertex sumber.
 * @param destinationVertex Vertex tujuan.
 * @param weight Bobot sisi yang akan ditambahkan.
 * @note I.S. : graph, sourceVertex, destinationVertex, weight terdefinisi.
 * @note F.S. : Sisi dari sourceVertex ke destinationVertex ditambahkan/diperbarui dengan bobot weight.
 */
void addEdge(Graph *graph, int sourceVertex, int destinationVertex, int weight);

/**
 * @brief Menghapus sebuah sisi berarah dari sourceVertex ke destinationVertex.
 * @details Jika sisi ditemukan, bobotnya akan disimpan ke dalam pointer weight,
 *          dan sisi tersebut akan dihilangkan dari graph (diatur ke NO_EDGE).
 * @param graph Pointer ke Graph yang akan dimodifikasi.
 * @param sourceVertex Vertex sumber.
 * @param destinationVertex Vertex tujuan.
 * @param weight Pointer untuk menyimpan bobot dari sisi yang dihapus.
 *               Jika sisi tidak ada atau vertex tidak valid, *weight akan diatur ke NO_EDGE.
 * @note I.S. : graph, sourceVertex, destinationVertex, weight terdefinisi.
 * @note F.S. : Sisi dari sourceVertex ke destinationVertex dihapus. Bobot sisi yang dihapus disimpan di *weight.
 */
void removeEdge(Graph *graph, int sourceVertex, int destinationVertex, int *weight);

/* ----------------------------------------------- */
/* -------------- Pengecekan Edge ---------------- */
/* ----------------------------------------------- */

/**
 * @brief Memeriksa apakah ada sisi dari sourceVertex ke destinationVertex dan mengembalikan bobotnya.
 * @param graph Pointer ke Graph.
 * @param sourceVertex Vertex sumber.
 * @param destinationVertex Vertex tujuan.
 * @return int Bobot sisi jika ada dan tidak sama dengan NO_EDGE.
 *             Mengembalikan 0 jika sisi tidak ada (NO_EDGE), atau jika vertex tidak valid,
 *             atau jika graph adalah NULL.
 *             (Catatan: Sesuai implementasi di .c, 0 dikembalikan jika NO_EDGE).
 */
int isAdjacent(Graph *graph, int sourceVertex, int destinationVertex);

#endif // GRAPH_H
#ifndef GRAPH_ADJACENCY_MATRIX_H
#define GRAPH_ADJACENCY_MATRIX_H

#include "Boolean.h"

/* ****************************** */
/* ********* KONSTANTA ********** */
/* ****************************** */

// Maksimum jumlah simpul (vertices) dalam graph
#define MAX_VERTICES 100

/* ------------------------------- */
/* ------- Struktur Graph -------- */
/* ------------------------------- */

/**
 * Struktur data Graph menggunakan adjacency matrix.
 *
 * - Matriks berukuran nVertices x nVertices.
 * - Nilai 1 pada adjMatrix[i][j] berarti ada edge antara simpul i dan j.
 * - Nilai 0 berarti tidak ada edge.
 */
typedef struct graph
{
    int numberOfVertices;                            // Jumlah simpul (vertices) dalam graph
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // Matriks ketetanggaan (adjacency matrix)
} Graph;

/* ********************************* */
/* ********** KONSTRUKTOR ********** */
/* ********************************* */

/**
 * Inisialisasi graph kosong dengan jumlah simpul tertentu.
 * Semua nilai dalam adjacency matrix akan di-set ke 0 (tidak ada edge).
 *
 * @param graph Pointer ke Graph yang akan diinisialisasi
 * @param numberOfVertices Jumlah simpul dalam graph
 */
void initializeGraph(Graph *graph, int numberOfVertices);

/* ********************************* */
/* ********* OPERASI GRAPG ********* */
/* ********************************* */

/* ----------------------------------------------- */
/* ----- Pengecekan validasi simpul (vertex) ----- */
/* ----------------------------------------------- */

/**
 * Mengecek apakah simpul (vertex) valid, yaitu berada dalam rentang 0 hingga numberOfVertices-1.
 *
 * @param graph Graph yang diperiksa
 * @param vertex Simpul yang ingin divalidasi
 * @return true jika valid, false jika tidak
 */
bool isValidVertex(Graph graph, int vertex);

/* ----------------------------------------------- */
/* ------------ Tambah dan Hapus Edge ------------ */
/* ----------------------------------------------- */

/**
 * Menambahkan edge (sisi) antara dua simpul dalam graf tak berarah.
 *
 * @param graph Pointer ke Graph
 * @param sourceVertex Indeks simpul asal
 * @param destinationVertex Indeks simpul tujuan
 */
void addEdge(Graph *graph, int sourceVertex, int destinationVertex);

/**
 * Menghapus edge (sisi) antara dua simpul dalam graf tak berarah.
 *
 * @param graph Pointer ke Graph
 * @param sourceVertex Indeks simpul asal
 * @param destinationVertex Indeks simpul tujuan
 */
void removeEdge(Graph *graph, int sourceVertex, int destinationVertex);

/* ----------------------------------------------- */
/* -------------- Pengecekan Edge ---------------- */
/* ----------------------------------------------- */

/**
 * Mengecek apakah dua simpul saling terhubung (bersebelahan).
 *
 * @param graph Pointer ke Graph
 * @param sourceVertex Indeks simpul asal
 * @param destinationVertex Indeks simpul tujuan
 * @return true jika terdapat edge dari sourceVertex ke destinationVertex, false jika tidak
 */
bool isAdjacent(Graph *graph, int sourceVertex, int destinationVertex);

#endif /* GRAPH_ADJACENCY_MATRIX_H */
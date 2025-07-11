/**
 * --------------------------------------------------------------
 * | @file graph_adjlist.h                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Definisi ADT Graph menggunakan representasi Adjacency List.|
 * | Graph ini tidak berarah dan tidak berbobot.                |
 * --------------------------------------------------------------
 */

#ifndef GRAPH_ADJLIST_H
#define GRAPH_ADJLIST_H

#include <stdbool.h> // Untuk tipe data bool
#include <stdlib.h>  // Untuk NULL (meskipun seringkali sudah ter-include dari stdio.h atau stdbool.h)

/* ***************************************************** */
/* ********************** TIPE DATA ******************** */
/* ***************************************************** */

/**
 * @struct Node
 * @brief Struktur untuk merepresentasikan sebuah node dalam adjacency list.
 * @details Setiap node menyimpan nomor vertex yang bertetangga dan pointer
 *          ke node berikutnya dalam list untuk vertex yang sama.
 */
typedef struct Node
{
    int vertex;        /**< Nomor vertex yang bertetangga. */
    struct Node *next; /**< Pointer ke node tetangga berikutnya dalam list. */
} Node;

/**
 * @struct Graph
 * @brief Struktur untuk merepresentasikan graph menggunakan adjacency list.
 * @details Graph terdiri dari jumlah vertex dan sebuah array pointer ke Node.
 *          Setiap elemen `adjList[i]` adalah pointer ke head dari linked list
 *          yang berisi semua vertex yang bertetangga dengan vertex `i`.
 */
typedef struct Graph // Memberikan nama pada struct untuk kejelasan
{
    int numVertices; /**< Jumlah total simpul (vertex) dalam graph. */
    Node **adjList;  /**< Array pointer ke head dari adjacency list untuk setiap vertex. */
} Graph;

/* ***************************************************** */
/* ******************** KONSTRUKTOR ******************** */
/* ***************************************************** */

/**
 * @brief Membuat sebuah node baru untuk digunakan dalam adjacency list.
 * @details Node ini akan menyimpan nomor vertex tujuan dan pointer ke node berikutnya.
 * @param vertexValue Nilai (nomor) vertex yang akan disimpan di dalam node.
 * @return Node* Pointer ke Node yang baru dibuat, atau NULL jika alokasi memori gagal.
 */
Node *createNode(int vertexValue);

/**
 * @brief Membuat sebuah graph baru dengan jumlah vertex tertentu.
 * @details Graph direpresentasikan sebagai array dari adjacency list.
 *          Setiap elemen array adalah pointer ke head dari linked list.
 * @param numberOfVertices Jumlah total vertex yang akan ada dalam graph.
 *                         Vertex yang valid akan memiliki nomor dari 0 hingga numberOfVertices-1.
 * @return Graph* Pointer ke Graph yang baru dibuat, atau NULL jika alokasi memori gagal.
 */
Graph *createGraph(int numberOfVertices);

/* ***************************************************** */
/* ******************* OPERASI GRAPH ******************* */
/* ***************************************************** */

/**
 * @brief Menambahkan sebuah sisi (edge) tak berarah antara dua simpul dalam graph.
 * @details Karena graph tak berarah, sisi akan ditambahkan ke adjacency list
 *          dari kedua simpul. Sisi baru selalu ditambahkan di akhir list.
 *          Jika vertex yang diberikan di luar rentang yang valid (0 sampai numVertices-1),
 *          atau jika alokasi node gagal, fungsi akan mencetak "Penambahan edge gagal.\n".
 * @param graph Pointer ke Graph yang akan dimodifikasi.
 * @param vertex1 Nomor simpul pertama dari sisi.
 * @param vertex2 Nomor simpul kedua dari sisi.
 */
void addEdge(Graph *graph, int vertex1, int vertex2);

/* ***************************************************** */
/* ******************** DESTRUKTOR ********************* */
/* ***************************************************** */

/**
 * @brief Membebaskan semua memori yang dialokasikan untuk graph.
 * @details Fungsi ini akan mengiterasi melalui setiap adjacency list, membebaskan
 *          semua node di dalamnya, kemudian membebaskan array adjacency list,
 *          dan terakhir membebaskan struktur Graph itu sendiri.
 * @param graph Pointer ke Graph yang akan dibebaskan memorinya.
 *              Jika graph adalah NULL, fungsi tidak melakukan apa-apa.
 */
void freeGraph(Graph *graph);

#endif // GRAPH_ADJLIST_H
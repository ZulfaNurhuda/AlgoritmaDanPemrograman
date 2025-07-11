#ifndef GRAPH_ADJLIST_H
#define GRAPH_ADJLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ***************************************************** */
/* ********************** TIPE DATA ******************** */
/* ***************************************************** */

typedef struct node *AddressNode;

/* ------------------------------- */
/* -------- Struktur Node -------- */
/* ------------------------------- */

typedef struct node
{
    int vertex;       /* < Nilai vertex. */
    AddressNode next; /* < Pointer ke simpul berikutnya dalam adjacency list. */
} Node;

/* ------------------------------- */
/* ------- Struktur Graph -------- */
/* ------------------------------- */

typedef struct graph
{
    int numberOfVertices; /* < Banyak simpul (vertex) dalam graf. */
    AddressNode *adjList; /* < Array pointer ke daftar adjacency. */
} Graph;

/* ***************************************************** */
/* ******************** KONSTRUKTOR ******************** */
/* ***************************************************** */

/* ------------------------------------ */
/* -------- Konstruktor Graph --------- */
/* ------------------------------------ */

/**
 * @brief Membuat graf dengan jumlah simpul tertentu.
 *
 * @param numberOfVertices Jumlah simpul dalam graf. Vertex yang valid adalah 0
 * sampai numVertices-1.
 * @return Pointer ke graf yang baru dibuat atau NULL jika alokasi graph atau
 * simpul gagal.
 */
Graph *createGraph(int numberOfVertices);

/* ------------------------------------ */
/* --------- Konstruktor Node --------- */
/* ------------------------------------ */

/**
 * @brief Membuat simpul baru untuk daftar adjacency.
 *
 * @param vertexValue Nomor vertex untuk simpul baru.
 * @return Pointer ke simpul yang baru dibuat atau NULL jika alokasi gagal;
 */
AddressNode createNode(int vertex);

/* ***************************************************** */
/* ******************* OPERASI GRAPH ******************* */
/* ***************************************************** */

/**
 * @brief Menambahkan sisi (edge) antara dua simpul dalam graf.
 *
 * Vertex yang valid adalah 0 sampai numVertices-1. Jika vertex di luar range
 * tersebut, penambahan edge akan gagal.
 *
 * Vertex baru selalu ditambahkan di akhir adjacency list. Contoh:
 * - Jika addEdge(graph, 0, 1) dipanggil, adjacency list untuk vertex 0 akan
 * berisi [1]
 * - Jika addEdge(graph, 0, 2) dipanggil, adjacency list untuk vertex 0 akan
 * berisi [1, 2]
 * - Jika addEdge(graph, 0, 3) dipanggil, adjacency list untuk vertex 0 akan
 * berisi [1, 2, 3]
 *
 * Jika penambahan gagal: keluarkan output: "Penambahan edge
 * gagal.\n"
 *
 * @param graph Pointer ke graf.
 * @param vertex1 Simpul pertama (harus dalam range 0 sampai numVertices-1).
 * @param vertex2 Simpul kedua (harus dalam range 0 sampai numVertices-1).
 */
void addEdge(Graph *graph, int vertex1, int vertex2);

/* ***************************************************** */
/* ******************** DESTRUKTOR ********************* */
/* ***************************************************** */

/**
 * @brief Membebaskan memori yang dialokasikan untuk graf.
 *
 * @param graph Pointer ke graf yang akan dibebaskan.
 */
void freeGraph(Graph *graph);

#endif
/**
 * --------------------------------------------------------------
 * | @file graph_modules.h                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Header file untuk modul tambahan operasi pada ADT Graph    |
 * | yang direpresentasikan menggunakan Adjacency List.         |
 * | Termasuk fungsi untuk mencetak graph dan menghapus sisi.   |
 * --------------------------------------------------------------
 */

#ifndef GRAPH_MODULES_H
#define GRAPH_MODULES_H

#include "graph_adjlist.h" // Menggunakan definisi Graph dan Node dari graph_adjlist.h
#include <stdio.h>         // Diperlukan jika ada tipe FILE* atau untuk NULL, meskipun di sini tidak secara langsung.
                           // Lebih baik di-include di .c jika hanya untuk implementasi printf.
                           // Namun, karena file asli menyertakannya, kita pertahankan untuk saat ini.
#include "boolean.h"       // Untuk tipe data bool, jika digunakan dalam implementasi.

/* ***************************************************** */
/* *************** PROTOTIPE FUNGSI MODUL ************** */
/* ***************************************************** */

/**
 * @brief Mencetak representasi adjacency list dari sebuah graph.
 * @details Fungsi ini mengiterasi melalui setiap vertex dalam graph dan
 *          mencetak daftar tetangganya. Format output per vertex adalah:
 *          `vertex_idx: tetangga1 -> tetangga2 -> ...`
 *          Jika sebuah vertex tidak memiliki tetangga, akan dicetak `Kosong`.
 *          Jika pointer graph adalah NULL, akan dicetak "Graph is NULL".
 * @param graph Pointer ke Graph yang akan dicetak.
 * @note I.S. : graph mungkin NULL atau graph terdefinisi.
 * @note F.S. : Isi graph dicetak ke layar sesuai format.
 */
void printGraph(Graph *graph);

/**
 * @brief Menghapus sebuah sisi (edge) tak berarah antara vertex1 dan vertex2.
 * @details Karena graph tak berarah, fungsi ini akan mencoba menghapus node vertex2
 *          dari adjacency list vertex1, dan menghapus node vertex1 dari adjacency list vertex2.
 *          Jika salah satu atau kedua vertex tidak valid (di luar rentang 0 sampai numVertices-1),
 *          graph adalah NULL, atau sisi tidak ditemukan, fungsi akan mencetak "Penghapusan edge gagal.\n".
 * @param graph Pointer ke Graph yang akan dimodifikasi.
 * @param vertex1 Nomor vertex pertama dari sisi yang akan dihapus.
 * @param vertex2 Nomor vertex kedua dari sisi yang akan dihapus.
 * @note I.S. : graph, vertex1, vertex2 terdefinisi.
 * @note F.S. : Sisi antara vertex1 dan vertex2 dihapus dari graph jika ada.
 *              Jika penghapusan gagal (misal, sisi tidak ada), pesan error dicetak.
 */
void deleteEdge(Graph *graph, int vertex1, int vertex2);

#endif // GRAPH_MODULES_H
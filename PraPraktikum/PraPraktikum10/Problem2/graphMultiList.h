#ifndef GRAPH_MULTILIST_H
#define GRAPH_MULTILIST_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h" // Asumsi boolean.h tersedia seperti di deskripsi soal

#define NIL NULL

typedef struct Node *AddressNode;                   // Pointer ke simpul utama dalam graph
typedef struct SuccessorNode *AddressSuccessorNode; // Pointer ke simpul successor (edge) dari simpul utama

/* Tipe simpul utama (Node/Leader) */
typedef struct Node
{
    int id;                             // Identitas simpul
    int predecessorCount;               // Banyaknya busur masuk
    AddressSuccessorNode successorList; // List busur keluar (successor)
    AddressNode next;                   // Pointer ke simpul berikutnya
} Node;

/* Tipe simpul successor (Trailer) */
typedef struct SuccessorNode
{
    AddressNode successor;     // Pointer ke simpul tujuan
    AddressSuccessorNode next; // Pointer ke successor berikutnya
} SuccessorNode;

/* Graph: hanya menyimpan pointer ke simpul pertama */
typedef struct
{
    AddressNode first;
} Graph;

/* ********* AKSES (Selektor) ********* */
/**
 * 'g' adalah variabel bertipe 'Graph' yang menyimpan pointer ke simpul pertama.
 * 'p' adalah pointer bertipe 'AddressNode', yaitu menunjuk ke sebuah simpul utama (GraphNode)
 * 'q' adalah pointer bertipe 'AddressSuccessorNode', yaitu menunjuk ke sebuah simpul successor (SuccessorNode)
 */
#define FIRST(g) ((g).first)             // Mengakses field pertama dari graph
#define ID(p) ((p)->id)                  // Mengakses ID dari simpul utama p
#define NPRED(p) ((p)->predecessorCount) // Mengakses jumlah predecessor simpul p
#define TRAIL(p) ((p)->successorList)    // Mengakses pointer ke list successor simpul p
#define NEXTNODE(p) ((p)->next)          // Mengakses simpul berikutnya dari p
#define SUCC(q) ((q)->successor)         // Mengakses simpul tujuan (successor) dari edge q
#define NEXTSUCC(q) ((q)->next)          // Mengakses edge berikutnya dari q

/* ********* KONSTRUKTOR ********* */
/**
 * @brief Membuat graph dengan satu simpul awal
 * @param rootNodeId ID simpul pertama
 * @param graph Graph yang akan dibentuk
 * I.S.  : Sembarang
 * F.S.  : Terbentuk graph dengan satu simpul ber-ID rootNodeId
 * Proses: Alokasi simpul baru dan diset sebagai simpul pertama
 */
void createGraph(int rootNodeId, Graph *graph);

/* ********* MANAJEMEN MEMORI NODE (LEADER) ********* */
/**
 * @brief Mengalokasikan simpul utama (Node) baru
 * @param value ID simpul yang ingin dibuat
 * @return Alamat simpul jika berhasil, NIL jika gagal
 * I.S.  : value terdefinisi
 * F.S.  : Dialokasikan simpul baru dengan nilai id = value
 * Proses: Alokasi memori dan inisialisasi atribut node
 */
AddressNode newGraphNode(int value);

/**
 * @brief Dealokasi simpul utama (Node)
 * @param p Pointer ke simpul yang akan didealokasi
 * I.S. : p menunjuk ke simpul yang valid
 * F.S. : Memori simpul dikembalikan ke sistem
 */
void deallocGraphNode(AddressNode node);

/* ********* MANAJEMEN MEMORI TRAIL (SUCCESSOR) ********* */
/**
 * @brief Mengalokasikan simpul successor baru
 * @param pn Pointer ke simpul tujuan
 * @return Alamat SuccNode jika berhasil, NIL jika gagal
 * I.S. : pn valid
 * F.S. : Dialokasikan SuccNode dengan succ menunjuk ke pn
 */
AdrSuccNode newSuccNode(AdrNode pn);

/**
 * @brief Dealokasi simpul successor (SuccNode)
 * @param p Pointer ke successor yang akan didealokasi
 * I.S. : p valid
 * F.S. : Memori SuccNode dikembalikan ke sistem
 */
void deallocSuccNode(AdrSuccNode p);

/* ********* OPERASI DASAR GRAF ********* */
/**
 * @brief Mencari simpul dalam graph
 * @param g Graph yang dicari
 * @param x ID simpul yang dicari
 * @return Alamat simpul jika ditemukan, NIL jika tidak ada
 * I.S. : g dan x terdefinisi
 * F.S. : Tidak mengubah g
 * Proses: Telusuri list simpul sampai ditemukan id = x
 */
AdrNode searchNode(Graph g, int x);

/**
 * @brief Mencari edge dari prec ke succ
 * @param g Graph yang diperiksa
 * @param prec ID simpul asal
 * @param succ ID simpul tujuan
 * @return Alamat SuccNode jika edge ada, NIL jika tidak ada
 * I.S. : g, prec, succ terdefinisi
 * F.S. : Tidak mengubah g
 */
AdrSuccNode searchEdge(Graph g, int prec, int succ);

/**
 * @brief Menambahkan simpul baru ke graph
 * @param g Graph yang akan diubah
 * @param x ID simpul yang akan ditambahkan
 * @param pn Alamat simpul hasil alokasi (output)
 * I.S. : g dan x terdefinisi, x belum ada dalam g
 * F.S. : Jika alokasi berhasil, x menjadi simpul terakhir
 *        dan pn menunjuk ke simpul tersebut
 *        Jika gagal, g tetap, pn = NIL
 */
void insertNode(Graph *g, int x, AdrNode *pn);

/**
 * @brief Menambahkan edge dari prec ke succ ke dalam graph
 * @param g Graph yang akan diubah
 * @param prec ID simpul asal
 * @param succ ID simpul tujuan
 * I.S. : g, prec, succ terdefinisi
 * F.S. :
 *   - Jika edge belum ada: tambahkan edge <prec, succ>
 *   - Jika node belum ada: node ditambahkan dulu
 *   - Jika edge sudah ada: tidak melakukan apa-apa
 */
void insertEdge(Graph *g, int prec, int succ);

/**
 * @brief Menghapus simpul dari graph beserta seluruh edge terkait
 * @param g Graph yang akan diubah
 * @param x ID simpul yang ingin dihapus
 * I.S. : g terdefinisi, x boleh ada atau tidak di g
 * F.S. : Simpul x dan semua edge ke/dari x dihapus dari g.
 *        Jika simpul yang dihapus adalah satu-satunya simpul di graph,
 *        maka graph menjadi kosong (FIRST(*g) == NIL).
 * Proses:
 * - Menghapus semua edge yang menunjuk ke x.
 * - Menghapus semua edge keluar dari x.
 * - Menghapus simpul x dari list simpul.
 */
void deleteNode(Graph *g, int x);

/**
 * @brief Menampilkan isi graph berupa daftar successor dari setiap simpul.
 *
 * I.S. : Graph g sudah terdefinisi (boleh kosong).
 * F.S. : Jika graph kosong, cetak "Graph kosong".
 *        Semua simpul dicetak ke layar bersama daftar successor-nya dalam format:
 *        <id_simpul> -> <id_succ_1> -> <id_succ_2> ...
 *        Jika simpul tidak memiliki successor, hanya ditampilkan id-nya saja
 *        Selalu akhiri setiap output dengan endline (\n).
 *
 * Proses:
 * - Jika graph kosong, cetak "Graph kosong" dan keluar.
 * - Melakukan traversal dari simpul pertama (g.first) ke simpul berikutnya
 * - Untuk setiap simpul, mencetak id-nya, lalu menelusuri dan mencetak semua trail (succNode) yang keluar darinya
 *
 *
 * Contoh Graph:
 * Misalkan ada graph dengan edge:
 *   1 → 2
 *   1 → 3
 *   4 → 5
 *   2 → 5
 *   3 → 5
 *
 * Maka output dari printGraph(g) adalah:
 * 1 -> 2 -> 3
 * 2 -> 5
 * 3 -> 5
 * 4 -> 5
 * 5
 *
 */
void printGraph(Graph g);

#endif
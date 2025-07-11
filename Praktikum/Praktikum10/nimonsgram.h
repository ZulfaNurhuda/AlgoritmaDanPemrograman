/**
 * --------------------------------------------------------------
 * | @file nimonsgram.h                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Definisi ADT Graph untuk NimonsGram, sebuah jejaring sosial|
 * | sederhana. Graph direpresentasikan sebagai directed graph  |
 * | menggunakan multi-list (adjacency list).                   |
 * | Setiap node merepresentasikan pengguna (Nimons), dan edge  |
 * | merepresentasikan hubungan "follow".                       |
 * --------------------------------------------------------------
 */

#ifndef NIMONSGRAM_H
#define NIMONSGRAM_H

#include <stdio.h>  // Untuk NULL (meskipun stdlib.h juga menyediakan)
#include <stdlib.h> // Untuk malloc, free, dan NULL
#include "boolean.h" // Menggunakan boolean.h yang sudah distandarisasi

/* ****************************** */
/* ********* KONSTANTA ********** */
/* ****************************** */

#define NIL NULL // Definisi NIL sebagai NULL pointer

/* ****************************** */
/* ********* TIPE DATA ********** */
/* ****************************** */

typedef struct Node *AdrNode;         // Pointer ke simpul utama dalam graph (pengguna Nimons)
typedef struct SuccNode *AdrSuccNode; // Pointer ke simpul successor (edge "following")

/**
 * @struct Node
 * @brief Merepresentasikan seorang pengguna (Nimons) dalam graph.
 * @details
 *   - `id`: Identitas unik pengguna.
 *   - `nPred`: Jumlah predecessor (pengguna lain yang mem-follow node ini / jumlah follower).
 *   - `trail`: Pointer ke list successor (daftar pengguna yang di-follow oleh node ini).
 *   - `next`: Pointer ke node pengguna berikutnya dalam list utama graph.
 */
typedef struct Node
{
    int id;            // Identitas simpul (pengguna)
    int nPred;         // Banyaknya busur masuk (jumlah follower)
    AdrSuccNode trail; // List busur keluar (daftar pengguna yang di-follow / following)
    AdrNode next;      // Pointer ke simpul pengguna berikutnya dalam list utama
} Node;

/**
 * @struct SuccNode
 * @brief Merepresentasikan sebuah edge "following" dalam adjacency list.
 * @details
 *   - `succ`: Pointer ke node pengguna yang di-follow.
 *   - `next`: Pointer ke edge "following" berikutnya dalam list untuk pengguna yang sama.
 */
typedef struct SuccNode
{
    AdrNode succ;     // Pointer ke simpul tujuan (pengguna yang di-follow)
    AdrSuccNode next; // Pointer ke successor (following) berikutnya
} SuccNode;

/**
 * @struct Graph
 * @brief Merepresentasikan keseluruhan graph NimonsGram.
 * @details Hanya menyimpan pointer ke node pengguna pertama dalam list utama.
 */
typedef struct Graph // Memberikan nama pada struct untuk kejelasan
{
    AdrNode first; // Pointer ke node pengguna pertama
} Graph;

/* ************************************ */
/* ********* AKSES (Selektor) ********* */
/* ************************************ */
// 'graph' adalah variabel bertipe 'Graph'.
// 'p' adalah variabel bertipe 'AdrNode'.
// 'q' adalah variabel bertipe 'AdrSuccNode'.

#define FIRST(graph) ((graph).first)  // Mengakses field 'first' dari Graph
#define ID(p) ((p)->id)               // Mengakses ID dari Node p
#define NPRED(p) ((p)->nPred)         // Mengakses jumlah predecessor (follower) Node p
#define TRAIL(p) ((p)->trail)         // Mengakses pointer ke list successor (following) Node p
#define NEXTNODE(p) ((p)->next)       // Mengakses Node pengguna berikutnya dari p
#define SUCC(q) ((q)->succ)           // Mengakses Node pengguna tujuan (yang di-follow) dari edge q
#define NEXTSUCC(q) ((q)->next)       // Mengakses edge "following" berikutnya dari q

/* ********************************* */
/* ********** KONSTRUKTOR ********** */
/* ********************************* */

/**
 * @brief Membuat graph dengan satu simpul (pengguna) awal.
 * @param rootNodeId ID untuk simpul pengguna pertama.
 * @param graph Pointer ke Graph yang akan dibentuk.
 * @note I.S. : graph sembarang, rootNodeId terdefinisi.
 * @note F.S. : Terbentuk graph dengan satu simpul pengguna ber-ID rootNodeId.
 *              Jika alokasi gagal, graph akan kosong (FIRST(*graph) == NIL).
 */
void createGraph(int rootNodeId, Graph *graph);

/* ************************************************** */
/* ********* MANAJEMEN MEMORI NODE PENGGUNA ********* */
/* ************************************************** */

/**
 * @brief Mengalokasikan dan menginisialisasi simpul pengguna (Node) baru.
 * @param nodeValue ID untuk simpul pengguna yang ingin dibuat.
 * @return AdrNode Alamat simpul jika berhasil dialokasikan, atau NIL jika gagal.
 * @note I.S. : nodeValue terdefinisi.
 * @note F.S. : Dialokasikan simpul pengguna baru dengan ID = nodeValue, nPred = 0,
 *              trail = NIL, dan next (NEXTNODE) = NIL.
 */
AdrNode newGraphNode(int nodeValue);

/**
 * @brief Dealokasi memori dari simpul pengguna (Node).
 * @param node Pointer ke simpul yang akan didealokasi.
 * @note I.S. : node terdefinisi (bisa NIL).
 * @note F.S. : Memori yang ditunjuk oleh node (jika tidak NIL) dikembalikan ke sistem.
 */
void deallocGraphNode(AdrNode node);

/* ******************************************************* */
/* ********* MANAJEMEN MEMORI EDGE ("FOLLOWING") ********* */
/* ******************************************************* */

/**
 * @brief Mengalokasikan dan menginisialisasi simpul successor (SuccNode) baru untuk edge.
 * @param targetSuccessorNode Pointer ke simpul pengguna yang dituju oleh edge ini (yang di-follow).
 * @return AdrSuccNode Alamat SuccNode jika berhasil dialokasikan, atau NIL jika gagal.
 * @note I.S. : targetSuccessorNode terdefinisi.
 * @note F.S. : Dialokasikan SuccNode dengan field `succ` menunjuk ke targetSuccessorNode
 *              dan field `next` (NEXTSUCC) = NIL.
 */
AdrSuccNode newSuccNode(AdrNode targetSuccessorNode);

/**
 * @brief Dealokasi memori dari simpul successor (SuccNode) atau edge.
 * @param node Pointer ke simpul successor yang akan didealokasi.
 * @note I.S. : node terdefinisi (bisa NIL).
 * @note F.S. : Memori yang ditunjuk oleh node (jika tidak NIL) dikembalikan ke sistem.
 */
void deallocSuccNode(AdrSuccNode node);

/* *************************************** */
/* ********* OPERASI DASAR GRAF ********* */
/* *************************************** */

/**
 * @brief Mencari simpul pengguna dalam graph berdasarkan ID.
 * @param graph Graph yang akan dicari.
 * @param targetNodeId ID simpul pengguna yang dicari.
 * @return AdrNode Alamat simpul jika ditemukan, atau NIL jika tidak ada.
 * @note I.S. : graph dan targetNodeId terdefinisi.
 * @note F.S. : Tidak mengubah graph.
 */
AdrNode searchNode(Graph graph, int targetNodeId);

/**
 * @brief Mencari edge "following" dari pengguna `predecessorId` ke `successorId`.
 * @param graph Graph yang akan diperiksa.
 * @param predecessorId ID simpul pengguna asal (yang mem-follow).
 * @param successorId ID simpul pengguna tujuan (yang di-follow).
 * @return AdrSuccNode Alamat SuccNode jika edge ada, atau NIL jika tidak ada.
 * @note I.S. : graph, predecessorId, successorId terdefinisi.
 * @note F.S. : Tidak mengubah graph.
 */
AdrSuccNode searchEdge(Graph graph, int predecessorId, int successorId);

/**
 * @brief Menambahkan simpul pengguna baru ke graph jika belum ada.
 * @param graph Pointer ke Graph yang akan diubah.
 * @param newNodeId ID simpul pengguna yang akan ditambahkan atau dicari.
 * @param createdOrFoundNode Pointer output yang akan menunjuk ke simpul yang baru dibuat
 *                           atau simpul yang sudah ada dengan ID yang sama.
 *                           Akan NIL jika alokasi gagal.
 * @note I.S. : graph dan newNodeId terdefinisi. createdOrFoundNode adalah pointer valid.
 * @note F.S. : Jika simpul dengan newNodeId belum ada, simpul baru dibuat, ditambahkan
 *              ke akhir list node utama, dan createdOrFoundNode menunjuk padanya.
 *              Jika sudah ada, createdOrFoundNode menunjuk ke simpul yang ada.
 *              Jika alokasi gagal, createdOrFoundNode adalah NIL.
 */
void insertNode(Graph *graph, int newNodeId, AdrNode *createdOrFoundNode);

/**
 * @brief Menambahkan edge "following" dari pengguna `predecessorId` ke `successorId`.
 * @param graph Pointer ke Graph yang akan diubah.
 * @param predecessorId ID simpul pengguna asal (yang mem-follow).
 * @param successorId ID simpul pengguna tujuan (yang di-follow).
 * @note I.S. : graph, predecessorId, successorId terdefinisi.
 * @note F.S. : Edge <predecessorId, successorId> ditambahkan.
 *              Jika simpul pengguna belum ada, akan dibuat terlebih dahulu.
 *              nPred (jumlah follower) dari successorId bertambah.
 *              Tidak ada perubahan jika edge sudah ada atau alokasi gagal.
 */
void insertEdge(Graph *graph, int predecessorId, int successorId);

/**
 * @brief Menghapus simpul pengguna dari graph beserta seluruh edge terkait (following dan follower).
 * @param graph Pointer ke Graph yang akan diubah.
 * @param targetNodeId ID simpul pengguna yang ingin dihapus.
 * @note I.S. : graph terdefinisi, targetNodeId terdefinisi.
 * @note F.S. : Simpul pengguna dengan ID targetNodeId dan semua edge yang terhubung
 *              dengannya (baik sebagai follower maupun following) dihapus dari graph.
 *              Memori yang terkait dibebaskan. Jika simpul tidak ada, graph tidak berubah.
 */
void deleteNode(Graph *graph, int targetNodeId);

/* ******************************************************* */
/* ********** OPERASI LAIN DAN FUNGSI TAMPILAN ********** */
/* ******************************************************* */

/**
 * @brief Menampilkan isi graph NimonsGram.
 * @details Setiap pengguna dicetak diikuti daftar pengguna yang di-follow olehnya.
 *          Format: `<id_pengguna> -> <id_following1> -> <id_following2> ...`
 *          Jika pengguna tidak mem-follow siapa pun, hanya ID-nya yang dicetak.
 *          Jika graph kosong, mencetak "Graph kosong".
 * @param graph Graph NimonsGram yang akan ditampilkan.
 * @note I.S. : Graph graph sudah terdefinisi (boleh kosong).
 * @note F.S. : Isi graph dicetak ke layar, diakhiri newline per pengguna.
 */
void printGraph(Graph graph);

/**
 * @brief Menemukan "Nimons Paling Digemari" (NPD), yaitu pengguna dengan jumlah follower (nPred) terbanyak.
 * @param graph Graph Nimonsgram yang akan diperiksa.
 * @param maxFollowers Output: pointer ke integer untuk menyimpan jumlah follower (nPred) dari NPD.
 * @return AdrNode Pointer ke Node pengguna yang merupakan Si NPD.
 *                 Jika graph kosong, mengembalikan NIL dan *maxFollowers diisi 0.
 *                 Jika ada beberapa NPD, mengembalikan yang pertama ditemukan.
 * @note I.S. : graph terdefinisi, maxFollowers adalah pointer valid.
 * @note F.S. : Mengembalikan node dengan nPred terbanyak. maxFollowers diisi dengan nilai nPred tersebut.
 */
AdrNode findNPD(Graph graph, int *maxFollowers);

/**
 * @brief Menemukan "Nimons Misterius", yaitu pengguna dengan jumlah following (koneksi keluar) paling sedikit.
 * @param graph Graph Nimonsgram yang akan diperiksa.
 * @param minFollowingCount Output: pointer ke integer untuk menyimpan jumlah following dari Nimons Misterius.
 * @return AdrNode Pointer ke Node pengguna yang merupakan Si Misterius.
 *                 Jika graph kosong, mengembalikan NIL dan *minFollowingCount diisi 0.
 *                 Jika ada beberapa Nimons Misterius, mengembalikan yang pertama ditemukan.
 * @note I.S. : graph terdefinisi, minFollowingCount adalah pointer valid.
 * @note F.S. : Mengembalikan node dengan jumlah koneksi keluar (TRAIL) paling sedikit.
 *              minFollowingCount diisi dengan jumlah koneksi keluar tersebut.
 */
AdrNode findMisterius(Graph graph, int *minFollowingCount);

#endif // NIMONSGRAM_H
/**
 * --------------------------------------------------------------
 * | @file nimonsgram.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Graph untuk NimonsGram, sebuah jejaring   |
 * | sosial sederhana. Direpresentasikan sebagai directed graph |
 * | menggunakan multi-list (adjacency list).                   |
 * --------------------------------------------------------------
 */

#include "nimonsgram.h"
#include <stdlib.h> // Untuk malloc dan free
#include <stdio.h>  // Untuk printf pada printGraph

/**
 * @brief Menginisialisasi sebuah graph dengan satu node awal.
 * @details Graph akan memiliki satu node dengan ID `rootNodeId`.
 *          Jika alokasi node gagal, graph akan tetap kosong.
 * @param rootNodeId ID dari node pertama yang akan dibuat.
 * @param graph Pointer ke Graph yang akan diinisialisasi.
 * @note I.S. : graph sembarang, rootNodeId terdefinisi.
 * @note F.S. : Terbentuk graph dengan satu simpul ber-ID rootNodeId jika alokasi berhasil,
 *              atau graph kosong (FIRST(*graph) == NIL) jika alokasi gagal.
 */
void createGraph(int rootNodeId, Graph *graph)
{
    FIRST(*graph) = NIL; // Inisialisasi graph kosong
    AdrNode newNode = newGraphNode(rootNodeId);
    if (newNode != NIL)
    {
        FIRST(*graph) = newNode; // Set node baru sebagai node pertama
    }
}

/**
 * @brief Mengalokasikan dan menginisialisasi sebuah node graph baru.
 * @details Node yang dibuat akan memiliki ID `nodeValue`, jumlah predecessor (NPRED) 0,
 *          dan pointer TRAIL (successor list) serta NEXTNODE (next main node) diatur ke NIL.
 * @param nodeValue ID untuk node baru.
 * @return AdrNode Alamat dari node yang baru dibuat, atau NIL jika alokasi memori gagal.
 * @note I.S. : nodeValue terdefinisi.
 * @note F.S. : Dialokasikan node baru dengan ID = nodeValue, NPRED = 0, TRAIL = NIL, NEXTNODE = NIL.
 */
AdrNode newGraphNode(int nodeValue)
{
    AdrNode newNode = (AdrNode)malloc(sizeof(Node));
    if (newNode == NIL)
    {
        return NIL; // Gagal alokasi
    }
    // Inisialisasi semua atribut node.
    ID(newNode) = nodeValue;
    NPRED(newNode) = 0;      // Jumlah predecessor (follower) awal adalah 0.
    TRAIL(newNode) = NIL;    // Belum menunjuk ke successor (following) manapun.
    NEXTNODE(newNode) = NIL; // Belum terhubung ke node lain dalam list utama.
    return newNode;
}

/**
 * @brief Dealokasi memori dari sebuah node graph.
 * @param node Pointer ke node yang akan di-dealokasi.
 *             Setelah dealokasi, pointer sebaiknya tidak digunakan lagi.
 * @note I.S. : node mungkin NIL atau menunjuk ke area memori yang valid.
 * @note F.S. : Jika node tidak NIL, memori yang ditunjuk oleh node dibebaskan.
 */
void deallocGraphNode(AdrNode node)
{
    if (node != NIL)
    {
        free(node);
        // Tidak mengatur node = NIL di sini karena node adalah pass-by-value (pointer copy)
    }
}

/**
 * @brief Mengalokasikan dan menginisialisasi sebuah node successor baru (edge).
 * @details Node ini digunakan dalam adjacency list (TRAIL) untuk menunjuk ke node lain (successor).
 * @param targetSuccessorNode Pointer ke node graph yang akan menjadi successor.
 * @return AdrSuccNode Alamat dari node successor yang baru dibuat, atau NIL jika alokasi gagal.
 * @note I.S. : targetSuccessorNode terdefinisi (bisa NIL jika memang ingin membuat edge ke NIL,
 *              walaupun umumnya menunjuk ke node valid).
 * @note F.S. : Dialokasikan SuccNode baru dengan SUCC menunjuk ke targetSuccessorNode dan NEXTSUCC = NIL.
 */
AdrSuccNode newSuccNode(AdrNode targetSuccessorNode)
{
    AdrSuccNode newNode = (AdrSuccNode)malloc(sizeof(SuccNode));
    if (newNode == NIL)
    {
        return NIL; // Gagal alokasi
    }
    SUCC(newNode) = targetSuccessorNode;
    NEXTSUCC(newNode) = NIL;
    return newNode;
}

/**
 * @brief Dealokasi memori dari sebuah node successor (edge).
 * @param node Pointer ke node successor yang akan di-dealokasi.
 * @note I.S. : node mungkin NIL atau menunjuk ke area memori yang valid.
 * @note F.S. : Jika node tidak NIL, memori yang ditunjuk oleh node dibebaskan.
 */
void deallocSuccNode(AdrSuccNode node)
{
    if (node != NIL)
    {
        free(node);
    }
}

/**
 * @brief Mencari sebuah node dalam graph berdasarkan ID-nya.
 * @param graph Graph yang akan dicari.
 * @param targetNodeId ID dari node yang dicari.
 * @return AdrNode Alamat dari node jika ditemukan, atau NIL jika tidak.
 * @note I.S. : graph dan targetNodeId terdefinisi.
 * @note F.S. : Mengembalikan alamat node dengan ID targetNodeId jika ada, atau NIL.
 */
AdrNode searchNode(Graph graph, int targetNodeId)
{
    AdrNode currentNode = FIRST(graph);
    // Telusuri list utama node dari awal.
    while (currentNode != NIL)
    {
        if (ID(currentNode) == targetNodeId)
        {
            return currentNode; // Node ditemukan
        }
        currentNode = NEXTNODE(currentNode); // Pindah ke node berikutnya
    }
    return NIL; // Node tidak ditemukan
}

/**
 * @brief Mencari sebuah edge (sisi berarah) dari node predecessor ke successor.
 * @param graph Graph yang akan dicari.
 * @param predecessorId ID dari node asal (predecessor).
 * @param successorId ID dari node tujuan (successor).
 * @return AdrSuccNode Alamat dari node dalam list successor (TRAIL) predecessorNode
 *                     yang menunjuk ke successorNode, atau NIL jika edge tidak ditemukan.
 * @note I.S. : graph, predecessorId, successorId terdefinisi.
 * @note F.S. : Mengembalikan alamat SuccNode jika edge ada, NIL jika tidak.
 */
AdrSuccNode searchEdge(Graph graph, int predecessorId, int successorId)
{
    AdrNode predecessorNode = searchNode(graph, predecessorId);
    if (predecessorNode == NIL)
    {
        return NIL; // Node predecessor tidak ditemukan
    }

    // Telusuri list successor (TRAIL) dari node predecessor.
    AdrSuccNode currentEdge = TRAIL(predecessorNode);
    while (currentEdge != NIL)
    {
        // Periksa apakah successor dari edge saat ini adalah node yang dicari.
        if (SUCC(currentEdge) != NIL && ID(SUCC(currentEdge)) == successorId)
        {
            return currentEdge; // Edge ditemukan
        }
        currentEdge = NEXTSUCC(currentEdge); // Pindah ke edge berikutnya
    }
    return NIL; // Edge tidak ditemukan
}

/**
 * @brief Memasukkan sebuah node baru ke dalam graph.
 * @details Jika node dengan ID yang sama sudah ada, tidak ada node baru yang dibuat,
 *          dan `createdOrFoundNode` akan menunjuk ke node yang sudah ada.
 *          Jika node belum ada, node baru akan dibuat dan ditambahkan ke akhir list utama graph.
 * @param graph Pointer ke Graph.
 * @param newNodeId ID dari node yang akan dimasukkan atau dicari.
 * @param createdOrFoundNode Pointer output untuk menyimpan alamat node yang baru dibuat atau yang sudah ada.
 *                           Akan bernilai NIL jika alokasi gagal.
 * @note I.S. : graph dan newNodeId terdefinisi. createdOrFoundNode adalah pointer valid.
 * @note F.S. : Jika node dengan newNodeId sudah ada, createdOrFoundNode menunjuk ke node tersebut.
 *              Jika belum ada, node baru dialokasikan, ditambahkan ke akhir list node utama,
 *              dan createdOrFoundNode menunjuk ke node baru tersebut.
 *              Jika alokasi gagal, createdOrFoundNode akan NIL.
 */
void insertNode(Graph *graph, int newNodeId, AdrNode *createdOrFoundNode)
{
    // Cek apakah node sudah ada dalam graph.
    *createdOrFoundNode = searchNode(*graph, newNodeId);
    if (*createdOrFoundNode != NIL)
    {
        return; // Node sudah ada, tidak perlu insert, pointer sudah menunjuk ke node yang ada.
    }

    // Buat node baru jika belum ada.
    *createdOrFoundNode = newGraphNode(newNodeId);
    if (*createdOrFoundNode == NIL)
    {
        return; // Gagal alokasi memori untuk node baru.
    }

    // Tambahkan node baru ke akhir list utama graph.
    if (FIRST(*graph) == NIL) // Jika graph kosong
    {
        FIRST(*graph) = *createdOrFoundNode;
    }
    else // Jika graph tidak kosong, cari node terakhir
    {
        AdrNode currentNode = FIRST(*graph);
        while (NEXTNODE(currentNode) != NIL)
        {
            currentNode = NEXTNODE(currentNode);
        }
        NEXTNODE(currentNode) = *createdOrFoundNode; // Sambungkan node baru di akhir.
    }
}

/**
 * @brief Memasukkan sebuah edge (sisi berarah) dari predecessor ke successor.
 * @details Jika node predecessor atau successor belum ada dalam graph,
 *          mereka akan dibuat (menggunakan `insertNode`) terlebih dahulu.
 *          Jika edge sudah ada, tidak ada operasi yang dilakukan.
 * @param graph Pointer ke Graph.
 * @param predecessorId ID node asal (yang "mem-follow").
 * @param successorId ID node tujuan (yang "di-follow").
 * @note I.S. : graph, predecessorId, successorId terdefinisi.
 * @note F.S. : Edge <predecessorId, successorId> ditambahkan ke graph.
 *              NPRED dari successorId bertambah satu.
 *              Jika node belum ada, akan dibuat. Jika alokasi gagal, edge tidak ditambahkan.
 */
void insertEdge(Graph *graph, int predecessorId, int successorId)
{
    // Jika edge sudah ada, tidak melakukan apa-apa.
    if (searchEdge(*graph, predecessorId, successorId) != NIL)
    {
        return;
    }

    // Cari atau buat node untuk predecessor.
    AdrNode predecessorNode; // Tidak perlu inisialisasi NIL karena akan diisi oleh insertNode
    insertNode(graph, predecessorId, &predecessorNode);
    if (predecessorNode == NIL) return; // Gagal membuat/menemukan predecessorNode

    // Cari atau buat node untuk successor.
    AdrNode successorNode;
    insertNode(graph, successorId, &successorNode);
    if (successorNode == NIL) return; // Gagal membuat/menemukan successorNode

    // Buat node edge baru yang menunjuk ke successor.
    AdrSuccNode newEdge = newSuccNode(successorNode);
    if (newEdge == NIL)
    {
        return; // Gagal alokasi memori untuk edge baru.
    }

    // Tambahkan edge baru ke akhir list successor (TRAIL) dari predecessor.
    if (TRAIL(predecessorNode) == NIL) // Jika predecessor belum memiliki successor
    {
        TRAIL(predecessorNode) = newEdge;
    }
    else // Jika sudah ada, cari akhir list successor
    {
        AdrSuccNode currentEdge = TRAIL(predecessorNode);
        while (NEXTSUCC(currentEdge) != NIL)
        {
            currentEdge = NEXTSUCC(currentEdge);
        }
        NEXTSUCC(currentEdge) = newEdge; // Sambungkan edge baru di akhir.
    }

    // Tambah jumlah predecessor (follower) dari node successor.
    NPRED(successorNode)++;
}

/**
 * @brief Menghapus sebuah node dan semua edge yang terhubung dengannya dari graph.
 * @details Proses ini melibatkan:
 *          1. Menghapus semua edge keluar dari `nodeToDelete` (mengurangi NPRED successor).
 *          2. Menghapus semua edge masuk ke `nodeToDelete` dari node lain.
 *          3. Menghapus `nodeToDelete` dari list utama node graph.
 * @param graph Pointer ke Graph.
 * @param targetNodeId ID dari node yang akan dihapus.
 * @note I.S. : graph dan targetNodeId terdefinisi. Node dengan targetNodeId mungkin ada atau tidak.
 * @note F.S. : Jika node dengan targetNodeId ada, node tersebut dan semua edge terkait
 *              dihapus dari graph. Memori yang digunakan dibebaskan.
 *              Jika node tidak ada, graph tidak berubah.
 */
void deleteNode(Graph *graph, int targetNodeId)
{
    AdrNode nodeToDelete = searchNode(*graph, targetNodeId);
    if (nodeToDelete == NIL)
    {
        return; // Node tidak ada dalam graph.
    }

    // Langkah 1: Hapus semua edge yang keluar dari nodeToDelete (daftar "following").
    //            Dan kurangi jumlah NPRED (follower) dari setiap successor-nya.
    AdrSuccNode currentFollowing = TRAIL(nodeToDelete);
    while (currentFollowing != NIL)
    {
        AdrSuccNode tempFollowing = currentFollowing;
        currentFollowing = NEXTSUCC(currentFollowing); // Simpan pointer sebelum dealokasi

        if (SUCC(tempFollowing) != NIL)
        {
            NPRED(SUCC(tempFollowing))--; // Kurangi jumlah follower dari node yang di-follow
        }
        deallocSuccNode(tempFollowing); // Dealokasi edge keluar
    }
    TRAIL(nodeToDelete) = NIL; // Reset daftar following dari nodeToDelete

    // Langkah 2: Hapus semua edge yang masuk ke nodeToDelete dari node lain (menghapus nodeToDelete dari daftar "following" node lain).
    AdrNode currentNode = FIRST(*graph);
    while (currentNode != NIL)
    {
        // Hanya proses jika currentNode bukan node yang akan dihapus
        if (ID(currentNode) != ID(nodeToDelete)) // Gunakan ID untuk perbandingan
        {
            AdrSuccNode currentTrail = TRAIL(currentNode);
            AdrSuccNode prevTrail = NIL;

            while (currentTrail != NIL)
            {
                // Jika edge saat ini menunjuk ke nodeToDelete
                if (SUCC(currentTrail) == nodeToDelete)
                {
                    AdrSuccNode edgeToDeleteFromTrail = currentTrail;
                    if (prevTrail == NIL) // Jika edge yang dihapus adalah head dari TRAIL
                    {
                        TRAIL(currentNode) = NEXTSUCC(currentTrail);
                    }
                    else // Jika edge yang dihapus ada di tengah atau akhir TRAIL
                    {
                        NEXTSUCC(prevTrail) = NEXTSUCC(currentTrail);
                    }
                    currentTrail = NEXTSUCC(currentTrail); // Pindah ke edge berikutnya di TRAIL
                    deallocSuccNode(edgeToDeleteFromTrail); // Dealokasi edge masuk
                }
                else
                {
                    prevTrail = currentTrail;
                    currentTrail = NEXTSUCC(currentTrail);
                }
            }
        }
        currentNode = NEXTNODE(currentNode); // Pindah ke node utama berikutnya
    }

    // Langkah 3: Hapus nodeToDelete itu sendiri dari list utama graph.
    if (FIRST(*graph) == nodeToDelete) // Jika nodeToDelete adalah node pertama
    {
        FIRST(*graph) = NEXTNODE(nodeToDelete);
    }
    else // Jika nodeToDelete bukan node pertama
    {
        AdrNode prevNode = FIRST(*graph);
        // Cari node sebelum nodeToDelete
        while (prevNode != NIL && NEXTNODE(prevNode) != nodeToDelete)
        {
            prevNode = NEXTNODE(prevNode);
        }
        if (prevNode != NIL) // Jika prevNode ditemukan (seharusnya selalu, kecuali graph rusak)
        {
            NEXTNODE(prevNode) = NEXTNODE(nodeToDelete); // Bypass nodeToDelete
        }
    }

    deallocGraphNode(nodeToDelete); // Dealokasi memori nodeToDelete
}

/**
 * @brief Mencetak representasi graph ke standar output.
 * @details Setiap node dicetak diikuti dengan daftar successor (node yang di-follow).
 *          Format: `nodeId -> succ1Id -> succ2Id ...`
 *          Jika graph kosong, pesan "Graph kosong" dicetak.
 * @param graph Graph yang akan dicetak.
 * @note I.S. : graph terdefinisi (bisa kosong).
 * @note F.S. : Isi graph dicetak ke layar. Setiap baris diakhiri newline.
 */
void printGraph(Graph graph)
{
    if (FIRST(graph) == NIL)
    {
        printf("Graph kosong\n");
        return;
    }

    AdrNode currentNode = FIRST(graph);
    while (currentNode != NIL)
    {
        printf("%d", ID(currentNode)); // Cetak ID node saat ini
        AdrSuccNode tempEdge = TRAIL(currentNode); // Ambil daftar successor
        while (tempEdge != NIL)
        {
            // Cetak ID dari setiap successor
            if (SUCC(tempEdge) != NIL) // Pastikan successor tidak NIL sebelum akses ID
            {
                printf(" -> %d", ID(SUCC(tempEdge)));
            }
            tempEdge = NEXTSUCC(tempEdge); // Pindah ke successor berikutnya
        }
        printf("\n"); // Baris baru untuk setiap node
        currentNode = NEXTNODE(currentNode); // Pindah ke node utama berikutnya
    }
}

/**
 * @brief Menemukan "Nimons Paling Digemari" (NPD), yaitu node dengan jumlah follower (NPRED) terbanyak.
 * @details Jika ada beberapa node dengan jumlah follower maksimal yang sama,
 *          fungsi ini akan mengembalikan salah satunya (biasanya yang pertama ditemui).
 * @param graph Graph yang akan dicari.
 * @param maxFollowers Pointer output untuk menyimpan jumlah follower dari NPD.
 *                     Akan diisi 0 jika graph kosong.
 * @return AdrNode Alamat dari node NPD, atau NIL jika graph kosong.
 * @note I.S. : graph terdefinisi. maxFollowers adalah pointer valid.
 * @note F.S. : Mengembalikan node dengan NPRED terbanyak. maxFollowers diisi dengan nilai NPRED tersebut.
 */
AdrNode findNPD(Graph graph, int *maxFollowers)
{
    AdrNode npdNode = NIL;
    AdrNode currentNode = FIRST(graph);
    *maxFollowers = 0; // Inisialisasi default

    if (isEmpty(graph)) { // Menggunakan isEmpty dari nimonsgram.h jika ada, atau FIRST(graph) == NIL
        return NIL;
    }

    // Iterasi melalui semua node untuk mencari yang punya NPRED (follower) terbanyak.
    while (currentNode != NIL)
    {
        if (npdNode == NIL || NPRED(currentNode) > *maxFollowers)
        {
            npdNode = currentNode;
            *maxFollowers = NPRED(currentNode);
        }
        // Jika NPRED sama, prioritas tidak ditentukan (ambil yang pertama ditemukan atau sesuai urutan list)
        currentNode = NEXTNODE(currentNode);
    }
    return npdNode;
}

/**
 * @brief Menemukan "Nimons Misterius", yaitu node dengan jumlah following (successor) paling sedikit.
 * @details Jika ada beberapa node dengan jumlah following minimal yang sama,
 *          fungsi ini akan mengembalikan salah satunya (biasanya yang pertama ditemui).
 * @param graph Graph yang akan dicari.
 * @param minFollowingCount Pointer output untuk menyimpan jumlah following dari Nimons Misterius.
 *                          Akan diisi 0 jika graph kosong.
 * @return AdrNode Alamat dari node Nimons Misterius, atau NIL jika graph kosong.
 * @note I.S. : graph terdefinisi. minFollowingCount adalah pointer valid.
 * @note F.S. : Mengembalikan node dengan jumlah TRAIL (successor) paling sedikit.
 *              minFollowingCount diisi dengan jumlah successor tersebut.
 */
AdrNode findMisterius(Graph graph, int *minFollowingCount)
{
    AdrNode misteriusNode = NIL;
    AdrNode currentNode = FIRST(graph);
    *minFollowingCount = -1; // Inisialisasi agar perbandingan pertama selalu berhasil jika graph tidak kosong

    if (isEmpty(graph)) {
        *minFollowingCount = 0;
        return NIL;
    }

    // Iterasi melalui semua node.
    while (currentNode != NIL)
    {
        // Hitung jumlah following (successor) untuk node saat ini.
        AdrSuccNode currentSucc = TRAIL(currentNode);
        int followingCount = 0;
        while (currentSucc != NIL)
        {
            followingCount++;
            currentSucc = NEXTSUCC(currentSucc);
        }

        // Bandingkan dengan nilai minimum sementara.
        // Jika ini node pertama atau jumlah following lebih kecil dari minimum saat ini.
        if (misteriusNode == NIL || followingCount < *minFollowingCount)
        {
            *minFollowingCount = followingCount;
            misteriusNode = currentNode;
        }
        // Jika jumlah following sama, prioritas tidak ditentukan (ambil yang pertama atau sesuai urutan)
        currentNode = NEXTNODE(currentNode);
    }
    return misteriusNode;
}

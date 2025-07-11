/**
 * --------------------------------------------------------------
 * | @file nimonsgram.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Graph untuk NimonsGram, sebuah jejaring   |
 * | sosial sederhana. Direpresentasikan sebagai directed graph |
 * | menggunakan multi-list.                                    |
 * --------------------------------------------------------------
 */

#include "nimonsgram.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Menginisialisasi sebuah graph dengan satu node awal.
 * @param initialNodeId ID dari node pertama yang dibuat.
 * @param graph Pointer ke Graph yang akan diinisialisasi.
 */
void createGraph(int initialNodeId, Graph *graph)
{
    FIRST(*graph) = NIL;
    AdrNode newNode = newGraphNode(initialNodeId);
    if (newNode != NIL)
    {
        FIRST(*graph) = newNode;
    }
}

/**
 * @brief Mengalokasikan dan menginisialisasi sebuah node graph baru.
 * @param nodeId ID untuk node baru.
 * @return Alamat dari node yang baru dibuat, atau NIL jika alokasi gagal.
 */
AdrNode newGraphNode(int nodeId)
{
    AdrNode newNode = (AdrNode)malloc(sizeof(Node));
    if (newNode == NIL)
    {
        return NIL;
    }
    // Inisialisasi semua atribut node.
    ID(newNode) = nodeId;
    NPRED(newNode) = 0; // Jumlah predecessor (follower) awal adalah 0.
    TRAIL(newNode) = NIL; // Belum menunjuk ke successor (following) manapun.
    NEXTNODE(newNode) = NIL; // Belum terhubung ke node lain dalam list utama.
    return newNode;
}

/**
 * @brief Dealokasi memori dari sebuah node graph.
 * @param nodeToDealloc Pointer ke node yang akan di-dealokasi.
 */
void deallocGraphNode(AdrNode nodeToDealloc)
{
    if (nodeToDealloc != NIL)
    {
        free(nodeToDealloc);
    }
}

/**
 * @brief Mengalokasikan dan menginisialisasi sebuah node successor baru.
 * @details Node ini digunakan dalam adjacency list untuk menunjuk ke node lain.
 * @param successorNode Pointer ke node graph yang akan menjadi successor.
 * @return Alamat dari node successor yang baru dibuat, atau NIL jika alokasi gagal.
 */
AdrSuccNode newSuccNode(AdrNode successorNode)
{
    AdrSuccNode newNode = (AdrSuccNode)malloc(sizeof(SuccNode));
    if (newNode == NIL)
    {
        return NIL;
    }
    SUCC(newNode) = successorNode;
    NEXTSUCC(newNode) = NIL;
    return newNode;
}

/**
 * @brief Dealokasi memori dari sebuah node successor.
 * @param nodeToDealloc Pointer ke node successor yang akan di-dealokasi.
 */
void deallocSuccNode(AdrSuccNode nodeToDealloc)
{
    if (nodeToDealloc != NIL)
    {
        free(nodeToDealloc);
    }
}

/**
 * @brief Mencari sebuah node dalam graph berdasarkan ID-nya.
 * @param graph Graph yang akan dicari.
 * @param nodeId ID dari node yang dicari.
 * @return Alamat dari node jika ditemukan, atau NIL jika tidak.
 */
AdrNode searchNode(Graph graph, int nodeId)
{
    AdrNode currentNode = FIRST(graph);
    // Telusuri list utama node.
    while (currentNode != NIL)
    {
        if (ID(currentNode) == nodeId)
        {
            return currentNode;
        }
        currentNode = NEXTNODE(currentNode);
    }
    return NIL;
}

/**
 * @brief Mencari sebuah edge (sisi) dari node predecessor ke successor.
 * @param graph Graph yang akan dicari.
 * @param predecessorId ID dari node asal (predecessor).
 * @param successorId ID dari node tujuan (successor).
 * @return Alamat dari node successor (edge) jika ditemukan, atau NIL jika tidak.
 */
AdrSuccNode searchEdge(Graph graph, int predecessorId, int successorId)
{
    AdrNode predecessorNode = searchNode(graph, predecessorId);
    if (predecessorNode == NIL)
    {
        return NIL;
    }

    // Telusuri list successor dari node predecessor.
    AdrSuccNode currentEdge = TRAIL(predecessorNode);
    while (currentEdge != NIL)
    {
        if (ID(SUCC(currentEdge)) == successorId)
        {
            return currentEdge;
        }
        currentEdge = NEXTSUCC(currentEdge);
    }
    return NIL;
}

/**
 * @brief Memasukkan sebuah node baru ke dalam graph.
 * @details Jika node dengan ID yang sama sudah ada, tidak ada node baru yang dibuat.
 * @param graph Pointer ke Graph.
 * @param nodeId ID dari node yang akan dimasukkan.
 * @param nodePointer Pointer output untuk menyimpan alamat node yang baru dibuat atau yang sudah ada.
 */
void insertNode(Graph *graph, int nodeId, AdrNode *nodePointer)
{
    // Cek apakah node sudah ada.
    *nodePointer = searchNode(*graph, nodeId);
    if (*nodePointer != NIL)
    {
        return; // Node sudah ada, tidak perlu insert.
    }

    // Buat node baru jika belum ada.
    *nodePointer = newGraphNode(nodeId);
    if (*nodePointer == NIL) return; // Gagal alokasi.

    // Tambahkan node baru ke akhir list utama graph.
    if (FIRST(*graph) == NIL)
    {
        FIRST(*graph) = *nodePointer;
    }
    else
    {
        AdrNode currentNode = FIRST(*graph);
        while (NEXTNODE(currentNode) != NIL)
        {
            currentNode = NEXTNODE(currentNode);
        }
        NEXTNODE(currentNode) = *nodePointer;
    }
}

/**
 * @brief Memasukkan sebuah edge (sisi) dari predecessor ke successor.
 * @details Jika node predecessor atau successor belum ada, mereka akan dibuat terlebih dahulu.
 * @param graph Pointer ke Graph.
 * @param predecessorId ID node asal.
 * @param successorId ID node tujuan.
 */
void insertEdge(Graph *graph, int predecessorId, int successorId)
{
    // Jika edge sudah ada, tidak melakukan apa-apa.
    if (searchEdge(*graph, predecessorId, successorId) != NIL)
        return;

    // Cari atau buat node untuk predecessor.
    AdrNode predecessorNode = searchNode(*graph, predecessorId);
    if (predecessorNode == NIL)
    {
        insertNode(graph, predecessorId, &predecessorNode);
    }

    // Cari atau buat node untuk successor.
    AdrNode successorNode = searchNode(*graph, successorId);
    if (successorNode == NIL)
    {
        insertNode(graph, successorId, &successorNode);
    }

    // Buat node edge baru yang menunjuk ke successor.
    AdrSuccNode newEdge = newSuccNode(successorNode);
    if (newEdge == NIL) return; // Gagal alokasi.

    // Tambahkan edge baru ke akhir list successor dari predecessor.
    if (TRAIL(predecessorNode) == NIL)
    {
        TRAIL(predecessorNode) = newEdge;
    }
    else
    {
        AdrSuccNode currentEdge = TRAIL(predecessorNode);
        while (NEXTSUCC(currentEdge) != NIL)
        {
            currentEdge = NEXTSUCC(currentEdge);
        }
        NEXTSUCC(currentEdge) = newEdge;
    }

    // Tambah jumlah predecessor (follower) dari node successor.
    NPRED(successorNode)++;
}

/**
 * @brief Menghapus sebuah node dan semua edge yang terhubung dengannya.
 * @param graph Pointer ke Graph.
 * @param nodeId ID dari node yang akan dihapus.
 */
void deleteNode(Graph *graph, int nodeId)
{
    AdrNode nodeToDelete = searchNode(*graph, nodeId);
    if (nodeToDelete == NIL) return; // Node tidak ada.

    // Langkah 1: Hapus semua edge yang keluar dari nodeToDelete (following).
    // Dan kurangi jumlah NPRED dari setiap successor-nya.
    AdrSuccNode currentFollowing = TRAIL(nodeToDelete);
    while (currentFollowing != NIL)
    {
        AdrSuccNode tempFollowing = currentFollowing;
        currentFollowing = NEXTSUCC(currentFollowing);

        if (SUCC(tempFollowing) != NIL)
        {
            NPRED(SUCC(tempFollowing))--;
        }
        deallocSuccNode(tempFollowing);
    }
    TRAIL(nodeToDelete) = NIL;

    // Langkah 2: Hapus semua edge yang masuk ke nodeToDelete dari node lain.
    AdrNode currentNode = FIRST(*graph);
    while (currentNode != NIL)
    {
        if (currentNode != nodeToDelete)
        {
            AdrSuccNode currentTrail = TRAIL(currentNode);
            AdrSuccNode prevTrail = NIL;

            while (currentTrail != NIL)
            {
                if (SUCC(currentTrail) == nodeToDelete)
                {
                    AdrSuccNode edgeToDelete = currentTrail;
                    if (prevTrail == NIL)
                    {
                        TRAIL(currentNode) = NEXTSUCC(currentTrail);
                    }
                    else
                    {
                        NEXTSUCC(prevTrail) = NEXTSUCC(currentTrail);
                    }
                    currentTrail = NEXTSUCC(currentTrail);
                    deallocSuccNode(edgeToDelete);
                }
                else
                {
                    prevTrail = currentTrail;
                    currentTrail = NEXTSUCC(currentTrail);
                }
            }
        }
        currentNode = NEXTNODE(currentNode);
    }

    // Langkah 3: Hapus node itu sendiri dari list utama graph.
    if (FIRST(*graph) == nodeToDelete)
    {
        FIRST(*graph) = NEXTNODE(nodeToDelete);
    }
    else
    {
        AdrNode prevNode = FIRST(*graph);
        while (prevNode != NIL && NEXTNODE(prevNode) != nodeToDelete)
        {
            prevNode = NEXTNODE(prevNode);
        }
        if (prevNode != NIL)
        {
            NEXTNODE(prevNode) = NEXTNODE(nodeToDelete);
        }
    }

    deallocGraphNode(nodeToDelete);
}

/**
 * @brief Mencetak representasi graph.
 * @param g Graph yang akan dicetak.
 */
void printGraph(Graph g)
{
    if (FIRST(g) == NIL)
    {
        printf("Graph kosong\n");
        return;
    }

    AdrNode currentNode = FIRST(g);
    while (currentNode != NIL)
    {
        printf("%d", ID(currentNode));
        AdrSuccNode tempEdge = TRAIL(currentNode);
        while (tempEdge != NIL)
        {
            printf(" -> %d", ID(SUCC(tempEdge)));
            tempEdge = NEXTSUCC(tempEdge);
        }
        printf("\n");
        currentNode = NEXTNODE(currentNode);
    }
}

/**
 * @brief Menemukan "Nimons Paling Digemari" (NPD), yaitu node dengan follower terbanyak.
 * @param g Graph yang akan dicari.
 * @param maxFollower Pointer output untuk menyimpan jumlah follower dari NPD.
 * @return Alamat dari node NPD, atau NIL jika graph kosong.
 */
AdrNode findNPD(Graph g, int *maxFollower)
{
    AdrNode npd = NIL;
    AdrNode currentNode = FIRST(g);

    // Iterasi melalui semua node untuk mencari yang punya NPRED (follower) terbanyak.
    while (currentNode != NIL)
    {
        if (npd == NIL)
        {
            npd = currentNode;
        }
        else if (NPRED(currentNode) > NPRED(npd))
        {
            npd = currentNode;
        }
        currentNode = NEXTNODE(currentNode);
    }

    // Simpan jumlah follower dari NPD yang ditemukan.
    *maxFollower = (npd == NIL) ? 0 : NPRED(npd);
    return npd;
}

/**
 * @brief Menemukan "Nimons Misterius", yaitu node dengan following paling sedikit.
 * @param g Graph yang akan dicari.
 * @param minFollowing Pointer output untuk menyimpan jumlah following dari Nimons Misterius.
 * @return Alamat dari node Nimons Misterius, atau NIL jika graph kosong.
 */
AdrNode findMisterius(Graph g, int *minFollowing)
{
    AdrNode misterius = NIL;
    AdrNode currentNode = FIRST(g);
    int tempMinFollowing = 99999; // Inisialisasi dengan nilai besar.

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
        if (tempMinFollowing > followingCount)
        {
            tempMinFollowing = followingCount;
            misterius = currentNode;
        }

        currentNode = NEXTNODE(currentNode);
    }

    *minFollowing = (misterius == NIL) ? 0 : tempMinFollowing;
    return misterius;
}

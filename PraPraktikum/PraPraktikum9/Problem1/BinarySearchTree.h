#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "Boolean.h"

/* ****************************** */
/* ********* KONSTANTA ********** */
/* ****************************** */

#define NIL NULL

/* ****************************** */
/* ********* TIPE DATA ********** */
/* ****************************** */

typedef struct treeNode *Address;
typedef Address BinTree;

/* ------------------------------- */
/* ------ Struktur Element ------- */
/* ------------------------------- */

/* *** Definisi Tipe TreeNode dengan info berupa ElType bertipe Map (Key dan Count) *** */

typedef struct
{
   int key;
   int count;
} ElType;

/* ------------------------------- */
/* ----- Struktur Tree Node ------ */
/* ------------------------------- */

typedef struct treeNode
{
   ElType info;
   Address left;
   Address right;
} TreeNode;

/* ************************************ */
/* ********* AKSES (Selektor) ********* */
/* ************************************ */

#define ROOT(tree) (tree)->info        // Mendapatkan info dari sebuah root tree
#define LEFT(tree) (tree)->left        // Mendapatkan address dari anak kiri
#define RIGHT(tree) (tree)->right      // Mendapatkan address dari anak kanan

/* ********************************************* */
/* ********* KONSTRUKTOR DAN DEALOKASI ********* */
/* ********************************************* */

/* Mengalokasikan sebuah simpul baru dengan info value */
/* I.S. Sembarang
   F.S. Menghasilkan address simpul baru dengan info = value serta anak kiri dan
        kanan = NIL. Return NIL jika alokasi gagal */
Address newTreeNode(ElType value);

/* Mengembalikan address node ke sistem */
/* I.S. node terdefinisi
   F.S. node didealokasi (free) */
void deallocTreeNode(Address node);

/* ************************************ */
/* ********* PREDIKAT PENTING ********* */
/* ************************************ */

/* Mengirimkan true jika tree adalah pohon kosong */
bool isTreeEmpty(BinTree tree);

/* Mengirimkan true jika tree hanya terdiri dari satu simpul
   anak kiri dan kanan bernilai NIL */
bool isOneElement(BinTree tree);

/* Mengirimkan true jika tree hanya memiliki anak kiri */
bool isUnerLeft(BinTree tree);

/* Mengirimkan true jika tree hanya memiliki anak kanan */
bool isUnerRight(BinTree tree);

/* Mengirimkan true jika tree memiliki dua anak */
bool isBiner(BinTree tree);

/* ********************************** */
/* ********* PEMBENTUK TREE ********* */
/* ********************************** */

/* Membentuk pohon seimbang dari nodeCount simpul dengan input element per simpul */
/* I.S. nodeCount >= 0
   F.S. Menghasilkan pohon biner seimbang dengan nodeCount simpul,
        setiap simpul diisi dengan input nilai key dan count = 1
   Proses:
      - Jika nodeCount = 0, return NIL
      - Setiap simpul diisi dengan input element.key dan count = 1
      - Jumlah simpul anak kiri (nL) = nodeCount div 2
      - Jumlah simpul anak kanan (nR) = nodeCount - nL - 1
      - Simpul kiri akan direkursif dengan nodeCount = nL
      - Simpul kanan akan direkursif dengan nodeCount = nR
      - Return nilai root paling atas */
BinTree buildBalancedTree(int nodeCount);

/* ******************************* */
/* ********* OPERASI BST ********* */
/* ******************************* */

/* Menyisipkan newValue ke dalam BST tree */
/* I.S. tree mungkin kosong, newValue terdefinisi
   F.S. Jika newValue.key sudah ada di tree, maka count bertambah
        Jika belum ada, simpul baru ditambahkan di tempat sesuai properti BST
        - Jika pohon kosong, buat node baru
        - Semua simpul pada subpohon kiri < akar tree
        - Semua simpul pada subpohon kanan >= akar tree */
void insertSearchTree(ElType newValue, BinTree *tree);

/* Prosedur pembantu untuk menghapus node maksimum dari subtree kiri */
/* I.S. *node menunjuk ke subtree kiri dari simpul yang ingin digantikan (node tidak
 * kosong) */
/* F.S. Node paling kanan dari subtree kiri (nilai maksimum) dihapus dari pohon,
         dan anak kirinya (jika ada) dinaikkan menggantikannya */
/* Proses:
   - Jika RIGHT(*node) != NIL, lanjut ke kanan (rekursif)
   - Jika RIGHT(*node) = NIL, berarti node saat ini adalah node maksimum
     → *node digantikan dengan anak kirinya (bisa NIL)
     → node tersebut didealokasi */
void deleteNode(Address *node);

/* Menghapus simpul dengan key = valueToDelete.key dari Binary Search Tree */
/* I.S. *tree menunjuk ke root dari subtree yang sedang diperiksa,
        valueToDelete.key pasti ada dalam BST */
/* F.S. Simpul dengan nilai key = valueToDelete.key dihapus dari BST,
        struktur dan sifat BST tetap dipertahankan */
/* Proses:
   - Jika valueToDelete.key < key node saat ini → rekursif ke kiri
   - Jika valueToDelete.key > key node saat ini → rekursif ke kanan
   - Jika valueToDelete.key = key node saat ini:
       - Jika node adalah daun (leaf) → langsung hapus
       - Jika hanya memiliki satu anak → naikkan anak ke atas
       - Jika memiliki dua anak:
           - Cari nilai maksimum di subtree kiri (RIGHT-most dari LEFT(*node))
           - Salin info dari node maksimum ke node saat ini
           - Hapus node maksimum tersebut (dengan deleteNode) */
void deleteBinaryTree(BinTree *tree, ElType valueToDelete);

/* Mencari node dengan queryKey yang sesuai dalam BST */
/* I.S. tree mungkin kosong, queryKey terdefinisi
   F.S. Mengembalikan address node dengan queryKey yang sesuai jika ditemukan,
        mengembalikan NIL jika tidak ditemukan */
Address searchNode(BinTree tree, int queryKey);

/* Mencari node dengan nilai minimum dalam BST */
/* I.S. tree mungkin kosong
   F.S. Mengembalikan address node dengan nilai key minimum dalam BST,
        mengembalikan NIL jika pohon kosong */
Address findMinimum(BinTree tree);

#endif /* BINARY_SEARCH_TREE_H */
#ifndef BINARY_TREE_TRAVERSAL_H
#define BINARY_TREE_TRAVERSAL_H

#include <stdio.h>
#include <stdlib.h>
#include "Boolean.h"

/* Ambil header file binarySearchTree.h dari folder PraPraktikum9/Problem1 */
/* Apabila header dan implementasi file berada di satu folder yang sama
   cukup menggunakan #include "BinarySearchTree.h" */
/* Saat kompilasi dengan gcc, tambahkan juga file implementasi BinarySearchTree.c
   tanpa menambahkan file driver BinarySearchTreeDriver.c */
#include "../Problem1/BinarySearchTree.h"

/* ****************************** */
/* ********* TIPE DATA ********** */
/* ****************************** */

typedef struct nodeList *AddressList;

/* Tipe data lainnya sudah tersedia dari file BinarySearchTree.h */

/* ------------------------------- */
/* ----- Struktur Node List ------ */
/* ------------------------------- */

typedef struct nodeList
{
   ElType info;
   AddressList next;
} NodeList;

/* ************************************ */
/* ********* AKSES (Selektor) ********* */
/* ************************************ */

#define INFO(node) (node)->info // Mengambil info dari node
#define NEXT(node) (node)->next // Mengambil adrress next dari node

/* *************************************************************** */
/* **************** FUNGSI TRAVERSAL TREE (PRINT) **************** */
/* *************************************************************** */

/* Menampilkan elemen preorder: akar, kiri, kanan */
/* I.S. tree terdefinisi
   F.S. Elemen ditampilkan sesuai urutan preorder, dipisah spasi, TANPA ENDLINE */
void printPreOrder(BinTree tree);

/* Menampilkan elemen inorder: kiri, akar, kanan, TANPA ENDLINE */
/* I.S. tree terdefinisi
   F.S. Elemen ditampilkan sesuai urutan inorder, dipisah spasi, TANPA ENDLINE */
void printInOrder(BinTree tree);

/* Menampilkan elemen postorder: kiri, kanan, akar, TANPA ENDLINE */
/* I.S. tree terdefinisi
   F.S. Elemen ditampilkan sesuai urutan postorder, dipisah spasi, TANPA ENDLINE */
void printPostOrder(BinTree tree);

/* ******************************************************************* */
/* **************** FUNGSI PEMBENTUKAN LIST TRAVERSAL **************** */
/* ******************************************************************* */

/* Membuat node list baru dengan info = value dan next = NIL */
/* Mengalokasikan simpul baru untuk NodeList dengan nilai value
   Return NIL jika alokasi gagal */
AddressList newNodeListElement(ElType value);

/* I.S. list1 dan list2 adalah NodeList yang bisa kosong atau tidak
   F.S. list1 diikuti list2, mengembalikan list hasil konkatenasi */
AddressList concat(AddressList list1, AddressList list2);

/* Menghasilkan list preorder traversal dari pohon */
/* I.S. tree terdefinisi
   F.S. Menghasilkan NodeList preorder traversal dari tree (jika semua alokasi berhasil),
        atau NIL jika ada alokasi gagal */
AddressList makeListPreOrder(BinTree tree);

/* Menghasilkan list inorder traversal dari pohon */
/* I.S. tree terdefinisi
   F.S. Menghasilkan NodeList inorder traversal dari tree */
AddressList makeListInOrder(BinTree tree);

/* Menghasilkan list postorder traversal dari pohon */
/* I.S. tree terdefinisi
   F.S. Menghasilkan NodeList postorder traversal dari tree */
AddressList makeListPostOrder(BinTree tree);

/* Menampilkan isi NodeList ke layar */
/* I.S. list mungkin kosong atau tidak
   F.S. Seluruh elemen list ditampilkan dalam format linked list eksplisit
        Misalnya ada 3 elemen: 10, 20, dan 50 maka output:
        [10] -> [20] -> [50] -> FINISH
        Akhiri output dengan endline */
void printNodeList(AddressList list);

#endif /*  BINARY_TREE_TRAVERSAL_H */
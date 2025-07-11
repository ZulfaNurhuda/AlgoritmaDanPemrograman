/* File : listlinier.h */
/* ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef LISTLINIER_H
#define LISTLINIER_H

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

typedef int InfoType;
typedef struct nodeList *Address;

/* ------------------------------- */
/* ----- Struktur List Node ------ */
/* ------------------------------- */

typedef struct nodeList
{
    InfoType info;
    Address next;
} NodeList;

/* ------------------------------- */
/* -------- Struktur List -------- */
/* ------------------------------- */

typedef struct list
{
    Address first;
} List;

/* ****************************** */
/* ********** DEFINISI ********** */
/* ****************************** */

/* List kosong : FIRST(L) = NIL                                         */
/* Setiap elemen dengan address node dapat diacu INFO(node), NEXT(node) */
/* Elemen terakhir list : jika addressnya last, maka NEXT(last)=NIL     */

/* ***************************************** */
/* ********** Akses (SELEKTOR) ************* */
/* ***************************************** */

#define INFO(node) (node)->info
#define NEXT(node) (node)->next
#define FIRST(list) ((list).first)

/* ******************************* */
/* ********** PROTOTYPE ********** */
/* ******************************* */

/* ************************************************** */
/* **************** TEST LIST KOSONG **************** */
/* ************************************************** */

/* Mengirim true jika list kosong */
bool isEmpty(List list);

/* ******************************************************* */
/* **************** PEMBUATAN LIST KOSONG **************** */
/* ******************************************************* */

/* I.S. Sembarang */
/* F.S. Terbentuk list kosong */
void createEmpty(List *list);

/* ************************************************** */
/* **************** Manajemen Memori **************** */
/* ************************************************** */

/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya */
/* menghasilkan node, maka INFO(node)=value, NEXT(node)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
Address allocate(InfoType value);

/* I.S. node terdefinisi */
/* F.S. node dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address node */
void deallocate(Address *node);

/* ************************************************************** */
/* **************** PENCARIAN SEBUAH ELEMEN LIST **************** */
/* ************************************************************** */

/* Mencari apakah ada elemen list dengan INFO(node)=query */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan NIL */
Address search(List list, InfoType query);

/* ************************************************************ */
/* **************** PRIMITIF BERDASARKAN NILAI **************** */
/* ************************************************************ */

/* ************************* */
/* *** PENAMBAHAN ELEMEN *** */
/* ************************* */

/* I.S. List mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai newValue jika alokasi berhasil */
void insertValueFirst(List *list, InfoType newValue);

/* I.S. List mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai newValue jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertValueLast(List *list, InfoType newValue);

/* ************************** */
/* *** PENGHAPUSAN ELEMEN *** */
/* ************************** */

/* I.S. List tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai INFO(node) disimpan pada *deletedValue */
/* dan alamat elemen pertama di-dealokasi */
void deleteValueFirst(List *list, InfoType *deletedValue);

/* I.S. List tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada *deletedValue */
/* dan alamat elemen terakhir di-dealokasi */
void deleteValueLast(List *list, InfoType *deletedValue);

/* ************************************************************* */
/* **************** PRIMITIF BERDASARKAN ALAMAT **************** */
/* ************************************************************* */

/* ******************************************** */
/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
/* ******************************************** */

/* I.S. Sembarang, newNode sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address newNode sebagai elemen pertama */
void insertFirst(List *list, Address newNode);

/* I.S. prevNode pastilah elemen list dan bukan elemen terakhir, */
/* newNode sudah dialokasi  */
/* F.S. Insert newNode sebagai elemen sesudah elemen beralamat prevNode */
void insertAfter(Address newNode, Address prevNode);

/* I.S. Sembarang, newNode sudah dialokasi  */
/* F.S. newNode ditambahkan sebagai elemen terakhir yang baru */
void insertLast(List *list, Address newNode);

/* ********************************* */
/* *** PENGHAPUSAN SEBUAH ELEMEN *** */
/* ********************************* */

/* I.S. List tidak kosong */
/* F.S. deletedNode adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First list yg baru adalah suksesor elemen pertama yang lama */
void deleteFirst(List *list, Address *deletedNode);

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress node, dengan INFO(node)=valueToDelete  */
/* Maka node dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan INFO(node)=valueToDelete, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void deleteNode(List *list, InfoType valueToDelete);

/* I.S. List tidak kosong */
/* F.S. deletedNode adalah alamat elemen terakhir list sebelum penghapusan  */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last list baru adalah predesesor elemen terakhir yg lama, jika ada */
void deleteLast(List *list, Address *deletedNode);

/* I.S. List tidak kosong. prevNode adalah anggota list  */
/* F.S. Menghapus NEXT(prevNode): */
/* deletedNode adalah alamat elemen list yang dihapus  */
void deleteAfter(List *list, Address *deletedNode, Address prevNode);

/* ********************************************************** */
/* **************** PROSES SEMUA ELEMEN LIST **************** */
/* ********************************************************** */

/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
void printInfo(List list);

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int numberOfElements(List list);

/* ************************** NOTE ****************************** */
/* *** Prekondisi untuk Max/Min/rata-rata : List tidak kosong *** */
/* ************************************************************** */

/* Mengirimkan nilai INFO(node) yang maksimum */
InfoType max(List list);

/* Mengirimkan address node, dengan INFO(node) yang bernilai maksimum */
Address addressMax(List list);

/* Mengirimkan nilai INFO(node) yang minimum */
InfoType min(List list);

/* Mengirimkan address node, dengan INFO(node) yang bernilai minimum */
Address addressMin(List list);

/* Mengirimkan nilai rata-rata seluruh INFO(node) dalam list */
float average(List list);

/* ****************************************************** */
/* **************** PROSES TERHADAP LIST **************** */
/* ****************************************************** */

/* I.S. Sembarang. */
/* F.S. Elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
void inversList(List *list);

/* I.S. list1 dan list2 mungkin kosong, sembarang */
/* F.S. list1 dan list2 kosong, list3 adalah hasil konkatenasi list1 & list2 */
/* Konkatenasi dua buah list : list1 dan list2    */
/* menghasilkan list3 yang baru (dengan elemen list list1 dan list2) */
/* dan list1 serta list2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
void concat(List *list1, List *list2, List *list3);

#endif /* LISTLINIER_H */

#ifndef hashHashMap_H
#define hashHashMap_H

#include "Boolean.h"
#include <stdio.h>

/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open Addressing
 */

#define Nil 0
#define MaxEl 16
#define Undefined -9999

typedef int keytype;   // Tipe data untuk key
typedef int valuetype; // Tipe data untuk value
typedef int address;   // Tipe data untuk alamat penyimpanan

typedef struct
{
    keytype key;
    valuetype value;
} infotype;

typedef struct
{
    // List of key-value pairs with maximum size MaxEl
    // Jumlah elemen dalam HashMap
    infotype Elements[MaxEl];
    int Count;
} HashMap;

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
// TODO: 1. CreateEmpty
void CreateEmpty(HashMap *M);

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K);
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
// TODO: 2. Value
valuetype Value(HashMap M, keytype K);

// TODO: 3. Insert
void Insert(HashMap *M, keytype K, valuetype V);

// TODO: 4. printHashMap
void printHashMap(HashMap M);

#endif /* hashHashMap_H */
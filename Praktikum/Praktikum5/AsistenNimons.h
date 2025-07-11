/**
 * --------------------------------------------------------------
 * | @file AsistenNimons.h                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Header file untuk ADT List Statik yang digunakan untuk     |
 * | mengelola daftar nilai praktikum Nimons. Mendefinisikan    |
 * | struktur data dan prototipe fungsi terkait.                |
 * --------------------------------------------------------------
 */

#ifndef ASISTENNIMONS_H
#define ASISTENNIMONS_H

#include "Boolean.h" // Asumsi Boolean.h sudah distandarisasi
// #include <stdio.h> // Sebaiknya di .c jika hanya untuk printf
// #include <string.h> // Sebaiknya di .c jika hanya untuk strcmp/strcpy

/* ***************************************************** */
/* ********************** KONSTANTA ******************** */
/* ***************************************************** */

#define MAX_CAPACITY 100   // Kapasitas maksimum list.
#define IDX_UNDEFINED -1   // Indeks yang tidak terdefinisi.
#define MAX_NAME_LENGTH 10 // Panjang maksimum nama Nimons (sesuai ElType asli).

/* ***************************************************** */
/* ********************** TIPE DATA ******************** */
/* ***************************************************** */

typedef int IdxType; // Tipe data untuk indeks array.

/**
 * @struct NimonsScoreRecord
 * @brief Menyimpan detail satu record nilai praktikum Nimons.
 * @details Terdiri dari nama Nimons, nomor praktikum, dan nilai yang diperoleh.
 */
typedef struct NimonsScoreRecord // Mengganti ElType menjadi nama yang lebih deskriptif
{
    char nimonsName[MAX_NAME_LENGTH + 1]; /**< Nama Nimons (string, +1 untuk null terminator). */
    int practicumNumber;                  /**< Nomor praktikum (misal, 1, 2, ...). */
    int score;                            /**< Nilai praktikum (0-100). */
} NimonsScoreRecord;

/**
 * @struct NimonsScoreList
 * @brief Merepresentasikan list statik untuk menyimpan kumpulan NimonsScoreRecord.
 * @details Menggunakan array dengan kapasitas tetap MAX_CAPACITY.
 */
typedef struct NimonsScoreList // Mengganti ListNilaiNimons
{
    NimonsScoreRecord scores[MAX_CAPACITY]; /**< Container (array) untuk menyimpan data nilai. */
    int effectiveElementCount;              /**< Jumlah elemen efektif yang terisi dalam list. */
} NimonsScoreList;

/*
 * Catatan Struktur Data dan Akses:
 * - Indeks yang digunakan: [0..MAX_CAPACITY-1].
 * - Jika `list` adalah NimonsScoreList:
 *   - `list.effectiveElementCount`: Jumlah elemen yang valid.
 *   - `list.scores`: Array yang menyimpan elemen.
 *   - `list.scores[i]`: Elemen pada indeks ke-i.
 * - Definisi List Kosong: `list.effectiveElementCount == 0`.
 * - Elemen Pertama: `list.scores[0]` (jika tidak kosong).
 * - Elemen Terakhir: `list.scores[list.effectiveElementCount - 1]` (jika tidak kosong).
 *
 * Asumsi Tambahan (dari file asli):
 * - Nomor praktikum (`practicumNumber`) diasumsikan terurut membesar dan berurutan
 *   (misal, 1, 2, 3, ...), tidak ada lompatan.
 */

/* ***************************************************** */
/* ******************** KONSTRUKTOR ******************** */
/* ***************************************************** */

/**
 * @brief Menginisialisasi list skor Nimons menjadi kosong.
 * @param list Pointer ke `NimonsScoreList` yang akan diinisialisasi.
 * @note I.S. : `list` sembarang.
 * @note F.S. : `list` terinisialisasi sebagai list kosong (`effectiveElementCount` = 0).
 */
void createEmptyScoreList(NimonsScoreList *list);

/* ***************************************************** */
/* ********************** SELEKTOR ********************* */
/* ***************************************************** */

// --- Banyaknya Elemen ---
/**
 * @brief Mengembalikan jumlah elemen efektif dalam list skor.
 * @param list `NimonsScoreList` yang akan dihitung elemennya.
 * @return int Jumlah elemen efektif. Mengembalikan 0 jika list kosong.
 */
int getNumberOfElements(NimonsScoreList list);

// --- Daya Tampung Container ---
/**
 * @brief Mengembalikan kapasitas maksimum list skor.
 * @param list `NimonsScoreList` (parameter ini sebenarnya tidak digunakan oleh implementasi).
 * @return int Kapasitas maksimum list (`MAX_CAPACITY`).
 */
int getMaxCapacity(NimonsScoreList list);

// --- Selektor Indeks ---
/**
 * @brief Mengembalikan indeks pertama yang valid untuk list (selalu 0).
 * @param list `NimonsScoreList` (parameter ini tidak digunakan oleh implementasi).
 * @return IdxType Indeks pertama (0).
 * @note Prekondisi: List tidak kosong (meskipun fungsi ini tetap mengembalikan 0).
 */
IdxType getFirstIndex(NimonsScoreList list);

/**
 * @brief Mengembalikan indeks terakhir yang terisi dalam list.
 * @param list `NimonsScoreList` yang akan diperiksa.
 * @return IdxType Indeks terakhir yang efektif. Mengembalikan `IDX_UNDEFINED` (-1) jika list kosong.
 * @note Prekondisi: List tidak kosong.
 */
IdxType getLastIndex(NimonsScoreList list);

// --- Menghasilkan Sebuah Elemen ---
/**
 * @brief Mengembalikan elemen (record nilai) pada indeks tertentu.
 * @param list `NimonsScoreList` sumber.
 * @param index Indeks elemen yang diinginkan.
 * @return NimonsScoreRecord Elemen pada `list.scores[index]`.
 * @note Prekondisi: List tidak kosong, `index` berada dalam rentang `getFirstIndex(list)` hingga `getLastIndex(list)`.
 */
NimonsScoreRecord getElementAt(NimonsScoreList list, IdxType index);

// --- Selektor SET: Mengubah Nilai List dan Elemen List ---
/**
 * @brief Menyalin isi dari `sourceList` ke `destinationList`.
 * @param sourceList `NimonsScoreList` sumber.
 * @param destinationList Pointer ke `NimonsScoreList` tujuan.
 * @note I.S. : `sourceList` terdefinisi, `destinationList` adalah pointer valid.
 * @note F.S. : `destinationList` berisi salinan identik dari `sourceList`.
 */
void copyScoreList(NimonsScoreList sourceList, NimonsScoreList *destinationList);

/**
 * @brief Mengatur nilai elemen pada `index` tertentu dalam `list` menjadi `value`.
 * @details Jika `index` lebih besar dari `effectiveElementCount` saat ini (namun masih dalam kapasitas),
 *          `effectiveElementCount` akan diperbarui.
 * @param list Pointer ke `NimonsScoreList` yang akan dimodifikasi.
 * @param index Indeks elemen yang akan diatur.
 * @param value `NimonsScoreRecord` baru untuk elemen tersebut.
 * @note I.S. : `list` terdefinisi, `index` valid (`0 <= index < MAX_CAPACITY`), `value` terdefinisi.
 * @note F.S. : `list->scores[index]` diisi dengan `value`. `list->effectiveElementCount` mungkin diperbarui.
 */
void setElementAt(NimonsScoreList *list, IdxType index, NimonsScoreRecord value);

/**
 * @brief Mengatur jumlah elemen efektif (`effectiveElementCount`) dari `list`.
 * @param list Pointer ke `NimonsScoreList` yang akan dimodifikasi.
 * @param newCount Jumlah elemen efektif baru.
 * @note I.S. : `list` terdefinisi, `newCount` valid (`0 <= newCount <= MAX_CAPACITY`).
 * @note F.S. : `list->effectiveElementCount` diatur menjadi `newCount`.
 */
void setEffectiveCount(NimonsScoreList *list, IdxType newCount);

/* ***************************************************** */
/* ************ VALIDASI INDEKS DAN STATUS ************* */
/* ***************************************************** */

/**
 * @brief Memeriksa apakah `index` adalah indeks yang valid untuk kapasitas list.
 * @param list `NimonsScoreList` (tidak digunakan oleh implementasi).
 * @param index Indeks yang akan diperiksa.
 * @return boolean `TRUE` jika `0 <= index < MAX_CAPACITY`, `FALSE` jika tidak.
 */
boolean isIndexValid(NimonsScoreList list, IdxType index);

/**
 * @brief Memeriksa apakah `index` adalah indeks yang efektif (terisi) dalam list.
 * @param list `NimonsScoreList` yang akan diperiksa.
 * @param index Indeks yang akan diperiksa.
 * @return boolean `TRUE` jika `getFirstIndex(list) <= index <= getLastIndex(list)`, `FALSE` jika tidak.
 */
boolean isIndexEffective(NimonsScoreList list, IdxType index);

/**
 * @brief Memeriksa apakah list skor kosong.
 * @param list `NimonsScoreList` yang akan diperiksa.
 * @return boolean `TRUE` jika list kosong, `FALSE` jika tidak.
 */
boolean isScoreListEmpty(NimonsScoreList list);

/**
 * @brief Memeriksa apakah list skor penuh.
 * @param list `NimonsScoreList` yang akan diperiksa.
 * @return boolean `TRUE` jika list penuh, `FALSE` jika tidak.
 */
boolean isScoreListFull(NimonsScoreList list);

/* ***************************************************** */
/* ********** BACA/TULIS & KONSTRUKTOR ELEMEN ********** */
/* ***************************************************** */

/**
 * @brief Mencetak isi dari list skor Nimons ke standar output.
 * @details Format per elemen: `nimonsName - practicumNumber - score`.
 *          Jika list kosong, mencetak "List kosong".
 * @param list `NimonsScoreList` yang akan dicetak.
 */
void printScoreList(NimonsScoreList list);

/**
 * @brief Membuat sebuah record nilai Nimons (`NimonsScoreRecord`) baru.
 * @param name Nama Nimons (string, maks 10 char).
 * @param practicumNo Nomor praktikum (1-100).
 * @param scoreValue Nilai praktikum (0-100).
 * @return NimonsScoreRecord Record nilai Nimons yang telah diisi.
 * @note Prekondisi (tidak dicek): Parameter sesuai batasan yang ditentukan.
 */
NimonsScoreRecord createNimonsScoreRecord(char *name, int practicumNo, int scoreValue);

/* ***************************************************** */
/* ************* OPERASI STATISTIK NILAI *************** */
/* ***************************************************** */

/**
 * @brief Menghitung rata-rata nilai untuk Nimons dengan `name` tertentu.
 * @param list `NimonsScoreList` sumber data.
 * @param name Nama Nimons yang dicari.
 * @return float Rata-rata nilai. Mengembalikan 0.0 jika Nimons tidak ditemukan atau tidak ada nilai.
 * @note Prekondisi: `list` tidak kosong (sesuai deskripsi asli, namun implementasi sebaiknya tangguh).
 */
float calculateAverageScoreByName(NimonsScoreList list, char *name);

/**
 * @brief Mencari nilai maksimum untuk Nimons dengan `name` tertentu.
 * @param list `NimonsScoreList` sumber data.
 * @param name Nama Nimons yang dicari.
 * @return int Nilai maksimum. Mengembalikan -1 jika Nimons tidak ditemukan atau tidak ada nilai.
 * @note Prekondisi: `list` tidak kosong.
 */
int findMaxScoreByName(NimonsScoreList list, char *name);

/**
 * @brief Mencari nilai minimum untuk Nimons dengan `name` tertentu.
 * @param list `NimonsScoreList` sumber data.
 * @param name Nama Nimons yang dicari.
 * @return int Nilai minimum. Mengembalikan 101 jika Nimons tidak ditemukan (sesuai nilai default di implementasi).
 * @note Prekondisi: `list` tidak kosong.
 */
int findMinScoreByName(NimonsScoreList list, char *name);

/**
 * @brief Menghitung rata-rata keseluruhan nilai dari semua Nimons dalam list.
 * @param list `NimonsScoreList` sumber data.
 * @return float Rata-rata keseluruhan nilai. Mengembalikan 0.0 jika list kosong.
 */
float calculateOverallAverageScore(NimonsScoreList list);

/**
 * @brief Mencari nilai maksimum keseluruhan dari semua Nimons dalam list.
 * @param list `NimonsScoreList` sumber data.
 * @return int Nilai maksimum. Mengembalikan -1 jika list kosong.
 */
int findOverallMaxScore(NimonsScoreList list);

/**
 * @brief Mencari nilai minimum keseluruhan dari semua Nimons dalam list.
 * @param list `NimonsScoreList` sumber data.
 * @return int Nilai minimum. Mengembalikan 101 jika list kosong (sesuai nilai default di implementasi).
 */
int findOverallMinScore(NimonsScoreList list);

/**
 * @brief Menghitung jumlah praktikum unik yang tercatat dalam list.
 * @param list `NimonsScoreList` sumber data.
 * @return int Jumlah praktikum unik.
 * @note Prekondisi: `list` tidak kosong.
 */
int countUniquePracticums(NimonsScoreList list);

/**
 * @brief Menampilkan statistik keseluruhan (total praktikum unik, rata-rata, maks, min) dari list.
 * @param list `NimonsScoreList` sumber data.
 * @note I.S. : `list` DIPASTIKAN tidak kosong.
 * @note F.S. : Statistik dicetak ke layar. Desimal dengan 2 angka di belakang koma.
 */
void displayOverallStatistics(NimonsScoreList list);

/**
 * @brief Menampilkan statistik nilai (per praktikum, rata-rata, maks, min, nilai akhir) untuk Nimons `name`.
 * @param list `NimonsScoreList` sumber data.
 * @param name Nama Nimons yang statistiknya akan ditampilkan.
 * @note I.S. : `list` DIPASTIKAN tidak kosong.
 * @note F.S. : Statistik Nimons `name` dicetak ke layar.
 */
void displayNimonsStatistics(NimonsScoreList list, char *name);

/* ***************************************************** */
/* *********************** UTILITAS ******************** */
/* ***************************************************** */

/**
 * @brief Mengonversi nilai angka (0-100) menjadi nilai huruf (grade).
 * @param score Nilai angka yang akan dikonversi.
 * @return char Nilai huruf (A, B, C, D, E). Mengembalikan 'I' jika nilai di luar rentang 0-100.
 * @note Prekondisi: `score` adalah integer.
 */
char convertScoreToGrade(int score);

#endif // ASISTENNIMONS_H
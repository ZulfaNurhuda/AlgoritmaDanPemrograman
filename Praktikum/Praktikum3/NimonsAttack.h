/**
 * --------------------------------------------------------------
 * | @file NimonsAttack.h                                       |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Header file untuk ADT dan fungsi terkait simulasi serangan |
 * | Nimons. Mendefinisikan struktur data untuk Koordinat dan   |
 * | Kapal, serta prototipe fungsi untuk operasi terkait.       |
 * --------------------------------------------------------------
 */

#ifndef NIMONSATTACK_H
#define NIMONSATTACK_H

// #define _INF 1000000000 // Konstanta tidak digunakan dalam fungsi yang dideklarasikan di sini.
                         // Jika akan digunakan, pastikan relevansinya jelas.

#include "Boolean.h" // Untuk tipe data boolean (TRUE/FALSE)
// Tidak perlu include <math.h>, <stdio.h>, <string.h> di header jika hanya untuk deklarasi fungsi
// yang parameternya tidak menggunakan tipe dari library tersebut secara langsung (misal FILE*).
// Cukup di .c file.

/* ***************************************************** */
/* ********************** TIPE DATA ******************** */
/* ***************************************************** */

/**
 * @struct Koordinat
 * @brief Merepresentasikan sebuah titik koordinat (x, y) dalam sistem kartesius 2D.
 */
typedef struct Koordinat // Memberikan nama pada struct untuk kejelasan
{
    int x; /**< Komponen absis (x) dari koordinat. */
    int y; /**< Komponen ordinat (y) dari koordinat. */
} Koordinat;

/**
 * @struct Kapal
 * @brief Merepresentasikan sebuah kapal dengan posisi dan kode identifikasi.
 */
typedef struct Kapal // Memberikan nama pada struct untuk kejelasan
{
    Koordinat posisi; /**< Posisi kapal saat ini, direpresentasikan oleh struct Koordinat. */
    char kode[3];     /**< Kode identifikasi unik untuk kapal (maksimal 2 karakter + null terminator). */
} Kapal;

/* ***************************************************** */
/* ******************* PROTOTIPE FUNGSI **************** */
/* ***************************************************** */

/**
 * @brief Menghitung jarak Euclidean antara sebuah kapal dan sebuah pulau.
 * @param ship Kapal yang posisinya akan digunakan untuk perhitungan jarak.
 * @param islandCoordinate Koordinat pulau yang menjadi titik acuan.
 * @return float Jarak Euclidean antara kapal dan pulau.
 * @note I.S. : `ship` dan `islandCoordinate` terdefinisi.
 * @note F.S. : Mengembalikan jarak non-negatif.
 */
float calculateDistanceToIsland(Kapal ship, Koordinat islandCoordinate);

/**
 * @brief Menghitung jarak Euclidean antara dua buah kapal.
 * @param ship1 Kapal pertama.
 * @param ship2 Kapal kedua.
 * @return float Jarak Euclidean antara kedua kapal.
 * @note I.S. : `ship1` dan `ship2` terdefinisi.
 * @note F.S. : Mengembalikan jarak non-negatif.
 */
float calculateDistanceBetweenShips(Kapal ship1, Kapal ship2);

/**
 * @brief Memeriksa apakah penempatan sebuah kapal baru valid terhadap kondisi yang ada.
 * @details Validitas ditentukan berdasarkan:
 *          1. Tidak ada tabrakan posisi dengan kapal lain yang sudah ada.
 *          2. Tidak ada duplikasi kode kapal dengan kapal lain yang sudah ada.
 *          3. Tidak ada tabrakan posisi dengan pulau.
 *        Jika tidak valid, fungsi ini akan mencetak pesan error yang sesuai ke standar output.
 * @param newShip Kapal baru yang validitas penempatannya akan dicek.
 * @param islandCoordinate Koordinat pulau.
 * @param existingShips Array dari kapal-kapal yang sudah ada sebelumnya.
 * @param numberOfExistingShips Jumlah kapal yang ada dalam array `existingShips`.
 * @return boolean `TRUE` jika penempatan kapal valid, `FALSE` jika tidak.
 * @note I.S. : Semua parameter terdefinisi.
 * @note F.S. : Mengembalikan status validitas. Pesan error dicetak jika tidak valid.
 */
boolean isShipPlacementValid(Kapal newShip, Koordinat islandCoordinate, Kapal *existingShips, int numberOfExistingShips);

/**
 * @brief Mengurutkan sebuah array kapal berdasarkan jarak terdekat ke pulau (ascending).
 * @details Menggunakan algoritma pengurutan sederhana (misalnya, bubble sort seperti di implementasi asli).
 *          Pengurutan dilakukan secara in-place pada array `shipList`.
 * @param shipList Pointer ke array kapal yang akan diurutkan.
 * @param islandCoordinate Koordinat pulau yang menjadi acuan untuk perhitungan jarak.
 * @param shipCount Jumlah kapal dalam `shipList`.
 * @note I.S. : `shipList`, `islandCoordinate`, dan `shipCount` terdefinisi. `shipList` berisi `shipCount` kapal.
 * @note F.S. : Array `shipList` terurut berdasarkan jarak setiap kapal ke `islandCoordinate` secara menaik.
 */
void sortShipsByDistanceToIsland(Kapal *shipList, Koordinat islandCoordinate, int shipCount);

/**
 * @brief Fungsi utama untuk menjalankan simulasi, mencari, dan melaporkan kapal terdekat yang dalam radius serang.
 * @details Fungsi ini akan:
 *          1. Membaca jumlah total kapal yang akan diinput dan radius serang.
 *          2. Membaca koordinat pulau.
 *          3. Membaca data untuk setiap kapal (posisi dan kode), memvalidasi penempatannya.
 *          4. Mengurutkan kapal-kapal yang valid berdasarkan jaraknya ke pulau.
 *          5. Mencetak informasi kapal yang berada dalam radius serang, diurutkan dari yang terdekat.
 *          6. Jika ada kapal (setelah diurutkan) yang berada di luar radius serang,
 *             mencetak pesan "Perdamaian di pulau Mackenbruh telah usai :(" dan berhenti melaporkan.
 * @note I.S. : Tidak ada. Input dibaca dari standar input.
 * @note F.S. : Hasil simulasi dicetak ke standar output.
 */
void findAndReportNearbyShips(void); // Menggunakan void karena tidak menerima argumen langsung

#endif // NIMONSATTACK_H
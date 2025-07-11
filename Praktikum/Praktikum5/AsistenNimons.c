/**
 * --------------------------------------------------------------
 * | @file AsistenNimons.c                                      |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT List Statik untuk mengelola daftar nilai  |
 * | praktikum Nimons. Termasuk fungsi dasar list, serta        |
 * | fungsi statistik untuk menghitung rata-rata, nilai min/max,|
 * | dan konversi nilai ke huruf.                               |
 * --------------------------------------------------------------
 */

#include "AsistenNimons.h" // Asumsi header ini mendefinisikan NimonsScoreList, NimonsScoreRecord, MAX_CAPACITY, IdxType, boolean
#include <stdio.h>        // Untuk printf
#include <string.h>       // Untuk strcpy, strcmp

/**
 * @brief Menginisialisasi list skor Nimons menjadi kosong.
 * @param list Pointer ke NimonsScoreList yang akan diinisialisasi.
 * @note I.S. : `list` sembarang.
 * @note F.S. : `list` terinisialisasi sebagai list kosong (`effectiveElementCount` = 0).
 */
void createEmptyScoreList(NimonsScoreList *list)
{
    list->effectiveElementCount = 0;
}

/**
 * @brief Mengembalikan jumlah elemen efektif dalam list skor.
 * @param list NimonsScoreList yang akan dihitung elemennya.
 * @return int Jumlah elemen efektif.
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Mengembalikan `list.effectiveElementCount`.
 */
int getNumberOfElements(NimonsScoreList list)
{
    return list.effectiveElementCount;
}

/**
 * @brief Mengembalikan kapasitas maksimum list skor.
 * @param list NimonsScoreList (parameter tidak benar-benar digunakan, MAX_CAPACITY adalah konstanta).
 * @return int Kapasitas maksimum list.
 * @note I.S. : `list` terdefinisi (meskipun tidak digunakan).
 * @note F.S. : Mengembalikan `MAX_CAPACITY`.
 */
int getMaxCapacity(NimonsScoreList list) // Parameter list sebenarnya tidak dibutuhkan jika MAX_CAPACITY global
{
    return MAX_CAPACITY;
}

/**
 * @brief Mengembalikan indeks pertama yang valid untuk list (selalu 0 untuk implementasi ini).
 * @param list NimonsScoreList (parameter tidak benar-benar digunakan).
 * @return IdxType Indeks pertama (0).
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Mengembalikan 0.
 */
IdxType getFirstIndex(NimonsScoreList list) // Parameter list tidak digunakan
{
    return 0; // Indeks pertama selalu 0 untuk array C.
}

/**
 * @brief Mengembalikan indeks terakhir yang terisi dalam list.
 * @param list NimonsScoreList yang akan diperiksa.
 * @return IdxType Indeks terakhir yang efektif. Mengembalikan -1 jika list kosong.
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Mengembalikan `list.effectiveElementCount - 1`.
 */
IdxType getLastIndex(NimonsScoreList list)
{
    return list.effectiveElementCount - 1;
}

/**
 * @brief Mengembalikan elemen (NimonsScoreRecord) pada indeks tertentu.
 * @param list NimonsScoreList sumber.
 * @param index Indeks elemen yang diinginkan. Diasumsikan valid dan efektif.
 * @return NimonsScoreRecord Elemen pada `list.scores[index]`.
 * @note I.S. : `list` terdefinisi, `index` adalah indeks yang valid dan efektif.
 * @note F.S. : Mengembalikan elemen pada `index`.
 */
NimonsScoreRecord getElementAt(NimonsScoreList list, IdxType index)
{
    // Diasumsikan index valid dan efektif sesuai prekondisi umum ADT List.
    return list.scores[index];
}

/**
 * @brief Menyalin isi dari satu list skor ke list skor lainnya.
 * @param sourceList NimonsScoreList sumber.
 * @param destinationList Pointer ke NimonsScoreList tujuan.
 * @note I.S. : `sourceList` terdefinisi, `destinationList` adalah pointer valid.
 * @note F.S. : `destinationList` berisi salinan dari `sourceList`.
 */
void copyScoreList(NimonsScoreList sourceList, NimonsScoreList *destinationList)
{
    destinationList->effectiveElementCount = sourceList.effectiveElementCount;
    for (int i = 0; i < sourceList.effectiveElementCount; i++)
    {
        destinationList->scores[i] = sourceList.scores[i];
    }
}

/**
 * @brief Mengatur nilai elemen pada indeks tertentu dalam list skor.
 * @details Jika `index` lebih besar dari `effectiveElementCount` saat ini,
 *          `effectiveElementCount` akan diperbarui menjadi `index + 1`.
 * @param list Pointer ke NimonsScoreList yang akan dimodifikasi.
 * @param index Indeks elemen yang akan diatur. Diasumsikan valid.
 * @param value Nilai (NimonsScoreRecord) baru untuk elemen tersebut.
 * @note I.S. : `list` terdefinisi, `index` valid (`0 <= index < MAX_CAPACITY`), `value` terdefinisi.
 * @note F.S. : `list->scores[index]` diisi dengan `value`. `list->effectiveElementCount` mungkin diperbarui.
 */
void setElementAt(NimonsScoreList *list, IdxType index, NimonsScoreRecord value)
{
    // Diasumsikan index valid (tidak melebihi MAX_CAPACITY).
    list->scores[index] = value;
    // Jika elemen baru ditambahkan di luar batas efektif saat ini, perbarui batas efektif.
    if (list->effectiveElementCount < index + 1)
    {
        list->effectiveElementCount = index + 1;
    }
}

/**
 * @brief Mengatur jumlah elemen efektif dalam list skor.
 * @param list Pointer ke NimonsScoreList yang akan dimodifikasi.
 * @param newCount Jumlah elemen efektif baru. Diasumsikan valid.
 * @note I.S. : `list` terdefinisi, `newCount` valid (`0 <= newCount <= MAX_CAPACITY`).
 * @note F.S. : `list->effectiveElementCount` diatur menjadi `newCount`.
 */
void setEffectiveCount(NimonsScoreList *list, IdxType newCount)
{
    // Diasumsikan newCount valid.
    list->effectiveElementCount = newCount;
}

/**
 * @brief Memeriksa apakah sebuah indeks valid untuk kapasitas list.
 * @param list NimonsScoreList (parameter tidak benar-benar digunakan untuk logika ini).
 * @param index Indeks yang akan diperiksa.
 * @return boolean true jika `0 <= index < MAX_CAPACITY`, false jika tidak.
 * @note I.S. : `list` terdefinisi, `index` terdefinisi.
 * @note F.S. : Mengembalikan status validitas indeks terhadap kapasitas.
 */
boolean isIndexValid(NimonsScoreList list, IdxType index) // Parameter list tidak digunakan
{
    return (index >= getFirstIndex(list) && index < MAX_CAPACITY);
}

/**
 * @brief Memeriksa apakah sebuah indeks adalah indeks efektif (terisi) dalam list.
 * @param list NimonsScoreList yang akan diperiksa.
 * @param index Indeks yang akan diperiksa.
 * @return boolean true jika `getFirstIndex(list) <= index <= getLastIndex(list)`, false jika tidak.
 * @note I.S. : `list` dan `index` terdefinisi.
 * @note F.S. : Mengembalikan status efektivitas indeks.
 */
boolean isIndexEffective(NimonsScoreList list, IdxType index)
{
    // Perlu hati-hati jika list kosong, getLastIndex(list) akan -1.
    if (isScoreListEmpty(list)) return false;
    return (index >= getFirstIndex(list) && index <= getLastIndex(list));
}

/**
 * @brief Memeriksa apakah list skor kosong.
 * @param list NimonsScoreList yang akan diperiksa.
 * @return boolean true jika `effectiveElementCount == 0`, false jika tidak.
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Mengembalikan status kekosongan list.
 */
boolean isScoreListEmpty(NimonsScoreList list)
{
    return (list.effectiveElementCount == 0);
}

/**
 * @brief Memeriksa apakah list skor penuh.
 * @param list NimonsScoreList yang akan diperiksa.
 * @return boolean true jika `effectiveElementCount == MAX_CAPACITY`, false jika tidak.
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Mengembalikan status kepenuhan list.
 */
boolean isScoreListFull(NimonsScoreList list)
{
    return (list.effectiveElementCount == MAX_CAPACITY);
}

/**
 * @brief Mencetak isi dari list skor Nimons ke standar output.
 * @details Format per elemen: `nama - praktikum - nilai`.
 *          Jika list kosong, mencetak "List kosong".
 * @param list NimonsScoreList yang akan dicetak.
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Isi list dicetak ke layar.
 */
void printScoreList(NimonsScoreList list)
{
    if (isScoreListEmpty(list))
    {
        printf("List kosong\n");
    }
    else
    {
        for (IdxType i = 0; i < list.effectiveElementCount; i++)
        {
            printf("%s - %d - %d\n", list.scores[i].nimonsName, list.scores[i].practicumNumber, list.scores[i].score);
        }
    }
}

/**
 * @brief Membuat sebuah record nilai Nimons baru.
 * @param name Nama Nimons (string).
 * @param practicumNo Nomor praktikum.
 * @param scoreValue Nilai praktikum.
 * @return NimonsScoreRecord Record nilai Nimons yang telah diisi.
 * @note I.S. : `name`, `practicumNo`, `scoreValue` terdefinisi.
 * @note F.S. : Mengembalikan `NimonsScoreRecord` baru.
 */
NimonsScoreRecord createNimonsScoreRecord(char *name, int practicumNo, int scoreValue)
{
    NimonsScoreRecord newScoreRecord;

    // Salin nama, pastikan tidak overflow.
    strncpy(newScoreRecord.nimonsName, name, sizeof(newScoreRecord.nimonsName) - 1);
    newScoreRecord.nimonsName[sizeof(newScoreRecord.nimonsName) - 1] = '\0'; // Pastikan null-terminated

    newScoreRecord.practicumNumber = practicumNo;
    newScoreRecord.score = scoreValue;

    return newScoreRecord;
}

/**
 * @brief Menghitung rata-rata nilai untuk Nimons dengan nama tertentu.
 * @param list NimonsScoreList yang berisi data nilai.
 * @param name Nama Nimons yang nilainya akan dihitung rata-ratanya.
 * @return float Rata-rata nilai. Mengembalikan 0.0 jika Nimons tidak ditemukan atau tidak ada nilai.
 * @note I.S. : `list` dan `name` terdefinisi.
 * @note F.S. : Mengembalikan rata-rata nilai Nimons `name`.
 */
float calculateAverageScoreByName(NimonsScoreList list, char *name)
{
    int totalScore = 0;
    int scoreCount = 0;

    for (int i = 0; i < list.effectiveElementCount; i++)
    {
        if (strcmp(list.scores[i].nimonsName, name) == 0)
        {
            totalScore += list.scores[i].score;
            scoreCount++;
        }
    }

    float averageScore;
    if (scoreCount == 0)
    {
        averageScore = 0.0f; // Gunakan f untuk float literal
    }
    else
    {
        averageScore = (float)totalScore / scoreCount;
    }
    return averageScore;
}

/**
 * @brief Mencari nilai maksimum untuk Nimons dengan nama tertentu.
 * @param list NimonsScoreList yang berisi data nilai.
 * @param name Nama Nimons yang nilai maksimumnya akan dicari.
 * @return int Nilai maksimum. Mengembalikan -1 jika Nimons tidak ditemukan atau tidak ada nilai.
 * @note I.S. : `list` dan `name` terdefinisi.
 * @note F.S. : Mengembalikan nilai maksimum Nimons `name`.
 */
int findMaxScoreByName(NimonsScoreList list, char *name)
{
    int maxScore = -1; // Asumsi nilai tidak mungkin negatif.
    for (int i = 0; i < list.effectiveElementCount; i++)
    {
        if (strcmp(list.scores[i].nimonsName, name) == 0 && list.scores[i].score > maxScore)
        {
            maxScore = list.scores[i].score;
        }
    }
    return maxScore;
}

/**
 * @brief Mencari nilai minimum untuk Nimons dengan nama tertentu.
 * @param list NimonsScoreList yang berisi data nilai.
 * @param name Nama Nimons yang nilai minimumnya akan dicari.
 * @return int Nilai minimum. Mengembalikan 101 (nilai di atas maks) jika Nimons tidak ditemukan.
 * @note I.S. : `list` dan `name` terdefinisi.
 * @note F.S. : Mengembalikan nilai minimum Nimons `name`.
 */
int findMinScoreByName(NimonsScoreList list, char *name)
{
    int minScore = 101; // Inisialisasi dengan nilai lebih tinggi dari skor maksimum mungkin.
    bool found = false;
    for (int i = 0; i < list.effectiveElementCount; i++)
    {
        if (strcmp(list.scores[i].nimonsName, name) == 0) {
            found = true;
            if (list.scores[i].score < minScore)
            {
                minScore = list.scores[i].score;
            }
        }
    }
    return found ? minScore : 101; // Kembalikan 101 jika tidak ditemukan, sesuai logika asli.
}

/**
 * @brief Menghitung rata-rata keseluruhan nilai dari semua Nimons.
 * @param list NimonsScoreList yang berisi data nilai.
 * @return float Rata-rata keseluruhan nilai. Mengembalikan 0.0 jika list kosong.
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Mengembalikan rata-rata semua nilai dalam `list`.
 */
float calculateOverallAverageScore(NimonsScoreList list)
{
    int totalScore = 0;

    for (int i = 0; i < list.effectiveElementCount; i++)
    {
        totalScore += list.scores[i].score;
    }

    float averageScore;
    if (list.effectiveElementCount == 0)
    {
        averageScore = 0.0f;
    }
    else
    {
        averageScore = (float)totalScore / list.effectiveElementCount;
    }
    return averageScore;
}

/**
 * @brief Mencari nilai maksimum keseluruhan dari semua Nimons.
 * @param list NimonsScoreList yang berisi data nilai.
 * @return int Nilai maksimum keseluruhan. Mengembalikan -1 jika list kosong.
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Mengembalikan nilai tertinggi dalam `list`.
 */
int findOverallMaxScore(NimonsScoreList list)
{
    int maxScore = -1;
    if (isScoreListEmpty(list)) return -1; // Menangani list kosong secara eksplisit.

    for (int i = 0; i < list.effectiveElementCount; i++)
    {
        if (list.scores[i].score > maxScore)
        {
            maxScore = list.scores[i].score;
        }
    }
    return maxScore;
}

/**
 * @brief Mencari nilai minimum keseluruhan dari semua Nimons.
 * @param list NimonsScoreList yang berisi data nilai.
 * @return int Nilai minimum keseluruhan. Mengembalikan 101 jika list kosong.
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Mengembalikan nilai terendah dalam `list`.
 */
int findOverallMinScore(NimonsScoreList list)
{
    int minScore = 101;
    if (isScoreListEmpty(list)) return 101; // Menangani list kosong.

    for (int i = 0; i < list.effectiveElementCount; i++)
    {
        if (list.scores[i].score < minScore)
        {
            minScore = list.scores[i].score;
        }
    }
    return minScore;
}

/**
 * @brief Menghitung jumlah praktikum unik yang tercatat dalam list.
 * @param list NimonsScoreList yang berisi data nilai.
 * @return int Jumlah praktikum unik.
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Mengembalikan jumlah nomor praktikum yang berbeda.
 *              Asumsi nomor praktikum > 0 dan <= MAX_CAPACITY (untuk `practicumTracker`).
 */
int countUniquePracticums(NimonsScoreList list)
{
    // Array untuk melacak praktikum yang sudah dihitung.
    // Ukuran MAX_CAPACITY mungkin terlalu besar jika nomor praktikum kecil.
    // Jika MAX_PRACTICUM_NUMBER diketahui, itu lebih baik.
    // Untuk sekarang, asumsikan MAX_CAPACITY cukup.
    int practicumTracker[MAX_CAPACITY] = {0}; // Inisialisasi semua ke 0.
    int uniqueCount = 0;

    for (int i = 0; i < list.effectiveElementCount; i++)
    {
        // Cek apakah nomor praktikum valid untuk indeks array.
        if (list.scores[i].practicumNumber > 0 && list.scores[i].practicumNumber <= MAX_CAPACITY) {
            if (practicumTracker[list.scores[i].practicumNumber - 1] == 0) // -1 karena nomor praktikum 1-based.
            {
                practicumTracker[list.scores[i].practicumNumber - 1] = 1; // Tandai sudah dihitung.
                uniqueCount++;
            }
        }
    }
    return uniqueCount;
}

/**
 * @brief Menampilkan statistik keseluruhan dari semua nilai praktikum.
 * @param list NimonsScoreList yang berisi data nilai.
 * @note I.S. : `list` terdefinisi.
 * @note F.S. : Statistik (total praktikum, rata-rata, maks, min) dicetak ke layar.
 */
void displayOverallStatistics(NimonsScoreList list)
{
    int uniquePracticumCount = countUniquePracticums(list);
    float overallAverage = calculateOverallAverageScore(list);
    int overallMax = findOverallMaxScore(list);
    int overallMin = findOverallMinScore(list);

    printf("- Total praktikum: %d\n", uniquePracticumCount);
    printf("- Rata-rata: %.2f\n", overallAverage);
    printf("- Nilai maksimum: %d\n", overallMax);
    printf("- Nilai minimum: %d\n", overallMin);
}

/**
 * @brief Menampilkan statistik nilai untuk Nimons dengan nama tertentu.
 * @param list NimonsScoreList yang berisi data nilai.
 * @param name Nama Nimons yang statistiknya akan ditampilkan.
 * @note I.S. : `list` dan `name` terdefinisi.
 * @note F.S. : Detail nilai per praktikum, rata-rata, maks, min, dan nilai akhir (huruf)
 *              untuk Nimons `name` dicetak ke layar.
 */
void displayNimonsStatistics(NimonsScoreList list, char *name)
{
    printf("Nama: %s\n", name);
    bool foundNimons = false;

    // Cetak semua nilai praktikum untuk Nimons ini.
    for (IdxType i = 0; i < list.effectiveElementCount; i++)
    {
        if (strcmp(list.scores[i].nimonsName, name) == 0)
        {
            printf("Praktikum %d: %d\n", list.scores[i].practicumNumber, list.scores[i].score);
            foundNimons = true;
        }
    }

    if (!foundNimons) {
        printf("Tidak ditemukan data untuk Nimons %s.\n", name);
        // Bisa langsung return atau biarkan statistik di bawah mencetak default (0, -1, 101).
        // Sesuai kode asli, statistik tetap dihitung (yang akan menghasilkan nilai default).
    }

    printf("\n"); // Baris kosong pemisah.

    // Hitung dan cetak statistik spesifik Nimons.
    float nimonsAverage = calculateAverageScoreByName(list, name);
    int nimonsMax = findMaxScoreByName(list, name);
    int nimonsMin = findMinScoreByName(list, name);

    printf("Rata-rata: %.2f\n", nimonsAverage);
    printf("Nilai maksimum: %d\n", nimonsMax);
    printf("Nilai minimum: %d\n", nimonsMin);

    // int averageFloor = (int)nimonsAverage; // Tidak digunakan di printf selanjutnya.
    char gradeLetter = convertScoreToGrade((int)nimonsAverage); // Konversi rata-rata (dibulatkan ke bawah) ke huruf.
    printf("Nilai akhir: %c\n", gradeLetter);
}

/**
 * @brief Mengonversi nilai angka menjadi nilai huruf (grade).
 * @param score Nilai angka yang akan dikonversi.
 * @return char Nilai huruf yang sesuai (A, B, C, D, E, atau I untuk tidak valid).
 * @note I.S. : `score` terdefinisi.
 * @note F.S. : Mengembalikan grade letter.
 */
char convertScoreToGrade(int score)
{
    char grade;

    if (score >= 80 && score <= 100) // Tambahkan batas atas untuk validitas
    {
        grade = 'A';
    }
    else if (score >= 65 && score < 80)
    {
        grade = 'B';
    }
    else if (score >= 50 && score < 65)
    {
        grade = 'C';
    }
    else if (score >= 35 && score < 50)
    {
        grade = 'D';
    }
    else if (score >= 0 && score < 35)
    {
        grade = 'E';
    }
    else // Nilai di luar rentang 0-100 atau kasus lain.
    {
        grade = 'I'; // Indeks Invalid atau Tidak Ada Nilai.
    }
    return grade;
}
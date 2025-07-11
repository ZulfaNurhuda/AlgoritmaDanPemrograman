/**
 * --------------------------------------------------------------
 * | @file JelajahWaktu.c                                       |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk melakukan manipulasi tanggal, termasuk       |
 * | pengecekan tahun kabisat, perhitungan hari dalam bulan,    |
 * | penambahan hari ke tanggal, dan penentuan hari dalam       |
 * | seminggu.                                                  |
 * --------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h> // Untuk strcmp dan strcspn
#include <stdbool.h> // Digunakan secara internal oleh beberapa fungsi, namun tidak secara eksplisit di sini

/**
 * @struct Date
 * @brief Struktur untuk merepresentasikan sebuah tanggal.
 * @details Menyimpan komponen hari, bulan, dan tahun dari sebuah tanggal.
 */
typedef struct Date
{
    int day;   /**< Komponen hari dari tanggal (integer). */
    int month; /**< Komponen bulan dari tanggal (integer, 1-12). */
    int year;  /**< Komponen tahun dari tanggal (integer). */
} Date;

/**
 * @brief Memeriksa apakah suatu tahun merupakan tahun kabisat.
 * @details Tahun kabisat adalah tahun yang:
 *          - Habis dibagi 4, tetapi tidak habis dibagi 100, ATAU
 *          - Habis dibagi 400.
 * @param targetYear Tahun yang akan dicek.
 * @return int Mengembalikan 1 (true) jika tahun adalah tahun kabisat, 0 (false) jika bukan.
 * @note I.S. : targetYear terdefinisi.
 * @note F.S. : Mengembalikan status kabisat dari targetYear.
 */
int isLeapYear(int targetYear)
{
    return (targetYear % 4 == 0 && targetYear % 100 != 0) || (targetYear % 400 == 0);
}

/**
 * @brief Mendapatkan jumlah hari dalam bulan tertentu pada suatu tahun.
 * @details Memperhitungkan tahun kabisat untuk bulan Februari.
 * @param targetMonth Bulan yang akan dicek (1 untuk Januari, ..., 12 untuk Desember).
 * @param targetYear Tahun dari bulan tersebut (untuk pengecekan Februari kabisat).
 * @return int Jumlah hari dalam bulan tersebut. Mengembalikan 0 jika bulan tidak valid (meskipun
 *             logika saat ini tidak secara eksplisit menangani bulan > 12 atau < 1 dengan return 0,
 *             namun akan jatuh ke kasus 30 hari).
 * @note I.S. : targetMonth dan targetYear terdefinisi.
 * @note F.S. : Mengembalikan jumlah hari pada targetMonth di targetYear.
 */
int getDaysInMonth(int targetMonth, int targetYear)
{
    if (targetMonth == 2) // Februari
    {
        return isLeapYear(targetYear) ? 29 : 28;
    }
    // Bulan dengan 31 hari: Januari, Maret, Mei, Juli, Agustus, Oktober, Desember
    else if (targetMonth == 1 || targetMonth == 3 || targetMonth == 5 || targetMonth == 7 ||
             targetMonth == 8 || targetMonth == 10 || targetMonth == 12)
    {
        return 31;
    }
    // Bulan dengan 30 hari: April, Juni, September, November
    // (dan kasus default jika bulan di luar 1-12, meskipun idealnya divalidasi)
    else
    {
        return 30;
    }
}

/**
 * @brief Menghitung jumlah total hari dari tanggal 1 Januari tahun 1 hingga sebelum tanggal yang diberikan.
 * @details Berguna sebagai basis untuk perhitungan selisih tanggal atau penambahan hari.
 * @param date Tanggal target.
 * @return int Jumlah total hari yang telah berlalu sejak 1 Januari tahun 1 (eksklusif tanggal input, jadi -1 di akhir).
 * @note I.S. : date terdefinisi dan valid.
 * @note F.S. : Mengembalikan jumlah hari kumulatif.
 */
int daysSinceBeginning(Date date)
{
    int totalDaysCount = 0;

    // Akumulasi hari dari tahun-tahun sebelumnya (dari tahun 1 hingga date.year - 1).
    for (int currentYear = 1; currentYear < date.year; currentYear++)
    {
        totalDaysCount += isLeapYear(currentYear) ? 366 : 365;
    }

    // Akumulasi hari dari bulan-bulan sebelumnya dalam tahun berjalan (dari bulan 1 hingga date.month - 1).
    for (int currentMonth = 1; currentMonth < date.month; currentMonth++)
    {
        totalDaysCount += getDaysInMonth(currentMonth, date.year);
    }

    // Tambahkan jumlah hari dalam bulan berjalan (hingga tanggal date.day - 1).
    totalDaysCount += date.day - 1; // -1 karena kita menghitung hari *sebelum* tanggal tersebut.

    return totalDaysCount;
}

/**
 * @brief Menambahkan sejumlah hari ke tanggal yang diberikan.
 * @param initialDate Tanggal awal.
 * @param daysToAdd Jumlah hari yang akan ditambahkan (bisa positif atau negatif).
 * @return Date Tanggal baru setelah penambahan (atau pengurangan) hari.
 * @note I.S. : initialDate dan daysToAdd terdefinisi.
 * @note F.S. : Mengembalikan tanggal baru hasil penambahan daysToAdd.
 *              Fungsi ini menangani kasus jika daysToAdd negatif, secara efektif
 *              mengurangkan hari.
 */
Date addDays(Date initialDate, int daysToAdd)
{
    // Hitung jumlah hari absolut dari awal zaman hingga tanggal target.
    int totalDaysFromEpoch = daysSinceBeginning(initialDate) + daysToAdd;

    Date resultDate;
    resultDate.year = 1; // Mulai perhitungan dari tahun 1.

    // Tentukan tahun dari total hari.
    // Loop mengurangi total hari dengan jumlah hari dalam setahun hingga total hari
    // lebih kecil dari jumlah hari dalam tahun berjalan.
    while (true) // Loop akan dihentikan dengan break
    {
        int daysInCurrentYear = isLeapYear(resultDate.year) ? 366 : 365;
        if (totalDaysFromEpoch >= daysInCurrentYear)
        {
            totalDaysFromEpoch -= daysInCurrentYear;
            resultDate.year++;
        }
        else
        {
            break; // Sisa hari ada dalam tahun `resultDate.year`.
        }
    }

    // Tentukan bulan dari sisa hari.
    resultDate.month = 1; // Mulai dari bulan Januari.
    while (true) // Loop akan dihentikan dengan break
    {
        int daysInCurrentMonth = getDaysInMonth(resultDate.month, resultDate.year);
        if (totalDaysFromEpoch >= daysInCurrentMonth)
        {
            totalDaysFromEpoch -= daysInCurrentMonth;
            resultDate.month++;
        }
        else
        {
            break; // Sisa hari ada dalam bulan `resultDate.month`.
        }
    }

    // Sisa `totalDaysFromEpoch` adalah jumlah hari dalam bulan tersebut (0-indexed),
    // jadi tambahkan 1 untuk mendapatkan tanggal (1-indexed).
    resultDate.day = totalDaysFromEpoch + 1;

    return resultDate;
}

/**
 * @brief Mendapatkan indeks hari dalam seminggu untuk tanggal tertentu.
 * @details Menggunakan referensi bahwa 1 Januari tahun 1 adalah hari Senin (indeks 1).
 *          Output: 0 = Minggu, 1 = Senin, ..., 6 = Sabtu.
 * @param date Tanggal yang akan dicek.
 * @return int Indeks hari dalam seminggu.
 * @note I.S. : date terdefinisi dan valid.
 * @note F.S. : Mengembalikan indeks hari (0-6).
 */
int getDayOfWeekAsIndex(Date date)
{
    // Jumlah hari sejak awal zaman (1 Jan tahun 1).
    int totalDays = daysSinceBeginning(date);
    // 1 Jan tahun 1 adalah Senin. Hari dihitung sebagai (totalDays + 1_offset_untuk_Senin) % 7.
    // Jika 0 adalah Minggu, maka (totalDays % 7) untuk Senin sebagai hari ke-0 jika 1/1/1 adalah Minggu.
    // Karena 1/1/1 adalah Senin (hari ke-1 jika Minggu=0), maka (totalDays + 1) % 7 cocok.
    return (totalDays + 1) % 7;
}

/* FUNGSI - FUNGSI DI BAWAH INI TIDAK PERLU DIUBAH (sesuai instruksi soal) */
// Array statik untuk nama bulan dan hari.
static const char *months[] = {"Januari", "Februari", "Maret", "April",
                               "Mei", "Juni", "Juli", "Agustus",
                               "September", "Oktober", "November", "Desember"};
static const char *days[] = {"Minggu", "Senin", "Selasa", "Rabu",
                             "Kamis", "Jumat", "Sabtu"};

/**
 * @brief Mendapatkan nama hari dari tanggal tertentu dalam bahasa Indonesia.
 * @param date Tanggal yang akan dicek.
 * @return const char* Pointer ke string nama hari.
 * @note I.S. : date terdefinisi.
 * @note F.S. : Mengembalikan nama hari yang sesuai.
 */
const char *getDayOfWeek(Date date)
{
    int dayIndex = getDayOfWeekAsIndex(date);
    return days[dayIndex];
}

/**
 * @brief Mencetak tanggal dalam format "NamaHari, DD NamaBulan YYYY".
 * @param date Struktur Date yang akan dicetak.
 * @note I.S. : date terdefinisi.
 * @note F.S. : Tanggal dicetak ke standar output.
 */
void printDate(Date date)
{
    printf("%s, %d %s %d\n", getDayOfWeek(date), date.day,
           months[date.month - 1], date.year);
}

/**
 * @brief Mengonversi string nama bulan (dalam bahasa Indonesia) ke angka bulan (1-12).
 * @param monthString String nama bulan (misal, "Januari").
 * @return int Angka bulan yang sesuai (1-12), atau -1 jika nama bulan tidak valid.
 * @note I.S. : monthString terdefinisi.
 * @note F.S. : Mengembalikan nomor bulan atau -1 jika tidak cocok.
 */
int getMonthNumber(const char *monthString)
{
    for (int i = 0; i < 12; i++)
    {
        // Membandingkan string input dengan nama bulan dalam array.
        if (strcmp(monthString, months[i]) == 0)
        {
            return i + 1; // Mengembalikan nomor bulan (1-based).
        }
    }
    return -1; // Bulan tidak valid atau tidak ditemukan.
}

/**
 * @brief Mengonversi string tanggal (format "DD NamaBulan YYYY") ke struktur Date.
 * @param dateString String tanggal yang akan dikonversi.
 * @return Date Struktur Date yang merepresentasikan tanggal dari string.
 *              Jika nama bulan tidak valid, date.month akan menjadi -1.
 * @note I.S. : dateString terdefinisi dengan format yang diharapkan.
 * @note F.S. : Mengembalikan struktur Date hasil parsing.
 */
Date parseDate(const char *dateString)
{
    Date parsedDate;
    char monthNameBuffer[10]; // Buffer untuk menyimpan nama bulan dari string.
    // Mem-parse string input untuk mendapatkan hari, nama bulan, dan tahun.
    sscanf(dateString, "%d %s %d", &parsedDate.day, monthNameBuffer, &parsedDate.year);
    // Mengonversi nama bulan menjadi nomor bulan.
    parsedDate.month = getMonthNumber(monthNameBuffer);
    return parsedDate;
}

/**
 * @brief Fungsi utama program untuk demonstrasi operasi tanggal.
 * @details Program ini membaca tanggal awal dan sejumlah hari N dari input.
 *          Kemudian, ia menambahkan N hari ke tanggal awal dan mencetak
 *          tanggal baru yang dihasilkan beserta nama harinya.
 * @return int Mengembalikan 0 yang menandakan eksekusi program berhasil.
 */
int main(void) // Menggunakan void karena tidak ada argumen command line.
{
    char inputDateString[30]; // Buffer untuk string tanggal input.
    int daysToAdd;            // Jumlah hari yang akan ditambahkan.

    // Membaca string tanggal dari input (termasuk spasi, hingga newline).
    fgets(inputDateString, sizeof(inputDateString), stdin);
    // Menghapus karakter newline dari akhir string inputDateString jika ada.
    inputDateString[strcspn(inputDateString, "\n")] = 0;

    // Membaca jumlah hari yang akan ditambahkan.
    scanf("%d", &daysToAdd);

    // Mengonversi string input menjadi struktur Date.
    Date date = parseDate(inputDateString);
    // Menambahkan jumlah hari yang ditentukan ke tanggal tersebut.
    date = addDays(date, daysToAdd);
    // Mencetak tanggal hasil perhitungan.
    printDate(date);

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
#include <stdio.h>
#include <string.h>

/**
 * @brief Struktur untuk merepresentasikan tanggal.
 *
 * Struktur ini menyimpan komponen hari, bulan, dan tahun dari sebuah tanggal.
 */
typedef struct
{
    int day;   /**< day (tipe data: int) */
    int month; /**< month (tipe data: int) */
    int year;  /**< year (tipe data: int) */
} Date;

/**
 * @brief Fungsi untuk mengecek apakah tahun adalah tahun kabisat.
 *
 * Tahun kabisat adalah tahun yang:
 * Jika tahun habis dibagi 100, maka tahun tersebut harus juga habis dibagi 400,
 * Jika tahun tidak habis dibagi 100, maka tahun harus habis habis dibagi 4
 *
 * @param year Tahun yang akan dicek.
 * @return int Mengembalikan 1 jika tahun adalah tahun kabisat, 0 jika bukan.
 */
int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @brief Fungsi untuk mendapatkan jumlah hari dalam bulan tertentu.
 *
 * @param month Bulan yang akan dicek.
 * @param year Tahun yang akan dicek.
 * @return int Jumlah hari dalam bulan tersebut.
 */
int getDaysInMonth(int month, int year)
{
    if (month == 2)
    {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (((month >= 1 && month <= 7) && month % 2 == 1) ||
             ((month >= 8 && month <= 12) && month % 2 == 0))
    {
        return 31;
    }
    else
    {
        return 30;
    }
}

/**
 * @brief Fungsi untuk menghitung jumlah hari sejak 1 Januari tahun 1.
 *
 * @param date Tanggal yang akan dihitung.
 * @return int Jumlah hari sejak 1 Januari tahun 1.
 */
int daysSinceBeginning(Date date)
{
    int totalDays = 0;

    // Hitung hari dari tahun 1 sampai tahun-1
    for (int y = 1; y < date.year; y++)
    {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    // Hitung hari dari bulan 1 sampai bulan-1
    for (int m = 1; m < date.month; m++)
    {
        totalDays += getDaysInMonth(m, date.year);
    }

    // Tambahkan hari
    totalDays += date.day - 1;

    return totalDays;
}

/**
 * @brief Fungsi untuk menambahkan n hari ke tanggal.
 *
 * @param date Tanggal awal.
 * @param n Jumlah hari yang akan ditambahkan.
 * @return Date Tanggal baru setelah menambahkan n hari.
 */
Date addDays(Date date, int n)
{
    int totalDays = daysSinceBeginning(date) + n;
    int year = 1;

    // Kurangi tahun penuh
    while (totalDays > 0)
    {
        int daysInYear = isLeapYear(year) ? 366 : 365;
        if (totalDays >= daysInYear)
        {
            totalDays -= daysInYear;
            year++;
        }
        else
        {
            break;
        }
    }

    // Kurangi bulan penuh
    int month = 1;
    while (totalDays > 0)
    {
        int daysInMonth = getDaysInMonth(month, year);
        if (totalDays >= daysInMonth)
        {
            totalDays -= daysInMonth;
            month++;
        }
        else
        {
            break;
        }
    }

    // Update tanggal
    date.day = totalDays + 1;
    date.month = month;
    date.year = year;

    return date;
}

/**
 * @brief Fungsi untuk mendapatkan indeks hari dalam seminggu.
 *
 * @param date Tanggal yang akan dicek.
 * @return int Indeks hari dalam seminggu (0 = Minggu, 1 = Senin, ..., 6 = Sabtu).
 * Keterangan: 1 Januari tahun 1 adalah Senin (index 1)
 */
int getDayOfWeekAsIndex(Date date)
{
    int totalDays = daysSinceBeginning(date);
    return (totalDays + 1) % 7;
}

/* FUNGSI - FUNGSI DI BAWAH INI TIDAK PERLU DIUBAH*/

static const char *months[] = {"Januari", "Februari", "Maret", "April",
                               "Mei", "Juni", "Juli", "Agustus",
                               "September", "Oktober", "November", "Desember"};
static const char *days[] = {"Minggu", "Senin", "Selasa", "Rabu",
                             "Kamis", "Jumat", "Sabtu"};

/**
 * @brief Fungsi untuk mendapatkan nama hari dari tanggal tertentu.
 *
 * @param date Tanggal yang akan dicek.
 * @return const char* Nama hari dalam bahasa Indonesia.
 */
const char *getDayOfWeek(Date date)
{
    int dayIndex = getDayOfWeekAsIndex(date);
    return days[dayIndex];
}

/**
 * @brief Fungsi untuk mencetak tanggal dalam format yang diinginkan.
 *
 * @param date Struktur Date yang akan dicetak.
 */
void printDate(Date date)
{
    printf("%s, %d %s %d\n", getDayOfWeek(date), date.day,
           months[date.month - 1], date.year);
}

/**
 * @brief Fungsi untuk mengonversi string bulan ke angka.
 *
 * @param monthStr String nama bulan yang akan dikonversi.
 * @return int Angka bulan yang sesuai, atau -1 jika bulan tidak valid.
 */
int getMonthNumber(const char *monthStr)
{
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(monthStr, months[i]) == 0)
        {
            return i + 1;
        }
    }
    return -1; // Bulan tidak valid
}

/**
 * @brief Fungsi untuk mengonversi string tanggal ke struct Date.
 *
 * @param dateStr String tanggal yang akan dikonversi.
 * @return Date Struktur Date yang sesuai dengan string tanggal.
 */
Date parseDate(const char *dateStr)
{
    Date date;
    char monthStr[10];
    sscanf(dateStr, "%d %s %d", &date.day, monthStr, &date.year);
    date.month = getMonthNumber(monthStr);
    return date;
}

/**
 * @brief Fungsi utama untuk menjalankan program.
 *
 * Program ini membaca tanggal dan jumlah hari dari input, menambahkan jumlah
 * hari ke tanggal, dan mencetak tanggal baru.
 *
 * @return int Status keluar dari program.
 */
int main()
{
    char inputDate[30];
    int n;

    fgets(inputDate, sizeof(inputDate), stdin);
    inputDate[strcspn(inputDate, "\n")] = 0;
    scanf("%d", &n);

    Date date = parseDate(inputDate);
    date = addDays(date, n);
    printDate(date);

    return 0;
}
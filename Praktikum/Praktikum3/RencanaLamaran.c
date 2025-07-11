/**
 * --------------------------------------------------------------
 * | @file RencanaLamaran.c                                     |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menentukan rencana strategis Gro untuk       |
 * | melamar Luiy. Rencana strategis adalah pasangan waktu      |
 * | (mulai, selesai) yang durasinya (dalam menit) merupakan    |
 * | bilangan palindrom. Program akan mencetak semua rencana    |
 * | strategis yang unik.                                       |
 * --------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h> // Untuk malloc, free, abs
#include <math.h>   // Untuk abs (meskipun stdlib.h juga punya untuk int)
#include <stdbool.h> // Untuk tipe data bool (digunakan secara implisit oleh periksaRencanaDuplikat)

/**
 * @struct TimeRecord
 * @brief Merepresentasikan suatu waktu dalam format jam dan menit.
 */
typedef struct TimeRecord
{
    int hour;   /**< Komponen jam (0-23). */
    int minute; /**< Komponen menit (0-59). */
} TimeRecord;

/**
 * @struct StrategicPlan
 * @brief Merepresentasikan sebuah rencana strategis dengan waktu mulai, selesai, dan durasi.
 */
typedef struct StrategicPlan
{
    TimeRecord startTime;         /**< Waktu mulai rencana. */
    TimeRecord endTime;           /**< Waktu selesai rencana. */
    int durationInMinutes; /**< Durasi rencana dalam menit. */
} StrategicPlan;

/**
 * @brief Membalikkan digit-digit sebuah bilangan integer.
 * @param number Bilangan integer yang akan dibalik.
 * @return int Bilangan hasil pembalikan digit. Contoh: 123 -> 321.
 * @note I.S. : number terdefinisi.
 * @note F.S. : Mengembalikan versi terbalik dari number.
 */
int reverseNumber(int number)
{
    int reversedNum = 0;
    while (number != 0)
    {
        reversedNum = reversedNum * 10 + (number % 10);
        number /= 10;
    }
    return reversedNum;
}

/**
 * @brief Menghitung durasi absolut dalam menit antara dua waktu.
 * @param time1 Waktu pertama.
 * @param time2 Waktu kedua.
 * @return int Durasi absolut dalam menit.
 * @note I.S. : time1 dan time2 terdefinisi.
 * @note F.S. : Mengembalikan selisih absolut dalam menit antara time1 dan time2.
 */
int calculateDurationInMinutes(TimeRecord time1, TimeRecord time2)
{
    int startMinutes = time1.hour * 60 + time1.minute;
    int endMinutes = time2.hour * 60 + time2.minute;
    return abs(endMinutes - startMinutes); // Menggunakan abs dari stdlib.h
}

/**
 * @brief Menentukan waktu yang lebih awal dari dua waktu yang diberikan.
 * @param time1 Waktu pertama.
 * @param time2 Waktu kedua.
 * @return TimeRecord Waktu yang lebih awal.
 * @note I.S. : time1 dan time2 terdefinisi.
 * @note F.S. : Mengembalikan TimeRecord yang lebih dulu.
 */
TimeRecord getEarlierTime(TimeRecord time1, TimeRecord time2)
{
    if (time1.hour > time2.hour)
    {
        return time2;
    }
    else if (time1.hour < time2.hour)
    {
        return time1;
    }
    else // Jam sama, bandingkan menit
    {
        return (time1.minute > time2.minute) ? time2 : time1;
    }
}

/**
 * @brief Menentukan waktu yang lebih akhir dari dua waktu yang diberikan.
 * @param time1 Waktu pertama.
 * @param time2 Waktu kedua.
 * @return TimeRecord Waktu yang lebih akhir.
 * @note I.S. : time1 dan time2 terdefinisi.
 * @note F.S. : Mengembalikan TimeRecord yang lebih belakangan.
 */
TimeRecord getLaterTime(TimeRecord time1, TimeRecord time2)
{
    if (time1.hour > time2.hour)
    {
        return time1;
    }
    else if (time1.hour < time2.hour)
    {
        return time2;
    }
    else // Jam sama, bandingkan menit
    {
        return (time1.minute > time2.minute) ? time1 : time2;
    }
}

/**
 * @brief Memeriksa apakah sebuah rencana (pasangan waktu mulai-selesai) sudah ada dalam array rencana.
 * @details Pengecekan duplikat mempertimbangkan urutan waktu (mulai-selesai atau selesai-mulai).
 * @param existingPlansArray Array dari rencana yang sudah ada.
 * @param planCount Jumlah rencana dalam existingPlansArray.
 * @param planToCheck Rencana baru yang akan diperiksa duplikasinya.
 * @return int Mengembalikan 1 (true) jika rencana duplikat ditemukan, 0 (false) jika tidak.
 * @note I.S. : existingPlansArray, planCount, planToCheck terdefinisi.
 * @note F.S. : Mengembalikan status duplikasi.
 */
int isPlanDuplicate(StrategicPlan *existingPlansArray, int planCount, StrategicPlan planToCheck)
{
    for (int k = 0; k < planCount; k++)
    {
        // Cek apakah (mulai1 == mulai2 && selesai1 == selesai2)
        bool condition1 = existingPlansArray[k].startTime.hour == planToCheck.startTime.hour &&
                          existingPlansArray[k].startTime.minute == planToCheck.startTime.minute &&
                          existingPlansArray[k].endTime.hour == planToCheck.endTime.hour &&
                          existingPlansArray[k].endTime.minute == planToCheck.endTime.minute;
        // Cek apakah (mulai1 == selesai2 && selesai1 == mulai2) - untuk menangani urutan terbalik
        bool condition2 = existingPlansArray[k].startTime.hour == planToCheck.endTime.hour &&
                          existingPlansArray[k].startTime.minute == planToCheck.endTime.minute &&
                          existingPlansArray[k].endTime.hour == planToCheck.startTime.hour &&
                          existingPlansArray[k].endTime.minute == planToCheck.startTime.minute;

        if (condition1 || condition2)
        {
            return 1; // Ditemukan duplikat
        }
    }
    return 0; // Tidak ada duplikat
}

/**
 * @brief Mencetak daftar rencana strategis ke standar output.
 * @details Format output: `[[(HH:MM - HH:MM), D menit], ...]`
 * @param plansArray Array rencana strategis yang akan dicetak.
 * @param planCount Jumlah rencana dalam plansArray.
 * @note I.S. : plansArray dan planCount terdefinisi. plansArray berisi planCount rencana.
 * @note F.S. : Daftar rencana dicetak ke layar.
 */
void printStrategicPlans(StrategicPlan *plansArray, int planCount)
{
    printf("[");
    for (int i = 0; i < planCount; i++)
    {
        printf("[(%02d:%02d - %02d:%02d), %d menit]",
               plansArray[i].startTime.hour, plansArray[i].startTime.minute,
               plansArray[i].endTime.hour, plansArray[i].endTime.minute,
               plansArray[i].durationInMinutes);
        if (i < planCount - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * @brief Fungsi utama program.
 * @details Membaca N input waktu, mencari semua pasangan waktu yang durasinya
 *          palindrom, dan mencetak pasangan unik tersebut sebagai rencana strategis.
 * @return int Mengembalikan 0 jika program berjalan sukses, atau 1 jika ada error alokasi.
 */
int main(void)
{
    int numberOfTimeInputs; // Jumlah input waktu (N)
    scanf("%d", &numberOfTimeInputs);

    // Alokasi dinamis untuk array input waktu.
    TimeRecord *timeInputs = (TimeRecord *)malloc(numberOfTimeInputs * sizeof(TimeRecord));
    if (timeInputs == NULL)
    {
        // Penanganan error jika alokasi gagal.
        perror("Gagal alokasi memori untuk timeInputs");
        return 1;
    }

    // Membaca setiap input waktu dalam format HH:MM.
    for (int i = 0; i < numberOfTimeInputs; i++)
    {
        char timeInputString[6]; // Buffer untuk HH:MM + null terminator.
        scanf("%s", timeInputString);
        // Parsing string input ke integer untuk jam dan menit.
        timeInputs[i].hour = (timeInputString[0] - '0') * 10 + (timeInputString[1] - '0');
        timeInputs[i].minute = (timeInputString[3] - '0') * 10 + (timeInputString[4] - '0');
    }

    // Alokasi dinamis untuk array rencana strategis.
    // Jumlah maksimum pasangan unik adalah N * (N - 1) / 2.
    int maxPossiblePlans = numberOfTimeInputs * (numberOfTimeInputs - 1) / 2;
    if (numberOfTimeInputs < 2) maxPossiblePlans = 0; // Hindari nilai negatif jika N < 2

    StrategicPlan *strategicPlansArray = NULL;
    if (maxPossiblePlans > 0) { // Hanya alokasi jika ada kemungkinan rencana
        strategicPlansArray = (StrategicPlan *)malloc(maxPossiblePlans * sizeof(StrategicPlan));
        if (strategicPlansArray == NULL)
        {
            perror("Gagal alokasi memori untuk strategicPlansArray");
            free(timeInputs); // Bebaskan memori yang sudah dialokasi sebelumnya.
            return 1;
        }
    }


    int strategicPlanCount = 0; // Jumlah rencana strategis yang valid ditemukan.

    // Memproses semua pasangan waktu untuk menemukan rencana strategis.
    for (int i = 0; i < numberOfTimeInputs; i++)
    {
        for (int j = i + 1; j < numberOfTimeInputs; j++) // j = i + 1 untuk pasangan unik.
        {
            int durationMinutes = calculateDurationInMinutes(timeInputs[i], timeInputs[j]);

            // Lewati jika durasi 0 (waktu sama, tidak relevan untuk rencana).
            if (durationMinutes == 0)
            {
                continue;
            }

            int reversedDuration = reverseNumber(durationMinutes);

            // Cek apakah durasi adalah palindrom.
            if (durationMinutes == reversedDuration)
            {
                // Buat rencana baru dengan waktu mulai yang lebih awal.
                StrategicPlan newStrategicPlan = {
                    .startTime = getEarlierTime(timeInputs[i], timeInputs[j]),
                    .endTime = getLaterTime(timeInputs[i], timeInputs[j]),
                    .durationInMinutes = durationMinutes
                };

                // Periksa duplikasi sebelum menambahkan.
                if (strategicPlansArray != NULL && !isPlanDuplicate(strategicPlansArray, strategicPlanCount, newStrategicPlan))
                {
                    if (strategicPlanCount < maxPossiblePlans) { // Pastikan tidak overflow buffer
                        strategicPlansArray[strategicPlanCount++] = newStrategicPlan;
                    }
                } else if (maxPossiblePlans == 0 && strategicPlanCount == 0) {
                    // Kasus khusus jika N < 2, tidak ada rencana yang bisa dibuat.
                    // Jika ini adalah rencana pertama dan maxPossiblePlans adalah 0 (N<2), ini seharusnya tidak terjadi.
                    // Namun, jika N=2, maxPossiblePlans=1.
                    // Jika !strategicPlansArray (karena N<2), maka tidak bisa ditambahkan.
                    // Logika ini aman jika maxPossiblePlans=0, strategicPlansArray akan NULL.
                }
            }
        }
    }

    // Cetak hasil.
    if (strategicPlanCount > 0)
    {
        printStrategicPlans(strategicPlansArray, strategicPlanCount);
    }
    else
    {
        // Pesan jika tidak ada rencana strategis yang ditemukan.
        printf("Mungkin bukan hari ini. Jadi, Gro akan melamar Luiy pekan depan.\n");
    }

    // Bebaskan memori yang sudah dialokasikan secara dinamis.
    free(timeInputs);
    if (strategicPlansArray != NULL) // Hanya free jika dialokasikan
    {
        free(strategicPlansArray);
    }

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
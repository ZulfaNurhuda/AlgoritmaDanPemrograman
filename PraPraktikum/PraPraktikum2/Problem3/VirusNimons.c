/**
 * --------------------------------------------------------------
 * | @file VirusNimons.c                                        |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk mensimulasikan penyebaran Virus Nimons Gila. |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Mensimulasikan pertumbuhan virus selama periode waktu tertentu.
 *
 * Setiap virus akan mereplikasi sejumlah `factor` virus baru setiap jam.
 * Virus baru akan mulai mereplikasi di jam berikutnya. Jadi, hanya virus
 * yang baru terbentuk di jam sebelumnya yang akan mereplikasi di jam berikutnya.
 *
 * Contoh: Jika ada 2 virus awal dan factor = 3, maka:
 * - Jam 1: 2 virus → 2 × 3 = 6 virus baru → total = 8
 * - Jam 2: 6 virus → 6 × 3 = 18 virus baru → total = 26
 * - dst.
 *
 * @param initialCount Jumlah virus awal sebelum simulasi dimulai.
 * @param hours Jumlah jam yang akan disimulasikan.
 * @param factor Jumlah virus baru yang dihasilkan oleh satu virus setiap jam.
 * @return Total jumlah virus setelah simulasi selama `hours` jam.
 */
long long simulateVirusGrowth(int initialCount, int hours, int factor)
{
    // Menyimpan total virus yang ada saat ini
    long long totalVirusCount = initialCount;

    // Menyimpan jumlah virus yang aktif dan akan mereplikasi di jam berikutnya
    long long activeReplicators = initialCount;

    // Melakukan simulasi selama 'hours' jam
    for (int i = 0; i < hours; i++)
    {
        // Hitung berapa banyak virus baru yang akan dibuat dari virus aktif saat ini
        long long newlyCreatedViruses = activeReplicators * factor;

        // Tambahkan virus baru ke total keseluruhan
        totalVirusCount += newlyCreatedViruses;

        // Virus baru ini akan menjadi virus aktif di iterasi/jam berikutnya
        activeReplicators = newlyCreatedViruses;
    }

    // Mengembalikan total virus yang ada setelah simulasi selesai
    return totalVirusCount;
}

int main(void)
{
    // Mendeklarasikan variabel untuk input
    int initialVirusCount;
    int simulationHours;
    int replicationFactor;

    // Membaca semua input
    scanf("%d", &initialVirusCount);
    scanf("%d", &simulationHours);
    scanf("%d", &replicationFactor);

    // Memanggil fungsi pembantu untuk mendapatkan hasil simulasi
    long long finalVirusCount = simulateVirusGrowth(initialVirusCount, simulationHours, replicationFactor);

    // Mencetak output sesuai format yang diminta
    printf("Terdapat %lld Virus Nimons Gila pada jam ke-%d\n", finalVirusCount, simulationHours);

    return 0;
}
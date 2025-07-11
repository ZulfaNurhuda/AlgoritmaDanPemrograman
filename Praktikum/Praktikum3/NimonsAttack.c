/**
 * --------------------------------------------------------------
 * | @file NimonsAttack.c                                       |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi fungsi-fungsi untuk simulasi serangan Nimons. |
 * | Ini melibatkan perhitungan jarak, validasi posisi kapal,   |
 * | pengurutan kapal berdasarkan jarak, dan penentuan kapal    |
 * | mana yang berada dalam radius serang.                      |
 * --------------------------------------------------------------
 */

#include "NimonsAttack.h" // Asumsi header ini mendefinisikan struct Koordinat, Kapal, dan konstanta/tipe boolean
#include <math.h>       // Untuk sqrt dan pow
#include <stdio.h>      // Untuk printf dan scanf
#include <string.h>     // Untuk strcmp

/**
 * @brief Menghitung jarak Euclidean antara sebuah kapal dan sebuah pulau.
 * @param ship Kapal yang posisinya akan digunakan.
 * @param islandCoordinate Koordinat pulau tujuan.
 * @return float Jarak antara kapal dan pulau.
 * @note I.S. : ship dan islandCoordinate terdefinisi.
 * @note F.S. : Mengembalikan jarak Euclidean.
 */
float calculateDistanceToIsland(Kapal ship, Koordinat islandCoordinate)
{
    // Rumus jarak: sqrt((x2-x1)^2 + (y2-y1)^2)
    return sqrt(pow(ship.posisi.x - islandCoordinate.x, 2) + pow(ship.posisi.y - islandCoordinate.y, 2));
}

/**
 * @brief Menghitung jarak Euclidean antara dua kapal.
 * @param ship1 Kapal pertama.
 * @param ship2 Kapal kedua.
 * @return float Jarak antara kedua kapal.
 * @note I.S. : ship1 dan ship2 terdefinisi.
 * @note F.S. : Mengembalikan jarak Euclidean.
 */
float calculateDistanceBetweenShips(Kapal ship1, Kapal ship2)
{
    return sqrt(pow(ship1.posisi.x - ship2.posisi.x, 2) + pow(ship1.posisi.y - ship2.posisi.y, 2));
}

/**
 * @brief Memeriksa apakah penempatan kapal baru valid.
 * @details Sebuah kapal dianggap valid jika:
 *          1. Tidak berada pada koordinat yang sama dengan kapal lain yang sudah ada.
 *          2. Tidak memiliki kode yang sama dengan kapal lain yang sudah ada.
 *          3. Tidak berada pada koordinat yang sama dengan pulau.
 * @param newShip Kapal baru yang akan divalidasi.
 * @param islandCoordinate Koordinat pulau.
 * @param existingShips Array kapal yang sudah ada.
 * @param numberOfExistingShips Jumlah kapal dalam array existingShips.
 * @return boolean TRUE jika valid, FALSE jika tidak valid (dan mencetak pesan error).
 * @note I.S. : newShip, islandCoordinate, existingShips, numberOfExistingShips terdefinisi.
 * @note F.S. : Mengembalikan status validitas. Pesan error dicetak jika tidak valid.
 */
boolean isShipPlacementValid(Kapal newShip, Koordinat islandCoordinate, Kapal *existingShips, int numberOfExistingShips)
{
    // Cek tabrakan dengan kapal lain atau duplikasi kode.
    for (int i = 0; i < numberOfExistingShips; i++)
    {
        // Cek jika posisi sama
        if (newShip.posisi.x == existingShips[i].posisi.x && newShip.posisi.y == existingShips[i].posisi.y)
        {
            printf("%s nabrak kapal lain dong!\n", newShip.kode);
            return FALSE;
        }
        // Cek jika kode sama
        if (strcmp(newShip.kode, existingShips[i].kode) == 0)
        {
            printf("%s kok ada dua!\n", newShip.kode);
            return FALSE;
        }
    }
    // Cek tabrakan dengan pulau.
    if (newShip.posisi.x == islandCoordinate.x && newShip.posisi.y == islandCoordinate.y)
    {
        printf("%s nabrak pulau dong!\n", newShip.kode);
        return FALSE;
    }
    return TRUE;
}

/**
 * @brief Mengurutkan array kapal berdasarkan jarak terdekat ke pulau (ascending).
 * @details Menggunakan algoritma bubble sort sederhana.
 * @param shipList Array kapal yang akan diurutkan (in-place).
 * @param islandCoordinate Koordinat pulau sebagai referensi jarak.
 * @param shipCount Jumlah kapal dalam shipList.
 * @note I.S. : shipList, islandCoordinate, shipCount terdefinisi.
 * @note F.S. : shipList terurut berdasarkan jarak ke islandCoordinate.
 */
void sortShipsByDistanceToIsland(Kapal *shipList, Koordinat islandCoordinate, int shipCount)
{
    for (int i = 0; i < shipCount - 1; i++)
    {
        for (int j = i + 1; j < shipCount; j++)
        {
            // Jika jarak kapal ke-i lebih besar dari jarak kapal ke-j, tukar posisi.
            if (calculateDistanceToIsland(shipList[i], islandCoordinate) > calculateDistanceToIsland(shipList[j], islandCoordinate))
            {
                Kapal tempShip = shipList[i];
                shipList[i] = shipList[j];
                shipList[j] = tempShip;
            }
        }
    }
}

/**
 * @brief Fungsi utama untuk simulasi serangan Nimons.
 * @details Membaca input jumlah kapal, radius serang, koordinat pulau, dan data setiap kapal.
 *          Memvalidasi penempatan kapal, mengurutkannya berdasarkan jarak ke pulau,
 *          dan melaporkan kapal mana saja yang berada dalam radius serang.
 * @note I.S. : Input pengguna sesuai format yang diharapkan.
 * @note F.S. : Mencetak kapal-kapal yang valid dan berada dalam radius serang,
 *              atau pesan bahwa perdamaian telah usai jika ada kapal di luar radius.
 */
void findAndReportNearbyShips(void) // Menggunakan void karena tidak ada argumen
{
    int numberOfShipsToInput; // Jumlah kapal yang akan diinput
    int attackRadius;         // Radius serang dari pulau

    // Membaca jumlah kapal dan radius serang.
    scanf("%d %d", &numberOfShipsToInput, &attackRadius);

    // Membaca koordinat pulau.
    Koordinat islandLocation;
    scanf("%d %d", &islandLocation.x, &islandLocation.y);

    // Array untuk menyimpan data kapal. Ukuran ditentukan saat runtime (VLA).
    // Perhatian: VLA adalah fitur C99 dan mungkin tidak didukung semua compiler C89.
    // Untuk portabilitas maksimal, alokasi dinamis atau ukuran tetap MAX_KAPAL bisa digunakan.
    Kapal shipList[numberOfShipsToInput];
    int currentShipCount = 0; // Jumlah kapal valid yang sudah dimasukkan

    // Loop untuk membaca data setiap kapal dan memvalidasinya.
    while (currentShipCount < numberOfShipsToInput)
    {
        Kapal currentShipInput;
        // Membaca posisi (x, y) dan kode kapal.
        scanf("%d %d %s", &currentShipInput.posisi.x, &currentShipInput.posisi.y, currentShipInput.kode);

        // Validasi penempatan kapal baru.
        if (isShipPlacementValid(currentShipInput, islandLocation, shipList, currentShipCount))
        {
            shipList[currentShipCount] = currentShipInput; // Tambahkan kapal valid ke list
            currentShipCount++; // Increment jumlah kapal valid
        }
        // Jika tidak valid, pesan error sudah dicetak oleh isShipPlacementValid,
        // dan loop akan meminta input untuk kapal yang sama (atau kapal berikutnya jika N dikurangi).
        // Namun, logika asli increment `i` hanya jika valid, jadi kita ikuti itu.
    }

    // Urutkan kapal berdasarkan jarak terdekat ke pulau.
    sortShipsByDistanceToIsland(shipList, islandLocation, numberOfShipsToInput);

    // Laporkan kapal yang berada dalam radius serang.
    // Loop melalui kapal yang sudah diurutkan.
    for (int i = 0; i < numberOfShipsToInput; i++)
    {
        Kapal currentTargetShip = shipList[i];
        // Cek apakah kapal saat ini berada dalam radius serang.
        if (calculateDistanceToIsland(currentTargetShip, islandLocation) <= attackRadius)
        {
            // Cetak informasi kapal jika dalam radius.
            printf("%d - %s (%d,%d)\n", i + 1, currentTargetShip.kode, currentTargetShip.posisi.x, currentTargetShip.posisi.y);
        }
        else
        {
            // Jika kapal terdekat berikutnya sudah di luar radius, maka tidak ada kapal lain yang perlu dicek.
            printf("Perdamaian di pulau Mackenbruh telah usai :(\n");
            break; // Hentikan loop.
        }
    }
}
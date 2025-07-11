/**
 * --------------------------------------------------------------
 * | @file NimonsBalap.c                                        |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Kendaraan (Vehicle) untuk simulasi balap  |
 * | Nimons. Termasuk fungsi untuk membuat, mengakses,          |
 * | memodifikasi, dan menganalisis properti kendaraan.         |
 * --------------------------------------------------------------
 */

#include "NimonsBalap.h" // Header file yang mendefinisikan struct Vehicle, Dimensions, dll.
#include <stdio.h>      // Untuk printf, scanf
#include <stdlib.h>     // Untuk malloc, free
#include <string.h>     // Untuk strcpy
#include <math.h>       // Tidak ada penggunaan math.h yang terlihat di sini, bisa dihapus jika tidak ada di header.

// Asumsi dari header (akan distandarisasi di file .h nanti):
// typedef struct { int panjang; int lebar; int tinggi; } Dimensions;
// typedef struct { Koordinat posisi; char kode[4]; int jumlahKursi; ... Dimensions dim; ...} Vehicle;

/**
 * @brief Mendapatkan kode identifikasi kendaraan.
 * @details Fungsi ini mengalokasikan memori baru untuk string kode dan menyalin
 *          kode kendaraan ke dalamnya. Pemanggil bertanggung jawab untuk membebaskan
 *          memori yang dikembalikan menggunakan `free()`.
 * @param vehicle Kendaraan yang kodenya akan diambil.
 * @return char* Pointer ke string kode yang baru dialokasikan, atau NULL jika alokasi gagal.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Mengembalikan salinan string kode kendaraan. Memori dialokasikan.
 */
char *getVehicleCode(Vehicle vehicle)
{
    // Alokasi memori seukuran field kode di struct Vehicle.
    // sizeof(vehicle.kode) sudah benar karena vehicle.kode adalah array char.
    char *code = (char *)malloc(sizeof(vehicle.kode));
    if (code != NULL)
    {
        strcpy(code, vehicle.kode);
    }
    return code;
}

/**
 * @brief Mengatur kode identifikasi kendaraan.
 * @param vehicle Pointer ke kendaraan yang kodenya akan diatur.
 * @param newCode String kode baru yang akan disalin ke kendaraan.
 *                Diasumsikan panjang newCode tidak melebihi kapasitas field kode.
 * @note I.S. : `vehicle` adalah pointer valid, `newCode` terdefinisi.
 * @note F.S. : `vehicle->kode` diisi dengan `newCode`.
 */
void setVehicleCode(Vehicle *vehicle, const char *newCode) // Menggunakan const char* untuk input string
{
    // Menggunakan strcpy untuk menyalin string. Pastikan vehicle->kode memiliki cukup ruang.
    // Jika vehicle.kode adalah char[4], maka newCode maksimal 3 karakter + null terminator.
    strcpy(vehicle->kode, newCode);
}

/**
 * @brief Mendapatkan jumlah kursi kendaraan.
 * @param vehicle Kendaraan yang akan diperiksa.
 * @return int Jumlah kursi.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Mengembalikan nilai `vehicle.seatCount`.
 */
int getVehicleSeatCount(Vehicle vehicle)
{
    return vehicle.seatCount;
}

/**
 * @brief Mengatur jumlah kursi kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param seatCount Jumlah kursi baru.
 * @note I.S. : `vehicle` adalah pointer valid, `seatCount` terdefinisi.
 * @note F.S. : `vehicle->seatCount` diatur ke `seatCount`.
 */
void setVehicleSeatCount(Vehicle *vehicle, int seatCount)
{
    vehicle->seatCount = seatCount;
}

/**
 * @brief Mendapatkan jumlah roda kendaraan.
 * @param vehicle Kendaraan yang akan diperiksa.
 * @return int Jumlah roda.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Mengembalikan nilai `vehicle.wheelCount`.
 */
int getVehicleWheelCount(Vehicle vehicle)
{
    return vehicle.wheelCount;
}

/**
 * @brief Mengatur jumlah roda kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param wheelCount Jumlah roda baru.
 * @note I.S. : `vehicle` adalah pointer valid, `wheelCount` terdefinisi.
 * @note F.S. : `vehicle->wheelCount` diatur ke `wheelCount`.
 */
void setVehicleWheelCount(Vehicle *vehicle, int wheelCount)
{
    vehicle->wheelCount = wheelCount;
}

/**
 * @brief Mendapatkan kecepatan maksimum kendaraan.
 * @param vehicle Kendaraan yang akan diperiksa.
 * @return int Kecepatan maksimum.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Mengembalikan nilai `vehicle.speed`.
 */
int getVehicleSpeed(Vehicle vehicle)
{
    return vehicle.speed;
}

/**
 * @brief Mengatur kecepatan maksimum kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param speed Kecepatan maksimum baru.
 * @note I.S. : `vehicle` adalah pointer valid, `speed` terdefinisi.
 * @note F.S. : `vehicle->speed` diatur ke `speed`.
 */
void setVehicleSpeed(Vehicle *vehicle, int speed)
{
    vehicle->speed = speed;
}

/**
 * @brief Mendapatkan panjang dimensi kendaraan.
 * @param vehicle Kendaraan yang akan diperiksa.
 * @return int Panjang dimensi.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Mengembalikan nilai `vehicle.dimensions.length`.
 */
int getVehicleLength(Vehicle vehicle)
{
    return vehicle.dimensions.length;
}

/**
 * @brief Mengatur panjang dimensi kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param length Panjang dimensi baru.
 * @note I.S. : `vehicle` adalah pointer valid, `length` terdefinisi.
 * @note F.S. : `vehicle->dimensions.length` diatur ke `length`.
 */
void setVehicleLength(Vehicle *vehicle, int length)
{
    vehicle->dimensions.length = length;
}

/**
 * @brief Mendapatkan lebar dimensi kendaraan.
 * @param vehicle Kendaraan yang akan diperiksa.
 * @return int Lebar dimensi.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Mengembalikan nilai `vehicle.dimensions.width`.
 */
int getVehicleWidth(Vehicle vehicle)
{
    return vehicle.dimensions.width;
}

/**
 * @brief Mengatur lebar dimensi kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param width Lebar dimensi baru.
 * @note I.S. : `vehicle` adalah pointer valid, `width` terdefinisi.
 * @note F.S. : `vehicle->dimensions.width` diatur ke `width`.
 */
void setVehicleWidth(Vehicle *vehicle, int width)
{
    vehicle->dimensions.width = width;
}

/**
 * @brief Mendapatkan tinggi dimensi kendaraan.
 * @param vehicle Kendaraan yang akan diperiksa.
 * @return int Tinggi dimensi.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Mengembalikan nilai `vehicle.dimensions.height`.
 */
int getVehicleHeight(Vehicle vehicle)
{
    return vehicle.dimensions.height;
}

/**
 * @brief Mengatur tinggi dimensi kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param height Tinggi dimensi baru.
 * @note I.S. : `vehicle` adalah pointer valid, `height` terdefinisi.
 * @note F.S. : `vehicle->dimensions.height` diatur ke `height`.
 */
void setVehicleHeight(Vehicle *vehicle, int height)
{
    vehicle->dimensions.height = height;
}

/**
 * @brief Mendapatkan berat kendaraan.
 * @param vehicle Kendaraan yang akan diperiksa.
 * @return int Berat kendaraan.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Mengembalikan nilai `vehicle.weight`.
 */
int getVehicleWeight(Vehicle vehicle)
{
    return vehicle.weight;
}

/**
 * @brief Mengatur berat kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param weight Berat kendaraan baru.
 * @note I.S. : `vehicle` adalah pointer valid, `weight` terdefinisi.
 * @note F.S. : `vehicle->weight` diatur ke `weight`.
 */
void setVehicleWeight(Vehicle *vehicle, int weight)
{
    vehicle->weight = weight;
}

/**
 * @brief Mendapatkan harga jual kendaraan.
 * @param vehicle Kendaraan yang akan diperiksa.
 * @return int Harga jual kendaraan.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Mengembalikan nilai `vehicle.sellingPrice`.
 */
int getVehicleSellingPrice(Vehicle vehicle)
{
    return vehicle.sellingPrice;
}

/**
 * @brief Mengatur harga jual kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param sellingPrice Harga jual baru.
 * @note I.S. : `vehicle` adalah pointer valid, `sellingPrice` terdefinisi.
 * @note F.S. : `vehicle->sellingPrice` diatur ke `sellingPrice`.
 */
void setVehicleSellingPrice(Vehicle *vehicle, int sellingPrice)
{
    vehicle->sellingPrice = sellingPrice;
}

/**
 * @brief Membuat dan menginisialisasi sebuah objek kendaraan baru.
 * @param code Kode identifikasi untuk kendaraan (string, maksimal 3 karakter).
 * @param seatCount Jumlah kursi.
 * @param wheelCount Jumlah roda.
 * @param speed Kecepatan maksimum.
 * @param dims Dimensi kendaraan (struct Dimensions).
 * @param weight Berat kendaraan.
 * @param sellingPrice Harga jual kendaraan.
 * @return Vehicle Objek kendaraan yang telah diinisialisasi.
 * @note I.S. : Semua parameter input terdefinisi.
 * @note F.S. : Mengembalikan struct Vehicle yang terisi.
 */
Vehicle createVehicle(const char *code, int seatCount, int wheelCount, int speed, Dimensions dims, int weight, int sellingPrice)
{
    Vehicle newVehicle;
    setVehicleCode(&newVehicle, code);
    setVehicleSeatCount(&newVehicle, seatCount);
    setVehicleWheelCount(&newVehicle, wheelCount);
    setVehicleSpeed(&newVehicle, speed);
    setVehicleLength(&newVehicle, dims.length);
    setVehicleWidth(&newVehicle, dims.width);
    setVehicleHeight(&newVehicle, dims.height);
    setVehicleWeight(&newVehicle, weight);
    setVehicleSellingPrice(&newVehicle, sellingPrice);
    return newVehicle;
}

/**
 * @brief Menginisialisasi sebuah kendaraan dengan nilai default.
 * @param vehicle Pointer ke kendaraan yang akan diinisialisasi dengan nilai default.
 * @note I.S. : `vehicle` adalah pointer valid.
 * @note F.S. : `vehicle` diisi dengan nilai-nilai default.
 */
void createDefaultVehicle(Vehicle *vehicle)
{
    // Definisi nilai default.
    char defaultCode[4] = "XXX"; // Pastikan ukuran buffer cukup untuk null terminator
    int defaultSeatCount = 4;
    int defaultWheelCount = 4;
    int defaultSpeed = 10;
    int defaultLength = 10;
    int defaultWidth = 10;
    int defaultHeight = 10;
    int defaultWeight = 100;
    int defaultSellingPrice = 100000;

    Dimensions defaultDimensions;
    defaultDimensions.length = defaultLength;
    defaultDimensions.width = defaultWidth;
    defaultDimensions.height = defaultHeight;

    // Membuat kendaraan dengan nilai default.
    *vehicle = createVehicle(defaultCode, defaultSeatCount, defaultWheelCount, defaultSpeed, defaultDimensions, defaultWeight, defaultSellingPrice);
}

/**
 * @brief Membuat dan menginisialisasi sebuah kendaraan berdasarkan input dari pengguna.
 * @param vehicle Pointer ke kendaraan yang akan diisi dengan data input.
 * @note I.S. : `vehicle` adalah pointer valid. Pengguna akan memasukkan data.
 * @note F.S. : `vehicle` diisi dengan data yang diinput oleh pengguna.
 *              Format input: kode seatCount wheelCount speed length width height weight sellingPrice
 */
void createVehicleFromInput(Vehicle *vehicle)
{
    char inputCode[4]; // Buffer untuk kode, pastikan cukup untuk 3 char + null.
    int seatCount, wheelCount, speed, length, width, height, weight, sellingPrice;

    // Membaca semua data input dari pengguna.
    scanf("%s %d %d %d %d %d %d %d %d",
          inputCode, &seatCount, &wheelCount, &speed,
          &length, &width, &height, &weight, &sellingPrice);

    Dimensions inputDimensions;
    inputDimensions.length = length;
    inputDimensions.width = width;
    inputDimensions.height = height;

    // Membuat kendaraan dengan data input.
    *vehicle = createVehicle(inputCode, seatCount, wheelCount, speed, inputDimensions, weight, sellingPrice);
}

/**
 * @brief Mencetak detail lengkap sebuah kendaraan ke standar output.
 * @details Format: kode kursi roda kecepatan panjang lebar tinggi berat harga_jual
 * @param vehicle Kendaraan yang detailnya akan dicetak.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Detail kendaraan dicetak. Memori untuk kode yang diambil dengan `getVehicleCode` dibebaskan.
 */
void printVehicleDetails(Vehicle vehicle)
{
    // Mendapatkan salinan kode untuk dicetak (dan kemudian dibebaskan).
    char *vehicleCode = getVehicleCode(vehicle);
    if (vehicleCode != NULL)
    {
        printf("%s %d %d %d %d %d %d %d %d\n",
               vehicleCode,
               getVehicleSeatCount(vehicle),
               getVehicleWheelCount(vehicle),
               getVehicleSpeed(vehicle),
               getVehicleLength(vehicle),
               getVehicleWidth(vehicle),
               getVehicleHeight(vehicle),
               getVehicleWeight(vehicle),
               getVehicleSellingPrice(vehicle));
        free(vehicleCode); // Penting untuk membebaskan memori yang dialokasikan oleh getVehicleCode.
    }
    else
    {
        // Penanganan jika alokasi kode gagal.
        printf("Error: Gagal mendapatkan kode kendaraan untuk pencetakan.\n");
    }
}

/**
 * @brief Mencetak jenis kendaraan berdasarkan jumlah rodanya.
 * @param vehicle Kendaraan yang akan diklasifikasikan.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Jenis kendaraan (NimoRide, NimoCar, NimoTruck, NimoTanker) dicetak.
 */
void printVehicleTypeByWheels(Vehicle vehicle)
{
    int wheelCount = getVehicleWheelCount(vehicle);
    if (wheelCount <= 2)
    {
        printf("NimoRide\n");
    }
    else if (wheelCount > 2 && wheelCount <= 4)
    {
        printf("NimoCar\n");
    }
    else if (wheelCount > 4 && wheelCount <= 6)
    {
        printf("NimoTruck\n");
    }
    else // Lebih dari 6 roda
    {
        printf("NimoTanker\n");
    }
}

/**
 * @brief Mencetak jenis kendaraan berdasarkan kecepatannya.
 * @param vehicle Kendaraan yang akan diklasifikasikan.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Jenis kendaraan (NimoSlow, NimoFast, NimoSuperFast, NimoSpeedy) dicetak.
 */
void printVehicleTypeBySpeed(Vehicle vehicle)
{
    int currentSpeed = getVehicleSpeed(vehicle);
    if (currentSpeed <= 10)
    {
        printf("NimoSlow\n");
    }
    else if (currentSpeed > 10 && currentSpeed <= 20)
    {
        printf("NimoFast\n");
    }
    else if (currentSpeed > 20 && currentSpeed <= 30)
    {
        printf("NimoSuperFast\n");
    }
    else // Lebih dari 30
    {
        printf("NimoSpeedy\n");
    }
}

/**
 * @brief Mencetak jenis kendaraan berdasarkan beratnya.
 * @param vehicle Kendaraan yang akan diklasifikasikan.
 * @note I.S. : `vehicle` terdefinisi.
 * @note F.S. : Jenis kendaraan (NimoLight, NimoMedium, NimoHeavy, NimoSuperHeavy) dicetak.
 */
void printVehicleTypeByWeight(Vehicle vehicle)
{
    int currentWeight = getVehicleWeight(vehicle);
    if (currentWeight <= 100)
    {
        printf("NimoLight\n");
    }
    else if (currentWeight > 100 && currentWeight <= 200)
    {
        printf("NimoMedium\n");
    }
    else if (currentWeight > 200 && currentWeight <= 300)
    {
        printf("NimoHeavy\n");
    }
    else // Lebih dari 300
    {
        printf("NimoSuperHeavy\n");
    }
}

/**
 * @brief Menghitung dan melaporkan profitabilitas perakitan kendaraan dibandingkan harga jualnya.
 * @details Fungsi ini menghitung total biaya perakitan berdasarkan komponen
 *          (roda, kursi, dimensi, berat) dan membandingkannya dengan harga jual.
 * @param targetVehicle Pointer ke kendaraan yang akan dievaluasi.
 * @note I.S. : `targetVehicle` adalah pointer valid ke Vehicle yang terdefinisi.
 * @note F.S. : Mencetak status profitabilitas (Rugi, Kaya, Pas).
 *              Memori untuk kode yang diambil dengan `getVehicleCode` dibebaskan.
 */
void checkAssemblyProfitability(Vehicle *targetVehicle) // Mengubah nama agar lebih jelas tujuannya
{
    // Menghitung biaya komponen.
    int wheelCost = targetVehicle->wheelCount * 1000;
    int seatCost = targetVehicle->seatCount * 10000;
    int dimensionCost = targetVehicle->dimensions.length * 100 + targetVehicle->dimensions.width * 100 + targetVehicle->dimensions.height * 100;
    int weightCost = targetVehicle->weight * 100;

    // Total biaya perakitan.
    int totalAssemblyCost = wheelCost + seatCost + dimensionCost + weightCost;

    // Mendapatkan kode kendaraan untuk pesan output.
    char *vehicleCode = getVehicleCode(*targetVehicle);
    if (vehicleCode == NULL) {
        printf("Error: Gagal mendapatkan kode kendaraan untuk laporan profitabilitas.\n");
        return;
    }

    // Membandingkan biaya perakitan dengan harga jual.
    if (totalAssemblyCost > targetVehicle->sellingPrice)
    {
        printf("Nimons Rugi! Harga rakit mobil %s lebih mahal dari harga jual\n", vehicleCode);
    }
    else if (totalAssemblyCost < targetVehicle->sellingPrice)
    {
        printf("Nimons Kaya hehe! Harga rakit mobil %s lebih murah dari harga jual\n", vehicleCode);
    }
    else
    {
        printf("Nimons Pas! Harga rakit mobil %s sama dengan harga jual\n", vehicleCode);
    }

    free(vehicleCode); // Bebaskan memori setelah digunakan.
}

/**
 * @brief Mengevaluasi dan melaporkan profitabilitas penjualan kendaraan.
 * @details Fungsi ini identik dengan `checkAssemblyProfitability` dalam implementasi asli.
 *          Menghitung total biaya komponen dan membandingkan dengan harga jual.
 * @param vehicle Pointer ke kendaraan yang akan dievaluasi.
 * @note I.S. : `vehicle` adalah pointer valid ke Vehicle yang terdefinisi.
 * @note F.S. : Mencetak status profitabilitas (Rugi, Kaya, Pas).
 *              Memori untuk kode yang diambil dengan `getVehicleCode` dibebaskan.
 * @deprecated Fungsi ini tampaknya duplikat dari `checkAssemblyProfitability`. Pertimbangkan untuk menggabungkan.
 */
void evaluateSaleProfitability(Vehicle *vehicle)
{
    // Menggunakan getter untuk konsistensi, meskipun akses langsung field juga bisa.
    int wheelCost = getVehicleWheelCount(*vehicle) * 1000;
    int seatCost = getVehicleSeatCount(*vehicle) * 10000;
    int lengthCost = getVehicleLength(*vehicle) * 100;
    int widthCost = getVehicleWidth(*vehicle) * 100;
    int heightCost = getVehicleHeight(*vehicle) * 100;
    int weightCost = getVehicleWeight(*vehicle) * 100;

    int totalComponentCost = wheelCost + seatCost + lengthCost + widthCost + heightCost + weightCost;

    char *vehicleCode = getVehicleCode(*vehicle);
    if (vehicleCode == NULL) {
        printf("Error: Gagal mendapatkan kode kendaraan untuk evaluasi penjualan.\n");
        return;
    }

    if (totalComponentCost > getVehicleSellingPrice(*vehicle))
    {
        printf("Nimons Rugi! Harga rakit mobil %s lebih mahal dari harga jual\n", vehicleCode);
    }
    else if (totalComponentCost < getVehicleSellingPrice(*vehicle))
    {
        printf("Nimons Kaya hehe! Harga rakit mobil %s lebih murah dari harga jual\n", vehicleCode);
    }
    else
    {
        printf("Nimons Pas! Harga rakit mobil %s sama dengan harga jual\n", vehicleCode);
    }

    free(vehicleCode);
}

/**
 * @brief Mensimulasikan balapan antara dua kendaraan dan menentukan pemenangnya.
 * @details Skor dihitung berdasarkan: kecepatan * 10 - berat * 2 - lebar.
 * @param vehicle1 Pointer ke kendaraan pertama.
 * @param vehicle2 Pointer ke kendaraan kedua.
 * @note I.S. : `vehicle1` dan `vehicle2` adalah pointer valid ke Vehicle yang terdefinisi.
 * @note F.S. : Mencetak hasil balapan (seri atau pemenang beserta skornya).
 *              Memori untuk kode yang diambil dengan `getVehicleCode` dibebaskan.
 */
void raceVehicles(Vehicle *vehicle1, Vehicle *vehicle2)
{
    // Menghitung skor untuk kendaraan pertama.
    int score1 = getVehicleSpeed(*vehicle1) * 10 - getVehicleWeight(*vehicle1) * 2 - getVehicleWidth(*vehicle1);
    // Menghitung skor untuk kendaraan kedua.
    int score2 = getVehicleSpeed(*vehicle2) * 10 - getVehicleWeight(*vehicle2) * 2 - getVehicleWidth(*vehicle2);

    // Mendapatkan kode kendaraan untuk pesan output.
    char *code1 = getVehicleCode(*vehicle1);
    char *code2 = getVehicleCode(*vehicle2);

    if (code1 == NULL || code2 == NULL) {
        printf("Error: Gagal mendapatkan kode kendaraan untuk balapan.\n");
        if (code1) free(code1);
        if (code2) free(code2);
        return;
    }

    // Menentukan dan mencetak hasil balapan.
    if (score1 == score2)
    {
        printf("Nimons Balap! Kedua kendaraan %s dan %s seri! dengan skor %d\n", code1, code2, score1);
    }
    else if (score1 > score2)
    {
        printf("Nimons Balap! Kendaraan %s menang! dengan skor %d\n", code1, score1);
    }
    else // score2 > score1
    {
        printf("Nimons Balap! Kendaraan %s menang! dengan skor %d\n", code2, score2);
    }

    // Bebaskan memori kode setelah digunakan.
    free(code1);
    free(code2);
}

/**
 * --------------------------------------------------------------
 * | @file NimonsBalap.h                                        |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Header file untuk ADT Kendaraan (Vehicle) dan Dimensi.     |
 * | Mendefinisikan struktur data dan prototipe fungsi untuk    |
 * | simulasi balap Nimons.                                     |
 * --------------------------------------------------------------
 */

#ifndef NIMONS_BALAP_H // Mengganti guard agar konsisten
#define NIMONS_BALAP_H

// Include standar library yang mungkin dibutuhkan oleh deklarasi di bawah ini
// atau oleh pengguna header ini. Umumnya, stdio.h, stdlib.h, string.h
// lebih sering di-include di file .c kecuali tipe data dari library tersebut
// (seperti FILE*) digunakan dalam deklarasi di header.
// Untuk saat ini, kita kosongkan include library standar dari header ini,
// dan pastikan ada di .c jika diperlukan.

/* ***************************************************** */
/* ********************** TIPE DATA ******************** */
/* ***************************************************** */

/**
 * @struct Dimensions
 * @brief Merepresentasikan dimensi fisik sebuah objek (panjang, lebar, tinggi).
 */
typedef struct Dimensions // Memberi nama pada struct
{
    int length; /**< Panjang objek. */
    int width;  /**< Lebar objek. */
    int height; /**< Tinggi objek. */
} Dimensions;

/**
 * @struct Vehicle
 * @brief Merepresentasikan sebuah kendaraan dengan berbagai atribut.
 */
typedef struct Vehicle // Memberi nama pada struct
{
    char kode[4];          /**< Kode unik kendaraan (maks 3 char + null terminator). */
    int seatCount;         /**< Jumlah kursi penumpang. */
    int wheelCount;        /**< Jumlah roda kendaraan. */
    int speed;             /**< Kecepatan maksimum kendaraan. */
    Dimensions dimensions; /**< Dimensi fisik kendaraan (panjang, lebar, tinggi). */
    int weight;            /**< Berat kendaraan. */
    int sellingPrice;      /**< Harga jual kendaraan. */
} Vehicle;

/* ***************************************************** */
/* ************ GETTER & SETTER KENDARAAN ************** */
/* ***************************************************** */

// --- Kode ---
/**
 * @brief Mendapatkan salinan kode identifikasi kendaraan.
 * @param vehicle Kendaraan sumber.
 * @return char* Pointer ke string kode yang baru dialokasikan.
 *               Pemanggil bertanggung jawab membebaskan memori ini.
 */
char *getVehicleCode(Vehicle vehicle);
/**
 * @brief Mengatur kode identifikasi kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param newCode Kode baru (string).
 */
void setVehicleCode(Vehicle *vehicle, const char *newCode);

// --- Jumlah Kursi ---
/**
 * @brief Mendapatkan jumlah kursi kendaraan.
 * @param vehicle Kendaraan sumber.
 * @return int Jumlah kursi.
 */
int getVehicleSeatCount(Vehicle vehicle);
/**
 * @brief Mengatur jumlah kursi kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param seatCount Jumlah kursi baru.
 */
void setVehicleSeatCount(Vehicle *vehicle, int seatCount);

// --- Jumlah Roda ---
/**
 * @brief Mendapatkan jumlah roda kendaraan.
 * @param vehicle Kendaraan sumber.
 * @return int Jumlah roda.
 */
int getVehicleWheelCount(Vehicle vehicle);
/**
 * @brief Mengatur jumlah roda kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param wheelCount Jumlah roda baru.
 */
void setVehicleWheelCount(Vehicle *vehicle, int wheelCount);

// --- Kecepatan ---
/**
 * @brief Mendapatkan kecepatan maksimum kendaraan.
 * @param vehicle Kendaraan sumber.
 * @return int Kecepatan.
 */
int getVehicleSpeed(Vehicle vehicle);
/**
 * @brief Mengatur kecepatan maksimum kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param speed Kecepatan baru.
 */
void setVehicleSpeed(Vehicle *vehicle, int speed);

// --- Dimensi: Panjang ---
/**
 * @brief Mendapatkan panjang dimensi kendaraan.
 * @param vehicle Kendaraan sumber.
 * @return int Panjang.
 */
int getVehicleLength(Vehicle vehicle);
/**
 * @brief Mengatur panjang dimensi kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param length Panjang baru.
 */
void setVehicleLength(Vehicle *vehicle, int length);

// --- Dimensi: Lebar ---
/**
 * @brief Mendapatkan lebar dimensi kendaraan.
 * @param vehicle Kendaraan sumber.
 * @return int Lebar.
 */
int getVehicleWidth(Vehicle vehicle);
/**
 * @brief Mengatur lebar dimensi kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param width Lebar baru.
 */
void setVehicleWidth(Vehicle *vehicle, int width);

// --- Dimensi: Tinggi ---
/**
 * @brief Mendapatkan tinggi dimensi kendaraan.
 * @param vehicle Kendaraan sumber.
 * @return int Tinggi.
 */
int getVehicleHeight(Vehicle vehicle);
/**
 * @brief Mengatur tinggi dimensi kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param height Tinggi baru.
 */
void setVehicleHeight(Vehicle *vehicle, int height);

// --- Berat ---
/**
 * @brief Mendapatkan berat kendaraan.
 * @param vehicle Kendaraan sumber.
 * @return int Berat.
 */
int getVehicleWeight(Vehicle vehicle);
/**
 * @brief Mengatur berat kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param weight Berat baru.
 */
void setVehicleWeight(Vehicle *vehicle, int weight);

// --- Harga Jual ---
/**
 * @brief Mendapatkan harga jual kendaraan.
 * @param vehicle Kendaraan sumber.
 * @return int Harga jual.
 */
int getVehicleSellingPrice(Vehicle vehicle);
/**
 * @brief Mengatur harga jual kendaraan.
 * @param vehicle Pointer ke kendaraan yang akan dimodifikasi.
 * @param sellingPrice Harga jual baru.
 */
void setVehicleSellingPrice(Vehicle *vehicle, int sellingPrice);

/* ***************************************************** */
/* ******************** KONSTRUKTOR ******************** */
/* ***************************************************** */

/**
 * @brief Membuat objek kendaraan baru dengan parameter yang ditentukan.
 * @param code Kode kendaraan (string).
 * @param seatCount Jumlah kursi.
 * @param wheelCount Jumlah roda.
 * @param speed Kecepatan.
 * @param dims Dimensi (struct Dimensions).
 * @param weight Berat.
 * @param sellingPrice Harga jual.
 * @return Vehicle Objek kendaraan yang baru dibuat dan diinisialisasi.
 */
Vehicle createVehicle(const char *code, int seatCount, int wheelCount, int speed, Dimensions dims, int weight, int sellingPrice);

/**
 * @brief Menginisialisasi kendaraan dengan nilai-nilai default.
 * @details Default: kode="XXX", kursi=4, roda=4, kecepatan=10, dim=10x10x10, berat=100, hargaJual=100000.
 *          Menggunakan `createVehicle` secara internal.
 * @param vehicle Pointer ke kendaraan yang akan diisi dengan nilai default.
 */
void createDefaultVehicle(Vehicle *vehicle);

/**
 * @brief Membuat kendaraan dengan membaca input detail dari pengguna.
 * @details Format input: `<kode> <jumlahKursi> <jumlahRoda> <kecepatan> <panjang> <lebar> <tinggi> <berat> <hargaJual>`
 *          Menggunakan `createVehicle` secara internal.
 * @param vehicle Pointer ke kendaraan yang akan diisi berdasarkan input.
 */
void createVehicleFromInput(Vehicle *vehicle);

/* ***************************************************** */
/* ***************** FUNGSI OPERASIONAL **************** */
/* ***************************************************** */

/**
 * @brief Mencetak detail lengkap sebuah kendaraan.
 * @details Format: `<kode> <kursi> <roda> <kecepatan> <panjang> <lebar> <tinggi> <berat> <harga>`
 *          Menggunakan fungsi getter untuk mendapatkan nilai.
 * @param vehicle Kendaraan yang detailnya akan dicetak.
 */
void printVehicleDetails(Vehicle vehicle);

/**
 * @brief Mencetak jenis kendaraan berdasarkan jumlah rodanya.
 * @details Kriteria: <=2 (NimoRide), >2 & <=4 (NimoCar), >4 & <=6 (NimoTruck), >6 (NimoTanker).
 * @param vehicle Kendaraan yang akan diklasifikasikan.
 */
void printVehicleTypeByWheels(Vehicle vehicle);

/**
 * @brief Mencetak jenis kendaraan berdasarkan kecepatannya.
 * @details Kriteria: <=10 (NimoSlow), >10 & <=20 (NimoFast), >20 & <=30 (NimoSuperFast), >30 (NimoSpeedy).
 * @param vehicle Kendaraan yang akan diklasifikasikan.
 */
 void printVehicleTypeBySpeed(Vehicle vehicle);

 /**
 * @brief Mencetak jenis kendaraan berdasarkan beratnya.
 * @details Kriteria: <=100 (NimoLight), >100 & <=200 (NimoMedium), >200 & <=300 (NimoHeavy), >300 (NimoSuperHeavy).
 * @param vehicle Kendaraan yang akan diklasifikasikan.
 */
void printVehicleTypeByWeight(Vehicle vehicle);

/**
 * @brief Menghitung dan melaporkan profitabilitas perakitan kendaraan.
 * @details Membandingkan total biaya perakitan (berdasarkan roda, kursi, dimensi, berat)
 *          dengan harga jual. Mencetak pesan "Nimons Rugi!", "Nimons Kaya hehe!", atau "Nimons Pas!".
 * @param targetVehicle Pointer ke kendaraan yang akan dievaluasi.
 */
void checkAssemblyProfitability(Vehicle *targetVehicle);

/**
 * @brief Mengevaluasi dan melaporkan profitabilitas penjualan kendaraan (serupa dengan checkAssemblyProfitability).
 * @deprecated Fungsi ini memiliki logika yang sangat mirip atau identik dengan `checkAssemblyProfitability`.
 *             Pertimbangkan untuk menggunakan salah satu saja.
 * @param vehicle Pointer ke kendaraan yang akan dievaluasi.
 */
void evaluateSaleProfitability(Vehicle *vehicle);

/**
 * @brief Mensimulasikan balapan antara dua kendaraan dan menentukan pemenangnya.
 * @details Skor dihitung: `kecepatan*10 - berat*2 - lebar`.
 *          Mencetak pesan pemenang atau seri beserta skor.
 * @param vehicle1 Pointer ke kendaraan pertama.
 * @param vehicle2 Pointer ke kendaraan kedua.
 */
void raceVehicles(Vehicle *vehicle1, Vehicle *vehicle2);

#endif // NIMONS_BALAP_H
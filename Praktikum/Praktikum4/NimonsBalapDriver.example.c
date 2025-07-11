/**
 * --------------------------------------------------------------
 * | @file NimonsBalapDriver.example.c                          |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Contoh program driver untuk menguji fungsionalitas ADT     |
 * | Kendaraan (Vehicle) dari NimonsBalap.h.                    |
 * | Program ini mendemonstrasikan pembuatan kendaraan,         |
 * | pencetakan detail, klasifikasi, evaluasi harga, dan        |
 * | simulasi balap.                                            |
 * --------------------------------------------------------------
 */

#include "NimonsBalap.h" // Menginclude header file ADT Kendaraan
#include <stdio.h>       // Untuk printf

/**
 * @brief Fungsi utama program driver.
 * @details Menjalankan serangkaian operasi untuk menguji ADT Kendaraan:
 *          1. Membuat kendaraan berdasarkan input pengguna.
 *          2. Mencetak detail kendaraan tersebut.
 *          3. Mengklasifikasikan kendaraan berdasarkan roda, kecepatan, dan berat.
 *          4. Mengevaluasi profitabilitas penjualan kendaraan.
 *          5. Membuat kendaraan default dan mensimulasikan balapan.
 * @return int Mengembalikan 0 jika program berjalan sukses.
 */
int main(void)
{
    // Deklarasi variabel untuk dua kendaraan.
    Vehicle vehicle1, vehicle2; // Menggunakan nama struct yang sudah distandarisasi (Vehicle)

    printf("===== NIMONS BALAPAN! =====\n");

    // === Input Kendaraan ===
    // Pengguna diminta memasukkan detail untuk kendaraan pertama.
    printf("\n=== Input Kendaraan ===\n");
    printf("Masukkan detail kendaraan (kode[3char] jmlKursi jmlRoda kecepatan panjang lebar tinggi berat hargaJual):\n");
    // Contoh: CAR 4 4 25 400 180 150 1500 200000
    createVehicleFromInput(&vehicle1); // Menggunakan nama fungsi yang sudah distandarisasi

    // === Detail Kendaraan ===
    // Mencetak detail lengkap dari kendaraan yang baru diinput.
    printf("\n=== Detail Kendaraan ===\n");
    printVehicleDetails(vehicle1); // Menggunakan nama fungsi yang sudah distandarisasi

    // === Jenis Kendaraan ===
    // Mengklasifikasikan dan mencetak jenis kendaraan berdasarkan berbagai kriteria.
    printf("\n=== Jenis Kendaraan ===\n");
    printf("Berdasarkan Roda: ");
    printVehicleTypeByWheels(vehicle1); // Menggunakan nama fungsi yang sudah distandarisasi
    printf("Berdasarkan Kecepatan: ");
    printVehicleTypeBySpeed(vehicle1); // Menggunakan nama fungsi yang sudah distandarisasi
    printf("Berdasarkan Berat: ");
    printVehicleTypeByWeight(vehicle1); // Menggunakan nama fungsi yang sudah distandarisasi

    // === Harga Kendaraan / Profitabilitas ===
    // Mengevaluasi apakah penjualan kendaraan akan menguntungkan.
    printf("\n=== Evaluasi Harga Kendaraan ===\n");
    // Menggunakan salah satu fungsi profitabilitas (keduanya memiliki logika serupa di implementasi asli)
    // Kita pilih checkAssemblyProfitability sebagai representasi.
    checkAssemblyProfitability(&vehicle1); // Menggunakan nama fungsi yang sudah distandarisasi

    // === Balap Kendaraan ===
    // Membuat kendaraan kedua dengan nilai default dan mensimulasikan balapan.
    printf("\n=== Balap Kendaraan ===\n");
    printf("Membuat kendaraan default untuk balapan...\n");
    createDefaultVehicle(&vehicle2); // Menggunakan nama fungsi yang sudah distandarisasi
    printf("Detail Kendaraan Default (Lawan Balap):\n");
    printVehicleDetails(vehicle2);
    printf("Hasil Balapan:\n");
    raceVehicles(&vehicle1, &vehicle2); // Menggunakan nama fungsi yang sudah distandarisasi

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}
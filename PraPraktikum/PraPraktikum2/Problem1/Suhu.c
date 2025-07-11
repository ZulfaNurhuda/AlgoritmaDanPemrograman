/**
 * --------------------------------------------------------------
 * | @file Suhu.c                                               |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk mengonversi suhu antara Celsius, Fahrenheit, |
 * | dan Kelvin.                                                |
 * --------------------------------------------------------------
 */

#include <stdio.h>
#include <math.h> // Diizinkan oleh soal untuk fungsi floor()

/**
 * @brief Memproses seluruh array data konversi suhu.
 *
 * Fungsi ini akan membaca `count` buah data suhu, satuan asal (`fromUnits`),
 * dan satuan tujuan (`toUnits`), lalu melakukan konversi satu per satu dan
 * menyimpan hasilnya ke array `results`.
 *
 * @param count Jumlah total konversi yang akan dilakukan.
 * @param values Pointer ke array nilai suhu awal.
 * @param fromUnits Pointer ke array satuan awal ('C', 'F', atau 'K').
 * @param toUnits Pointer ke array satuan tujuan ('C', 'F', atau 'K').
 * @param results Pointer ke array untuk menyimpan hasil konversi.
 */
void processAllConversions(int count, double *values, char *fromUnits, char *toUnits, double *results)
{
    // Proses konversi suhu untuk setiap elemen
    for (int i = 0; i < count; i++)
    {
        // Ambil nilai suhu dan satuan dari elemen ke-i
        double currentValue = values[i];
        char currentFrom = fromUnits[i];
        char currentTo = toUnits[i];
        double convertedValue = currentValue; // Default: tidak berubah jika satuan sama

        // Konversi berdasarkan jenis satuan asal dan tujuan
        if (currentFrom == 'C') // Dari Celsius
        {
            if (currentTo == 'F') // ke Fahrenheit
            {
                convertedValue = (currentValue * 9.0 / 5.0) + 32.0;
            }
            else if (currentTo == 'K') // ke Kelvin
            {
                convertedValue = currentValue + 273.15;
            }
        }
        else if (currentFrom == 'F') // Dari Fahrenheit
        {
            if (currentTo == 'C') // ke Celsius
            {
                convertedValue = (currentValue - 32.0) * 5.0 / 9.0;
            }
            else if (currentTo == 'K') // ke Kelvin
            {
                convertedValue = (currentValue - 32.0) * 5.0 / 9.0 + 273.15;
            }
        }
        else if (currentFrom == 'K') // Dari Kelvin
        {
            if (currentTo == 'C') // ke Celsius
            {
                convertedValue = currentValue - 273.15;
            }
            else if (currentTo == 'F') // ke Fahrenheit
            {
                convertedValue = (currentValue - 273.15) * 9.0 / 5.0 + 32.0;
            }
        }

        // Simpan hasil konversi ke array hasil
        results[i] = convertedValue;
    }
}

int main(void)
{
    // Membaca jumlah konversi yang akan dilakukan dari input
    int numberOfConversions;
    scanf("%d", &numberOfConversions);

    // Menyediakan array untuk menyimpan suhu awal, hasil konversi, dan satuan
    double initialValues[numberOfConversions];     // Nilai suhu awal
    double conversionResults[numberOfConversions]; // Hasil konversi
    char sourceUnits[numberOfConversions];         // Satuan asal
    char targetUnits[numberOfConversions];         // Satuan tujuan

    // Membaca semua data input dari pengguna
    for (int i = 0; i < numberOfConversions; i++)
    {
        // Format input: <nilai> <satuan_awal> <satuan_tujuan>
        scanf("%lf %c %c", &initialValues[i], &sourceUnits[i], &targetUnits[i]);
    }

    // Proses semua konversi sekaligus
    processAllConversions(numberOfConversions, initialValues, sourceUnits, targetUnits, conversionResults);

    // Cetak semua hasil konversi, dibulatkan ke bawah (floor), dua desimal
    for (int i = 0; i < numberOfConversions; i++)
    {
        printf("%.2f\n", floor(conversionResults[i]));
    }

    return 0;
}
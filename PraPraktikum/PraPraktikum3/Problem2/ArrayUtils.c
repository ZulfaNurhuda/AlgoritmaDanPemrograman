/**
 * --------------------------------------------------------------
 * | @file ArrayUtils.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi berbagai fungsi utilitas untuk memanipulasi   |
 * | array integer, seperti mengurutkan, mencari, dan           |
 * | menghitung statistik dasar.                                |
 * --------------------------------------------------------------
 */

#include "ArrayUtils.h"

void sort(int array[], int numberOfElements)
{
    int i = 0;
    int swapped = 1; // Menandai apakah terjadi pertukaran elemen dalam iterasi

    // Lakukan iterasi selama masih ada pertukaran dan indeks belum mencapai akhir
    while (i < numberOfElements - 1 && swapped)
    {
        swapped = 0; // Set ke 0 setiap awal iterasi

        // Loop membandingkan pasangan elemen berdekatan
        for (int j = 0; j < numberOfElements - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // Tukar jika urutan salah (ascending)
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                swapped = 1; // Menandai bahwa terjadi pertukaran
            }
        }

        i++; // Naikkan indeks untuk iterasi berikutnya
    }
}

int find(int array[], int numberOfElements, int target)
{
    int foundIndex = -1; // Inisialisasi nilai default (tidak ditemukan)

    // Lakukan pencarian linear hingga elemen ditemukan
    for (int i = 0; i < numberOfElements && foundIndex == -1; i++)
    {
        if (array[i] == target)
        {
            foundIndex = i; // Simpan indeks saat elemen ditemukan
        }
    }

    return foundIndex;
}

double calculateAverage(int array[], int numberOfElements)
{
    double average = 0.0;

    if (numberOfElements > 0)
    {
        int sum = 0;

        // Jumlahkan seluruh elemen array
        for (int i = 0; i < numberOfElements; i++)
        {
            sum += array[i];
        }

        // Hitung rata-rata sebagai float
        average = (double)sum / numberOfElements;
    }

    return average;
}

int findMedian(int array[], int numberOfElements)
{
    int median = 0;

    if (numberOfElements > 0)
    {
        // Sort array terlebih dahulu (in-place)
        sort(array, numberOfElements);

        if (numberOfElements % 2 == 0)
        {
            // Jika jumlah genap: median adalah rata-rata dua elemen tengah
            int middle1 = array[numberOfElements / 2 - 1];
            int middle2 = array[numberOfElements / 2];
            median = (middle1 + middle2) / 2;
        }
        else
        {
            // Jika jumlah ganjil: ambil elemen di tengah
            median = array[numberOfElements / 2];
        }
    }

    return median;
}

int findMode(int array[], int numberOfElements)
{
    int mode = 0;

    if (numberOfElements > 0)
    {
        sort(array, numberOfElements); // Sorting memudahkan pencarian modus

        mode = array[0];      // Asumsikan elemen pertama adalah modus
        int maxCount = 1;     // Jumlah tertinggi ditemukan sejauh ini
        int currentCount = 1; // Hitung elemen berulang saat ini

        for (int i = 1; i < numberOfElements; i++)
        {
            if (array[i] == array[i - 1])
            {
                // Elemen sama seperti sebelumnya → increment counter
                currentCount++;
            }
            else
            {
                // Elemen berubah → reset counter
                currentCount = 1;
            }

            if (currentCount > maxCount)
            {
                // Jika jumlah sekarang lebih besar dari max → update modus
                maxCount = currentCount;
                mode = array[i];
            }
        }
    }

    return mode;
}

int findMax(int array[], int numberOfElements)
{
    int maximum = 0;

    if (numberOfElements > 0)
    {
        maximum = array[0]; // Anggap elemen pertama adalah maksimum awal

        // Telusuri semua elemen untuk mencari nilai terbesar
        for (int i = 1; i < numberOfElements; i++)
        {
            if (array[i] > maximum)
            {
                maximum = array[i]; // Perbarui jika ditemukan yang lebih besar
            }
        }
    }

    return maximum;
}

int findMin(int array[], int numberOfElements)
{
    int minimum = 0;

    if (numberOfElements > 0)
    {
        minimum = array[0]; // Asumsi awal nilai minimum

        // Bandingkan dengan elemen lain untuk mencari nilai terkecil
        for (int i = 1; i < numberOfElements; i++)
        {
            if (array[i] < minimum)
            {
                minimum = array[i]; // Perbarui minimum jika ditemukan nilai lebih kecil
            }
        }
    }

    return minimum;
}

void reverseArray(int array[], int numberOfElements)
{
    int start = 0;                  // Pointer dari depan array
    int end = numberOfElements - 1; // Pointer dari belakang array

    // Tukar elemen secara berpasangan dari ujung ke tengah
    while (start < end)
    {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;

        // Geser kedua pointer ke arah tengah
        start++;
        end--;
    }
}
#include "ArrayUtils.h"

#define COLOR_GREEN "\e[0;32m"
#define COLOR_RESET "\e[0m"

/**
 * @brief Mencetak isi array integer dalam format "[a, b, c, ...]".
 *
 * Fungsi ini mencetak setiap elemen dalam array secara berurutan,
 * dipisahkan dengan koma dan diapit oleh tanda kurung siku.
 * Label (keterangan awal) akan dicetak sebelum array sebagai
 * deskripsi isi array tersebut.
 *
 * Contoh output:
 *    Array Awal: [10, 20, 30]
 *
 * @param label String yang dicetak sebelum array, seperti "Array Awal: ".
 * @param array Array integer yang akan ditampilkan.
 * @param size Jumlah elemen dalam array (harus >= 0).
 *
 * @note Tidak mencetak baris baru setelah label, tetapi mencetak baris baru setelah array selesai.
 */
void printArray(const char *label, int array[], int numberOfElements)
{
    printf("%s", label); // Cetak label deskripsi array
    printf("[");
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("%d", array[i]); // Cetak elemen ke-i
        if (i < numberOfElements - 1)
        {
            printf(", "); // Tambahkan koma antar elemen kecuali elemen terakhir
        }
    }
    printf("]\n"); // Tutup array dan pindah baris
}

int main(void)
{
    // Inisialisasi array untuk pengujian fungsi utilitas
    int testArray[] = {27, 19, 42, 19, 5, 50, 33, 42, 19};
    int numberOfElements = sizeof(testArray) / sizeof(testArray[0]);

    // Cetak kondisi awal array
    printArray("Array Asli: ", testArray, numberOfElements);
    printf("--------------------------------------------------\n");

    // Uji fungsi findMax
    int maxValue = findMax(testArray, numberOfElements);
    printf("Elemen Maksimum: %d (nilai tertinggi dalam array)\n", maxValue);

    // Uji fungsi findMin
    int minValue = findMin(testArray, numberOfElements);
    printf("Elemen Minimum: %d (nilai terendah dalam array)\n", minValue);

    // Uji fungsi calculateAverage
    double avgValue = calculateAverage(testArray, numberOfElements);
    printf("Rata-rata elemen: %.2f (total/jumlah elemen)\n", avgValue);

    // Uji fungsi find untuk elemen yang ada dan tidak ada
    int targetFound = 42;
    int indexFound = find(testArray, numberOfElements, targetFound);
    printf("Indeks %d ditemukan di posisi: %d\n", targetFound, indexFound);

    int targetNotFound = 100;
    int indexNotFound = find(testArray, numberOfElements, targetNotFound);
    printf("Indeks %d tidak ditemukan, mengembalikan: %d\n", targetNotFound, indexNotFound);

    printf("--------------------------------------------------\n");

    // Uji fungsi sort
    // Salin array agar mudah dibandingkan sebelum dan setelah sort
    int sortedArray[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
        sortedArray[i] = testArray[i];
    sort(sortedArray, numberOfElements);
    printArray("Array setelah diurutkan: ", sortedArray, numberOfElements);

    // Uji fungsi findMedian
    // Karena findMedian melakukan sort di dalamnya, kita harus memberikan array terurut
    int medianValue = findMedian(sortedArray, numberOfElements);
    printf("Median: %d (nilai tengah dari array terurut)\n", medianValue);

    // Uji fungsi findMode
    int modeValue = findMode(sortedArray, numberOfElements);
    printf("Modus: %d (nilai yang paling sering muncul)\n", modeValue);

    printf("--------------------------------------------------\n");

    // Uji fungsi reverseArray
    reverseArray(sortedArray, numberOfElements);
    // Setelah dibalik, cetak kembali
    printArray("Array setelah dibalik: ", sortedArray, numberOfElements);

    // Indikasi bahwa semua pengujian telah selesai
    printf(COLOR_GREEN "\n[ ☑ ] Pengujian seluruh fungsi ArrayUtils selesai.\n" COLOR_RESET);

    return 0;
}
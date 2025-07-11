/**
 * --------------------------------------------------------------
 * | @file RotasiKekuatan.c                                     |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk melakukan rotasi ke kanan pada sebuah        |
 * | barisan (array) beberapa kali.                             |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Melakukan rotasi ke kanan pada sebuah array dan mencetak hasilnya.
 *
 * Fungsi ini membuat salinan array sementara untuk menyimpan hasil rotasi,
 * lalu mencetak array yang telah dirotasi sesuai format yang diinginkan.
 * Array asli tidak diubah.
 *
 * @param originalArray Array integer asli yang akan dirotasi.
 * @param size Jumlah elemen dalam array.
 * @param rotationAmount Jumlah langkah rotasi ke kanan.
 */
void rotateAndPrintArray(int originalArray[], int size, int rotationAmount)
{
    // Hanya proses jika ukuran array lebih dari 0
    if (size > 0)
    {
        int rotatedArray[size]; // Array sementara untuk hasil rotasi

        // Hitung rotasi efektif (jika jumlah rotasi melebihi ukuran array)
        int effectiveRotation = rotationAmount % size;

        // Pindahkan elemen ke indeks baru sesuai rotasi ke kanan
        for (int i = 0; i < size; i++)
        {
            int newIndex = (i + effectiveRotation) % size;
            rotatedArray[newIndex] = originalArray[i];
        }

        // Cetak array hasil rotasi dengan format [a, b, c]
        printf("[");
        for (int i = 0; i < size; i++)
        {
            printf("%d", rotatedArray[i]);
            if (i < size - 1)
            {
                printf(", "); // Tambahkan koma kecuali di elemen terakhir
            }
        }
        printf("]\n");
    }
}

int main(void)
{
    int nimonsCount;
    scanf("%d", &nimonsCount); // Baca jumlah elemen dalam barisan

    int rotationCount;
    scanf("%d", &rotationCount); // Baca jumlah permintaan rotasi

    int nimonsLineup[nimonsCount]; // Array utama yang akan dirotasi
    for (int i = 0; i < nimonsCount; i++)
    {
        scanf("%d", &nimonsLineup[i]); // Input elemen barisan awal
    }

    int rotationRequests[rotationCount]; // Array yang berisi berapa banyak rotasi
    for (int i = 0; i < rotationCount; i++)
    {
        scanf("%d", &rotationRequests[i]); // Input jumlah rotasi untuk setiap permintaan
    }

    // Jalankan rotasi sesuai permintaan satu per satu
    for (int i = 0; i < rotationCount; i++)
    {
        rotateAndPrintArray(nimonsLineup, nimonsCount, rotationRequests[i]);
    }

    return 0;
}
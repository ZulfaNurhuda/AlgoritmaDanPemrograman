/**
 * --------------------------------------------------------------
 * | @file Barisan.c                                            |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program untuk menghitung skor barisan maksimum yang        |
 * | didapat dari perkalian FPB dan KPK elemennya, dengan opsi  |
 * | menghilangkan paling banyak satu elemen.                   |
 * --------------------------------------------------------------
 */

#include <stdio.h>

/**
 * @brief Menghitung Faktor Persekutuan Terbesar (FPB) menggunakan Algoritma Euclidean.
 *
 * FPB dari dua bilangan a dan b didefinisikan sebagai bilangan bulat positif terbesar
 * yang membagi habis kedua bilangan tersebut.
 *
 * @param firstNumber Bilangan pertama.
 * @param secondNumber Bilangan kedua.
 * @return FPB dari dua bilangan.
 */
long long calculateGCD(long long firstNumber, long long secondNumber)
{
    long long result;
    if (secondNumber == 0)
    {
        result = firstNumber;
    }
    else
    {
        result = calculateGCD(secondNumber, firstNumber % secondNumber);
    }
    return result;
}

/**
 * @brief Menghitung Kelipatan Persekutuan Terkecil (KPK) dari dua bilangan.
 *
 * KPK dari dua bilangan a dan b adalah bilangan terkecil > 0 yang dapat dibagi oleh keduanya.
 * Rumus: lcm(a, b) = (a * b) / gcd(a, b)
 * Untuk menghindari overflow, hitung (a / gcd(a,b)) * b.
 *
 * @param firstNumber Bilangan pertama.
 * @param secondNumber Bilangan kedua.
 * @return KPK dari dua bilangan. Mengembalikan 0 jika salah satu bilangan adalah 0.
 */
long long calculateLCM(long long firstNumber, long long secondNumber)
{
    long long result;
    if (firstNumber == 0 || secondNumber == 0)
    {
        result = 0;
    }
    else
    {
        result = (firstNumber / calculateGCD(firstNumber, secondNumber)) * secondNumber;
    }
    return result;
}

int main(void)
{
    int nimonCount;
    scanf("%d", &nimonCount); // Membaca jumlah elemen barisan

    long long nimonIds[nimonCount]; // Menyimpan nilai setiap elemen
    for (int i = 0; i < nimonCount; i++)
    {
        scanf("%lld", &nimonIds[i]); // Input masing-masing elemen
    }

    long long maxScore = 0; // Variabel untuk menyimpan skor maksimum

    if (nimonCount == 0)
    {
        // Tidak ada elemen, skor = 0
        maxScore = 0;
    }
    else if (nimonCount == 1)
    {
        // Hanya ada 1 elemen, maka FPB dan KPK adalah elemen itu sendiri
        maxScore = nimonIds[0] * nimonIds[0];
    }
    else
    {
        // Gunakan array prefix dan suffix untuk efisiensi komputasi
        long long prefixGCD[1000], suffixGCD[1000];
        long long prefixLCM[1000], suffixLCM[1000];

        // Mengisi prefix FPB dan KPK
        prefixGCD[0] = nimonIds[0];
        prefixLCM[0] = nimonIds[0];
        for (int i = 1; i < nimonCount; i++)
        {
            prefixGCD[i] = calculateGCD(prefixGCD[i - 1], nimonIds[i]);
            prefixLCM[i] = calculateLCM(prefixLCM[i - 1], nimonIds[i]);
        }

        // Mengisi suffix FPB dan KPK
        suffixGCD[nimonCount - 1] = nimonIds[nimonCount - 1];
        suffixLCM[nimonCount - 1] = nimonIds[nimonCount - 1];
        for (int i = nimonCount - 2; i >= 0; i--)
        {
            suffixGCD[i] = calculateGCD(suffixGCD[i + 1], nimonIds[i]);
            suffixLCM[i] = calculateLCM(suffixLCM[i + 1], nimonIds[i]);
        }

        // Kasus tanpa menghilangkan elemen apapun: skor = FPB seluruh array * KPK seluruh array
        maxScore = prefixGCD[nimonCount - 1] * prefixLCM[nimonCount - 1];

        // Pertimbangkan menghilangkan satu elemen dan cek skor maksimal
        for (int i = 0; i < nimonCount; i++)
        {
            long long currentGCD, currentLCM;

            if (i == 0)
            {
                // Menghilangkan elemen pertama → pakai suffix dari index ke-1
                currentGCD = suffixGCD[1];
                currentLCM = suffixLCM[1];
            }
            else if (i == nimonCount - 1)
            {
                // Menghilangkan elemen terakhir → pakai prefix sampai index ke-(n-2)
                currentGCD = prefixGCD[nimonCount - 2];
                currentLCM = prefixLCM[nimonCount - 2];
            }
            else
            {
                // Menghilangkan elemen di tengah → gabungkan prefix kiri dan suffix kanan
                currentGCD = calculateGCD(prefixGCD[i - 1], suffixGCD[i + 1]);
                currentLCM = calculateLCM(prefixLCM[i - 1], suffixLCM[i + 1]);
            }

            long long currentScore = currentGCD * currentLCM;
            if (currentScore > maxScore)
            {
                maxScore = currentScore;
            }
        }
    }

    // Menampilkan skor maksimum setelah mempertimbangkan semua kasus
    printf("%lld\n", maxScore);

    return 0;
}
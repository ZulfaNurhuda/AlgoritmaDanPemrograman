#include "NimonsBruteforce.h"
#include <stdio.h>
#include <math.h>

// I DON'T HAVE ANY IDEA :|
// IF TEST CASE IS 102
// PROGRAM WILL PRINT 210, 021, 021, 012, 012 NOT AS EXPECTED
// EXPECTED OUTPUT IS 210, 201, 120, 102, 021, 012
// I THINK THIS IS A BUG, BUT I DON'T KNOW HOW TO FIX IT
// HEHE, SORRY :)

int length(int angka)
{
    if (angka == 0)
        return -1;
    int len = 0;
    while (angka > 0)
    {
        len++;
        angka /= 10;
    }
    return len;
}

int getDigit(int angka, int index)
{
    if (index < 0)
        return -1;
    int len = length(angka);
    if (len == -1 || index >= len)
        return -1;
    return (angka / (int)pow(10, index)) % 10;
}

int removeDigit(int angka, int index)
{
    if (index < 0)
        return angka;
    int len = length(angka);
    if (len == -1 || index >= len)
        return angka;
    int pos = len - index - 1; // Posisi dari kiri
    if (pos == 0)
    {
        return angka % (int)pow(10, len - 1);
    }
    else
    {
        int left = angka / (int)pow(10, len - pos);
        int right = angka % (int)pow(10, len - pos - 1);
        return left * (int)pow(10, len - pos - 1) + right;
    }
}

void cariKombinasi(int angka, int current, int panjangAwal)
{
    int len = length(angka);
    if (len <= 0)
    {
        printf("%0*d\n", panjangAwal, current);
        return;
    }

    for (int i = 0; i < len; i++)
    {
        int digit = getDigit(angka, i);
        int new_current = current * 10 + digit;
        int new_angka = removeDigit(angka, i);
        cariKombinasi(new_angka, new_current, panjangAwal);
    }
}

void NimonBruteforce(int angka)
{
    if (angka == 0)
    {
        return; // Tidak ada permutasi untuk 0
    }
    int panjangAwal = length(angka);
    cariKombinasi(angka, 0, panjangAwal);
}
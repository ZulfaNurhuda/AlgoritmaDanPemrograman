#include <stdio.h>

int hitungTotalDigit(long angka)
{
    long total = 0;

    while (angka > 0)
    {
        total += angka % 10;
        angka /= 10;
    }

    return total;
}

int main()
{
    long kodeAwal, kodeTakUnik;
    scanf("%ld", &kodeAwal);

    do {
        kodeTakUnik = hitungTotalDigit(kodeAwal);
        if (kodeTakUnik > 9)
        {
            kodeAwal = kodeTakUnik;
        }
    }
    while (kodeTakUnik > 9);

    printf("%ld\n", kodeTakUnik);

    return 0;
}
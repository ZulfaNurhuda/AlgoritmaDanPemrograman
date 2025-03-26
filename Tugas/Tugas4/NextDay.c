#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int DD, MM, YY;
} Tanggal;

bool IsKabisat(int tahun)
{
    return (tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0);
}

Tanggal NextDay(Tanggal T)
{
    int hari_per_bulan[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (IsKabisat(T.YY) && T.MM == 2)
    {
        hari_per_bulan[1] = 29;
    }

    T.DD++;

    if (T.DD > hari_per_bulan[T.MM - 1])
    {
        T.DD = 1;
        T.MM++;
        if (T.MM > 12)
        {
            T.MM = 1;
            T.YY++;
        }
    }
    return T;
}

int main()
{
    Tanggal today = {31, 12, 2024};
    Tanggal tomorrow = NextDay(today);
    printf("Besok: %d/%d/%d\n", tomorrow.DD, tomorrow.MM, tomorrow.YY);
    return 0;
}
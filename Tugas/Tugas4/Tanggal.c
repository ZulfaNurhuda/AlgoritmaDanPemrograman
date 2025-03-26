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

bool IsTanggalValid(int d, int m, int y)
{
    int hari_per_bulan[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m < 1 || m > 12 || d < 1 || y < 1)
        return false;
    if (IsKabisat(y) && m == 2)
        hari_per_bulan[1] = 29;
    return (d <= hari_per_bulan[m - 1]);
}

void BacaTanggal(Tanggal *T)
{
    int d, m, y;
    do
    {
        printf("Masukkan tanggal (DD MM YYYY): ");
        scanf("%d %d %d", &d, &m, &y);
        if (!IsTanggalValid(d, m, y))
            printf("Tanggal tidak valid!\n");
    } while (!IsTanggalValid(d, m, y));
    T->DD = d;
    T->MM = m;
    T->YY = y;
}

const char *NamaBulan(int m)
{
    const char *nama[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni",
                          "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    return nama[m - 1];
}

void TulisTanggal(Tanggal T)
{
    printf("%d %s %d\n", T.DD, NamaBulan(T.MM), T.YY);
}

/*
    Salin fungsi NextDay dari latihan soal nomer 2
    (Kalau tidak disalin akan terjadi error karena fungsi tidak ditemukan)
*/
Tanggal NextDay(Tanggal T) // Fungsi dari soal nomor 2
{
    int hari_per_bulan[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Update hari Februari jika tahun kabisat
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
    Tanggal hari_ini, besok;

    BacaTanggal(&hari_ini);

    printf("Hari ini: ");
    TulisTanggal(hari_ini);

    besok = NextDay(hari_ini);
    printf("Besok: ");
    TulisTanggal(besok);

    return 0;
}
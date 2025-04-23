#include <stdio.h>

int main()
{
    long N;
    int stopped = 0;
    scanf("%d", &N); // Membaca jumlah laporan

    long sum_even = 0, sum_odd = 0;

    for (long i = 0; i < N; i++)
    {
        long x;
        scanf("%d", &x); // Membaca nilai laporan

        if (x == 0)
        {
            stopped = 1; // Berhenti jika menemukan 0
        }

        if (!stopped) {
            if (x % 2 == 0)
            {
                sum_even += x; // Tambahkan ke jumlah genap
            }
            else
            {
                sum_odd += x; // Tambahkan ke jumlah ganjil
            }
        }
    }

    printf("%d %d\n", sum_even, sum_odd); // Cetak hasil

    return 0;
}
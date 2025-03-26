#include <stdio.h>

// TODO: Perbaiki prosedur agar variabel total bisa diperbarui secara langsung
void countPrime(int A, int B, int *total)
{
    // TODO: Implementasi prosedur untuk menghitung jumlah bilangan prima dalam rentang [A, B]
    // Saat ini, total tidak bisa diperbarui karena hanya merupakan salinan dari nilai di main()

    for (int i = A; i <= B; i++)
    {
        int isPrime = 1;
        if (i <= 1)
        {
            isPrime = 0;
        }
        else
        {
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
        }
        
        if (isPrime)
        {
            (*total)++; // Perbarui nilai total melalui pointer
        }
    }
}

int main()
{
    int A, B, total = 0;

    // TODO: Baca dua bilangan integer A dan B dalam satu baris
    // Input harus dalam format: "A B"
    scanf("%d %d", &A, &B);

    // TODO: Perbaiki pemanggilan prosedur dengan menggunakan alamat variabel total
    // Agar perubahan nilai di dalam prosedur juga mempengaruhi nilai di main()
    countPrime(A, B, &total);

    printf("%d\n", total);

    return 0;
}
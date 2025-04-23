#include <stdio.h>

int main()
{
    int N, total_mentah = 0, total_matang = 0, total_terlalu = 0;
    scanf("%d", &N);

    int i = 0;
    while (i < N)
    {
        int option;
        scanf("%d", &option);

        if (option == 1)
        {
            int day;
            scanf("%d", &day);
            if (day >= 0 && day <= 2)
            {
                printf("Kategori: Mentah\n");
                total_mentah++;
            }
            else if (day >= 3 && day <= 5)
            {
                printf("Kategori: Matang\n");
                total_matang++;
            }
            else
            {
                printf("Kategori: Terlalu matang\n");
                total_terlalu++;
            }
            i++;
        }
        else if (option == 2)
        {
            printf("Laporan Kematangan Pisang\n");
            printf("Mentah: %d\n", total_mentah);
            printf("Matang: %d\n", total_matang);
            printf("Terlalu matang: %d\n", total_terlalu);
        }
        else
        {
            printf("Input salah. Masukkan kembali input dengan benar.\n");
        }
    }

    printf("Program selesai\n");
    return 0;
}
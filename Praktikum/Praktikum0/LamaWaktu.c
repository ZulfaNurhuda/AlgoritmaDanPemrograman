#include <stdio.h>

int main()
{
    int jam_awal, menit_awal, detik_awal, jam_akhir, menit_akhir, detik_akhir;

    scanf("%d %d %d", &jam_awal, &menit_awal, &detik_awal);
    scanf("%d %d %d", &jam_akhir, &menit_akhir, &detik_akhir);
    
    printf("%d %d %d\n", jam_akhir - jam_awal, menit_akhir - menit_awal, detik_akhir - detik_awal);
    
    return 0;
}
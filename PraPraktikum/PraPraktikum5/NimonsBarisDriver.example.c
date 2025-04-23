#include <stdio.h>
#include "NimonsBaris.h"

int main() {
    BarisanNimons T;
    MakeEmpty(&T);

    printf("Apakah tabel kosong? %s\n", IsEmpty(T) ? "Ya" : "Tidak");
    TulisIsi(T);

    printf("\n");
    
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 1; i <= 5; i++) {
        SetEl(&T, i, arr[i - 1]);
    }

    printf("Apakah tabel penuh? %s\n", IsFull(T) ? "Ya" : "Tidak");
    TulisIsi(T);

    printf("\n");

    int idx = 2;
    printf("Elemen ke-%d: %d\n", idx, GetElmt(T, idx));

    printf("\n");

    int val = 10;
    SetEl(&T, idx, val);
    printf("Setelah diubah, elemen ke-%d: %d\n", idx, GetElmt(T, idx));

    return 0;
}

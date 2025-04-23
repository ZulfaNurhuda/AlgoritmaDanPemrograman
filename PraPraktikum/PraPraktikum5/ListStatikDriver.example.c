#include "ListStatik.h"
#include <stdlib.h>

int main() {
    ListStatik list;
    inisialisasiList(&list, 10);

    tambahElemen(&list, 5);
    tambahElemen(&list, 10);
    tambahElemen(&list, 15);

    printf("Isi list: ");
    tampilkanList(list);

    hapusElemenAkhir(&list);
    printf("Setelah menghapus elemen terakhir: ");
    tampilkanList(list);

    int searchValue = 10;
    int indeks = cariElemen(list, searchValue);
    if (indeks != -1) {
        printf("Elemen %d ditemukan pada indeks: %d\n", searchValue, indeks);
    } else {
        printf("Elemen %d tidak ditemukan\n", searchValue);
    }

    ubahElemen(&list, 1, 20);
    tampilkanList(list);

    free(list.data);

    return 0;
}
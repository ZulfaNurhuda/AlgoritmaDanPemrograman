#include "ListNimons.h"
#include <stdio.h>
#include <string.h>

int main() {
    ListNimons l;
    CreateListNimons(&l);
    
    printf("Apakah list kosong? %s\n", isNimonsEmpty(l) ? "Ya" : "Tidak");
    printf("Apakah list penuh? %s\n", isNimonsFull(l) ? "Ya" : "Tidak");

    printf("\n");

    char name[10] = "Budi";
    char name2[10] = "Joko";

    Nimons n;
    strcpy(n.name, name);
    n.age = 20;
    n.height = 165;
    insertNimonsLast(&l, n);
    
    printf("Apakah list kosong? %s\n", isNimonsEmpty(l) ? "Ya" : "Tidak");
    printf("Apakah list penuh? %s\n", isNimonsFull(l) ? "Ya" : "Tidak");

    printf("\n");

    Nimons m;
    strcpy(m.name, name2);
    m.age = 20;
    m.height = 165;
    insertNimonsLast(&l, m);

    int idx = indexOfNimons(l, name);
    if (idx != IDX_UNDEF) {
        printf("%s berada pada indeks %d\n", name, idx);
    } else {
        printf("%s tidak ditemukan\n", name);
    }
    
    deleteNimonsLast(&l, &n);
    
    printf("Apakah list kosong? %s\n", isNimonsEmpty(l) ? "Ya" : "Tidak");
    printf("Apakah list penuh? %s\n", isNimonsFull(l) ? "Ya" : "Tidak");
    
    return 0;
}

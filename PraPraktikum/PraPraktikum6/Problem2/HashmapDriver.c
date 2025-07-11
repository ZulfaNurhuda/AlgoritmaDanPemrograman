#include "Hashmap.h"

int main(void)
{
    HashMap M;

    // Inisialisasi HashMap M sebagai map kosong
    // Semua key dan value diset ke UNDEFINED
    createEmpty(&M);

    // Menambahkan pasangan key-value ke dalam HashMap
    insert(&M, 1, 2);     // Key: 1, Value: 2
    insert(&M, 2, 3);     // Key: 2, Value: 3
    insert(&M, 3, 4);     // Key: 3, Value: 4
    insert(&M, 123, 123); // Key: 123, Value: 123 (untuk uji tabrakan hash)

    // Mencetak nilai yang terkait dengan key tertentu
    // Harusnya mencetak: 2
    printf("%d\n", value(M, 1));

    // Harusnya mencetak: 3
    printf("%d\n", value(M, 2));

    // Menampilkan seluruh isi HashMap (termasuk slot kosong)
    printHashMap(M);

    return 0;
}
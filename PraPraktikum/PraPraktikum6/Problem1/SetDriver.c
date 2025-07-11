#include "Set.h"

int main(void)
{
    Set s;
    createEmpty(&s); // Inisialisasi Set menjadi kosong

    // Cek apakah set kosong setelah inisialisasi
    if (isEmpty(s))
    {
        printf("Set is empty\n");
    }

    // Menambahkan beberapa elemen ke dalam Set
    insert(&s, 5); // Tambah 5
    insert(&s, 3); // Tambah 3
    insert(&s, 8); // Tambah 8
    insert(&s, 3); // Ulangi 3 (harusnya tidak ditambahkan karena Set tidak boleh duplikat)

    // Tampilkan elemen Set setelah penyisipan
    printf("Set elements: ");
    for (int i = 0; i < s.count; i++)
    {
        printf("%d ", s.elements[i]);
    }
    printf("\n");

    // Uji keanggotaan
    printf("Is 3 a member? %s\n", isMember(s, 3) ? "Yes" : "No");
    printf("Is 7 a member? %s\n", isMember(s, 7) ? "Yes" : "No");

    // Menghapus elemen dari Set
    delete(&s, 3); // Hapus elemen 3

    // Tampilkan Set setelah penghapusan
    printf("Set elements after deleting 3: ");
    for (int i = 0; i < s.count; i++)
    {
        printf("%d ", s.elements[i]);
    }
    printf("\n");

    // Periksa apakah Set sudah penuh
    if (isFull(s))
    {
        printf("Set is full\n");
    }
    else
    {
        printf("Set is not full\n");
    }
    
    return 0;
}
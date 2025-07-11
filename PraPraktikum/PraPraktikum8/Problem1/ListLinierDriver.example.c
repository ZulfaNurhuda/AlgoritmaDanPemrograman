#include "ListLinier.h"

#define COLOR_GREEN "\e[0;32m"
#define COLOR_RESET "\e[0m"

int main(void)
{
    // Inisialisasi beberapa list kosong
    List myList, list1, list2, list3;
    createEmpty(&myList);
    createEmpty(&list1);
    createEmpty(&list2);

    // Cetak list awal yang masih kosong
    printf("Initial list: ");
    printInfo(myList);
    printf("Is list empty? %s\n", isEmpty(myList) ? "Yes" : "No");

    // ------------------------------------------
    // Uji fungsi insertValueFirst dan insertValueLast
    // ------------------------------------------
    printf("\n--- Testing Insertion ---\n");
    insertValueFirst(&myList, 10); // List: [10]
    insertValueLast(&myList, 30);  // List: [10,30]
    insertValueFirst(&myList, 5);  // List: [5,10,30]
    insertValueLast(&myList, 40);  // List: [5,10,30,40]
    printf("After insertions: ");
    printInfo(myList); // Expected output: [5,10,30,40]
    printf("Number of elements: %d\n", numberOfElements(myList));

    // ------------------------------------------
    // Uji fungsi search
    // ------------------------------------------
    printf("\n--- Testing Search ---\n");
    Address foundNode = search(myList, 30); // Cari elemen 30
    if (foundNode != NIL)
    {
        printf("Element 30 found at address %p\n", (void *)foundNode);
    }
    else
    {
        printf("Element 30 not found.\n");
    }

    foundNode = search(myList, 99); // Cari elemen yang tidak ada
    if (foundNode != NIL)
    {
        printf("Element 99 found.\n");
    }
    else
    {
        printf("Element 99 not found.\n");
    }

    // ------------------------------------------
    // Uji fungsi deleteValueFirst dan deleteValueLast
    // ------------------------------------------
    printf("\n--- Testing Deletion ---\n");
    InfoType deletedValue;

    deleteValueFirst(&myList, &deletedValue); // Hapus elemen pertama
    printf("Deleted first element: %d. List is now: ", deletedValue);
    printInfo(myList); // Expected: [10,30,40]

    deleteValueLast(&myList, &deletedValue); // Hapus elemen terakhir
    printf("Deleted last element: %d. List is now: ", deletedValue);
    printInfo(myList); // Expected: [10,30]

    // ------------------------------------------
    // Uji fungsi deleteNode (hapus berdasarkan nilai)
    // ------------------------------------------
    deleteNode(&myList, 10); // Hapus nilai 10 dari list
    printf("After deleting element 10: ");
    printInfo(myList); // Expected: [30]

    // ------------------------------------------
    // Uji inversList
    // ------------------------------------------
    printf("\n--- Testing inversList ---\n");
    insertValueFirst(&myList, 20); // List: [20,30]
    insertValueFirst(&myList, 10); // List: [10,20,30]
    printf("Original list for inversion: ");
    printInfo(myList);   // Expected: [10,20,30]
    inversList(&myList); // List dibalik: [30,20,10]
    printf("Inversed list: ");
    printInfo(myList);

    // ------------------------------------------
    // Uji fungsi concat (penggabungan list1 dan list2 ke list3)
    // ------------------------------------------
    printf("\n--- Testing concat ---\n");
    insertValueFirst(&list1, 1); // list1: [1]
    insertValueLast(&list1, 2);  // list1: [1,2]
    insertValueFirst(&list2, 3); // list2: [3]
    insertValueLast(&list2, 4);  // list2: [3,4]
    printf("List 1: ");
    printInfo(list1);
    printf("List 2: ");
    printInfo(list2);

    concat(&list1, &list2, &list3); // Gabungkan list1 dan list2 menjadi list3
    printf("Concatenated List 3: ");
    printInfo(list3);
    printf("Is List 1 empty now? %s\n", isEmpty(list1) ? "Yes" : "No");
    printf("Is List 2 empty now? %s\n", isEmpty(list2) ? "Yes" : "No");

    // ------------------------------------------
    // Dealokasi semua node dari list3
    // (menghindari memory leak)
    // ------------------------------------------
    Address p;
    while (!isEmpty(list3))
    {
        deleteFirst(&list3, &p);
        deallocate(&p); // Bebaskan node dari memori
    }
    printf("\nAll nodes in all lists have been deallocated.\n");

    printf(COLOR_GREEN "\n[ ☑ ] - Pengujian selesai.\n" COLOR_RESET);

    return 0;
}
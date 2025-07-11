#include "CircularLinkedList.h"

#define COLOR_GREEN "\e[0;32m"
#define COLOR_RESET "\e[0m"

int main(void)
{
    Address list = NULL; // List circular awalnya kosong

    printf("Initial list state: ");
    displayList(list);
    printf("Is empty? %s\n", isEmpty(list) ? "Yes" : "No");

    // ------------------------------------------
    // Testing penambahan elemen
    // ------------------------------------------
    printf("\n--- Testing Insertion ---\n");
    insertAtEnd(&list, 20);       // List: 20
    insertAtBeginning(&list, 10); // List: 10 -> 20
    insertAtEnd(&list, 40);       // List: 10 -> 20 -> 40
    insertAfter(&list, 20, 30);   // List: 10 -> 20 -> 30 -> 40
    printf("List after insertions: ");
    displayList(list);

    // ------------------------------------------
    // Testing pencarian node
    // ------------------------------------------
    printf("\n--- Testing Search ---\n");
    Address found = searchNode(list, 30);
    printf("Node with value 30 %s.\n", (found != NULL) ? "found" : "not found");

    found = searchNode(list, 99);
    printf("Node with value 99 %s.\n", (found != NULL) ? "found" : "not found");

    // ------------------------------------------
    // Testing penghapusan node
    // ------------------------------------------
    printf("\n--- Testing Deletion ---\n");
    deleteFromBeginning(&list); // Hapus 10
    printf("After deleting from beginning: ");
    displayList(list); // Expected: 20 -> 30 -> 40

    deleteFromEnd(&list); // Hapus 40
    printf("After deleting from end: ");
    displayList(list); // Expected: 20 -> 30

    deleteNodeWithValue(&list, 20); // Hapus 20
    printf("After deleting node with value 20: ");
    displayList(list); // Expected: 30

    // ------------------------------------------
    // Testing penghapusan node terakhir
    // ------------------------------------------
    deleteNodeWithValue(&list, 30); // Hapus node terakhir
    printf("After deleting the last element: ");
    displayList(list); // Expected: KOSONG

    // ------------------------------------------
    // Testing deleteAllNodes
    // ------------------------------------------
    printf("\n--- Testing deleteAllNodes ---\n");
    insertAtEnd(&list, 1);
    insertAtEnd(&list, 2);
    insertAtEnd(&list, 3);
    printf("List before deleteAllNodes: ");
    displayList(list);

    deleteAllNodes(&list); // Hapus semua node
    printf("List after deleteAllNodes: ");
    displayList(list);
    printf("Is empty? %s\n", isEmpty(list) ? "Yes" : "No");

    printf(COLOR_GREEN "\n[ ☑ ] - Pengujian selesai.\n" COLOR_RESET);

    return 0;
}
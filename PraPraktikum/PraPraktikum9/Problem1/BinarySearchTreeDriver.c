#include "BinarySearchTree.h"

int main(void)
{
    BinTree root = NIL; // Inisialisasi BST kosong
    ElType x;

    // ------------------------------
    // Penambahan beberapa node
    // ------------------------------
    x.key = 50;
    x.count = 1;
    insertSearchTree(x, &root);

    x.key = 30;
    x.count = 1;
    insertSearchTree(x, &root);

    x.key = 70;
    x.count = 1;
    insertSearchTree(x, &root);

    x.key = 20;
    x.count = 1;
    insertSearchTree(x, &root);

    x.key = 40;
    x.count = 1;
    insertSearchTree(x, &root);

    x.key = 60;
    x.count = 1;
    insertSearchTree(x, &root);

    x.key = 80;
    x.count = 1;
    insertSearchTree(x, &root);

    // ------------------------------
    // Pencarian nilai dalam BST
    // ------------------------------
    printf("\nMelakukan pencarian node:\n");

    int search_value = 40;
    Address found_node = searchNode(root, search_value);
    if (found_node != NIL)
    {
        printf("Node dengan nilai %d ditemukan (count: %d).\n", ROOT(found_node).key, ROOT(found_node).count);
    }
    else
    {
        printf("Node dengan nilai %d tidak ditemukan.\n", search_value);
    }

    search_value = 90;
    found_node = searchNode(root, search_value);
    if (found_node != NIL)
    {
        printf("Node dengan nilai %d ditemukan (count: %d).\n", ROOT(found_node).key, ROOT(found_node).count);
    }
    else
    {
        printf("Node dengan nilai %d tidak ditemukan.\n", search_value);
    }

    // ------------------------------
    // Mencari nilai terkecil
    // ------------------------------
    printf("\nMencari nilai minimum:\n");
    Address min_node = findMinimum(root);
    if (min_node != NIL)
    {
        printf("Nilai minimum dalam BST adalah: %d (count: %d)\n", ROOT(min_node).key, ROOT(min_node).count);
    }
    else
    {
        printf("BST kosong.\n");
    }

    return 0;
}
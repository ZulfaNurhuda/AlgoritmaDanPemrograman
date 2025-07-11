#include "BintreeTraversal.h"

int main(void)
{
    /*
     * --------------------------------------------------------------------------
     * | Struktur pohon BST yang akan dibangun:                                 |
     * |                                                                        |
     * |            8                                                           |
     * |          /   \                                                         |
     * |         3     10                                                       |
     * |        / \      \                                                      |
     * |       2   6      14                                                    |
     * |      /   / \     /                                                     |
     * |     1   4   7   13                                                     |
     * |                                                                        |
     * | Node dimasukkan menggunakan insertSearchTree agar bentuknya BST valid. |
     * --------------------------------------------------------------------------
     */

    BinTree T = NIL;
    ElType x;

    // Nilai-nilai key yang akan dimasukkan
    int keys[] = {8, 3, 10, 2, 6, 14, 1, 7, 4, 13};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Bangun BST satu per satu
    for (int i = 0; i < n; i++)
    {
        x.key = keys[i];
        x.count = 1;
        insertSearchTree(x, &T);
    }

    // Traversal pohon secara langsung
    printf("Traversal PreOrder: ");
    printPreOrder(T);
    printf("\n");

    printf("Traversal InOrder: ");
    printInOrder(T);
    printf("\n");

    printf("Traversal PostOrder: ");
    printPostOrder(T);
    printf("\n");

    // Membuat linked list hasil traversal
    NodeList *preList = makeListPreOrder(T);
    NodeList *inList = makeListInOrder(T);
    NodeList *postList = makeListPostOrder(T);

    // Cetak linked list preorder
    printf("\nList PreOrder: ");
    printNodeList(preList);

    // Cetak linked list inorder
    printf("List InOrder: ");
    printNodeList(inList);

    // Cetak linked list postorder
    printf("List PostOrder: ");
    printNodeList(postList);

    return 0;
}
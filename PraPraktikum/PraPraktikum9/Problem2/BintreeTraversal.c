/**
 * --------------------------------------------------------------
 * | @file bintreeTraversal.c                                   |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi fungsi traversal pada Binary Tree sesuai      |
 * | dengan header bintreeTraversal.h                           |
 * --------------------------------------------------------------
 */

#include "BintreeTraversal.h"

void printPreOrder(BinTree tree)
{
    if (!isTreeEmpty(tree))
    {
        // Cetak root terlebih dahulu
        printf("%d ", ROOT(tree).key);
        // Rekursi ke subtree kiri
        printPreOrder(LEFT(tree));
        // Rekursi ke subtree kanan
        printPreOrder(RIGHT(tree));
    }
}

void printInOrder(BinTree tree)
{
    if (!isTreeEmpty(tree))
    {
        // Rekursi ke subtree kiri
        printInOrder(LEFT(tree));
        // Cetak root di tengah
        printf("%d ", ROOT(tree).key);
        // Rekursi ke subtree kanan
        printInOrder(RIGHT(tree));
    }
}

void printPostOrder(BinTree tree)
{
    if (!isTreeEmpty(tree))
    {
        // Rekursi ke subtree kiri
        printPostOrder(LEFT(tree));
        // Rekursi ke subtree kanan
        printPostOrder(RIGHT(tree));
        // Cetak root di akhir
        printf("%d ", ROOT(tree).key);
    }
}

AddressList newNodeListElement(ElType value)
{
    // Alokasi node list baru
    AddressList newNode = (AddressList)malloc(sizeof(NodeList));
    if (newNode != NIL)
    {
        INFO(newNode) = value;
        NEXT(newNode) = NIL;
    }
    return newNode;
}

AddressList concat(AddressList list1, AddressList list2)
{
    // Menggabungkan dua list secara sekuensial
    AddressList result;
    if (list1 == NIL)
    {
        // Jika list pertama kosong, hasil adalah list kedua
        result = list2;
    }
    else
    {
        // Cari ujung dari list pertama
        AddressList current = list1;
        while (NEXT(current) != NIL)
        {
            current = NEXT(current);
        }
        // Sambungkan ke list kedua
        NEXT(current) = list2;
        result = list1;
    }
    return result;
}

AddressList makeListPreOrder(BinTree tree)
{
    AddressList result = NIL;
    if (!isTreeEmpty(tree))
    {
        // Buat node dari root saat ini
        AddressList rootNode = newNodeListElement(ROOT(tree));
        // Bangun list dari anak kiri dan kanan
        AddressList leftList = makeListPreOrder(LEFT(tree));
        AddressList rightList = makeListPreOrder(RIGHT(tree));

        // Gabungkan: root -> kiri -> kanan
        if (rootNode != NIL)
        {
            result = concat(rootNode, concat(leftList, rightList));
        }
    }
    return result;
}

AddressList makeListInOrder(BinTree tree)
{
    AddressList result = NIL;
    if (!isTreeEmpty(tree))
    {
        AddressList leftList = makeListInOrder(LEFT(tree));
        AddressList rootNode = newNodeListElement(ROOT(tree));
        AddressList rightList = makeListInOrder(RIGHT(tree));

        // Gabungkan: kiri -> root -> kanan
        if (rootNode != NIL)
        {
            result = concat(leftList, concat(rootNode, rightList));
        }
    }
    return result;
}

AddressList makeListPostOrder(BinTree tree)
{
    AddressList result = NIL;
    if (!isTreeEmpty(tree))
    {
        AddressList leftList = makeListPostOrder(LEFT(tree));
        AddressList rightList = makeListPostOrder(RIGHT(tree));
        AddressList rootNode = newNodeListElement(ROOT(tree));

        // Gabungkan: kiri -> kanan -> root
        if (rootNode != NIL)
        {
            result = concat(concat(leftList, rightList), rootNode);
        }
    }
    return result;
}

void printNodeList(AddressList list)
{
    AddressList current = list;
    while (current != NULL)
    {
        // Cetak elemen list dengan format [key] -> ...
        printf("[%d] -> ", INFO(current).key);
        current = NEXT(current);
    }
    printf("FINISH\n");
}
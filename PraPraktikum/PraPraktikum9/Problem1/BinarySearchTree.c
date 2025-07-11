/**
 * --------------------------------------------------------------
 * | @file BinarySearchTree.c                                   |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Binary Search Tree (BST) sesuai header    |
 * | binarySearchTree.h                                         |
 * --------------------------------------------------------------
 */

#include "BinarySearchTree.h"

Address newTreeNode(ElType value)
{
    Address newNode = (Address)malloc(sizeof(TreeNode)); // Alokasi node baru
    if (newNode != NIL)
    {
        ROOT(newNode) = value; // Isi data pada node
        LEFT(newNode) = NIL;   // Set anak kiri ke NIL
        RIGHT(newNode) = NIL;  // Set anak kanan ke NIL
    }
    return newNode; // Kembalikan alamat node baru
}

void deallocTreeNode(Address node)
{
    free(node); // Bebaskan memori node
    node = NIL; // Hindari dangling pointer
}

bool isTreeEmpty(BinTree tree)
{
    return (tree == NIL); // Pohon kosong jika alamat root NIL
}

bool isOneElement(BinTree tree)
{
    // Hanya satu elemen jika tidak kosong dan tidak punya anak kiri/kanan
    return (!isTreeEmpty(tree) && LEFT(tree) == NIL && RIGHT(tree) == NIL);
}

bool isUnerLeft(BinTree tree)
{
    // Hanya anak kiri jika tidak kosong dan hanya punya anak kiri
    return (!isTreeEmpty(tree) && LEFT(tree) != NIL && RIGHT(tree) == NIL);
}

bool isUnerRight(BinTree tree)
{
    // Hanya anak kanan jika tidak kosong dan hanya punya anak kanan
    return (!isTreeEmpty(tree) && LEFT(tree) == NIL && RIGHT(tree) != NIL);
}

bool isBiner(BinTree tree)
{
    // Dua anak jika tidak kosong dan punya anak kiri dan kanan
    return (!isTreeEmpty(tree) && LEFT(tree) != NIL && RIGHT(tree) != NIL);
}

BinTree buildBalancedTree(int nodeCount)
{
    BinTree root = NIL;
    if (nodeCount > 0)
    {
        int nL = nodeCount / 2;      // Jumlah node kiri
        int nR = nodeCount - nL - 1; // Jumlah node kanan

        ElType element;
        element.key = nL; // Key sementara (berbasis indeks)
        element.count = 1;

        root = newTreeNode(element); // Buat root node
        if (root != NIL)
        {
            LEFT(root) = buildBalancedTree(nL);  // Rekursif bangun kiri
            RIGHT(root) = buildBalancedTree(nR); // Rekursif bangun kanan
        }
    }
    return root;
}

void insertSearchTree(ElType newValue, BinTree *tree)
{
    if (isTreeEmpty(*tree))
    {
        *tree = newTreeNode(newValue); // Sisipkan di tempat kosong
    }
    else
    {
        if (newValue.key < ROOT(*tree).key)
        {
            insertSearchTree(newValue, &LEFT(*tree)); // Masuk kiri
        }
        else if (newValue.key > ROOT(*tree).key)
        {
            insertSearchTree(newValue, &RIGHT(*tree)); // Masuk kanan
        }
        else
        {
            ROOT(*tree).count++; // Key sudah ada, tambahkan count
        }
    }
}

void deleteNode(Address *node)
{
    if (RIGHT(*node) != NIL)
    {
        deleteNode(&RIGHT(*node)); // Cari node paling kanan (max)
    }
    else
    {
        Address temp = *node;  // Simpan node yang akan dihapus
        *node = LEFT(*node);   // Gantikan node dengan anak kirinya
        deallocTreeNode(temp); // Dealokasi node lama
    }
}

void deleteBinaryTree(BinTree *tree, ElType valueToDelete)
{
    if (!isTreeEmpty(*tree))
    {
        if (valueToDelete.key < ROOT(*tree).key)
        {
            deleteBinaryTree(&LEFT(*tree), valueToDelete); // Ke kiri
        }
        else if (valueToDelete.key > ROOT(*tree).key)
        {
            deleteBinaryTree(&RIGHT(*tree), valueToDelete); // Ke kanan
        }
        else
        {
            Address nodeToDelete = *tree;
            // Kasus node adalah leaf, hapus langsung
            if (isOneElement(nodeToDelete))
            {
                *tree = NIL;
                deallocTreeNode(nodeToDelete);
            }
            // Kasus node memiliki satu anak, naikkan anak ke atas
            else if (isUnerLeft(nodeToDelete))
            {
                *tree = LEFT(nodeToDelete);
                deallocTreeNode(nodeToDelete);
            }
            else if (isUnerRight(nodeToDelete))
            {
                *tree = RIGHT(nodeToDelete);
                deallocTreeNode(nodeToDelete);
            }
            // Kasus node memiliki dua anak, cari node maksimum di subtree kiri
            // dan salin info dari node tersebut ke node saat ini
            else
            {
                Address predecessor = LEFT(*tree); // Cari node terbesar di subtree kiri
                while (RIGHT(predecessor) != NIL)
                {
                    predecessor = RIGHT(predecessor);
                }
                ROOT(*tree) = ROOT(predecessor); // Gantikan data
                deleteNode(&LEFT(*tree));        // Hapus duplikat node predecessor
            }
        }
    }
}

Address searchNode(BinTree tree, int queryKey)
{
    Address result = NIL;
    if (!isTreeEmpty(tree))
    {
        if (queryKey == ROOT(tree).key)
        {
            // Ditemukan, simpan alamat node
            result = tree;
        }
        else if (queryKey < ROOT(tree).key)
        {
            result = searchNode(LEFT(tree), queryKey); // Rekursif kiri
        }
        else
        {
            result = searchNode(RIGHT(tree), queryKey); // Rekursif kanan
        }
    }
    return result;
}

Address findMinimum(BinTree tree)
{
    Address result = NIL;
    if (!isTreeEmpty(tree))
    {
        if (LEFT(tree) == NIL)
        {
            result = tree; // Tidak ada anak kiri = minimum
        }
        else
        {
            result = findMinimum(LEFT(tree)); // Terus ke kiri
        }
    }
    return result;
}
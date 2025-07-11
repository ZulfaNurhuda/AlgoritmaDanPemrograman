#include "bst_range_sum.h"

void printPreOrder(BinTree p)
{
    if (!isTreeEmpty(p))
    {
        printf("%d ", Info(p).key);
        printPreOrder(LEFT(p));
        printPreOrder(RIGHT(p));
    }
}

void printInOrder(BinTree p)
{
    if (!isTreeEmpty(p))
    {
        printInOrder(LEFT(p));
        printf("%d ", Info(p).key);
        printInOrder(RIGHT(p));
    }
}

void printPostOrder(BinTree p)
{
    if (!isTreeEmpty(p))
    {
        printPostOrder(LEFT(p));
        printPostOrder(RIGHT(p));
        printf("%d ", Info(p).key);
    }
}

NodeList *newNodeListElement(ElType val)
{
    NodeList *newNode = (NodeList *)malloc(sizeof(NodeList));
    if (newNode != NULL)
    {
        Info(newNode) = val;
        Next(newNode) = NIL;
    }
    return newNode;
}

NodeList *concat(NodeList *l1, NodeList *l2)
{
    if (l1 == NIL)
    {
        return l2;
    }
    else if (l2 == NIL)
    {
        return l1;
    }
    else
    {
        NodeList *current = l1;
        while (Next(current) != NIL)
        {
            current = Next(current);
        }
        Next(current) = l2;
        return l1;
    }
}

NodeList *makeListPreOrder(BinTree p)
{
    if (isTreeEmpty(p))
    {
        return NIL;
    }

    NodeList *node = newNodeListElement(ROOT(p));
    if (node == NIL)
    {
        return NIL;
    }

    NodeList *leftList = makeListPreOrder(LEFT(p));
    NodeList *rightList = makeListPreOrder(RIGHT(p));

    Next(node) = leftList;
    if (leftList == NIL)
    {
        Next(node) = rightList;
    }
    else
    {
        NodeList *current = leftList;
        while (Next(current) != NIL)
        {
            current = Next(current);
        }
        Next(current) = rightList;
    }

    return node;
}

NodeList *makeListInOrder(BinTree p)
{
    if (isTreeEmpty(p))
    {
        return NIL;
    }

    NodeList *leftList = makeListInOrder(LEFT(p));
    NodeList *node = newNodeListElement(ROOT(p));
    if (node == NIL)
    {
        return NIL;
    }
    NodeList *rightList = makeListInOrder(RIGHT(p));

    if (leftList != NIL)
    {
        NodeList *current = leftList;
        while (Next(current) != NIL)
        {
            current = Next(current);
        }
        Next(current) = node;
    }
    else
    {
        leftList = node;
    }
    Next(node) = rightList;

    return leftList;
}

NodeList *makeListPostOrder(BinTree p)
{
    if (isTreeEmpty(p))
    {
        return NIL;
    }

    NodeList *leftList = makeListPostOrder(LEFT(p));
    NodeList *rightList = makeListPostOrder(RIGHT(p));
    NodeList *node = newNodeListElement(ROOT(p));
    if (node == NIL)
    {
        return NIL;
    }

    NodeList *combined = concat(leftList, rightList);
    if (combined == NIL)
    {
        return node;
    }
    else
    {
        NodeList *current = combined;
        while (Next(current) != NIL)
        {
            current = Next(current);
        }
        Next(current) = node;
        return combined;
    }
}

void printNodeList(NodeList *l)
{
    NodeList *current = l;
    while (current != NULL)
    {
        printf("[%d] -> ", Info(current).key);
        current = Next(current);
    }
    printf("FINISH\n");
}

int rangeSumBST(BinTree p, int L, int R)
{
    int total = 0;
    if (isTreeEmpty(p))
    {
        return total;
    }

    if (ROOT(p).key >= L && ROOT(p).key <= R)
    {
        total += ROOT(p).key;
    }

    if (ROOT(p).key > L)
    {
        total += rangeSumBST(LEFT(p), L, R);
    }

    if (ROOT(p).key < R)
    {
        total += rangeSumBST(RIGHT(p), L, R);
    }

    return total;
}

/**
 * This function calculates the sum of all values in the binary search tree
 * that are within the range [L, R]. It uses an iterative approach with a list
 * to store the nodes in order.
 *
 * @param p The root of the binary search tree.
 * @param L The lower bound of the range.
 * @param R The upper bound of the range.
 * @return The sum of all values within the range [L, R].
 *
 * @deprecated Other method to calculate the sum of all values in the binary search tree (iterative approach with a list).
 */
int rangeSumBST_alt(BinTree p, int L, int R)
{
    if (isTreeEmpty(p))
    {
        return 0;
    }

    int total = 0;
    NodeList *list = makeListInOrder(p);

    NodeList *current = list;
    while (current != NULL)
    {
        if (Info(current).key <= R && Info(current).key >= L)
        {
            total += Info(current).key;
        }
        current = Next(current);
    }

    return total;
}

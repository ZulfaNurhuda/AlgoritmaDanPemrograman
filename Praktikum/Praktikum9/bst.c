#include "bst.h"

Address newTreeNode(ElType x)
{
    Address newNode = (Address)malloc(sizeof(TreeNode));
    if (newNode != NULL)
    {
        ROOT(newNode) = x;
        LEFT(newNode) = NIL;
        RIGHT(newNode) = NIL;
    }
    return newNode;
}

void deallocTreeNode(Address p)
{
    free(p);
    p = NIL;
}

boolean isTreeEmpty(BinTree p)
{
    return (p == NIL);
}

boolean isOneElmt(BinTree p)
{
    return (p != NIL && LEFT(p) == NIL && RIGHT(p) == NIL);
}

boolean isUnerLeft(BinTree p)
{
    return (p != NIL && LEFT(p) != NIL && RIGHT(p) == NIL);
}

boolean isUnerRight(BinTree p)
{
    return (p != NIL && LEFT(p) == NIL && RIGHT(p) != NIL);
}

boolean isBiner(BinTree p)
{
    return (p != NIL && LEFT(p) != NIL && RIGHT(p) != NIL);
}

BinTree buildBalancedTree(int n)
{
    if (n <= 0)
    {
        return NIL;
    }

    int nL = n / 2;
    int nR = n - nL - 1;

    ElType x;
    x.key = nL;
    x.count = 1;

    BinTree tree;
    tree = newTreeNode(x);

    BinTree leftSubtree = buildBalancedTree(nL);
    BinTree rightSubtree = buildBalancedTree(nR);

    LEFT(tree) = leftSubtree;
    RIGHT(tree) = rightSubtree;

    return tree;
}

void insSearchTree(ElType x, BinTree *p)
{
    if (*p == NIL)
    {
        *p = newTreeNode(x);
    }
    else if (x.key == ROOT(*p).key)
    {
        ROOT(*p).count += 1;
    }
    else if (x.key < ROOT(*p).key)
    {
        insSearchTree(x, &LEFT(*p));
    }
    else
    {
        insSearchTree(x, &RIGHT(*p));
    }
}

void delNode(BinTree *p)
{
    Address temp = *p;
    if (RIGHT(*p) != NIL)
    {
        delNode(&RIGHT(*p));
    }
    else
    {
        *p = LEFT(*p);
        deallocTreeNode(temp);
    }
}

void delBTree(BinTree *p, ElType x)
{
    if (*p == NIL)
        return;

    if (x.key < ROOT(*p).key)
    {
        delBTree(&LEFT(*p), x);
    }
    else if (x.key > ROOT(*p).key)
    {
        delBTree(&RIGHT(*p), x);
    }
    else
    {
        if (LEFT(*p) == NIL && RIGHT(*p) == NIL)
        {
            deallocTreeNode(*p);
            *p = NIL;
        }
        else if (LEFT(*p) == NIL)
        {
            Address temp = *p;
            *p = RIGHT(*p);
            deallocTreeNode(temp);
        }
        else if (RIGHT(*p) == NIL)
        {
            Address temp = *p;
            *p = LEFT(*p);
            deallocTreeNode(temp);
        }
        else
        {
            Address temp = findMinimum(RIGHT(*p));
            ROOT(*p).key = ROOT(temp).key;
            ROOT(*p).count = ROOT(temp).count;
            delBTree(&RIGHT(*p), ROOT(*p));
        }
    }
}

Address searchNode(BinTree p, int value)
{
    if (p == NIL || ROOT(p).key == value)
    {
        return p;
    }

    if (value < ROOT(p).key)
    {
        return searchNode(LEFT(p), value);
    }
    else
    {
        return searchNode(RIGHT(p), value);
    }
}

Address findMinimum(BinTree p)
{
    if (p == NIL)
        return NIL;
    while (LEFT(p) != NIL)
    {
        p = LEFT(p);
    }
    return p;
}

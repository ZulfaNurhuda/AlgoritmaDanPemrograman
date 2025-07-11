#include "graphMultiList.h"

void CreateGraph(int x, Graph *g)
{
    FIRST(*g) = NIL;
    AdrNode new = newGraphNode(x);
    if (new != NIL)
    {
        FIRST(*g) = new;
    }
}

AdrNode newGraphNode(int x)
{
    AdrNode new = (AdrNode)malloc(sizeof(Node));
    if (new == NIL)
    {
        return NIL;
    }
    ID(new) = x;
    NPRED(new) = 0;
    TRAIL(new) = NIL;
    NEXTNODE(new) = NIL;
    return new;
}

void deallocGraphNode(AdrNode p)
{
    if (p != NIL)
    {
        free(p);
        p = NIL;
    }
}

AdrSuccNode newSuccNode(AdrNode pn)
{
    AdrSuccNode new = (AdrSuccNode)malloc(sizeof(SuccNode));
    if (new == NIL)
    {
        return NIL;
    }
    SUCC(new) = pn;
    NEXTSUCC(new) = NIL;
    return new;
}

void deallocSuccNode(AdrSuccNode p)
{
    if (p != NIL)
    {
        free(p);
        p = NIL;
    }
}

AdrNode searchNode(Graph g, int x)
{
    AdrNode temp = FIRST(g);
    while (temp != NIL)
    {
        if (ID(temp) == x)
        {
            return temp;
        }
        temp = NEXTNODE(temp);
    }
    return NIL;
}

AdrSuccNode searchEdge(Graph g, int prec, int succ)
{
    AdrNode pred = searchNode(g, prec);
    if (pred == NIL)
    {
        return NIL;
    }

    AdrSuccNode temp = TRAIL(pred);
    while (temp != NIL)
    {
        if (ID(SUCC(temp)) == succ)
        {
            return temp;
        }
        temp = NEXTSUCC(temp);
    }
    return NIL;
}

void insertNode(Graph *g, int x, AdrNode *pn)
{
    if (searchNode(*g, x) != NIL)
    {
        *pn = searchNode(*g, x);
        return;
    }

    *pn = newGraphNode(x);
    if (*pn == NIL)
        return;

    if (FIRST(*g) == NIL)
    {
        FIRST(*g) = *pn;
    }
    else
    {
        AdrNode temp = FIRST(*g);
        while (NEXTNODE(temp) != NIL)
        {
            temp = NEXTNODE(temp);
        }
        NEXTNODE(temp) = *pn;
    }
}

void insertEdge(Graph *g, int prec, int succ)
{
    if (searchEdge(*g, prec, succ) != NIL)
        return;

    AdrNode nPrec = searchNode(*g, prec);
    if (nPrec == NIL)
    {
        insertNode(g, prec, &nPrec);
    }

    AdrNode nSucc = searchNode(*g, succ);
    if (nSucc == NIL)
    {
        insertNode(g, succ, &nSucc);
    }

    AdrSuccNode newEdge = newSuccNode(nSucc);
    if (newEdge == NIL)
        return;

    if (TRAIL(nPrec) == NIL)
    {
        TRAIL(nPrec) = newEdge;
    }
    else
    {
        AdrSuccNode temp = TRAIL(nPrec);
        while (NEXTSUCC(temp) != NIL)
        {
            temp = NEXTSUCC(temp);
        }
        NEXTSUCC(temp) = newEdge;
    }

    NPRED(nSucc)++;
}

void deleteNode(Graph *g, int x)
{
    AdrNode nodeX = searchNode(*g, x);
    if (nodeX == NIL)
    {
        return;
    }

    AdrSuccNode currentSucc = TRAIL(nodeX);
    while (currentSucc != NIL)
    {
        AdrSuccNode tempSucc = currentSucc;
        currentSucc = NEXTSUCC(currentSucc);

        if (SUCC(tempSucc) != NIL)
        {
            NPRED(SUCC(tempSucc))--;
        }
        deallocSuccNode(tempSucc);
    }
    TRAIL(nodeX) = NIL;

    AdrNode P = FIRST(*g);
    while (P != NIL)
    {
        if (P != nodeX)
        {
            AdrSuccNode trailP = TRAIL(P);
            AdrSuccNode prevTrailP = NIL;

            while (trailP != NIL)
            {
                if (SUCC(trailP) == nodeX)
                {
                    AdrSuccNode toDeleteEdge = trailP;
                    if (prevTrailP == NIL)
                    {
                        TRAIL(P) = NEXTSUCC(trailP);
                    }
                    else
                    {
                        NEXTSUCC(prevTrailP) = NEXTSUCC(trailP);
                    }
                    trailP = NEXTSUCC(trailP);
                    deallocSuccNode(toDeleteEdge);
                }
                else
                {
                    prevTrailP = trailP;
                    trailP = NEXTSUCC(trailP);
                }
            }
        }
        P = NEXTNODE(P);
    }

    if (FIRST(*g) == nodeX)
    {
        FIRST(*g) = NEXTNODE(nodeX);
    }
    else
    {
        AdrNode current = FIRST(*g);
        while (current != NIL && NEXTNODE(current) != nodeX)
        {
            current = NEXTNODE(current);
        }
        if (current != NIL)
        {
            NEXTNODE(current) = NEXTNODE(nodeX);
        }
    }

    deallocGraphNode(nodeX);
}

void printGraph(Graph g)
{
    if (FIRST(g) == NIL)
    {
        printf("Graph kosong\n");
        return;
    }

    AdrNode temp = FIRST(g);
    while (temp != NIL)
    {
        printf("%d", ID(temp));
        AdrSuccNode temp2 = TRAIL(temp);
        while (temp2 != NIL)
        {
            printf(" -> %d", ID(SUCC(temp2)));
            temp2 = NEXTSUCC(temp2);
        }
        printf("\n");
        temp = NEXTNODE(temp);
    }
}
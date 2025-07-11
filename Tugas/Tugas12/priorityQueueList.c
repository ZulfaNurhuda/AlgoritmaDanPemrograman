#include "priorityQueueList.h"

Address newNode(ElType x, int pr)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != Nil)
    {
        INFO(p) = x;
        PRIORITY(p) = pr;
        NEXT(p) = Nil;
    }
    return p;
}

void delNode(Address P)
{
    if (P != Nil)
    {
        free(P);
    }
}

bool isEmpty(PriorityQueue q)
{
    return (ADDR_HEAD(q) == Nil);
}

int length(PriorityQueue q)
{
    Address p = ADDR_HEAD(q);
    int count = 0;
    while (p != Nil)
    {
        count++;
        p = NEXT(p);
    }
    return count;
}

void CreateQueue(PriorityQueue *q)
{
    ADDR_HEAD(*q) = Nil;
}

void enqueue(PriorityQueue *q, ElType x, int pr)
{
    Address p = newNode(x, pr);
    if (p != Nil)
    {
        if (isEmpty(*q) || PRIORITY(p) < PRIORITY(ADDR_HEAD(*q)))
        {
            NEXT(p) = ADDR_HEAD(*q);
            ADDR_HEAD(*q) = p;
        }
        else
        {
            Address curr = ADDR_HEAD(*q), prev = Nil;
            while (curr != Nil && PRIORITY(curr) <= PRIORITY(p))
            {
                prev = curr;
                curr = NEXT(curr);
            }
            NEXT(p) = curr;
            NEXT(prev) = p;
        }
    }
}

void dequeue(PriorityQueue *q, ElType *x, int *pr)
{
    Address del = ADDR_HEAD(*q);
    (*x) = INFO(del);
    (*pr) = PRIORITY(del);
    ADDR_HEAD(*q) = NEXT(del);
    delNode(del);
}
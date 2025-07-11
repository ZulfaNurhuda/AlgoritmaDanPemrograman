#include <stdio.h>
#include "tiket_konser.h"

boolean IsEmpty(Queue Q)
{
    return (IDX_HEAD(Q) == IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF);
}

boolean IsFull(Queue Q)
{
    return (IDX_HEAD(Q) == 0 && IDX_TAIL(Q) == IDX_MAX);
}

int Length(Queue Q)
{
    if (IsEmpty(Q)) return 0;
    return (IDX_TAIL(Q) - IDX_HEAD(Q) + 1);
}

void CreateQueue(Queue *Q)
{
    for (int i = 0; i <= IDX_MAX; i++)
    {
        Q->Tab[i].seatNumber = -9999;
    }

    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
}

void enqueue(Queue *Q, ElType P)
{
    if (!isDuplicateSN(*Q, SN(P)) && !IsFull(*Q))
    {
        if (IsEmpty(*Q))
        {
            IDX_HEAD(*Q) = 0;
            IDX_TAIL(*Q) = 0;
            Q->Tab[0] = P;
        }
        else
        {
            int pos = IDX_HEAD(*Q);
            while (pos <= IDX_TAIL(*Q) && QN(Q->Tab[pos]) <= QN(P))
            {
                pos++;
            }

            for (int i = IDX_TAIL(*Q); i >= pos; i--)
            {
                Q->Tab[i + 1] = Q->Tab[i];
            }

            Q->Tab[pos] = P;
            IDX_TAIL(*Q)++;
        }
    }
}

ElType dequeue(Queue *Q)
{
    ElType val = HEAD(*Q);

    if (IDX_HEAD(*Q) == IDX_TAIL(*Q))
    {
        IDX_HEAD(*Q) = IDX_UNDEF;
        IDX_TAIL(*Q) = IDX_UNDEF;
    }
    else
    {
        for (int i = IDX_HEAD(*Q); i < IDX_TAIL(*Q); i++)
        {
            Q->Tab[i] = Q->Tab[i + 1];
        }
        IDX_TAIL(*Q)--;
    }

    return val;
}

ElType peek(Queue Q)
{
    return HEAD(Q);
}

boolean isDuplicateSN(Queue Q, int sn)
{
    boolean isDuplicate = false;
    if (!IsEmpty(Q))
    {
        for (int i = IDX_HEAD(Q); i <= IDX_TAIL(Q); i++)
        {
            if (Q.Tab[i].seatNumber == sn)
                isDuplicate = true;
        }
    }
    return isDuplicate;
}

void displayQueue(Queue q)
{
    printf("[");
    if (!IsEmpty(q))
    {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            printf("(%s-%d-%d)", NAMA(q.Tab[i]), SN(q.Tab[i]), QN(q.Tab[i]));
            if (i != IDX_TAIL(q))
                printf(", ");
        }
    }
    printf("]\n");
}
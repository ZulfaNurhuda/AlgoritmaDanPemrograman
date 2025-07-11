#include "stack.h"

void CreateStack(Stack *s)
{
    IDX_TOP(*s) = IDX_UNDEF;
}

boolean isEmpty(Stack s)
{
    return IDX_TOP(s) == IDX_UNDEF;
}

boolean isFull(Stack s)
{
    return IDX_TOP(s) == CAPACITY - 1;
}

int length(Stack s)
{
    return IDX_TOP(s) + 1;
}

void push(Stack *s, ElType val)
{
    if (!isFull(*s))
    {
        IDX_TOP(*s)++;
        TOP(*s) = val;
    }
}

void pop(Stack *s, ElType *val)
{
    if (!isEmpty(*s))
    {
        (*val) = TOP(*s);
        IDX_TOP(*s)--;
    }
}

void copyStack(Stack *sres, Stack s)
{
    Stack temp;
    CreateStack(sres);
    CreateStack(&temp);

    while (!isEmpty(s))
    {
        ElType val;
        pop(&s, &val);
        push(&temp, val);
    }

    while (!isEmpty(temp))
    {
        ElType val;
        pop(&temp, &val);
        push(sres, val);
        push(&s, val);
    }
}

void reverseStack(Stack *s)
{
    Stack temp;
    CreateStack(&temp);

    while (!isEmpty(*s))
    {
        ElType val;
        pop(s, &val);
        push(&temp, val);
    }

    (*s) = temp;
}

void mergeStack(Stack *sres, Stack *s1, Stack *s2)
{
    Stack temp1, temp2;
    CreateStack(sres);
    CreateStack(&temp1);
    CreateStack(&temp2);

    copyStack(&temp1, *s1);
    copyStack(&temp2, *s2);
    
    reverseStack(&temp1);
    reverseStack(&temp2);

    while (!isEmpty(temp1))
    {
        ElType val;
        pop(&temp1, &val);
        push(sres, val);
    }

    while (!isEmpty(temp2))
    {
        ElType val;
        pop(&temp2, &val);
        push(sres, val);
    }
}

void printStack(Stack s)
{
    if (isEmpty(s))
    {
        printf("Stack: EMPTY\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= IDX_TOP(s); i++)
        {
            printf("%d", s.buffer[i]);
            if (i < IDX_TOP(s))
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
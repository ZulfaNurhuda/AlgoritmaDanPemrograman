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
    return IDX_TOP(s) == (CAPACITY - 1);
}

int length(Stack s)
{
    return IDX_TOP(s) + 1;
}

void push(Stack *s, ElType val)
{
    if (!isFull(*s))
    {
        s->buffer[++IDX_TOP(*s)] = val;
    }
}

void pop(Stack *s, ElType *val)
{
    *val = TOP(*s);
    --IDX_TOP(*s);
}

void SortirStack(Stack *S1, Stack *S2)
{
    int s1_length = length(*S1);

    for (int i = 0; i < s1_length; i++)
    {
        ElType currentValue;
        pop(S1, &currentValue);

        int tempCount = 0;

        while (!isEmpty(*S2) && currentValue < TOP(*S2))
        {
            ElType tempValue;
            pop(S2, &tempValue);
            push(S1, tempValue);
            tempCount++;
        }

        push(S2, currentValue);

        for (int j = 0; j < tempCount; j++)
        {
            ElType tempValue;
            pop(S1, &tempValue);
            push(S2, tempValue);
        }
    }
}

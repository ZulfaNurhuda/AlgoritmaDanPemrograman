#include "hashmap.h"

void CreateEmpty(HashMap *M)
{
    M->Count = 0;
    for (int i = 0; i < MaxEl; i++)
    {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
}

address Hash(keytype K)
{
    return K % MaxEl;
}

valuetype Value(HashMap M, keytype k)
{
    address addr = Hash(k);
    int attempts = 0;

    while (attempts < MaxEl && M.Elements[addr].Key != k && M.Elements[addr].Key != Undefined)
    {
        addr = (addr + 1) % MaxEl;
        attempts++;
    }

    return (M.Elements[addr].Key == k) ? M.Elements[addr].Value : Undefined;
}

void Insert(HashMap *M, keytype k, valuetype v)
{
    if (M->Count >= MaxEl)
        return;

    address addr = Hash(k);
    int attempts = 0;

    while (attempts < MaxEl && M->Elements[addr].Key != k && M->Elements[addr].Key != Undefined)
    {
        addr = (addr + 1) % MaxEl;
        attempts++;
    }

    if (M->Elements[addr].Key == k)
        return;

    if (attempts < MaxEl && M->Elements[addr].Key == Undefined)
    {
        M->Elements[addr].Key = k;
        M->Elements[addr].Value = v;
        M->Count++;
    }
}

void printHashMap(HashMap M)
{
    for (int i = 0; i < MaxEl; i++)
    {
        printf("%d:\n  Key: %d\n  Value: %d\n", i, M.Elements[i].Key, M.Elements[i].Value);
    }
}

void Delete(HashMap *M, keytype k)
{
    address addr = Hash(k);
    int attempts = 0;

    while (attempts < MaxEl && M->Elements[addr].Key != k && M->Elements[addr].Key != Undefined)
    {
        addr = (addr + 1) % MaxEl;
        attempts++;
    }

    if (M->Elements[addr].Key == k)
    {
        M->Elements[addr].Key = Undefined;
        M->Elements[addr].Value = Undefined;
        M->Count--;
    }
}
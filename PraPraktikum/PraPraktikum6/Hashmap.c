#include "Hashmap.h" // OR: #include "hashmap.h"

void CreateEmpty(HashMap *M)
{
    M->Count = 0;
    for (int i = 0; i < MaxEl; i++)
    {
        M->Elements[i].key = Undefined;
        M->Elements[i].value = Undefined;
    }
}

address Hash(keytype K)
{
    return K % MaxEl;
}

void Insert(HashMap *map, keytype key, valuetype value)
{
    address idx = Hash(key);
    int attempts = 0;

    while (attempts < MaxEl && map->Elements[idx].key != Undefined)
    {
        idx = (idx + 1) % MaxEl;
        attempts++;
    }

    if (attempts < MaxEl)
    {
        map->Elements[idx].key = key;
        map->Elements[idx].value = value;
        map->Count++;
    }
}

valuetype Value(HashMap M, keytype key)
{
    address idx = Hash(key);
    int attempts = 0;

    while (attempts < MaxEl && M.Elements[idx].key != key)
    {
        idx = (idx + 1) % MaxEl;
        attempts++;
    }

    return (M.Elements[idx].key == key) ? M.Elements[idx].value : Undefined;
}

void printHashMap(HashMap M)
{
    for (int i = 0; i < MaxEl; i++)
    {
        printf("%d:\n  Key: %d\n  Value: %d\n", i, M.Elements[i].key, M.Elements[i].value);
    }
}

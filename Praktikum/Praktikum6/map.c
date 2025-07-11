#include "map.h"
#include <stdio.h>

int binary_search(const Map *map, int key, bool *found)
{
    *found = false;

    int left = 0;
    int right = map->size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (map->entries[mid].key == key)
        {
            *found = true;
            return mid;
        }
        else if (map->entries[mid].key < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

Map *create_map(int capacity)
{
    Map *map = (Map *)malloc(sizeof(Map));
    if (!map)
    {
        return NULL;
    }

    map->entries = (MapEntry *)malloc(capacity * sizeof(MapEntry));
    if (!map->entries)
    {
        free(map);
        return NULL;
    }

    map->capacity = capacity;
    map->size = 0;
    return map;
}

bool map_insert(Map *map, int key, const char *value)
{
    if (map->size >= map->capacity)
    {
        return false;
    }

    bool isFound = false;
    int idx = binary_search(map, key, &isFound);

    if (isFound)
    {
        free(map->entries[idx].value);
        map->entries[idx].value = (char *)malloc(strlen(value) + 1);
        if (!map->entries[idx].value)
        {
            return false;
        }
        strcpy(map->entries[idx].value, value);
        return true;
    }

    for (int i = map->size; i > idx; i--)
    {
        map->entries[i] = map->entries[i - 1];
    }

    map->entries[idx].key = key;
    map->entries[idx].value = (char *)malloc(strlen(value) + 1);
    if (!map->entries[idx].value)
    {
        for (int i = idx; i < map->size; i++)
        {
            map->entries[i] = map->entries[i + 1];
        }
        return false;
    }
    strcpy(map->entries[idx].value, value);
    map->size++;
    return true;
}

char *map_get(const Map *map, int key)
{
    bool isFound = false;
    int idx = binary_search(map, key, &isFound);
    return isFound ? map->entries[idx].value : NULL;
}

bool map_delete(Map *map, int key)
{
    bool isFound = false;
    int idx = binary_search(map, key, &isFound);

    if (!isFound)
    {
        return false;
    }

    free(map->entries[idx].value);
    for (int i = idx; i < map->size - 1; i++)
    {
        map->entries[i] = map->entries[i + 1];
    }
    map->size--;

    map->entries[map->size].key = 0;
    map->entries[map->size].value = NULL;

    return true;
}

int map_size(const Map *map)
{
    return (map && map->entries) ? map->size : 0;
}

bool map_contains_key(const Map *map, int key)
{
    bool isFound = false;
    binary_search(map, key, &isFound);
    return isFound;
}
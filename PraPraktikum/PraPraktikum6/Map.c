#include "Map.h" // OR #include "map.h"
#include <stdio.h>

Map *create_map(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }

    Map *map = (Map *)malloc(sizeof(Map));
    if (map == NULL)
    {
        return NULL;
    }

    map->entries = (MapEntry *)malloc(sizeof(MapEntry) * capacity);
    if (map->entries == NULL)
    {
        free(map);
        return NULL;
    }

    map->capacity = capacity;
    map->size = 0;

    for (int i = 0; i < capacity; i++)
    {
        map->entries[i].key = -1;
        map->entries[i].value = NULL;
    }

    return map;
}

bool map_insert(Map *map, int key, const char *value)
{
    bool inserted = false;
    int i = 0;

    while (i < map->size && !inserted)
    {
        if (map->entries[i].key == key)
        {
            char *new_value = (char *)malloc(strlen(value) + 1);
            if (new_value == NULL)
            {
                return NULL;
            }

            strcpy(new_value, value);

            free(map->entries[i].value);
            map->entries[i].value = new_value;

            inserted = true;
        }
        else
        {
            i++;
        }
    }

    if (!inserted && map->size < map->capacity)
    {
        char *new_value = (char *)malloc(strlen(value) + 1);
        if (new_value == NULL)
        {
            return NULL;
        }

        strcpy(new_value, value);

        map->entries[map->size].key = key;
        map->entries[map->size].value = new_value;
        map->size++;

        inserted = true;
    }

    return inserted;
}

char *map_get(const Map *map, int key)
{
    char *result = NULL;

    int i = 0;

    while (i < map->size && result == NULL)
    {
        if (map->entries[i].key == key)
        {
            result = map->entries[i].value;
        }
        else
        {
            i++;
        }
    }

    return result;
}

bool map_delete(Map *map, int key)
{
    bool deleted = false;
    int i = 0;

    while (i < map->size && !deleted)
    {
        if (map->entries[i].key == key)
        {
            free(map->entries[i].value);

            for (int j = i; j < map->size - 1; j++)
            {
                map->entries[j] = map->entries[j + 1];
            }

            map->entries[map->size - 1].key = -1;
            map->entries[map->size - 1].value = NULL;
            map->size--;

            deleted = true;
        }
        else
        {
            i++;
        }
    }

    return deleted;
}

int map_size(const Map *map)
{
    return map->size;
}

bool map_contains_key(const Map *map, int key)
{
    bool found = false;
    int i = 0;

    while (i < map->size && !found)
    {
        if (map->entries[i].key == key)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    return found;
}
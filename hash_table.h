#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define _assert(cond, msg) \
    do { \
        if (!(cond)) { \
            fprintf(stderr, "Assertion failed: %s\n", msg); \
            fprintf(stderr, "In file %s, line %d\n", __FILE__, __LINE__); \
            abort(); \
        } \
    } while (0)

struct hash_entry {
    void*   key;
    void*   value;
};

struct hash_table {
    int                 size;
    int                 count;
    struct hash_entry** entries;
};

struct hash_entry* new_entry(const void* key, void* (*alloc_key)(void*), const void* value, void* (*alloc_value)(void*));



#endif

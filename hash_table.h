#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>
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
    const char*   key;
    const char*   value;
};

struct hash_table {
    size_t              size;
    size_t              count;
    struct hash_entry** entries;
};

struct hash_entry* new_entry(const char* key, const char* value);
struct hash_table* new_hash_table( void );

void free_entry(struct hash_entry* entry);
void free_hash_table(struct hash_table* ht);

// mad technic: Multiply Add Divide 
size_t hash(const char* str, size_t table_size);
size_t string_to_int(const char* str);


#endif

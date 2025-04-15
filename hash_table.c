#include "hash_table.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct hash_entry* new_entry(const char* key, const char* value) {
    _assert(key != NULL, "key can't be null");
    _assert(value != NULL, "value can't be null");

    char* _key = strdup(key);
    if (!_key) {
        return NULL;
    }

    char* _value = strdup(value);
    if (!_value) {
        return NULL;
    }

    struct hash_entry* entry = (struct hash_entry*) malloc(sizeof(struct hash_entry));
    if (!entry) {
        return NULL;
    }

    entry->key = _key;
    entry->value = _value;

    return entry;
}

struct hash_table* new_hash_table( void ) {
    struct hash_table* ht = malloc(sizeof(struct hash_table));
    if (ht == NULL) {
        fprintf(stderr, "error allocating memory\n");
        return NULL;
    }

    ht->count = 0;
    ht->size = 101;

    ht->entries = calloc(ht->size, sizeof(struct hash_table*));
    if (ht->entries == NULL) {
        fprintf(stderr, "error allocating memory\n");
        return NULL;
    }
    return ht;
}

void free_entry(struct hash_entry* entry) {
    _assert(entry != NULL, "error: entry is null");
    free((void*)entry->key);
    free((void*)entry->value);
    free(entry);
}

void free_hash_table(struct hash_table* ht) {
    _assert(ht != NULL, "error: hash table is null");

    for (size_t i = 0; i < ht->size; ++i) {
        if (ht->entries[i] != NULL) {
            free_entry(ht->entries[i]);
        }
    }
    free(ht->entries);
    free(ht);
}

size_t string_to_int(const char *str) {
    _assert(str != NULL, "string shouldn't be null");

    int c;
    size_t hash = 0;

    // Prime number
    const int BASE_PRIME_NBR = 31;

    while((c = *str++)) {
        hash = (hash * BASE_PRIME_NBR + c);
    }
    return hash;
}

size_t hash(const char* str, size_t size) {
    size_t key = string_to_int(str);
    size_t LARGE_PRIME_NUMBER = 100000007;
    size_t MULTIPLIER_COEFFICIENT_PRIME = 99999971;
    size_t SHIFT_PRIME_NUMBER = 16777619;

    return ((size_t)(MULTIPLIER_COEFFICIENT_PRIME * key + SHIFT_PRIME_NUMBER) % LARGE_PRIME_NUMBER) % size;
}

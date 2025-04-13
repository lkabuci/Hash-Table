#include "hash_table.h"

struct hash_entry* new_entry(const void* key, void* (*alloc_key)(void*), const void* value, void* (*alloc_value)(void*)) {
    _assert(key != NULL, "key can't be null");
    _assert(value != NULL, "value can't be null");

    void* _key = alloc_key((void*)key);
    if (!_key) {
        return NULL;
    }

    void* _value = alloc_value((void*)value);
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


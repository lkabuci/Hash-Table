#include "hash_table.h"
#include <stdio.h>


int main(int argc, char *argv[]) {
    struct hash_entry* entry = new_entry("key","Hello World");
    printf("%s: \"%s\"", entry->key, (char*)entry->value);
    free_entry(entry);

    struct hash_table* dict = new_hash_table();
    free_hash_table(dict);

    char* str = "Redouane";
    char* str2 = "Imane";
    printf("%zu\n", hash(str, 101));
    printf("%zu\n", hash(str2, 101));

    return 0;
}

#include "hash_table.h"

void* alloc_int(void *nbr_ptr) {
    int* nbr = malloc(sizeof(int));
    nbr = (int*)nbr_ptr;
    printf("%d\n", *nbr);
    return nbr;
}

void* alloc_str(void *str_ptr) {
    return (void*)strdup((char*)str_ptr);
}

int main(int argc, char *argv[]) {
    int nbr = 42;
    struct hash_entry* entry = new_entry((void*)&nbr, alloc_int, "Hello World", alloc_str);
    printf("%d: \"%s\"", *(int*)(entry->key), (char*)entry->value);
    return 0;
}

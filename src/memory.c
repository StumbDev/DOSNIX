#include "memory.h"
#include <stdlib.h>

void *allocate_memory(unsigned int size) {
    return malloc(size);
}

void free_memory(void *ptr) {
    free(ptr);
}

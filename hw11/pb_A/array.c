#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct _array {
  size_t capacity; /* elements allocated */
  size_t inUse;    /* elements currently in use */
  void ** data;    /* actual data */
};

array * newArray(void) {
  array * a;
  a = (array *) malloc(sizeof(array));
  if (!a) return NULL;
  a->capacity = 1; /* parsimonious */
  a->inUse = 0;
  a->data = (void **) malloc(sizeof(void *) * a->capacity);
  if (!a->data) {
    free(a);
    return NULL;
  }
  return a;
}

void deleteArray(array * a) {
  if (a) {
    free(a->data);
    free(a);
  }
}

int resizeArray(array * a, size_t newSize) {
  if (!a) return -1;
  if (newSize > a->capacity) {
    /* To avoid too many calls to realloc, we choose the larger of
     * twice the current size and the new requested size. */
    size_t newCapacity = 2 * a->capacity;
    if (newCapacity < newSize)
      newCapacity = newSize;
    void ** tmp = (void **) realloc(a->data, newCapacity * sizeof(void *));
    /* If the allocation fails, leave the array alone. */
    if (!tmp) return -1;
    a->data = tmp;
    a->capacity = newCapacity;
  }
  /* Here we are guaranteed that newSize <= a->capacity. */
  a->inUse = newSize;
  return 0;
}

int arrayNum(array const * a, size_t * num) {
  if (!a || !num) return -1;
  *num = a->inUse;
  return 0;
}

int arrayGet(array const * a, size_t index, void ** e) {
  if (!a || !e || index >= a->inUse) return -1;
  *e = a->data[index];
  return 0;
}

int arrayPushBack(array * a, void * e) {
  if (!a) return -1;
  if (resizeArray(a, a->inUse + 1)) return -1;
  /* Now we have space. */
  a->data[a->inUse-1] = e;
  return 0;
}

int arrayPut(array * a, size_t index, void * e) {
  if (!a || index >= a->inUse) return -1;
  a->data[index] = e;
  return 0;
}

int printArray(array const * a, printFn f) {
  if(!a || !f) return -1;
  size_t b;
  for(b = 0; b < a->inUse; b++) {
    printf("%zu: ",b);
    f(a->data[b]);
    printf("\n");
  }
  return 0;
}

int sortArray(array * a, compareFn f) {
  if (!a || !f) return -1;
  qsort(a->data, a->inUse, sizeof(void *), f);
  return 0;
}

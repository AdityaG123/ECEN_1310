#include <stdio.h>
#include <assert.h>
#include <complex.h>
#include <stdlib.h>
#include "array.h"

void printLong(void const * e);
void printChar(void const * e);
int compareChar(void const * x, void const * y);

int main(void) {
  int err;
  void * e;
  double complex * cnum;
  size_t i, asize;
  array * a;

  a = newArray();
  assert(a);
  err = arrayPushBack(a, (void *) 1L); assert(!err);
  err = arrayPushBack(a, (void *) 2L); assert(!err);
  err = arrayPushBack(a, (void *) 0L); assert(!err);
  err = arrayGet(a, 0, &e); assert(!err);
  printf("a(0) = %ld (1)\n", (long) e);
  err = arrayGet(a, 1, &e); assert(!err);
  printf("a(1) = %ld (2)\n", (long) e);
  err = arrayGet(a, 2, &e); assert(!err);
  printf("a(2) = %ld (0)\n", (long) e);
  err = arrayPut(a, 0, (void *) 3L); assert(!err);
  err = arrayGet(a, 0, &e); assert(!err);
  printf("a(0) = %ld (3)\n", (long) e);
  deleteArray(a);

  a = newArray();
  assert(a);
  err = resizeArray(a, 3); assert(!err);
  err = arrayPut(a, 0, (void *) 1L); assert(!err);
  err = arrayPut(a, 1, (void *) 2L); assert(!err);
  err = arrayPut(a, 2, (void *) 0L); assert(!err);
  err = arrayGet(a, 0, &e); assert(!err);
  printf("a(0) = %ld (1)\n", (long) e);
  err = arrayGet(a, 1, &e); assert(!err);
  printf("a(1) = %ld (2)\n", (long) e);
  err = arrayGet(a, 2, &e); assert(!err);
  printf("a(2) = %ld (0)\n", (long) e);
  err = arrayPut(a, 0, (void *) 3L); assert(!err);
  err = arrayGet(a, 0, &e); assert(!err);
  printf("a(0) = %ld (3)\n", (long) e);
  printf("(Expecting 0:3 1:2 2:0) ");
  err = printArray(a, printLong); assert(!err);
  deleteArray(a);

  /* Test with elements that do not fit into the space used for
   * a void * (double complex).  We need to allocate memory and
   * then free it. */
  a = newArray();
  assert(a);
  for (i = 1; i <= 4; i++) {
    cnum = (double complex *) malloc(sizeof(double complex));
    assert(cnum);
    *cnum = (double) i + I*1;
    err = arrayPushBack(a, cnum); assert(!err);
  }
  err = arrayNum(a, &asize); assert(!err);
  for (i = 0; i < asize; i++) {
    err = arrayGet(a, i, &e); assert(!err);
    cnum = (double complex *) e;
    printf("a(%zu) = %g + i%g (%zu + i1)\n",
           i, creal(*cnum), cimag(*cnum), i+1);
    free(cnum);
  }
  deleteArray(a);

  /* Test with small data (characters). */
  a = newArray();
  assert(a);
  err = arrayPushBack(a, (void *) (long) 'a'); assert(!err);
  err = arrayPushBack(a, (void *) (long) 'd'); assert(!err);
  err = arrayPushBack(a, (void *) (long) 'c'); assert(!err);
  err = arrayPushBack(a, (void *) (long) 'b'); assert(!err);
  err = arrayGet(a, 0, &e); assert(!err);
  printf("a(0) = %c (a)\n", (char) (long) e);
  err = sortArray(a, compareChar); assert(!err);
  printf("(Expecting 0:a 1:b 2:c 3:d) ");
  err = printArray(a, printChar); assert(!err);
  deleteArray(a);

  /* Miscellaneous tests. */
  err = arrayGet(NULL, 0, &e); assert(err);

  a = newArray();
  assert(a);
  err = resizeArray(a, 2); assert(!err);
  err = arrayGet(a, 3, &e); assert(err);
  err = arrayPut(a, 3, (void *) 3L); assert(err);
  err = arrayPushBack(a, (void *) 3L); assert(!err);
  arrayGet(a, 2, &e);
  printf("a(2) = %ld (3)\n", (long) e);
  err = arrayGet(a, 0, NULL); assert(err);
  deleteArray(a);

  return 0;
}

void printLong(void const * e) {
  long l = (long) e;
  printf("%ld ", l);
}

void printChar(void const * e) {
  char c = (char) (long) e;
  printf("%c ", c);
}

int compareChar(void const * x, void const * y) {
  int a = * (char const *) x;
  int b = * (char const *) y;
  return a - b;
}

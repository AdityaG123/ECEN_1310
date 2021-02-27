#include <assert.h>
#include <stdio.h>

#include "llist.h"

static void printLong(void const * e);
static void printString(void const * e);
static void basicTest(void);
static void testZip(void);

int main(void) {
  basicTest();
  testZip();
  return 0;
}

static void printLong(void const * e) {
  printf("%ld", (long) e);
}

static void printString(void const * e) {
  printf("%s", (char *) e);
}

static void basicTest(void) {
  llist * longl, * stringl;
  void * e;
  int err;

  /* test with longs */
  longl = newLList();

  assert(isEmptyLList(longl));

  printf("longl (empty): ");
  printLList(longl, printLong);

  err = putLList(longl, (void *) 1); assert(!err);
  err = putLList(longl, (void *) 2); assert(!err);
  err = putLList(longl, (void *) 3); assert(!err);
  err = putLList(longl, (void *) 4); assert(!err);

  printf("longl (4 elements): ");
  err = printLList(longl, printLong); assert(!err);

  err = getLList(longl, &e); assert(!err);
  printf("from longl (4): %ld\n", (long) e);
  err = getLList(longl, &e); assert(!err);
  printf("from longl (3): %ld\n", (long) e);
  err = getLList(longl, &e); assert(!err);
  printf("from longl (2): %ld\n", (long) e);
  err = getLList(longl, &e); assert(!err);
  printf("from longl (1): %ld\n", (long) e);

  assert(isEmptyLList(longl));
  err = getLList(longl, &e); assert(err);
  assert(!e);

  deleteLList(longl);

  /* test with strings */

  stringl = newLList();
  assert(isEmptyLList(stringl));

  printf("stringl (empty): ");
  printLList(stringl, printString);

  err = putLList(stringl, "Hello"); assert(!err);
  err = putLList(stringl, "there"); assert(!err);
  err = putLList(stringl, "universe"); assert(!err);
  err = putLList(stringl, "!"); assert(!err);

  printf("stringl (4 elements): ");
  err = printLList(stringl, printString); assert(!err);

  err = getLList(stringl, &e); assert(!err);
  printf("from stringl (!): %s\n", (char *) e);
  err = getLList(stringl, &e); assert(!err);
  printf("from stringl (universe): %s\n", (char *) e);
  err = getLList(stringl, &e); assert(!err);
  printf("from stringl (there): %s\n", (char *) e);
  err = getLList(stringl, &e); assert(!err);
  printf("from stringl (Hello): %s\n", (char *) e);

  assert(isEmptyLList(stringl));
  err = getLList(stringl, &e); assert(err);
  assert(!e);

  deleteLList(stringl);
}

static void testZip(void) {
  llist * ll1, * ll2, * ll3;
  int err;
  long i; /* payload type */

  printf("------ zipping ------\n");
  /* Create ll1 with elements [0, 1, 2]. */
  ll1 = newLList();
  for (i = 0; i < 3; i++) {
    err = putLList(ll1, (void *) i); assert(!err);
  }
  printf("ll1:");
  printLList(ll1, printLong);

  /* Create ll2 with elements [3, 4, 5, 6, 7]. */
  ll2 = newLList();
  for (; i < 8; i++) {
    err = putLList(ll2, (void *) i); assert(!err);
  }
  printf("ll2:");
  printLList(ll2, printLong);

  /* Create empty list ll3. */
  ll3 = newLList();
  assert(isEmptyLList(ll3));

  /* Zip back and forth. */

  err = zip(ll1, ll2, ll3); assert(!err);
  printf("ll3:");
  printLList(ll3, printLong);
  assert(isEmptyLList(ll1));
  assert(isEmptyLList(ll2));
  /* Zipping with an empty list moves a list to the destination. */
  err = zip(ll1, ll3, ll2); assert(!err);
  printf("ll2:");
  printLList(ll2, printLong);
  assert(isEmptyLList(ll1));
  assert(isEmptyLList(ll3));
  /* Using the same list for both input arguments
   * moves it to the destination. */
  err = zip(ll2, ll2, ll3); assert(!err);
  printf("ll3:");
  printLList(ll3, printLong);
  assert(isEmptyLList(ll1));
  assert(isEmptyLList(ll2));
  deleteLList(ll3);

  /* Invalid input.  Here ll1, ll2, and ll3 are empty. */
  ll3 = newLList();
  err = zip(NULL, ll2, ll3); assert(err);
  err = zip(ll1, NULL, ll3); assert(err);
  err = zip(ll1, ll2, NULL); assert(err);
  err = zip(ll1, ll2, ll1); assert(err);
  err = zip(ll1, ll2, ll2); assert(err);
  err = putLList(ll3, (void *) 0L); assert(!err);
  err = zip(ll1, ll2, ll3); assert(err);
  deleteLList(ll3);

  deleteLList(ll1);
  deleteLList(ll2);
}

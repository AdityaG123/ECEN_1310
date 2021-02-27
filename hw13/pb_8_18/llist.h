#ifndef LLIST_H_
#define LLIST_H_

/* Define the ADT of singly-linked lists. */

/* The type declaration of the ADT. */
typedef struct _llist llist;

/* Type of functions to be applied to each element. */
typedef void (* foreachFn)(void * e);

/* Type of user-provided printing function. */
typedef void (* printFn)(void const * e);

/* Type of functions to compare pairs of elements. */
typedef int (* compareFn)(void const * e1, void const * e2);

/* Type of functions to test predicate on elements. */
typedef int (* llistPred)(void const * e);

/* Returns a new linked list. */
llist * newLList(void);

/* Deletes a linked list.  Before deletion, it applies f to
 * each element of the queue. */
void deleteLList(llist * ll);

/* Returns whether ll is empty -- 1 (true) or 0 (false). */
int isEmptyLList(llist const * ll);

/* Adds element e to the front of the linked list.  Returns 0
 * if successful and -1 if e could not be added to ll because
 * ll is full. */
int putLList(llist * ll, void * e);

/* Sets e to point to the first element of ll and removes
 * the element from ll.  Returns 0 if successful and -1 if e
 * is NULL.  If ll is empty, returns -2 and sets *e to NULL. */
int getLList(llist * ll, void ** e);

/* Sets e to point to the first element of ll, but does not remove
 * the element from ll.  Returns 0 if successful and -1 if e
 * is NULL.  If ll is empty, returns -2 and sets *e to NULL. */
int peekLList(llist const * ll, void ** e);

/* Prints the elements of ll in order.  Requires a printFn,
 * a user-provided function that prints an element.
 * Returns 0 if successful and -1 if f is NULL. */
int printLList(llist const * ll, printFn f);

/* Zips together the lists ll1 and ll2.  For example,
 * if ll1 is [0, 1, 2] and ll2 is [3, 4, 5, 6, 7],
 * then after running, ll3 will be [0, 3, 1, 4, 2, 5, 6, 7],
 * and both ll1 and ll2 will be empty.  Return 0 if successful
 * and -1 if passed a NULL pointer, a non-empty ll3 or an
 * output list that is one of the two input lists.
 */
int zip(llist * ll1, llist * ll2, llist * ll3);

#endif

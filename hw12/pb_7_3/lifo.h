#ifndef LIFO_H_
#define LIFO_H_

/* Define the ADT of Last-In First-Out queues. */

/* The type declaration of the ADT. */
typedef struct _lifo lifo;

/* Returns a new lifo with the given maximum capacity. */
lifo * newLifo(int capacity);

/* Deletes a lifo. */
void deleteLifo(lifo * q);

/* Returns whether q is empty -- 1 (true) or 0 (false). */
int isEmptyLifo(lifo const * q);

/* Adds element e to q.  Returns 0 if successful and -1 if
 * e could not be added to q because q is full.
 */
int putLifo(lifo * q, void * e);

/* Sets e to point to the first element of q and removes
 * the element from q.  Returns 0 if successful and -1 if e
 * is NULL.  If q is empty, returns -2 and sets *e to NULL.
 */
int getLifo(lifo * q, void ** e);

/* Returns the number of items in the queue. */
int sizeLifo(lifo const * q);

/* Specification of user-provided printing function */
typedef void (* printFn)(void const *);

/* Prints the elements of q in order.  Requires a printFn,
 * a user-provided function that prints an element.
 * Returns 0 if successful and -1 if f is NULL.
 */
int printLifo(lifo const * q, printFn f);

/* Performs the same as the getLifo function without removing
 * the data from the LIFO queue. Returns 0 if successful, -1 if
 * e or q is NULL, or -2 and sets e to NULL if q is full.
 */
int peekLifo(lifo const * q, void ** e);

#endif

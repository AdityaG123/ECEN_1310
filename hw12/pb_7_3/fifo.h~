#ifndef FIFO_H_
#define FIFO_H_

/* Define the ADT of First-In First-Out queues. */

/* The type declaration of the ADT. */
typedef struct _fifo fifo;

/* Returns a new fifo with the given maximum capacity. */
fifo * newFifo(int capacity);

/* Deletes a fifo. */
void deleteFifo(fifo * q);

/* Returns whether q is empty -- 1 (true) or 0 (false). */
int isEmptyFifo(fifo const * q);

/* Adds element e to q.  Returns 0 if successful and -1 if
 * e could not be added to q because q is full.
 */
int putFifo(fifo * q, void * e);

/* Sets e to point to the first element of q and removes
 * the element from q.  Returns 0 if successful and -1 if e
 * is NULL.  If q is empty, returns -2 and sets *e to NULL.
 */
int getFifo(fifo * q, void ** e);

/* Returns the number of items in the queue. */
int sizeFifo(fifo const * q);

/* Specification of user-provided printing function */
typedef void (* printFn)(void const *);

/* Prints the elements of q in order.  Requires a printFn,
 * a user-provided function that prints an element.
 * Returns 0 if successful and -1 if f is NULL.
 */
int printFifo(fifo const * q, printFn f);

#endif

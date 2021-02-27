#include <stdio.h>
#include <stdlib.h> /* for realloc, free, and qsort */

/*
 * Read integers from stdin until EOF.  Then
 * print the median of the numbers read.
 */

/*
 * Print the median of a sequence of sorted integers.
 */
void printMedian(int const * numbers, int cnt) {
  int i, halfWay;
  double median;
  /* debugging printout of sorted array */
  for (i = 0; i < cnt; i++) {
    printf("%d%c", numbers[i], i == cnt-1 ? '\n' : ' ');
  }
  halfWay = cnt / 2;
  if (halfWay * 2 == cnt) {
    /* cnt is even: average two middle numbers */
    median = 0.5 * (numbers[halfWay] + numbers[halfWay-1]);
  } else {
    /* cnt is odd: take middle number */
    median = numbers[halfWay];
  }
  printf("Median of %d integers: %g\n", cnt, median);
}

/* Integer comparison function for qsort. */
static int icompare(void const * x, void const * y) {
  int ix = * (int const *) x;
  int iy = * (int const *) y;
  return ix - iy;
}

int main(void) {
  /* Size of allocated array. */
  size_t size = 0;
  /* Number of ints stored in the array.  Must be less
   * than or equal to size at all times. */
  size_t cnt = 0;
  /* Pointer to dynamically allocated array. */
  int * numbers = 0;
  /* Variables used by scanf. */
  int num, ret;
  while ((ret = scanf("%d", &num)) != EOF) {
    if(ret != 1) {
      printf("Read non-integer. Check input.\n");
      return -1;
    }
    if(size == cnt) {
      size = size * 2 + 1;
      numbers = realloc(numbers,size*(sizeof(int)));
      if(!numbers) {
	free(numbers);
	printf("Memory allocation failed.");
	return -1;
      }
    }
    numbers[cnt] = num;
    cnt++;
  }
  if (!numbers) {
    printf("Read no integers.  Median undefined.\n");
    return -1;
  }
  /* Sort numbers in ascending order. */
  qsort(numbers, cnt, sizeof(int), icompare);
  printMedian(numbers, cnt);
  free(numbers);
  return 0;
}

#include <stdio.h>
#include "array.h"

/* Compute and print the median of a sorted array. */
void printMedian(array const * numbers);
/* Integer comparison function for sortArray. */
static int icompare(void const * x, void const * y);

int main(void) {
  int num, ret;
  size_t cnt;
  array * numbers =  newArray();
  if (!numbers) return -1;
  while ((ret = scanf("%d", &num)) != EOF) {
    if (ret != 1) {
      printf("Expected an integer.\n");
      deleteArray(numbers);
      return -1;
    }
    ret = arrayPushBack(numbers, (void*)(long) num);
    if(ret) {deleteArray(numbers); return -1;}
  }
  ret = arrayNum(numbers, &cnt);
  if (ret) {
    deleteArray(numbers);
    return -1;
  }
  if (cnt == 0) {
    printf("Read no integers.  Median undefined.\n");
    deleteArray(numbers);
    return -1;
  }
  ret = sortArray(numbers, icompare);
  if (!ret)
    printMedian(numbers);
  deleteArray(numbers);
  return ret;
}

static void printInt(void const * e) {
  printf("%d ", (int) (long) e);
}

void printMedian(array const * numbers) {
  double median;
  size_t halfWay, cnt;
  void * e;
  int num;
  printArray(numbers, printInt);
  arrayNum(numbers, &cnt);
  halfWay = cnt / 2;
  arrayGet(numbers, halfWay, &e);
  num = (int) (long) e;
  if (halfWay * 2 == cnt) {
    /* cnt is even: average two middle numbers */
    arrayGet(numbers, halfWay - 1, &e);
    median = 0.5 * (num + (int) (long) e);
  } else {
    /* cnt is odd: take middle number */
    median = (double) num;
  }
  printf("Median of %zu integers: %g\n", cnt, median);
}

static int icompare(void const * x, void const * y) {
  int ix = * (int const *) x;
  int iy = * (int const *) y;
  return ix - iy;
}

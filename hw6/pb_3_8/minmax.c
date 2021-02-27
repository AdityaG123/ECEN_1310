#include <stdio.h>
#include <assert.h>

int minmax(int const *a, int n, int *min, int *max) {
  if (!a || !min || !max) return -1;
  if (n <= 0) return -2;
  *min = a[0]; *max = a[0];
  for(int i = 1; i < n; i++) {
    if (a[i] < *min) *min = a[i];
    else if (a[i] > *max) *max = a[i];
  }
  return 0;
}

int main(void) {
  int min; int max;
  int a[7] = {1,13,21,-12,0,99,46};
  int err = minmax(a,7,&min,&max);
  assert(!err && min == -12 && max == 99);
  int b[3] = {4,4,4};
  err = minmax(b,3,&min,&max);
  assert(!err && min == 4 && max == 4);
  int c[2] = {1,2};
  err = minmax(c,2,&min,&max);
  assert(!err && min == 1 && max == 2);
  int d[1] = {7};
  err = minmax(d,1,&min,&max);
  assert(!err && min == 7 && max == 7);
  err = minmax(a,-1,&min,&max);
  assert(err == -2);
  err = minmax(a,0,&min,&max);
  assert(err == -2);
  err = minmax(NULL,7,&min,&max);
  assert(err == -1);
  err = minmax(a,7,NULL,&max);
  assert(err == -1);
  err = minmax(a,7,&min,NULL);
  assert(err == -1);
}

#include <stdio.h>
#include <assert.h>

int mean(int *a, int len, int *mn) {
  if(!a || !mn || len <= 0) return -1;
  *mn = 0;
  for(int i = 0; i < len; i++) *mn = *mn + a[i];
  *mn = *mn/len;
  return 0;
}

int main(void) {
  int a[] = {1,2,3,4,5};
  int out;
  int err = mean(a,5,&out);
  assert(!err && out == 3);
  int b[] = {1,1,1,1};
  err = mean(b,4,&out);
  assert(!err && out == 1);
  err = mean(a,0,&out);
  assert(err);
  err = mean(a,-1,&out);
  assert(err);
  err = mean(NULL,0,&out);
  assert(err);
  err = mean(a,0,NULL);
  assert(err);
}

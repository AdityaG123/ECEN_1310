#include <assert.h>
#include <stdio.h>
#define N 8

int numOccur(int a[N], int n, int v, int *occ) {
  if(!a || !occ) return -1;
  if(n < 0) return -2;
  *occ = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == v) *occ = *occ + 1;
  }
  return 0;
}

int main(void) {
  int occ; int a[N]={1,2,2,1,1,9,9,9};
  int err = numOccur(a,N,1,&occ);
  assert(err == 0 && occ == 3);
  err = numOccur(NULL,N,1,&occ);
  assert(err == -1);
  err = numOccur(a,N,1,NULL);
  assert(err == -1);
  err = numOccur(a,-1,1,&occ);
  assert(err == -2);

}

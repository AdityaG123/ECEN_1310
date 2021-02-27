#include <stdio.h>
#include <assert.h>
#define N 3

int unzip(int *a, int *b, int const *c, int n) {
  if(n < 0 || !a || !b || !c) return -1;
  for(int i = 0; i < n; i++){
    a[i] = c[2*i];
    b[i] = c[2*i+1];
  }
  return 0;
}

int main(void) {
  int a[N]; int b[N];
  int c[2*N] = {1,2,3,4,5,6};
  int err = unzip(a,b,c,N);
  for(int i = 0; i < N; i++) {
    assert(err == 0 && a[i] == 2*i+1 && b[i] == 2*i+2);
  }
  err = unzip(NULL,b,c,N);
  assert(err);
  err = unzip(a,NULL,c,N);
  assert(err);
  err = unzip(a,b,NULL,N);
  assert(err);
  err = unzip(a,b,c,-1);
  assert(err);
}
  

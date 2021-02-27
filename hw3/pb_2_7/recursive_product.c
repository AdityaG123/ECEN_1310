#include <stdio.h>
#include <assert.h>

int fac(int n){
  if (n == 1 || n == 0)
    return 1;
  if (n < 0)
    return -1;
  return n = n * fac(n-1);
}

int main(void){
  int f = fac(2);
  assert(f == 2);
  f = fac(6);
  assert(f == 720);
  f = fac(0);
  assert(f == 1);
  f = fac(-2);
  assert(f == -1);
  f = fac(1);
  assert(f == 1);
  f = fac(9);
  assert(f == 362880);
  printf("All Clear! \n");
}

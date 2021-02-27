#include <stdio.h>
#include <assert.h>

int whilefac(int n){
  if (n < 0)
    return -1;
  if (n == 0)
    return 1;
  return _whilefac(n);
}

int _whilefac(int n){
  int S = 1;
  int i = 1;
  while(i <= n){
    S = S * i;
    i = i + 1;
  }
  return S;
}

int main(void){
  int f = whilefac(2);
  assert(f == 2);
  f = whilefac(6);
  assert(f == 720);
  f = whilefac(0);
  assert(f == 1);
  f = whilefac(-2);
  assert(f == -1);
  f = whilefac(1);
  assert(f == 1);
  f = whilefac(9);
  assert(f == 362880);
  printf("All Clear! \n");
}

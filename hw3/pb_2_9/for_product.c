#include <stdio.h>
#include <assert.h>

int forfac(int n){
  if (n < 0)
    return -1;
  if (n == 0)
    return 1;
  return _forfac(n);
}

int _forfac(int n){
  int S = 1;
  for(int i = 1; i <= n; i++){
    S = S * i;
  }
  return S;
}

int main(void){
  int f = forfac(2);
  assert(f == 2);
  f = forfac(6);
  assert(f == 720);
  f = forfac(0);
  assert(f == 1);
  f = forfac(-2);
  assert(f == -1);
  f = forfac(1);
  assert(f == 1);
  f = forfac(9);
  assert(f == 362880);
  printf("All Clear! \n");
}

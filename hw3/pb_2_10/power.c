#include <stdio.h>
#include <assert.h>

int power(int a, int n, int *p){
  if(n < 0 || p == NULL)
    return -1;
  int acopy = a;
  for(int i = 1; i < n; i++){
    a=a*acopy;
  }
  *p = a;
  return 0;
}

int main(void){
  int x = 3, y = 5, pow;
  int e = power(x,y,&pow);
  assert(e == 0);
  printf("%d^%d = %d\n", x, y, pow);
  x = 2, y = 8;
  e = power(x,y,&pow);
  assert(e == 0);
  printf("%d^%d = %d\n", x, y, pow);
  x = 1, y = 19;
  e = power(x,y,&pow);
  assert(e == 0);
  printf("%d^%d = %d\n", x, y, pow);
  x = 3, y = 5;
  e =  power(x,y,NULL);
  assert(e == -1);
  x = -1, y = 20;
  assert(e == -1);
}

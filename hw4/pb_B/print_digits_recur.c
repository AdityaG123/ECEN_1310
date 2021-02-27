#include <stdio.h>
#include <assert.h>

int printDec(int n){
  if (n <= 0)
    return -1;
   _printDec(n);
   printf("\n");
   return 0;
}

int _printDec(int n){
  if (n == 0)
    return 0;
  int p = n%10;
  n = _printDec(n/10);
  printf("%d\n",p);
  return n;
}
  
int main(void){
  printf("%d\n\n",12);
  int err = printDec(12);
  assert(err == 0);
  printf("%d\n\n",807);
  err = printDec(807);
  assert(err == 0);
  err = printDec(0);
  assert(err == -1);
  err = printDec(-21);
  assert(err == -1);
}

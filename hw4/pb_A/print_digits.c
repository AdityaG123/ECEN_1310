#include <stdio.h>
#include <assert.h>

int printDecimalDigits(int n){
  if (n <= 0)
    return -1;
  while (n != 0){
    int p = n%10;
    printf("%d\n", p);
    n = n/10;
  }
  printf("\n");
  return 0;
}


int main(void){
  int err = printDecimalDigits(0);
  assert(err == -1);
  err = printDecimalDigits(-20);
  assert(err == -1);
  printf("%d\n\n",1291);
  err = printDecimalDigits(1291);
  assert(err == 0);
  printf("%d\n\n",9);
  err = printDecimalDigits(9);
  assert(err == 0);
}

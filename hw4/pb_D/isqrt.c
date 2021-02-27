#include <stdio.h>
#include <assert.h>

int isqrt(int n, int *isr){
  if(!isr || n < 0)
    return -1;
  int a = 0;
  int b = 1;
  for (int i = 1; n >= a; i = i+2){
    a = a + i;
    b = i;
    printf("%d\n",a);
  }
  *isr = b/2;
  return 0;
}

int main(void){
  int r; int t = 13;
  printf("%d\n",t);
  int err = isqrt(t,&r);
  printf("\n%d\n",r);
  assert(r == 3 && err == 0);
  t = 30;
  printf("\n%d\n",t);
  err = isqrt(t,&r);
  printf("\n%d\n",r);
  assert(r == 5 && err == 0);
  t = -21;
  err = isqrt(t,&r);
  assert(err == -1);
  err = isqrt(t,NULL);
  assert(err == -1);
}

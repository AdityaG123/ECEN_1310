#include <stdio.h>
#include <assert.h>

int multof3(int m) {
   if (m % 3  == 0)
    return 1;
  else
    return 0;

}

int main(void) {
  int x = multof3(21);
  assert(x == 1);
  x = multof3(40);
  assert(x == 0);
  x = multof3(0);
  assert(x == 1);
  x = multof3(-69);
  assert(x == 1);
  x = multof3(-200);
  assert(x == 0);
  printf("All Clear \n");
  return 0;
}









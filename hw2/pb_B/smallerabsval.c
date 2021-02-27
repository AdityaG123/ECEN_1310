#include <assert.h>
#include <stdio.h>

int abs(int a) {
  if (a < 0)
    a = a * -1;
  return a;
    }

int smallerabvalinterval(int x, int y) {
  if (x == y)
    return x;
  int  Ax = abs(x);
  int  Ay = abs(y);
  if (Ax > Ay)
    return y;
  else
    if (Ax < Ay)
      return x;
  else
    return Ax;
}

int main(void) {
  int rv =  smallerabsinterval(-5,7);
  assert(rv == -5);
  rv = smallerabsinterval(5,-7);
  assert(rv == 5);
  rv = smallerabsinterval(-2,-2);
  assert(rv == -2);
  rv = smallerabsinterval(2,2);
  assert(rv == 2);
  rv = smallerabsinterval(-3,-2);
  assert(rv == -2);
  rv = smallerabsinterval(2,3);
  assert(rv == 2);
  rv = smallerabsinterval(2,0);
  assert(rv == 0);
  rv = smallerabsinterval(-4,0);
  assert(rv == 0);
  rv = smallerabsinterval(-2,0);
  assert(rv == 0);
  printf("All Clear \n");
}


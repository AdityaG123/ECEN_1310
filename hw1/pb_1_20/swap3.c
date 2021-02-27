#include <stdio.h>
#include <assert.h>

void swap3(int *a, int *b, int *c)
{
  assert(a!=NULL);
  assert(b!=NULL);
  assert(c!=NULL);
  int x, y, z;
  x = *a;
  y = *b;
  z = *c;
  *a = y;
  *b = z;
  *c = x;
  return;
}

int main()
{
  int x = 1;
  int y = 2;
  int z = 3;
  swap3(&x, &y, &z);
  assert(x==2);
  assert(y==3);
  assert(z==1);
}

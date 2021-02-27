#include <assert.h>
#include <stdio.h>
#define N 5

int vectorSum(int const * x, int const * y, int n, int * sum) {
  if(!x || !y || !sum) return -1;
  if(n <= 0) return -2;
  for(int i = 0; i < n; i++){
    sum[i] = x[i] + y[i];
  }
  return 0;
}

int main(void) {
  int sum[N];
  int x[N]={1,2,3,4,5};
  int y[N]={6,7,8,9,10};
  int err = vectorSum(x,y,5,sum);
  for(int i = 0; i < N;i++){
    assert(err == 0 && sum[i] == 2*i+7);
  }
  err = vectorSum(NULL,y,5,sum);
  assert(err == -1);
  err = vectorSum(x,NULL,5,sum);
  assert(err == -1);
  err = vectorSum(x,y,5,NULL);
  assert(err == -1);
  err = vectorSum(x,y,0,sum);
  assert(err == -2);
  err = vectorSum(x,y,-1,sum);
  assert(err == -2);
}

#include <stdio.h>
#include <string.h>

int main(int argc, char * argr[]){
  int m; int n; int sum = 0; int i;
  if(argc != 3) {printf("Please input only two arguments.\n"); return -1;}
  else if(sscanf(argr[1],"%d",&m) != 1) {printf("Please input integer as first argument.\n"); return -1;}
  else if(sscanf(argr[2],"%d",&n) != 1) {printf("Please input integer as second argument.\n"); return -1;}
  if(m < 0 || n < 0 || m > n) {printf("Error in arguments, either negative or the second argument is greater.\n"); return -1;}
  for(i = m; i <=n; i++) sum += i;
  printf("The sum is %d.\n",sum);
  return 0;
}

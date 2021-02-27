#include <stdio.h>
#include <string.h>

int main(){
  int min; int max; int range = 0; int rc; int val;
  if(scanf("%d",&min) != 1){printf("Invalid input. First input must be an integer.\n"); return -1;}
  max = min;
  while((rc = scanf("%d",&val)) != EOF) {
    if(rc == 0) {printf("Invalid input. Expected integers only.\n"); return -1;}
    if(min > val) min = val;
    if(max < val) max = val;
  }
  range = max - min;
  printf("The range of the inputs is %d.\n",range);
  return 0;
}
  

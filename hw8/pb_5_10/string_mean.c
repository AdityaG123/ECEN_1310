#include <stdio.h>
#include <ctype.h>

int main(void){
  char c; int n = 0; int len = 0; int totlen = 0;
  while(scanf("%c",&c) != EOF){
    if(isspace(c)){
      if(len != 0) {
	totlen += len;
	n++;
	len = 0;
      }
    }
    else len++;
  }
  if(n > 0) {printf("Mean Length = %d\n",totlen/n); return 0;}
  else {printf("No string read, so mean length undefined.\n"); return -1;}
}

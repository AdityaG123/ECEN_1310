#include <stdio.h>

int main(int argc, char ** argv){
  char c; char mode;
  if(argc < 2) {printf("Invalid input. Requires at least 1 argument.\n");return -1;}
  if(sscanf(argv[1],"%c",&mode) != 1){printf("Invalid input. Requires input mode s or w.\n"); return -1;}
  if(mode == 's')
    while(scanf("%c",&c) != EOF){
      if(c >= 'a' && c <= 'z') c += 'A'-'a';
      printf("%c",c);
    }
  else if(mode == 'w'){
    while(scanf("%c",&c) != EOF){
      if(c >= 'A' && c <= 'Z') c += 'a'-'A';
      printf("%c",c);
    }
  }
  else{printf("Invalid input. Requires input mode s or w.\n"); return -1;}
  return 0;
}

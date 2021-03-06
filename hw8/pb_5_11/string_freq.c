#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printUsage(void) {
  printf("Usage: string_freq [modifier] [string]\n");
}

void printDistribution(int * nOccur, int sz, int nWords) {
  if(!nOccur) return;
  int i, j;
  for(i = 0; i < sz; i++) {
    int percent = (100 * nOccur[i]) / nWords;
    printf("%2d %2d ", i, percent);
    for(j = 0; j < percent; ++j) printf("*");
    printf("\n");
  }
}

int parseArgs(int argc, char ** argv) {
  int max = 32;
  if(argc == 1) return max;
  if(argc == 2){
    if(strcmp("-h",argv[1]) == 0) {printUsage(); return 0;}
    if(strcmp("-s",argv[1]) == 0) {printf("Please input integer for string threshold.\n"); return -1;}
    }
  if(argc == 3 && strcmp("-s",argv[1]) == 0) {if(sscanf(argv[2],"%d", &max) != 1) {printf("Please input integer for string threshold.\n"); return -1;} return max;}
  if(argc >= 4) {printUsage(); return -1;}
}

int main(int argc, char ** argv){
  int lenmax;
  lenmax = parseArgs(argc, argv);
  if (lenmax == -1 || lenmax == 0) return lenmax;
  int occur[lenmax+1], len = 0, words = 0; char c;
  int i;
  for(i = 0; i <= lenmax; i++) occur[i] = 0;
  while(scanf("%c",&c) != EOF){
    if(isspace(c)){
      words++;
      if(len != 0) {
	if(len >= lenmax) occur[lenmax]++;
	else occur[len]++;
	len = 0;
      }
    }
    else len++;
  }
  if(words == 0) {printUsage(); return -1;}
  printDistribution(occur,lenmax+1,words);
  return 0;
}

      

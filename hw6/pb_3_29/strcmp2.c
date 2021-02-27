#include <stdio.h>
#include <assert.h>

int strcmp2(char *str1, char *str2) {
  if(!str1 || !str2) return 0;
  int i = 0;
  while(str1[i]){
    if(str1[i] < str2[i]) return -1;
    if(str1[i] > str2[i]) return 1;
    else if(str1[i] == str2[i]) {i++;}
  }
  if (str1[i] == '\0' && str1[i] == str2[i]) return 0;
}

int main(void) {
  printf("aardvark , aardwolf %d\n", strcmp2("aardvark", "aardwolf"));
  printf("AVAST , avast %d\n", strcmp2("AVAST", "avast"));
  printf("ahoy , ahoy %d\n", strcmp2("ahoy", "ahoy"));
  printf("Watch for aardvarks!, " "Watches aren’t for aardwolves. %d\n", strcmp2("Watch for aardvarks!", "Watches aren’t for aardwolves."));
  printf("zoology , zoo %d\n", strcmp2("zoology", "zoo"));
  printf("NULL, abc %d\n", strcmp2(NULL,"abc"));
  printf("abc, NULL %d\n", strcmp2("abc",NULL));
}

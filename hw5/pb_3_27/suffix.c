#include <assert.h>
#include <stdio.h>

int suffix(char *str, char *suf) {
  if(!str || !suf) return 0;
  int i; int k = 0;
  for(i = 0; str[i] != '\0'; i++);
  assert(str[i] == '\0');
  char rts[i];
  for(i--; i >= 0; i--) {
    rts[k] = str[i];
    k++;
  }
  rts[k] = '\0';
  int j; int l = 0;
  for(j = 0; suf[j] != '\0'; j++);
  assert(suf[j] == '\0');
  char fus[j];
  for(j--; j >= 0; j--) {
    fus[l] = suf[j];
    l++;
  }
  fus[l] = '\0';
  int m = 0;
  while(fus[m] != '\0') {
    if(fus[m] != rts[m]) return 0;
    m++;
  }
  return 1;
}

int main(void) {
  char input[9] = "Malarkey"; char suff[4] = "key";
  int err = suffix(input,suff);
  assert(err);
  char notsuffix[4] = "ish";        //from "rubbish" :)
  err = suffix(input,notsuffix);
  assert(!err);
  err = suffix(NULL,suff);
  assert(!err);
  err = suffix(input,NULL);
  assert(!err);
}

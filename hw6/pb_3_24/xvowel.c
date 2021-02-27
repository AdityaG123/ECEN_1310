#include <stdio.h>
#include <assert.h>

int xvowel(char const *in, char *out) {
  if(!in || !out) return -1;
  int i = 0; int j = 0;
  while(in[i]){
    if(in[i] == 'A' || in[i] == 'E' || in[i] == 'I' || in[i] == 'O' || in[i] == 'U' || in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u') i++;
    else {out[j] = in[i]; i++; j++;}
  }
  out[j] = '\0';
  return 0;
}

int main(void) {
  char str[] = "Hello universe!";
  char out[32];
  int err = xvowel(str, out);
  assert (!err);
  printf("%s\n%s\n", str, out);
  err = xvowel(NULL, out);
  assert(err);
  err = xvowel(str, NULL);
  assert(err);
  char a[] = "A";
  err = xvowel(a, out);
  assert (!err);
  printf("%s\n%s\n", a, out);
  char z[0];
  err = xvowel(z, out);
  assert(!err);
}

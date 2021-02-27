#include <stdio.h>
#include <assert.h>

int copyStringN(char const *in, char *out, int n) {
  if (!in || !out) return -1;
  int i;
  for(i = 0; i < n-1; i++) {
    out[i] = in[i];
    if(in[i]=='\0') return 0;
  }
  out[i] = '\0';
  if(in[i]=='\0') return 0;
  if(in[i]!='\0') return -2;
}

int main(void) {
  char a[7] = "Hello!";
  int n = 3;
  char copy[n];
  int err = copyStringN(a,copy,n);
  for(int i = 0; i < n-1; i++)
    assert(err == -2 && copy[i] == a[i]);
  char b[3] = "He";
  err = copyStringN(b,copy,n);
  for(int i = 0; i < n-1; i++)
    assert(err == 0 && copy[i] == b[i]);
  char c[2] = "H";
  err = copyStringN(c,copy,n);
  for(int i = 0; i < n-1; i++)
    assert(err == 0 && copy[i] == c[i]);
  err = copyStringN(NULL,b,n);
  assert(err == -1);
  err = copyStringN(a,NULL,n);
  assert(err == -1);
}
    

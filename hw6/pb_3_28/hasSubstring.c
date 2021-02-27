#include <stdio.h>
#include <assert.h>

int hasSubstring(char *str, char *substr) {
  if(!str || !substr) return 0;
  int i, j;
  if(!substr[0]) return 1;
  for(i=0; str[i]; i++) {
    for(j = 0; ;j++) {
      if(!substr[j]) return 1;
      if(str[i+j] != substr[j]) break;
    }
  }
  return 0;
}

int main(void) {
  assert(hasSubstring("Hello universe!", "lo"));
  assert(hasSubstring("Hello universe!", "verse"));
  assert(hasSubstring("Hello universe!", ""));
  assert(hasSubstring("", ""));
  assert(! hasSubstring("Hello universe!", "verses"));
  assert(! hasSubstring("Hello universe!", "loun"));
  assert(! hasSubstring("Hello universe!", "erse!!"));
  char a[] = "Hello world"; char b[] = "lo w";
  int err = hasSubstring(a,b);
  assert(err);
  err = hasSubstring(NULL,b);
  assert(!err);
  err = hasSubstring(a,NULL);
  assert(!err);
  err = hasSubstring(b,a);
  assert(!err);
  char z[0];
  err = hasSubstring(z,b);
  assert(!err);
  char c[] = "He"; char d[] = "H";
  err = hasSubstring(c,d);
  assert(err); 
}

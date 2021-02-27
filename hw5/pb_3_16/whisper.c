#include <stdio.h>
#include <assert.h>
#define N 17

int whisper(char *msgIn, char *msgOut) {
  if(!msgIn || !msgOut) return -1;
  while(*msgIn != '\0') {
    if('A' <= *msgIn && *msgIn <= 'Z')
      *msgOut = *msgIn + ('a' - 'A');
    else
      *msgOut = *msgIn;
    msgIn++;
    msgOut++;
  }
  *msgOut = '\0';
  return 0;
}

int main(void) {
  char whisp[N]; char input[N] = "I hAvE a SEcrEt!";
  int err = whisper(input,whisp);
  printf("%s\n",whisp);
  assert(!err);
  err = whisper(NULL,whisp);
  assert(err);
  err = whisper(input,NULL);
  assert(err);
}

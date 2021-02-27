#include <stdio.h>
#include <assert.h>
#include <string.h>

void printUsage(char *name) {
	printf("usage %s [-encrypt][-decrypt][<file]\n"
			"-encrypt: encryption mode(default),\n"
			"-decrypt: decryption mode\n", name);
}

int parseArgs(char **argv, int *n) {
  if(strcmp("-encrypt", argv[1]) == 0) {
		*n = 1; 
	}
  else if(strcmp("-decrypt", argv[1]) == 0) {
		*n = 0; 
	}
	else {
		printUsage(argv[1]);
		return -1; 
	}
	return 0; 
}

#define SHIFT 12

void doShift(int shift) {
	char c; 
	while(scanf("%c", &c) !=EOF) {
		if('a' <= c && c <= 'z') {
			c = 'a' + ((c - 'a' +shift)%26); 
		}
		else if('A' <=c && c<= 'Z') {
			c = 'A' +((c -'A' +shift)%26); 
		}
		printf("%c", c); 
	}
}

int main(int argc, char **argv) {
	int err; 
	int encrypt; 
	int shift; 
	assert(0 <= SHIFT && SHIFT<26); 
	err = parseArgs(argv, &encrypt);
	if(err) return err; 
	if(encrypt) shift=SHIFT; 
	else shift=26-SHIFT; 
	doShift(shift); 
	return 0; 
}

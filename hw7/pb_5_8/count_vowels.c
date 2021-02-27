#include <stdio.h>

int main() {
    char c;
    int i, count[5];
    for (i=0; i<5; i++){
        count[i] = 0;
    }
    while(scanf("%c", &c) !=EOF) {
        if(c=='a' || c=='A') count[0]+=1;
        else if(c=='e' || c=='E') count[1]+=1;
        else if(c=='i' || c=='I') count[2]+=1;
        else if(c=='o' || c=='O') count[3]+=1;
        else if(c=='u' || c=='U') count[4]+=1;
    }
    printf("Number of Vowels:\n");
    printf("A or a: %d, E or e: %d, I or i: %d, O or o: %d, U or u: %d", count[0], count[1], count[2], count[3], count[4] );
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "blackjack.h"

struct _card{
  int suit;
  int number;
};

typedef struct _card Card;

 Card * createDeck(){
  int s,n,cnt=0;
  Card card;
  Card * x = malloc(52*sizeof(Card));
  for(s=1;s<5;s++)
    for(n=1;n<14;n++){
      card.suit = s;
      card.number = n;
      x[cnt]= card;
      cnt++;
    }
  return x;
}

void shuffleDeck(Card *deck){
  Card temp;
  int i,r;
  srand(time(0));
  for(i=0;i<52;i++){
    r = rand()%52;
    temp = deck[i];
    deck[i] = deck[r];
    deck[r] = temp;
  }
}

void printCard(Card c){
  if(c.number==2) printf("Two of ");
  if(c.number==3) printf("Three of ");
  if(c.number==4) printf("Four of ");
  if(c.number==5) printf("Five of ");
  if(c.number==6) printf("Six of ");
  if(c.number==7) printf("Seven of ");
  if(c.number==8) printf("Eight of ");
  if(c.number==9) printf("Nine of ");
  if(c.number==10) printf("Ten of ");
  if(c.number==1) printf("Ace of ");
  if(c.number==11) printf("Jack of ");
  if(c.number==12) printf("Queen of ");
  if(c.number==13) printf("King of ");
  if(c.suit == 1) printf("Spades\n");
  if(c.suit == 2) printf("Hearts\n");
  if(c.suit == 3) printf("Clubs\n");
  if(c.suit == 4) printf("Diamonds\n");
}

Card pointValue(Card c){
  if(c.number==1) c.number = 11;
  else if(c.number>10) c.number = 10;
  return c;
}

void clearHand(Card * x){
  int i;
  Card c;
  for(i=0;i<11;i++){
    c.number=0;
    c.suit=0;
    x[i]=c;
  }
}
      
int handSum(Card * x,int cnt){
  int i,sum=0,place=0;
  Card c;
  for(i=1;i<cnt+1;i++){
    c = x[i-1];
    sum += c.number;
    if(c.number==11) place = i;
  }
  c = x[cnt];
  if(c.number==11)
    if(sum>10)
      c.number = 1;
  sum += c.number;
  if(place)
    if(sum>21){
      c = x[place-1];
      c.number = 1;
      x[place-1] = c;
      sum = 0;
      for(i=0;i<=cnt;i++){
    c = x[i];
    sum += c.number;
    }
    }
  return sum;
}

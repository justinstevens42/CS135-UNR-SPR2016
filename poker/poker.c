/*
Poker Hand Simulator by Justin Stevens
Deals out a random poker hand, and then tells the user what hand they have.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "poker.h"



struct PokerHand MakeHand(struct PokerHand Player_Cards){
  int i,j;
  for (i=0; i<=12; i++){
    for(j=0; j<=3; j++){
      //iniitialize
      Player_Cards.hand[i][j]=0;
    }
  }
  const char ranks[]={'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
  const char suits[]={'s', 'h', 'c', 'd'};
  srand((unsigned) time(NULL));
  int card_counter=0, card_rank, card_suit;
  while(card_counter<hand_size){
    //rank is random number from 1 to 13
    card_rank=rand()%13;
    //suit is random number from 1 to 4
    card_suit=rand()%4;
    if(Player_Cards.hand[card_rank][card_suit]){
      //if it's in the hand, then continue and disregard everything else
      continue;
    }
    Player_Cards.hand[card_rank][card_suit]=true;
    //add the rank to the poker_ranks variable
    Player_Cards.poker_ranks[card_rank]+=1;
    Player_Cards.poker_suits[card_suit]+=1;
    printf(" %c%c", ranks[card_rank], suits[card_suit]);
    card_counter+=1;
  }
  printf("\n");
  return Player_Cards;
}
int main(){
    struct PokerHand player1;
    player1=MakeHand(player1);
    /*
    char straight=0;
    int i;
    for(i=0; i<=8; i++){
      if(poker_ranks[i]==1 && poker_ranks[i+1]==1 && poker_ranks[i+2]==1 && poker_ranks[i+3]==1 && poker_ranks[i+4]==1){
        straight=ranks[i+4];
      }
      else{
        continue;
      }
    }
    char high_card;
    char quads=0, trips=0, pair=0, two_pair=0; //all initialized to the null character

    for(i=0; i<13; i++){
      //incrementing through all the ranks
      switch(poker_ranks[i]){
        case 4:
          //if there are 4 of a kind, then we have quads
          quads=ranks[i];
          break;
        case 3:
          //if there are 3 of a kind, then we have trips
          trips=ranks[i];
          break;
        case 2:
          //if there is 2 of a kind, then we have a pair
          if(pair){
          //if we already have one pair, then we have two pair
          two_pair=ranks[i];
          }
          else{
            //otherwise, we just have one pair
            pair=ranks[i];
          }
          break;
        case 1:
          //otherwise, it's just a high card
          high_card=ranks[i];
          break;
        default:
          break;
        }
      }
      if(flush && straight){
        //if this happens, you should probably buy a lottery ticket
        printf("Straight flush %c high of %c\n", straight, flush);
      }
      if(quads){
        printf("Quad %cs\n", quads);
      }
      else if(trips && pair){
        printf("Full house %cs full of %cs\n", trips, pair);
      }
      else if(flush){
        switch(flush_suit){
          case 's':
            printf("Flush: Spades\n");
            break;
          case 'h':
            printf("Flush: Hearts\n");
            break;
          case 'd':
            printf("Flush:  Diamonds\n");
            break;
          case 'c':
            printf("Flush:  Clubs\n");
            break;
          default:
            break;
          }
        }
        else if(straight){
          printf("%c high straight\n", straight);
        }
        else if(trips){
          printf("Trip %cs\n", trips);
        }
        else if(two_pair){
          printf("Two pair %cs and %cs\n", pair, two_pair);
        }
        else if(pair){
          printf("Pair of %cs\n", pair);
        }
        else{
          printf("High card %c\n", high_card);
        }

        char ch=0;
        printf("Do you want another hand (y/n)?");
        while(ch!='n' && ch!='y'){
          ch=getchar();
        }
        if(ch=='n'){
          break;
        }
        printf("\n");
  }
  */
return 0;
}

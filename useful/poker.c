/*
Poker Hand Simulator by Justin Stevens
Deals out a random poker hand, and then tells the user what hand they have.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define true 1
#define false 0
#define hand_size 5
typedef int bool;

int main(){
  //in_hand variableto avoid repeats

  //ranks of the cards
  const char ranks[]={'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
  const char suits[]={'s', 'h', 'c', 'd'};

  while(true){
    bool in_hand[13][4]={false};
    int poker_ranks[13]={0};
    srand((unsigned) time(NULL));
    int card_suit=0, card_rank=0, card_counter=0;
    printf("Your hand: ");
    //define a variable flush_suit to represent the suit of each card that is passed through
    char flush_suit=0;
    bool flush=true;
    while(card_counter<hand_size){
      //rank is random number from 1 to 13
      card_rank=rand()%13;
      //suit is random number from 1 to 4
      card_suit=rand()%4;
      if(in_hand[card_rank][card_suit]){
        //if it's in the hand, then continue and disregard everything else
        continue;
      }
      in_hand[card_rank][card_suit]=true;
      //add the rank to the poker_ranks variable
      poker_ranks[card_rank]+=1;
      //print out the card
      printf(" %c%c", ranks[card_rank], suits[card_suit]);
      card_counter+=1;
      if(card_counter==1){
        //first time through so nothing to compare to;
        flush_suit=suits[card_suit];
        continue;
      }
      if(suits[card_suit]!=flush_suit){
        //if the suit of the new card is not the suit of the previous card, then flush is false
        flush=false;
      }
      flush_suit=suits[card_suit];

    }
    printf("\n");
    int i; //variable used to go through the poker_ranks array
    char straight=0;
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
return 0;
}

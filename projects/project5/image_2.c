/*
Name:  image_1.c
Purpose: Print out a Tic Tac Toe board
Author:  Justin Stevens */

#include <stdio.h>

int main(){
  int user_input;
  scanf("%d", &user_input);
  if(user_input%3!=2){
    //the remainder when user_input is divided by 3
    int rem=user_input%3;
    //for instance, if rem=1, then 2-rem=1, therefore user_input (which is 1 mod 3), will now be 2 mod 3
    //similarly, if rem=0, then 2-rem=2, therefore user_input will now be 2 mod 3
    user_input+=(2-rem);
  }
  //printing to get a nice format
  printf("P2\n");
  printf("# image.pgm\n");
  printf("%d %d\n", user_input, user_input);
  printf("%d\n", 1);
  int X[user_input][user_input];
  int row, col;
  //quotient which is used to divide the board into 3 parts
  int quotient=user_input/3;
  for(row=0; row<user_input; row++){
    for(col=0; col<user_input; col++){
      //the conditions where we have a 0 (which divide the board into threes) are when row or column is equal to quotient, or 2*quotient+1
      //the reason that it is 2*quotient+1 is for this to be of equal distance away from the first value, since the row begins at 0
      if(row==quotient || row==2*quotient+1 || col==quotient || col==2*quotient+1){
        X[row][col]=0;

      }
      else{
        X[row][col]=1;
      }
      printf("%d ", X[row][col]);
    }
  printf("\n");
  }

}

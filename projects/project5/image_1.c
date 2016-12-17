/*
Name:  image_1.c
Purpose: Print out an X in an array
Author:  Justin Stevens  */

#include <stdio.h>

int main(){
  int user_input;
  scanf("%d", &user_input);
  if(user_input%2==0){
    //if the input is even, tell them they must print an odd number
    printf("You must enter an odd number\n");
    //make the number an odd number now
    user_input+=1;;
  }
  //print statements at the beginning
  printf("P2\n");
  printf("# test.pgm\n");
  printf("%d %d\n", user_input, user_input);
  printf("%d\n", 255);
  //declare an array, X, which will hold all of the variables
  int X[user_input][user_input];
  int row, col;

  for(row=0; row<user_input; row++){
    for(col=0; col<user_input; col++){
      X[row][col]=0;
      printf("%d ", X[row][col]);
    }
    printf("\n");
  }
  printf("\n");
  for(row=0; row<user_input; row++){
    //iterate through the rows and columns
    for(col=0; col<user_input; col++){
      //the condition for it to print out a symmetric x is when either the row is equal to the column (one line)
      //or when the row and col together sum up to give user_input-1 (the other line)
      if(row==col || row+col==user_input-1){
        X[row][col]=255;

      }
      else{
        X[row][col]=0;
      }
      printf("%d ", X[row][col]);
    }
  printf("\n");
  }

}

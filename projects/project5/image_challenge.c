/*
Name:  image_1.c
Purpose: Print out a Tic Tac Toe board
Author:  Justin Stevens */

#include <stdio.h>

int main(){
  //this is the way to declare a new file
  FILE *fp;
  //file will go to image.pgm
  fp=fopen("image.pgm", "w+");

  int user_input;
  scanf("%d", &user_input);
  if(user_input%3!=2){
    int rem=user_input%3;
    user_input+=(2-rem);
  }
  //same as before, but now we're printing all of this to the file "fp"
  fprintf(fp, "P2\n");
  fprintf(fp, "# image.pgm\n");
  fprintf(fp, "%d %d\n", user_input, user_input);
  fprintf(fp, "%d\n", 1);
  int X[user_input][user_input];
  int row, col;
  //define quotient like we did in image_2.c to divide the board into thirds
  int quotient=user_input/3;
  for(row=0; row<user_input; row++){
    for(col=0; col<user_input; col++){
      //now we also add in one extra condition for when we will have the X (which is when row=col or when row+col=user_input-1)
      //this will print out the board with a giant X through it
      if(row==quotient || row==2*quotient+1 || col==quotient || col==2*quotient+1 || row==col || row+col==user_input-1){
        X[row][col]=0;

      }
      else{
        X[row][col]=1;
      }
      fprintf(fp, "%d ", X[row][col]);
    }
  fprintf(fp, "\n");
  }
  fclose(fp);

  return 0;

}

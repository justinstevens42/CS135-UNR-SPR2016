#include <stdio.h>

int main(){

  int board_size=23;
  printf("P2\n");
  printf("# image.pgm\n");
  printf("%d %d\n", board_size, board_size);
  printf("%d\n", 1);
  int X[board_size][board_size];
  int row, col;
  //quotient which is used to divide the board into 3 parts
  int quotient=board_size/4;
  for(row=0; row<board_size; row++){
    for(col=0; col<board_size; col++){
      //the conditions where we have a 0 (which divide the board into threes) are when row or column is equal to quotient, or 2*quotient+1
      //the reason that it is 2*quotient+1 is for this to be of equal distance away from the first value, since the row begins at 0
      if(row==quotient || row==2*quotient+1 || row==3*quotient+2 || col==quotient || col==2*quotient+1 || col==3*quotient+2){
        X[row][col]=0;

      }
      else{
        X[row][col]=1;
      }
      printf("%d ", X[row][col]);
    }
  printf("\n");
  }
  return 0;
}

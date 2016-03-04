/*  Author:  Justin Stevens
    Purpose:  Prints Pascal's triangle */
#include <stdio.h>

#define N 8
int main(){
  int pascal[N][N];
  int row, col;

  for(row=0; row<N; row++){
    for(col=0; col<N; col++){
      if(row==0 || col==0){
        pascal[row][col]=1;
      }
      else{
        pascal[row][col]=pascal[row-1][col]+pascal[row][col-1];
      }
      }
    }
  for(row=0; row<N; row++){
    for(col=0; col<N; col++){
      printf("%5d", pascal[row][col]);
    }
    printf("\n");
  }
  return 0;
}

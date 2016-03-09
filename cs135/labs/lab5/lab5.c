/*
Name:  lab5.c
Purpose:  Write a program that asks the user to input a matrix, and outputs the matrix such that A[i][j]=A[i][j]+A[i][j+1] unless j=n-1, in which case A[i][j]=A[i][j]+A[i][j][0]
Author:  Justin Stevens */

#include <stdio.h>
#define N 5 //done that this program can be executed with any size matrix
int main(){
  int matrix[N][N]; //input matrix
  int output[N][N]={0}; //output matrix
  printf("Enter a 5x5 matrix of integers.\n");

  int i, j; //variable declerations to go through the loop
  for(i=0; i<N; i++){
    printf("Row number %d: ", i+1);
    for(j=0; j<N; j++){
    scanf("%d", &matrix[i][j]); //scan the result into matrix row i, column j
    }
  }
  printf("\nThe new matrix is:\n");
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      output[i][j]=matrix[i][j]+matrix[i][(j+1)%N]; //the reason that I use (j+1) mod N is because this will return 0 when j=N-1, which we want
      printf("%d\t", output[i][j]); //formatted printing
    }
  printf("\n");  //new line after each row
  }

}

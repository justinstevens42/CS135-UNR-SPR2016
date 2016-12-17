/*
Name:  lab7.c
Purpose:  Write a function swap that swaps two numbers using pointers.  Then, use this to switch the 0th and 7th element of an array, the 8th and 3rd, and finally the 14th and 0th, and print the resulting swapped array.
Author:  Justin Stevens   */

#include <stdio.h>

void swap(int *arg1, int *arg2){
  //define a temporary variable for *arg1 as we are able to change it in the next line, but still want it stored somewhere
  int temp=*arg1;
  *arg1=*arg2;
  *arg2=temp;
}
int main(){
  printf("Enter 15 integers:\n");
  int user_inputs[15];
  int i;
  for(i=0; i<15; i++){
    scanf("%d", &user_inputs[i]);
  }
  //pass into the function memory addresses
  swap(&user_inputs[0], &user_inputs[7]);
  swap(&user_inputs[8], &user_inputs[3]);
  swap(&user_inputs[14], &user_inputs[0]);

  //print out the swapped array
  printf("\nSwapped array:\n");
  for(i=0; i<15; i++){
    printf("%d ", user_inputs[i]);
  }
  printf("\n");
  return 0;

}

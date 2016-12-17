/*
Name:  convert_time.c
Purpose: Converts uppercase letter to lowercase
Author:  Justin Stevens */

#include <stdio.h>

void print_time(long sec, int *hours, int *minutes, int *seconds){
  //the pointers that are inputted into this function's values will be changed
  *hours=sec/3600; //3600 seconds in an hour
  *minutes=(sec/60)%60; //60 seconds in a minute (then have to do mod 60 to account for the hours)
  *seconds=sec%60;

}

int main(){
  int input_seconds;
  printf("Enter the number of seconds: ");
  scanf("%d", &input_seconds);
  //declare these values as integers
  int hours, minutes, seconds;
  print_time(input_seconds, &hours, &minutes, &seconds); //pass in their addresses which will be updated accordingly  
  printf("\nThe equivalent is: %d hour(s), %d minute(s), %d second(s).\n", hours, minutes, seconds);
  return 0;

}

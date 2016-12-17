/*
Name:  lab4.c
Purpose:  Write a program that asks the user to enter a number containing multiple digits and that prints out a table showing how many times each digit appears in the number.
Author:  Justin Stevens /*

/*  Example:
Enter a number: 41271092
Digit:		    0 1 2 3 4 5 6 7 8 9
Occurrences:	1 2 2 0 1 0 0 1 0 1*/
#include <stdio.h>
#define N 10
int main(){
  //define an array that will show the number of times each digit occurs
  int occurences[N]={0};
  //number is input
  int number;
  int digit;
  //digit is the digit in the number
  printf("Enter a number:   ");
  scanf("%d", &number);
  while(number>=1){
    digit=number%10; //find the result of the number mod 10 (to give the unit digit)
    occurences[digit]+=1; //then add that this unit digit exists
    number=number/10; //finally, get rid of the unit digits, and start all over again
  }
  printf("Digit: \t \t %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d \n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  printf("Occurences: \t %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d \n", occurences[0], occurences[1], occurences[2], occurences[3], occurences[4], occurences[5], occurences[6], occurences[7], occurences[8], occurences[9]);
  return 0;
}

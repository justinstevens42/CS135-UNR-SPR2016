/*
Name:  lab6.c
Purpose:  Write a program that asks the user to input two numbers, n and k, and outputs the kth digit of n
Author:  Justin Stevens */

#include <stdio.h>

int digit (n,k){
  int lastdig;
  //while k is positive and n is positive, implement through this loop
  while(k>0 && n>0){
    //lastdig is the result of n mod 10
    lastdig=n%10;
    //divide n by 10 now since we no longer care about the previous lastdig, and want to find the next one
    n/=10;
    //decrement k as this loop will continue running running until k=0
    k--;
  }
  //if k is 0 and n=10, then lastdig is the first digit of n
  //otherwise when n=0, we have gone too far into the loop, and therefore, return -1
  if(n==0 && k!=0){
    return -1;
  }
  else{
    return lastdig;
  }


}
int main(){
  int n=0, k=0;
  do{
    printf("Enter two positive integers (n,k): ");
    scanf("%d, %d", &n, &k);
  } while(n<=0 || k<=0);
  printf("The k=%d digit of %d is: %d\n", k, n, digit(n,k));
}

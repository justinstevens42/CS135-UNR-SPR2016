/*
Name:  lab8.c
Purpose:  Write a function that prints out the length of a string and the capitalized version of the string which is inputted by the user.
Author:  Justin Stevens   */

#include <stdio.h>

int len(const char *str){
  //initialize the string_length to 0
  int string_length=0;
  //while the string pointer is not the null character
  while(*str){
    //increment to get the next character
    str++;
    string_length++;
  }
  //return the length (a few different interesting ways to do this)
  return string_length;
}

void cap(char *str){
  //this is going to change the value of str
  //while we're not at the null character
  while(*str!='\0'){
    //if it is lowercase, then capitalize it!
    if('a'<=*str && *str<='z'){
      //make it a capital letter by finding the difference between 'A' and 'a' (therefore all lowercase letters map to uppercase)
      *str+='A'-'a';
    }
    str++;
  }
}
int main(){
  //get user_input, arbitrarily chosen to be of length 100
  char user_input[100];
  printf("Enter a string:\n");
  //get a string (note:  it would be a lot more ideal to do fgets(user_inputs, 100, stdin))
  gets(user_input);
  //would've used size_t but had issues with the print
  int user_len=len(user_input);
  printf("\n%d\n", user_len);
  //capitalize (since it's a pointer, it changes the values accordingly)
  cap(user_input);
  //print it
  puts(user_input);
  return 0;
}

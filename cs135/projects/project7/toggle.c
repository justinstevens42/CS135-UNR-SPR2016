/*
Name:  toggle.c
Purpose: Toggles lowercase to uppercase and vice versa
Author:  Justin Stevens   */

#include <stdio.h>

#define MAX_LEN 30

void read_message(char *str, int *len){
  //takes in as input a string and a pointer to the length
  printf("Enter your string (maximum 30 characters): ");
  //I was having issues using *len=0 and summing that way, so I declared a strlen value
  int strlen=0;

  char ch;
  do{
    ch=getchar();
    //str is a pointer to the first element of the string, which is set to be ch
    *str=ch;
    //we then go to the next element in the string and so forth
    str++;
    strlen++; //keep track of the value of strlen
  }while(ch!='\n'); //ends when we have a newline
  *str='\0'; //add the null character so that it wouldn't print weird things
  *len=strlen; //have len be a pointer the value strlen which is the length of the string
}

void toggle_case(char *str){
  //inputs a string, changes the string so that it's values switch from lower-> upper and vice versa
  while(*str!='\n'){
    //if it is a lowercase value
    if('a'<=*str && *str<='z'){
      *str+='A'-'a'; //make it uppercase
    }
    //if it's uppercase
    else if('A'<=*str && *str<='Z'){
      *str+='a'-'A'; //make it lowercase
    }
    //str initially points to first element in the character array, then goes through all elements
    str++;
  }
}
int main(){
  //max length of 30 (have to add 1 more for null character)
  char user_message[MAX_LEN+1];
  int message_len;
  //message_len and the user_message both change below
  read_message(user_message, &message_len);
  //the cases of user_message are changed from lower-> upper and upper-> lower
  toggle_case(user_message);
  //print the string
  printf("New string: ");
  puts(user_message);
  return 0;
}

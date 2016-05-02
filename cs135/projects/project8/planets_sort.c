/*
Name:  planets_sort.c
Purpose: Sorts an array of planets
Author:  Justin Stevens */

#include <stdio.h>
#include <string.h>
//use this variable throughout the program for the number
#define NUM_PLANETS 9


int string_compare(char *str1, char *str2){
  //while both of them are not pointing at the null terminator
  while(*str1!='\0' && *str2!='\0'){
    //if str1 is before str2 alphabetically
    if(*str1<*str2){
      return 0;  
    }
    //if str1 is after str2 alphabetically 
    if(*str1>*str2){
      return 1;
    }
    str1++;
    str2++;
  }
  return -1;  
}

void reverse_alphabetical_order(char planets[NUM_PLANETS][8]){
  //variables i and j to increment through the array
  int i,j;
  char temp[8];
  for(i=0; i<=NUM_PLANETS-1; i++){
    //standard bubble sort like algorithm
    for(j=NUM_PLANETS-1; j>=i+1; j--){
      //if planets[j] is after planets[j-1] in the alphabet, then switch them
      if(string_compare(planets[j], planets[j-1])==1){
        //implement a temp variable to copy planets[j] to while switching it using strcpy
        strcpy(temp, planets[j]);
        strcpy(planets[j], planets[j-1]); //planets[j] now has planets[j-1]
        strcpy(planets[j-1], temp); //planets[j-1] now has what planets[j] initially was
      }
    }
  }
}

void alphabetical_order(char planets[NUM_PLANETS][8]){
  int i,j;
  char temp[8]; //temp variable
  for(i=0; i<=NUM_PLANETS-1; i++){
    for(j=NUM_PLANETS-1; j>=i+1; j--){
      if(string_compare(planets[j], planets[j-1])==0){
        //if planets[j-1] is after planets[j] in the alphabet (i.e. they're not in alphetical order)
        strcpy(temp, planets[j]); //switch planets[j]-> planets[j-1] and planets[j-1]-> planets[j] (next 3 lines of code)
        strcpy(planets[j], planets[j-1]);
        strcpy(planets[j-1], temp);
      }
    }
  }
}

int main(int argc, char *argv[]){
  //each character in this array has size <=8 chars
  char planets[NUM_PLANETS][8]={"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

  int i;
  //if the third thing the user entered was a, print the planets in alphabetical order
  if(strcmp(argv[2],"a")==0){
    //changes planets array
    alphabetical_order(planets);
    printf("The planets in alphabetical order are: ");
    //print them out
    for(i=0; i<NUM_PLANETS-1; i++){
      printf("%s, ", planets[i]);
    }
    //weird printing for the final planet (no comma after it)
    printf("%s\n", planets[NUM_PLANETS-1]);
  }
  else if(strcmp(argv[2],"r")==0){
    //otherwise, if the third thing the user entered was r, print the planets in reverse alphabetical order
    reverse_alphabetical_order(planets);
    printf("The planets in reverse alphabetical order are: ");
    for(i=0; i<NUM_PLANETS-1; i++){
      printf("%s, ", planets[i]);
    }
    printf("%s\n", planets[NUM_PLANETS-1]);
  }

  return 0;


}

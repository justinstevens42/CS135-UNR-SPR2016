/*
Name:  encode.c
Purpose: Encodes a message from the user into a PGM file
Author:  Justin Stevens */

#include <stdio.h>



int main(int argc, char *argv[]){
  FILE *original=fopen(argv[1], "r");
  // FILE *message=fopen(argv[2], "r");
  FILE *write=fopen(argv[2], "w");
  char *image_header;
  char image_character;
  while (image_character=getc(original)!='\n'){
    printf("%c", image_character);
    // fputc(image_character, write);
  }
  while (image_character=getc(original)!='\n'){
    // fputc(image_character, write);
  }
  // unsigned char image=malloc()
}

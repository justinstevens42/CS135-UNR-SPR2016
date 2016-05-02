/*
Name:  encode.c
Purpose: Encodes a message from the user into a PGM file
Author:  Justin Stevens */

#include <stdio.h>



int main(int argc, char *argv[]){
  FILE *original=fopen(argv[1], "r");
  // FILE *message=fopen(argv[2], "r");
  FILE *output=fopen(argv[2], "w");
  char *image_header;
  char image_character;
  while (image_character=fgetc(original)!='\n'){
  }
  while (image_character=fgetc(original)!='\n'){
  }
  int row, col;
  fscanf(original, "%d %d", row, col);
  printf("%d %d", row, col);

  fclose(original);
  fclose(output);  
  // unsigned char image=malloc()
}

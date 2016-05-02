/*
Name:  encode.c
Purpose: Encodes a message from the user into a PGM file
Author:  Justin Stevens */

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
  if(argc!=3){
    printf("Failure:  Wrong number of files");
    exit(EXIT_FAILURE);
  }
  FILE *original=fopen(argv[1], "r");
  if(original==NULL){
    printf("Failure:  Input image did not open properly");
    exit(EXIT_FAILURE);
  }
  FILE *output=fopen(argv[2], "w");
  if(output==NULL){
    printf("Failure:  Output image was not written to successfully");
    exit(EXIT_FAILURE);
  }

  char image_character;
  while((image_character=fgetc(original))!='\n'){
    fprintf(output, "%c", image_character);
  }
  fprintf(output, "\n");
  while((image_character=fgetc(original))!='\n'){
    fprintf(output, "%c", image_character);
  }
  fprintf(output, "\n");
  int row, col;
  fscanf(original, "%d %d", &row, &col);

  unsigned char *image;
  printf("%d", sizeof(unsigned char)*row*col);
  image=(unsigned char *) malloc(sizeof(unsigned char)*row*col);

  fclose(original);
  fclose(output);
  // unsigned char image=malloc()
  return 0;
}

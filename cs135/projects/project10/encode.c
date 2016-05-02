/*
Name:  encode.c
Purpose: Encodes a message from the user into a PGM file
Author:  Justin Stevens */

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
  FILE *original, *hidden, *output;
  char image_character; //image_character to print out the header and iterate through the original image file
  char hidden_character; //hidden_character to iterate through the text file
  int row, col, i, j; //the row and column size of the output PGM file
  int image_pixels; //how many pizels are in the image (mainly a garbage variable)


  int image_row=0, image_col=0, hidden_counter;  //these three counters will be used for incrementing through the image and through the hidden character

  if(argc!=4){
    printf("Failure:  Wrong number of files\n");
    exit(EXIT_FAILURE);
  }
  //original file is the original image before being edited
  original=fopen(argv[1], "r");
  if(original==NULL){
    //in the case that the user enters a bad file
    printf("Failure:  Input image did not open properly\n");
    exit(EXIT_FAILURE);
  }

  hidden=fopen(argv[2], "r");
  if(hidden==NULL){
    //if the user enters a bad text file
    printf("Failure:  Hidden text file did not open properly\n");
    exit(EXIT_FAILURE);
  }
  output=fopen(argv[3], "w");
  if(output==NULL){
    //this would only happen in the case of a memory leak I think
    printf("Failure:  Output image was not written to successfully\n");
    exit(EXIT_FAILURE);
  }

  while((image_character=fgetc(original))!='\n'){ //cycle through each part until we get to the new line
    fprintf(output, "%c", image_character); //print out to the output file
  }
  fprintf(output, "\n"); //print a new line to the output file (which is also a pgm)
  while((image_character=fgetc(original))!='\n'){ //cycle through the next new line character
    fprintf(output, "%c", image_character);
  }
  fprintf(output, "\n");
  //get the row and column values to know how big to make the image file
  fscanf(original, "%d %d", &row, &col);
  fscanf(original, "%d", &image_pixels);
  fprintf(output, "%d %d\n%d\n", row, col, image_pixels);

  //start with a double pointer to image.  from here, we need to allocate space for each row to be an integer pointer (and we need "row" number of these)
  int **image=malloc(sizeof(int *)*row);

  for(i=0; i<row; i++){
    image[i]=malloc(sizeof(int)*col); //now for each row, we need to allocate enough space for all of the columns (and we need "col" number of these)
    for(j=0; j<col; j++){
      fscanf(original, "%d", &image[i][j]);
    }
  }

  while((hidden_character=fgetc(hidden))!=EOF){
    // printf("%c", hidden_character);
    // printf("%d", hidden_character); ->  debugging
    for(hidden_counter=7; hidden_counter>=0; hidden_counter--){
      if((hidden_character & 1<<hidden_counter) !=0){
        image[image_row][image_col] |= (1<<0);
      }
      else{
        image[image_row][image_col] &= ~(1<<0);
      }
      image_col++;
      if(image_col==col){
        image_row++;
        image_col=0;
      }
    }
  }
  for(i=0; i<row; i++){
    for(j=0; j<col; j++){
      fprintf(output, "%d ", image[i][j]);
    }
    fprintf(output, "\n");
  }
  fprintf(output, "\n");


  // fwrite(image, sizeof(int), sizeof(image), output);


  fclose(original);
  fclose(hidden);
  fclose(output);

  return 0;
}

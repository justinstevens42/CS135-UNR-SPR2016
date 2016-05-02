/*
Name:  decode.c
Purpose: Decodes an image file into a message
Author:  Justin Stevens */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE *image, *hidden;

  char image_character;
  int row, col, image_pixels;
  int counter=0, i=0; //counter variable
  int flag=1;

  if(argc!=3){
    printf("Failure:  Wrong number of files\n");
    exit(EXIT_FAILURE);
  }

  image=fopen(argv[1], "r");
  if(image==NULL){
    printf("Failure:  Input image did not open properly\n");
    exit(EXIT_FAILURE);
  }
  hidden=fopen(argv[2], "w");
  if(hidden==NULL){
    printf("Failure:  Hidden output was not written to successfully\n");
    exit(EXIT_FAILURE);
  }
  //skips the first two newline characters
  while((image_character=fgetc(image))!='\n'){;}
  while((image_character=fgetc(image))!='\n'){;}
  //get the row and column values
  fscanf(image, "%d %d", &row, &col);
  fscanf(image, "%d", &image_pixels); //fourth line (image pixels)

  //store the numbers of element into an array called image_array
  int *image_array=malloc(sizeof(int)*row*col);
  do{
    fscanf(image, "%d", &image_array[counter]);
    // printf("%d ", image_array[counter]);
    counter++;
  } while(!feof(image)); //while it's not the end of the file

  char *output_array=malloc(sizeof(char)*counter);

  //I have to say I'm really not proud of this code below, but I'll explain what I'm doing
  int image_array_counter=0; //this goes through image_array and increments EVERY time we go through the loop
  int output_array_counter=0;
  /*  On the other hand, output_array_counter increments only once every 8 times.
  This is because 8 bits make up one character, so we have to gather information from all 8 bits first */
  int cycle_8=0; //this variable helps us go through every cycle full of 8 bits
  while(flag){ //I declared a flag above that was set to 1.  The times when the flag breaks is when we have a non-character value, or we've reached the end of the counter
  // printf("%d", image_array[image_array_counter]%2);
    output_array[output_array_counter]+=(image_array[image_array_counter]%2)*(1<<cycle_8);
    /*  This above line is the crux of how we go from bits to characters
    Essentially, we start with the first bit which is the least significant bit in the character, therefore should be multiplied by the smallest value of cycle_8 (when it is equal to 0)
    Then, for each of the more significant bits making up the character beyond that, we multiply them by powers of 2 which are bigger than this.
    Note that in the above line, I only care about the least signifcant bit of image_array (which is why I use mod 2)
    And that also 1<<cycle_8 is equivalen to 2^(cycle_8) */
    cycle_8++;
    if(cycle_8==8){ //when we've gone through one complete cycle
      //these are the likely conditions for when we have an actual hidden character (and not garbage system memory)
      if(32<=output_array[output_array_counter] && output_array[output_array_counter]<=200){
        fprintf(hidden, "%c", output_array[output_array_counter]);
        output_array_counter++; //when we've completed one full cycle, increment the output_array_counter variable
        cycle_8=0; //reset the cycle
      }
      else{
        // printf("FAILED");
        //if it is a non hidden character, then set the flag to 0 and exit out
        flag=0;
      }

    }
    //when we have reached the end of the image_array counter
    if(image_array_counter==counter){
      flag=0;
    }
    image_array_counter++;
  }
  free(output_array);
  fclose(image);
  fclose(hidden);
  return 0;

}

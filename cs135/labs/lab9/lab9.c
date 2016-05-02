/*
Name:  lab9.c
Purpose:  Remove the file name of a url so that it only prints the initial address
Author:  Justin Stevens */

#include <stdio.h>

void remove_filename(char *url){
  //declare a variable j which will increment through the url
  int j=0;
  //instead of directly modifying url, use pointer addition to access url[j] essentially
  while(*(url+j)!='\0'){
    // printf("%c", *(url+j));
    j++;
  }
  //it will stop at the end of the array here
  //now it's going to start at the end, and begin going down until it reaches the last backslash
  while(*(url+j) !='/'){
    // printf("%c", *url);
    j--;

  }
  //this will be the location where url[j]='/'
  // *(url+j)='\0';


}

int main(){
  char *url="http://www.knking.com/index.html";
  printf("%p\n", url);

  printf("%p", url+1);
  // puts(url);
  remove_filename(url);
  // puts(url);

  return 0;

}

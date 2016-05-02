/*
Name:  lab11.c
Purpose:  Uses dynamic memory allocation to check an array of integers.  
Author:  Justin Stevens   */

#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value){
	int i;
	//allocate space for n integers 
	int *result=malloc(n*sizeof(int));
	//if there isn't enough space, print an error 
	if(result==NULL){
		printf("Error:  Array not initialized");
		return NULL;  
	}
	//initialize the array  
	for(i=0; i<n; i++){
		result[i]=initial_value;
	}
	return result;  

}

int main(){
	//make the array  
	int *p;
	int n, initial_value;
	//get values from the user  
	printf("Please enter the size of the array: ");
	scanf("%d", &n);
	printf("Please enter the initial value of the array: ");
	scanf("%d", &initial_value);  
	//p has n elements, each with value initial_value  
	p=create_array(n, initial_value);
	if(!p){
		exit(EXIT_FAILURE);
	}

	//write the array to a file
	FILE *fp;  
	fp=fopen("arrayb.dat", "wb+");  
	//fwrite takes 4 arguments:  the array, the size of each integer, the number of integers to read, the file to write to 
	fwrite(p, sizeof(p[0]), n, fp);  
	free(p);   
	fclose(fp);
	return 0;

}
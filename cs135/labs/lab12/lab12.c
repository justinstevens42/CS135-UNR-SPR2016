/*
Name:  lab12.c
Purpose:  Sums an array of integers  
Author:  Justin Stevens   */

#include <stdio.h>  
#include <stdlib.h>  

void increment_value(int *value){*value=*value+1;} //using fancy one line function (increments the value the value points to by 1)

int sum_array(const int *a, int n){
	//start the sum at 0  and adds each value 
	int sum=0;
	int j=0;  //because a is a const, we should not be incrementing a directly, but rather point p at a and increment p 
	while(j<n){ //until we get to the end (when we have gone through n values)
		sum+=*(a+j); //add to sum the value that p points to (which changes in the line below)  
		j++;
	}
	return sum; 

}

int main(){
	int *a=malloc(sizeof(int)*10);
	int i; 
	for(i=0; i<10; i++){
		*(a+i)=i+1;
	} 
	printf("Original Sum: %d\n", sum_array(a, 10));
	for(i=0; i<10; i++){
		increment_value(&a[i]); //increment_value takes in input as pointers
	}
	printf("New Sum:  %d\n", sum_array(a, 10));
	return 0;
}
/*  Name:  series_challenge1.c
	Purpose:  Sums the series 2^2+4^2+6^2+...+n^2 for n<=100 and prints off each number which is summed   
	Author:  Justin Stevens  
*/

#include <stdio.h>

int main(){
	int sum=0;
	int input;
	printf("Enter an integer smaller than 100: ");
	scanf("%d", &input);
	int i=2;
	sum+=i*i;
	//I printed it this way because the first print statement does not have a + before it 
	printf("Sum = %d ", i*i);
	while(i<=input-2){
		i+=2; //when i=input, then we will be adding (input+2) here, which we don't want 
		sum+=i*i;
		printf(" + %d ", i*i);
	}
	printf("= %d \n", sum);
}
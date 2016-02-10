/*  Name:  series.c
	Purpose:  Sums the series 2^2+4^2+6^2+...+n^2 for n<=100  
	Author:  Justin Stevens  
*/

#include <stdio.h>

int main(){
	int sum=0;
	int input; //value for user to input  
	printf("Enter an integer smaller than 100: ");
	scanf("%d", &input);
	int i=2;
	while(i<=input){
		sum+=i*i; //add i^2 to the sum  
		i+=2;
	}
	printf("Sum = %d \n", sum);
}
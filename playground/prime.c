/*  Author:  Justin Stevens
	Purpose:  Prime number function */
#include <stdio.h>

int prime(int x){
	if(x==1){
		return 0;
	}
	if(x==2){
		printf("2 is prime \n");
		return 1;
	}
	if(x%2==0){
		//printf("2 divides %d \n", x);
		return 0;
	}
	for (int d=3; d<x; d++){
		if(x%d==0){
			//printf("%d divides %d \n", d, x);
			return 0;
		}
	}
	printf("%d is prime \n", x);
	return 1;
}

int main(){
	for(int n=1; n<100; n++)
		prime(n);
	
}
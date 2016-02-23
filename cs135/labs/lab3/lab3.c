/*  Name:  lab3.c
	Purpose:  Prints the number of occurences of a letter in a string.  
	Author:  Justin Stevens */

#include <stdio.h>

int main(){
	//Declare an initial array with 26 elements, all of which are 0
	int message[26]={0};
	printf("Enter a sentence ended by a '.' : ");
	char ch='\0'; //Initialize the character ch to be the null character
	ch=getchar(); //Read off the first letter that is inputted
	while (ch != '.'){ //When ch='.', the while loop will stop
		//The letter 'a' in ASCII maps to the integer 97.  
		//In our array above, however, we want the index 0 to correspond with a, therefore we have to subtract 97 from ch
		if(ch>='a' && ch<='z'){ //We only care about the letter if it's between a and z.
			message[ch-97]+=1; 
		
		}
		ch=getchar();
	
	}
	int letter;
	//For loop which increments through the array, starting with 0 (a) and ending with 25 (z).
	for(letter=0; letter<=25; letter++){
		if(message[letter]==0){
			//Then the letter does not occur, and go back to the beginning.
			continue;
		}
		else if (message[letter]==1){
			//If it only occurs 1 time, print time since it is singular.
			printf("Letter '%c' occurs %d time \n", letter+97, message[letter]);
		}
		else{
			//If it occurs more than once, then print times instead.  
			printf("Letter '%c' occurs %d times \n", letter+97, message[letter]);
		}
	};
}
/*  Name:  sentence.c
	Purpose:  User inputs a sentence, and it prints the capitalized version of the sentence, and the number of words in the sentence.
	Author:  Justin Stevens */

#include <stdio.h>  
int main(){
	char ch='0';
	//Declare an array to hold the characters inputted in 
	char sentence[100];
	int var=0; //This is the variable which I use to assign values to the array.  It starts from 0, and for each new character that is entered, adds it to the array  
	int Number_Of_Words=0; 
	printf("Enter a sentence ended by a ‘.’, a ‘?’ or a ‘!’: ");
	while((ch=getchar())!='!' && ch != '.' && ch != '?'){ //Loop conditions for when the program should end
		if('A'<=ch && ch<='Z'){ 
			; //If the letter is already capital, then leave it be
		}
		else if('a'<=ch && ch<='z'){
			ch-=32;  //Otherwise, subtract 32 from it, since the ASCII code for 'A' is 65 and 'a' is 97
		}
		sentence[var]=ch; //assign the value ch to the place "var" in the array (see above)
		var++;
	
	}
	sentence[var]='\0'; //add the null character to the end to avoid garbage printing
	printf("Capitalized sentence: ");
	int letter=0; //letter is being iterated across, use while loop since we don't know when we will hit the null character
	while(sentence[letter]!='\0'){
		putchar(sentence[letter]); //print the character
		/*the line below was the most tricky part of my code
		if sentence[letter] is a space (ascii code 32)
		and the letter is not the very first part of the string (such as if the user entered " hello")
		and the letter proceeding it is a letter in the alphabet 
		then it is a new word, and we inrement the counter
		for instance, if somebody enters "   hello   .", all of the extra spaces would be ignored, since the only one it cares about would be the space following the "o" */
		if(sentence[letter]==32 && letter !=0 && ('A'<=sentence[letter-1] && sentence[letter-1]<='Z')) { 
			Number_Of_Words++; //then increase the number of words (since it must be a space)
		}
		letter++;
	}
	if('A'<=sentence[letter-1] && sentence[letter-1]<='Z'){
		//number of words is inremented only after the user enters a space after a word 
		//if the letter immediately before the one which breaks out of the while loop is a character (i.e. not a space), add 1 to the count
		Number_Of_Words++;
	}
	//whichever punctuation is entered last needs to be printed as well
	putchar(ch);
	printf("\nTotal number of words: %d \n", Number_Of_Words);

	return 0;
}

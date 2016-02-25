/*  Name:  sentence.c
	Purpose:  User inputs a sentence, and it prints the capitalized version of the sentence, and the number of words in the sentence.
	Author:  Justin Stevens */

#include <stdio.h>  
int main(){
	char ch='0';
	char sentence[100];
	int var=0;
	int Number_Of_Words=1;
	printf("Enter a sentence ended by a ‘.’, a ‘?’ or a ‘!’: ");
	while((ch=getchar())!='!' && ch != '.' && ch != '?'){ //Loop conditions for when the program should end
		if('A'<=ch && ch<='Z'){ 
			; //If the letter is already capital, then leave it be
		}
		else if('a'<=ch && ch<='z'){
			ch-=32;  //Otherwise, subtract 32 from it, since the ASCII code for 'A' is 65 and 'a' is 97
		}
		sentence[var]=ch;
		var++;
	
	}
	sentence[var]='\0';
	printf("Capitalized sentence: ");
	int letter=0;
	while(sentence[letter]!='\0'){
		putchar(sentence[letter]);
		if('A'>sentence[letter] || 'Z'<sentence[letter]){
			Number_Of_Words++;
		}
		letter++;
	}

	putchar(ch);
	printf("\nTotal number of words: %d \n", Number_Of_Words);

	return 0;
}

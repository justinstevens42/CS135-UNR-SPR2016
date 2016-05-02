#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *stringcopy(char *str1, char *str2){
	char result[20];
	char *q=result;
	while(*str1){
		*q=*str1;
		q++;
		str1++;
	}
	while(*str2){
		*q=*str2;
		q++;
		str2++;
	}
	*q='\0';
	puts(result);
	return result;



}
int main(){
	char str1[30], str2[30];
	gets(str1);
	gets(str2);
	char result[60];
	char *res=result;;
	result=stringcopy(str1, str2);
	puts(result);
	return 0;

}

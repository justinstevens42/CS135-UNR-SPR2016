#include <stdio.h>

char convert(char ch){
	if ('a'<= ch && ch<='z'){
		ch=ch-'a'+'A';
	}
	return ch;
}

int main(){
	printf("%c", convert('c'));
}
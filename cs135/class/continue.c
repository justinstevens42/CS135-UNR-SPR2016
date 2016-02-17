#include <stdio.h>

int main(){
	int n=0;
	int sum=0;
	int i;
	while (n<10) {
		scanf("%d", &i);
		if (i!=0){
			sum+=i;
			n++;
		}
	}
}
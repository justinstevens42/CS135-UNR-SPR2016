#include <stdio.h>

int main(){
	for (;;){
		int n;
		printf("Enter a number (enter 0 to stop): ");
		scanf("%d", &n);
		if (n==0)
			break;
		printf("%d cubed is %d\n", n, n*n*n);
	}
}
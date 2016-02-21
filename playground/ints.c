#include <stdio.h>

int main(){
	float quotient;
	int dividend=13, divisor=3;

	quotient=dividend/divisor;
	printf("%f", quotient);
	quotient=(float) dividend/divisor;
	printf("%f", quotient);
}
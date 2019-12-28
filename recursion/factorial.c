#include <stdio.h>
#include <stdlib.h>

unsigned int factorial(unsigned int n) {
	// n! = n * (n-1) * ... * 1
	// 5! = 5 * 4 * 3 * 2 * 1
	// 0! = 1
  // n! = n * (n-1)!

	// base condition
	if (n == 0) {
		return 1;	
	}
	return n * factorial(n-1);			
}

int main() {
	printf("%u\n", factorial(5));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

void printNumberRev(unsigned int n) {
	if (n == 0) {
		return;
	}
	printf("%u\n", n);	// OS not need to preserve n by pushing it to stack
	// TAIL recursion
	printNumberRev(n-1);	// last statement is recursive call, no stack need to be created
}

void printNumberFord(unsigned int n) {
	if (n == 0) {
		return;	// OS will look at stack top
	}
	printNumberFord(n-1); // OS preserves n by pushing it to stack
	printf("%u\n", n);	// n will be retrieved from STACK
}

long factorial(unsigned int n) {
	if (n == 0) {
		return 1L;
	}
	return n * factorial(n-1);
}

int main() {
	printNumberRev(10);
	// printNumberFord(10);
	// printf("ld\n", factorial(5));
	return 0;	
}

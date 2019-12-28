#include <stdio.h>
#include <stdlib.h>

void print(int n) {
	// live of static variable equals live of the program
	// static int k = 1;
	
	// base condition
	if (n <= 0) {
		return;
	}

	//printf("Hello!! n = %d\n", n);
	print(n-1);
	printf("Hello!! n = %d\n", n);
}

int main() {
	print(3);
	return 0;
}


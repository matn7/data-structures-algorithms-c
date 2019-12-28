#include <stdio.h>
#include <stdlib.h>

void decToBin(unsigned int n) {
	// base case
	if (n == 0) {
		printf("0");
		return;
	}
	else if (n == 1) {
		printf("1");
		return;
	}
	else {
		decToBin(n/2);
		printf("%d", n % 2);
	}
	// bin of n
	// bin of n/2	n%2
	
	// bin of 5
	// bin of 2	5 %2
	// bin of 1 2 % 2
	// 10	

}

void decToBin_iter(unsigned int n) {
	unsigned int stack[32];
	unsigned int top = -1;
	while (n > 0) {
		stack[++top] = n % 2;
		n /= 2;
	}
	int i;
	for (i = top; i>= 0; --i) {
		printf("%u", stack[i]);
	}
}

int main() {
	// 1100
	decToBin(12);
	printf("\n");
	return 0;
}

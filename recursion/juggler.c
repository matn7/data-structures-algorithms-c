#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Printing Jugglers sequence
int juggler(int a) {
	// base case
	if (a == 1) {
		printf("%4d\n", a);
		return 1;
	}
	printf("%4d", a);

/*	// a is odd
	if (a % 2 != 0) {
		a = (int) pow(a, 1.5);
	}
	// a is even
	else {
		a = (int) pow(a, 0.5);
	}
*/
	juggler(a % 2 != 0 ? (int)pow(a, 1.5) : (int)pow(a, 0.5));
	// print sequence in reverse order
	// printf("%4d",a);
}

int main() {

	juggler(7);
	return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4

int main() {
	int *p;
	int a[COUNT];
	printf("size of an 'int' is %d\n", sizeof(int));
	// initialize our array
	for (int i = 0; i < COUNT; i++) {
		a[i] = i;
	}
	// pointer arithmetic
	p = a;	// set the pointer to the array to the start of the array
	printf("address of a is %p; value of p is %p [%d]; value pointed by p is %d\n", a, p, p, *p);

	p = p + 1;
  printf("address of a is %p; value of p is %p [%d]; value pointed by p is %d\n", a, p, p, *p);

	// value pointed by 'p' is a[3]
	p = p + 2;
  printf("address of a is %p; value of p is %p [%d]; value pointed by p is %d\n", a, p, p, *p);

	// go beyond array
	p = p + 1;
	printf("address of a is %p; value of p is %p [%d]; value pointed by p is %d\n", a, p, p, *p);

	return 0;
}

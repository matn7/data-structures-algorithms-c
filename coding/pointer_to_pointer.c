#include <stdio.h>
#include <stdlib.h>

void excercise_1() {
  // Excercise 1
  int value1 = 10;
  int value2 = 5;

  int* ptr = &value1;
  int** ptr_ptr = &ptr;

	printf("Excercise 1\n");
  printf("Printing dereferenced pointer:\n");
  printf("value1: %d\n", value1);
  printf("*ptr: %d\n", *ptr);   // One level dereferencing of a pointer
}

void excercise_2() {
	// Excercise 2
	int value1 = 10;
	int value2 = 5;
	
	int* ptr = &value1;
	int** ptr_ptr = &ptr;

	printf("\nExcercise 2\n");
	printf("Printing pointers:\n");
	printf("ptr_ptr: %p\n", ptr_ptr);
	printf("*ptr_ptr: %p\n", *ptr_ptr); // the same value
	printf("ptr: %p\n", ptr);						// the same value
}

void excercise_3() {
	// Excercise 3
	int value1 = 10;
	int value2 = 5;

	int* ptr = &value1;
	int** ptr_ptr = &ptr;

	printf("\nExcercise 3\n");
	printf("Printing dereferenced pointer to pointer:\n");
	printf("**ptr_ptr: %d\n", **ptr_ptr);
}

void excercise_4() {
	int value1 = 10;
	int value2 = 5;

	int* ptr = &value1;
	int** ptr_ptr = &ptr;

	**ptr_ptr = 20;

	printf("\nExcercise 4\n");
	printf("On editing dereferenced pointer to pointer:\n");
	printf("value1: %d\n", value1); 			// 20
	printf("*ptr: %d\n", *ptr);						// 20
	printf("**ptr_ptr: %d\n", **ptr_ptr);	// 20
}

void excercise_5() {
	int value1 = 10;
	int value2 = 5;

	int* ptr = &value1;
	int** ptr_ptr = &ptr;

	*ptr_ptr = &value2;

	printf("\nExcercise 5\n");
	printf("On reassigning dereferenced pointer:\n");
	printf("*ptr: %d\n", *ptr);
	printf("**ptr_ptr: %d\n", **ptr_ptr);
}

int main() {

	excercise_1();
	excercise_2();
	excercise_3();
	excercise_4();
	excercise_5();

	return 0;
}

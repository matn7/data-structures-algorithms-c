#include <stdio.h>

// function prototype
int binary_search(int[], int, int);

// returns index of target element in array
int binary_search(int intArray[], int size, int target) {
	int lb = 0;
	int ub = size - 1;

	// execute loop while ub >= lb
	while (ub >= lb) {
		int m = (lb + ub) / 2;
		// element found
		if (target == intArray[m]) {
			return m;
		}
		// * * * * * * # * *
		//         ^
		else if (intArray[m] < target) {
			lb = m + 1;
		}
		// * * # * * * * * *
		//       	 ^
		else {
			ub = m -1;
		}
	}
	return -1;
}

int main() {
	int intArray[] = {12, 14, 22, 134, 345, 890, 8760, 10000};
	int target;
	//               size in bytes      size of one element
	int size = (int) sizeof(intArray) / sizeof(intArray[0]);
	printf("Content of array\n");
	printf("%d\n", size);
	for (int i = 0; i < size; i++) {
		printf("%d, ", intArray[i]);
	}
	printf("\n");
	printf("Enter element: \n");
	scanf("%d", &target);

  int index = binary_search(intArray, size, target);

	printf("Target element is at index %d\n", index);
	return 0;
}

















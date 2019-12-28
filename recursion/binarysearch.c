#include <stdio.h>
#include <stdlib.h>

int bin_search(int arr[], int lb, int ub, int target) {
	//  base condition
	if (lb > ub) {
		return -1;
	}	
	int m = (lb + ub) / 2;
	if (arr[m] == target) {
		return m;
	} 
	// * * * * * # *
	//       ^
	else if (arr[m] < target) {
		return bin_search(arr, m + 1, ub, target);
	}
	// * # * * * * *
	//       ^
	else {
		return bin_search(arr, lb, m - 1, target);
	}
}

int main() {
	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

	int size = (int)sizeof(arr) / (int)sizeof(arr[0]);

	int k = bin_search(arr, 0, size, 7);
	
	if (k == -1) {
		printf("Target not found\n");
	} else {
	  printf("Target is at index = %d\n", k);
	}

	return 0;
}

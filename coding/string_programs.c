#include <stdio.h>
#include <stdlib.h>

// String Length
size_t my_strlen(const char* str) {
	if (str == NULL) {
		return 0;
	}

	int length = 0;
	const char *ch = str;
	
	while (*ch != '\0') {
		length++;
		ch++;
	}
	return length;
}

// String character check
char* my_strchr(const char* str, int c) {
	if (str == NULL) {
		return NULL;
	}
	
	while (*str != '\0') {
		if (*str == c) {
			return (char*) str;
		}
		str++;
	}
	return NULL;
}

// Substring check
char* my_strstr(const char* haystack, const char* needle) {
	if (haystack == NULL || needle == NULL) {
		return NULL;
	}
	//            V
	// haystack = PANDAPANDA\0
	// needle   = ANDA\0

	while (*haystack != '\0') {
		if (*haystack == *needle) {
			const char* h = haystack;
			const char* n = needle;
		
			while (*n != '\0' && *h == *n) {
				h++;
				n++;
			}
			// end of needle
			if (*n == '\0') {
				return (char*) haystack;
			}
		}
		//             V
		// haystack = PANDAPANDA\0
		// needle   =  ANDA\0
		haystack++;
	}
	return NULL;
}

// String compare
int my_strcmp(const char* str1, const char* str2) {
	// str1 = PANDA\0
	// str2 = ZEBRA\0
	if (str1 == NULL && str2 == NULL) {
		return 0;
	}

	// str1 = NULL
	// str2 = ZEBRA\0
	if (str1 == NULL) {
		return 0 - *str2; // 0 - Z = -90, str1 less than str2
	}

	// str1 = PANDA\0
	// str2 = NULL
	if (str2 == NULL) {
		return *str1; // P = 80, str1 is greater than str2
	}

	const char* ch1 = str1;
	const char* ch2 = str2;

	while (*ch1 != '\0' && *ch2 != '\0') {
		// ch1 = PANDA\0
		// ch2 = ZEBRA\0
		if (*ch1 != *ch2) {
			return *ch1 - *ch2; // P - Z = 80 - 120 = -40
		}

		ch1++;
		ch2++;
	}

	// ch1 = PANDA\0
	// ch2 = PANDAZ\0
	if (*ch1 == '\0' && *ch2 != '\0') {
		return 0 - *ch2; // 0 - Z = 0 - 120 = -120, longer string are greater
	}

	// ch1 = PANDA\0
	// ch2 = PAND\0
	if (*ch1 != '\0' && *ch2 == '\0') {
		return *ch1; // A = 65
	}

	return 0;
}

// String concatenation
char* my_strcat(char* dest, const char* src) {
	// dest = PANDA\0
	// src  = ZEBRA\0
	if (dest == NULL || src == NULL) {
		return dest;
	}

	char* d = dest;
	while (*d != '\0') { // find end od destination
		d++;
	}

	// d = \0
	while (*src != '\0') {
		// d = Z on first iteration, PANDAZ
		*d = *src;
		//       V
		// PANDAZ
		d++;
		//  V
		// ZEBRA
		src++;
	}
	// PANDAZEBRA\0
	*d = '\0';
	return dest;
}


int main() {
	size_t len = my_strlen("Hello World");
	printf("Length is %lu \n", len);

	char *another_string = "How are you?";
	len = my_strlen(another_string);
	printf("Length is %lu \n", len);

	char *null_string = NULL;
	len = my_strlen(null_string);
  printf("Length is %lu \n", len);

	char *empty_string = "";
	len = my_strlen(empty_string);
  printf("Length is %lu \n", len);

	char dest[100] = "PANDA";
	char src[50] = "ZEBRA";

	printf("majka %s", my_strcat(dest, src));

	return 0;
}













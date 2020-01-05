# Porinter

- Variable that points to address in computer memory.

## Data type alignment

```c
typedef struct {
	int a;						// 4 bytes
	double b;					// 8 bytes
	int c;						// 4 bytes
	long long int d; 	// 8 bytes
} MYSTRUCT;
```

- 8 bytes boundaries
- By using calloc free cels are initialized with `\0`

```
A	A	A	A	\0\0\0\0
B	B	B	B	B	B	B	B
C	C	C	C	\0\0\0\0
D	D	D	D	D	D	D	D

4 * 8 = 32 bytes
```

```c
typedef struct {
  int a;            // 4 bytes
 	int c;						// 4 bytes
	double b;         // 8 bytes
  long long int d;  // 8 bytes
} MYSTRUCT;
```

- C compiler optimized memory allocation

```
A A A A C C C C
B B B B B B B B
D D D D D D D D

8 * 3 = 24 bytes
```

## Linked List

- Dont allocate fixed block of memory in advance
- Pointer in element 1 to find element 2

## Queue

- FIFO
- Correct order is maintained

## Stack

- LIFO





























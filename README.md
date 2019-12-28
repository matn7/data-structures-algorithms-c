# Data Structures

## Stack

- Linear abstract data structure where the elements could be added or deleted only at one open end called the top of the stack.
- The elements follows **Last In First Out Order**, typically called **LIFO**.
- Insertion into the stack is called **push** operation and deletion from the stack is called **pop** operation.
- If the stack is full it is said to be in **Overflow** state, and push is rejected if stack is overflow.
- If the stack is empty it is said to be in **Underflow** state, and pop is rejected if stack is underflow.

![Alt text](stack/stack.png "Stack")


### Stack used

- Undo
- Back button in web browser
- Terminal history

### Implementation of Stack using 1-D array

```
top = -1; // initial value
top = holds last index insertion take place

size = 5; // size of array, top [0,4]

push first check size of array
push 6 th time will fail with overflow
```

**push algorithm**

```
1. PROCEDURE PUSH(v)
2. IF TOP := SIZE - 1 THEN
3.	DISPLAY "STACK OVERFLOW"
4.	EXIT PUSH
5. END IF
6. TOP := TOP + 1 // increment the top of the stack S by 1
7. S[TOP] := v	  // assign the element at the top position of the stack
8. END PROCEDURE PUSH
```

**pop algorithm**

```
1. PROCEDURE POP()
2. IF S.TOP = -1 THEN
3.	DISPLAY "STACK UNDERFLOW"
4. 	EXIT POP
5. END IF
6. v := S[TOP]
7. TOP := TOP - 1
8. RETURN v
9. END PROCEDURE POP
```

```
gcc main.c -o main
./main
```

### Reverse content of file

**reverse algorithm**

```
Data Structure needed: stack of characters.
Algorithm:
1. Go on reading characters from source file until End-of-file is reached.
2. PUSH Each character read into the stack.
3. When done, POP characters from the stack and write them into the destination file until stack is underflow.
```

### Match parenthesis

```
[{(a+b)*c}/a]	well formed
{(a+b)/c]	bad formed

{(a+b)/c]	)a + b(
AA   A		A
||   |		|
||   |		|
   check	error stop scanning
   stack


Opening bracket to stack
Closing bracket check stack
```

![Alt text](stack/match-parenthesis.png "Match parenthesis")

**match parenthesis algorithm**

```
error = FALSE

while Not end of the expression
  next_char = next character of input expression
  if next_char == '(' OR next_char == '{' OR next_char == '[' then
    push(STACK, next_char)
  else if next_char == ')' OR next_char == '}' OR next_char == ']' then
    if isEmpty(STACK) then
      error = TRUE
      break while
    else if isOpeningMatch(stacktop(STACK), next_char) then
      pop(STACK)
    else
      error = TRUE
      break while
    end if
  end if
end while

if !error and !isEmpty(STACK) then
  error = TRUE
end if

if error then
  print "The input expression does not contain well formed brackets"  
else
  print "The input expression is well formed"
end if
```

### Polish notation

```
(a+b)*c		// infix 

a+b ---> +ab	// prefix, Polish notation
a+b ---> ab+  // postfix, reverse Polish notation

// prefix, Polish notation
(a+b)*c	==> +ab*c  ==> r*c ==> *rc ==> *+abc

// postfix, reverse Polish notation
(a+b)*c ==> ab+*c ==> r*c ==> rc* ==> ab+c*
```

```
a*b+c
() - highest precidence
*,/
+,-

a*b/c		L -> R precidence
a-b+c		L -> R

a^b			exponential
a$b

a*b$(c-d)/k$p
a*b$-cd/k$p
a*$b-cd/k$p
a*$b-cd/$kp		r1 = $b-cd		r2 = $kp		
a*r1/r2
*ar1/r2
/*ar1r2

/*a$b-cd$kp		prefix notation
<------------
```

### Evaluate Polish or Reverse Polish notations

```
24+32-*
632-*
61*
6
```

**evaluate algorithm**

```
2 							---> push to stack
4 							---> push to stack
operand1 = 4.0
+
operand2 = 2.0
					 6.0	---> push to stack
3								---> push to stack
2								---> push to stack
operand1 = 2.0
-
operand2 = 3.0
					 1.0 ---> push to stack
operand1 = 1.0
*
operand2 = 6.0 
					 6.0 ---> push to stack
```

```
initialize(stack)
while not end of the postfix string:
	next_token = get the next token from postfix string
	if next_token is an operand then
		push(stack, next_token)
	else if next_token is an operator then
		opnd1 = pop(stack)
		opnd2 = pop(stack)
		result = operate (opnd2, opnd1, next_token)
		push(stack, result)
	end if

end while

print pop(stack)
```

**postfix compile**

```console
gcc postfix_eval.c -lm -o postfix_eval
```

### Invert Infix to Postfix

```
infix: 		a*(b+c)
postfix: 	a*bc+
					abc+*
```

- While converting to postfix, operands in infix do not change their position in postfix. However, operators
are rearranged according to their precedence
- Keep operators on the stack
- If the stack is empty and you have an operator then just push it into the stack

![Alt text](stack/infix2postfix.png "Infix to postfix")

## Algorithm converting Infix to Postfix

- Arrays:
	- infix - to hold the infix string
	- postfix - to hold the postfix string, initially empty

- Other Data structure:
	- OperatorStack - top is initialized and push and pop operation works on this

**ALGORITHM**

```
WHILE NOT END OF INFIX STRING:
	TOKEN = GET THE NEXT ELEMENT FROM INFIX STRING
	IF TOKEN IS AN OPERRAND THEN
		APPEND TOKEN WITH POSTFIX STRING
	ELSE IF TOKEN IS AN OPERATOR THEN
		WHILE NOT EMPTY OPERATORSTACK AND PRCD(STACKTOP, TOKEN):
			TOP_OPERATOR = POP(OPERATORSTACK)
			APPEND TOP_OPERATOR WITH THE POSTFIX STRING
		END WHILE
		IF TOKEN = ')' THEN
			POP (OPERATORSTACK)
		ELSE
			PUSH(OPERATORSTACK, TOKEN)
		END IF
	END IF
END WHILE

WHILE NOT EMPTY OPERATORSTACK:
	TOP_OPERATOR = POP(OPERATORSTACK)
	APPEND TOP_OPERATOR WITH THE POSTFIX STRING
END WHILE

PRINT POSTFIX
```

## Queue

- FIFO - First In First Out
- Implementing array

- Queue is a linear data structure with two open ends, called the 'rear' and 'front', elements are added at the 'rear'
end and deleted from the 'front' end.
- Elements in a Queue typically follows 'First In First Out' order, that is element inserted first will be always
deleted first.

- Some other variations of Queue DS:
	- Double ended queue.
	- Priority Queue.

![Alt text](queue/Queue.png "Queue")

- Queue is empty - This will happen when rear and front are at the same index.
- Insertion to queue - ENQUEUE
- Deletion from queue - DEQUEUE

### Algorithm for FIFO Queue using 1-D array

```
REAR : is an integer variable to hold the index of the rear end of Queue, that is
			 	the index of the next insertion element.

FRONT : is an integer variable to hold the index of the front end of Queue, that is
				the index of the next element to be deleted.

ITEM[SIZE] : is and 1-D array that we will be using for keeping the queue elements
							SIZE is the size of the Queue, that is the number of elements in the array.
							We consider tha index of the array starts from 0. 

Initially:
						REAR = 0
						FRONT = 0
```

```
OPERATION ENQUEUE(V):
	IF REAR == SIZE THEN
		PRINT "QUEUE OVERFLOW"
		EXIT ENQUEUE
	END IF

	ITEM[REAR] = V
	REAR = REAR + 1
END ENQUEUE

OPERATION DEQUEUE:
	IF REAR == FRONT THEN
		PRINT "QUEUE UNDERFLOW"
		EXIT DEQUEUE
	END IF

	V = ITEM[FRONT]
	FRONT = FRONT + 1
	RETURN V
END DEQUEUE
```

### Circural queue

![Alt text](queue/circural_queue.png "Circural queue")

**Algorithm**

```
IF R == F
	QUEUE IS UNDERFLOW

IF ((R + 1) % SIZE == F) 
	QUEUE OVERFLOW
```

**Algorithm for enqueue and dequeue operations for a Circular Queue**

```
Initially:
ITEM IS AN 1-D ARRAY TO HOLD THE ENQUEUE ELEMENTS
REAR = SIZE - 1
FRONT = SIZE -1

OPERATION ENQUEUE(V):
	IF (REAR + 1) % SIZE == FRONT THEN
		PRINT "QUEUE OVERFLOW"
		EXIT ENQUEUE
	END IF
	REAR = (REAR + 1) % SIZE
	ITEM[REAR] = V
END ENQUEUE	

OPERATION DEQUEUE:
	IF REAR == FRONT THEN
		PRINT "QUEUE UNDERFLOW"
		EXIT DEQUEUE
	END IF
	FRONT = (FROMT + 1) % SIZE
	V = ITEM[FRONT]
	RETURN V
END DEQUEUE
```

### Double ended queue

```
1. Insertion at REAR
2. Deletion from REAR
3. Insertion at FRONT
4. Deletion from FRONT
```

![Double ended queue](queue/double-ended-queue.png "Double ended queue")

**Algorithm insertion deletion**

```
FRONT = 0
REAR = -1

PROCEDURE INS_AT_REAR:
	IF REAR == SIZE - 1 THEN
		PRINT "UNABLE TO ADD AT REAR"
		EXIT INS_AT_REAR
	END IF
	REAR = REAR + 1
	ITEM[REAR] = V
END OF INS_AT_REAR


PROCEDURE DEL_FROM_REAR:
	IF FRONT > REAR THEN
		PRINT "QUEUE UNDERFLOW"
		EXIT DEL_FROM_REAR
	END IF
	V = ITEM[REAR]
	REAR = REAR - 1
	RETURN V
END OF DEL_FROM_REAR


PROCEDURE INS_AT_FRONT(V):
	IF FRONT == 0
		PRINT "UNABLE TO INSERT AT FRONT"
		EXIT INS_AT_FRONT
	END IF
	FRONT = FRONT - 1
	ITEM[FRONT] = V
END OF INS_AT_FRONT


PROCEDURE DEL_FROM_FRONT:
	IF FRONT > REAR THEN
		PRINT "QUEUE UNDERFLOW"
		EXIT DEL_FROM_FRONT
	END IF
	V = ITEM[FRONT]
	FRONT = FRONT + 1
	RETURN V
END OF DEL_FROM_FRONT
```

## Linked List

```
The drawbacks of arrays are removed in linked list at the cost of the benefit of having an array.
```

**Problem with arrays**

- The size of array.
- Once allocated with size it is a hazard to change the size of the array in runtime.
- Insertion and deletion operation at any point between the first and the last index of the existing elements.
- Adding a new element or deleting an existing element is independent to number of elements in the linked list, no shifting
kind of activities like array are required.

**Structure of linked list**

- Linked list is dynamic, created on "as and when required basis".
- You do not need to mention the size when you create a linked list.
- Programmers need to write functions for linked list operations such as inserting and deleting an element, searching and other
necessary DS operations.

![Structure of linked list](linked_list/structure-of-linked-list.png "Structure of Linked List")

**Singly linked list**

**Circular linked list**

![Circular linked list](linked_list/circular-linked-list.png "Circular Linked List")

**Doubly linked list**

![Doubly linked list](linked_list/doubly-linked-list.png "Doubly Linked List")

## Efficiency of Algorithm

- Execution time
- Memory needed by the algorithm to solve the problem

- How to estimate the Execution time and amount of memory consumed?
	- Machine
	- Input Size

- Hypothetical Machine
	- No parallel processing supported
	- Any simple instruction takes 1 unit of time
	- Loops and subroutines are not simple operations
	- Memory read or write operation takes 1 unit time
	- Infinite memory
	- **RAM model machine**

- INPUT SIZE
	
### Mathematical Approach

- Implement run and find execution time.
- We will not be able to draw a general conclusion about execution time depending on n.
- Here we are not finding execution time for all possible input size n but only for some input size.
- Input size n is a positive integer and can be as large as possible.

### Big-On notation

- We want a theoretical way based upon mathematics to compare the efficiency of the algorithms.
- A function f(n) is said to be O(g(n)) if there exists a positive constant C and a non nevative n0 such that 
|f(n)| <= c * |g(n)|

**Big Omega (The best case complexity)**

- A function f(n) is said th be Omega(g(n)) if and only if there exists a positive C and non-negative integer n0
such that
```
|f(n)| >= C * g(n), for all n > n0
```

**Big theta (The average case complexity)**

- A function f(n) is said to be Theta(g(n)) if and only if there exists two positive constants C1 and C2 and a non-negative
integer n0 such that
```
C1 * g(n) <= |f(n)| <= C2 * g(n), for all n >= n0
```

## Binary Search

- Worst case complexity of binary search is O(logn)
- The elements must be in sorted order in a list or array
- Binary search is best applied when the elements are kept in a binary search tree
- For binary search tree no overhead is there for keeping the elements in sorted order

## Recursion

```console
gcc juggler.c -lm -o juggler
```

**Recursion vs Iteration**

- When both are equivalent
	- When using tail recursion and loops
- When loop is better
	- Calculating factorial is not tail recursion, STACK push pop overhead. Not need the stack to solve this problem
- When recursion is better
	- Calculating decToBin to solve problem using iterative approach stack must by created by programmer.
	- In recursive approach stack is created for programmer by compiler and OS will manage the stack
	- Solution require stack explicitly

## Binary tree

- Hierarchical relationships of elements
- Each node can have 0,1,2 children
- Each node can have one parent

```
Binary tree is a set of 3 disjoint subsets, the first one is the root of the tree the other 2 subsets are either
empty or they are themselves binary tree.
```

**Traversing a Binary Tree**

- There are three Strategies:
	- Inorder
	- Preorder
	- Postorder

**Inorder**

- Traverse left subtree
- Access Root
- Traverse right subtree

**Preorder**

- Access Root
- Traverse left subtree
- Traverse right subtree

**Postorder**

- Traverse right subtree
- Traverse left subtree
- Access Root

**Construct Binary Tree from given list**

- Inorder Traversal List:		D	B	F	E	G	A	H	C	I
- Preorder Traversal List:	A B D E F G C H I
- Postorder Traversal List:	D F G E B H I C A

- Constructing by using Inorder + Preorder
- Constructing by using Inorder + Postorder

**Structure of Node in Binary Tree**

- Self referencial structure

```c
struct Node {
	int key;
	struct Node *left;
	struct Node *right;
};
```

**Binary Search Tree**

- To apply Binary Search on list/array elements, the list of array must be sorted.
- The worst case complexity of quick sort or merge sort is O(n * logn) 
- The worst case complexity of Binary Search is O(logn)

## Heap

- Comparision based sorting algorithm
- Worst case time complexity O(nlogn)
- Space complexity is O(1)
- Improved version of selection sort
- Heap sort uses HEAP Data Structure
- Build a heap using the unsorted list data
- The elements deleted from heap are ordered
- These deleted elements are placed into the sorted section
- For understanding heap sort you must know how to insert, delete and build a Heap

**Almost complete binary tree**

- When one level is complete we go to the next level
- Can be represented using 1-D array

```
Heap is an almost complete binary tree such that each node should contain a key value that
is at least or larger than it's children, with the largest key value always at the root. Such a
heap is called a MAX Heap. For a MIN Heap each node contains key field value that is less
than equals to the key field value of it's children and for a MIN Heap the root contains 
smallest value.
```

```
insertHeap(A[], n):
	// insert element at A[n] into heap that is maintained in A[1:n-1]
	i = n
	item = A[n]
	parent = floor(i/2)
	// as long as parent index is valid and the value at parent is less than the current item
	while (p > 0 and A[p] < item):
		A[i] = A[p]
		i = p
		p = floor(i/2)

	A[i] = item
```

**Delete from Heap**

- Root element are always deleted
- After deletion second largest (or smallest) occupied root
- Move last Node to Root
- Delete last Node
- After copying the content of the last node the heap may not be a heap anymore
- To restore heap at index i, we need to perform Adjust operation

```
deleteHeap(A[], heap_size):
	if (heap_size == 0):
		Print "Heap Empty"
		return -1

	// get the content of the root into a variable
	item = A[1]
	// copy the content of the last element into root
	A[1] = A[heap_size]
	// reduce the heap size by 1
	heap_size = heap_size - 1
	// call adjust operation for restoring the heap at index = 1
	Adjust(A, 1, heap_size)
	Return item
```

**Adjust**

```
Procedure Adjust(A[], i, n):
	// The max heaps are well maintained at 2*i and 2*i + 1, however, Max heap is not maintained at
	// index i, adjust to maintain MAX heap
	j = 2 * i
	temp = A[i]
	while(j <= n):
		if (j < n and A[j] < A[j+1]):
			j = j + 1
		
		if (temp >= A[j])
			break

		A[j/2] = A[j]
		j = 2 * j;
	// after while loop is over, we found the place for item
	A[j/2] = temp
```

**Heapify**

- Building a heap from array with O(n) worst case complexity
- If you have only one node in a tree then that is always a HEAP



























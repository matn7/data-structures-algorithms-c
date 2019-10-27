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


















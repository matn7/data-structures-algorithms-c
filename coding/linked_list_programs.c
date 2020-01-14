#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

// Get the length of a linked list
int get_length(struct node* head) {
	int length = 0;
	while (head != NULL) {
		length++;						// increment length while traverse
		head = head->next;
	}
	return length;
}

// Get the nth element in a linked list
struct node* get_nth(struct node* head, int n) {
	if (n < 0) {		// check for negative numbers
		return NULL;
	}
	int index = 0;
	while (head != NULL && index < n) {
		index++;
		head = head->next;
	}
	return head;
}

// Append an element to the end of a linked list
//	+------+	+------+	+------+
//	|  10	 |	|  20	 |	|	 30  |
//	| 11DA |	| AB24 |	| NULL |
//	+------+	+------+	+------+
// 	123FF				11DA			AB24
void append_data(struct node** headRef, int data) {
	if (headRef == NULL) {
		return;
	}
	// We are appending node
	// +------+
	// |	40  |
	// | NULL |
	// +------+
	// Handles 0 element list
	if (*headRef == NULL) {
		*headRef = (struct node*)malloc(sizeof(struct node));
		(*headRef)->data = data;
		(*headRef)->next = NULL;
		return;
	}
	struct node* head = *headRef;
	while (head->next != NULL) {
		head = head->next;
	}

	head->next = (struct node*)malloc(sizeof(struct node));
	head->next->data = data;
	head->next->next = NULL;
}

int main() {
  struct node* head = NULL;
 
  append_data(&head, 4);
  printf("Length: %d", get_length(head));
  append_data(&head, 5);
  printf("Length: %d", get_length(head));
  append_data(&head, 6);
  printf("Length: %d\n", get_length(head));
}























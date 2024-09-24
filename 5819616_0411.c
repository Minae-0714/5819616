#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

#define MAX_STACK_SIZE 10

typedef int element;
typedef struct Stacktype {
	element* data;
	int capacity;
	int top;
} StackType;

void init(StackType* sptr, int ofs) {
	sptr->data = (element*)malloc(sizeof(StackType) * ofs);
	sptr->top = -1;
	sptr->capacity = ofs;
}

int is_full(StackType* sptr) {
	if (sptr->top == sptr->capacity - 1) {
		sptr->capacity = sptr->capacity * 2;
		sptr->data = (element*)realloc(sptr->data, sptr->capacity * sizeof(element));
	}
}

int is_empty(StackType* sptr) {
	return (sptr->top == -1);
}

void push(StackType* sptr, element item) {
	is_full(sptr);
	sptr->data[++sptr->top] = item;
}

element pop(StackType* sptr) {
	element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack is empty\n");
		return -1;
	}
	else {
		return (sptr->data[(sptr->top)--]);
	}
}

element peek(StackType* sptr) {

	element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack is empty\n");
		return -1;
	}
	else {
		return (sptr->data[sptr->top]);
	}
}

int main() {

	StackType s;
	int rand_num;

	srand(time(NULL));


	init(&s, 5);

	for (int i = 0; i < 30; i++) {
		rand_num = rand() % 100 + 1;
		printf("%d \n", rand_num);
		if (rand_num % 2 == 0) {
			push(&s, rand_num);
			printf("Push Stack S %d\n", rand_num);
		}
		else {
			rand_num = pop(&s);
			printf("Pop Stack S %d\n", rand_num);
		}
	}
	return 0;
}

// This module provides functions, which is necessary working with stack.

// Version history:
// v0: Created mod.c and mod.h files
// v1: used if sentences to fix some problems
//     added debugging mode (#define DEBUG 0)
// v2: now functions can operate with all types of variables

#define DEBUG 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"mod.h"

struct Stack stackInit(int size)
{
	struct Stack stack = {NULL, size};
	stack.data = malloc(sizeof(void *));
	stack.size = size;

	return stack;
}
void stackFree(struct Stack *s)
{
	int i;
	for (i = 0; i < s->size; i++) {
		s->data[i] = realloc(s->data[i], 0);
	}
	s->data = realloc(s->data, 0);
	s->size = 0;
}
int stackElementCount(struct Stack *s)
{
	return s->size;
}
int stackElementIntValue(struct Stack *s, int index)
{
	// Returns the value of s->data typecast to int
	// Return 0 on error
	if (index < s->size) {
		return (int)*(int *)s->data[index];
	} else {
		printf("error: index [%d] out of bounds!\n", index);
	}
	return 0;
}
void push(struct Stack *s, void* value, int valueSize)
{
	if (s->size >= MAX_DATA - 1) {
		#if DEBUG
		printf("Elementas nepridetas. Neuztenka masyve vietos.\n");
		#endif
	}
	else {
		s->data = (void *)realloc(s->data, sizeof(void *) * (s->size+1));
		s->data[s->size] = malloc(valueSize);
		memcpy(s->data[s->size++], value, valueSize);
		#if DEBUG
		printf("Pridetas elementas.\n");
		#endif
	}
}
void* pop(struct Stack *s)
{
	void *temp = NULL;
	if ((s != NULL) && (s->size > 0)) {
		#if DEBUG
		printf("ispopintas elementas.\n");
		#endif
		temp = malloc(sizeof(void *));
		memcpy(temp, s->data[s->size - 1], sizeof(void *));
		s->size--;
		s->data[s->size] = realloc(s->data[s->size], 0);
		s->data = realloc(s->data, sizeof(void *) * s->size);
	} else {
		printf("error: stack [%p] is empty!\n", s);
	}
	return temp;
}

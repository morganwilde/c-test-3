#include <stdlib.h>
#include <stdio.h>
#include "mod.h"

int main(void) {
	// Create an instance of a Stack
	//struct Stack stack = {{NULL}, 0};
	struct Stack stack = stackInit(0);
	// Push 15, 4, 18 to stack
	int *storage = NULL;
	int temp = 0;
	storage = &temp;
	*storage = 15;
	push(&stack, (void *)storage, sizeof(storage));
	*storage = 4;
	push(&stack, (void *)storage, sizeof(storage));
	*storage = 18;
	push(&stack, (void *)storage, sizeof(storage));
	
	// Print out the stack
	int i;
	for (i = 0; i < stackElementCount(&stack); i++) {
		printf("stack[%d] = %d\n", i, stackElementIntValue(&stack, i));
	}

	// Test pop
	storage = pop(&stack);
	printf("storage value = [%d]\n", *storage);
	if (storage) {
		storage = realloc(storage, 0);
	}

	// Get element count
	printf("stack has \x1B[31m%d\x1B[0m elements\n", stackElementCount(&stack));

	// Free the stack
	stackFree(&stack);

	return 0;
}

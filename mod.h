#define MAX_DATA 30

struct Stack {
	void **data;
	//void* data[MAX_DATA];
	int size;
};  

// Function initializes the Stack to correct initial values
struct Stack stackInit(int size);

// Frees the stack once everything is done to not leak memory
void stackFree(struct Stack *s);

// How many elements are there in stack
int stackElementCount(struct Stack *s);

// Stack element value
int stackElementIntValue(struct Stack *s, int index);

// This function adds element to the end of the structure.
void push(struct Stack *s, void* value, int valueSize);

// This function removes element from the end of the structure.
void* pop(struct Stack *s);
//int pop(struct Stack *s);

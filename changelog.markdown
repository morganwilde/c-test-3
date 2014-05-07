# Changes

1. Changed `void* data[MAX_DATA];` to `void **data;`
1. Added `struct Stack stackInit(int size);` to mod.h to initialize a Stack
1. Implemented  `stackInit()` in mod.c
1. Changed the indentation/style for mod.c implementations
1. Added a `realloc` to `s->data` in the `push()` function
1. Made a function to free up memory `void stackFree(struct Stack *s)` in mod.[ch]
1. Added `int stackElementCount(struct Stack *s)` to return the count of elements
1. Added `int stackElementIntValue(struct Stack *s, int index)` to return values in the stack typecast to `int`

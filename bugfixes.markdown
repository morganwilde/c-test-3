# Fixes

1. Implicit declaration of `malloc` in mod.c - added `#include <stdlib.h>`
1. Implicit declaration of `memcpy` in mod.c - added `#include <string.h>`
1. Placed the `return` statement of a non-void function outside of the `if`
1. Added error messages in `pop()` to notify of bad inputs
1. Added functionality to manage memory since it is now dynamically allocated

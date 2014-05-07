test: test.c mod.o
	gcc test.c mod.o -o test

mod.o: mod.c
	gcc mod.c -c -o mod.o

reverse: reverse.o
	gcc reverse.o -o reverse -std=c99 -Wall -pedantic
reverse.o: reverse.c reverse.h
	gcc reverse.c -c -std=c99 -Wall -pedantic

test: driver.o avl.o
	gcc driver.o avl.o -o test

driver.o: driver.c avl.h
	gcc -c -g driver.c -o driver.o

avl.o: avl.c avl.h
	gcc -c -g avl.c -o avl.o


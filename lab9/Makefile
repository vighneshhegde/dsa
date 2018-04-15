ntree: driver.o nary.o iter.o set.o
	gcc -g driver.o nary.o iter.o set.o -o ntree

driver.o: driver.c nary.o 
	gcc -c -g driver.c -o driver.o

nary.o: nary.c nary.h iter.o
	gcc -c -g nary.c -o nary.o

iter.o: iterAR.c iter.h
	gcc -c -g iterAR.c -o iter.o

set.o: stack.c set.h
	gcc -c -g stack.c -o set.o

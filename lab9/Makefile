ntree: driver.o nary.o iter.o
	gcc -g driver.o nary.o iter.o -o ntree

driver.o: driver.c nary.o iter.o
	gcc -c -g driver.c -o driver.o

nary.o: nary.c nary.h iter.o
	gcc -c -g nary.c -o nary.o

iter.o: iter.c iter.h
	gcc -c -g iter.c -o iter.o


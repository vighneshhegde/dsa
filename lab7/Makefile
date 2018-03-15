test: besthash.o driver.o
	gcc driver.o besthash.o -o test

driver: besthash.h driver.c
	gcc -c driver.c -o driver.o

besthash.o: besthash.c besthash.h
	gcc -c besthash.c -o besthash.o


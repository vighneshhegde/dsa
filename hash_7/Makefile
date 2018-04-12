test: besthash.o driver.o linklist.o hasht.o
	gcc -g driver.o besthash.o linklist.o hasht.o -o test -lm

driver: besthash.h driver.c
	gcc -c -g driver.c -lm -o driver.o

hasht.o: hasht.c hasht.h
	gcc -c -g hasht.c -lm

besthash.o: besthash.c besthash.h
	gcc -c -g besthash.c -lm -o besthash.o

linklist.o: linklist.c linklist.h
	gcc -c -g linklist.c 

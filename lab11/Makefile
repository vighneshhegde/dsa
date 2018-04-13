test: driver.o linklist.o graph.o topo.o
	gcc -g driver.o topo.o linklist.o graph.o -o test

driver.o: driver.c
	gcc -c -g driver.c

topo.o: topo.c topo.h
	gcc -c -g topo.c

graph.o: graph.c graph.h linklist.o
	gcc -c -g graph.c

linklist.o: linklist.c linklist.h
	gcc -c -g linklist.c 

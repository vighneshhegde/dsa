cycle: cycle.o cycleTest.o mymem.o
	gcc -pg -g cycle.o cycleTest.o mymem.o -o cycle

mymem.o: mymem.c mymem.h
	gcc -pg -g -c mymem.c -o mymem.o;

cycle.o: cycle.c cycle.h
	gcc -pg -g -c cycle.c -o cycle.o;

cycleTest.o : cycleTest.c
	gcc -pg -g -c cycleTest.c -o cycleTest.o; 

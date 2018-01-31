cycle: cycle.o cycleTest.o mymem.o
	gcc -pg cycle.o cycleTest.o mymem.o -o cycle

mymem.o: mymem.c
	gcc -pg -c mymem.c -o mymem.o;

cycle.o: cycle.c 
	gcc -pg -c cycle.c -o cycle.o;

cycleTest.o : cycleTest.c
	gcc -pg -c cycleTest.c -o cycleTest.o; 

runIter: merge.o mergeIter.o
	gcc -g mergeIter.o merge.o -o mergeIter		
	./mergeIter

cmpIter: mergeIter.c merge.o merge.c
	gcc -g -c mergeIter.c -o mergeIter.o	

runRec: merge.o mergeRec.o
	gcc -g mergeRec.o merge.o -o mergeRec		
	./mergeRec

cmpRec: mergeRec.c merge.o merge.c
	gcc -g -c mergeRec.c -o mergeRec.o	

mergeTest: mergeTest.o merge.o
	gcc -g mergeTest.o merge.o -o mergeTest
	./mergeTest

mergeTest.o: mergeTest.c
	gcc -g -c mergeTest.c -o mergeTest.o

merge.o: merge.c merge.h
	gcc -g -c merge.c -o merge.o

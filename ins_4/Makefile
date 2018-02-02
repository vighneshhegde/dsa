record: record.o recordTest.o 
	gcc -g -pg record.o recordTest.o -o record

recordTest.o: recordTest.c
	gcc -g -pg -c recordTest.c -o recordTest.o

record.o: record.c record.h
	gcc -g -pg -c record.c -o record.o


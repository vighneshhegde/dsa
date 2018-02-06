record: record.o recordTest.o qs.o
	gcc -g -pg record.o recordTest.o qs.o -o record

recordTest.o: recordTest.c
	gcc -g -pg -c recordTest.c -o recordTest.o

record.o: record.c record.h
	gcc -g -pg -c record.c -o record.o

qs.o: qs.c qs.h
	gcc -g -pg -c qs.c -o qs.o


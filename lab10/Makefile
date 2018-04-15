graph: driver.o graphL.o que.o linklist.o bfs.o
	gcc -g driver.o graphL.o que.o linklist.o bfs.o -o graph

driver.o: driver.c graphL.o
	gcc -c -g driver.c -o driver.o

bfs.o: bfs.c que.h graph.h
	gcc -c -g bfs.c -o bfs.o

graphL.o: graphL.c graph.h
	gcc -c -g graphL.c -o graphL.o

graph.o: graph.c graph.h
	gcc -c -g graph.c -o graph.o

que.o: que.c que.h
	gcc -c -g que.c -o que.o

linklist.o: linklist.h linklist.c
	gcc -c -g linklist.c

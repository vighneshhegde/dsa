graph: driver.o graph.o que.o bfs.o
	gcc -g driver.o graph.o que.o bfs.o -o graph

driver.o: driver.c graph.o
	gcc -c -g driver.c -o driver.o

bfs.o: bfs.c que.h graph.h
	gcc -c -g bfs.c -o bfs.o

graph.o: graph.c graph.h
	gcc -c -g graph.c -o graph.o

que.o: que.c que.h
	gcc -c -g que.c -o que.o

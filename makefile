CC=clang
CFLAGS=-Wall -std=c17
LDLIBS=-lm -lMLV
OBJ=main.c Graphique.c Particules.c QuadTree.c Pliste.c

quadtree: $(OBJ)
	$(CC) -o $@ $^ $(LDLIBS)

Graphique.o: Graphique.c Graphique.h Particules.c Pliste.c QuadTree.c
	$(CC) $(CFLAGS) -c -o $@ $< 

QuadTree.o: QuadTree.c QuadTree.h Pliste.c Particules.c
	$(CC) $(CFLAGS) -c -o $@ $< 

Particules.o: Particules.c Particules.h
	$(CC) $(CFLAGS) -c -o $@ $< 

Pliste.o: Pliste.c Pliste.h
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm -f *.o quadtree
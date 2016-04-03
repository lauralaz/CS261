all: animal

animal: bst.o compare.o animalgame.o
	gcc -g -Wall -std=c99 -o animal bst.o compare.o animalgame.o

compare.o: compare.c
	gcc -g -Wall -std=c99 -c compare.c
		
bst.o: bst.c bst.h
	gcc -g -Wall -std=c99 -c bst.c

animalgame.o: bst.c bst.h
	gcc -g -Wall -std=c99 -c animalgame.c

clean:	
	rm bst.o
	rm compare.o
	rm animalgame.o
	rm animal

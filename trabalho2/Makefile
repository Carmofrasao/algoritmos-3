CFLAGS = -Wall -g 

objs = main.o TAD-ab.o TAD-Aab.o

all: busca

busca: $(objs)
		cc -o busca $(objs)
		
main.o: main.c 
	cc -c main.c $(CFLAGS)
TAD-ab.o: TAD-ab.c
	cc -c TAD-ab.c $(CFLAGS)
TAD-Aab.o: TAD-Aab.c 
	cc -c TAD-Aab.c $(CFLAGS)

clean: 
	-rm -f *.o *~		

purge: clean
	-rm -f busca

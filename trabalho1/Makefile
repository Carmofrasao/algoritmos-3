
objs = main.o TAD-ab.o

all: calculadora

calculadora: $(objs)
		cc -o calculadora $(objs)
		
main.o: main.c TAD-ab.h
TAD-ab.o: TAD-ab.c TAD-ab.h

clean: 
	-rm -f *.o *~		

purge: clean
	-rm -f calculadora

#*******************************************************
# Programacion I. Curso 2016-2017
# Compilación del programa biblioteca
#*******************************************************


CC	=gcc -Wall

all: biblioteca

base_de_datos.o: base_de_datos.c base_de_datos.h
		 $(CC) -c base_de_datos.c

pantalla.o: pantalla.c pantalla.h
	    $(CC) -c pantalla.c

biblioteca: biblioteca.c pantalla.o base_de_datos.o
	    $(CC) biblioteca.c pantalla.o base_de_datos.o -o biblioteca

clean:
	rm -f base_de_datos *.o *~ *.bak
